#include <iostream>
#include <cmath>

#include "AnalysisFuncs.h"

using namespace std;


void WavesData::fill_is_empty()
{
	for (int i = 0; i < 5; i++)
		_is_waves_empty.push_back((heights()[i] == 0) || (lengths()[i] == 0) || (poses()[i] == 0));
}

//It checks patient`s hearth for arrhythmia
System::String^ WavesData::Check_arrhythmia()
{
	System::String^ s = "";
	if ((heights()[0] == 0.0) && (RR_intervals()[0] != RR_intervals()[1]))
		s =  "мерцательная аритмия";
	else if (heights()[0] > 0)
		s =  "синусовый";
	else if (heights()[0] < 0)
		s = "предсердный";
	else s = "желудочковый";

	return s;
}

//return patient`s hearth rate
double WavesData::count_heart_rate()
{
	if (RR_intervals()[0] == 0)
		return 0;
	return speed() == 50 ? trunc(600 / RR_intervals()[0]) : trunc(300 / RR_intervals()[0]);
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

	if (abs(w1.heights()[2]) > abs(w1.heights()[3]) && abs(w3.heights()[3]) > abs(w3.heights()[2]))
		return "Электрическая ось отклонена влево";

	if(abs(w1.heights()[2]) < abs(w1.heights()[3]) && abs(w3.heights()[3]) < abs(w3.heights()[2]))
		return "Электрическая ось отклонена вправо";

	return "Электрическая ось в нормальном положении";
}

//It checks patient for back myocardial
bool WavesData::Check_back_myocardial(const WavesData & w3, const WavesData & aVF)
{
	return 1;
}

System::String^ WavesData::Right_blockade(const WavesData & w1, const WavesData & w2, const WavesData & w3, const WavesData & v1)
{
	if (Define_hearth_axis(w1, w2, w3) == "Электрическая ось отклонена вправо" && v1.heights()[6] != 0)
	{
		if (v1.heights()[2] >= v1.heights()[6])
			return "Неполная блокада правой ножки пучка Гиса";
		else
			return "Полная блокада правой ножки пучка Гиса";
	}

	return "";
}

System::String^ WavesData::Left_blockade(const WavesData & w1, const WavesData & w2, const WavesData & w3, const WavesData & aVR, const std::vector<WavesData> v)
{
	if (Define_hearth_axis(w1, w2, w3) == "Электрическая ось отклонена влево")
	{
		bool full_blockade = abs(aVR.heights()[1]) > abs(aVR.heights()[3]);

		if (!full_blockade)
			return "";

		for (int i = 0; v.size(); i++)
		{
			full_blockade = abs(v[i].lengths()[1] + v[i].lengths()[2] + v[i].lengths()[3]) > 1.5;
		}

		if (full_blockade && v[4].heights()[4] < 0 && v[5].heights()[4] < 0)
			return "Полная блокада левой ножки пучка Гиса";

		for (int i = 0; i < v.size(); i++)
		{
			full_blockade = abs(v[i].heights()[1]) < abs(v[i].heights()[3]);
			if (!full_blockade)
				return "Неполная блокада передне-верхнего разветвления левой ножки пучка Гиса";
		}

		return "Полная блокада передне-верхнего разветвления левой ножки пучка Гиса";
	}
}

bool Hypertrophia(const WavesData & w1, const WavesData & w2, const WavesData & w3, const std::vector<WavesData> v)
{
	if (Define_hearth_axis(w1, w2, w3) == "Электрическая ось отклонена влево")
	{
		bool hyp = 1;
		for (int i = 0; i < v.size() - 1; i++)
		{
			hyp = v[i].heights()[2] < v[i + 1].heights()[2] && abs(v[i].heights()[3]) > abs(v[i + 1].heights()[3]) && v[i].lengths()[0] > 1.5;
		}

		if (hyp)
			return "Гипертрофия левых отделов сердца";
	}

	return "";
}

//Parse string from data file to get 6 double digits from it
void WavesData::parse_string(string & s)
{
	int del_pos = s.find_first_of(";") + 1;
	s.erase(s.begin(), s.begin() + del_pos);
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