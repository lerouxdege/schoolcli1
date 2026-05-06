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

    Student() {
        Id = 0;
        Name = "";
        Grade = "";
        BloodType = "";
        Conditions = "";
        Allergies = "";
        ParentName = "";
        Contact = "";
    }
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

    Visit() {
        StudentRef = nullptr;
        Temperature = 0.0;
        BloodPressure = "";
        Pulse = 0;
        Symptoms = "";
        Diagnosis = "";
        Treatment = "";
        Time = DateTime::Now;
    }
};

public ref class QueueEntry {
public:
    Student^ StudentRef;
    String^ Complaint;
    DateTime ArrivalTime;
    String^ Status;
    String^ Priority;

    QueueEntry() {
        StudentRef = nullptr;
        Complaint = "";
        ArrivalTime = DateTime::Now;
        Status = "Waiting";
        Priority = "Normal";
    }
};

public ref class InventoryItem {
public:
    String^ Name;
    String^ Category;
    int Quantity;
    int MinStock;
    DateTime Expiry;

    InventoryItem() {
        Name = "";
        Category = "";
        Quantity = 0;
        MinStock = 5;
        Expiry = DateTime::Now;
    }
};

public ref class User {
public:
    String^ Username;
    String^ Password;
    String^ Role;

    User() {
        Username = "";
        Password = "";
        Role = "";
    }
};