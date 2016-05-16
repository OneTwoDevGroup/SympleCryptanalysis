#pragma once


namespace LinguisticAnalysis {

	using namespace System;

	// Функция поиска соответствий слов в словаре
	String^ DictionaryAnalysis(String^ *text, String^ *conformity_table);

	bool CheckPlainText(String^ text);

}