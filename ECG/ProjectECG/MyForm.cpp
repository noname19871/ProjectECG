#include "MyForm.h"
#include "func.h"
#include <algorithm>

using namespace System;
using namespace System::Windows::Forms;
//Своя функция, конкретно тут сложение все элементов компонентов в групповом окне
//В данном примере из текстовых окон группового окна парсится текст в целочисленные значения и вовзращает их целочисленную сумму
int myFunc(GroupBox^ gb)
{
	int sum = 0;
	for (int i = 0; i < gb->Controls->Count; i++)
	{
		if (gb->Controls[i]->Text != "") 
		sum += System::Convert::ToInt32(gb->Controls[i]->Text);
	}
	return sum;
}


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	ProjectECG::MyForm form;
	Application::Run(%form);
}
