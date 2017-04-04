#pragma once

#include "InterfaceFuncs.h"
#include "AnalysisFuncs.h"
#include "DataForm.h"
#include <math.h>

namespace ProjectECG {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms::DataVisualization::Charting;

	
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		MyForm(void) {

			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm() {
			if (components)
			{
				delete components;
			}
		}
 


	private: System::Windows::Forms::Button^  DataButton;
	private: System::Windows::Forms::Button^  AnalyzeButton;
	private: System::Windows::Forms::Button^ HelpButton;



	private: System::Windows::Forms::TextBox^  ConclusionText;

	private: System::Windows::Forms::Label^  Conclusion;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  DrawButton;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::ComboBox^  comboBox3;
	private:
		System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->DataButton = (gcnew System::Windows::Forms::Button());
			this->AnalyzeButton = (gcnew System::Windows::Forms::Button());
			this->HelpButton = (gcnew System::Windows::Forms::Button());
			this->ConclusionText = (gcnew System::Windows::Forms::TextBox());
			this->Conclusion = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->DrawButton = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// DataButton
			// 
			this->DataButton->AutoSize = true;
			this->DataButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DataButton->Location = System::Drawing::Point(12, 54);
			this->DataButton->Name = L"DataButton";
			this->DataButton->Size = System::Drawing::Size(432, 66);
			this->DataButton->TabIndex = 21;
			this->DataButton->Text = L"Enter data";
			this->DataButton->UseVisualStyleBackColor = true;
			this->DataButton->Click += gcnew System::EventHandler(this, &MyForm::DataButton_Click);
			// 
			// AnalyzeButton
			// 
			this->AnalyzeButton->AutoSize = true;
			this->AnalyzeButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->AnalyzeButton->Location = System::Drawing::Point(12, 135);
			this->AnalyzeButton->Name = L"AnalyzeButton";
			this->AnalyzeButton->Size = System::Drawing::Size(432, 66);
			this->AnalyzeButton->TabIndex = 22;
			this->AnalyzeButton->Text = L"Analyse";
			this->AnalyzeButton->UseVisualStyleBackColor = true;
			this->AnalyzeButton->Click += gcnew System::EventHandler(this, &MyForm::AnalyzeButton_Click);
			// 
			// HelpButton
			// 
			this->HelpButton->AutoSize = true;
			this->HelpButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->HelpButton->Location = System::Drawing::Point(466, 199);
			this->HelpButton->Margin = System::Windows::Forms::Padding(2);
			this->HelpButton->Name = L"HelpButton";
			this->HelpButton->Size = System::Drawing::Size(432, 62);
			this->HelpButton->TabIndex = 22;
			this->HelpButton->Text = L"Справка";
			this->HelpButton->UseVisualStyleBackColor = true;
			this->HelpButton->Click += gcnew System::EventHandler(this, &MyForm::HelpButton_Click);
			// 
			// ConclusionText
			// 
			this->ConclusionText->BackColor = System::Drawing::SystemColors::Window;
			this->ConclusionText->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ConclusionText->Location = System::Drawing::Point(1323, 174);
			this->ConclusionText->Multiline = true;
			this->ConclusionText->Name = L"ConclusionText";
			this->ConclusionText->ReadOnly = true;
			this->ConclusionText->Size = System::Drawing::Size(444, 239);
			this->ConclusionText->TabIndex = 23;
			// 
			// Conclusion
			// 
			this->Conclusion->AutoSize = true;
			this->Conclusion->Font = (gcnew System::Drawing::Font(L"Times New Roman", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Conclusion->Location = System::Drawing::Point(1316, 78);
			this->Conclusion->Name = L"Conclusion";
			this->Conclusion->Size = System::Drawing::Size(239, 42);
			this->Conclusion->TabIndex = 24;
			this->Conclusion->Text = L"Analysis result:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(8, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 20);
			this->label1->TabIndex = 25;
			this->label1->Text = L"V 2.0";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(12, 421);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1755, 522);
			this->pictureBox1->TabIndex = 26;
			this->pictureBox1->TabStop = false;
			// 
			// DrawButton
			// 
			this->DrawButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DrawButton->Location = System::Drawing::Point(28, 232);
			this->DrawButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->DrawButton->Name = L"DrawButton";
			this->DrawButton->Size = System::Drawing::Size(432, 62);
			this->DrawButton->TabIndex = 27;
			this->DrawButton->Text = L"Create ECG graphic";
			this->DrawButton->UseVisualStyleBackColor = true;
			this->DrawButton->Click += gcnew System::EventHandler(this, &MyForm::DrawButton_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->BackColor = System::Drawing::SystemColors::Menu;
			this->comboBox1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"1 St.", L"2 St.", L"3 St.", L"aVL", L"aVF", L"aVR",
					L"V1", L"V2", L"V3", L"V4", L"V5", L"V6"
			});
			this->comboBox1->Location = System::Drawing::Point(1115, 232);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(181, 29);
			this->comboBox1->TabIndex = 28;
			// 
			// comboBox2
			// 
			this->comboBox2->BackColor = System::Drawing::SystemColors::MenuBar;
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"1 St.", L"2 St.", L"3 St.", L"aVL", L"aVF", L"aVR",
					L"V1", L"V2", L"V3", L"V4", L"V5", L"V6"
			});
			this->comboBox2->Location = System::Drawing::Point(1145, 280);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(181, 29);
			this->comboBox2->TabIndex = 29;
			// 
			// comboBox3
			// 
			this->comboBox3->BackColor = System::Drawing::SystemColors::MenuBar;
			this->comboBox3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"1 St.", L"2 St.", L"3 St.", L"aVL", L"aVF", L"aVR",
					L"V1", L"V2", L"V3", L"V4", L"V5", L"V6"
			});
			this->comboBox3->Location = System::Drawing::Point(1136, 329);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(181, 29);
			this->comboBox3->TabIndex = 30;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1780, 957);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->DrawButton);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Conclusion);
			this->Controls->Add(this->ConclusionText);
			this->Controls->Add(this->AnalyzeButton);
			this->Controls->Add(this->DataButton);
			this->Controls->Add(this->HelpButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		this->comboBox1->SelectedItem = L"1 St.";
		this->comboBox2->SelectedItem = L"2 St.";
		this->comboBox3->SelectedItem = L"3 St.";

		PrepareFile("data.csv");
	}

	private: System::Void DataButton_Click(System::Object^  sender, System::EventArgs^  e) {
				ofstream f("data.csv", ios::out);
				f << "2 St." << ";";
				f.close();
		
				DataForm^ form2 = gcnew DataForm();
				 form2->ShowDialog();

				 if (form2->DialogResult == System::Windows::Forms::DialogResult::OK)
					 form2->Close();	
			 }

	private: System::Void tableLayoutPanel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	}

	private: System::Void AnalyzeButton_Click(System::Object^  sender, System::EventArgs^  e) {
		//Инициализация класса информации о зубцах значениями из DataForm
		WavesData w("data.csv", "1 St.");

		if (w.Check_arrhythmia())
		{
			this->ConclusionText->Clear();
			this->ConclusionText->Text = "У вас аритмия. Рекомендуем обратиться к врачу.";
		}
		else
		{
			this->ConclusionText->Clear();
			this->ConclusionText->Text = "Норма.";
		}

		this->ConclusionText->Text += " Ваша ЧСС = " + w.count_heart_rate() + ".";
	}


private: System::Void DrawButton_Click(System::Object^  sender, System::EventArgs^  e) {
	pictureBox1->Image = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
	Graphics^ g = Graphics::FromImage(pictureBox1->Image);

	WavesData w1("data.csv", this->comboBox1->SelectedItem->ToString());
	WavesData w2("data.csv", this->comboBox2->SelectedItem->ToString());
	WavesData w3("data.csv", this->comboBox3->SelectedItem->ToString());

	DrawGrid(g, pictureBox1->Width, pictureBox1->Height);

	DrawGraphic(g, pictureBox1->Width, pictureBox1->Height / 3, w1);
	DrawGraphic(g, pictureBox1->Width, pictureBox1->Height , w2);
	DrawGraphic(g, pictureBox1->Width, 2 *  pictureBox1->Height - 120, w3);
}

private: System::Void HelpButton_Click(System::Object^ sender, System::EventArgs^ e) {
	HelpForm^ form = gcnew HelpForm();
	form->Information->Text = System::IO::File::ReadAllText(L"helpmyform.txt", System::Text::Encoding::Default);
	form->ShowDialog();
}


};
};
	

