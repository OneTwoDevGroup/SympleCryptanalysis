#pragma once
#include "stdio.h"

#define MAXALPHLEN 40    // Максимальная длина алфавита

namespace WordProcessing {
	using namespace System;

	// Класс определяет используемый алфавит
	class Alphabit {
	public:
		int firstchar, lastchar, length;
		double frequency[MAXALPHLEN];
		int freq_sorted_index[MAXALPHLEN];

		// Конструктор класса
		Alphabit(String^ lang);

		// Функция формирует букву по соответствующей ей позиции в алфавите
		__declspec(dllexport) wchar_t getLetter(int num);

		// Функция проверяет символ на соответствие букве
		__declspec(dllexport) bool isLetter(int num);

		// Инициализация массива индексов для соответствия отсортированному массиву по частоте
		__declspec(dllexport) void formIndexing(double *frequency, int *frequency_indexing);
	};

	//Функция сохраняет последние изменения
	String^ changeTextUp(String^ *text, String^ *conformity_table, int *conformity = NULL, String ^key = nullptr);

	//Функция откатывает последние изменения
	String^ changeTextDown(String^ *text, String^ *conformity_table);

	// Функция передаёт исходный текст
	String^ getFirstText();

	// Функция передаёт последний текст
	String^ getLastText();

	// Функция передаёт последнюю таблицу соответствий
	int *getLastConformity();
}
