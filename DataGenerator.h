#pragma once
#include "Models.h"
#include "DataStore.h"
using namespace System;
using namespace System::Collections::Generic;

public ref class DataGenerator abstract sealed {
public:
    static void GenerateStudents(int count);
    static void GenerateInventory();
    static void GenerateQueue();
    static void GenerateUsers();

private:
    static array<String^>^ FirstNames;
    static array<String^>^ LastNames;
    static array<String^>^ Grades;
    static array<String^>^ BloodTypes;
    static array<String^>^ Conditions;
    static array<String^>^ Allergies;
    static array<String^>^ Medicines;
    static array<String^>^ InventoryCategories;
    static Random^ rnd;
};