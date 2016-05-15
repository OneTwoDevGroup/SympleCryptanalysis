#pragma once
#define MAXALPHLEN 40

namespace VigenereAnalysis {

	using namespace System;

	// Функция подбора длины ключа
	int KasiskiExamination(String^ text);



	//// Функция подбирает ключ, основываясь на длине ключа, используя частотный анализ
	//String^ keyDetermination(String^ text, int **conformity);

	// Функция дешифрует текст
	String^ textPreparing(String^ *text, int **conformity);

}