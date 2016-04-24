#include "WordProcessing.h"
#include "KasiskiExamination.h"
#include "FrequencyAnalysis.h"
#include "KasiskiExamination.h"

#define MAXKEYLEN 100
#define MAXKEYAMOUNT 100

namespace IndexOfСoincidence {
	
	using namespace System;

	WordProcessing::Alphabit alph("eng"); // Класс определяет используемый язык

	// Функция находит длину ключа, используя метод индекса совпадений
	void keyLengthSearch() {

	}

	// Функция подбирает ключ, основываясь на длине ключа, используя частотный анализ
	String^ keySearch(String^ text) {
		
		// Определяем длину ключа
		int key_length = KasiskiExamination::keyLengthSearch(text);
	//	int key_length = 4;

		// Задаём массив групп, на которые разбивается текст в зависимости от длины ключа
		array<System::String ^>^ group = gcnew array<System::String^>(MAXKEYAMOUNT);

		// Задаём переменную под хранение ключа
		String^ key;
		
		// Цикл заполняет группы
		int not_letters = 0; // Опеределяет количество небуквенных символов, которые нужно пропустить
		for (int j = 0; j < text->Length; j++) {
			if ( !alph.isLetter( text[j]) ) { not_letters++; continue; }
			group[(j - not_letters)  % key_length] += text[j];        
		}

		// Цикл делает частотный анализ для каждой группы и формирует ключ
		for (int i = 0; i < key_length; i++)
			key += alph.getLetter( FreaquancyAnalysis::calcFreaquancy(group[i]) );


		return key;
	}

	// Функция дешифрует текст
	String^ preparingText(String^ text) {

		String^ key = keySearch(text);				// Подбираем ключ
		Text::StringBuilder text_builder(text);		// Формируем изменяемую строку

		// Заменяет символы текста в соответствии с ключом и квадратом Веженера
		int not_letters = 0;  // Опеределяет количество небуквенных символов, которые нужно пропустить
		for (int j = 0; j < text->Length; j++) {
			if ( !alph.isLetter(text_builder[j]) ) { not_letters++; continue; }
			text_builder[j] = alph.getLetter( text_builder[j] - key[(j - not_letters) % key->Length] );
		}


		return text_builder.ToString();				// Возвращаем изменённую строку
	}

}