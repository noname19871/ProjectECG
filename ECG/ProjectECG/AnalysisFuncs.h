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

	//Storage for lengths of R-R intervals
	std::vector<double> _RR_intervals;

	//height of ST_interval
	double _ST_interval;

	//ECG tape`s speed
	double _speed;

	std::vector<bool> _is_waves_empty;
protected:

	//Parse string from data file to get 6 double digits from it
	void parse_string(std::string & s);

	//Return number of diversion in data file
	int define_diversion(System::String^ s);

public:


	//Copy constructor
	WavesData(WavesData & other) :_heights(other._heights), _lengths(other._lengths), _poses(other._poses), _RR_intervals(other._RR_intervals), _speed(other._speed) { fill_is_empty(); };

	//It initializes class`s fields by values from vectors h,l and p, which hold values of lengths, heights and poses of waves respectively
	WavesData(std::vector<double> h, std::vector<double> l, std::vector<double> p, std::vector<double> i, double s) :_heights(h), _lengths(l), _poses(p), _RR_intervals(i), _speed(s) { fill_is_empty(); }

	//It initializes class`s fields by values from file 
	WavesData(std::string filename, System::String^ s)
	{
		std::ifstream fin(filename, std::ios::in);

		std::string s1 = "";
		std::string s2 = "";
		std::string s3 = "";

		getline(fin, s1);
		parse_string(s1);

		double tmp = 0.0;
		std::istringstream is4(s1);
		for (int i = 0; i < 2; i++)
		{
			is4 >> tmp;
			_RR_intervals.push_back(tmp);
		}
		is4 >> s2;
		is4 >> _speed;

		for (int i = 0; i < 6 * define_diversion(s); i++)
			getline(fin, s1);

		getline(fin, s1);
		getline(fin, s1);
		getline(fin, s2);
		getline(fin, s3);

		
		parse_string(s1);
		parse_string(s2);
		parse_string(s3);

		std::istringstream is1(s1);
		std::istringstream is2(s2);
		std::istringstream is3(s3);

		double tmp2, tmp3;
		while (is1 >> tmp && is2 >> tmp2 && is3 >> tmp3)
		{
			_heights.push_back(tmp);
			_lengths.push_back(tmp2);
			_poses.push_back(tmp3);
		}
		
		getline(fin, s1);
		parse_string(s1);
		std::istringstream is5(s1);
		is5 >> _ST_interval;
		fin.close();

		fill_is_empty();
	}

	//Getter for heights vector
	std::vector<double> heights() const {
		return _heights;
	}

	//Getter for lengths vector
	std::vector<double> lengths() const {
		return _lengths;
	}

	//Getter for poses vector
	std::vector<double> poses() const {
		return _poses;
	}

	//Getter for intervals vector
	std::vector<double> RR_intervals() const {
		return _RR_intervals;
	}

	//Getter for speed
	double speed() const {
		return _speed;
	}

	double ST_interval() const {
		return _ST_interval;
	}

	std::vector<bool> is_waves_empty() const {
		return _is_waves_empty;
	}

	void fill_is_empty();

	int next_wave(int x) const
	{
		{
			int next = x;
			for (int i = x; i < is_waves_empty().size(); i++)
				if (!is_waves_empty()[i] && i != next)
				{
					next = i;
					break;
				}

			return next;
		}
	}


	//Return true if all vectors contain only 0
	bool empty() const
	{
		return is_waves_empty()[0] && is_waves_empty()[1] && is_waves_empty()[2] && is_waves_empty()[3] && is_waves_empty()[4];
	}


	//It checks patient`s heart for arrhythmia
	System::String^ Check_arrhythmia();

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

	System::String^ Right_blockade(const WavesData & w1, const WavesData & w2, const WavesData & w3, const WavesData & v1); 

	System::String^ Left_blockade(const WavesData & w1, const WavesData & w2, const WavesData & w3, const WavesData & aVR, const std::vector<WavesData> v);

	bool Hypertrophia(const WavesData & w1, const WavesData & w2, const WavesData & w3, const std::vector<WavesData> v);
};







#endif
