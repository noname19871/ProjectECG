#include <iostream>

#include "AnalysisFuncs.h"

using namespace std;

//It checks patient`s heart for arrhythmia
bool WavesData::Check_arrhythmia()
{
	return (heights[0] == 0.0) /*&& (intervals[1] != intervals[2])*/;
}

//TODO
//return patient`s hearth rate
double WavesData::count_heart_rate()
{
	return speed == 50 ? 600 / intervals[0] : 300 / intervals[0];
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