#pragma once


namespace IndexOfСoincidence {

	using namespace System;

	// Функция находит длину ключа, используя метод индекса совпадений
	void keyLengthSearch();		

	// Функция подбирает ключ, основываясь на длине ключа, используя частотный анализ
	String^ keySearch(String^ text);		

	// Функция дешифрует текст
	String^ preparingText(String^ text);	
}

