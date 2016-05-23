#pragma once

#include "malloc.h"

namespace SympleCryptanalysis {


		using namespace System;
		using namespace System::ComponentModel;
		using namespace System::Collections;
		using namespace System::Windows::Forms;
		using namespace System::Data;
		using namespace System::Drawing;

		/// <summary>
		/// Summary for MyForm
		/// </summary>
		public ref class MyForm : public System::Windows::Forms::Form
		{
		public:
			MyForm(void)
			{
				InitializeComponent();
				//
				//TODO: Add the constructor code here
				//
			}

		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~MyForm()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Windows::Forms::RichTextBox^  TextBox;
		private: System::Windows::Forms::TextBox^  DictionaryConformityText;
		private: System::Windows::Forms::Panel^  buttons_panel;



		private: System::Windows::Forms::Button^  ChangeTextDownButton;

		private: System::Windows::Forms::TextBox^  ConformityTable;
		private: System::Windows::Forms::ComboBox^  keys_list;

		private: System::Windows::Forms::ComboBox^  key_lengths_list;
		private: System::Windows::Forms::Label^  replaceable_symbol_label;
		private: System::Windows::Forms::Label^  replacing_symbol_label;
		private: System::Windows::Forms::TextBox^  replaceable_symbol;
		private: System::Windows::Forms::TextBox^  replacing_symbol;
		private: System::Windows::Forms::Label^  key_label;
		private: System::Windows::Forms::Label^  key_len_label;
		private: System::Windows::Forms::Label^  label6;
		private: System::Windows::Forms::Label^  label5;
		private: System::Windows::Forms::Label^  label4;
		private: System::Windows::Forms::Label^  label3;
		private: System::Windows::Forms::Label^  label2;
		private: System::Windows::Forms::Label^  label1;
		private: System::Windows::Forms::TextBox^  incorrect_symbols_amount;
		private: System::Windows::Forms::TextBox^  word_length;
		private: System::Windows::Forms::TextBox^  substring_length;
		private: System::Windows::Forms::TextBox^  substring_position;
		private: System::Windows::Forms::ComboBox^  changeable_words_list;
		private: System::Windows::Forms::Label^  label7;
		private: System::Windows::Forms::TextBox^  symbol_position;







		private:
			/// <summary>
			/// Required designer variable.
			/// </summary>
			System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
			/// <summary>
			/// Required method for Designer support - do not modify
			/// the contents of this method with the code editor.
			/// </summary>
			void InitializeComponent(void)
			{
				this->TextBox = (gcnew System::Windows::Forms::RichTextBox());
				this->DictionaryConformityText = (gcnew System::Windows::Forms::TextBox());
				this->buttons_panel = (gcnew System::Windows::Forms::Panel());
				this->label7 = (gcnew System::Windows::Forms::Label());
				this->symbol_position = (gcnew System::Windows::Forms::TextBox());
				this->label6 = (gcnew System::Windows::Forms::Label());
				this->label5 = (gcnew System::Windows::Forms::Label());
				this->label4 = (gcnew System::Windows::Forms::Label());
				this->label3 = (gcnew System::Windows::Forms::Label());
				this->label2 = (gcnew System::Windows::Forms::Label());
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->incorrect_symbols_amount = (gcnew System::Windows::Forms::TextBox());
				this->word_length = (gcnew System::Windows::Forms::TextBox());
				this->substring_length = (gcnew System::Windows::Forms::TextBox());
				this->substring_position = (gcnew System::Windows::Forms::TextBox());
				this->changeable_words_list = (gcnew System::Windows::Forms::ComboBox());
				this->replaceable_symbol_label = (gcnew System::Windows::Forms::Label());
				this->replacing_symbol_label = (gcnew System::Windows::Forms::Label());
				this->replaceable_symbol = (gcnew System::Windows::Forms::TextBox());
				this->replacing_symbol = (gcnew System::Windows::Forms::TextBox());
				this->key_label = (gcnew System::Windows::Forms::Label());
				this->key_len_label = (gcnew System::Windows::Forms::Label());
				this->key_lengths_list = (gcnew System::Windows::Forms::ComboBox());
				this->keys_list = (gcnew System::Windows::Forms::ComboBox());
				this->ChangeTextDownButton = (gcnew System::Windows::Forms::Button());
				this->ConformityTable = (gcnew System::Windows::Forms::TextBox());
				this->buttons_panel->SuspendLayout();
				this->SuspendLayout();
				// 
				// TextBox
				// 
				this->TextBox->AcceptsTab = true;
				this->TextBox->AutoWordSelection = true;
				this->TextBox->Dock = System::Windows::Forms::DockStyle::Left;
				this->TextBox->EnableAutoDragDrop = true;
				this->TextBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(204)));
				this->TextBox->Location = System::Drawing::Point(0, 0);
				this->TextBox->Name = L"TextBox";
				this->TextBox->Size = System::Drawing::Size(650, 561);
				this->TextBox->TabIndex = 1;
				this->TextBox->Text = L"";
				this->TextBox->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::TextBox_MouseDown);
				// 
				// DictionaryConformityText
				// 
				this->DictionaryConformityText->Dock = System::Windows::Forms::DockStyle::Right;
				this->DictionaryConformityText->Location = System::Drawing::Point(980, 0);
				this->DictionaryConformityText->Multiline = true;
				this->DictionaryConformityText->Name = L"DictionaryConformityText";
				this->DictionaryConformityText->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
				this->DictionaryConformityText->Size = System::Drawing::Size(204, 561);
				this->DictionaryConformityText->TabIndex = 11;
				// 
				// buttons_panel
				// 
				this->buttons_panel->Controls->Add(this->label7);
				this->buttons_panel->Controls->Add(this->symbol_position);
				this->buttons_panel->Controls->Add(this->label6);
				this->buttons_panel->Controls->Add(this->label5);
				this->buttons_panel->Controls->Add(this->label4);
				this->buttons_panel->Controls->Add(this->label3);
				this->buttons_panel->Controls->Add(this->label2);
				this->buttons_panel->Controls->Add(this->label1);
				this->buttons_panel->Controls->Add(this->incorrect_symbols_amount);
				this->buttons_panel->Controls->Add(this->word_length);
				this->buttons_panel->Controls->Add(this->substring_length);
				this->buttons_panel->Controls->Add(this->substring_position);
				this->buttons_panel->Controls->Add(this->changeable_words_list);
				this->buttons_panel->Controls->Add(this->replaceable_symbol_label);
				this->buttons_panel->Controls->Add(this->replacing_symbol_label);
				this->buttons_panel->Controls->Add(this->replaceable_symbol);
				this->buttons_panel->Controls->Add(this->replacing_symbol);
				this->buttons_panel->Controls->Add(this->key_label);
				this->buttons_panel->Controls->Add(this->key_len_label);
				this->buttons_panel->Controls->Add(this->key_lengths_list);
				this->buttons_panel->Controls->Add(this->keys_list);
				this->buttons_panel->Controls->Add(this->ChangeTextDownButton);
				this->buttons_panel->Dock = System::Windows::Forms::DockStyle::Fill;
				this->buttons_panel->Location = System::Drawing::Point(650, 0);
				this->buttons_panel->Name = L"buttons_panel";
				this->buttons_panel->Size = System::Drawing::Size(330, 561);
				this->buttons_panel->TabIndex = 12;
				// 
				// label7
				// 
				this->label7->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->label7->AutoSize = true;
				this->label7->Location = System::Drawing::Point(207, 131);
				this->label7->Name = L"label7";
				this->label7->Size = System::Drawing::Size(43, 13);
				this->label7->TabIndex = 34;
				this->label7->Text = L"position";
				// 
				// symbol_position
				// 
				this->symbol_position->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->symbol_position->Location = System::Drawing::Point(205, 159);
				this->symbol_position->Name = L"symbol_position";
				this->symbol_position->Size = System::Drawing::Size(42, 20);
				this->symbol_position->TabIndex = 33;
				// 
				// label6
				// 
				this->label6->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->label6->AutoSize = true;
				this->label6->Location = System::Drawing::Point(154, 249);
				this->label6->Name = L"label6";
				this->label6->Size = System::Drawing::Size(110, 13);
				this->label6->TabIndex = 32;
				this->label6->Text = L"Changeable words list";
				// 
				// label5
				// 
				this->label5->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->label5->AutoSize = true;
				this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.25F));
				this->label5->Location = System::Drawing::Point(81, 193);
				this->label5->Name = L"label5";
				this->label5->Size = System::Drawing::Size(149, 20);
				this->label5->TabIndex = 31;
				this->label5->Text = L"Linguistic Analysis";
				// 
				// label4
				// 
				this->label4->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->label4->AutoSize = true;
				this->label4->Location = System::Drawing::Point(45, 394);
				this->label4->Name = L"label4";
				this->label4->Size = System::Drawing::Size(127, 13);
				this->label4->TabIndex = 30;
				this->label4->Text = L"Incorrect symbols amount";
				// 
				// label3
				// 
				this->label3->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->label3->AutoSize = true;
				this->label3->Location = System::Drawing::Point(72, 344);
				this->label3->Name = L"label3";
				this->label3->Size = System::Drawing::Size(65, 13);
				this->label3->TabIndex = 29;
				this->label3->Text = L"Word length";
				// 
				// label2
				// 
				this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->label2->AutoSize = true;
				this->label2->Location = System::Drawing::Point(64, 295);
				this->label2->Name = L"label2";
				this->label2->Size = System::Drawing::Size(83, 13);
				this->label2->TabIndex = 28;
				this->label2->Text = L"Substring length";
				// 
				// label1
				// 
				this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->label1->AutoSize = true;
				this->label1->Location = System::Drawing::Point(58, 249);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(90, 13);
				this->label1->TabIndex = 27;
				this->label1->Text = L"Substring position";
				// 
				// incorrect_symbols_amount
				// 
				this->incorrect_symbols_amount->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->incorrect_symbols_amount->Location = System::Drawing::Point(61, 410);
				this->incorrect_symbols_amount->Name = L"incorrect_symbols_amount";
				this->incorrect_symbols_amount->Size = System::Drawing::Size(86, 20);
				this->incorrect_symbols_amount->TabIndex = 26;
				this->incorrect_symbols_amount->Text = L"1";
				// 
				// word_length
				// 
				this->word_length->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->word_length->Location = System::Drawing::Point(61, 360);
				this->word_length->Name = L"word_length";
				this->word_length->Size = System::Drawing::Size(86, 20);
				this->word_length->TabIndex = 25;
				this->word_length->Text = L"5";
				// 
				// substring_length
				// 
				this->substring_length->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->substring_length->Location = System::Drawing::Point(61, 311);
				this->substring_length->Name = L"substring_length";
				this->substring_length->Size = System::Drawing::Size(86, 20);
				this->substring_length->TabIndex = 24;
				this->substring_length->Text = L"20";
				// 
				// substring_position
				// 
				this->substring_position->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->substring_position->Location = System::Drawing::Point(61, 265);
				this->substring_position->Name = L"substring_position";
				this->substring_position->Size = System::Drawing::Size(86, 20);
				this->substring_position->TabIndex = 23;
				this->substring_position->Text = L"0";
				// 
				// changeable_words_list
				// 
				this->changeable_words_list->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->changeable_words_list->FormattingEnabled = true;
				this->changeable_words_list->Location = System::Drawing::Point(170, 265);
				this->changeable_words_list->Name = L"changeable_words_list";
				this->changeable_words_list->Size = System::Drawing::Size(86, 21);
				this->changeable_words_list->TabIndex = 22;
				this->changeable_words_list->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::changeable_words_list_SelectedIndexChanged);
				this->changeable_words_list->Click += gcnew System::EventHandler(this, &MyForm::changeable_words_list_Click);
				// 
				// replaceable_symbol_label
				// 
				this->replaceable_symbol_label->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->replaceable_symbol_label->AutoSize = true;
				this->replaceable_symbol_label->Location = System::Drawing::Point(128, 131);
				this->replaceable_symbol_label->Name = L"replaceable_symbol_label";
				this->replaceable_symbol_label->Size = System::Drawing::Size(65, 13);
				this->replaceable_symbol_label->TabIndex = 21;
				this->replaceable_symbol_label->Text = L"replaceable ";
				// 
				// replacing_symbol_label
				// 
				this->replacing_symbol_label->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->replacing_symbol_label->AutoSize = true;
				this->replacing_symbol_label->Location = System::Drawing::Point(62, 131);
				this->replacing_symbol_label->Name = L"replacing_symbol_label";
				this->replacing_symbol_label->Size = System::Drawing::Size(50, 13);
				this->replacing_symbol_label->TabIndex = 20;
				this->replacing_symbol_label->Text = L"replacing";
				// 
				// replaceable_symbol
				// 
				this->replaceable_symbol->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->replaceable_symbol->Location = System::Drawing::Point(142, 159);
				this->replaceable_symbol->Name = L"replaceable_symbol";
				this->replaceable_symbol->Size = System::Drawing::Size(42, 20);
				this->replaceable_symbol->TabIndex = 19;
				// 
				// replacing_symbol
				// 
				this->replacing_symbol->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->replacing_symbol->Location = System::Drawing::Point(67, 159);
				this->replacing_symbol->Name = L"replacing_symbol";
				this->replacing_symbol->Size = System::Drawing::Size(42, 20);
				this->replacing_symbol->TabIndex = 18;
				this->replacing_symbol->TextChanged += gcnew System::EventHandler(this, &MyForm::replacing_symbol_TextChanged);
				// 
				// key_label
				// 
				this->key_label->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->key_label->AutoSize = true;
				this->key_label->Location = System::Drawing::Point(202, 48);
				this->key_label->Name = L"key_label";
				this->key_label->Size = System::Drawing::Size(24, 13);
				this->key_label->TabIndex = 17;
				this->key_label->Text = L"key";
				// 
				// key_len_label
				// 
				this->key_len_label->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->key_len_label->AutoSize = true;
				this->key_len_label->Location = System::Drawing::Point(77, 48);
				this->key_len_label->Name = L"key_len_label";
				this->key_len_label->Size = System::Drawing::Size(56, 13);
				this->key_len_label->TabIndex = 16;
				this->key_len_label->Text = L"key length";
				// 
				// key_lengths_list
				// 
				this->key_lengths_list->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->key_lengths_list->FormattingEnabled = true;
				this->key_lengths_list->Location = System::Drawing::Point(61, 77);
				this->key_lengths_list->Name = L"key_lengths_list";
				this->key_lengths_list->Size = System::Drawing::Size(86, 21);
				this->key_lengths_list->TabIndex = 15;
				this->key_lengths_list->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::key_lengths_SelectedIndexChanged);
				this->key_lengths_list->Click += gcnew System::EventHandler(this, &MyForm::key_lengths_Click);
				// 
				// keys_list
				// 
				this->keys_list->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->keys_list->FormattingEnabled = true;
				this->keys_list->Location = System::Drawing::Point(170, 77);
				this->keys_list->Name = L"keys_list";
				this->keys_list->Size = System::Drawing::Size(86, 21);
				this->keys_list->TabIndex = 14;
				this->keys_list->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::keys_list_SelectedIndexChanged);
				// 
				// ChangeTextDownButton
				// 
				this->ChangeTextDownButton->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->ChangeTextDownButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				this->ChangeTextDownButton->Location = System::Drawing::Point(80, 493);
				this->ChangeTextDownButton->Name = L"ChangeTextDownButton";
				this->ChangeTextDownButton->Size = System::Drawing::Size(150, 37);
				this->ChangeTextDownButton->TabIndex = 12;
				this->ChangeTextDownButton->Text = L"Cancel Changes";
				this->ChangeTextDownButton->UseVisualStyleBackColor = true;
				this->ChangeTextDownButton->Click += gcnew System::EventHandler(this, &MyForm::ChangeTextDownButton_Click);
				// 
				// ConformityTable
				// 
				this->ConformityTable->Dock = System::Windows::Forms::DockStyle::Right;
				this->ConformityTable->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(204)));
				this->ConformityTable->Location = System::Drawing::Point(1184, 0);
				this->ConformityTable->Multiline = true;
				this->ConformityTable->Name = L"ConformityTable";
				this->ConformityTable->Size = System::Drawing::Size(100, 561);
				this->ConformityTable->TabIndex = 13;
				// 
				// MyForm
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(1284, 561);
				this->Controls->Add(this->buttons_panel);
				this->Controls->Add(this->DictionaryConformityText);
				this->Controls->Add(this->TextBox);
				this->Controls->Add(this->ConformityTable);
				this->MinimumSize = System::Drawing::Size(1000, 600);
				this->Name = L"MyForm";
				this->Text = L"SympleCryptanalysis";
				this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
				this->buttons_panel->ResumeLayout(false);
				this->buttons_panel->PerformLayout();
				this->ResumeLayout(false);
				this->PerformLayout();

			}
#pragma endregion
		
		private: System::Void MyForm_Resize(System::Object^  sender, System::EventArgs^  e) {
			TextBox->Size = System::Drawing::Size(MyForm::Size.Width / 2, TextBox->Size.Height);
			buttons_panel->Size = System::Drawing::Size(MyForm::Size.Width / 4, buttons_panel->Size.Height);
		}


		
		// Обработка нажатия кнопки отката измений
		private: System::Void ChangeTextDownButton_Click(System::Object^  sender, System::EventArgs^  e) {
			String^ conformity_table; String^ text ;
			WordProcessing::changeTextDown(&text, &conformity_table);
			TextBox->Text = text;
			ConformityTable->Text = conformity_table;
		}

		private: System::Void key_lengths_Click(System::Object^  sender, System::EventArgs^  e) {

			if (TextBox->Text == "") return;
		
			key_lengths_list->Items->Clear();
			using namespace VigenereAnalysis;
		
			String ^text = TextBox->Text->ToLower();
		
			// Определяем длину ключа
			int* lenght = (result(KasiskiExamination(text), Index(text)));

			for (int i = 0; i < 10; i++) key_lengths_list->Items->Add(lenght[i]);
		}
		
		private: System::Void key_lengths_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

			if (TextBox->Text == "") return;
			
			keys_list->Items->Clear();

			using namespace VigenereAnalysis;

			String ^text = TextBox->Text->ToLower();
			int key_length = int::Parse(key_lengths_list->Text);
			
			// Разбиваем текст на группы
			array<System::String ^>^ groups = gcnew array<System::String^>(100);
			splitIntoGroups(text, key_length, groups);

			// Подбираем ключ
			array<System::String ^>^ keys = gcnew array<System::String^>(100);
			keyDetermination(&keys, groups, key_length);

			int i = 0; while (i < 20 && keys[i]) { keys_list->Items->Add(keys[i]); i++; }
		}

		private: System::Void keys_list_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			String^ conformity_table; String^ text = TextBox->Text->ToLower();
			WordProcessing::changeTextUp(&text, &conformity_table, NULL, keys_list->Text);
			TextBox->Text = text;
			ConformityTable->Text = conformity_table;
		}
				

		private: System::Void keys_list_Click(System::Object^  sender, System::EventArgs^  e) {
			
			if (TextBox->Text == "") return;	

			String^ text = TextBox->Text->ToLower();

			array<System::String ^>^ words = LinguisticAnalysis::DictionaryBasedChange(text, int::Parse(substring_length->Text), int::Parse(word_length->Text), int::Parse(incorrect_symbols_amount->Text), int::Parse(substring_position->Text));

			changeable_words_list->Items->Clear();
			int i = 0; while (i < 20 && words[i]){ changeable_words_list->Items->Add(words[i]); i++; }

		}
		
		private: System::Void changeable_words_list_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			
			if (TextBox->Text == "") return;

			String^ conformity_table; String^ text = TextBox->Text->ToLower();

			changeable_words_list->Text;
			String^ temp = DictionaryConformityText->Text;
			DictionaryConformityText->Text = LinguisticAnalysis::DictionaryMakeChange(temp, &text, keys_list->Text, &conformity_table, changeable_words_list->Text, int::Parse(word_length->Text));

			TextBox->Text = text;
			ConformityTable->Text = conformity_table;
		}
		private: System::Void changeable_words_list_Click(System::Object^  sender, System::EventArgs^  e) {
			
			if (TextBox->Text == "") return;

			changeable_words_list->Items->Clear();
			String^ conformity_table; String^ text = TextBox->Text->ToLower();
			array<System::String ^>^ words = LinguisticAnalysis::DictionaryBasedChange(text, int::Parse(substring_length->Text), int::Parse(word_length->Text), int::Parse(incorrect_symbols_amount->Text), int::Parse(substring_position->Text));
			TextBox->Text = text;
			ConformityTable->Text = conformity_table;
			for (int i = 0; i < 100; i++) if (i < words->Length && words[i]) changeable_words_list->Items->Add(words[i]); else break;
			DictionaryConformityText->Text = words[0];
		}
		
		private: System::Void TextBox_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			
			if (TextBox->Text == "") return;

			if (e->Clicks == true && e->Button == System::Windows::Forms::MouseButtons::Left) {
			
				int position = TextBox->GetCharIndexFromPosition(Point(e->X, e->Y));

					replaceable_symbol->Text = TextBox->Text[position].ToString() + "";
					symbol_position->Text = position.ToString();
			}
		}
		private: System::Void replacing_symbol_TextChanged(System::Object^  sender, System::EventArgs^  e) {

			if (TextBox->Text == "") return;


			WordProcessing::Alphabit alph("rus");
			if (replacing_symbol->Text != L"" && replaceable_symbol->Text != L"" &&
				alph.isLetter(replacing_symbol->Text[0]) && alph.isLetter(replaceable_symbol->Text[0])) {

				int* conformity = WordProcessing::getLastConformity();
				String ^ tmp; for (int i = 0; i < alph.length; i++) tmp += alph.getLetter(conformity[i]);

				int replacing = replacing_symbol->Text[0] - alph.firstchar;
				int replaceable = replaceable_symbol->Text[0] - alph.firstchar;
				String^ key = keys_list->Text;
				int position = int::Parse(symbol_position->Text);
				int not_letters_amount = 0; for (int i = 0; i < position; i++) if (!alph.isLetter(TextBox->Text[i])) not_letters_amount++;
				position -= not_letters_amount;
				int shift = key[position % key->Length] - key[0];


				for (int i = 0; i < alph.length; i++)
					if (conformity[i] == (alph.length + replaceable + shift) % alph.length) {
						for (int j = 0; j < alph.length; j++) {
							if (i != j && conformity[j] == (alph.length + replacing + shift) % alph.length) {

								int temp = conformity[i];
								conformity[i] = conformity[j];
								conformity[j] = temp;
								int tempTest[50] = { 0 };
								for (int l = 0; l < alph.length; l++)
									tempTest[l] = conformity[l];

								break;
							}

						}
						break;
					}


				String^ conformity_table; String^ text = TextBox->Text->ToLower();
				WordProcessing::changeTextUp(&text, &conformity_table, conformity, keys_list->Text);
				TextBox->Text = text; ConformityTable->Text = conformity_table;
			}
		}
};
}