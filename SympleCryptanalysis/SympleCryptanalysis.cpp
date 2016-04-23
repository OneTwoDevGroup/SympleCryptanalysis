#include "WordProcessing.h"
#include "FrequencyAnalysis.h"
#include "LinguisticAnalysis.h"
#include "IndexOfÑoincidence.h"
#include "KasiskiExamination.h"
#include "SympleCryptanalysis.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	SympleCryptanalysis::MyForm form;
	Application::Run(%form);
}
