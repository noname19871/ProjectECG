#include <iostream>

#include "AnalysisFuncs.h"

using namespace std;


bool WavesData::Check_arrhythmia()
{
	return (heights()[0] == 0.0) && (intervals()[0] != intervals()[1]);
}

//return patient`s hearth rate
double WavesData::count_heart_rate()
{
	if (intervals()[0] == 0)
		return 0;
	return speed() == 50 ? trunc(600 / intervals()[0]) : trunc(300 / intervals()[1]);
}

//It checks patient`s hearth rate for Bradycardia
bool WavesData::Check_Bradycardia()
{
	return count_heart_rate() < 60;
}

//It checks patient`s hearth rate for Tachycardia
bool WavesData::Check_Tachycardia()
{
	return count_heart_rate() > 100;
}

//Return hearth axis`s position
System::String^ Define_hearth_axis(const WavesData & w1, const WavesData & w2, const WavesData & w3)
{

	if (w1.heights()[2] > w1.heights()[3] && w3.heights()[3] > w3.heights()[2])
		return "Электрическая ось отклонена влево";

	if(w1.heights()[2] < w1.heights()[3] && w3.heights()[3] < w3.heights()[2])
		return "Электрическая ось отклонена вправо";

	return "Электрическая ось в нормальном положении";
}

//It checks patient for back myocardial
bool WavesData::Check_back_myocardial(const WavesData & w3, const WavesData & aVF)
{
	return 1;
}

//Parse string from data file to get 6 double digits from it
void WavesData::parse_string(string & s)
{
	int del_pos = s.find_first_of(";") + 1;
	s.erase(s.begin(), s.begin() + del_pos);
	//s.erase(s.begin() + s.find_last_of(";") + 1, s.end());
	while (s.find(";") != string::npos)
		s.replace(s.find(";"), 1, " ");
}

//Return number of diversion in data file
int WavesData::define_diversion(System::String^ s)
{
	switch(s[0])
	{
	case '1': { return 0; }
	case '2': { return 1; }
	case '3': { return 2; }
	case 'a': 
	{
		switch (s[2])
		{
		case 'L': { return 3; }
		case 'F': { return 4; }
		case 'R': { return 5; }
		};
	}
	case 'V': 
	{
		switch (s[1])
		{
		case '1': { return 6; }
		case '2': { return 7; }
		case '3': { return 8; }
		case '4': { return 9; }
		case '5': { return 10; }
		case '6': { return 11; }
		}
	}
	};
}