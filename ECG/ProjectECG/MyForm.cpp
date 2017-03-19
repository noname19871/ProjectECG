#include <vector>

#include "MyForm.h"
#include "DataForm.h"
#include "InterfaceFuncs.h"
#include "AnalysisFuncs.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace std;


//[STAThread]
void Main(/*array<String^>^ args*/)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	ProjectECG::MyForm form;
	
	Application::Run(%form);
}
