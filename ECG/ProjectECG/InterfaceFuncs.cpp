#include <iostream>
#include <locale>
#include <string>
#include <fstream>

#include "InterfaceFuncs.h"
#include "AnalysisFuncs.h"



using namespace System;
using namespace System::Windows::Forms;
using namespace std;

// Parse TextBoxes in TLP and add them to vector<double>
// size - count of TextBoxes
std::vector<double> ParseDatasIntoDoubleVector(TableLayoutPanel^ p, int size)
{

	std::vector<double> res(size);
	if (p->Controls->Count == 6)
	{
		for (int i = 0; i < 6; i++)
		{
			String^ tmp = p->Controls[i]->Text == "" ? "0" : p->Controls[i]->Text;
			if (p->Controls[i]->Text->Contains("."))
				tmp = p->Controls[i]->Text->Replace(".", ",");
			res[i] = System::Convert::ToDouble(tmp);
		}
	}
	else
	{
		String^ tmp = p->Controls[1]->Text;

		if (p->Controls[1]->Text->Contains("."))
			tmp = p->Controls[1]->Text->Replace(".", ",");
		res[0] = System::Convert::ToDouble(p->Controls[1]->Text == "" ? "0" : tmp);

		tmp = p->Controls[3]->Text;
		if (p->Controls[3]->Text->Contains("."))
			tmp = p->Controls[3]->Text->Replace(".", ",");
		res[1] = System::Convert::ToDouble(p->Controls[3]->Text == "" ? "0" : tmp);
	}

	return res;
}

//It resets textboxes in TableLayoutPanel^ p to "";
void ResetTextboxesInDataTable(System::Windows::Forms::TableLayoutPanel^ p)
{
	for (int i = 0; i < 6; i++)
	{
		if (p->Controls[i]->Text != "") p->Controls[i]->Text = "";
	}
}

void PrepareAssignation(string filename)
{
	ofstream f(filename, ios::app);
	f << "P tooth";
	f << ";";
	f << "Q tooth";
	f << ";";
	f << "R tooth";
	f << ";";
	f << "S tooth";
	f << ";";
	f << "T tooth";
	f << ";";
	f << "U tooth";
	f << '\n';
	f.close();
}

//It saves values from vector to csv file 
void SaveWavesToFile(vector<double> v, string filename, string vector_name)
{
	ofstream f(filename, ios::app);
	f << vector_name;
	f << ";";
	for (int i = 0; i < v.size(); i++)
		f << v[i] << ";";
	f << '\n';
	f.close();
}

//It draws grid for ECG graphic
void DrawGrid(System::Drawing::Graphics^ g, int width, int height)
{
	System::Drawing::Pen^ myPen =
		gcnew System::Drawing::Pen(System::Drawing::Color::Black);
	for (int i = 0; i < width; i += 20)
		g->DrawLine(myPen, System::Drawing::Point(i, 0), System::Drawing::Point(i, height));

	for (int i = 0; i < height; i += 20)
		g->DrawLine(myPen, System::Drawing::Point(0, i), System::Drawing::Point(width, i));
	delete myPen;
}

//It draws control volt (first Rectangle) for ECG graphic
void DrawControlVolt(System::Drawing::Graphics^ g, int height, double p_pose)
{
	System::Drawing::Pen^ myPen =
		gcnew System::Drawing::Pen(System::Drawing::Color::Red, 3);

	g->DrawLine(myPen, System::Drawing::Point(0,  height / 2),      System::Drawing::Point(20,          height / 2));
	g->DrawLine(myPen, System::Drawing::Point(20, height / 2),      System::Drawing::Point(20,          height / 2 - 40));
	g->DrawLine(myPen, System::Drawing::Point(20, height / 2 - 40), System::Drawing::Point(40,          height / 2 - 40));
	g->DrawLine(myPen, System::Drawing::Point(40, height / 2 - 40), System::Drawing::Point(40,          height / 2));
	g->DrawLine(myPen, System::Drawing::Point(40, height / 2),      System::Drawing::Point(40 + 20 * p_pose, height / 2));
	delete myPen;
}

//It draws P wave (first arc) for ECG graphic
void DrawP(System::Drawing::Graphics^ g, int height, double p_length, double p_height, double p_pose, double q_pose)
{
	System::Drawing::Pen^ myPen =
		gcnew System::Drawing::Pen(System::Drawing::Color::Red, 3);

	if (p_height != 0)
	{
		g->DrawArc(myPen, System::Drawing::Rectangle(40 + 20 * p_pose, height / 2 - 20 * p_height, 20 * p_length, 40 * p_height), 180, 180);
		g->DrawLine(myPen, System::Drawing::Point(40 + 20 * (p_pose + p_length), height / 2), System::Drawing::Point(40 + 20 * q_pose, height / 2));
	}
	else
		g->DrawLine(myPen, System::Drawing::Point(40 + 20 * p_pose, height / 2), System::Drawing::Point(40 + 20 * q_pose, height / 2));

	delete myPen;
}

//It draws QRS complex (3 waves between P and T) for ECG graphic
void DrawQRS(System::Drawing::Graphics^ g, double height,
	double q_length, double q_height, double q_pose,
	double r_length, double r_height, double r_pose,
	double s_length, double s_heigth, double s_pose,
	double t_pose)
{
	System::Drawing::Pen^ myPen =
		gcnew System::Drawing::Pen(System::Drawing::Color::Red, 3);

	g->DrawLine(myPen, System::Drawing::Point(40 + 20 * q_pose,                                    height / 2),                 System::Drawing::Point(40 + 20 * (q_pose + q_length),                       height / 2 - 20 * q_height));
	g->DrawLine(myPen, System::Drawing::Point(40 + 20 * (q_pose + q_length),                       height / 2 - 20 * q_height), System::Drawing::Point(40 + 20 * (q_pose + q_length + r_length / 2),        height / 2 - 20 * r_height));
	g->DrawLine(myPen, System::Drawing::Point(40 + 20 * (q_pose + q_length + r_length / 2),        height / 2 - 20 * r_height), System::Drawing::Point(40 + 20 * (q_pose + q_length + r_length),            height / 2 - 20 * s_heigth));
	g->DrawLine(myPen, System::Drawing::Point(40 + 20 * (q_pose + q_length + r_length),            height / 2 - 20 * s_heigth), System::Drawing::Point(40 + 20 * (q_pose + q_length + r_length + s_length), height / 2));
	g->DrawLine(myPen, System::Drawing::Point(40 + 20 * (q_pose + q_length + r_length + s_length), height / 2),                 System::Drawing::Point(40 + 20 * t_pose,                                    height / 2));

	delete myPen;
}

//It draws T wave (second arc) for ECG graphic
void DrawT(System::Drawing::Graphics^ g, int height, double t_length, double t_height, double t_pose)
{
	System::Drawing::Pen^ myPen =
		gcnew System::Drawing::Pen(System::Drawing::Color::Red, 3);

	if (t_height != 0)
	{
		g->DrawArc(myPen, System::Drawing::Rectangle(40 + 20 * t_pose, height / 2 - 20 * t_height, 20 * t_length, 40 * t_height), 180, 180);
		g->DrawLine(myPen, System::Drawing::Point(40 + 20 * (t_pose + t_length), height / 2), System::Drawing::Point(420, height / 2));
	}
	else
		g->DrawLine(myPen, System::Drawing::Point(40 + 20 * t_pose , height / 2), System::Drawing::Point(420, height / 2));
	delete myPen;
}

//It draws ECG graphic on PictureBox
void DrawGraphic(System::Drawing::Graphics^ g, int width, int height, const WavesData & w)
{
	DrawP(g, height, w.lengths()[0], w.heights()[0], w.poses()[0], w.poses()[1]);
	DrawQRS(g, height,
			   w.lengths()[1], w.heights()[1], w.poses()[1],
		       w.lengths()[2], w.heights()[2], w.poses()[2], 
		       w.lengths()[3], w.heights()[3], w.poses()[3],
			   w.poses()[4]);
	DrawT(g, height, w.lengths()[4],w.heights()[4],w.poses()[4]);
	DrawControlVolt(g, height, w.poses()[0]);
}