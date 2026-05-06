#include "SessionManager.h"
#include "DataStore.h"

bool SessionManager::Login(String^ username, String^ password) {
    for each (User^ user in DataStore::Users) {
        if (user->Username == username && user->Password == password) {
            CurrentUser = user;
            LoginTime = DateTime::Now;
            return true;
        }
    }
    return false;
}

void SessionManager::Logout() {
    CurrentUser = nullptr;
    LoginTime = DateTime::MinValue;
}

bool SessionManager::IsLoggedIn() {
    return CurrentUser != nullptr;
}