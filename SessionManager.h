#pragma once
#include "Models.h"
using namespace System;

public ref class SessionManager abstract sealed {
public:
    static User^ CurrentUser = nullptr;
    static DateTime LoginTime = DateTime::MinValue;

    static bool Login(String^ username, String^ password);
    static void Logout();
    static bool IsLoggedIn();
};