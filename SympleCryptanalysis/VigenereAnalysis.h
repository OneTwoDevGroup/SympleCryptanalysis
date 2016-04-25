#pragma once

namespace VigenereAnalysis {

	using namespace System;

	// Функция подбора длины ключа
	int KasiskiExamination(String^ text);

	// Функция находит длину ключа, используя метод индекса совпадений
	void IndexOfСoincidence();

	// Функция подбирает ключ, основываясь на длине ключа, используя частотный анализ
	String^ keySearch(String^ text);

	// Функция дешифрует текст
	String^ preparingText(String^ text);

}