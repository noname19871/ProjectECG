#pragma once

namespace ProjectECG {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для DataForm
	/// </summary>
	public ref class DataForm : public System::Windows::Forms::Form
	{
	public:
		DataForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~DataForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  DataTable;
	private: System::Windows::Forms::TextBox^  textBox16;
	private: System::Windows::Forms::TextBox^  textBox13;
	private: System::Windows::Forms::TextBox^  textBox11;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::Label^  LengthOf;
	private: System::Windows::Forms::Label^  StartOf;
	private: System::Windows::Forms::Label^  P;
	private: System::Windows::Forms::Label^  R;
	private: System::Windows::Forms::Label^  U;
	private: System::Windows::Forms::Label^  T;
	private: System::Windows::Forms::Label^  S;
	private: System::Windows::Forms::Label^  HeightOf;
	private: System::Windows::Forms::Label^  Q;
	private: System::Windows::Forms::Label^  Title;

	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::TextBox^  textBox12;
	private: System::Windows::Forms::TextBox^  textBox14;
	private: System::Windows::Forms::TextBox^  textBox15;
	private: System::Windows::Forms::TextBox^  textBox17;
	private: System::Windows::Forms::TextBox^  textBox18;
	private: System::Windows::Forms::Button^  ReadyButton;




	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->DataTable = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->LengthOf = (gcnew System::Windows::Forms::Label());
			this->StartOf = (gcnew System::Windows::Forms::Label());
			this->P = (gcnew System::Windows::Forms::Label());
			this->R = (gcnew System::Windows::Forms::Label());
			this->U = (gcnew System::Windows::Forms::Label());
			this->T = (gcnew System::Windows::Forms::Label());
			this->S = (gcnew System::Windows::Forms::Label());
			this->HeightOf = (gcnew System::Windows::Forms::Label());
			this->Q = (gcnew System::Windows::Forms::Label());
			this->Title = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->textBox17 = (gcnew System::Windows::Forms::TextBox());
			this->textBox18 = (gcnew System::Windows::Forms::TextBox());
			this->ReadyButton = (gcnew System::Windows::Forms::Button());
			this->DataTable->SuspendLayout();
			this->SuspendLayout();
			// 
			// DataTable
			// 
			this->DataTable->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DataTable->AutoSize = true;
			this->DataTable->ColumnCount = 7;
			this->DataTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 125)));
			this->DataTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 150)));
			this->DataTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 150)));
			this->DataTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 150)));
			this->DataTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 150)));
			this->DataTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 150)));
			this->DataTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 150)));
			this->DataTable->Controls->Add(this->LengthOf, 0, 3);
			this->DataTable->Controls->Add(this->StartOf, 0, 4);
			this->DataTable->Controls->Add(this->P, 1, 1);
			this->DataTable->Controls->Add(this->R, 3, 1);
			this->DataTable->Controls->Add(this->U, 6, 1);
			this->DataTable->Controls->Add(this->T, 5, 1);
			this->DataTable->Controls->Add(this->S, 4, 1);
			this->DataTable->Controls->Add(this->HeightOf, 0, 2);
			this->DataTable->Controls->Add(this->Q, 2, 1);
			this->DataTable->Controls->Add(this->Title, 0, 0);
			this->DataTable->Controls->Add(this->textBox1, 1, 2);
			this->DataTable->Controls->Add(this->textBox2, 2, 2);
			this->DataTable->Controls->Add(this->textBox3, 3, 2);
			this->DataTable->Controls->Add(this->textBox4, 4, 2);
			this->DataTable->Controls->Add(this->textBox5, 5, 2);
			this->DataTable->Controls->Add(this->textBox6, 6, 2);
			this->DataTable->Controls->Add(this->textBox7, 1, 3);
			this->DataTable->Controls->Add(this->textBox8, 2, 3);
			this->DataTable->Controls->Add(this->textBox9, 3, 3);
			this->DataTable->Controls->Add(this->textBox10, 4, 3);
			this->DataTable->Controls->Add(this->textBox11, 5, 3);
			this->DataTable->Controls->Add(this->textBox12, 6, 3);
			this->DataTable->Controls->Add(this->textBox13, 1, 4);
			this->DataTable->Controls->Add(this->textBox14, 2, 4);
			this->DataTable->Controls->Add(this->textBox15, 3, 4);
			this->DataTable->Controls->Add(this->textBox16, 4, 4);
			this->DataTable->Controls->Add(this->textBox17, 5, 4);
			this->DataTable->Controls->Add(this->textBox18, 6, 4);
			this->DataTable->Location = System::Drawing::Point(12, 54);
			this->DataTable->Name = L"DataTable";
			this->DataTable->RowCount = 5;
			this->DataTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->DataTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 50)));
			this->DataTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 50)));
			this->DataTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 50)));
			this->DataTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 50)));
			this->DataTable->Size = System::Drawing::Size(1025, 237);
			this->DataTable->TabIndex = 32;
			// 
			// LengthOf
			// 
			this->LengthOf->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->LengthOf->AutoSize = true;
			this->LengthOf->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->LengthOf->Location = System::Drawing::Point(3, 145);
			this->LengthOf->Name = L"LengthOf";
			this->LengthOf->Size = System::Drawing::Size(58, 20);
			this->LengthOf->TabIndex = 23;
			this->LengthOf->Text = L"Длина";
			// 
			// StartOf
			// 
			this->StartOf->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->StartOf->AutoSize = true;
			this->StartOf->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->StartOf->Location = System::Drawing::Point(3, 198);
			this->StartOf->Name = L"StartOf";
			this->StartOf->Size = System::Drawing::Size(67, 20);
			this->StartOf->TabIndex = 32;
			this->StartOf->Text = L"Начало";
			// 
			// P
			// 
			this->P->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->P->AutoSize = true;
			this->P->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->P->Location = System::Drawing::Point(190, 45);
			this->P->Name = L"P";
			this->P->Size = System::Drawing::Size(19, 20);
			this->P->TabIndex = 25;
			this->P->Text = L"P";
			// 
			// R
			// 
			this->R->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->R->AutoSize = true;
			this->R->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->R->Location = System::Drawing::Point(489, 45);
			this->R->Name = L"R";
			this->R->Size = System::Drawing::Size(21, 20);
			this->R->TabIndex = 27;
			this->R->Text = L"R";
			// 
			// U
			// 
			this->U->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->U->AutoSize = true;
			this->U->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->U->Location = System::Drawing::Point(939, 45);
			this->U->Name = L"U";
			this->U->Size = System::Drawing::Size(21, 20);
			this->U->TabIndex = 30;
			this->U->Text = L"U";
			// 
			// T
			// 
			this->T->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->T->AutoSize = true;
			this->T->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->T->Location = System::Drawing::Point(791, 45);
			this->T->Name = L"T";
			this->T->Size = System::Drawing::Size(18, 20);
			this->T->TabIndex = 29;
			this->T->Text = L"T";
			// 
			// S
			// 
			this->S->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->S->AutoSize = true;
			this->S->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->S->Location = System::Drawing::Point(640, 45);
			this->S->Name = L"S";
			this->S->Size = System::Drawing::Size(20, 20);
			this->S->TabIndex = 28;
			this->S->Text = L"S";
			// 
			// HeightOf
			// 
			this->HeightOf->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->HeightOf->AutoSize = true;
			this->HeightOf->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->HeightOf->Location = System::Drawing::Point(3, 95);
			this->HeightOf->Name = L"HeightOf";
			this->HeightOf->Size = System::Drawing::Size(66, 20);
			this->HeightOf->TabIndex = 22;
			this->HeightOf->Text = L"Высота";
			// 
			// Q
			// 
			this->Q->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Q->AutoSize = true;
			this->Q->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->Q->Location = System::Drawing::Point(339, 45);
			this->Q->Name = L"Q";
			this->Q->Size = System::Drawing::Size(21, 20);
			this->Q->TabIndex = 26;
			this->Q->Text = L"Q";
			// 
			// Title
			// 
			this->Title->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->Title->Location = System::Drawing::Point(3, 5);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(106, 20);
			this->Title->TabIndex = 32;
			this->Title->Text = L"II отведение";
			// 
			// textBox1
			// 
			this->textBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox1->Location = System::Drawing::Point(150, 92);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 26);
			this->textBox1->TabIndex = 33;
			// 
			// textBox2
			// 
			this->textBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox2->Location = System::Drawing::Point(300, 92);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 26);
			this->textBox2->TabIndex = 34;
			// 
			// textBox3
			// 
			this->textBox3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox3->Location = System::Drawing::Point(450, 92);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 26);
			this->textBox3->TabIndex = 35;
			// 
			// textBox4
			// 
			this->textBox4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox4->Location = System::Drawing::Point(600, 92);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 26);
			this->textBox4->TabIndex = 36;
			// 
			// textBox5
			// 
			this->textBox5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox5->Location = System::Drawing::Point(750, 92);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 26);
			this->textBox5->TabIndex = 37;
			// 
			// textBox6
			// 
			this->textBox6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox6->Location = System::Drawing::Point(900, 92);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 26);
			this->textBox6->TabIndex = 38;
			// 
			// textBox7
			// 
			this->textBox7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox7->Location = System::Drawing::Point(150, 142);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(100, 26);
			this->textBox7->TabIndex = 36;
			// 
			// textBox8
			// 
			this->textBox8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox8->Location = System::Drawing::Point(300, 142);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(100, 26);
			this->textBox8->TabIndex = 36;
			// 
			// textBox9
			// 
			this->textBox9->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox9->Location = System::Drawing::Point(450, 142);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(100, 26);
			this->textBox9->TabIndex = 39;
			// 
			// textBox10
			// 
			this->textBox10->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox10->Location = System::Drawing::Point(600, 142);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(100, 26);
			this->textBox10->TabIndex = 40;
			// 
			// textBox11
			// 
			this->textBox11->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox11->Location = System::Drawing::Point(750, 142);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(100, 26);
			this->textBox11->TabIndex = 36;
			// 
			// textBox12
			// 
			this->textBox12->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox12->Location = System::Drawing::Point(900, 142);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(100, 26);
			this->textBox12->TabIndex = 41;
			// 
			// textBox13
			// 
			this->textBox13->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox13->Location = System::Drawing::Point(150, 195);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(100, 26);
			this->textBox13->TabIndex = 36;
			// 
			// textBox14
			// 
			this->textBox14->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox14->Location = System::Drawing::Point(300, 195);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(100, 26);
			this->textBox14->TabIndex = 42;
			// 
			// textBox15
			// 
			this->textBox15->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox15->Location = System::Drawing::Point(450, 195);
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(100, 26);
			this->textBox15->TabIndex = 43;
			// 
			// textBox16
			// 
			this->textBox16->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox16->Location = System::Drawing::Point(600, 195);
			this->textBox16->Name = L"textBox16";
			this->textBox16->Size = System::Drawing::Size(100, 26);
			this->textBox16->TabIndex = 36;
			// 
			// textBox17
			// 
			this->textBox17->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox17->Location = System::Drawing::Point(750, 195);
			this->textBox17->Name = L"textBox17";
			this->textBox17->Size = System::Drawing::Size(100, 26);
			this->textBox17->TabIndex = 44;
			// 
			// textBox18
			// 
			this->textBox18->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox18->Location = System::Drawing::Point(900, 195);
			this->textBox18->Name = L"textBox18";
			this->textBox18->Size = System::Drawing::Size(100, 26);
			this->textBox18->TabIndex = 45;
			// 
			// ReadyButton
			// 
			this->ReadyButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ReadyButton->AutoSize = true;
			this->ReadyButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->ReadyButton->Location = System::Drawing::Point(912, 314);
			this->ReadyButton->Name = L"ReadyButton";
			this->ReadyButton->Size = System::Drawing::Size(100, 47);
			this->ReadyButton->TabIndex = 33;
			this->ReadyButton->Text = L"Готово";
			this->ReadyButton->UseVisualStyleBackColor = true;
			this->ReadyButton->Click += gcnew System::EventHandler(this, &DataForm::ReadyButton_Click);
			// 
			// DataForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->AutoSize = true;
			this->CausesValidation = false;
			this->ClientSize = System::Drawing::Size(1134, 459);
			this->Controls->Add(this->ReadyButton);
			this->Controls->Add(this->DataTable);
			this->Name = L"DataForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"DataForm";
			this->Load += gcnew System::EventHandler(this, &DataForm::DataForm_Load);
			this->DataTable->ResumeLayout(false);
			this->DataTable->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();
			
		}
#pragma endregion
	private: System::Void DataForm_Load(System::Object^  sender, System::EventArgs^  e) {

	}

	private: System::Void ReadyButton_Click(System::Object^  sender, System::EventArgs^  e) {
		SaveWavesToFile(ParseDatasIntoDoubleVector(this->DataTable));
		this->DialogResult = ::DialogResult::OK;
	}

	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	}


};
}


