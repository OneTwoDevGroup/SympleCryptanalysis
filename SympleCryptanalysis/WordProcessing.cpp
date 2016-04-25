#include <math.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include <wctype.h>
#include "gcroot.h"
#include <msclr/marshal_cppstd.h>

#include "VigenereAnalysis.h"

#define MAXALPHLEN 40    // Максимальная длина алфавита
#define ARRAY_SIZE 1000  // Максимальная длина массива изменений


namespace WordProcessing {

	using namespace System;
	using namespace msclr::interop;


	// Класс определяет используемый алфавит
	class Alphabit {
	public:
		int firstchar, lastchar, length;
		double freaquancy[MAXALPHLEN] = { 0.0 };
		
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
			for (int i = 0; i < length; i++) langsFile >> freaquancy[i];
			langsFile.close();
		}

		// Функция формирует букву по соответствующей ей позиции в алфавите
		__declspec(dllexport) wchar_t getLetter(int num) {
			return firstchar + ((num + length) % length);
		}

		// Функция проверяет символ на соответствие букве
		__declspec(dllexport) bool isLetter(int num) {
			return num >= firstchar && num <= lastchar;
		}

	} alph("eng"); // Объявление используемого алфавита


	// Класс управляет изменениями в тексте по ходу работы для возможности отката изменений
	class Changes {
	
	private:

		gcroot<array<System::String ^>^> textChanges = gcnew array<System::String^ >(ARRAY_SIZE);       // Массив содержит все изменения текста
		int last = 0;                                                                                   // Переменнная определяет номер последнего изменения

		// Функция сохраняет изменения																								
		void save_changes(String^ old_text) {
			textChanges[last % ARRAY_SIZE] = old_text;
			last++;

		}

	public:

		// Функция передаёт исходный текст
		String^ getFirstText() { return textChanges[0]->ToLower(); }

		// Функция передаёт последний текст
		String^ getLastText() { return textChanges[last]->ToLower(); }

		//Функция откатывает последние изменения
		String^ changeTextDown() {
			if (last > 0) last--;
			return textChanges[last];
		}

		//Функция сохраняет последние изменения
		String^ changeTextUp(String^ old_text) {

			String^ new_text = VigenereAnalysis::textPreparing(old_text);
			save_changes(old_text);
			return new_text;
			
		}



	} textChanges; // Экземпляр класса хранящий все изменения

	//Функция сохраняет последние изменения
	String^ changeTextUp(String^ old_text) { return textChanges.changeTextUp(old_text); }

	//Функция откатывает последние изменения
	String^ changeTextDown() { return textChanges.changeTextDown(); }
	
	// Функция передаёт исходный текст
	String^ getFirstText() { return textChanges.getFirstText();  }

	// Функция передаёт последний текст
	String^ getLastText() { return textChanges.getLastText(); }

}