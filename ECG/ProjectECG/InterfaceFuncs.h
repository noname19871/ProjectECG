#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <vector>
#include <fstream>

#include "AnalysisFuncs.h"

//Ïðîõîä ïî âñåì TextBox â TableLayoutPanel è èõ ïàðñ â âåêòîð äàáë
std::vector<double> ParseDatasIntoDoubleVector(System::Windows::Forms::TableLayoutPanel^ p, int size);

void PrepareAssignation(std::string filename);

//It saves values from vector to csv file 
void SaveWavesToFile(std::vector<double> v, std::string filename, std::string vector_name);

//It draws grid for ECG graphic
void DrawGrid(System::Drawing::Graphics^ g, int width, int height);

//It draws ECG graphic on PictureBox
void DrawGraphic(System::Drawing::Graphics^ g, int width, int height, const WavesData & w);

//It resets textboxes in TableLayoutPanel^ p to value "";
void ResetTextboxesInDataTable(System::Windows::Forms::TableLayoutPanel^ p);



#endif  FUNC_H