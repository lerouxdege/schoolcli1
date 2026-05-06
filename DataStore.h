#pragma once
#include "Models.h"
using namespace System;
using namespace System::Collections::Generic;

public ref class DataStore abstract sealed {
public:
    static List<Student^>^ Students;
    static List<Visit^>^ Visits;
    static List<QueueEntry^>^ Queue;
    static List<InventoryItem^>^ Inventory;
    static List<User^>^ Users;

    static void Initialize();
};