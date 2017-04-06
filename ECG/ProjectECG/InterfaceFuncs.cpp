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
	if (p->Name->Contains("ST_Table"))
	{	
		String^ tmp = p->Controls[0]->Text;
		if (p->Controls[0]->Text->Contains("."))
			 tmp = p->Controls[0]->Text->Replace(".", ",");
		res[0] = System::Convert::ToDouble(p->Controls[0]->Text == "" ? "0" : tmp);
		return res;
	}
	if (!(p->Name->Contains("Intervals")))
	{
		for (int i = 0; i < size /*5*/; i++)
		{
			String^ tmp = p->Controls[i]->Text == "" ? "0" : p->Controls[i]->Text;
			if (p->Controls[i]->Text->Contains("."))
				tmp = p->Controls[i]->Text->Replace(".", ",");
			res[i] = System::Convert::ToDouble(tmp);
			int b = res[i];
		}
	}
	else
	{
		String^ tmp = p->Controls[0]->Text;
		if (p->Controls[0]->Text->Contains("."))
			 tmp = p->Controls[0]->Text->Replace(".", ",");
		res[0] = System::Convert::ToDouble(p->Controls[0]->Text == "" ? "0" : tmp);
		tmp = p->Controls[1]->Text;
		if (p->Controls[1]->Text->Contains("."))
			 tmp = p->Controls[1]->Text->Replace(".", ",");
		res[1] = System::Convert::ToDouble(p->Controls[1]->Text == "" ? "0" : tmp);
	}

	return res;
}

//It resets textboxes in TableLayoutPanel^ p to "";
void ResetTextboxesInDataTable(System::Windows::Forms::TableLayoutPanel^ p)
 {
	for (int i = 0; i < 6; i++)
		if (p->Controls[i]->Text != "") p->Controls[i]->Text = "";
 }

//It prepares data file for 
void PrepareFile(string filename)
{
	ofstream f(filename); 
	vector<string> diversions{ "1 St.", "2 St.", "3 St.", "aVL", "aVF", "aVR", "V1", "V2", "V3", "V4", "V5", "V6" };
	f << "Intervals                                  " << ";" << 1.50 << ";" << 1.50 << ";" << "Speed" << ";" << 50.00 << ";" << '*' << endl;
	for (int i = 0; i < 12; i++)
	{
		f << diversions[i] << ";" << "P" << ";" << "Q" << ";" << "R" << ";" << "S" << ";" << "T" << ";" << "Sec P" << ";" << endl;
		f << "Heights                                                         " << ";" << 0.0 << ";" << 0.0 << ";" << 0.0 << ";" << 0.0 << ";" << 0.0 << ";" << 0.0 << ";" << '*' << endl;
		f << "Lengths                                                         " << ";" << 0.0 << ";" << 0.0 << ";" << 0.0 << ";" << 0.0 << ";" << 0.0 << ";" << 0.0 << ";" << '*' << endl;
		f << "Poses                                                           " << ";" << 0.0 << ";" << 0.0 << ";" << 0.0 << ";" << 0.0 << ";" << 0.0 << ";" << 0.0 << ";" << '*' << endl;
		f << "ST height                        " << ";" << 0.0 << ";" << '*' << endl;
		f << endl;
	}
	f.close();
}

//It saves values from vector to csv file 
void SaveWavesToFile(vector<double> v, string filename, string vector_name, int & pos)
{
	fstream f(filename);
	f.seekp(pos);
	f << vector_name;
	f << ";";
	for (int i = 0; i < v.size(); i++)
		f << v[i] << ";";
	pos = f.tellp();
	f.seekp(0);
	f.close();
}

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
			if (vector_name == "Lengths")
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
			else if (vector_name == "ST height") {
				getline(f, tmp);
				getline(f, tmp);
				getline(f, tmp);   //St interval saving branch
				pos = f.tellp();
				
			}
			f.close();
			SaveWavesToFile(v, filename, vector_name, pos);
			FalseDataDelete(filename, pos);
			fstream f(filename);
			f.seekp(pos);
			f << '*' << ";";
			return;
			}
		
			}
	f.close();
	}

//Deletes false datas created because of shifting
void FalseDataDelete(std::string filename, int pos)
{
	fstream f(filename);
	f.seekp(pos);
	char b;
	while (true)
	{
		f >> b;
		if (b == '*') {
			int r = f.tellp();
			f.seekp(r - 1);
			f << " ";
			f.seekp(r);
			return;
			
		}
		else /*if (b != ';')*/ {
			int r = f.tellp();
			f.seekp(r - 1);
			f << " ";
			f.seekp(r);
			
		}
		}
	f.close();
}

void SaveInFileIntervalAndSpeed(std::string filename, vector<double> v)
{
	fstream f(filename);
	f << "Intervals" << ";" << v[0] << ";" << v[1] << ";" << "Speed" << ";" << v[2];
	int pos = f.tellp();
	f.close();
	FalseDataDelete(filename, pos);
	f.open(filename);
	f.seekp(pos);
	f << ";" << '*' << ";";
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
void DrawControlVolt(System::Drawing::Graphics^ g, double height, const WavesData & w)
{
	System::Drawing::Pen^ myPen =
		gcnew System::Drawing::Pen(System::Drawing::Color::Red, 2);

	g->DrawLine(myPen, System::Drawing::Point(0,  height / 2),      System::Drawing::Point(20,          height / 2));
	g->DrawLine(myPen, System::Drawing::Point(20, height / 2),      System::Drawing::Point(20,          height / 2 - 40));
	g->DrawLine(myPen, System::Drawing::Point(20, height / 2 - 40), System::Drawing::Point(40,          height / 2 - 40));
	g->DrawLine(myPen, System::Drawing::Point(40, height / 2 - 40), System::Drawing::Point(40,          height / 2));

	if (!w.is_waves_empty()[0])
		g->DrawLine(myPen, System::Drawing::Point(40, height / 2),      System::Drawing::Point(40 + 20 * w.poses()[0], height / 2));
	else
		g->DrawLine(myPen, System::Drawing::Point(40, height / 2), System::Drawing::Point(40 + 20 * w.poses()[w.next_wave(0)], height / 2));
	delete myPen;
}

//It draws P wave (first arc) for ECG graphic
void DrawP(System::Drawing::Graphics^ g, double height, double shift, double next_interval, const WavesData & w)
{
	System::Drawing::Pen^ myPen =
		gcnew System::Drawing::Pen(System::Drawing::Color::Red, 2);

	if (w.is_waves_empty()[0])
		return;

	int next = 0;
	if (w.next_wave(0) != 0)
		next = w.next_wave(0);

	if (w.heights()[0] < 0)
		g->DrawArc(myPen, System::Drawing::Rectangle(shift + 20 * w.poses()[0], height / 2 - 20 * abs(w.heights()[0]), 20 * w.lengths()[0], 40 * abs(w.heights()[0])), 0, 180);
	else
		g->DrawArc(myPen, System::Drawing::Rectangle(shift + 20 * w.poses()[0], height / 2 - 20 * abs(w.heights()[0]), 20 * w.lengths()[0], 40 * abs(w.heights()[0])), 180, 180);

	if(next != 0)
		g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[0] + w.lengths()[0]), height / 2), System::Drawing::Point(shift + 20 * w.poses()[next], height / 2));
	else
		g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[0] + w.lengths()[0]), height / 2), System::Drawing::Point(next_interval + 20 * w.poses()[next], height / 2));

	delete myPen;
}

//It draws QRS complex (3 waves between P and T) for ECG graphic
void DrawQRS(System::Drawing::Graphics^ g, double height, double shift, double next_interval, const WavesData & w)
{
	System::Drawing::Pen^ myPen =
		gcnew System::Drawing::Pen(System::Drawing::Color::Red, 2);

	//If all waves are empty - we do nothing
	if (w.is_waves_empty()[1] && w.is_waves_empty()[2] && w.is_waves_empty()[3])
		return;

	//only S wave in QRS
	if (w.is_waves_empty()[1] && w.is_waves_empty()[2])
	{
		//Draw S wave
		g->DrawLine(myPen, System::Drawing::Point(shift + 20 * w.poses()[3], height / 2), System::Drawing::Point(shift + 20 * (w.poses()[3] + w.lengths()[3] / 2), height / 2 - 20 * w.heights()[3]));
		g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[3] + w.lengths()[3] / 2), height / 2 - 20 * w.heights()[3]), System::Drawing::Point(shift + 20 * (w.poses()[3] + w.lengths()[3]), height / 2));

		//ST interval is normal
		if (w.ST_interval() == 0)
		{
			//Looking for next wave in this cycle or in next cycle
			if (w.next_wave(3) == 3 && !w.is_waves_empty()[0])
				//Next wave is P wave in next cycle
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[3] + w.lengths()[3] + w.lengths()[0]), height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[0]), height / 2));
			else if (w.next_wave(3) == 3)
			{
				//Next wave is S wave in next cycle (we know what Q and R are empty, so we should check only P wave to understand it)
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[3] + w.lengths()[3]), height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[3]), height / 2));
			}
			else
				//Next wave is T wave in this cycle 
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[3] + w.lengths()[3] + w.lengths()[w.next_wave(3)]), height / 2), System::Drawing::Point(shift + 20 * (w.poses()[w.next_wave(3)]), height / 2));
		}	
		else //ST interval isn`t normal
		{
			//Find end of ST interval
			double st_end = w.is_waves_empty()[4] ? w.poses()[3] + w.lengths()[3] + 2 : w.poses()[4];

			//Draw ST interval
			if (w.ST_interval() < 0)
				g->DrawArc(myPen, System::Drawing::Rectangle(shift + 20 * (w.poses()[3] + w.lengths()[3]), height / 2 - 20 * abs(w.ST_interval()),
					20 * (st_end  - (w.poses()[3] + w.lengths()[3])), 40 * abs(w.ST_interval())), 0, 180);
			else if (w.ST_interval() > 0)
				g->DrawArc(myPen, System::Drawing::Rectangle(shift + 20 * (w.poses()[3] + w.lengths()[3]), height / 2 - 20 * abs(w.ST_interval()),
					20 * (st_end - (w.poses()[3] + w.lengths()[3])), 40 * abs(w.ST_interval())), 180, 180);



			//Looking for next wave in this cycle or in next cycle
			if (w.next_wave(3) == 3 && !w.is_waves_empty()[0])
				//Next wave is P wave in next cycle
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (st_end ), height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[0]), height / 2));
			else if (w.next_wave(3) == 3)
			{
				//Next wave is S wave in next cycle (we know what Q and R are empty, so we should check only P wave to understand it)
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * st_end, height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[3]), height / 2));
			}
			else
				//Next wave is T wave in this cycle 
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (st_end + w.lengths()[w.next_wave(3)]), height / 2), System::Drawing::Point(shift + 20 * (w.poses()[w.next_wave(3)]), height / 2));
		}
	}

	//Only R wave int QRS
	if (w.is_waves_empty()[1] && w.is_waves_empty()[3])
	{
		//Draw R wave
		g->DrawLine(myPen, System::Drawing::Point(shift + 20 * w.poses()[2], height / 2), System::Drawing::Point(shift + 20 * (w.poses()[2] + w.lengths()[2] / 2), height / 2 - 20 * w.heights()[2]));
		g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[2] + w.lengths()[2] / 2), height / 2 - 20 * w.heights()[2]), System::Drawing::Point(shift + 20 * (w.poses()[2] + w.lengths()[2]), height / 2));

		//ST interval is normal
		if (w.ST_interval() == 0)
		{
			//Looking for next wave in this cycle or in next cycle
			if (w.next_wave(2) == 2 && !w.is_waves_empty()[0])
				//Next wave is P wave in next cycle
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[2] + w.lengths()[2] + w.lengths()[0]), height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[0]), height / 2));
			else if (w.next_wave(2) == 2)
			{
				//Next wave is R wave in next cycle (we know what Q and S are empty, so we should check only P wave to understand it)
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[2] + w.lengths()[2]), height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[2]), height / 2));
			}
			else
				//Next wave is T wave in this cycle 
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[2] + w.lengths()[2] + w.lengths()[w.next_wave(2)]), height / 2), System::Drawing::Point(shift + 20 * (w.poses()[w.next_wave(2)]), height / 2));
		}
		else  	//ST interval isn`t normal
		{
			//Find end of ST interval
			double st_end = w.is_waves_empty()[4] ? w.poses()[2] + w.lengths()[2] + 2 : w.poses()[4];

			if (w.ST_interval() < 0)
				g->DrawArc(myPen, System::Drawing::Rectangle(shift + 20 * (w.poses()[2] + w.lengths()[2]), height / 2 - 20 * abs(w.ST_interval()),
					20 * (st_end - (w.poses()[2] + w.lengths()[2])), 40 * abs(w.ST_interval())), 0, 180);
			else if (w.ST_interval() > 0)
				g->DrawArc(myPen, System::Drawing::Rectangle(shift + 20 * (w.poses()[2] + w.lengths()[2]), height / 2 - 20 * abs(w.ST_interval()),
					20 * (st_end - (w.poses()[2] + w.lengths()[2])), 40 * abs(w.ST_interval())), 180, 180);

			//Looking for next wave in this cycle or in next cycle
			if (w.next_wave(2) == 2 && !w.is_waves_empty()[0])
				//Next wave is P wave in next cycle
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (st_end), height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[0]), height / 2));
			else if (w.next_wave(2) == 2)
			{
				//Next wave is R wave in next cycle (we know what Q and S are empty, so we should check only P wave to understand it)
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * st_end, height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[2]), height / 2));
			}
			else
				//Next wave is T wave in this cycle 
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (st_end + w.lengths()[w.next_wave(2)]), height / 2), System::Drawing::Point(shift + 20 * (w.poses()[w.next_wave(2)]), height / 2));
		}
	}
	else if (w.is_waves_empty()[1] && !w.is_waves_empty()[2] && !w.is_waves_empty()[3]) //Only R and S waves int QRS
	{
		//ST interval is normal
		if (w.ST_interval() == 0)
		{
			if (w.heights()[2] == w.heights()[3])
			{
				//Draw R wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * w.poses()[2] , height / 2),
					System::Drawing::Point(shift + 20 * (w.poses()[2] + (w.lengths()[2] + w.lengths()[3]) / 2), height / 2 - 20 * w.heights()[2]));
				//Draw S wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[2] + (w.lengths()[2] + w.lengths()[3]) / 2), height / 2 - 20 * w.heights()[2]),
					System::Drawing::Point(shift + 20 * (w.poses()[2] + w.lengths()[2] + w.lengths()[3]), height / 2));
			}
			else
			{
				//Draw R wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * w.poses()[2], height / 2), 
								   System::Drawing::Point(shift + 20 * (w.poses()[2] + w.lengths()[2] / 2), height / 2 - 20 * w.heights()[2]));
				//Draw S wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[2] + w.lengths()[2] / 2), height / 2 - 20 * w.heights()[2]), 
								   System::Drawing::Point(shift + 20 * (w.poses()[2] + w.lengths()[2] + w.lengths()[3] / 2), height / 2 - 20 * w.heights()[3]));
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[2] + w.lengths()[2] + w.lengths()[3] / 2), height / 2 - 20 * w.heights()[3]), 
								   System::Drawing::Point(shift + 20 * (w.poses()[2] + w.lengths()[2] + w.lengths()[3]), height / 2));

			}
			
			//Looking for next wave in this cycle or in next cycle
			if (w.next_wave(3) == 3 && !w.is_waves_empty()[0])
				//Next wave is P wave in next cycle
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[2] + w.lengths()[2] + w.lengths()[3]), height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[0]), height / 2));
			else if (w.next_wave(3) == 3)
			{
				//Next wave is R wave in next cycle (we know what Q is empty, so we should check only P wave to understand it)
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[2] + w.lengths()[2] + w.lengths()[3]), height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[2]), height / 2));
			}
			else
				//Next wave is T wave in this cycle 
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[2] + w.lengths()[2] + w.lengths()[3] ), height / 2), System::Drawing::Point(shift + 20 * (w.poses()[w.next_wave(3)]), height / 2));
		}
		else //ST interval isn`t normal
		{
			//Find end of ST interval
			double st_end = w.is_waves_empty()[4] ? w.poses()[2] + w.lengths()[2] + w.lengths()[3] + 2 : w.poses()[4];

			if (w.heights()[2] == w.heights()[3])
			{
				//Draw R wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * w.poses()[2], height / 2),
					System::Drawing::Point(shift + 20 * (w.poses()[2] + (w.lengths()[2] + w.lengths()[3]) / 2), height / 2 - 20 * w.heights()[2]));
				//Draw S wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[2] + (w.lengths()[2] + w.lengths()[3]) / 2), height / 2 - 20 * w.heights()[2]),
					System::Drawing::Point(shift + 20 * (w.poses()[2] + w.lengths()[2] + w.lengths()[3]), height / 2));

				if (w.ST_interval() < 0)
					g->DrawArc(myPen, System::Drawing::Rectangle(shift + 20 * (w.poses()[2] + w.lengths()[2] + w.lengths()[3]), height / 2 - 20 * abs(w.ST_interval()),
						20 * (st_end - (w.poses()[2] + w.lengths()[2] + w.lengths()[3])), 40 * abs(w.ST_interval())), 0, 180);
				else if (w.ST_interval() > 0)
					g->DrawArc(myPen, System::Drawing::Rectangle(shift + 20 * (w.poses()[2] + w.lengths()[2] + w.lengths()[3]), height / 2 - 20 * abs(w.ST_interval()),
						20 * (st_end - (w.poses()[2] + w.lengths()[2] + w.lengths()[3])), 40 * abs(w.ST_interval())), 180, 180);

				//Looking for next wave in this cycle or in next cycle
				if (w.next_wave(3) == 3 && !w.is_waves_empty()[0])
					//Next wave is P wave in next cycle
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * st_end, height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[0]), height / 2));
				else if (w.next_wave(3) == 3)
					//Next wave is Q wave in next cycle (we know what S is empty, so we should check only P wave to understand it)
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * st_end, height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[1]), height / 2));
				else
					//Next wave is T wave in this cycle 
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * st_end, height / 2), System::Drawing::Point(shift + 20 * (st_end + 0.25), height / 2));

			}
			else
			{
				//Draw R wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * w.poses()[2], height / 2), 
								   System::Drawing::Point(shift + 20 * (w.poses()[2] + w.lengths()[2]), height / 2 - 20 * w.heights()[2]));
				//Draw S wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[2] + w.lengths()[2]), height / 2 - 20 * w.heights()[2]), 
								   System::Drawing::Point(shift + 20 * (w.poses()[2] + w.lengths()[2] + w.lengths()[3]), height / 2 - 20 * w.heights()[3]));

				if (w.ST_interval() < 0)
					g->DrawArc(myPen, System::Drawing::Rectangle(shift + 20 * (w.poses()[2] + w.lengths()[2] + w.lengths()[3]), height / 2 - 20 * (w.heights()[3] + abs(w.ST_interval())),
						20 * (st_end - (w.poses()[2] + w.lengths()[2] + w.lengths()[3])), 40 * abs(w.ST_interval())), 0, 180);
				else if (w.ST_interval() > 0)
					g->DrawArc(myPen, System::Drawing::Rectangle(shift + 20 * (w.poses()[2] + w.lengths()[2] + w.lengths()[3]), height / 2 - 20 * (w.heights()[3] + abs(w.ST_interval())),
						20 * (st_end - (w.poses()[2] + w.lengths()[2] + w.lengths()[3])), 40 * abs(w.ST_interval())), 180, 180);

				//Looking for next wave in this cycle or in next cycle
				if (w.next_wave(3) == 3 && !w.is_waves_empty()[0])
				{
					//Next wave is P wave in next cycle
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (st_end), height / 2 - 20 * w.heights()[3]), System::Drawing::Point(shift + 20 * (st_end + 0.25), height / 2));
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (st_end + 0.25), height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[0]), height / 2));
				}
				else if (w.next_wave(3) == 3)
				{
					//Next wave is R wave in next cycle (we know what Q is empty, so we should check only P wave to understand it)
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (st_end), height / 2 - 20 * w.heights()[3]), System::Drawing::Point(shift + 20 * (st_end + 0.25), height / 2));
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (st_end + 0.25), height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[2]), height / 2));
				}
				else
					//Next wave is T wave in this cycle 
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (st_end), height / 2 - 20 * w.heights()[3]), System::Drawing::Point(shift + 20 * (st_end + 0.25), height / 2));
			}

			

			
		}
	}

	if (!w.is_waves_empty()[1] && !w.is_waves_empty()[2] && w.is_waves_empty()[3]) //only Q and R waves in QRS
	{
		//ST interval is normal
		if (w.ST_interval() == 0)
		{
			if (w.heights()[1] == w.heights()[2])
			{
				//Draw Q wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * w.poses()[1], height / 2),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + (w.lengths()[1] + w.lengths()[2]) / 2), height / 2 - 20 * w.heights()[2]));
				//Draw R wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + (w.lengths()[1] + w.lengths()[2]) / 2), height / 2 - 20 * w.heights()[2]),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2]), height / 2));
			}
			else
			{
				//Draw Q wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * w.poses()[1], height / 2),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] / 2), height / 2 - 20 * w.heights()[1]));
				//Draw R wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] / 2), height / 2 - 20 * w.heights()[1]),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2] / 2), height / 2 - 20 * w.heights()[2]));
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2] / 2), height / 2 - 20 * w.heights()[2]),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2]), height / 2));

			}

			//Looking for next wave in this cycle or in next cycle
			if (w.next_wave(2) == 2 && !w.is_waves_empty()[0])
				//Next wave is P wave in next cycle
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2]), height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[0]), height / 2));
			else if (w.next_wave(2) == 2)
			{
				//Next wave is Q wave in next cycle (we know what S is empty, so we should check only P wave to understand it)
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2]), height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[1]), height / 2));
			}
			else
				//Next wave is T wave in this cycle 
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2]), height / 2), System::Drawing::Point(shift + 20 * (w.poses()[w.next_wave(2)]), height / 2));
		}
		else //ST interval isn`t normal
		{
			//Find end of ST interval
			double st_end = w.is_waves_empty()[4] ? w.poses()[1] + w.lengths()[1] + w.lengths()[2] + 2 : w.poses()[4];

			if (w.heights()[1] == w.heights()[2])
			{
				//Draw Q wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * w.poses()[1], height / 2),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + (w.lengths()[1] + w.lengths()[2]) / 2), height / 2 - 20 * w.heights()[2]));
				//Draw R wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + (w.lengths()[1] + w.lengths()[2]) / 2), height / 2 - 20 * w.heights()[2]),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2]), height / 2));

				if (w.ST_interval() < 0)
					g->DrawArc(myPen, System::Drawing::Rectangle(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2]), height / 2 - 20 * abs(w.ST_interval()),
						20 * (st_end - (w.poses()[1] + w.lengths()[1] + w.lengths()[2])), 40 * abs(w.ST_interval())), 0, 180);
				else if (w.ST_interval() > 0)
					g->DrawArc(myPen, System::Drawing::Rectangle(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2]), height / 2 - 20 * abs(w.ST_interval()),
						20 * (st_end - (w.poses()[1] + w.lengths()[1] + w.lengths()[2])), 40 * abs(w.ST_interval())), 180, 180);

				//Looking for next wave in this cycle or in next cycle
				if (w.next_wave(2) == 2 && !w.is_waves_empty()[0])
					//Next wave is P wave in next cycle
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * st_end, height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[0]), height / 2));
				else if (w.next_wave(2) == 2)
					//Next wave is Q wave in next cycle (we know what S is empty, so we should check only P wave to understand it)
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * st_end, height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[1]), height / 2));
				else
					//Next wave is T wave in this cycle 
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * st_end, height / 2), System::Drawing::Point(shift + 20 * (st_end + 0.25), height / 2));

			}
			else
			{
				//Draw Q wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * w.poses()[1], height / 2),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1]), height / 2 - 20 * w.heights()[1]));
				//Draw R wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1]), height / 2 - 20 * w.heights()[1]),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2]), height / 2 - 20 * w.heights()[2]));

				if (w.ST_interval() < 0)
					g->DrawArc(myPen, System::Drawing::Rectangle(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2]), height / 2 - 20 * (w.heights()[2] + abs(w.ST_interval())),
						20 * (st_end - (w.poses()[1] + w.lengths()[1] + w.lengths()[2])), 40 * abs(w.ST_interval())), 0, 180);
				else if (w.ST_interval() > 0)
					g->DrawArc(myPen, System::Drawing::Rectangle(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2]), height / 2 - 20 * (w.heights()[2] + abs(w.ST_interval())),
						20 * (st_end - (w.poses()[1] + w.lengths()[1] + w.lengths()[2])), 40 * abs(w.ST_interval())), 180, 180);

				//Looking for next wave in this cycle or in next cycle
				if (w.next_wave(2) == 2 && !w.is_waves_empty()[0])
				{
					//Next wave is P wave in next cycle
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (st_end), height / 2 - 20 * w.heights()[2]), System::Drawing::Point(shift + 20 * (st_end + 0.25), height / 2));
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (st_end + 0.25), height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[0]), height / 2));
				}
				else if (w.next_wave(2) == 2)
				{
					//Next wave is Q wave in next cycle (we know what S is empty, so we should check only P wave to understand it)
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (st_end), height / 2 - 20 * w.heights()[2]), System::Drawing::Point(shift + 20 * (st_end + 0.25), height / 2));
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (st_end + 0.25), height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[1]), height / 2));
				}
				else
					//Next wave is T wave in this cycle 
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (st_end), height / 2 - 20 * w.heights()[2]), System::Drawing::Point(shift + 20 * (st_end + 0.25), height / 2));
			}



			
		}
	}
	else if (!w.is_waves_empty()[1] && !w.is_waves_empty()[3] && w.is_waves_empty()[2]) //only Q and S waves in QRS
	{
		//ST interval is normal
		if (w.ST_interval() == 0)
		{
			if (w.heights()[1] == w.heights()[3])
			{
				//Draw Q wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * w.poses()[1], height / 2),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + (w.lengths()[1] + w.lengths()[3]) / 2), height / 2 - 20 * w.heights()[3]));
				//Draw S wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + (w.lengths()[1] + w.lengths()[3]) / 2), height / 2 - 20 * w.heights()[3]),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[3]), height / 2));
			}
			else
			{
				//Draw Q wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * w.poses()[1], height / 2),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] / 2), height / 2 - 20 * w.heights()[1]));
				//Draw S wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] / 2), height / 2 - 20 * w.heights()[1]),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[3] / 2), height / 2 - 20 * w.heights()[3]));
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[3] / 2), height / 2 - 20 * w.heights()[3]),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[3]), height / 2));

			}

			//Looking for next wave in this cycle or in next cycle
			if (w.next_wave(3) == 3 && !w.is_waves_empty()[0])
				//Next wave is P wave in next cycle
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[3]), height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[0]), height / 2));
			else if (w.next_wave(3) == 3)
			{
				//Next wave is Q wave in next cycle (we know what R is empty, so we should check only P wave to understand it)
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[3]), height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[1]), height / 2));
			}
			else
				//Next wave is T wave in this cycle 
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[3]), height / 2), System::Drawing::Point(shift + 20 * (w.poses()[w.next_wave(3)]), height / 2));
		}
		else //ST interval isn`t normal
		{
			//Find end of ST interval
			double st_end = w.is_waves_empty()[4] ? w.poses()[1] + w.lengths()[1] + w.lengths()[3] + 2 : w.poses()[4];

			if (w.heights()[1] == w.heights()[3])
			{
				//Draw Q wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * w.poses()[1], height / 2),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + (w.lengths()[1] + w.lengths()[3]) / 2), height / 2 - 20 * w.heights()[3]));
				//Draw S wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + (w.lengths()[1] + w.lengths()[3]) / 2), height / 2 - 20 * w.heights()[3]),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[3]), height / 2));

				if (w.ST_interval() < 0)
					g->DrawArc(myPen, System::Drawing::Rectangle(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[3]), height / 2 - 20 * abs(w.ST_interval()),
						20 * (st_end - (w.poses()[1] + w.lengths()[1] + w.lengths()[3])), 40 * abs(w.ST_interval())), 0, 180);
				else if (w.ST_interval() > 0)
					g->DrawArc(myPen, System::Drawing::Rectangle(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[3]), height / 2 - 20 * abs(w.ST_interval()),
						20 * (st_end - (w.poses()[1] + w.lengths()[1] + w.lengths()[3])), 40 * abs(w.ST_interval())), 180, 180);

				//Looking for next wave in this cycle or in next cycle
				if (w.next_wave(3) == 3 && !w.is_waves_empty()[0])
					//Next wave is P wave in next cycle
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * st_end, height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[0]), height / 2));
				else if (w.next_wave(3) == 3)
					//Next wave is Q wave in next cycle (we know what S is empty, so we should check only P wave to understand it)
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * st_end, height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[1]), height / 2));
				else
					//Next wave is T wave in this cycle 
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * st_end, height / 2), System::Drawing::Point(shift + 20 * (st_end + 0.25), height / 2));
			}
			else
			{
				//Draw Q wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * w.poses()[1], height / 2),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1]), height / 2 - 20 * w.heights()[1]));
				//Draw S wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1]), height / 2 - 20 * w.heights()[1]),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[3]), height / 2 - 20 * w.heights()[3]));

				if (w.ST_interval() < 0)
					g->DrawArc(myPen, System::Drawing::Rectangle(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[3]), height / 2 - 20 * (w.heights()[3] + abs(w.ST_interval())),
						20 * (st_end - (w.poses()[1] + w.lengths()[1] + w.lengths()[3])), 40 * abs(w.ST_interval())), 0, 180);
				else if (w.ST_interval() > 0)
					g->DrawArc(myPen, System::Drawing::Rectangle(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[3]), height / 2 - 20 * (w.heights()[3] + abs(w.ST_interval())),
						20 * (st_end - (w.poses()[1] + w.lengths()[1] + w.lengths()[3])), 40 * abs(w.ST_interval())), 180, 180);

				//Looking for next wave in this cycle or in next cycle
				if (w.next_wave(3) == 3 && !w.is_waves_empty()[0])
				{
					//Next wave is P wave in next cycle
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (st_end), height / 2 - 20 * w.heights()[3]), System::Drawing::Point(shift + 20 * (st_end + 0.25), height / 2));
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (st_end + 0.25), height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[0]), height / 2));
				}
				else if (w.next_wave(3) == 3)
				{
					//Next wave is Q wave in next cycle (we know what S is empty, so we should check only P wave to understand it)
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (st_end), height / 2 - 20 * w.heights()[3]), System::Drawing::Point(shift + 20 * (st_end + 0.25), height / 2));
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (st_end + 0.25), height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[1]), height / 2));
				}
				else
					//Next wave is T wave in this cycle 
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (st_end), height / 2 - 20 * w.heights()[3]), System::Drawing::Point(shift + 20 * (st_end + 0.25), height / 2));
			}

			

			
		}
	}
	else if (!w.is_waves_empty()[1] && !w.is_waves_empty()[2] && !w.is_waves_empty()[3]) //Full QRS exist
	{
		//ST interval is normal
		if (w.ST_interval() == 0)
		{
			if (w.heights()[1] == w.heights()[2] && w.heights()[2] == w.heights()[3])
			{
				//Draw Q wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * w.poses()[1], height / 2),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + (w.lengths()[1] + w.lengths()[2] + w.lengths()[3]) / 2), height / 2 - 20 * w.heights()[3]));
				//Draw S wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + (w.lengths()[1] + w.lengths()[2] + w.lengths()[3]) / 2), height / 2 - 20 * w.heights()[3]),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2] + w.lengths()[3]), height / 2));
			}
			else if (w.heights()[1] == w.heights()[2] && w.heights()[1] != w.heights()[3])
			{
				//Draw Q wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * w.poses()[1], height / 2),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + (w.lengths()[1] + w.lengths()[2]) / 2), height / 2 - 20 * w.heights()[2]));
				//Draw R wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + (w.lengths()[1] + w.lengths()[2]) / 2), height / 2 - 20 * w.heights()[2]),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2] + w.lengths()[3] / 2), height / 2 - 20 * w.heights()[3]));
				//Draw S wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2] + w.lengths()[3] / 2), height / 2 - 20 * w.heights()[3]),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2] + w.lengths()[3]), height / 2));
			}
			else if (w.heights()[2] == w.heights()[3] && w.heights()[1] != w.heights()[2])
			{
				//Draw Q wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * w.poses()[1], height / 2),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1]), height / 2 - 20 * w.heights()[1]));
				//Draw R wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1]), height / 2 - 20 * w.heights()[1]),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + (w.lengths()[2] + w.lengths()[3]) / 2), height / 2 - 20 * w.heights()[2]));
				//Draw S wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + (w.lengths()[2] + w.lengths()[3]) / 2), height / 2 - 20 * w.heights()[2]),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2] + w.lengths()[3]), height / 2));
			}
			else
			{

				//Draw Q wave
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * w.poses()[1], height / 2),
						System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1]), height / 2 - 20 * w.heights()[1]));
				//Draw R wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1]), height / 2 - 20 * w.heights()[1]),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2] / 2), height / 2 - 20 * w.heights()[2]));
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2] / 2), height / 2 - 20 * w.heights()[2]),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2]), height / 2 - 20 * w.heights()[3]));
				//Draw S wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2]), height / 2 - 20 * w.heights()[3]),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2] + w.lengths()[3]), height / 2));
			}

			//Looking for next wave in this cycle or in next cycle
			if (w.next_wave(3) == 3 && !w.is_waves_empty()[0])
				//Next wave is P wave in next cycle
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2] + w.lengths()[3]), height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[0]), height / 2));
			else if (w.next_wave(3) == 3)
			{
				//Next wave is Q wave in next cycle (we know what R is empty, so we should check only P wave to understand it)
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2] + w.lengths()[3]), height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[1]), height / 2));
			}
			else
				//Next wave is T wave in this cycle 
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2] + w.lengths()[3]), height / 2), System::Drawing::Point(shift + 20 * (w.poses()[w.next_wave(3)]), height / 2));
		}
		else //ST interval isn`t normal
		{
			//Find end of ST interval
			double st_end = w.is_waves_empty()[4] ? w.poses()[1] + w.lengths()[1] + w.lengths()[2] + w.lengths()[3] + 1.75 : w.poses()[4] - 0.25;

			if (w.heights()[1] == w.heights()[2] && w.heights()[2] == w.heights()[3]) // Q == R == S
			{
				//Draw Q wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * w.poses()[1], height / 2),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + (w.lengths()[1] + w.lengths()[2] + w.lengths()[3]) / 2), height / 2 - 20 * w.heights()[3]));
				//Draw S wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + (w.lengths()[1] + w.lengths()[2] + w.lengths()[3]) / 2), height / 2 - 20 * w.heights()[3]),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2] + w.lengths()[3]), height / 2));

				if (w.ST_interval() < 0)
					g->DrawArc(myPen, System::Drawing::Rectangle(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2] + w.lengths()[3]), height / 2 - 20 * abs(w.ST_interval()),
						20 * (st_end - (w.poses()[1] + w.lengths()[1] + w.lengths()[2] + w.lengths()[3])), 40 * abs(w.ST_interval())), 0, 180);
				else if (w.ST_interval() > 0)
					g->DrawArc(myPen, System::Drawing::Rectangle(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2] + w.lengths()[3]), height / 2 - 20 * abs(w.ST_interval()),
						20 * (st_end - (w.poses()[1] + w.lengths()[1] + w.lengths()[2] + w.lengths()[3])), 40 * abs(w.ST_interval())), 180, 180);

				//Looking for next wave in this cycle or in next cycle
				if (w.next_wave(3) == 3 && !w.is_waves_empty()[0])
					//Next wave is P wave in next cycle
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * st_end, height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[0]), height / 2));
				else if (w.next_wave(3) == 3)
					//Next wave is Q wave in next cycle (we know what S is empty, so we should check only P wave to understand it)
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * st_end, height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[1]), height / 2));
				else
					//Next wave is T wave in this cycle 
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * st_end, height / 2 ), System::Drawing::Point(shift + 20 * (st_end + 0.25), height / 2));
			}
			else if (w.heights()[1] == w.heights()[2] && w.heights()[1] != w.heights()[3]) // Q == R != S
			{
				//Draw Q wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * w.poses()[1], height / 2),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + (w.lengths()[1] + w.lengths()[2]) / 2), height / 2 - 20 * w.heights()[2]));
				//Draw R & S wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + (w.lengths()[1] + w.lengths()[2]) / 2), height / 2 - 20 * w.heights()[2]),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2] + w.lengths()[3]), height / 2 - 20 * w.heights()[3]));

				if (w.ST_interval() < 0)
					g->DrawArc(myPen, System::Drawing::Rectangle(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2] + w.lengths()[3]), height / 2 - 20 * (w.heights()[3] + abs(w.ST_interval())),
						20 * (st_end - (w.poses()[1] + w.lengths()[1] + w.lengths()[2] + w.lengths()[3])), 40 * abs(w.ST_interval())), 0, 180);
				else if (w.ST_interval() > 0)
					g->DrawArc(myPen, System::Drawing::Rectangle(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2] + w.lengths()[3]), height / 2 - 20 * (w.heights()[3] + abs(w.ST_interval())),
						20 * (st_end - (w.poses()[1] + w.lengths()[1] + w.lengths()[2] + w.lengths()[3])), 40 * abs(w.ST_interval())), 180, 180);

				//Looking for next wave in this cycle or in next cycle
				if (w.next_wave(3) == 3 && !w.is_waves_empty()[0])
				{
					//Next wave is P wave in next cycle
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (st_end), height / 2 - 20 * w.heights()[3]), System::Drawing::Point(shift + 20 * (st_end + 0.25), height / 2));
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (st_end + 0.25), height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[0]), height / 2));
				}
				else if (w.next_wave(3) == 3)
				{
					//Next wave is Q wave in next cycle (we know what S is empty, so we should check only P wave to understand it)
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (st_end), height / 2 - 20 * w.heights()[3]), System::Drawing::Point(shift + 20 * (st_end + 0.25), height / 2));
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (st_end + 0.25), height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[1]), height / 2));
				}
				else
					//Next wave is T wave in this cycle 
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (st_end), height / 2 - 20 * w.heights()[3]), System::Drawing::Point(shift + 20 * (st_end + 0.25), height / 2));
			}
			else if (w.heights()[2] == w.heights()[3] && w.heights()[1] != w.heights()[2]) // Q != R == S
			{
				//Draw Q wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * w.poses()[1], height / 2),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1]), height / 2 - 20 * w.heights()[1]));
				//Draw R wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1]), height / 2 - 20 * w.heights()[1]),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + (w.lengths()[2] + w.lengths()[3]) / 2), height / 2 - 20 * w.heights()[2]));
				//Draw S wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + (w.lengths()[2] + w.lengths()[3]) / 2), height / 2 - 20 * w.heights()[2]),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2] + w.lengths()[3]), height / 2));

				if (w.ST_interval() < 0)
					g->DrawArc(myPen, System::Drawing::Rectangle(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2] + w.lengths()[3]), height / 2 - 20 * abs(w.ST_interval()),
						20 * (st_end - (w.poses()[1] + w.lengths()[1] + w.lengths()[2] + w.lengths()[3])), 40 * abs(w.ST_interval())), 0, 180);
				else if (w.ST_interval() > 0)
					g->DrawArc(myPen, System::Drawing::Rectangle(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2] + w.lengths()[3]), height / 2 - 20 * abs(w.ST_interval()),
						20 * (st_end - (w.poses()[1] + w.lengths()[1] + w.lengths()[2] + w.lengths()[3])), 40 * abs(w.ST_interval())), 180, 180);

				//Looking for next wave in this cycle or in next cycle
				if (w.next_wave(3) == 3 && !w.is_waves_empty()[0])
					//Next wave is P wave in next cycle
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * st_end, height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[0]), height / 2));
				else if (w.next_wave(3) == 3)
					//Next wave is Q wave in next cycle (we know what S is empty, so we should check only P wave to understand it)
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * st_end, height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[1]), height / 2));
				else
					//Next wave is T wave in this cycle 
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * st_end, height / 2), System::Drawing::Point(shift + 20 * (st_end + 0.25), height / 2));
			}
			else // Q != R != S
			{

				//Draw Q wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * w.poses()[1], height / 2),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1]), height / 2 - 20 * w.heights()[1]));
				//Draw R wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1]), height / 2 - 20 * w.heights()[1]),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2] / 2), height / 2 - 20 * w.heights()[2]));
				//Draw S wave
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2] / 2), height / 2 - 20 * w.heights()[2]),
					System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2] + w.lengths()[3]), height / 2 - 20 * w.heights()[3]));

				if (w.ST_interval() < 0)
					g->DrawArc(myPen, System::Drawing::Rectangle(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2] + w.lengths()[3]), height / 2 - 20 * (w.heights()[3] + abs(w.ST_interval())),
						20 * (st_end - (w.poses()[1] + w.lengths()[1] + w.lengths()[2] + w.lengths()[3])), 40 * abs(w.ST_interval())), 0, 180);
				else if (w.ST_interval() > 0)
					g->DrawArc(myPen, System::Drawing::Rectangle(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[2] + w.lengths()[3]), height / 2 - 20 * (w.heights()[3] + abs(w.ST_interval())),
						20 * (st_end - (w.poses()[1] + w.lengths()[1] + w.lengths()[2] + w.lengths()[3])), 40 * abs(w.ST_interval())), 180, 180);

				//Looking for next wave in this cycle or in next cycle
				if (w.next_wave(3) == 3 && !w.is_waves_empty()[0])
				{
					//Next wave is P wave in next cycle
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (st_end), height / 2 - 20 * w.heights()[3]), System::Drawing::Point(shift + 20 * (st_end + 0.25), height / 2));
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (st_end + 0.25), height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[0]), height / 2));
				}
				else if (w.next_wave(3) == 3)
				{
					//Next wave is Q wave in next cycle (we know what S is empty, so we should check only P wave to understand it)
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (st_end), height / 2 - 20 * w.heights()[3]), System::Drawing::Point(shift + 20 * (st_end + 0.25), height / 2));
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (st_end + 0.25), height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[1]), height / 2));
				}
				else
					//Next wave is T wave in this cycle 
					g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (st_end), height / 2 - 20 * w.heights()[3]), System::Drawing::Point(shift + 20 * (st_end + 0.25), height / 2));
			}

		}
	}
	else if (!w.is_waves_empty()[1]) // Only Q wave in QRS
	{
		//Draw Q wave
		g->DrawLine(myPen, System::Drawing::Point(shift + 20 * w.poses()[1], height / 2), System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] / 2), height / 2 - 20 * w.heights()[1]));
		g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] / 2), height / 2 - 20 * w.heights()[1]), System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1]), height / 2));

		//ST interval is normal
		if (w.ST_interval() == 0)
		{
			//Looking for next wave in this cycle or in next cycle
			if(w.next_wave(1) == 1 && !w.is_waves_empty()[0])
				//Next wave is P wave in next cycle
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[0]), height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[0]), height / 2));
			else if (w.next_wave(1) == 1 && !w.is_waves_empty()[0])
				//Next wave is Q wave in next cycle (we know what R and S are empty, so we should check only P wave to understand it)
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[1]), height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[1]), height / 2));
			else
				//Next wave is T wave in this cycle 
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[1] + w.lengths()[1] + w.lengths()[w.next_wave(3)]), height / 2), System::Drawing::Point(shift + 20 * (w.poses()[w.next_wave(1)]), height / 2));
		}
		else //ST interval isn`t normal
		{
			//Find end of ST interval
			double st_end = w.is_waves_empty()[4] ? w.poses()[1] + w.lengths()[1] + 2 : w.poses()[4];

			if (w.ST_interval() < 0)
				g->DrawArc(myPen, System::Drawing::Rectangle(shift + 20 * (w.poses()[1] + w.lengths()[1]), height / 2 - 20 * abs(w.ST_interval()),
					20 * (st_end - (w.poses()[1] + w.lengths()[1])), 40 * abs(w.ST_interval())), 0, 180);
			else if (w.ST_interval() > 0)
				g->DrawArc(myPen, System::Drawing::Rectangle(shift + 20 * (w.poses()[1] + w.lengths()[1]), height / 2 - 20 * abs(w.ST_interval()),
					20 * (st_end - (w.poses()[1] + w.lengths()[1])), 40 * abs(w.ST_interval())), 180, 180);



			//Looking for next wave in this cycle or in next cycle
			if (w.next_wave(1) == 1 && !w.is_waves_empty()[0])
				//Next wave is P wave in next cycle
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (st_end), height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[0]), height / 2));
			else if (w.next_wave(1) == 1)
				//Next wave is Q wave in next cycle (we know what R and S are empty, so we should check only P wave to understand it)
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * st_end, height / 2), System::Drawing::Point(shift + 20 * (next_interval + w.poses()[1]), height / 2));
			else
				//Next wave is T wave in this cycle 
				g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (st_end + w.lengths()[w.next_wave(1)]), height / 2), System::Drawing::Point(shift + 20 * (w.poses()[w.next_wave(1)]), height / 2));
		}
	}

	delete myPen;
}

//It draws T wave (second arc) for ECG graphic
void DrawT(System::Drawing::Graphics^ g,  double height, double shift, double next_interval, const WavesData & w)
{
	System::Drawing::Pen^ myPen =
		gcnew System::Drawing::Pen(System::Drawing::Color::Red, 2);

	if (w.is_waves_empty()[4])
		return;

	int next = 0;
	if (w.is_waves_empty()[0])
		next = w.next_wave(0);

	if (w.heights()[4] < 0)
		g->DrawArc(myPen, System::Drawing::Rectangle(shift + 20 * w.poses()[4], height / 2 - 20 * abs(w.heights()[4]), 20 * w.lengths()[4], 40 * abs(w.heights()[4])), 0, 180);
	else
		g->DrawArc(myPen, System::Drawing::Rectangle(shift + 20 * w.poses()[4], height / 2 - 20 * abs(w.heights()[4]), 20 * w.lengths()[4], 40 * abs(w.heights()[4])), 180, 180);
	g->DrawLine(myPen, System::Drawing::Point(shift + 20 * (w.poses()[4] + w.lengths()[4]), height / 2), System::Drawing::Point(shift +  + 20 * (next_interval + w.poses()[next]), height / 2));

	delete myPen;
}

//It draws ECG graphic on PictureBox
void DrawGraphic(System::Drawing::Graphics^ g, int width, int height, const WavesData & w)
{
	DrawControlVolt(g, height, w);
	if (w.empty())
	{
		System::Drawing::Pen^ myPen =
			gcnew System::Drawing::Pen(System::Drawing::Color::Red, 2);
		g->DrawLine(myPen, System::Drawing::Point(40, height / 2), System::Drawing::Point(width, height / 2));
		delete myPen;
		return;
	}

	for (int i = 0; i < 14; i++)
	{
		int interval = (i % 2 == 0) ? w.RR_intervals()[0] : w.RR_intervals()[1];
		int next_interval = (i % 2 == 0) ? w.RR_intervals()[1] : w.RR_intervals()[0];
		DrawP(g, height, 40 + 20 * i * interval, next_interval, w);
		DrawQRS(g, height, 40 + 20 * i * interval, next_interval, w);
		DrawT(g, height, 40 + 20 * i * interval, next_interval, w);
	}
}