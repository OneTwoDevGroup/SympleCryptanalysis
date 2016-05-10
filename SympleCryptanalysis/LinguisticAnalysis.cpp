#include <fstream>
#include <string>
#include <msclr/marshal_cppstd.h>
#include <regex>
#define MAX_LEN 20

//namespace LinguisticAnalysis {
//
//	using namespace System;
//	using namespace msclr::interop;
//
//	// Функция поиска соответствия слов в словаре
//	// Словарь находится в файле Configs/dictionary.dic, содержит 
//	// большое количество слов одного языка
//	String^ DictionaryAnalysis(String^ text)
//	{
//		const int WORDS_COUNT = 1000000;
//		array<System::String ^>^ words = gcnew array<System::String^ >(WORDS_COUNT);
//		int words_amount = 0;
//		int total_words = 0;
//
//		using namespace std;
//
//		ifstream dictionary("Configs/russian_dictionary.dic");
//		ifstream indexes("Configs/russian_dictionary.inx"); // файл, в котором хранятся байтовые сдвиги
//
//		string converted_text = msclr::interop::marshal_as<string>(text);
//		smatch match;
//		regex re("\\b[a-zA-Z'-]+\\b");
//
//		while (regex_search(converted_text, match, re))
//		{
//			string word = match.str();
//			total_words++;
//			long long index = 0; // сдвиг
//
//			string index_letter;
//			string index_line;
//			indexes.clear();
//			indexes.seekg(0);
//			while (getline(indexes, index_letter)) // находим нужный сдвиг
//				if (index_letter[0] == word[0]) {
//					getline(indexes, index_line);
//					index += stoi(index_line, nullptr);
//					break;
//				}
//
//			dictionary.clear();
//			dictionary.seekg(0);
//			dictionary.seekg(index); // переход по индексу
//
//			string dic_word;
//			while (getline(dictionary, dic_word) && dic_word != word && dic_word[0]==word[0]);
//			if (dic_word == word) {
//				words[words_amount] = msclr::interop::marshal_as<String^>(word);
//				words_amount++;
//			}
//
//			converted_text = match.suffix().str();
//		}
//
//		float wordsFound = (float)words_amount / total_words*100;
//		
//		String^ dictionaryConformity = wordsFound.ToString() + "% of words were found in the dictionary.\r\n\r\n";
//		dictionaryConformity += "Found conformity in dictionary\r\n";
//
//		for (int i = 0; i < words_amount; i++)
//			dictionaryConformity += words[i] + "\r\n";
//
//		return dictionaryConformity;
//	}
//
//
//}

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
		int total_words = 0;

		using namespace std;

		ifstream dictionary("Configs/russian_dictionary.dic");
		ifstream indexes("Configs/russian_dictionary.inx"); // файл, в котором хранятся байтовые сдвиги

		string converted_text = msclr::interop::marshal_as<string>(text);
		smatch match;
		string dic_word;

		while (getline(dictionary, dic_word) /*&& dic_word != word && dic_word[0] != word[0] + 1*/)
			if (converted_text.find(dic_word) != (-1)) {// функция возвращает -1 если не было совпадения
				words[words_amount] = msclr::interop::marshal_as<String^>(dic_word);
				words_amount++;
			}
		int wordsForStat = 0;
		for (int i = 0; i < words_amount; i++)
		{
			if (words[i]->Length > 3)
				wordsForStat++;
		}
				float wordsFound = (float)words_amount / total_words * 100;

				String^ dictionaryConformity = wordsForStat.ToString() + " words (more than 3 characters) were found in the text.\r\n\r\n";
				dictionaryConformity += "Found conformity in dictionary\r\n";

				for (int i = 0; i < words_amount; i++)
					dictionaryConformity += words[i] + "\r\n";

				return dictionaryConformity;
	}

	/*array<System::String ^>^ PartitialMatches(String^ word)*/		// Возвращает массив слов (найденные совпадения)
	String^ PartitialMatches(String^ word) {						// Возвращает строку-отчет (используется для отладки и вывода в текстовое поле)
		const int WORDS_COUNT = 10000;
		array<System::String ^>^ words = gcnew array<System::String^ >(WORDS_COUNT); // массив слов-совпадений
		using namespace std;
		string wordString = msclr::interop::marshal_as<string>(word);
		ifstream dictionary("Configs/russian_dictionary.dic");
		string dic_word;
		int wordsNumber = 0;
		int maxMatchedLetters = 0; // здесь можно указать минимальное колтчество совпадающих символов
		while (getline(dictionary, dic_word)) { // полный перебор словаря
			if (wordString.length() == dic_word.length()) {
				int matchedLetters = 0;
				for (int i = 0; i < wordString.length(); i++) {
					if (wordString[i] == dic_word[i])
						matchedLetters++;
				}
				if (matchedLetters > maxMatchedLetters) {
					maxMatchedLetters = matchedLetters;
					wordsNumber = 0; // переходим в начало массива слов-совпадений
				}
				if (matchedLetters == maxMatchedLetters) {
					words[wordsNumber] = msclr::interop::marshal_as<String^>(dic_word);
					wordsNumber++;
				}
			}
		}
		String^ foundMatches = wordsNumber.ToString() + " words with " + maxMatchedLetters + " matching letters:\r\n\r\n";
		for (int i = 0; i < wordsNumber; i++)
			foundMatches += words[i] + "\r\n";
		if (!wordsNumber)
			foundMatches = "No matches were found";
		return foundMatches;
		/*return words;*/
	}
}