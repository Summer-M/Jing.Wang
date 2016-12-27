#include "MyForm.h"

using namespace DataVisualization;

[STAThread]

int main()
{
	Application::EnableVisualStyles();
	Application::Run(gcnew MyForm());
}

