#include "MyForm.h"
#include "MiniTip.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main(array<String^>^ args) {

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	WinFormsNewLife::MyForm form;
	// уберём границу рамки
	form.FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
	WinFormsNewLife::MiniTip miniform;
	miniform.FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
	Application::Run(% form);

}
