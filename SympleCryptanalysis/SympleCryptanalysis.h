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


		private: System::Windows::Forms::Button^  FindInDictionaryButton;
		private: System::Windows::Forms::Button^  ChangeTextDownButton;
		private: System::Windows::Forms::Button^  ChangeTextUpButton;
		private: System::Windows::Forms::TextBox^  ConformityTable;
		private: System::Windows::Forms::ComboBox^  keys_list;

		private: System::Windows::Forms::ComboBox^  key_lengths_list;
		private: System::Windows::Forms::Label^  replaceable_symbol_label;
		private: System::Windows::Forms::Label^  replacing_symbol_label;
		private: System::Windows::Forms::TextBox^  replaceable_symbol;
		private: System::Windows::Forms::TextBox^  replacing_symbol;
		private: System::Windows::Forms::Label^  key_label;
		private: System::Windows::Forms::Label^  key_len_label;






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
				this->replaceable_symbol_label = (gcnew System::Windows::Forms::Label());
				this->replacing_symbol_label = (gcnew System::Windows::Forms::Label());
				this->replaceable_symbol = (gcnew System::Windows::Forms::TextBox());
				this->replacing_symbol = (gcnew System::Windows::Forms::TextBox());
				this->key_label = (gcnew System::Windows::Forms::Label());
				this->key_len_label = (gcnew System::Windows::Forms::Label());
				this->key_lengths_list = (gcnew System::Windows::Forms::ComboBox());
				this->keys_list = (gcnew System::Windows::Forms::ComboBox());
				this->FindInDictionaryButton = (gcnew System::Windows::Forms::Button());
				this->ChangeTextDownButton = (gcnew System::Windows::Forms::Button());
				this->ChangeTextUpButton = (gcnew System::Windows::Forms::Button());
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
				this->buttons_panel->Controls->Add(this->replaceable_symbol_label);
				this->buttons_panel->Controls->Add(this->replacing_symbol_label);
				this->buttons_panel->Controls->Add(this->replaceable_symbol);
				this->buttons_panel->Controls->Add(this->replacing_symbol);
				this->buttons_panel->Controls->Add(this->key_label);
				this->buttons_panel->Controls->Add(this->key_len_label);
				this->buttons_panel->Controls->Add(this->key_lengths_list);
				this->buttons_panel->Controls->Add(this->keys_list);
				this->buttons_panel->Controls->Add(this->FindInDictionaryButton);
				this->buttons_panel->Controls->Add(this->ChangeTextDownButton);
				this->buttons_panel->Controls->Add(this->ChangeTextUpButton);
				this->buttons_panel->Dock = System::Windows::Forms::DockStyle::Fill;
				this->buttons_panel->Location = System::Drawing::Point(650, 0);
				this->buttons_panel->Name = L"buttons_panel";
				this->buttons_panel->Size = System::Drawing::Size(330, 561);
				this->buttons_panel->TabIndex = 12;
				// 
				// replaceable_symbol_label
				// 
				this->replaceable_symbol_label->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->replaceable_symbol_label->AutoSize = true;
				this->replaceable_symbol_label->Location = System::Drawing::Point(167, 176);
				this->replaceable_symbol_label->Name = L"replaceable_symbol_label";
				this->replaceable_symbol_label->Size = System::Drawing::Size(97, 13);
				this->replaceable_symbol_label->TabIndex = 21;
				this->replaceable_symbol_label->Text = L"replaceable symbol";
				// 
				// replacing_symbol_label
				// 
				this->replacing_symbol_label->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->replacing_symbol_label->AutoSize = true;
				this->replacing_symbol_label->Location = System::Drawing::Point(62, 176);
				this->replacing_symbol_label->Name = L"replacing_symbol_label";
				this->replacing_symbol_label->Size = System::Drawing::Size(85, 13);
				this->replacing_symbol_label->TabIndex = 20;
				this->replacing_symbol_label->Text = L"replacing symbol";
				// 
				// replaceable_symbol
				// 
				this->replaceable_symbol->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->replaceable_symbol->Location = System::Drawing::Point(170, 204);
				this->replaceable_symbol->Name = L"replaceable_symbol";
				this->replaceable_symbol->Size = System::Drawing::Size(86, 20);
				this->replaceable_symbol->TabIndex = 19;
				this->replaceable_symbol->TextChanged += gcnew System::EventHandler(this, &MyForm::replaceable_symbol_TextChanged);
				this->replaceable_symbol->Enter += gcnew System::EventHandler(this, &MyForm::replaceable_symbol_Enter);
				// 
				// replacing_symbol
				// 
				this->replacing_symbol->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->replacing_symbol->Location = System::Drawing::Point(61, 204);
				this->replacing_symbol->Name = L"replacing_symbol";
				this->replacing_symbol->Size = System::Drawing::Size(86, 20);
				this->replacing_symbol->TabIndex = 18;
				this->replacing_symbol->TextChanged += gcnew System::EventHandler(this, &MyForm::replacing_symbol_TextChanged);
				this->replacing_symbol->Enter += gcnew System::EventHandler(this, &MyForm::replacing_symbol_Enter);
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
				// FindInDictionaryButton
				// 
				this->FindInDictionaryButton->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->FindInDictionaryButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				this->FindInDictionaryButton->Location = System::Drawing::Point(80, 490);
				this->FindInDictionaryButton->Name = L"FindInDictionaryButton";
				this->FindInDictionaryButton->Size = System::Drawing::Size(150, 38);
				this->FindInDictionaryButton->TabIndex = 13;
				this->FindInDictionaryButton->Text = L"Find In Dictionary";
				this->FindInDictionaryButton->UseVisualStyleBackColor = true;
				this->FindInDictionaryButton->Click += gcnew System::EventHandler(this, &MyForm::FindInDictionaryButton_Click);
				// 
				// ChangeTextDownButton
				// 
				this->ChangeTextDownButton->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->ChangeTextDownButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				this->ChangeTextDownButton->Location = System::Drawing::Point(80, 414);
				this->ChangeTextDownButton->Name = L"ChangeTextDownButton";
				this->ChangeTextDownButton->Size = System::Drawing::Size(150, 37);
				this->ChangeTextDownButton->TabIndex = 12;
				this->ChangeTextDownButton->Text = L"Cancel Changes";
				this->ChangeTextDownButton->UseVisualStyleBackColor = true;
				this->ChangeTextDownButton->Click += gcnew System::EventHandler(this, &MyForm::ChangeTextDownButton_Click);
				// 
				// ChangeTextUpButton
				// 
				this->ChangeTextUpButton->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->ChangeTextUpButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				this->ChangeTextUpButton->Location = System::Drawing::Point(80, 331);
				this->ChangeTextUpButton->Name = L"ChangeTextUpButton";
				this->ChangeTextUpButton->Size = System::Drawing::Size(150, 37);
				this->ChangeTextUpButton->TabIndex = 11;
				this->ChangeTextUpButton->Text = L"Change Text";
				this->ChangeTextUpButton->UseVisualStyleBackColor = true;
				this->ChangeTextUpButton->Click += gcnew System::EventHandler(this, &MyForm::ChangeTextUpButton_Click);
				// 
				// ConformityTable
				// 
				this->ConformityTable->Dock = System::Windows::Forms::DockStyle::Right;
				this->ConformityTable->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
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


		
		// Обработка нажатия кнопки изменения текста
		private: System::Void ChangeTextUpButton_Click(System::Object^  sender, System::EventArgs^  e) {
			
			String^ conformity_table; String^ text = TextBox->Text->ToLower(); 
			WordProcessing::changeTextUp(&text, &conformity_table);
			TextBox->Text = text;
			ConformityTable->Text = conformity_table;
		}

		// Обработка нажатия кнопки отката измений
		private: System::Void ChangeTextDownButton_Click(System::Object^  sender, System::EventArgs^  e) {
			String^ conformity_table; String^ text ;
			WordProcessing::changeTextDown(&text, &conformity_table);
			TextBox->Text = text;
			ConformityTable->Text = conformity_table;
		}

		// Обработка нажатия кнопки поиска по словарю
		private: System::Void FindInDictionaryButton_Click(System::Object^  sender, System::EventArgs^  e) {
			String^ conformity_table; String^ text = TextBox->Text->ToLower();
			DictionaryConformityText->Text = LinguisticAnalysis::DictionaryAnalysis(&text, &conformity_table);
			TextBox->Text = text;
			ConformityTable->Text = conformity_table;
		}
		private: System::Void key_lengths_Click(System::Object^  sender, System::EventArgs^  e) {
		
			key_lengths_list->Items->Clear();
			using namespace VigenereAnalysis;
		
			String ^text = TextBox->Text->ToLower();
		
			// Определяем длину ключа
			int* lenght = (result(KasiskiExamination(text), Index(text)));

			for (int i = 0; i < 10; i++) key_lengths_list->Items->Add(lenght[i]);
		}
		
		private: System::Void key_lengths_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			
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

		private: System::Void replacing_symbol_Enter(System::Object^  sender, System::EventArgs^  e) {

		}
		private: System::Void replaceable_symbol_Enter(System::Object^  sender, System::EventArgs^  e) {

		}
	private: System::Void replacing_symbol_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		//WordProcessing::Alphabit alph("rus");
		//if (replacing_symbol->Text != L"" && replaceable_symbol->Text != L"" &&
		//	alph.isLetter(replacing_symbol->Text[0]) && alph.isLetter(replaceable_symbol->Text[0])) {

		//	int* conformity = (int*)malloc(MAXALPHLEN * sizeof(int));

		//	for (int i = 0; i < alph.length; i++) conformity[i] = -1;

		//	conformity[replacing_symbol->Text[0] - alph.firstchar] = replaceable_symbol->Text[0] - alph.firstchar;
		//	conformity[replaceable_symbol->Text[0] - alph.firstchar] = replacing_symbol->Text[0] - alph.firstchar;

		//	String^ conformity_table; String^ text = TextBox->Text->ToLower();
		//	WordProcessing::changeTextUp(&text, &conformity_table, &conformity);
		//	TextBox->Text = text; ConformityTable->Text = conformity_table;
		//}
	}

	private: System::Void replaceable_symbol_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		WordProcessing::Alphabit alph("rus");
		if (replacing_symbol->Text != L"" && replaceable_symbol->Text != L"" &&
			alph.isLetter(replacing_symbol->Text[0]) && alph.isLetter(replaceable_symbol->Text[0])) {

			int* conformity = (int*)malloc(MAXALPHLEN * sizeof(int));

			for (int i = 0; i < alph.length; i++) conformity[i] = -1;

			conformity[replacing_symbol->Text[0] - alph.firstchar] = replaceable_symbol->Text[0] - alph.firstchar;
			conformity[replaceable_symbol->Text[0] - alph.firstchar] = replacing_symbol->Text[0] - alph.firstchar;

			String^ conformity_table; String^ text = TextBox->Text->ToLower();
			WordProcessing::changeTextUp(&text, &conformity_table, &conformity);
			TextBox->Text = text; ConformityTable->Text = conformity_table;
		}
	}
};
}