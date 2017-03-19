#include <iostream>

#include "AnalysisFuncs.h"

using namespace std;

//Функция проверки наличия аритмии у пациента
bool WavesData::Check_arrhythmia()
{
	return heights[0] == 0.0;
}