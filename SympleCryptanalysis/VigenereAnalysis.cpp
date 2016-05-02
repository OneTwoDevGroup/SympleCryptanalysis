﻿#include "stdio.h"
#include <msclr/marshal.h>
#include "string.h"
#include "malloc.h"
#include <fcntl.h>
#include <io.h>

#include "WordProcessing.h"
#include "FrequencyAnalysis.h"

#define N 5000
#define r 256// ASCII
#define R 33 //Мощность языка
#define u 20 // предполагаемая максимальная длина ключа

#define MAXKEYLEN 100
#define MAXKEYAMOUNT 100

namespace VigenereAnalysis {

	using namespace System;
	WordProcessing::Alphabit alph("rus"); // Класс определяет используемый язык
	int* Index (String^ text)
	{
		unsigned char alf[R] = { 'А','Б','В','Г','Д','Е','Ж','З','И','Й','К','Л','М','Н','О','П','Р','С','Т','У','Ф','Х','Ц','Ч','Ш','Щ','Э','Ъ','Ы','Ь','Ю','Я' };
		unsigned	char *S = (unsigned char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(text);
		int i, j,l,k;
		float IS[u][u];
		float n = 0,f=0;
		int size = strlen((const char*)S);
		for (i = 1; i < u; i++)
		{
			
			for (k = 0; k < i; k++)
			{
				n = 0;
				IS[i][k] = 0;
				for (j = 0; j < R - 1; j++)
				{
					f = 0;
					for (l = k; l < size; l += i)
					{
						while ( (l<size)&&((S[l] < 192) || (S[l]>223)))
						{
							l++;
						}
						if (((l<size))&&(S[l] == alf[j]))
						{
							f++;
						}
						n++;

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
		int besti[u] = {0};
		for (i = 0; i < u; i++)
		{
			for (j = i + 1; j < u; j++)
			{
				mindx = 0;
				for (k = 0; k<j; k++)
				{
					if (fabs(IS[i][j] - 0.55)>mindx)
						mindx = fabs(IS[i][j] - 0.55);
				}
				if (mindx < max)
				{
					max = mindx;
					besti[i] = j;
				}
			}
		}
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


		return besti;
	}
	// Функция подбора длины ключа
	int* KasiskiExamination(String^ text)
	{
		int size;
		//char alf[R] = { 'a','b','c','d','e','f','h','i','j','k','l','m','n','o','p','r','s','t','u','w','v','q','z','g' ,'x' };//буквы английского алфавита
		unsigned char alf[R] = { 'А','Б','В','Г','Д','Е','Ж','З','И','Й','К','Л','М','Н','О','П','Р','С','Т','У','Ф','Х','Ц','Ч','Ш','Щ','Э','Ъ','Ы','Ь','Ю','Я' };
		char buff[100];										//Для копирование строк
		int** lenght_distance;								//в lenght_distane[][0] заносится длина совпадения, в lenght_distance[][1] расстояние между совпадениями
		char **matched;		//массив с совпавшими значениями
		
		
		int max_match_sum = 0;								//кол-во одинаковых совпадений
		int max_match_ind = -1;								// индекс максимального совпадения кол-ва
		//int* count_matched;									// массив кол-ва совпадений
		int w = 0;											// номер совпадения
		int max_lenght_matched = 0;							//максимальное совпадение по длине
		int max_lenght_distance = 0;                        //максимальное расстояние между совпадениями
		int max_m = -1;										//индекс; максимального совпадения
		int dopmax, maxind;									// множитель и текущая длина ключа
		float best;
		bool flag = 1;
		int i = 0, j, l, g, z, s,k,f;							//счетчики

															//строка с шифром//место поиска
		unsigned	char *S = (unsigned char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(text);

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
						if ((S[l] < 192) || (S[l]>223))
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
								while (((l + g + f) < size) && ((j + g + k) < size)&& ((S[l + g + f] < 192) || (S[l + g + f]>223)))
								{
									f++;
								}
								while (((l + g + f) < size) && ((j + g + k) < size)&& ((S[j + g + k] < 192) || (S[j + g + k]>223)))
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

		float* h;
		h = (float*)malloc(sizeof(float));
		
		for (j = 2; j <max_lenght_distance; j++)
		{
			h = (float*)realloc(h, (j + 1)*(sizeof(float)));
			h[j] = 0;
			for (i = 0; i < w; i++)
			{
				if ((lenght_distance[i][1] % j) == 0)
				{
					h[j] ++;
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
		int besti[u];

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
			max = 0;
			for (j = i+1; j < u;j++)
				if (h[j]>max)
				{
					max = h[j];
					maxind = j;
				}
			besti[i] = maxind;
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
		free(h);

		return besti;
	}

	int* result(int* besti1, int *besti2)
	{
		int i, j, best,k,max1,max2;
		float min;
		int result[u];
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

	// Функция находит длину ключа, используя метод индекса совпадений
	


	// Функция подбирает ключ, основываясь на длине ключа, используя частотный анализ
	String^ keyDetermination(String^ text, int **conformity) {

		// Определяем длину ключа
		
        //int key_length = KasiskiExamination(text)[0];
		//int key_length = *(result(KasiskiExamination(text), Index(text)));
		int key_length = 4;

		// Задаём массив групп, на которые разбивается текст в зависимости от длины ключа
		array<System::String ^>^ groups = gcnew array<System::String^>(MAXKEYAMOUNT);

		// Задаём переменную под хранение ключа
		String^ key;

		// Цикл заполняет группы
		int not_letters = 0; // Опеределяет количество небуквенных символов, которые нужно пропустить
		for (int j = 0; j < text->Length; j++) {
			if (!alph.isLetter(text[j])) { not_letters++; continue; }
			groups[(j - not_letters) % key_length] += text[j];
		}

		double *text_frequency = FrequencyAnalysis::frequencyDetermination(groups[0]);

		int shifts[MAXKEYAMOUNT];
		for (int i = 1; i < key_length; i++) {

			double *group_frequency = FrequencyAnalysis::frequencyDetermination(groups[i]);
			long double max_conformity_coef = 0; int best_shift;

			for (int shift = 0; shift < alph.length; shift++) {
				long double conformity_coef = 0;
				for (char letter = 0; letter < alph.length; letter++)
					conformity_coef += text_frequency[letter] * group_frequency[(letter + shift) % alph.length];

				if (max_conformity_coef < conformity_coef) {
					max_conformity_coef = conformity_coef;
					best_shift = shift;
				}
			}

			shifts[i] = best_shift;
			for (char letter = 0; letter < alph.length; letter++)
				text_frequency[letter] = (text_frequency[letter] + group_frequency[(letter + best_shift) % alph.length]) / 2;

		}



		// Отладочная информация
		FILE *log_file = fopen("Configs/log.txt", "w+");
		_setmode(_fileno(log_file), _O_U8TEXT);

		fwprintf(log_file, L"Таблица частот для всего текста суммарно:\n");
		for (int i = 0; i < alph.length; i++)
			fwprintf(log_file, L"%lc - %lf\n", alph.getLetter(i), text_frequency[i]);
		fclose(log_file);
		// Отладочная информация


		*conformity = FrequencyAnalysis::conformityDetermination(text_frequency);

		// Цикл делает частотный анализ для каждой группы и формирует ключ
		for (int i = 0; i < key_length; i++)
			//key += alph.getLetter(FrequencyAnalysis::shiftDeducing(groups[i], conformity));
			key += alph.getLetter(shifts[i]);


		return key;
	}

	// Функция дешифрует текст
	String^ textPreparing(String^ text) {

		int **conformity = (int**)malloc(1);			// Таблицы соответствия букв шифротекста буквам исходного алфавита
		String^ key = keyDetermination(text, conformity);	// Подбираем ключ
		Text::StringBuilder text_builder(text);			// Формируем изменяемую строку

														// Заменяет символы текста в соответствии с ключом и квадратом Веженера
		int not_letters = 0;  // Опеределяет количество небуквенных символов, которые нужно пропустить
		for (int j = 0; j < text->Length; j++) {
			if (!alph.isLetter(text_builder[j])) { not_letters++; continue; }
			text_builder[j] = alph.getLetter((*conformity)[(alph.length + text_builder[j] - key[(j - not_letters) % key->Length])% alph.length]);
		}


		// Отладочная информация
		FILE *log_file = fopen("Configs/log.txt", "r+");
		fseek(log_file, 0, SEEK_END);
		_setmode(_fileno(log_file), _O_U8TEXT);

		fwprintf(log_file, L"\nКлюч: %LS\n\n", PtrToStringChars(key));

		fwprintf(log_file, L"Таблица моноалфавитного соответствия: \n");
		for (int i = 0; i < alph.length; i++)
			fwprintf(log_file, L"%lc - %lc\n", alph.getLetter(i), alph.getLetter((*conformity)[i]));

		fclose(log_file);
		// Отладочная информация

		return text_builder.ToString();				// Возвращаем изменённую строку
	}
}