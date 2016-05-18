#pragma once
#define MAXALPHLEN 40

namespace VigenereAnalysis {

	using namespace System;

	//// Функция подбирает ключ, основываясь на длине ключа, используя частотный анализ
	//String^ keyDetermination(String^ text, int **conformity);

	// Функция дешифрует текст
	String^ textPreparing(String^ *text, int **conformity, String ^key = nullptr);

	// Поиск сдвигов
	String ^keyDetermination(array<System::String ^>^ *keys, array<System::String ^>^ groups, int key_length);

	int* result(int* besti1, int *besti2);

	// Функция подбора длины ключа
	int* KasiskiExamination(String^ text);

	int* Index(String^ text);

	void splitIntoGroups(String^ text, int key_length, array<System::String ^>^ groups);

	String^ shiftLettersInText(String^ text, String^ key, int *conformity);
}