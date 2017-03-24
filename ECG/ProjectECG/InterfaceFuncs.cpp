#include <iostream>
#include <locale>
#include <algorithm>


#include "InterfaceFuncs.h"
#include "AnalysisFuncs.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace std;

// textboxes MUST BE in TableLayoutPanel^ and their names MUST CONTAIN "textBox"
std::vector<double> ParseDatasIntoDoubleVector(TableLayoutPanel^ pan)
{

	std::vector<double> res;
	String^ st1 = "textBox";
	String^ st2 = "comboBox";

	for (int i = 0; i < pan->Controls->Count; i++)
	{
		auto ST = pan->Controls[i]->Name;
		auto flag = ST->Contains(st1);
		auto flag1 = ST->Contains(st2);
		if (flag)
			if (pan->Controls[i]->Text != "")
			{
				String^ tmp = pan->Controls[i]->Text;
				if (pan->Controls[i]->Text->Contains("."))
					tmp = pan->Controls[i]->Text->Replace(".", ",");
				res.push_back(System::Convert::ToDouble(tmp));
			}
			else res.push_back(0);
		else if (flag1) {
			String^ tmp = pan->Controls[i]->Text;
			res.push_back(System::Convert::ToDouble(tmp));
		}
	}
	return res;
}

//It saves values from vector to text file 
void SaveWavesToFile(vector<double> v)
{
	ofstream f;
	f.open("WavesData.txt", ios::app);//Now don't forget to delete this file after test, because this adds data to an existing data

	for_each(v.begin(), v.end(), [&f](double x) {f << x << " "; });
	f << endl;

	//for (int i = 0; i < 6; i ++)
	//	f << v[i] << " ";
	//f << endl;

	//for (int i = 6; i < 12; i ++)
	//	f << v[i] << " ";
	//f << endl;

	//for (int i = 12; i < 18; i ++)
	//	f << v[i] << " ";

	f.close();
}