#ifndef FUNC_H
#define FUNC_H
using namespace System::Windows::Forms;
#include<iostream>
#include<vector>
//Своя функция, конкретно тут сложение все элементов компонентов в групповом окне
//В данном примере из текстовых окон группового окна парсится текст в целочисленные значения и вовзращает их целочисленную сумму
int myFunc(Panel^ gb);

//Проход по всем TextBox в TableLayoutPanel и их парс в вектор дабл
std::vector<double>& ParseDatasIntoDoubleVector(TableLayoutPanel^ pan);

#endif  FUNC_H