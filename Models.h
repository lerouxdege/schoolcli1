#pragma once
using namespace System;
using namespace System::Collections::Generic;

public ref class Student {
public:
    int Id;
    String^ Name;
    String^ Grade;
    String^ BloodType;
    String^ Conditions;
    String^ Allergies;
    String^ ParentName;
    String^ Contact;
};

public ref class Visit {
public:
    Student^ StudentRef;
    double Temperature;
    String^ BloodPressure;
    int Pulse;
    String^ Symptoms;
    String^ Diagnosis;
    String^ Treatment;
    DateTime Time;
};

public ref class QueueEntry {
public:
    Student^ StudentRef;
    String^ Complaint;
    DateTime ArrivalTime;
    String^ Status;
    String^ Priority;
};

public ref class InventoryItem {
public:
    String^ Name;
    String^ Category;
    int Quantity;
    int MinStock;
    DateTime Expiry;
};

public ref class User {
public:
    String^ Username;
    String^ Password;
    String^ Role;
};