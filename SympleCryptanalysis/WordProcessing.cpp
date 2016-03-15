#include <math.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include <wctype.h>
#include "gcroot.h"
#include <msclr/marshal_cppstd.h>


#define MAXALPHLEN 40    // ������������ ����� ��������
#define ARRAY_SIZE 1000  // ������������ ����� ������� ���������


namespace WordProcessing {

	using namespace System;
	using namespace msclr::interop;


	// ����� ���������� ������������ �������, 
	// ��� ������ � ��������� �������� ������� � ����� Configs/langsFile.lng
	// � ����� ���������� ������ � ���������� ������� � ���������� ������� �������� 
	// ������� �������� � Unicode �������, ���������� �������� � �������� � ��������� �������������
	class Alphabit {
	public:
		int firstchar, lastchar, length;
		double freaquancy[MAXALPHLEN] = { 0.0 };

		Alphabit(String^ lang) {
			getDataFor(lang);
		}

	private:
		void getDataFor(String^ lang) {
			using namespace std;
			ifstream langsFile("Configs/langsFile.lng");
			string str;
			while (getline(langsFile, str) && String::Compare(marshal_as<String^>(str), lang));
			langsFile >> firstchar >> lastchar >> length;
			for (int i = 0; i < length; i++) langsFile >> freaquancy[i];
			langsFile.close();
		}

	};
	Alphabit alph("rus"); // ���������� ������������� ��������


						  // ����� ��������� ����������� � ������ � ������� ������ �� ���� ������ ��� ����������� ������ ���������
	class Changes {
	public:
		gcroot<array<System::String ^>^> textChanges = gcnew array<System::String^ >(ARRAY_SIZE);       // ������, ���������� ��� �������� ���������� ������
		gcroot<array<System::String ^>^> freaquancyChanges = gcnew array<System::String^ >(ARRAY_SIZE); // ������, ���������� ��� �������� ��������� ������� ������
		wchar_t conformityChanges[ARRAY_SIZE][MAXALPHLEN] = { 0 };										// ������, ���������� ��� �������� ��������� ������������ ������
		int changedConformityIndex[ARRAY_SIZE][MAXALPHLEN] = { 0 };                                     // ������, ���������� ��� �������� ��������� ������������ ������
		int indexChangesAmount[ARRAY_SIZE] = { 0 };                                                     // ������, ���������� ��� �������� ���������� ������������ ������
		int last = -1;                                                                                  // ���������� ���������� ������� � �������� ��������� ��������� 

																										// ������� ��������� ���������
		int save_changes(String^ text, wchar_t *conformity, String^ freaquancyTable) {

			last++;

			textChanges[last % ARRAY_SIZE] = text;
			freaquancyChanges[last % ARRAY_SIZE] = freaquancyTable;
			memcpy(conformityChanges[last % ARRAY_SIZE], conformity, alph.length * sizeof(wchar_t));

			if (last != 0) {
				int changesAmount = 0;

				for (int i = 0; i < alph.length; i++)
					if (conformityChanges[last][i] != conformityChanges[last - 1][i]) {
						changedConformityIndex[last][changesAmount] = i;
						changesAmount++;
					}

				if (changesAmount == 0) { last--; return 0; }
				indexChangesAmount[last] = changesAmount;
			}
			else {
				for (int i = 0; i < alph.length; i++)
					changedConformityIndex[last][i] = i;
				indexChangesAmount[last] = alph.length;
			}

			return 1;

		}

		// ������� ���������� ��������� ��������� ��� ������
		int getLast(String^ *text, String^ *freaquancyTable)
		{
			if (last == -1) return 0;
			*text = textChanges[last % ARRAY_SIZE];
			if (last == 0) *freaquancyTable = freaquancyChanges[last % ARRAY_SIZE];
			else *freaquancyTable = freaquancyChanges[(last - 1) % ARRAY_SIZE];
			last--;
			return 1;
		}

		// ������� ������� �������� �����
		String^ getFirstText() { return textChanges[0]->ToLower(); }
	};
	Changes textChanges; // ���������� ���������� ��� �������� ���������

						 // ������� ��������� ��������� ���������
	String^ ChangeTextUp(String^ text, String^ freaquancyTable) {

		wchar_t conformity[MAXALPHLEN];
		array< String^ >^ freaquancies = freaquancyTable->Split('%', '\r', '\n');
		for (int i = 0; i < alph.length; i++)
			conformity[i] = freaquancies[i * 3][2];

		if (!textChanges.save_changes(text, conformity, freaquancyTable)) return text;

		text = textChanges.getFirstText();

		for (int i = 0; i < alph.length; i++)
			text = text->Replace(wchar_t(i + alph.firstchar) + "", (conformity[i] + "")->ToUpper());


		return text->ToLower();
	}


	// ������� ���������� ��������� ���������
	int ChangeDown(String^ *text, String^ *freaquancyTable) { return textChanges.getLast(text, freaquancyTable); }
}