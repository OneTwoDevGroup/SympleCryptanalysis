#pragma once
#include "stdio.h"
using namespace System;

namespace FrequencyAnalysis {

	// Функция нахождения наилучшего сдвига в алфавите
	int shiftDetermination(String^ text, int *conformity);
	
	// Поиск соответствий букв шифротекста буквам исходного алфавита 
	int *conformityDetermination(double *frequency);

	// Подсчёт частот букв в заданном тексте
	double *frequencyDetermination(String^ text);
}