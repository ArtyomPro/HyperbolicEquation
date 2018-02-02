#include "MyForm.h"
#include "HyperbolicEquation.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]

void Main(array<String^>^ args) 
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	HyperE::MyForm form;
	Application::Run(%form);
}

