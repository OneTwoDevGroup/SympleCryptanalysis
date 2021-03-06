#include <math.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include <wctype.h>
#include "gcroot.h"
#include <msclr/marshal_cppstd.h>
#include <regex>
#include <malloc.h>
#include "WordProcessing.h"


#define MAXALPHLEN 40    // Максимальная длина алфавита

WordProcessing::Alphabit alph("rus");



namespace FrequencyAnalysis {

	using namespace System;
	using namespace msclr::interop;

	// Подсчёт количества каждой буквы в тексте
	int *lettersAmount(String^ text) {

		int *letters_amount = (int*)malloc(MAXALPHLEN * sizeof(int));

		for (int i = 0; i < alph.length; i++) letters_amount[i] = 0;

		for (unsigned long i = 0; i < text->Length; i++) {
			if (alph.isLetter(text[i]))	letters_amount[text[i] - alph.firstchar]++;
		}

		return letters_amount;
	}

	// Подсчёт частот букв в заданном тексте
	double *frequencyDetermination(String^ text = nullptr, int *letters_amount = NULL) {

		double *frequency = (double*)malloc(MAXALPHLEN * sizeof(double));

		if (!letters_amount) letters_amount = lettersAmount(text);

		int total_amount = 0;
		for (int i = 0; i < alph.length; i++) total_amount += letters_amount[i];


		for (int i = 0; i < alph.length; i++)
			frequency[i] = (double)letters_amount[i] / (double)total_amount;

		return frequency;
	}

	// Поиск соответствий букв шифротекста буквам исходного алфавита 
	int *conformityDetermination(String^ text = nullptr, double *frequency = NULL, int *letters_amount = NULL) {

		if (!frequency) frequency = frequencyDetermination(text, letters_amount);

		int *conformity = (int*)malloc(MAXALPHLEN * sizeof(int));
		int sorted_freq_index[MAXALPHLEN];

		alph.formIndexing(frequency, sorted_freq_index);

		//for (int i = 0; i < alph.length; i++) sorted_freq_index[i] = i;

		//for (int i = 0; i < alph.length - 1; i++) {
		//	int max_id = i;
		//	for (int j = i + 1; j < alph.length; j++)
		//		if (frequency[sorted_freq_index[j]] > frequency[sorted_freq_index[max_id]])
		//			max_id = j;
		//	int tmp = sorted_freq_index[i];
		//	sorted_freq_index[i] = sorted_freq_index[max_id];
		//	sorted_freq_index[max_id] = tmp;
		//}

		for (int i = 0; i < alph.length; i++)
			conformity[sorted_freq_index[i]] = alph.freq_sorted_index[i];

		return conformity;
	}

	// Функция нахождения наилучшего сдвига в алфавите
	int shiftDetermination(String^ text, int *conformity) {

		// Подсчёт частот в заданном тексте
		double *frequency = frequencyDetermination(text);

		// Подбор сдвига
		double difference, min_difference = MAXDWORD; int best_shift = 0;
		for (int i = 0; i < alph.length; i++) {
			difference = 0;
			for (int j = 0; j < alph.length; j++) {
				difference += abs(frequency[(j + i) % alph.length] - alph.frequency[conformity[j]]);
			}
			if (difference < min_difference) {
				min_difference = difference;
				best_shift = i;
			}
		}

		return best_shift;
	}

	//// Поиск соответствий
	//int *conformityDeducing(double *frequency) {


	//	double first_eps, second_eps, eps; int first_loc, second_loc;

	//	int  first_conformity[MAXALPHLEN], second_conformity[MAXALPHLEN];
	//	for (int i = 0; i < alph.length; i++) first_conformity[i] = second_conformity[alph.length - i] = i;
	//	bool first_chosen[MAXALPHLEN] = { false }, second_chosen[MAXALPHLEN] = { false };

	//	int chosen_amount = 0;

	//	while (chosen_amount < alph.length) {

	//		for (int i = 0; i < alph.length; i++) {

	//			if (first_conformity[alph.frequencyIndexing[i]] == second_conformity[alph.frequencyIndexing[i]]) continue;

	//			first_eps = second_eps = 100.0;
	//			first_loc = i; second_loc = alph.length - i;

	//			for (int j = 0; j < alph.length; j++) {

	//				eps = fabs(frequency[j] - alph.frequency[alph.frequencyIndexing[i]]);
	//				if (!first_chosen[j] && eps < first_eps) {
	//					first_eps = eps;
	//					first_loc = j;
	//				}

	//				eps = fabs(frequency[alph.length - j] - alph.frequency[alph.frequencyIndexing[alph.length - i]]);
	//				if (!second_chosen[alph.length - j] && eps < second_eps) {
	//					second_eps = eps;
	//					second_loc = alph.length - j;
	//				}
	//			}

	//			first_conformity[alph.frequencyIndexing[i]] = first_loc;
	//			first_chosen[first_loc] = true;

	//			second_conformity[alph.frequencyIndexing[alph.length - i]] = second_loc;
	//			second_chosen[second_loc] = true;
	//		}

	//		chosen_amount = 26;

	//		for (int i = 0; i < alph.length; i++) {

	//			if (first_conformity[alph.frequencyIndexing[i]] != second_conformity[alph.frequencyIndexing[i]]) {
	//				second_chosen[i] = first_chosen[i] = false;
	//				chosen_amount--;
	//			}

	//		}
	//	}

	//	return first_conformity;
	//}





	// //Функция частотного анализа текста
	//int *analysis(String^ text) {


	//	double *frequency = frequencyCalculating(text);

	//	int *conformity = conformityDeducing(frequency);

	//	return conformity;


	//}

}