#pragma once
#include "Models.h"
using namespace System;
using namespace System::Collections::Generic;

public ref class DataStore abstract sealed {
public:
    static List<Student^>^ Students = gcnew List<Student^>();
    static List<Visit^>^ Visits = gcnew List<Visit^>();
    static List<QueueEntry^>^ Queue = gcnew List<QueueEntry^>();
    static List<InventoryItem^>^ Inventory = gcnew List<InventoryItem^>();
    static List<User^>^ Users = gcnew List<User^>();

    static void Initialize();
};