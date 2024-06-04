#include "RegistroVehicular.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void Main(cli::array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	RegistroVehicularVentana::RegistroVehicular form;
	Application::Run(% form);
}


