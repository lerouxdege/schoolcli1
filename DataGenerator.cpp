#include "DataGenerator.h"

void DataGenerator::GenerateStudents(int count) {
    array<String^>^ FirstNames = gcnew array<String^>{ 
        "John", "Emma", "Michael", "Sarah", "David", "Jessica", "James", "Lisa",
        "Robert", "Maria", "William", "Anna", "Joseph", "Lauren", "Thomas", "Sophie"
    };

    array<String^>^ LastNames = gcnew array<String^>{ 
        "Smith", "Johnson", "Williams", "Brown", "Jones", "Garcia", "Miller", "Davis",
        "Rodriguez", "Martinez", "Hernandez", "Lopez", "Gonzalez", "Wilson", "Anderson", "Taylor"
    };

    array<String^>^ Grades = gcnew array<String^>{ 
        "G1-A", "G1-B", "G2-A", "G2-B", "G3-A", "G3-B", "G4-A", "G4-B",
        "G5-A", "G5-B", "G6-A", "G6-B"
    };

    array<String^>^ BloodTypes = gcnew array<String^>{ 
        "O+", "O-", "A+", "A-", "B+", "B-", "AB+", "AB-"
    };

    array<String^>^ Conditions = gcnew array<String^>{ 
        "None", "Asthma", "Diabetes", "Allergy", "Hypertension", "Migraine"
    };

    array<String^>^ Allergies = gcnew array<String^>{ 
        "None", "Peanut", "Shellfish", "Dairy", "Wheat", "Soy", "Tree Nut"
    };

    Random^ rnd = gcnew Random();

    for (int i = 0; i < count; i++) {
        Student^ student = gcnew Student();
        student->Id = i + 1;
        student->Name = FirstNames[rnd->Next(FirstNames->Length)] + " " + 
                        LastNames[rnd->Next(LastNames->Length)];
        student->Grade = Grades[rnd->Next(Grades->Length)];
        student->BloodType = BloodTypes[rnd->Next(BloodTypes->Length)];
        student->Conditions = Conditions[rnd->Next(Conditions->Length)];
        student->Allergies = Allergies[rnd->Next(Allergies->Length)];
        student->ParentName = FirstNames[rnd->Next(FirstNames->Length)] + " " + 
                              LastNames[rnd->Next(LastNames->Length)];
        student->Contact = String::Format("{0:D10}", rnd->Next(1000000000));

        DataStore::Students->Add(student);
    }
}

void DataGenerator::GenerateInventory() {
    array<String^>^ items = gcnew array<String^>{
        "Paracetamol 500mg", "Ibuprofen 200mg", "Aspirin", "Amoxicillin",
        "Thermometer", "BP Monitor", "First Aid Kit", "Bandages",
        "Cotton Wool", "Syringes", "Ointment A", "Ointment B"
    };

    array<String^>^ InventoryCategories = gcnew array<String^>{ 
        "Medicine", "Equipment", "Supplies", "Bandages", "Ointments"
    };

    Random^ rnd = gcnew Random();

    for (int i = 0; i < items->Length; i++) {
        InventoryItem^ item = gcnew InventoryItem();
        item->Name = items[i];
        item->Category = InventoryCategories[rnd->Next(InventoryCategories->Length)];
        item->Quantity = rnd->Next(5, 100);
        item->MinStock = rnd->Next(3, 10);
        item->Expiry = DateTime::Now.AddMonths(rnd->Next(3, 24));

        DataStore::Inventory->Add(item);
    }
}

void DataGenerator::GenerateQueue() {
    Random^ rnd = gcnew Random();
    int queueSize = rnd->Next(3, 8);
    for (int i = 0; i < queueSize; i++) {
        if (DataStore::Students->Count > 0) {
            QueueEntry^ entry = gcnew QueueEntry();
            entry->StudentRef = DataStore::Students[rnd->Next(DataStore::Students->Count)];
            entry->Complaint = "General Checkup";
            entry->ArrivalTime = DateTime::Now.AddMinutes(-rnd->Next(0, 60));
            entry->Status = "Waiting";
            entry->Priority = (rnd->Next(0, 10) > 7) ? "Urgent" : "Normal";

            DataStore::Queue->Add(entry);
        }
    }
}

void DataGenerator::GenerateUsers() {
    User^ admin = gcnew User();
    admin->Username = "admin";
    admin->Password = "admin";
    admin->Role = "Admin";
    DataStore::Users->Add(admin);

    User^ nurse = gcnew User();
    nurse->Username = "nurse";
    nurse->Password = "nurse";
    nurse->Role = "Nurse";
    DataStore::Users->Add(nurse);

    User^ teacher = gcnew User();
    teacher->Username = "teacher";
    teacher->Password = "teacher";
    teacher->Role = "Teacher";
    DataStore::Users->Add(teacher);

    User^ parent = gcnew User();
    parent->Username = "parent";
    parent->Password = "parent";
    parent->Role = "Parent";
    DataStore::Users->Add(parent);
}