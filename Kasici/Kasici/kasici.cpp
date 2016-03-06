#include "stdio.h"

#define N 100
#define r 256// ASCII
#define R 26 //Мощность русского языка

int main()
{
	FILE* fp1;
	fp1 = fopen("input.txt", "r");
	char matched[N][50]; //массив с совпавшими значениями
	int max_match_sum = 0;
	int max_match_ind;
	int s;
	int i = 0, j, l, g, z; //счетчики
	char S[N]; //строка с шифром//место поиска

	while ((S[i] = fgetc(fp1)) && (S[i] != '0'))//считывание входных данных
		i++;
	int k = i; //k- длина входного шифра
	char alf[R] = { 'a','b','c','d','e','f','h','i','j','k','l','m','n','o','p','r','s','t','u','w','v','q','z','g' ,'x' };//буквы русского алфавита

	int lenght_distance[N][2] = { 0 };//в lenght_distane[][0] заносится длина совпадения, в lenght_distance[][1] расстояние между совпадениями
	int w = 0;
	int max_lenght_matched = 0;//максимальное совпадение по длине
	int max_m = -1; //индекс; максимального совпадения
	for (i = 0; i < R; i++)//i-прогоняемся по всем символам алфавита
	{
		for (j = 0; j < k - 1; j++) // ищем все символы Alf[i] в S[]
			if (S[j] == alf[i])
				for (l = j; l < k; l++)// l - ищем все символы Alf[i ] в строке S[j+]
				{
					if (S[l] == alf[i])
					{
						g = 0;
						while (((l + g) < k) && ((j + g) < k) && (S[l + g] == S[j + g]))
							g++;                                                          //g считаем сколько символов совпало
						if (g > 1)
						{
							for (z = 0; z < g; z++)
								matched[w][z] = S[l + g];
							matched[w][z] = '\0';
							lenght_distance[w][0] = g;
							lenght_distance[w][1] = l - j; // расстояние между совпадениями
							w++;
						}


					}
				}
	}
	for (i = 0; i < w; i++)
		if (lenght_distance[w][0]>max_lenght_matched)
		{
			max_lenght_matched = lenght_distance[w][0];      // выбираем самое максимальное совпадение и растояние между ними( cчитаем его 100%)
			max_m = w;
		}

	for (i = 0; i < w - 1; i++)
	{
		s = 0;
		for (j = i; j < w; j++)
		{

			z = 0;
			while (matched[i][z] && matched[j][z] && (matched[i][z] == matched[j][z]))
			{
				z++;
			}
			if ((matched[i][z] == '\0') && (matched[j][z] == '\0'))
				s++;


		}
		if ((max_match_sum < s))
		{
			max_match_sum = s;
			max_match_ind = i;
		}
	}

	printf("%d %s %d %s", max_match_sum, matched[max_match_ind], max_lenght_matched, matched[max_m]);


	return 0;


}