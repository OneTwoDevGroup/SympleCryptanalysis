#pragma once
#include "stdio.h"
using namespace System;

namespace FrequencyAnalysis {

	// Функция нахождения наилучшего сдвига в алфавите
	int shiftDetermination(String^ text, int *conformity);
	
	// Подсчёт количества каждой буквы в тексте
	int *lettersAmount(String^ text);
	
	// Поиск соответствий букв шифротекста буквам исходного алфавита 
	int *conformityDetermination(String^ text = nullptr, double *frequency = NULL, int *letters_amount = NULL);

	// Подсчёт частот букв в заданном тексте
	double *frequencyDetermination(String^ text = nullptr, int *letters_amount = NULL);
}