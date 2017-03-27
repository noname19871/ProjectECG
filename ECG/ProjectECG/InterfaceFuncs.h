#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <vector>
#include <fstream>

#include "AnalysisFuncs.h"

using namespace System::Windows::Forms;
using namespace std;


//Ïðîõîä ïî âñåì TextBox â TableLayoutPanel è èõ ïàðñ â âåêòîð äàáë
std::vector<double> ParseDatasIntoDoubleVector(TableLayoutPanel^ p, int size);

//Ñîõðàíåíèå çíà÷åíèé ïîëåé â ôàéë
void SaveWavesToFile(std::vector<double> v);

//Çàêðûâàåò ôàéë ñ äàííûìè çóáöîâ
void close_file();

//Î÷èùàåò ôàéë ñ äàííûìè çóáöîâ ïåðåä äàëüíåéøèì èñïîëüçîâàíèåì
void clear_file();

//Çàïèñûâàåò ñòðîêó s â ôàéë ñ äàííûìè çóáöîâ
void write_s(char *s);

//It draws grid for ECG graphic
void DrawGrid(System::Drawing::Graphics^ g, int width, int height);

//It draws ECG graphic on PictureBox
void DrawGraphic(System::Drawing::Graphics^ g, int width, int height, const WavesData & w);

#endif  FUNC_H