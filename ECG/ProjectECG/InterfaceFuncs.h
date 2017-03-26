#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <vector>
#include <fstream>

using namespace System::Windows::Forms;
using namespace std;


//Проход по всем TextBox в TableLayoutPanel и их парс в вектор дабл
std::vector<double> ParseDatasIntoDoubleVector(TableLayoutPanel^ pan);

//Сохранение значений полей в файл
void SaveWavesToFile(std::vector<double> v);

//Закрывает файл с данными зубцов
void close_file();

//Очищает файл с данными зубцов перед дальнейшим использованием
void clear_file();

//Записывает строку s в файл с данными зубцов
void write_s(char *s);

#endif  FUNC_H