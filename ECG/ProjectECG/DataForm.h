#pragma once

#include <iostream>
#include <vector>

#include "InterfaceFuncs.h"
#include "HelpForm.h"

namespace ProjectECG {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	public ref class DataForm : public System::Windows::Forms::Form
	{
	public:
		DataForm(void)
		{
			InitializeComponent();
		}

	protected:
		~DataForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^  Title;
	private: System::Windows::Forms::Label^  HeightOf;
	private: System::Windows::Forms::Label^  StartOf;
	private: System::Windows::Forms::Label^  P;
	private: System::Windows::Forms::Label^  Q;
	private: System::Windows::Forms::Label^  R;
	private: System::Windows::Forms::Label^  S;
	private: System::Windows::Forms::Label^  T;
	private: System::Windows::Forms::Label^  U;

	private: System::Windows::Forms::Label^  Interval2;
	private: System::Windows::Forms::Label^  StartPos;
	private: System::Windows::Forms::Label^  Interval1;

	private: System::Windows::Forms::Button^  ReadyButton;
	private: System::Windows::Forms::Button^  NextFormButton;
	private: System::Windows::Forms::Button^  HelpButton;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel;
	private: System::Windows::Forms::TableLayoutPanel^  IntervalsPanel;
	private: System::Windows::Forms::TableLayoutPanel^  HeightsPanel;
	private: System::Windows::Forms::TableLayoutPanel^  LengthsPanel;
	private: System::Windows::Forms::TableLayoutPanel^  PosesPanel;

	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::TextBox^  textBox11;
	private: System::Windows::Forms::TextBox^  textBox12;
	private: System::Windows::Forms::TextBox^  textBox13;
	private: System::Windows::Forms::TextBox^  textBox14;
	private: System::Windows::Forms::TextBox^  textBox15;
	private: System::Windows::Forms::TextBox^  textBox16;
	private: System::Windows::Forms::TextBox^  textBox17;
	private: System::Windows::Forms::TextBox^  textBox18;
	private: System::Windows::Forms::TextBox^  textBox19;
	private: System::Windows::Forms::TextBox^  textBox20;

	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::ComboBox^  comboBox2;


	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->StartOf = (gcnew System::Windows::Forms::Label());
			this->HeightOf = (gcnew System::Windows::Forms::Label());
			this->Title = (gcnew System::Windows::Forms::Label());
			this->Interval1 = (gcnew System::Windows::Forms::Label());
			this->Interval2 = (gcnew System::Windows::Forms::Label());
			this->StartPos = (gcnew System::Windows::Forms::Label());
			this->P = (gcnew System::Windows::Forms::Label());
			this->Q = (gcnew System::Windows::Forms::Label());
			this->R = (gcnew System::Windows::Forms::Label());
			this->T = (gcnew System::Windows::Forms::Label());
			this->S = (gcnew System::Windows::Forms::Label());
			this->U = (gcnew System::Windows::Forms::Label());
			this->ReadyButton = (gcnew System::Windows::Forms::Button());
			this->NextFormButton = (gcnew System::Windows::Forms::Button());
			this->HelpButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->HeightsPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->LengthsPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->PosesPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->textBox17 = (gcnew System::Windows::Forms::TextBox());
			this->textBox18 = (gcnew System::Windows::Forms::TextBox());
			this->IntervalsPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->textBox19 = (gcnew System::Windows::Forms::TextBox());
			this->textBox20 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->tableLayoutPanel->SuspendLayout();
			this->HeightsPanel->SuspendLayout();
			this->LengthsPanel->SuspendLayout();
			this->PosesPanel->SuspendLayout();
			this->IntervalsPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// StartOf
			// 
			this->StartOf->Location = System::Drawing::Point(0, 0);
			this->StartOf->Name = L"StartOf";
			this->StartOf->Size = System::Drawing::Size(100, 23);
			this->StartOf->TabIndex = 53;
			// 
			// HeightOf
			// 
			this->HeightOf->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->HeightOf->AutoSize = true;
			this->HeightOf->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->HeightOf->Location = System::Drawing::Point(85, 227);
			this->HeightOf->Name = L"HeightOf";
			this->HeightOf->Size = System::Drawing::Size(83, 29);
			this->HeightOf->TabIndex = 22;
			this->HeightOf->Text = L"Height";
			// 
			// Title
			// 
			this->Title->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->Title->Location = System::Drawing::Point(3, 3);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(122, 58);
			this->Title->TabIndex = 32;
			this->Title->Text = L"II standart diversion";
			// 
			// Interval1
			// 
			this->Interval1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->Interval1->AutoSize = true;
			this->Interval1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->Interval1->Location = System::Drawing::Point(3, 7);
			this->Interval1->Name = L"Interval1";
			this->Interval1->Size = System::Drawing::Size(90, 58);
			this->Interval1->TabIndex = 32;
			this->Interval1->Text = L"R1-R2 interval";
			// 
			// Interval2
			// 
			this->Interval2->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->Interval2->AutoSize = true;
			this->Interval2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->Interval2->Location = System::Drawing::Point(445, 7);
			this->Interval2->Name = L"Interval2";
			this->Interval2->Size = System::Drawing::Size(90, 58);
			this->Interval2->TabIndex = 46;
			this->Interval2->Text = L"R2-R3 interval";
			// 
			// StartPos
			// 
			this->StartPos->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->StartPos->AutoSize = true;
			this->StartPos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->StartPos->Location = System::Drawing::Point(85, 412);
			this->StartPos->Name = L"StartPos";
			this->StartPos->Size = System::Drawing::Size(62, 29);
			this->StartPos->TabIndex = 52;
			this->StartPos->Text = L"Start";
			// 
			// P
			// 
			this->P->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->P->AutoSize = true;
			this->P->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->P->Location = System::Drawing::Point(202, 79);
			this->P->Name = L"P";
			this->P->Size = System::Drawing::Size(29, 29);
			this->P->TabIndex = 25;
			this->P->Text = L"P";
			// 
			// Q
			// 
			this->Q->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Q->AutoSize = true;
			this->Q->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->Q->Location = System::Drawing::Point(351, 79);
			this->Q->Name = L"Q";
			this->Q->Size = System::Drawing::Size(32, 29);
			this->Q->TabIndex = 26;
			this->Q->Text = L"Q";
			// 
			// R
			// 
			this->R->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->R->AutoSize = true;
			this->R->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->R->Location = System::Drawing::Point(502, 79);
			this->R->Name = L"R";
			this->R->Size = System::Drawing::Size(30, 29);
			this->R->TabIndex = 27;
			this->R->Text = L"R";
			// 
			// T
			// 
			this->T->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->T->AutoSize = true;
			this->T->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->T->Location = System::Drawing::Point(802, 79);
			this->T->Name = L"T";
			this->T->Size = System::Drawing::Size(29, 29);
			this->T->TabIndex = 29;
			this->T->Text = L"T";
			// 
			// S
			// 
			this->S->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->S->AutoSize = true;
			this->S->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->S->Location = System::Drawing::Point(652, 79);
			this->S->Name = L"S";
			this->S->Size = System::Drawing::Size(29, 29);
			this->S->TabIndex = 28;
			this->S->Text = L"S";
			// 
			// U
			// 
			this->U->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->U->AutoSize = true;
			this->U->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->U->Location = System::Drawing::Point(952, 79);
			this->U->Name = L"U";
			this->U->Size = System::Drawing::Size(30, 29);
			this->U->TabIndex = 30;
			this->U->Text = L"U";
			// 
			// ReadyButton
			// 
			this->ReadyButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ReadyButton->AutoSize = true;
			this->ReadyButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->ReadyButton->Location = System::Drawing::Point(1379, 645);
			this->ReadyButton->Name = L"ReadyButton";
			this->ReadyButton->Size = System::Drawing::Size(104, 47);
			this->ReadyButton->TabIndex = 33;
			this->ReadyButton->Text = L"OK";
			this->ReadyButton->UseVisualStyleBackColor = true;
			this->ReadyButton->Click += gcnew System::EventHandler(this, &DataForm::ReadyButton_Click);
			// 
			// NextFormButton
			// 
			this->NextFormButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->NextFormButton->AutoSize = true;
			this->NextFormButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->NextFormButton->Location = System::Drawing::Point(14, 645);
			this->NextFormButton->Name = L"NextFormButton";
			this->NextFormButton->Size = System::Drawing::Size(374, 47);
			this->NextFormButton->TabIndex = 34;
			this->NextFormButton->Text = L"Enter next diversion";
			this->NextFormButton->UseVisualStyleBackColor = true;
			this->NextFormButton->Click += gcnew System::EventHandler(this, &DataForm::NextFormButton_Click);
			// 
			// HelpButton
			// 
			this->HelpButton->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->HelpButton->AutoSize = true;
			this->HelpButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->HelpButton->Location = System::Drawing::Point(1210, 645);
			this->HelpButton->Name = L"HelpButton";
			this->HelpButton->Size = System::Drawing::Size(163, 47);
			this->HelpButton->TabIndex = 34;
			this->HelpButton->Text = L"Help";
			this->HelpButton->UseVisualStyleBackColor = true;
			this->HelpButton->Click += gcnew System::EventHandler(this, &DataForm::HelpButton_Click);
			// 
			// tableLayoutPanel
			// 
			this->tableLayoutPanel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tableLayoutPanel->AutoSize = true;
			this->tableLayoutPanel->ColumnCount = 7;
			this->tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				142)));
			this->tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				150)));
			this->tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				150)));
			this->tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				150)));
			this->tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				150)));
			this->tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				150)));
			this->tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				150)));
			this->tableLayoutPanel->Controls->Add(this->P, 1, 1);
			this->tableLayoutPanel->Controls->Add(this->R, 3, 1);
			this->tableLayoutPanel->Controls->Add(this->U, 6, 1);
			this->tableLayoutPanel->Controls->Add(this->T, 5, 1);
			this->tableLayoutPanel->Controls->Add(this->S, 4, 1);
			this->tableLayoutPanel->Controls->Add(this->Q, 2, 1);
			this->tableLayoutPanel->Controls->Add(this->Title, 0, 0);
			this->tableLayoutPanel->Location = System::Drawing::Point(59, 76);
			this->tableLayoutPanel->Name = L"tableLayoutPanel";
			this->tableLayoutPanel->RowCount = 2;
			this->tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 65)));
			this->tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 15)));
			this->tableLayoutPanel->Size = System::Drawing::Size(1042, 122);
			this->tableLayoutPanel->TabIndex = 32;
			// 
			// HeightsPanel
			// 
			this->HeightsPanel->ColumnCount = 6;
			this->HeightsPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.57397F)));
			this->HeightsPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.68521F)));
			this->HeightsPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.68521F)));
			this->HeightsPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.68521F)));
			this->HeightsPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.68521F)));
			this->HeightsPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.68521F)));
			this->HeightsPanel->Controls->Add(this->textBox1, 0, 0);
			this->HeightsPanel->Controls->Add(this->textBox2, 1, 0);
			this->HeightsPanel->Controls->Add(this->textBox3, 2, 0);
			this->HeightsPanel->Controls->Add(this->textBox4, 3, 0);
			this->HeightsPanel->Controls->Add(this->textBox5, 4, 0);
			this->HeightsPanel->Controls->Add(this->textBox6, 5, 0);
			this->HeightsPanel->Location = System::Drawing::Point(199, 204);
			this->HeightsPanel->Name = L"HeightsPanel";
			this->HeightsPanel->RowCount = 1;
			this->HeightsPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->HeightsPanel->Size = System::Drawing::Size(899, 82);
			this->HeightsPanel->TabIndex = 49;
			// 
			// textBox1
			// 
			this->textBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox1->Location = System::Drawing::Point(24, 23);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 35);
			this->textBox1->TabIndex = 33;
			// 
			// textBox2
			// 
			this->textBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox2->Location = System::Drawing::Point(172, 23);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 35);
			this->textBox2->TabIndex = 34;
			// 
			// textBox3
			// 
			this->textBox3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox3->Location = System::Drawing::Point(321, 23);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 35);
			this->textBox3->TabIndex = 35;
			// 
			// textBox4
			// 
			this->textBox4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox4->Location = System::Drawing::Point(470, 23);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 35);
			this->textBox4->TabIndex = 36;
			// 
			// textBox5
			// 
			this->textBox5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox5->Location = System::Drawing::Point(619, 23);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 35);
			this->textBox5->TabIndex = 37;
			// 
			// textBox6
			// 
			this->textBox6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox6->Location = System::Drawing::Point(771, 23);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 35);
			this->textBox6->TabIndex = 38;
			// 
			// LengthsPanel
			// 
			this->LengthsPanel->ColumnCount = 6;
			this->LengthsPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.57397F)));
			this->LengthsPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.68521F)));
			this->LengthsPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.68521F)));
			this->LengthsPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.68521F)));
			this->LengthsPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.68521F)));
			this->LengthsPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.68521F)));
			this->LengthsPanel->Controls->Add(this->textBox7, 0, 0);
			this->LengthsPanel->Controls->Add(this->textBox8, 1, 0);
			this->LengthsPanel->Controls->Add(this->textBox9, 2, 0);
			this->LengthsPanel->Controls->Add(this->textBox10, 3, 0);
			this->LengthsPanel->Controls->Add(this->textBox11, 4, 0);
			this->LengthsPanel->Controls->Add(this->textBox12, 5, 0);
			this->LengthsPanel->Location = System::Drawing::Point(199, 292);
			this->LengthsPanel->Name = L"LengthsPanel";
			this->LengthsPanel->RowCount = 1;
			this->LengthsPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->LengthsPanel->Size = System::Drawing::Size(899, 82);
			this->LengthsPanel->TabIndex = 50;
			// 
			// textBox7
			// 
			this->textBox7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox7->Location = System::Drawing::Point(24, 23);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(100, 35);
			this->textBox7->TabIndex = 33;
			// 
			// textBox8
			// 
			this->textBox8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox8->Location = System::Drawing::Point(172, 23);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(100, 35);
			this->textBox8->TabIndex = 34;
			// 
			// textBox9
			// 
			this->textBox9->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox9->Location = System::Drawing::Point(321, 23);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(100, 35);
			this->textBox9->TabIndex = 35;
			// 
			// textBox10
			// 
			this->textBox10->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox10->Location = System::Drawing::Point(470, 23);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(100, 35);
			this->textBox10->TabIndex = 36;
			// 
			// textBox11
			// 
			this->textBox11->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox11->Location = System::Drawing::Point(619, 23);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(100, 35);
			this->textBox11->TabIndex = 37;
			// 
			// textBox12
			// 
			this->textBox12->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox12->Location = System::Drawing::Point(771, 23);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(100, 35);
			this->textBox12->TabIndex = 38;
			// 
			// PosesPanel
			// 
			this->PosesPanel->ColumnCount = 6;
			this->PosesPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.57397F)));
			this->PosesPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.68521F)));
			this->PosesPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.68521F)));
			this->PosesPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.68521F)));
			this->PosesPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.68521F)));
			this->PosesPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.68521F)));
			this->PosesPanel->Controls->Add(this->textBox13, 0, 0);
			this->PosesPanel->Controls->Add(this->textBox14, 1, 0);
			this->PosesPanel->Controls->Add(this->textBox15, 2, 0);
			this->PosesPanel->Controls->Add(this->textBox16, 3, 0);
			this->PosesPanel->Controls->Add(this->textBox17, 4, 0);
			this->PosesPanel->Controls->Add(this->textBox18, 5, 0);
			this->PosesPanel->Location = System::Drawing::Point(202, 380);
			this->PosesPanel->Name = L"PosesPanel";
			this->PosesPanel->RowCount = 1;
			this->PosesPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->PosesPanel->Size = System::Drawing::Size(899, 82);
			this->PosesPanel->TabIndex = 51;
			// 
			// textBox13
			// 
			this->textBox13->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox13->Location = System::Drawing::Point(24, 23);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(100, 35);
			this->textBox13->TabIndex = 33;
			// 
			// textBox14
			// 
			this->textBox14->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox14->Location = System::Drawing::Point(172, 23);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(100, 35);
			this->textBox14->TabIndex = 34;
			// 
			// textBox15
			// 
			this->textBox15->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox15->Location = System::Drawing::Point(321, 23);
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(100, 35);
			this->textBox15->TabIndex = 35;
			// 
			// textBox16
			// 
			this->textBox16->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox16->Location = System::Drawing::Point(470, 23);
			this->textBox16->Name = L"textBox16";
			this->textBox16->Size = System::Drawing::Size(100, 35);
			this->textBox16->TabIndex = 36;
			// 
			// textBox17
			// 
			this->textBox17->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox17->Location = System::Drawing::Point(619, 23);
			this->textBox17->Name = L"textBox17";
			this->textBox17->Size = System::Drawing::Size(100, 35);
			this->textBox17->TabIndex = 37;
			// 
			// textBox18
			// 
			this->textBox18->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox18->Location = System::Drawing::Point(771, 23);
			this->textBox18->Name = L"textBox18";
			this->textBox18->Size = System::Drawing::Size(100, 35);
			this->textBox18->TabIndex = 45;
			// 
			// IntervalsPanel
			// 
			this->IntervalsPanel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->IntervalsPanel->AutoSize = true;
			this->IntervalsPanel->ColumnCount = 5;
			this->IntervalsPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				142)));
			this->IntervalsPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				300)));
			this->IntervalsPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				150)));
			this->IntervalsPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				300)));
			this->IntervalsPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				12)));
			this->IntervalsPanel->Controls->Add(this->Interval1, 0, 0);
			this->IntervalsPanel->Controls->Add(this->textBox19, 1, 0);
			this->IntervalsPanel->Controls->Add(this->Interval2, 2, 0);
			this->IntervalsPanel->Controls->Add(this->textBox20, 3, 0);
			this->IntervalsPanel->Controls->Add(this->comboBox1, 4, 0);
			this->IntervalsPanel->Location = System::Drawing::Point(59, 468);
			this->IntervalsPanel->Name = L"IntervalsPanel";
			this->IntervalsPanel->RowCount = 1;
			this->IntervalsPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 50)));
			this->IntervalsPanel->Size = System::Drawing::Size(1039, 73);
			this->IntervalsPanel->TabIndex = 48;
			// 
			// textBox19
			// 
			this->textBox19->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox19->Location = System::Drawing::Point(242, 19);
			this->textBox19->Name = L"textBox19";
			this->textBox19->Size = System::Drawing::Size(100, 35);
			this->textBox19->TabIndex = 44;
			// 
			// textBox20
			// 
			this->textBox20->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox20->Location = System::Drawing::Point(692, 19);
			this->textBox20->Name = L"textBox20";
			this->textBox20->Size = System::Drawing::Size(100, 35);
			this->textBox20->TabIndex = 45;
			// 
			// comboBox1
			// 
			this->comboBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"25", L"50" });
			this->comboBox1->Location = System::Drawing::Point(915, 18);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(100, 37);
			this->comboBox1->TabIndex = 49;
			// 
			// comboBox2
			// 
			this->comboBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"1 St.", L"2 St.", L"3 St.", L"aVL", L"aVR", L"aVF",
					L"V1", L"V2", L"V3", L"V4", L"V5", L"V6"
					
			});
			this->comboBox2->Location = System::Drawing::Point(569, 529);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(100, 28);
			this->comboBox2->TabIndex = 53;
			// 
			// DataForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->AutoSize = true;
			this->CausesValidation = false;
			this->ClientSize = System::Drawing::Size(1492, 704);
			this->Controls->Add(this->NextFormButton);
			this->Controls->Add(this->HelpButton);
			this->Controls->Add(this->StartPos);
			this->Controls->Add(this->PosesPanel);
			this->Controls->Add(this->LengthsPanel);
			this->Controls->Add(this->HeightsPanel);
			this->Controls->Add(this->StartOf);
			this->Controls->Add(this->IntervalsPanel);
			this->Controls->Add(this->ReadyButton);
			this->Controls->Add(this->HeightOf);
			this->Controls->Add(this->tableLayoutPanel);
			this->Controls->Add(this->comboBox2);
			this->Name = L"DataForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"DataForm";
			this->Load += gcnew System::EventHandler(this, &DataForm::DataForm_Load);
			this->tableLayoutPanel->ResumeLayout(false);
			this->tableLayoutPanel->PerformLayout();
			this->HeightsPanel->ResumeLayout(false);
			this->HeightsPanel->PerformLayout();
			this->LengthsPanel->ResumeLayout(false);
			this->LengthsPanel->PerformLayout();
			this->PosesPanel->ResumeLayout(false);
			this->PosesPanel->PerformLayout();
			this->IntervalsPanel->ResumeLayout(false);
			this->IntervalsPanel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void DataForm_Load(System::Object^  sender, System::EventArgs^  e) {
		this->comboBox1->SelectedItem = L"50";
		this->comboBox2->SelectedItem = L"2 St."; //Should be here, because it bugs and disappers after first compile
		PrepareFile("data.csv");
	}
	

	private: System::Void ReadyButton_Click(System::Object^  sender, System::EventArgs^  e) {
		std::string diversName;
		if (this->Title->Text->Contains("1 St.")) diversName = "1 St.";
		else if (this->Title->Text->Contains("2 St.")) diversName = "2 St.";
		else if (this->Title->Text->Contains("3 St.")) diversName = "3 St.";
		else if (this->Title->Text->Contains("aVF")) diversName = "aVF";
		else if (this->Title->Text->Contains("aVL")) diversName = "aVL";
		else if (this->Title->Text->Contains("aVR")) diversName = "aVR";
		else if (this->Title->Text->Contains("V1")) diversName = "V1";
		else if (this->Title->Text->Contains("V2")) diversName = "V2";
		else if (this->Title->Text->Contains("V3")) diversName = "V3";
		else if (this->Title->Text->Contains("V4")) diversName = "V4";
		else if (this->Title->Text->Contains("V5")) diversName = "V5";
		else  diversName = "V6";
		SaveInFile("data.csv", diversName, ParseDatasIntoDoubleVector(this->HeightsPanel, 5), "Height");
		SaveInFile("data.csv", diversName, ParseDatasIntoDoubleVector(this->LengthsPanel, 5), "Length");
		SaveInFile("data.csv", diversName, ParseDatasIntoDoubleVector(this->PosesPanel, 5), "Poses");
				//ofstream f("data.csv");
					//auto vv = ParseDatasIntoDoubleVector(this->PosesPanel, 3);
			
			
					//f << "Intervals" << ";" <<vv[0] << ";" << vv[1] << ";" << "Speed" << ";" << vv[2] << ";" << endl;
					//f.close();
			
			
			this->Close();
	}

	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	}


	System::Void NextFormButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		std::string diversName;
		if (this->Title->Text->Contains("1 St.")) diversName = "1 St.";
		else if (this->Title->Text->Contains("2 St.")) diversName = "2 St.";
		else if (this->Title->Text->Contains("3 St.")) diversName = "3 St.";
		else if (this->Title->Text->Contains("aVF")) diversName = "aVF";
		else if (this->Title->Text->Contains("aVL")) diversName = "aVL";
		else if (this->Title->Text->Contains("aVR")) diversName = "aVR";
		else if (this->Title->Text->Contains("V1")) diversName = "V1";
		else if (this->Title->Text->Contains("V2")) diversName = "V2";
		else if (this->Title->Text->Contains("V3")) diversName = "V3";
		else if (this->Title->Text->Contains("V4")) diversName = "V4";
		else if (this->Title->Text->Contains("V5")) diversName = "V5";
		else  diversName = "V6";
		SaveInFile("data.csv", diversName, ParseDatasIntoDoubleVector(this->HeightsPanel, 5), "Height");
		SaveInFile("data.csv", diversName, ParseDatasIntoDoubleVector(this->LengthsPanel, 5), "Length");
		SaveInFile("data.csv", diversName, ParseDatasIntoDoubleVector(this->PosesPanel, 5), "Poses");
		
		this->IntervalsPanel->Visible = false;
		this->Title->Text = this->comboBox2->Text;
		if (this->comboBox2->Text->Contains("2 St."))
			 {
			this->IntervalsPanel->Visible = true;
			this->IntervalsPanel->Controls[1]->Text = "";
			this->IntervalsPanel->Controls[3]->Text = "";
			}
		ResetTextboxesInDataTable(this->HeightsPanel);
		ResetTextboxesInDataTable(this->LengthsPanel);
		ResetTextboxesInDataTable(this->PosesPanel);
		this->Refresh();
	}

	private: System::Void HelpButton_Click(System::Object^ sender, System::EventArgs^ e) {
		HelpForm^ form = gcnew HelpForm();
		form->Information->Text = System::IO::File::ReadAllText("helpdataform.txt", System::Text::Encoding::Default);
		form->ShowDialog();
	}

	private: System::Void textBox14_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		this->textBox15->Text = this->textBox14->Text;
		this->textBox16->Text = this->textBox14->Text;
		}

	private: System::Void textBox15_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		this->textBox14->Text = this->textBox15->Text;
		this->textBox16->Text = this->textBox15->Text;
		}

	private: System::Void textBox16_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		this->textBox15->Text = this->textBox16->Text;
		this->textBox14->Text = this->textBox16->Text;
		}

};

	
}


