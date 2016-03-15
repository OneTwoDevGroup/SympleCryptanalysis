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

		private: System::Windows::Forms::Button^  CalcFreaquance;






		private: System::Windows::Forms::Panel^  panel1;
		private: System::Windows::Forms::TextBox^  FreaquancyTable;
		private: System::Windows::Forms::Button^  ChangeTextUpButton;
		private: System::Windows::Forms::Button^  ChangeTextDownButton;
		private: System::Windows::Forms::Button^  FindInDictionaryButton;
		private: System::Windows::Forms::TextBox^  DictionaryConformityText;








		protected:

		protected:

		protected:

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
				this->CalcFreaquance = (gcnew System::Windows::Forms::Button());
				this->panel1 = (gcnew System::Windows::Forms::Panel());
				this->DictionaryConformityText = (gcnew System::Windows::Forms::TextBox());
				this->FindInDictionaryButton = (gcnew System::Windows::Forms::Button());
				this->ChangeTextDownButton = (gcnew System::Windows::Forms::Button());
				this->ChangeTextUpButton = (gcnew System::Windows::Forms::Button());
				this->FreaquancyTable = (gcnew System::Windows::Forms::TextBox());
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
				this->TextBox->TextChanged += gcnew System::EventHandler(this, &MyForm::TextBox_TextChanged);
				// 
				// CalcFreaquance
				// 
				this->CalcFreaquance->Anchor = System::Windows::Forms::AnchorStyles::Top;
				this->CalcFreaquance->Location = System::Drawing::Point(6, 12);
				this->CalcFreaquance->Name = L"CalcFreaquance";
				this->CalcFreaquance->Size = System::Drawing::Size(95, 39);
				this->CalcFreaquance->TabIndex = 3;
				this->CalcFreaquance->Text = L"Calculate Freaquance";
				this->CalcFreaquance->UseVisualStyleBackColor = true;
				this->CalcFreaquance->Click += gcnew System::EventHandler(this, &MyForm::CalcFreaquance_Click);
				// 
				// panel1
				// 
				this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
				this->panel1->Controls->Add(this->DictionaryConformityText);
				this->panel1->Controls->Add(this->FindInDictionaryButton);
				this->panel1->Controls->Add(this->ChangeTextDownButton);
				this->panel1->Controls->Add(this->ChangeTextUpButton);
				this->panel1->Controls->Add(this->CalcFreaquance);
				this->panel1->Location = System::Drawing::Point(500, 0);
				this->panel1->Name = L"panel1";
				this->panel1->Size = System::Drawing::Size(246, 561);
				this->panel1->TabIndex = 5;
				// 
				// DictionaryConformityText
				// 
				this->DictionaryConformityText->Anchor = System::Windows::Forms::AnchorStyles::Top;
				this->DictionaryConformityText->Location = System::Drawing::Point(7, 121);
				this->DictionaryConformityText->Multiline = true;
				this->DictionaryConformityText->Name = L"DictionaryConformityText";
				this->DictionaryConformityText->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
				this->DictionaryConformityText->Size = System::Drawing::Size(229, 440);
				this->DictionaryConformityText->TabIndex = 7;
				// 
				// FindInDictionaryButton
				// 
				this->FindInDictionaryButton->Location = System::Drawing::Point(7, 56);
				this->FindInDictionaryButton->Name = L"FindInDictionaryButton";
				this->FindInDictionaryButton->Size = System::Drawing::Size(94, 38);
				this->FindInDictionaryButton->TabIndex = 6;
				this->FindInDictionaryButton->Text = L"Find In Dictionary";
				this->FindInDictionaryButton->UseVisualStyleBackColor = true;
				this->FindInDictionaryButton->Click += gcnew System::EventHandler(this, &MyForm::FindInDictionaryButton_Click);
				// 
				// ChangeTextDownButton
				// 
				this->ChangeTextDownButton->Location = System::Drawing::Point(141, 57);
				this->ChangeTextDownButton->Name = L"ChangeTextDownButton";
				this->ChangeTextDownButton->Size = System::Drawing::Size(95, 37);
				this->ChangeTextDownButton->TabIndex = 5;
				this->ChangeTextDownButton->Text = L"Cancel Changes";
				this->ChangeTextDownButton->UseVisualStyleBackColor = true;
				this->ChangeTextDownButton->Click += gcnew System::EventHandler(this, &MyForm::ChangeTextDownButton_Click);
				// 
				// ChangeTextUpButton
				// 
				this->ChangeTextUpButton->Location = System::Drawing::Point(141, 14);
				this->ChangeTextUpButton->Name = L"ChangeTextUpButton";
				this->ChangeTextUpButton->Size = System::Drawing::Size(95, 37);
				this->ChangeTextUpButton->TabIndex = 4;
				this->ChangeTextUpButton->Text = L"Change Text";
				this->ChangeTextUpButton->UseVisualStyleBackColor = true;
				this->ChangeTextUpButton->Click += gcnew System::EventHandler(this, &MyForm::ChangeTextUpButton_Click);
				// 
				// FreaquancyTable
				// 
				this->FreaquancyTable->Dock = System::Windows::Forms::DockStyle::Right;
				this->FreaquancyTable->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(204)));
				this->FreaquancyTable->Location = System::Drawing::Point(742, 0);
				this->FreaquancyTable->Multiline = true;
				this->FreaquancyTable->Name = L"FreaquancyTable";
				this->FreaquancyTable->Size = System::Drawing::Size(242, 561);
				this->FreaquancyTable->TabIndex = 6;
				// 
				// MyForm
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(984, 561);
				this->Controls->Add(this->FreaquancyTable);
				this->Controls->Add(this->panel1);
				this->Controls->Add(this->TextBox);
				this->MinimumSize = System::Drawing::Size(1000, 600);
				this->Name = L"MyForm";
				this->Text = L"SympleCryptanalysis";
				this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
				this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
				this->panel1->ResumeLayout(false);
				this->panel1->PerformLayout();
				this->ResumeLayout(false);
				this->PerformLayout();

			}
#pragma endregion
		private: System::Void MyForm_Resize(System::Object^  sender, System::EventArgs^  e) {
			TextBox->Size = System::Drawing::Size(MyForm::Size.Width / 2, TextBox->Size.Height);
		}
		private: System::Void TextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			// TODO: Analysis
		}
		private: System::Void tableLayoutPanel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		}
		private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		}
		private: System::Void CalcFreaquance_Click(System::Object^  sender, System::EventArgs^  e) {
			FreaquancyTable->Text = FreaquancyAnalysis::CalcFreaquancy(TextBox->Text);
		}
		private: System::Void ChangeTextUpButton_Click(System::Object^  sender, System::EventArgs^  e) {
			TextBox->Text = WordProcessing::ChangeTextUp(TextBox->Text, FreaquancyTable->Text);
		}

		private: System::Void ChangeTextDownButton_Click(System::Object^  sender, System::EventArgs^  e) {
			String^ text; String^ freaquancy;
			if (!WordProcessing::ChangeDown(&text, &freaquancy)) return;
			TextBox->Text = text;
			FreaquancyTable->Text = freaquancy;
		}
		private: System::Void FindInDictionaryButton_Click(System::Object^  sender, System::EventArgs^  e) {
			DictionaryConformityText->Text = LinguisticAnalysis::DictionaryAnalysis(TextBox->Text);
		}
		};
	}