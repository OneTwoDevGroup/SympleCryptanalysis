#pragma once

#define MAXALPHLEN 40    // Максимальная длина алфавита

namespace WordProcessing {
	using namespace System;

	// Класс определяет используемый алфавит
	class Alphabit {
	public:
		int firstchar, lastchar, length;
		double freaquancy[MAXALPHLEN];

		// Конструктор класса
		Alphabit(String^ lang);

		// Функция формирует букву по соответствующей ей позиции в алфавите
		__declspec(dllexport) wchar_t getLetter(int num);

		// Функция проверяет символ на соответствие букве
		__declspec(dllexport) bool isLetter(int num);
	};

	//Функция сохраняет последние изменения
	String^ changeTextUp(String^ old_text);

	//Функция откатывает последние изменения
	String^ changeTextDown();

	// Функция передаёт исходный текст
	String^ getFirstText();

	// Функция передаёт последний текст
	String^ getLastText();
}
