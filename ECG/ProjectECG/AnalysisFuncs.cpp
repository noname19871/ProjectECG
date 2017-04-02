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
		return "Ýëåêòðè÷åñêàÿ îñü îòêëîíåíà âëåâî";

	if(w1.heights()[2] < w1.heights()[3] && w3.heights()[3] < w3.heights()[2])
		return "Ýëåêòðè÷åñêàÿ îñü îòêëîíåíà âïðàâî";

	return "Ýëåêòðè÷åñêàÿ îñü ñåðäöà íå îòêëîíåíà";
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
	s.erase(s.begin() + s.find_last_of(";"), s.end());
	while (s.find(";") != string::npos)
		s.replace(s.find(";"), 1, " ");
}