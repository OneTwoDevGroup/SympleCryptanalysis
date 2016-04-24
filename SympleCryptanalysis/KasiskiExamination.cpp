#include "stdio.h"
#include "WordProcessing.h"
#include <msclr/marshal.h>
#include "string.h"
#include "malloc.h"
#define N 5000
#define r 256// ASCII
#define R 26 //�������� �������� �����


namespace KasiskiExamination {

	using namespace System;

	// ������� ������� ����� �����
	int keyLengthSearch(String ^text)
	{
		int size;
		char alf[R] = { 'a','b','c','d','e','f','h','i','j','k','l','m','n','o','p','r','s','t','u','w','v','q','z','g' ,'x' };//����� ����������� ��������
		char buff[100];										//��� ����������� �����
		int** lenght_distance;								//� lenght_distane[][0] ��������� ����� ����������, � lenght_distance[][1] ���������� ����� ������������
		char **matched;										//������ � ���������� ����������
		int max_match_sum = 0;								//���-�� ���������� ����������
		int max_match_ind=-1;									// ������ ������������� ���������� ���-��
		int* count_matched;									// ������ ���-�� ����������
		int w = 0;											// ����� ����������
		int max_lenght_matched = 0;							//������������ ���������� �� �����
		int max_lenght_distance = 0;                         //������������ ���������� ����� ������������
		int max_m = -1;										//������; ������������� ����������
		int i = 0, j, l, g, z, s;							//��������

		//������ � ������//����� ������
		char *S = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(text);

		i = 0;
		size = strlen(S);

		matched = (char**)malloc(sizeof(char*));
		lenght_distance = (int**)malloc(sizeof(int*));

		for (i = 0; i < R; i++)								//i-����������� �� ���� �������� ��������
		{
			for (j = 0; j < size; j++)						// ���� ��� ������� Alf[i] � S[]
				if (S[j] == alf[i])
				{
					s = 0;
					for (l = j + 1; l < size; l++)			// l - ���� ��� ������� Alf[i] � ������ S[j+]
					{
						if (S[l] < 97)
						{
							s++;
						}
						if (S[l] == alf[i])
						{

							g = 0;
							while (((l + g) < size) && ((j + g) < size) && ((S[l + g] == S[j + g])/*||( S[l+g]<97||S[j+g]<97)*/))
							{
								g++;						//g ������� ������� �������� �������

							}
							if (g > (size / 3000) + 2)
							{
								matched = (char**)realloc(matched, (sizeof(char*)*(w + 1)));
								matched[w] = (char*)malloc(1);
								for (z = 0; z < g; z++)
								{
									matched[w] = (char*)realloc(matched[w], sizeof(char)*(z + 2));
									matched[w][z] = S[l + z];
								}
								matched[w][z] = '\0';
								lenght_distance = (int**)realloc(lenght_distance, sizeof(int*)*(w + 1));
								lenght_distance[w] = (int*)malloc(2 * (sizeof(int)));
								lenght_distance[w][0] = g;
								lenght_distance[w][1] = l - j - s; // ���������� ����� ������������
								w++;
							}
						}
					}
				}
		}

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
				max_lenght_matched = lenght_distance[j][0];// �������� ����� ������������ ���������� � ��������� ����� ����( c������ ��� 100%)
				max_m = j;
			}
		}
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
		}

		for (i = 0; i < w; i++)
		{
			printf("         %s", matched[i]);
		}

		float* h;
		h = (float*)malloc(sizeof(float));
		for (j = 2; j < max_lenght_distance; j++)
		{
			h = (float*)realloc(h, (j+1)*(sizeof(float)));
			for (i = 0; i < w; i++)
			{
				if ((lenght_distance[i][1] % j) == 0)
				{
					if (lenght_distance[i][0]>4)
					{
						if (count_matched[i]>2 * max_match_sum / 3)
							h[j] += 4.0*lenght_distance[i][0];
						else
						{
							h[j] += 2.0*lenght_distance[i][0];
						}
					}
					else
					{


						if (count_matched[i]>2 * max_match_sum / 3)
							h[j] += 2.0*lenght_distance[i][0];
						else
							h[j] += 1.0*lenght_distance[i][0];
					}
				}
			}
		}
		float max=h[2];
		int maxind=2;
		for (j = 3; j < max_lenght_distance; j++)
		{
			if (h[j] > max)
			{
				max = h[j];
				maxind = j;
			}
		}

		//��������
		free(count_matched);
		for (i = 0; i < w; i++)
		{
			free(matched[i]);
			free(lenght_distance[i]);
		}
		free(matched);
		free(lenght_distance);
		free(h);

		return maxind;


	}

}