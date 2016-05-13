#pragma once
#include "stdio.h"
using namespace System;

namespace FrequencyAnalysis {

	// ������� ���������� ���������� ������ � ��������
	int shiftDetermination(String^ text, int *conformity);
	
	// ������� ���������� ������ ����� � ������
	int *lettersAmount(String^ text);
	
	// ����� ������������ ���� ����������� ������ ��������� �������� 
	int *conformityDetermination(String^ text = nullptr, double *frequency = NULL, int *letters_amount = NULL);

	// ������� ������ ���� � �������� ������
	double *frequencyDetermination(String^ text = nullptr, int *letters_amount = NULL);
}