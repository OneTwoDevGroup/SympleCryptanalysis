#include <fstream>
#include <string>
#include <msclr/marshal_cppstd.h>
#include <regex>
#include "WordProcessing.h"
#include <time.h>
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

	// ---------------------------Заголовки функций-------------------------------
	array<System::String ^>^ GetWordsWithLen(int length);



	//-----------------------------------------------------------------------------

/*array<System::String ^>^ PartitialMatches(String^ word)*/		// Возвращает массив слов (найденные совпадения)
	//int PartitialMatches(String^ word, int minMatches)
	String^ PartitialMatches(String^ word, int minMatches) {						// Возвращает строку-отчет (используется для отладки и вывода в текстовое поле)
		const int WORDS_COUNT = 10000;
		array<System::String ^>^ words = gcnew array<System::String^ >(WORDS_COUNT); // массив слов-совпадений
		using namespace std;
		string wordString = msclr::interop::marshal_as<string>(word);
		ifstream dictionary("Configs/russian_dictionary.dic");
		string dic_word;
		int wordsNumber = 0;
		int maxMatchedLetters = minMatches; // здесь можно указать минимальное колтчество совпадающих символов
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
		//return wordsNumber;
		return foundMatches;
		/*return words;*/
	}

	String^ PartitialMatchesAnalysis(String^ text, int stringLength, int wordLength, int matchesNum) {
	//int PartitialMatchesAnalysis(String^ text, int wordLength, matchesNum) {
		using namespace std;
		int statistics = 0;
		string convertedText = msclr::interop::marshal_as<string>(text);
		string word;
		String ^temp;
		for (int j = 0; j < stringLength - wordLength; j++) {
			word = convertedText.substr(j, wordLength);
			String^ tempWord = msclr::interop::marshal_as<String^>(word);
			temp += PartitialMatches(tempWord, matchesNum) + "\n";
			//statistics += PartitialMatches(tempWord, matchesNum);
		}
		String^ foundMatches = statistics.ToString();
		return temp;
		//return foundMatches;
		//return 0;
	}

	array<System::String ^>^ PartitialMatchesChanges(String^ word, int matchesNum, int * pos) {	// Возвращает строку-отчет (используется для отладки и вывода в текстовое поле)
		const int WORDS_COUNT = 10000;
		array<System::String ^>^ words = gcnew array<System::String^ >(WORDS_COUNT); // массив слов-совпадений
		using namespace std;
		string wordString = msclr::interop::marshal_as<string>(word);
		ifstream dictionary("Configs/testDic.txt");
		ifstream indexes("Configs/test.txt");
		string dic_word;
		int wordsNumber = 0;
		int maxMatchedLetters = 0; // здесь можно указать минимальное колтчество совпадающих символов
		
		indexes.clear();
		indexes.seekg(0);
		string index_letter;
		string index_line;
		int index = 0;
		indexes.clear();
		indexes.seekg(0);
		
		while (getline(indexes, index_letter)) { // находим нужный сдвиг
			int length = stoi(index_letter, nullptr);
			if (length == word->Length) {
				getline(indexes, index_line);
				index += stoi(index_line, nullptr);
				break;
			}
		}
		indexes.close();
		dictionary.clear();
		dictionary.seekg(0);
		dictionary.seekg(index);

		while (getline(dictionary, dic_word)) { // полный перебор словаря
			if (wordString.length() == dic_word.length()) {
				int matchedLetters = 0;
				for (int i = 0; i < wordString.length(); i++) {
					if (wordString[i] == dic_word[i])
						matchedLetters++;
				}
				if ((matchedLetters > maxMatchedLetters) /*&& (word->Length - maxMatchedLetters >= matchesNum + 1)*/) {
					maxMatchedLetters = matchedLetters;
					wordsNumber = 0; // переходим в начало массива слов-совпадений
				}
				if (matchedLetters == maxMatchedLetters) {
					words[wordsNumber] = msclr::interop::marshal_as<String^>(dic_word);
					wordsNumber++;
				}
				words[wordsNumber] = "0";
				*pos = wordsNumber + 1;
			}
			else break;
		}
		if (word->Length - maxMatchedLetters < matchesNum+1) {
			return words;
		}
		else return nullptr;
	}

	array<System::String ^>^ DictionaryBasedChange(String^ *text, int *pos, String^ *conformity_table, int stringLength, int wordLength, int matchesNum, int start) {

		int* conformity_new = (int*)malloc(MAXALPHLEN * sizeof(int));
		for (int i = 0; i < MAXALPHLEN; i++)
			conformity_new[i] = -1;
		String^ result;
		String^ word;
		for (int j = start; j < j + wordLength; j++) {
			int spaceNum = 0;
			for (int k = 0; k < wordLength + spaceNum; k++)
				if ((*text)[j + k] != ' ')
					word += (*text)[j + k];
				else
					spaceNum++;
			array<System::String ^>^ tempWords = PartitialMatchesChanges(word, matchesNum, pos);
			tempWords[*pos] = word;
			/*if (tempWord[0] != '0') {
				for (int i = 0; i < wordLength; i++)
					if (word[i] != tempWord[i]) {
						int tempInte = word[i]-1072;
						int tempInte2 = tempWord[i] - 1072;
						conformity_new[word[i]-1072] = tempWord[i]-1072;
						conformity_new[tempWord[i] - 1072] = word[i] - 1072;
						result = result + word + "\r\n" + tempWord + "\r\n";
						result = result + word[i] + " -> " + tempWord[i] + "\r\n";
						WordProcessing::changeTextUp(text, conformity_table, &conformity_new);
					}
			}
		}
		String^ temp;*/
			return tempWords;
		}
	}

	String^ DictionaryMakeChange(String^ *text, String^ key, String^ *conformity_table, String^ word, String^ tempWord, int wordLength) {
		int* conformity = WordProcessing::getLastConformity();
		String^ result;
		if (tempWord[0] != '0') {
			for (int i = 0; i < wordLength; i++) {
				if (word[i] != tempWord[i]) {
					int tempSign = conformity[word[i] - 1072];
					conformity[word[i] - 1072] = tempWord[i] - 1072;
					for (int j = 0; j < MAXALPHLEN; j++)
						if (conformity[j] == tempWord[i] - 1072) {
							conformity[j] = tempSign;
							break;
						}

					result = result + word + "\r\n" + tempWord + "\r\n";
					result = result + word[i] + " -> " + tempWord[i] + "\r\n";
					WordProcessing::changeTextUp(text, conformity_table, &conformity, key);
					break;
				}
				
			}
		}
		return result;
	}

	// Функция поиска соответствия слов в словаре
	// Словарь находится в файле Configs/dictionary.dic, содержит 
	// большое количество слов одного языка
	String^ DictionaryAnalysis(String^ *text, String^ *conformity_table)
	{
		//const int WORDS_COUNT = 1000000;
		//array<System::String ^>^ words = gcnew array<System::String^ >(WORDS_COUNT);
		//int words_amount = 0;
		//int total_words = 0;

		//using namespace std;

		//ifstream dictionary("Configs/russian_dictionary.dic");
		//ifstream indexes("Configs/russian_dictionary.inx"); // файл, в котором хранятся байтовые сдвиги

		//string converted_text = msclr::interop::marshal_as<string>(text);
		//int textLength = converted_text.length();
		//smatch match;
		//string dic_word;

		//while (getline(dictionary, dic_word) /*&& dic_word != word && dic_word[0] != word[0] + 1*/)
		//	if (converted_text.find(dic_word) != (-1)) {// функция возвращает -1 если не было совпадения
		//		words[words_amount] = msclr::interop::marshal_as<String^>(dic_word);
		//		words_amount++;
		//	}
		//int wordsForStat = 0;
		//for (int i = 0; i < words_amount; i++)
		//{
		//	if (words[i]->Length > 3)
		//		wordsForStat++;
		//}
		//		float wordsFound = (float)words_amount / total_words * 100;
		//		double analysisResult = (float)wordsForStat / textLength;
		//		bool result = 0;
		//		if (analysisResult > 0.04)
		//			result = 1;
		//		String^ dictionaryConformity = wordsForStat.ToString() + " words (more than 3 characters) were found in the text. Result: " + result.ToString() + "\r\n\r\n";
		//		dictionaryConformity += "Found conformity in dictionary\r\n";

		//		for (int i = 0; i < words_amount; i++)
		//			dictionaryConformity += words[i] + "\r\n";

		//		return dictionaryConformity;
		//GetWordsWithLen(7);
		time_t t = clock();
		String ^ tempWord;
		int pos;
		String^ key;
		array<System::String ^>^ temp = DictionaryBasedChange(text, &pos, conformity_table, 40, 7, 4, 22);
		String^ result = DictionaryMakeChange(text, key, conformity_table, temp[pos], temp[0], 7);
		time_t t2 = clock() - t;
		return result;
	}

	

	bool CheckPlainText(String^ text)
	{
		const int WORDS_COUNT = 1000000;
		array<System::String ^>^ words = gcnew array<System::String^ >(WORDS_COUNT);
		int words_amount = 0;
		int total_words = 0;

		using namespace std;

		ifstream dictionary("Configs/russian_dictionary.dic");
		ifstream indexes("Configs/russian_dictionary.inx"); // файл, в котором хранятся байтовые сдвиги

		string converted_text = msclr::interop::marshal_as<string>(text);
		int textLength = converted_text.length();
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
		double analysisResult = (float)wordsForStat / textLength;
		bool result = 0;
		if (analysisResult > 0.04)
			result = 1;
		return result;
	}

	array<System::String ^>^ GetWordsWithLen(int length) {
		const int WORDS_COUNT = 1000000;
		array<System::String ^>^ words = gcnew array<System::String^ >(WORDS_COUNT);

		using namespace std;

		ifstream dictionary("Configs/testDic.txt");
		ifstream indexes("Configs/test.txt");

		indexes.clear();
		indexes.seekg(0);
		string index_letter;
		string index_line;
		int index = 0;
		indexes.clear();
		indexes.seekg(0);
		bool isLengthFound = 0;
		while (getline(indexes, index_letter)) { // находим нужный сдвиг
			int lengthInd = stoi(index_letter, nullptr);
			if (lengthInd == length) {
				isLengthFound = 1;
				getline(indexes, index_line);
				index += stoi(index_line, nullptr);
				break;
			}
		}
		if (isLengthFound) {
			indexes.close();
			dictionary.clear();
			dictionary.seekg(0);
			dictionary.seekg(index);

			string dic_word;
			int i = 0;
			while (getline(dictionary, dic_word) && dic_word.length() == length) {
				words[i] = msclr::interop::marshal_as<String^>(dic_word);
				i++;
			}
			words[i] = "";
			return words;
		}
		else return nullptr;
	}
}