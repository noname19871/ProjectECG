#include <iostream>
#include <locale>
#include <string>
#include <fstream>
#include <vector>

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
	auto ss = p->Name;
	if (!(p->Name->Contains("IntervalsPanel")))
	{
		for (int i = 0; i < 5; i++)
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
	//	res[2] = System::Convert::ToDouble(p->Controls[4]->Text);
	}

	return res;
}

//It prepares data file for 
void PrepareFile(string filename)
{
	ofstream f(filename); 
	vector<string> diversions{ "1 St.", "2 St.", "3 St.", "aVL", "aVF", "aVR", "V1", "V2", "V3", "V4", "V5", "V6" };
	f << "Intervals" << ";" << 1.50 << ";" << 1.50 << ";" << "Speed" << ";" << 50.00 << ";" << endl;
	for (int i = 0; i < 12; i++)
	{
		f << diversions[i] << ";" << "P" << ";" << "Q" << ";" << "R" << ";" << "S" << ";" << "T" << ";" << endl;
		f << "Heights" << ";" << 0.0 << ";" << 0.0 << ";" << 0.0 << ";" << 0.0 << ";" << 0.0 << ";" << endl;
		f << "Lengths" << ";" << 0.0 << ";" << 0.0 << ";" << 0.0 << ";" << 0.0 << ";" << 0.0 << ";" << endl;
		f << "Poses" << ";" << 0.0 << ";" << 0.0 << ";" << 0.0 << ";" << 0.0 << ";" << 0.0 << ";" << endl;
		f << endl;
		f << endl;
	}
	f.close();
}

//It resets textboxes in TableLayoutPanel^ p to "";
void ResetTextboxesInDataTable(System::Windows::Forms::TableLayoutPanel^ p)
{
	for (int i = 0; i < 5; i++)
	{
		if (p->Controls[i]->Text != "") p->Controls[i]->Text = "";
	}
}
//It saves values from vector to csv file 
void SaveWavesToFile(vector<double> v, string filename, string vector_name, int pos )
{
	fstream f(filename);
	f.seekp(pos);
	f << vector_name;
	f << ";";
	for (int i = 0; i < 5; i++)
		f << v[i] << ";";
	f << endl;
	f.seekp(0);
	f.close();
}



//
void SaveInFile(string filename, string diversion_name, vector<double> v, string vector_name)
{
	int pos;
	string tmp;
	fstream f("data.csv");
	while (!f.eof())
	{
		getline(f, tmp);
		pos = f.tellp();
		if (tmp.find(diversion_name) != string::npos)
		{
			if (vector_name == "Length")
			{
				getline(f, tmp);
				pos = f.tellp();
			}
			else if (vector_name == "Poses")
			{
				getline(f, tmp);
				getline(f, tmp);
				pos = f.tellp();
			}
			f.close();
			SaveWavesToFile(v, filename, vector_name, pos);
			return;
		}

	}
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

	if (r_height != 0)
	{
		g->DrawLine(myPen, System::Drawing::Point(40 + 20 * (q_pose + q_length), height / 2 - 20 * q_height), System::Drawing::Point(40 + 20 * (q_pose + q_length + r_length / 2), height / 2 - 20 * r_height));
		g->DrawLine(myPen, System::Drawing::Point(40 + 20 * (q_pose + q_length + r_length / 2), height / 2 - 20 * r_height), System::Drawing::Point(40 + 20 * (q_pose + q_length + r_length), height / 2 - 20 * s_heigth));
	}

	g->DrawLine(myPen, System::Drawing::Point(40 + 20 * (q_pose + q_length + r_length),            height / 2 - 20 * s_heigth), System::Drawing::Point(40 + 20 * (q_pose + q_length + r_length + s_length), height / 2));
	g->DrawLine(myPen, System::Drawing::Point(40 + 20 * (q_pose + q_length + r_length + s_length), height / 2),                 System::Drawing::Point(40 + 20 * t_pose,                                    height / 2));

	delete myPen;
}

//It draws T wave (second arc) for ECG graphic
void DrawT(System::Drawing::Graphics^ g, int height, double t_length, double t_height, double t_pose, double p_pose)
{
	System::Drawing::Pen^ myPen =
		gcnew System::Drawing::Pen(System::Drawing::Color::Red, 3);

	if (t_height != 0)
	{
		g->DrawArc(myPen, System::Drawing::Rectangle(40 + 20 * t_pose, height / 2 - 20 * t_height, 20 * t_length, 40 * t_height), 180, 180);
		g->DrawLine(myPen, System::Drawing::Point(40 + 20 * (t_pose + t_length), height / 2), System::Drawing::Point(40 + 20 * p_pose, height / 2));
	}
	else
		g->DrawLine(myPen, System::Drawing::Point(40 + 20 * t_pose , height / 2), System::Drawing::Point(40 + 20 * p_pose, height / 2));
	delete myPen;
}

//It draws ECG graphic on PictureBox
void DrawGraphic(System::Drawing::Graphics^ g, int width, int height, const WavesData & w)
{
	DrawControlVolt(g, height, w.poses()[0]);

	if (w.empty())
	{
		System::Drawing::Pen^ myPen =
			gcnew System::Drawing::Pen(System::Drawing::Color::Red, 3);
		g->DrawLine(myPen, System::Drawing::Point(40, height / 2), System::Drawing::Point(width, height / 2));
		delete myPen;
		return;
	}

	for (int i = 0; i < 14; i++)
	{
		int interval = (i % 2 == 0) ? w.intervals()[0] : w.intervals()[1];
		DrawP(g, height, w.lengths()[0], w.heights()[0], i * interval + w.poses()[0], i * interval + w.poses()[1]);
		DrawQRS(g, height,
			 w.lengths()[1], w.heights()[1], i * interval + w.poses()[1],
			 w.lengths()[2], w.heights()[2], i * interval + w.poses()[2],
			 w.lengths()[3], w.heights()[3], i * interval + w.poses()[3],
			 i * interval + w.poses()[4]);
		if(interval != 0)
			DrawT(g, height, w.lengths()[4],  w.heights()[4], i * interval + w.poses()[4], (i + 1) * interval + w.poses()[0]);
		else
			DrawT(g, height, w.lengths()[4], w.heights()[4], i * interval + w.poses()[4], w.poses()[4] + w.lengths()[4] + w.poses()[0]);

		if (interval == 0)
		{
			System::Drawing::Pen^ myPen =
				gcnew System::Drawing::Pen(System::Drawing::Color::Red, 3);
			g->DrawLine(myPen, System::Drawing::Point(40 + 20 * (w.poses()[4] + w.lengths()[4]), height / 2), System::Drawing::Point(width, height / 2));
			delete myPen;
			return;
		}
	}
}