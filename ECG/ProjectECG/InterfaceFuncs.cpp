#include <iostream>
#include <cstring>

#include "InterfaceFuncs.h"

using namespace System;
using namespace System::Windows::Forms;

//Своя функция, конкретно тут сложение все элементов компонентов в групповом окне
//В данном примере из текстовых окон группового окна парсится текст в целочисленные значения и вовзращает их целочисленную сумму
int myFunc(Panel^ gb)
{
	int sum = 0;
	for (int i = 0; i < gb->Controls->Count; i++)
	{
		if (gb->Controls[i]->Text != "")
			sum += System::Convert::ToInt32(gb->Controls[i]->Text);
	}
	return sum;
}
//Проход по всем TextBox в TableLayoutPanel и их парс в вектор дабл
std::vector<double>& ParseDatasIntoDoubleVector(TableLayoutPanel^ pan)
{

	std::vector<double> res(18, 0.0);
	int j = 0;

	String^ st1 = "textBox";
	auto st = gcnew String("textBox");

	for (int i = 0; i<pan->Controls->Count; i++)
	{
		auto ST = pan->Controls[i]->Name;
		auto flag = ST->Contains(st1);

		if (flag)
			if (pan->Controls[i]->Text != "")
			{
				res[j] = System::Convert::ToDouble(pan->Controls[i]->Text);
				j++;
			}
			else ++j;
	}

	return res;


}