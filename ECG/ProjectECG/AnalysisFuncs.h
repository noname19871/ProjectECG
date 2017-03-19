#ifndef ANALYSIS_FUNCS_H
#define ANALYSIS_FUNCS_H

#include <iostream>
#include <algorithm>
#include <vector>

class WavesData {

	struct Wave
	{
		double length;
		double height;
		double pos;
	};

	std::vector<Wave> Waves;

public:

	WavesData(std::vector<double> v)
	{		
		for (int i = 0; i < v.size(); i += 3)
		{
			Waves.push_back({ v[i],v[i + 1],v[i + 2] });
		}
	}

};





#endif
