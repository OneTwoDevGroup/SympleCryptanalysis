#pragma once


namespace LinguisticAnalysis {

	using namespace System;

	// ������� ������ ������������ ���� � �������
	String^ DictionaryAnalysis(String^ *text, String^ *conformity_table);

	bool CheckPlainText(String^ text);

	// ������� ��������� ����� �� �������, � ��������������� � �����������
	String^ DictionaryBasedChange(String^ *text, String^ *conformity_table, int stringLength, int wordLength, int matchesNum, int start);

	// �������� ������� ������������, �������������� �� ������, ��������� �������������
	void DictionaryMakeChange(String^ *text, String^ *conformity_table, String^ word, String^ tempWord, int wordLength);
}