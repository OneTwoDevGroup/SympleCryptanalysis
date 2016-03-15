#include <math.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include <wctype.h>
#include "gcroot.h"
#include <msclr/marshal_cppstd.h>
#include <regex>
#include "WordProcessing.h"


#define MAXALPHLEN 40    // ������������ ����� ��������

WordProcessing::Alphabit alph("rus"); // ���������� ������������� ��������

// ������� ��������� ��������� ������� ��� ������� QSort
int compare(const void * x1, const void * x2)
{
	double a = alph.freaquancy[*(int*)x2] - alph.freaquancy[*(int*)x1];
	if (a < 0) return (-1);
	if (a > 0) return (1);
	if (a = 0) return (0);
}

namespace FreaquancyAnalysis {

	using namespace System;
	using namespace msclr::interop;
	
	// ������� ���������� ������� ������
	// ��������� ������� ���� ��������� ������ ������ �� ��������� � ���������� ����� 
	// ���������� �������������. ������ ���������� �������� ������ ��� ������ �����, ������� �
	// ����� ��c��� ����.
	String^ CalcFreaquancy(String^ text) {
		using namespace std;
		//Alphabit alph("rus"); // ���������� ������������� ��������
		text = text->ToLower();

		// ������� ������ � �������� ������
		double freaquancy[MAXALPHLEN] = { 0.0 };
		int charsAmount = 0;
		for (unsigned long i = 0; i < text->Length; i++) {
			if (text[i] >= alph.firstchar && text[i] <= alph.lastchar) {
				freaquancy[text[i] - alph.firstchar] += 1;
				charsAmount++;
			}
		}
		for (int i = 0; i < alph.length; i++)
			freaquancy[i] /= charsAmount / 100;

		// ������������� ������� �������� ��� ������������ ���������������� ������� �� �������
		int newID[MAXALPHLEN]; for (int i = 0; i < alph.length; i++) newID[i] = i;
		qsort(newID, alph.length, sizeof(int), compare);

		// ����� ������������
		double eps, temp;
		int loc, conformity[MAXALPHLEN], chosen[MAXALPHLEN] = { 0 };
		for (int i = 0; i < alph.length; i++) {
			eps = 100.0;
			loc = i;
			for (int j = 0; j < alph.length; j++)
				if (!chosen[j] && fabs(freaquancy[j] - alph.freaquancy[newID[i]]) < eps)
				{
					eps = fabs(freaquancy[j] - alph.freaquancy[newID[i]]);
					loc = j;
				}
			conformity[newID[i]] = loc;
			chosen[loc] = 1;
		}

		String^ toFreaquancyTable;

		for (int i = 0; i < alph.length; i++)
			toFreaquancyTable += wchar_t(i + alph.firstchar) + "\t" + wchar_t(conformity[i] + alph.firstchar) +
			"\t" + Convert::ToString(Math::Round(freaquancy[conformity[i]] * 100) / 100) + "%\r\n";

		return toFreaquancyTable;
	}

}