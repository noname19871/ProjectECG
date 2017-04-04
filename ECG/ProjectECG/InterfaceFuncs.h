#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <vector>
#include <fstream>

#include "AnalysisFuncs.h"

// Parse TextBoxes in TLP and add them to vector<double>
// size - count of TextBoxes
std::vector<double> ParseDatasIntoDoubleVector(System::Windows::Forms::TableLayoutPanel^ p, int size);

//It resets textboxes in TableLayoutPanel^ p to value "";
void ResetTextboxesInDataTable(System::Windows::Forms::TableLayoutPanel^ p);

void SaveInFile(std::string filename, std::string diversion_name, std::vector<double> v, std::string vector_name);

void PrepareFile(std::string filename);

//It saves values from vector to csv file 
void SaveWavesToFile(std::vector<double> v, std::string filename, std::string vector_name, int pos);

//It draws grid for ECG graphic
void DrawGrid(System::Drawing::Graphics^ g, int width, int height);

//It draws ECG graphic on PictureBox
void DrawGraphic(System::Drawing::Graphics^ g, int width, int height, const WavesData & w);

#endif  FUNC_H