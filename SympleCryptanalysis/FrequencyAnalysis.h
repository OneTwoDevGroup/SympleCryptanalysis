#pragma once
#include "stdio.h"
using namespace System;

namespace FrequencyAnalysis {

	// ������� ���������� ���������� ������ � ��������
	int shiftDetermination(String^ text, int *conformity);
	
	// ����� ������������ ���� ����������� ������ ��������� �������� 
	int *conformityDetermination(double *frequency);

	// ������� ������ ���� � �������� ������
	double *frequencyDetermination(String^ text);
}