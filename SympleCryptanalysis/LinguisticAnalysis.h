#pragma once


namespace LinguisticAnalysis {

	using namespace System;

	// ������� ������ ������������ ���� � �������
	String^ DictionaryAnalysis(String^ *text, String^ *conformity_table);

	bool CheckPlainText(String^ text);

}