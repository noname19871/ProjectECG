#ifndef ANALYSIS_FUNCS_H
#define ANALYSIS_FUNCS_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>


//This class is for holding information about ECG and about second standart diversion concretly
class WavesData {
	
	//Storage for heights of waves
	std::vector<double> _heights;

	//Storage for lengths of waves
	std::vector<double> _lengths;

	//Storage for starting positions of waves
	std::vector<double> _poses;

	//Storage for lengths of intervals
	std::vector<double> _intervals;

	//ECG tape`s speed
	double _speed;


public:


	//Copy constructor
	WavesData(WavesData & other) :_heights(other._heights), _lengths(other._lengths), _poses(other._poses), _intervals(other._intervals), _speed(other._speed) {};

	//It initializes class`s fields by values from vectors h,l and p, which hold values of lengths, heights and poses of waves respectively
	WavesData(std::vector<double> h, std::vector<double> l, std::vector<double> p, std::vector<double> i, double s) :_heights(h), _lengths(l), _poses(p), _intervals(i), _speed(s) {}

	//It initializes class`s fields by values from file 
	WavesData(std::string filename)
	{
		std::ifstream fin(filename);

		std::string firstline = "";
		std::string h = "";
		std::string l = "";
		std::string p = "";
		std::string i = "";

		getline(fin, firstline);
		getline(fin, h);
		getline(fin, l);
		getline(fin, p);
		getline(fin, i);

		std::istringstream is1(h);
		double tmp = 0.0;
		is1 >> tmp;
		while (is1 >> tmp)

			_heights.push_back(tmp);

		std::istringstream is2(l);
		is2 >> tmp;
		while (is2 >> tmp)
			_lengths.push_back(tmp);

		std::istringstream is3(p);
		is3 >> tmp;
		while (is3 >> tmp)
			_poses.push_back(tmp);

		std::istringstream is4(i);
		is4 >> tmp;
		for (int i = 0; i < 2; i++)
		{
			is4 >> tmp;
			_intervals.push_back(tmp);
		}
		is4 >> _speed;
	}

	std::vector<double> heights() const {
		return _heights;
	}

	std::vector<double> lengths() const {
		return _lengths;
	}

	std::vector<double> poses() const {
		return _poses;
	}

	std::vector<double> intervals() const {
		return _intervals;
	}

	double speed() const {
		return _speed;
	}

	//It checks patient`s heart for arrhythmia
	bool Check_arrhythmia();

	//return patient`s hearth rate
	double count_heart_rate();

	//It checks patient`s hearth rate for Bradycardia
	bool Check_Bradycardia();

	//It checks patient`s hearth rate for Tachycardia
	bool Check_Tachycardia();

	//Return hearth axis`s position
	friend System::String^ Define_hearth_axis(const WavesData & w1, const WavesData & w2, const WavesData & w3);

	//It checks patient for back myocardial
	bool Check_back_myocardial(const WavesData & w3, const WavesData & aVF);
};





#endif
