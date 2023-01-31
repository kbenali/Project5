#include"MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project4::MyForm myform;

	myform.ShowDialog();
	User^ user = myform.user;
	if (user != nullptr)
	{
		MessageBox::Show("Successfull authentification of" + user->name, "Program.cpp", MessageBoxButtons::OK);
	}
	else
	{
		MessageBox::Show("authentification canceled", "Program.cpp", MessageBoxButtons::OK);

	}



}