#pragma once


namespace LinguisticAnalysis {

	using namespace System;

	// ������� ������ ������������ ���� � �������
	String^ DictionaryAnalysis(String^ *text, String^ *conformity_table);

	bool CheckPlainText(String^ text);

	array<System::String ^>^ DictionaryBasedChange(String^ text, int stringLength, int wordLength, int matchesNum, int start);
	// �������� ������� ������������, �������������� �� ������, ��������� �������������

	String^ DictionaryMakeChange(String^ word, String^ *text, String^ key, String^ *conformity_table, String^ tempWord, int wordLength);

	array<System::String ^>^ GetWordsWithLen(int length);
}