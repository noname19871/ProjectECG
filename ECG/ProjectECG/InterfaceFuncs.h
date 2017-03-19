#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <vector>

using namespace System::Windows::Forms;

//Проход по всем TextBox в TableLayoutPanel и их парс в вектор дабл
std::vector<double> ParseDatasIntoDoubleVector(TableLayoutPanel^ pan);

//Сохранение значений полей в файл
void SaveWavesToFile(std::vector<double> v);

std::vector<double> InitWavesFromFile(std::string filename);

#endif  FUNC_H