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

		void print_vector(std::vector<double> v)
		{
			for (int i = 0; i < v.size(); i++)
			{
				this->ConclusionText->Text += System::Convert::ToString(v[i]);
			}
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



	private: System::Windows::Forms::TextBox^  ConclusionText;

	private: System::Windows::Forms::Label^  Conclusion;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  DrawButton;
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
			this->ConclusionText = (gcnew System::Windows::Forms::TextBox());
			this->Conclusion = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->DrawButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// DataButton
			// 
			this->DataButton->AutoSize = true;
			this->DataButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DataButton->Location = System::Drawing::Point(12, 303);
			this->DataButton->Margin = System::Windows::Forms::Padding(2);
			this->DataButton->Name = L"DataButton";
			this->DataButton->Size = System::Drawing::Size(203, 41);
			this->DataButton->TabIndex = 21;
			this->DataButton->Text = L"Ввести данные";
			this->DataButton->UseVisualStyleBackColor = true;
			this->DataButton->Click += gcnew System::EventHandler(this, &MyForm::DataButton_Click);
			// 
			// AnalyzeButton
			// 
			this->AnalyzeButton->AutoSize = true;
			this->AnalyzeButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->AnalyzeButton->Location = System::Drawing::Point(219, 303);
			this->AnalyzeButton->Margin = System::Windows::Forms::Padding(2);
			this->AnalyzeButton->Name = L"AnalyzeButton";
			this->AnalyzeButton->Size = System::Drawing::Size(203, 41);
			this->AnalyzeButton->TabIndex = 22;
			this->AnalyzeButton->Text = L"Анализировать";
			this->AnalyzeButton->UseVisualStyleBackColor = true;
			this->AnalyzeButton->Click += gcnew System::EventHandler(this, &MyForm::AnalyzeButton_Click);
			// 
			// ConclusionText
			// 
			this->ConclusionText->BackColor = System::Drawing::SystemColors::Window;
			this->ConclusionText->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ConclusionText->Location = System::Drawing::Point(1113, 144);
			this->ConclusionText->Margin = System::Windows::Forms::Padding(2);
			this->ConclusionText->Multiline = true;
			this->ConclusionText->Name = L"ConclusionText";
			this->ConclusionText->ReadOnly = true;
			this->ConclusionText->Size = System::Drawing::Size(400, 200);
			this->ConclusionText->TabIndex = 23;
			// 
			// Conclusion
			// 
			this->Conclusion->AutoSize = true;
			this->Conclusion->Font = (gcnew System::Drawing::Font(L"Times New Roman", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Conclusion->Location = System::Drawing::Point(1106, 89);
			this->Conclusion->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Conclusion->Name = L"Conclusion";
			this->Conclusion->Size = System::Drawing::Size(304, 42);
			this->Conclusion->TabIndex = 24;
			this->Conclusion->Text = L"Результат анализа:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(5, 6);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(32, 13);
			this->label1->TabIndex = 25;
			this->label1->Text = L"V 1.0";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(12, 349);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1501, 401);
			this->pictureBox1->TabIndex = 26;
			this->pictureBox1->TabStop = false;
			// 
			// DrawButton
			// 
			this->DrawButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DrawButton->Location = System::Drawing::Point(427, 304);
			this->DrawButton->Name = L"DrawButton";
			this->DrawButton->Size = System::Drawing::Size(203, 40);
			this->DrawButton->TabIndex = 27;
			this->DrawButton->Text = L"Построить график";
			this->DrawButton->UseVisualStyleBackColor = true;
			this->DrawButton->Click += gcnew System::EventHandler(this, &MyForm::DrawButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1528, 761);
			this->Controls->Add(this->DrawButton);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Conclusion);
			this->Controls->Add(this->ConclusionText);
			this->Controls->Add(this->AnalyzeButton);
			this->Controls->Add(this->DataButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Margin = System::Windows::Forms::Padding(2);
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
	}

	private: System::Void DataButton_Click(System::Object^  sender, System::EventArgs^  e) {
		ofstream f("data.csv", ios::out);
		f << "2 St." << ";";
		f.close();

		DataForm^ form2 = gcnew DataForm();
		form2->ShowDialog();

		/*if (form2->DialogResult == System::Windows::Forms::DialogResult::OK)
			form2->Close();*/
	}

	private: System::Void tableLayoutPanel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	}

	private: System::Void AnalyzeButton_Click(System::Object^  sender, System::EventArgs^  e) {
		//Инициализация класса информации о зубцах значениями из DataForm
		WavesData w("data.csv");

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
		WavesData w("data.csv");

		DrawGrid(g, pictureBox1->Width, pictureBox1->Height);
		DrawGraphic(g, pictureBox1->Width, pictureBox1->Height, w);
	}






	};

}

