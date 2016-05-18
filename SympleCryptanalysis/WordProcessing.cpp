#include <math.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include <wctype.h>
#include "gcroot.h"
#include <msclr/marshal_cppstd.h>
#include <algorithm>

//#include "SympleCryptanalysis.h"
#include "VigenereAnalysis.h"


#define MAXALPHLEN 40    // Максимальная длина алфавита
#define ARRAY_SIZE 1000  // Максимальная длина массива изменений


namespace WordProcessing {

	using namespace System;
	using namespace msclr::interop;


	// Класс определяет используемый алфавит
	class Alphabit {
	private:
		void sort(double *frequency, int *frequency_indexing) {
			
			for (int i = 0; i < length - 1; i++) {
				int max_id = i;
				for (int j = i + 1; j < length; j++)
					if (frequency[frequency_indexing[j]] > frequency[frequency_indexing[max_id]])
						max_id = j;
				int tmp = frequency_indexing[i];
				frequency_indexing[i] = frequency_indexing[max_id];
				frequency_indexing[max_id] = tmp;
			}
 		}

	public:
		int firstchar, lastchar, length;
		double frequency[MAXALPHLEN] = { 0.0 };
		int freq_sorted_index[MAXALPHLEN] = { 0 };
		
		// Конструктор класса.
		// Все данные о требуемом алфавите берутся и файла Configs/langsFile.lng
		// В файле содержатся данные о положениях первого и последнего символа алфавита 
		// нижнего регистра в Unicode таблице, количество символов в алфавите и частотное распределение
		Alphabit(String^ lang) {
			using namespace std;
			ifstream langsFile("Configs/langsFile.lng");
			string str;
			while (getline(langsFile, str) && String::Compare(marshal_as<String^>(str), lang));
			langsFile >> firstchar >> lastchar >> length;
			for (int i = 0; i < length; i++) langsFile >> frequency[i];
			langsFile.close();

			formIndexing(frequency, freq_sorted_index);
		}

		// Функция формирует букву по соответствующей ей позиции в алфавите
		__declspec(dllexport) wchar_t getLetter(int num) {
			return firstchar + ((num + length) % length);
		}

		// Функция проверяет символ на соответствие букве
		__declspec(dllexport) bool isLetter(int num) {
			return num >= firstchar && num <= lastchar;
		}

		// Инициализация массива индексов для соответствия отсортированному массиву по частоте
		__declspec(dllexport) void formIndexing(double *frequency, int *frequency_indexing) {
			for (int i = 0; i < length; i++) frequency_indexing[i] = i;
			sort(frequency, frequency_indexing);

		}

	} alph("rus"); // Объявление используемого алфавита


	// Класс управляет изменениями в тексте по ходу работы для возможности отката изменений
	class Changes {
	
	private:

		gcroot<array<System::String ^>^> textChanges = gcnew array<System::String^ >(ARRAY_SIZE);       // Массив содержит все изменения текста
		int conformityChanges[ARRAY_SIZE][MAXALPHLEN];
		int amount = 0;                                                                                   // Переменнная определяет номер последнего изменения

		// Функция сохраняет изменения																								
		void save_changes(String^ text, int *conformity) {
			textChanges[amount % ARRAY_SIZE] = text;
			memcpy(conformityChanges[amount % ARRAY_SIZE], conformity, sizeof(int) * MAXALPHLEN);
			//for (int i = 0; i < alph.length; i++) {
			//	if ((*conformity)[i] == -1)	(*conformity)[i] = amount > 0 ? conformityChanges[(amount - 1) % ARRAY_SIZE][i] : i;
			//	conformityChanges[amount % ARRAY_SIZE][i] = (*conformity)[i];
			//} 
			amount++;

		}

	public:

		// Функция передаёт исходный текст
		String^ getFirstText(String^ text = nullptr) { return (amount != 0 || text == nullptr) ? textChanges[0]->ToLower() : text; }

		// Функция передаёт последний текст
		String^ getLastText() { return textChanges[amount - 1]->ToLower(); }

		int *getLastConformity() { return (amount != 0) ? conformityChanges[amount - 1] : NULL; }

		//Функция откатывает последние изменения
		String^ changeTextDown(String^ *text, String^ *conformity_table) {
			if (amount > 0) amount--;
			*text = textChanges[amount];
			for (int i = 0; i < alph.length; i++) {
				*conformity_table += alph.getLetter(conformityChanges[amount][i]) + " - " + alph.getLetter(i) + "\r\n";
			}
			return *text;
		}

		//Функция сохраняет последние изменения
		String^ changeTextUp(String^ *text, String^ *conformity_table, int *conformity = NULL, String ^key = nullptr) {
			
			

			if (conformity) {
				
				//for (int i = 0; i < alph.length; i++) 
				//	if ((*conformity)[i]!=-1)
				//		*text = (*text)->Replace(alph.getLetter(i) + "", (alph.getLetter((*conformity)[i]) + "")->ToUpper());
	
				save_changes(*text, conformity);
				
				*text = getFirstText(*text);
				*text = VigenereAnalysis::shiftLettersInText(*text, key, conformity);

				*conformity_table = "";

				for (int i = 0; i < alph.length; i++)
					*conformity_table += alph.getLetter(conformity[i]) + " - " + alph.getLetter(i) + "\r\n";
			}
			else {
				String^ old_text = *text;

				int **conformity = (int**)malloc(MAXALPHLEN * sizeof(int));
				*text = getFirstText(*text);
				
				VigenereAnalysis::textPreparing(text, conformity, key);
				save_changes(old_text, *conformity);

				*conformity_table = "";

				for (int i = 0; i < alph.length; i++) 
					*conformity_table += alph.getLetter((*conformity)[i]) + " - " + alph.getLetter(i) + "\r\n";
			}

			return *text;
			
		}



	} Changes; // Экземпляр класса хранящий все изменения

	//Функция сохраняет последние изменения
	String^ changeTextUp(String^ *text, String^ *conformity_table, int **conformity = NULL, String ^key = nullptr) { 
		return Changes.changeTextUp(text, conformity_table, conformity, key); 
	}

	//Функция откатывает последние изменения
	String^ changeTextDown(String^ *text, String^ *conformity_table) { return Changes.changeTextDown(text, conformity_table); }
	
	// Функция передаёт исходный текст
	String^ getFirstText() { return Changes.getFirstText();  }

	// Функция передаёт последний текст
	String^ getLastText() { return Changes.getLastText(); }

	int *getLastConformity() { return Changes.getLastConformity(); }

}