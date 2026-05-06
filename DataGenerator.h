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
};