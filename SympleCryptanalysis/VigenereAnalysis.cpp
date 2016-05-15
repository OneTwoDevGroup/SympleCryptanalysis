﻿#include "stdio.h"
#include <msclr/marshal.h>
#include "string.h"
#include "malloc.h"
#include <fcntl.h>
#include <io.h>

#include <fstream>
#include <string>

#include "WordProcessing.h"
#include "FrequencyAnalysis.h"

#define N 5000
#define r 256// ASCII
#define R 33 //Мощность языка
#define u 20 // предполагаемая максимальная длина ключа
#define MAXHIGH 255 // верхний предел в котором находятся буквы
#define MAXLOW  224 // нижний

#define MAXKEYLEN 100
#define MAXKEYAMOUNT 100

// Константы определяют размер кэша для биномиальных коэффициентов
#define BCR_N_MAX 10000
#define BCR_K_MAX 10000


unsigned bcr_cache[BCR_N_MAX][BCR_K_MAX] = { 0 };
// Функция вычисляет биномиальный коэффициент
unsigned bcr(int n, int k) {
	if (k > n / 2) k = n - k;
	if (k == 1)  return n;
	if (k == 0)  return 1;
	if (bcr_cache[n][k] == 0)
		bcr_cache[n][k] = bcr(n - 1, k) + bcr(n - 1, k - 1);
	return bcr_cache[n][k];
}


namespace VigenereAnalysis {

	using namespace System;
	WordProcessing::Alphabit alph("rus"); // Класс определяет используемый язык
	int* Index (String^ text)
	{
//char alf[R] = { 'А','Б','В','Г','Д','Е','Ж','З','И','Й','К','Л','М','Н','О','П','Р','С','Т','У','Ф','Х','Ц','Ч','Ш','Щ','Э','Ъ','Ы','Ь','Ю','Я' };
		unsigned 	char alf[R] = { 'а','б','в','г','д','е','ж','з','и','й','к','л','м','н','о','п','р','с','т','у','ф','х','ц','ч','ш','щ','э','ъ','ы','ь','ю','я' };

		unsigned char *S = (unsigned char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(text);
		int i, j,l,k;
		float IS[u][u];
		int n = 0,f=0,g;
		int size = strlen((const char*)S);
		for (i = 1; i < u; i++)
		{
			
			for (k = 0; k < i; k++)
			{
				IS[i][k] = 0.0;
				for (j = 0; j < R - 1; j++)
				{
					n = 0;
					f = 0;
					l = 0;
					g = i-k;
					while(l < size)
					{
						while ((g < i)&& (l < size))
						{
							while ((l < size) && ((S[l] <MAXLOW) || (S[l]>MAXHIGH)))
							{
							l++;
						}
							g++;
							l++;
							
						}
						while ((l < size) && ((S[l] <MAXLOW) || (S[l]>MAXHIGH)))
						{
							l++;
						}
						g = 0;
						if (((l < size)) && (S[l] == alf[j]))
						{
							n++;
							f++;
						}
						else
						{
						n++;
						}
										  // Функция подбора длины ключа
					}
					IS[i][k] += f*(f - 1);	
				}
				IS[i][k] /= n*(n - 1);
			}
		}

		float average;
		float max = FLT_MAX;
		float mindx;
		static int besti2[u] = {0};
		/*for (i = 0; i < u; i++)
		{
			max = MAXINT64;
			for (j = 2; j < u; j++)
			{
				mindx = 0;
				for (k = 0; k<j; k++)
				{

					if (fabs(IS[j][k] - 0.55)>mindx)
						if (IS[j][0]>-0.5)
						mindx = fabs(IS[j][k] - 0.55);
				}
				if ((mindx < max)&&(IS[j][0]>-0.5))
				{
					max = mindx;
					
					besti[i] = j;
					
				}

			}
			
			
				IS[besti[i]][0] = -1;
			
		}
		*/
		/*for (i = 1; i < u; i++)
		{
			mindx = 0;
			for (j = 0; j < i; j++)
			{
				if (fabs(IS[i][j] - 0.55)>mindx)
					mindx = fabs(IS[i][j] - 0.55);
			}
			
			if (mindx <max)
			{
				max = mindx;
				besti =i;
			}
		}*/
		for (i = 0; i < u; i++)
		{
			max = MAXINT64;
			for (j = 2; j < u; j++)
			{
				mindx = 0;
				for (k = 0; k < j; k++)
				{
					mindx += fabs(IS[j][k] -0.0550);

				}
				mindx /= k;
				if ((mindx < max) && (IS[j][0]>-0.5))
				{
					max = mindx;
					besti2[i] = j;
				}
			}
			IS[besti2[i]][0] = -1;
		}
		return besti2;
	}
	// Функция подбора длины ключа
	int* KasiskiExamination(String^ text)
	{
		int size;
		//char alf[R] = { 'a','b','c','d','e','f','h','i','j','k','l','m','n','o','p','r','s','t','u','w','v','q','z','g' ,'x' };//буквы английского алфавита
		unsigned char alf[R] = { 'а','б','в','г','д','е','ж','з','и','й','к','л','м','н','о','п','р','с','т','у','ф','х','ц','ч','ш','щ','э','ъ','ы','ь','ю','я' };
		char buff[100];										//Для копирование строк
		int** lenght_distance;								//в lenght_distane[][0] заносится длина совпадения, в lenght_distance[][1] расстояние между совпадениями
		char **matched;										//массив с совпавшими значениями
		int max_match_sum = 0;								//кол-во одинаковых совпадений
		int max_match_ind = -1;								// индекс максимального совпадения кол-ва
		//int* count_matched;								// массив кол-ва совпадений
		int w = 0;											// номер совпадения
		int max_lenght_matched = 0;							//максимальное совпадение по длине
		int max_lenght_distance = 0;                        //максимальное расстояние между совпадениями
		int max_m = -1;										//индекс; максимального совпадения
		int dopmax, maxind;									// множитель и текущая длина ключа
		float best;
		bool flag = 1;
		int i = 0, j, l, g, z, s,k,f;							//счетчики

															//строка с шифром//место поиска
		unsigned char *S =(unsigned char*) ( char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(text);

		i = 0;
		size = strlen((const char*)S);

		matched = (char**)malloc(sizeof(char*));
		lenght_distance = (int**)malloc(sizeof(int*));
		

		for (i = 0; i < R; i++)								// i-прогоняемся по всем символам алфавита
		{
			for (j = 0; j < size; j++)						// ищем все символы Alf[i] в S[]
				if (S[j] == alf[i])
				{
					s = 0;									//счетчик пробелов
					for (l = j + 1; l < size; l++)			// l - ищем все символы Alf[i] в строке S[j+]
					{
						if ((S[l] < MAXLOW) || (S[l]>MAXHIGH))//отбрасываем пробельные символы
						{
							s++;
						}
						if (S[l] == alf[i])
						{	
							g = 0;                         
							k = 0;
							f = 0;
							while (((l + g+f) < size) && ((j + g+k) < size) && ((S[l + g+f] == S[j + g+k])))
							{
								g++;						//g считаем сколько символов совпало
								while (((l + g + f) < size) && ((j + g + k) < size)&& ((S[l + g + f] < MAXLOW) || (S[l + g + f]>MAXHIGH))) // отбрасываем пробельные символы
								{
									f++;
								}
								while (((l + g + f) < size) && ((j + g + k) < size)&& ((S[j + g + k] < MAXLOW) || (S[j + g + k]>MAXHIGH))) // отбрасываем пробельные символы
								{
									k++;
								}
							}
							if (g > 3)
							{
								matched = (char**)realloc(matched, (sizeof(char*)*(w + 1)));
								matched[w] = (char*)malloc(1);
								for (z = 0; z < g+k; z++)
								{
									matched[w] = (char*)realloc(matched[w], sizeof(char)*(z + 2));
									matched[w][z] = S[j + z];
								}
								matched[w][z] = '\0';
								lenght_distance = (int**)realloc(lenght_distance, sizeof(int*)*(w + 1));
								lenght_distance[w] = (int*)malloc(2 * (sizeof(int)));
								lenght_distance[w][0] = g;													// длина совпадения
								lenght_distance[w][1] = l - j - s;											// расстояние между совпадениями
								w++;																		//счетчик совпадений
							}
						}
					}
				}
		}
		/*
		max_lenght_matched = 0;
		max_lenght_distance = 0;
		for (j = 0; j < w; j++)

		{
			if (lenght_distance[j][1]>max_lenght_distance)
			{
				max_lenght_distance = lenght_distance[j][1];
			}
			if (lenght_distance[j][0]>max_lenght_matched)
			{
				max_lenght_matched = lenght_distance[j][0];													// выбираем самое максимальное совпадение и растояние между ними( cчитаем его 100%)
				max_m = j;
			}
		}*/
		/*
		count_matched = (int*)calloc(w, sizeof(int));
		for (i = 0; i < w - 1; i++)
		{
			s = 1;
			for (j = i; j < w; j++)
			{
				z = 0;
				if (!strcmp(matched[i], matched[j]))
				{
					count_matched[i]++;
					count_matched[j]++;
					s++;
				}
			}
			if ((max_match_sum < s))
			{
				max_match_sum = s;
				max_match_ind = i;
			}
		}*/

//		float* h;
//		h = (float*)malloc(sizeof(float));
		float h[u];
		for (j = 2; j <u; j++)
		{
			//h = (float*)realloc(h, (j + 1)*(sizeof(float)));
			h[j] = 0;
			for (i = 0; i < w; i++)
			{
				if ((lenght_distance[i][1] % j) == 0)
				{
					h[j] +=1.0;
					/*if (lenght_distance[i][0]>5)
					{
						if (count_matched[i]>2 * max_match_sum / 3)
							h[j] += 4.0*count_matched[i]*lenght_distance[i][0] * lenght_distance[i][0];
						else
						{
							h[j] += 2.0*lenght_distance[i][0] * lenght_distance[i][0];
						}
					}
					else
					{
						if (count_matched[i]>2 * max_match_sum / 3)
							h[j] += 2.0*lenght_distance[i][0] * lenght_distance[i][0];
						else
							h[j] += 1.0*lenght_distance[i][0] * lenght_distance[i][0];
					}
				}*/

				}
			}
		}
	static int besti[u];

		/*h[0] = 1;
		best = 1.0;
		maxind = 1;

		while (TRUE)
		{
			dopmax = 0;
			for (j = 2; j < max_lenght_distance; j++)
			{
				if (h[dopmax] < h[j])
				{
					dopmax = j;
				}
			}
			if ((dopmax*maxind<max_lenght_distance) && (best / h[dopmax*maxind] <1.05))
			{
				maxind = dopmax*maxind;
				best = h[maxind];
			}
			else
			{
				h[dopmax] = 1;
			}
			if (dopmax == 0)
				break;
		}*/
		
		float max;
		for (i = 0; i < u; i++)
		{
			max = -0.5;
			for (j = 2; j < u;j++)
				if (h[j]>max)
				{
					max = h[j];
					maxind = j;
				}
			besti[i] = maxind;
			h[maxind] = -1;
		}
		//ЗАЧИСТКА
		//free(count_matched);
		for (i = 0; i < w; i++)
		{
			free(matched[i]);
			free(lenght_distance[i]);
		}
		free(matched);
		free(lenght_distance);
		//free(h);

		return besti;
	}

	int* result(int* besti1, int *besti2)
	{
		int i, j, best,k,max1,max2;
		float min;
		static int result[u];
		for (k = 0; k < u; k++)
		{
			min = LONG_MAX;
			best = 0;
			max1 = 0;
			max2 = 0;
			for (i = 0; i < u; i++)
			{
				for (j = 0; j < u; j++)
				{
					if ((besti1[i] == besti2[j]) && (i + j < min))
					{
						if (besti1[i] && besti2[j])
						{
							min = i + j;
							best = besti1[i];
							max1 = i;
							max2 = j;
						}
						
					}
				}
			}
			result[k] = best;
			besti1[max1] = 0;
			besti2[max2] = 0;
		}
		return result;
	}

	// Разбиение текста на группы, согласно найденной длине ключа
	void splitIntoGroups(String^ text, int key_length, array<System::String ^>^ groups) {
		int not_letters = 0; // Опеределяет количество небуквенных символов, которые нужно пропустить
		for (int j = 0; j < text->Length; j++) {
			if (!alph.isLetter(text[j])) { not_letters++; continue; }
			groups[(j - not_letters) % key_length] += text[j];
		}

	}

	// Строит таблицу соответствий для исходного алфавита в квадрате Виженера
	int *conformityDetermination(array<System::String ^>^ groups, String^ key) {

		int *letters_amount = FrequencyAnalysis::lettersAmount(groups[0]);

		for (int i = 1; i < key->Length; i++) {

			int shift = (alph.length + key[0] - key[i]) % alph.length;
			int *group_letters_amount = FrequencyAnalysis::lettersAmount(groups[i]);

			for (char letter = 0; letter < alph.length; letter++)
				letters_amount[letter] += group_letters_amount[(letter + shift) % alph.length];
		}

		return FrequencyAnalysis::conformityDetermination(nullptr, NULL, letters_amount);

	}

	// Подбор ключа
	String^ keyDetermination(array<System::String ^>^ groups, int key_length) {

		double conformoty_probability[u][MAXALPHLEN][MAXALPHLEN] = { 0 };

		double amount_probolity[MAXALPHLEN][MAXALPHLEN] = { 0 };

		double shift_probobility[u][u][MAXALPHLEN];

		for (int k = 0; k < key_length; k++) {

			int *group_frequency = FrequencyAnalysis::lettersAmount(groups[k]);

			for (int j = 0; j < alph.length; j++) {
				for (int i = 0; i < alph.length; i++) {
					amount_probolity[j][i] = bcr(groups[k]->Length, group_frequency[j]) * pow(alph.frequency[i] / 100, group_frequency[j]) *
						pow(1 - alph.frequency[i] / 100, groups[k]->Length - group_frequency[j]);
				}

				double sum_amount_probolity = 0;

				for (int m = 0; m < alph.length; m++) sum_amount_probolity += amount_probolity[j][m];

				for (int i = 0; i < alph.length; i++)
					conformoty_probability[k][i][j] = amount_probolity[j][i] / sum_amount_probolity;
			}
		}


		for (int k = 0; k < key_length; k++)

			for (int l = 0; l < key_length; l++) {

				double sum_shift_probobility = 0;

				for (int shift = 0; shift < alph.length; shift++) {

					shift_probobility[k][l][shift] = 1;

					for (int j = 0; j < alph.length; j++) {

						double sum_conformity_probolity = 0;

						for (int i = 0; i < alph.length; i++)
							sum_conformity_probolity += conformoty_probability[k][i][j] * conformoty_probability[l][(i + shift) % alph.length][j];


						shift_probobility[k][l][shift] *= sum_conformity_probolity;
					}

					sum_shift_probobility += shift_probobility[k][l][shift];
				}

				for (int shift = 0; shift < alph.length; shift++)
					shift_probobility[k][l][shift] /= sum_shift_probobility;
			}

		int shifts[MAXKEYAMOUNT] = { 0 };


		//for (int l = 0; l < key_length; l++) {

		//	double max_coef = 0; int best_shift;

		//	for (int shift = 0; shift < alph.length; shift++) {
		//		
		//		double coef = 0;
		//		
		//		for (int k = 0; k < key_length; k++)
		//			coef += shift_probobility[k][l][shift];

		//		if (max_coef < coef) {
		//			max_coef = coef;
		//			best_shift = shift;
		//		}

		//	}

		//	shifts[l] = best_shift;

		//}



		//array<System::String ^>^ keys = gcnew array<System::String^>(MAXKEYAMOUNT);

		//for (int shift = 0; shift < alph.length; shift++)
		//	for (int i = 0; i < key_length; i++)
		//		keys[shift] += alph.getLetter(shifts[i] + shift);

		
		std::ifstream dictionary("Configs/russian_dictionary.dic");
		std::string word;

		array<System::String ^>^ best_words = gcnew array<System::String^>(1000);

		double best_coef = 0;
		//string best_word[1000];
		

		int amount = 0;
		//double eps = 0.19400000000000015;

		//do {
		//	
		//	eps += 0.001;
		//	amount = 0;
		//	dictionary.clear();
		//	dictionary.seekg(0, ios::beg);

		while (dictionary) {
				
			getline(dictionary, word); int len = word.length();
			if (len != key_length) continue;

			double coef = 0;

			for (int i = 0; i < key_length; i++)
				for (int j = 0; j < key_length; j++) {
					if (i == j) continue;
					coef += shift_probobility[i][j][(alph.length + word[i] - word[j]) % alph.length];
				}
			if (coef > best_coef )	best_coef = coef;

		}

		double eps = 0;
		dictionary.clear();
		dictionary.seekg(0, std::ios::beg);

		while (dictionary) {

			getline(dictionary, word); int len = word.length();
			if (len != key_length) continue;

			double coef = 0;

			for (int i = 0; i < key_length; i++)
				for (int j = 0; j < key_length; j++) {
					if (i == j) continue;
					coef += shift_probobility[i][j][(alph.length + word[i] - word[j]) % alph.length];
				}
			if (fabs(coef - best_coef) <= eps) {
				best_coef = coef;
				best_words[amount % 1000] = gcnew String(word.c_str());;
				amount++;
			}

		}

		

		return best_words[0];
	}
	


	//// Функция подбирает ключ, основываясь на длине ключа, используя частотный анализ
	//String^ keyDetermination(String^ text, int **conformity) {

	//	// Определяем длину ключа
	//	int* lenght = (result(KasiskiExamination(text), Index(text)));
 //       int key_length = result(KasiskiExamination(text), Index(text))[0];
	//	//int key_length = 7;
	//	//for (i = 0; i < u; i++)
	//	//	lenght++;
	//	//	int key_length = *(result(KasiskiExamination(text), Index(text)));

	//	// Задаём массив групп, на которые разбивается текст в зависимости от длины ключа
	//	array<System::String ^>^ groups = gcnew array<System::String^>(MAXKEYAMOUNT);

	//	// Задаём переменную под хранение ключа
	//	String^ key;

	//	// Цикл заполняет группы
	//	int not_letters = 0; // Опеределяет количество небуквенных символов, которые нужно пропустить
	//	for (int j = 0; j < text->Length; j++) {
	//		if (!alph.isLetter(text[j])) { not_letters++; continue; }
	//		groups[(j - not_letters) % key_length] += text[j];
	//	}
	//	
	//	double *text_frequency = FrequencyAnalysis::frequencyDetermination(groups[0]);
	//	int shifts[MAXKEYAMOUNT] = { 0 };
	//	for (int i = 1; i < key_length; i++) {

	//		double *group_frequency = FrequencyAnalysis::frequencyDetermination(groups[i]);
	//		long double max_conformity_coef = 0; int best_shift;

	//		for (int shift = 0; shift < alph.length; shift++) {
	//			long double conformity_coef = 0;
	//			for (char letter = 0; letter < alph.length; letter++)
	//				conformity_coef += text_frequency[letter] * group_frequency[(letter + shift) % alph.length];

	//			if (max_conformity_coef < conformity_coef) {
	//				max_conformity_coef = conformity_coef;
	//				best_shift = shift;
	//			}
	//		}

	//		shifts[i] = best_shift;

	//		//int best_shift = shifts[i];

	//		for (char letter = 0; letter < alph.length; letter++)
	//			text_frequency[letter] = (text_frequency[letter] + group_frequency[(letter + best_shift) % alph.length]) / 2;

	//	}



	//	// Отладочная информация
	//	FILE *log_file = fopen("Configs/log.txt", "w+");
	//	_setmode(_fileno(log_file), _O_U8TEXT);

	//	fwprintf(log_file, L"Таблица частот для всего текста суммарно:\n");
	//	for (int i = 0; i < alph.length; i++)
	//		fwprintf(log_file, L"%lc - %lf\n", alph.getLetter(i), text_frequency[i]);
	//	fclose(log_file);
	//	// Отладочная информация


	//	*conformity = FrequencyAnalysis::conformityDetermination(text_frequency);

	//	// Цикл делает частотный анализ для каждой группы и формирует ключ
	//	for (int i = 0; i < key_length; i++)
	//		//key += alph.getLetter(FrequencyAnalysis::shiftDeducing(groups[i], conformity));
	//		key += alph.getLetter(shifts[i]);


	//	return key;
	//}


	// Функция дешифрует текст
	String^ textPreparing(String^ text) {

		// Определяем длину ключа
		int* lenght = (result(KasiskiExamination(text), Index(text)));
		int key_length = result(KasiskiExamination(text), Index(text))[0];

		// Разбиваем текст на группы
		array<System::String ^>^ groups = gcnew array<System::String^>(MAXKEYAMOUNT);
		splitIntoGroups(text, key_length, groups);
		
		// Подбираем ключ
		String^ key = keyDetermination(groups, key_length);				
		
		// Таблицы соответствия букв шифротекста буквам исходного алфавита
		int *conformity = conformityDetermination(groups, key);			
		
		// Формируем изменяемую строку
		Text::StringBuilder text_builder(text);			

		// Заменяет символы текста в соответствии с ключом и квадратом Веженера
		int not_letters = 0;  // Опеределяет количество небуквенных символов, которые нужно пропустить
		for (int j = 0; j < text->Length; j++) {
			if (!alph.isLetter(text_builder[j])) { not_letters++; continue; }
			text_builder[j] = alph.getLetter(conformity[(alph.length + text_builder[j] - key[(j - not_letters) % key->Length] + key[0]) % alph.length]);
		}


		// Отладочная информация
		FILE *log_file = fopen("Configs/log.txt", "w+");
		fseek(log_file, 0, SEEK_END);
		_setmode(_fileno(log_file), _O_U8TEXT);

		fwprintf(log_file, L"\nКлюч: %LS\n\n", PtrToStringChars(key));

		fwprintf(log_file, L"Таблица моноалфавитного соответствия: \n");
		for (int i = 0; i < alph.length; i++)
			fwprintf(log_file, L"%lc - %lc\n", alph.getLetter(i), alph.getLetter(conformity[i]));

		fclose(log_file);
		// Отладочная информация

		return text_builder.ToString();				// Возвращаем изменённую строку
	}
}