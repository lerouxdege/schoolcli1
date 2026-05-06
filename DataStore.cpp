#include "DataStore.h"

List<Student^>^ DataStore::Students;
List<Visit^>^ DataStore::Visits;
List<QueueEntry^>^ DataStore::Queue;
List<InventoryItem^>^ DataStore::Inventory;
List<User^>^ DataStore::Users;

void DataStore::Initialize() {
    Students = gcnew List<Student^>();
    Visits = gcnew List<Visit^>();
    Queue = gcnew List<QueueEntry^>();
    Inventory = gcnew List<InventoryItem^>();
    Users = gcnew List<User^>();
}