#include <windows.h>
#include "frmLogin.h"
#include "DataStore.h"
#include "DataGenerator.h"

using namespace SchoolClinic360;
using namespace System;

[STAThreadAttribute]
int main(array<String^>^ args)
{
    // Generate random data
    DataGenerator::GenerateStudents(20);
    DataGenerator::GenerateInventory();
    DataGenerator::GenerateUsers();
    DataGenerator::GenerateQueue();

    // Enable visual styles
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Show login form
    frmLogin^ loginForm = gcnew frmLogin();
    Application::Run(loginForm);

    return 0;
}