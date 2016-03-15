#include <math.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include <wctype.h>
#include "gcroot.h"
#include <msclr/marshal_cppstd.h>


#define MAXALPHLEN 40    // Максимальная длина алфавита
#define ARRAY_SIZE 1000  // Максимальная длина массива изменений


namespace WordProcessing {

	using namespace System;
	using namespace msclr::interop;


	// Класс определяет используемый алфавит, 
	// все данные о требуемом алфавите берутся и файла Configs/langsFile.lng
	// В файле содержатся данные о положениях первого и последнего символа алфавита 
	// нижнего регистра в Unicode таблице, количество символов в алфавите и частотное распределение
	class Alphabit {
	public:
		int firstchar, lastchar, length;
		double freaquancy[MAXALPHLEN] = { 0.0 };

		Alphabit(String^ lang) {
			getDataFor(lang);
		}

	private:
		void getDataFor(String^ lang) {
			using namespace std;
			ifstream langsFile("Configs/langsFile.lng");
			string str;
			while (getline(langsFile, str) && String::Compare(marshal_as<String^>(str), lang));
			langsFile >> firstchar >> lastchar >> length;
			for (int i = 0; i < length; i++) langsFile >> freaquancy[i];
			langsFile.close();
		}

	};
	Alphabit alph("rus"); // Объявление используемого алфавита


						  // Класс управляет изменениями в тексте и таблице частот по ходу работы для возможности отката изменений
	class Changes {
	public:
		gcroot<array<System::String ^>^> textChanges = gcnew array<System::String^ >(ARRAY_SIZE);       // Массив, содержащий все варианты изменённого текста
		gcroot<array<System::String ^>^> freaquancyChanges = gcnew array<System::String^ >(ARRAY_SIZE); // Массив, содержащий все варианты изменённой таблицы частот
		wchar_t conformityChanges[ARRAY_SIZE][MAXALPHLEN] = { 0 };										// Массив, содержащие все варианты изменения соответствий частот
		int changedConformityIndex[ARRAY_SIZE][MAXALPHLEN] = { 0 };                                     // Массив, содержащий все варианты изменённых соответствий частот
		int indexChangesAmount[ARRAY_SIZE] = { 0 };                                                     // Массив, содержащий все варианты количества соответствий частот
		int last = -1;                                                                                  // Переменная определяет позицию в массивах последних изменений 

																										// Функция сохраняет изменения
		int save_changes(String^ text, wchar_t *conformity, String^ freaquancyTable) {

			last++;

			textChanges[last % ARRAY_SIZE] = text;
			freaquancyChanges[last % ARRAY_SIZE] = freaquancyTable;
			memcpy(conformityChanges[last % ARRAY_SIZE], conformity, alph.length * sizeof(wchar_t));

			if (last != 0) {
				int changesAmount = 0;

				for (int i = 0; i < alph.length; i++)
					if (conformityChanges[last][i] != conformityChanges[last - 1][i]) {
						changedConformityIndex[last][changesAmount] = i;
						changesAmount++;
					}

				if (changesAmount == 0) { last--; return 0; }
				indexChangesAmount[last] = changesAmount;
			}
			else {
				for (int i = 0; i < alph.length; i++)
					changedConformityIndex[last][i] = i;
				indexChangesAmount[last] = alph.length;
			}

			return 1;

		}

		// Функция возвращает последние изменения для отката
		int getLast(String^ *text, String^ *freaquancyTable)
		{
			if (last == -1) return 0;
			*text = textChanges[last % ARRAY_SIZE];
			if (last == 0) *freaquancyTable = freaquancyChanges[last % ARRAY_SIZE];
			else *freaquancyTable = freaquancyChanges[(last - 1) % ARRAY_SIZE];
			last--;
			return 1;
		}

		// Функция передаёт исходный текст
		String^ getFirstText() { return textChanges[0]->ToLower(); }
	};
	Changes textChanges; // Объявление переменной для хранения изменений

						 // Функция сохраняет последние изменения
	String^ ChangeTextUp(String^ text, String^ freaquancyTable) {

		wchar_t conformity[MAXALPHLEN];
		array< String^ >^ freaquancies = freaquancyTable->Split('%', '\r', '\n');
		for (int i = 0; i < alph.length; i++)
			conformity[i] = freaquancies[i * 3][2];

		if (!textChanges.save_changes(text, conformity, freaquancyTable)) return text;

		text = textChanges.getFirstText();

		for (int i = 0; i < alph.length; i++)
			text = text->Replace(wchar_t(i + alph.firstchar) + "", (conformity[i] + "")->ToUpper());


		return text->ToLower();
	}


	// Функция откатывает последние изменения
	int ChangeDown(String^ *text, String^ *freaquancyTable) { return textChanges.getLast(text, freaquancyTable); }
}