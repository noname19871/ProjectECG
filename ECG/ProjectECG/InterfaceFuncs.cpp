#include <iostream>
#include <locale>
#include <algorithm>


#include "InterfaceFuncs.h"
#include "AnalysisFuncs.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace std;

// textboxes MUST BE in TableLayoutPanel^ and their names MUST CONTAIN "textBox"
std::vector<double> ParseDatasIntoDoubleVector(TableLayoutPanel^ p, int size)
{

	std::vector<double> res(size);
	String^ st1 = "textBox";
	String^ st2 = "comboBox";

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
		res[0] = System::Convert::ToDouble(p->Controls[1]->Text == "" ? "0" : p->Controls[1]->Text);
		res[1] = System::Convert::ToDouble(p->Controls[3]->Text == "" ? "0" : p->Controls[3]->Text);
	}

	return res;

}

//It saves values from vector to text file 
void SaveWavesToFile(vector<double> v)
{
	ofstream f;
	f.open("WavesData.txt", ios::app);

	for (int i = 0; i < v.size(); i++)
		f << v[i] << " ";
	f << endl;
	f.close();
}