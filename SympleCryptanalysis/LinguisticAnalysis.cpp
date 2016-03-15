#include <fstream>
#include <string>
#include <msclr/marshal_cppstd.h>
#include <regex>

namespace LinguisticAnalysis {

	using namespace System;
	using namespace msclr::interop;

	// Функция поиска соответствия слов в словаре
	// Словарь находится в файле Configs/dictionary.dic, содержит 
	// большое количество слов одного языка
	String^ DictionaryAnalysis(String^ text)
	{
		const int WORDS_COUNT = 1000000;
		array<System::String ^>^ words = gcnew array<System::String^ >(WORDS_COUNT);
		int words_amount = 0;

		using namespace std;

		ifstream dictionary("Configs/dictionary.dic");

		string converted_text = msclr::interop::marshal_as<string>(text);

		smatch match;
		regex re("[а-яА-Я-]+");

		while (regex_search(converted_text, match, re))
		{
			string word = match.str();

			dictionary.clear();
			dictionary.seekg(0);

			string dic_word;
			while (getline(dictionary, dic_word) && dic_word != word);
			if (dic_word == word) {
				words[words_amount] = msclr::interop::marshal_as<String^>(word);
				words_amount++;
			}

			converted_text = match.suffix().str();
		}

		String^ dictionaryConformity = "Found conformity in dictionary\r\n";

		for (int i = 0; i < words_amount; i++)
			dictionaryConformity += words[i] + "\r\n";

		return dictionaryConformity;
	}


}