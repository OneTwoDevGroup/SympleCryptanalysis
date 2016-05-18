#pragma once


namespace LinguisticAnalysis {

	using namespace System;

	// Функция поиска соответствий слов в словаре
	String^ DictionaryAnalysis(String^ *text, String^ *conformity_table);

	bool CheckPlainText(String^ text);

	// Функция подбирает слово из словаря, в соответветствии с параметрами
	String^ DictionaryBasedChange(String^ *text, String^ *conformity_table, int stringLength, int wordLength, int matchesNum, int start);

	// Заменяет таблицу соответствий, соответственно со словом, выбранным пользователем
	void DictionaryMakeChange(String^ *text, String^ *conformity_table, String^ word, String^ tempWord, int wordLength);
}