#pragma once

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
		private: System::Windows::Forms::Panel^  panel1;
		private: System::Windows::Forms::Button^  FindInDictionaryButton;
		private: System::Windows::Forms::Button^  ChangeTextDownButton;
		private: System::Windows::Forms::Button^  ChangeTextUpButton;
		private: System::Windows::Forms::TextBox^  ConformityTable;
		private: System::Windows::Forms::ListBox^  listBox1;

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
				this->panel1 = (gcnew System::Windows::Forms::Panel());
				this->FindInDictionaryButton = (gcnew System::Windows::Forms::Button());
				this->ChangeTextDownButton = (gcnew System::Windows::Forms::Button());
				this->ChangeTextUpButton = (gcnew System::Windows::Forms::Button());
				this->ConformityTable = (gcnew System::Windows::Forms::TextBox());
				this->listBox1 = (gcnew System::Windows::Forms::ListBox());
				this->panel1->SuspendLayout();
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
				this->TextBox->Size = System::Drawing::Size(500, 561);
				this->TextBox->TabIndex = 1;
				this->TextBox->Text = L"";
				// 
				// DictionaryConformityText
				// 
				this->DictionaryConformityText->Dock = System::Windows::Forms::DockStyle::Right;
				this->DictionaryConformityText->Location = System::Drawing::Point(897, 0);
				this->DictionaryConformityText->Multiline = true;
				this->DictionaryConformityText->Name = L"DictionaryConformityText";
				this->DictionaryConformityText->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
				this->DictionaryConformityText->Size = System::Drawing::Size(229, 561);
				this->DictionaryConformityText->TabIndex = 11;
				// 
				// panel1
				// 
				this->panel1->Controls->Add(this->FindInDictionaryButton);
				this->panel1->Controls->Add(this->ChangeTextDownButton);
				this->panel1->Controls->Add(this->ChangeTextUpButton);
				this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
				this->panel1->Location = System::Drawing::Point(500, 0);
				this->panel1->Name = L"panel1";
				this->panel1->Size = System::Drawing::Size(397, 561);
				this->panel1->TabIndex = 12;
				// 
				// FindInDictionaryButton
				// 
				this->FindInDictionaryButton->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->FindInDictionaryButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				this->FindInDictionaryButton->Location = System::Drawing::Point(124, 370);
				this->FindInDictionaryButton->Name = L"FindInDictionaryButton";
				this->FindInDictionaryButton->Size = System::Drawing::Size(149, 38);
				this->FindInDictionaryButton->TabIndex = 13;
				this->FindInDictionaryButton->Text = L"Find In Dictionary";
				this->FindInDictionaryButton->UseVisualStyleBackColor = true;
				this->FindInDictionaryButton->Click += gcnew System::EventHandler(this, &MyForm::FindInDictionaryButton_Click);
				// 
				// ChangeTextDownButton
				// 
				this->ChangeTextDownButton->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->ChangeTextDownButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				this->ChangeTextDownButton->Location = System::Drawing::Point(124, 262);
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
				this->ChangeTextUpButton->Location = System::Drawing::Point(124, 153);
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
				this->ConformityTable->Location = System::Drawing::Point(1126, 0);
				this->ConformityTable->Multiline = true;
				this->ConformityTable->Name = L"ConformityTable";
				this->ConformityTable->Size = System::Drawing::Size(100, 561);
				this->ConformityTable->TabIndex = 13;
				// 
				// listBox1
				// 
				this->listBox1->FormattingEnabled = true;
				this->listBox1->Location = System::Drawing::Point(266, 172);
				this->listBox1->Name = L"listBox1";
				this->listBox1->Size = System::Drawing::Size(8, 4);
				this->listBox1->TabIndex = 14;
				// 
				// MyForm
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(1226, 561);
				this->Controls->Add(this->listBox1);
				this->Controls->Add(this->panel1);
				this->Controls->Add(this->DictionaryConformityText);
				this->Controls->Add(this->TextBox);
				this->Controls->Add(this->ConformityTable);
				this->MinimumSize = System::Drawing::Size(1000, 600);
				this->Name = L"MyForm";
				this->Text = L"SympleCryptanalysis";
				this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
				this->panel1->ResumeLayout(false);
				this->ResumeLayout(false);
				this->PerformLayout();

			}
#pragma endregion
		
		private: System::Void MyForm_Resize(System::Object^  sender, System::EventArgs^  e) {
			TextBox->Size = System::Drawing::Size(MyForm::Size.Width / 2, TextBox->Size.Height);
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
			String^ conformity_table; String^ text;
			WordProcessing::changeTextDown(&text, &conformity_table);
			TextBox->Text = text;
			ConformityTable->Text = conformity_table;
		}

		// Обработка нажатия кнопки поиска по словарю
		private: System::Void FindInDictionaryButton_Click(System::Object^  sender, System::EventArgs^  e) {
			DictionaryConformityText->Text = LinguisticAnalysis::DictionaryAnalysis(TextBox->Text);
		}
	};
}