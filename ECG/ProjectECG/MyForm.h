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
 
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;

	private: System::Windows::Forms::Button^  DataButton;
	private: System::Windows::Forms::Button^  AnalyzeButton;



	private: System::Windows::Forms::TextBox^  ConclusionText;

	private: System::Windows::Forms::Label^  Conclusion;
	private: System::Windows::Forms::Label^  label1;
	private:
		System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::StripLine^  stripLine1 = (gcnew System::Windows::Forms::DataVisualization::Charting::StripLine());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->DataButton = (gcnew System::Windows::Forms::Button());
			this->AnalyzeButton = (gcnew System::Windows::Forms::Button());
			this->ConclusionText = (gcnew System::Windows::Forms::TextBox());
			this->Conclusion = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea1->AxisX->Interval = 10;
			chartArea1->AxisX->IntervalOffset = 10;
			chartArea1->AxisX->StripLines->Add(stripLine1);
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(8, 335);
			this->chart1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			series2->ChartArea = L"ChartArea1";
			series2->Legend = L"Legend1";
			series2->Name = L"Series2";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(827, 255);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// DataButton
			// 
			this->DataButton->AutoSize = true;
			this->DataButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DataButton->Location = System::Drawing::Point(8, 246);
			this->DataButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->DataButton->Name = L"DataButton";
			this->DataButton->Size = System::Drawing::Size(136, 41);
			this->DataButton->TabIndex = 21;
			this->DataButton->Text = L"Ввести данные";
			this->DataButton->UseVisualStyleBackColor = true;
			this->DataButton->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// AnalyzeButton
			// 
			this->AnalyzeButton->AutoSize = true;
			this->AnalyzeButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->AnalyzeButton->Location = System::Drawing::Point(8, 291);
			this->AnalyzeButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->AnalyzeButton->Name = L"AnalyzeButton";
			this->AnalyzeButton->Size = System::Drawing::Size(138, 41);
			this->AnalyzeButton->TabIndex = 22;
			this->AnalyzeButton->Text = L"Анализировать";
			this->AnalyzeButton->UseVisualStyleBackColor = true;
			this->AnalyzeButton->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// ConclusionText
			// 
			this->ConclusionText->BackColor = System::Drawing::SystemColors::Window;
			this->ConclusionText->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ConclusionText->Location = System::Drawing::Point(573, 246);
			this->ConclusionText->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->ConclusionText->Multiline = true;
			this->ConclusionText->Name = L"ConclusionText";
			this->ConclusionText->ReadOnly = true;
			this->ConclusionText->Size = System::Drawing::Size(263, 75);
			this->ConclusionText->TabIndex = 23;
			this->ConclusionText->Text = L"Норма";
			// 
			// Conclusion
			// 
			this->Conclusion->AutoSize = true;
			this->Conclusion->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Conclusion->Location = System::Drawing::Point(569, 209);
			this->Conclusion->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Conclusion->Name = L"Conclusion";
			this->Conclusion->Size = System::Drawing::Size(223, 31);
			this->Conclusion->TabIndex = 24;
			this->Conclusion->Text = L"Результат анализа:";
			this->Conclusion->Click += gcnew System::EventHandler(this, &MyForm::Conclusion_Click);
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
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(843, 599);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Conclusion);
			this->Controls->Add(this->ConclusionText);
			this->Controls->Add(this->AnalyzeButton);
			this->Controls->Add(this->DataButton);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		//Отрисовка графика
		chart1->Series->Clear();

		Series^ series1 = gcnew Series(L"сетка");
		Series^ series2 = gcnew Series(L"i*i");

		series1->Color = Color::Black;
		series1->BorderWidth = 2;

		series1->IsVisibleInLegend = true;
		series1->IsXValueIndexed = false;

		series1->ChartType = SeriesChartType::Line;
		chart1->Series->Add(series1);
		series2->Color = Color::Red;
		series2->BorderWidth = 2;

		series2->IsVisibleInLegend = false;
		series2->IsXValueIndexed = false;

		series2->ChartType = SeriesChartType::Line;
		for (double i = 0; i < 124; i++) {
			series1->Points->AddXY(i, 10);
		}

		//Инициализация класса информации о зубцах значениями из DataForm
		WavesData w(InitWavesFromFile("WavesData.txt"));
	}

	private: System::Void Conclusion_Click(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 DataForm^ form2 = gcnew DataForm();
				 form2->ShowDialog();
				 
				 if (form2->DialogResult == ::DialogResult::OK)
					 form2->Close();	
			 }

	private: System::Void tableLayoutPanel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}

};
};
	

