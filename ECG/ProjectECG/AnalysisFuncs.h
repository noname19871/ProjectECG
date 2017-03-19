#ifndef ANALYSIS_FUNCS_H
#define ANALYSIS_FUNCS_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

//Класс для хранения общей информации об ЭКГ и о втором стандартном отведении в частности
class WavesData {
	
	//Вектор для хранения высот зубцов
	std::vector<double> heights;

	//Вектор для хранения длин зубцов
	std::vector<double> lengths;

	//Вектор для хранения позиций зубцов
	std::vector<double> poses;

	//Вектор для хранения длины интервалов
	std::vector<double> intervals;

	//Поле для скорости ленты
	double speed;


public:

	//Конструктор копии для класса WavesData
	WavesData(WavesData & other) :heights(other.heights), lengths(other.lengths), poses(other.poses) {};

	//Конструкток класса WavesData - инициализирует поля класса тремя векторами, содержащими высоты, длины и позиции зубцов
	WavesData(std::vector<double> h, std::vector<double> l, std::vector<double> p) :heights(h), lengths(l), poses(p) {}

	//Конструктор класса WavesData - инициализирует поля класса значениями из файла с именем filename
	WavesData(std::string filename)
	{
		std::ifstream fin(filename);

		std::string l = "";
		std::string h = "";
		std::string p = "";

		getline(fin, h);
		getline(fin, l);
		getline(fin, p);

		std::vector<double> res;

		std::istringstream is1(h);
		double tmp = 0.0;
		while (is1 >> tmp)
			heights.push_back(tmp);

		std::istringstream is2(l);
		while (is2 >> tmp)
			lengths.push_back(tmp);

		std::istringstream is3(p);
		while (is3 >> tmp)
			poses.push_back(tmp);

	}

	//Функция проверки наличия аритмии у пациента
	bool Check_arrhythmia();
};





#endif
