#pragma once
#include"func.h"
#include"DataForm.h"
namespace ProjectECG {

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
	private: System::Windows::Forms::Button^  DataButton;
	private: System::Windows::Forms::Button^  AnalyzeButton;


	protected:


	private: System::Windows::Forms::TextBox^  ConclusionText;

	private: System::Windows::Forms::Label^  Conclusion;
	private: System::Windows::Forms::Label^  label1;
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
			this->DataButton = (gcnew System::Windows::Forms::Button());
			this->AnalyzeButton = (gcnew System::Windows::Forms::Button());
			this->ConclusionText = (gcnew System::Windows::Forms::TextBox());
			this->Conclusion = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// DataButton
			// 
			this->DataButton->AutoSize = true;
			this->DataButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DataButton->Location = System::Drawing::Point(54, 80);
			this->DataButton->Name = L"DataButton";
			this->DataButton->Size = System::Drawing::Size(164, 63);
			this->DataButton->TabIndex = 21;
			this->DataButton->Text = L"Ввести данные";
			this->DataButton->UseVisualStyleBackColor = true;
			this->DataButton->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// AnalyzeButton
			// 
			this->AnalyzeButton->AutoSize = true;
			this->AnalyzeButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->AnalyzeButton->Location = System::Drawing::Point(54, 173);
			this->AnalyzeButton->Name = L"AnalyzeButton";
			this->AnalyzeButton->Size = System::Drawing::Size(164, 63);
			this->AnalyzeButton->TabIndex = 22;
			this->AnalyzeButton->Text = L"Анализ";
			this->AnalyzeButton->UseVisualStyleBackColor = true;
			this->AnalyzeButton->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// ConclusionText
			// 
			this->ConclusionText->BackColor = System::Drawing::SystemColors::Window;
			this->ConclusionText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->ConclusionText->Location = System::Drawing::Point(939, 210);
			this->ConclusionText->Name = L"ConclusionText";
			this->ConclusionText->ReadOnly = true;
			this->ConclusionText->Size = System::Drawing::Size(100, 26);
			this->ConclusionText->TabIndex = 23;
			this->ConclusionText->Text = L"Норма";
			// 
			// Conclusion
			// 
			this->Conclusion->AutoSize = true;
			this->Conclusion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->Conclusion->Location = System::Drawing::Point(802, 213);
			this->Conclusion->Name = L"Conclusion";
			this->Conclusion->Size = System::Drawing::Size(68, 20);
			this->Conclusion->TabIndex = 24;
			this->Conclusion->Text = L"Вывод: ";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(568, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(32, 13);
			this->label1->TabIndex = 25;
			this->label1->Text = L"V 1.0";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1264, 986);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Conclusion);
			this->Controls->Add(this->ConclusionText);
			this->Controls->Add(this->AnalyzeButton);
			this->Controls->Add(this->DataButton);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	DataForm^ form2 = gcnew DataForm();
	form2->ShowDialog();
}
private: System::Void tableLayoutPanel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}


private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		//Вывод = //Draw Diagram; Можно вернуть значение во время рисовки
		//Ну или я его откуда-то должен взять

	}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}