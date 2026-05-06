# SchoolClinic360 - School Clinic Management System

## Overview
SchoolClinic360 is a **Windows Forms C++/CLR desktop application** that simulates a **school clinic management system** using in-memory data with no database required.

## Features
- ✅ **Login System** with role-based access control
- ✅ **Student Management** - Add, edit, delete students
- ✅ **Visit Recording** - Log student clinic visits
- ✅ **Queue Management** - Manage patient queue with priority levels
- ✅ **Inventory Management** - Track clinic supplies and medicines
- ✅ **Reports** - Generate monthly and diagnosis reports
- ✅ **User Management** (Admin only)
- ✅ **Random Data Generation** - Pre-populated demo data

## Project Structure
```
Models.h              // Data model classes
DataStore.h/cpp       // In-memory data storage
DataGenerator.h/cpp   // Random data generation
SessionManager.h/cpp  // User session management
frmLogin.h            // Login form
frmMain.h             // Dashboard/main form
frmStudents.h         // Student management form
frmVisit.h            // Visit recording form
frmQueue.h            // Queue management form
frmInventory.h        // Inventory management form
frmReports.h          // Reports form
frmUsers.h            // User management form
Main.cpp              // Application entry point
```

## Default Login Credentials
- **Admin**: admin / admin
- **Nurse**: nurse / nurse
- **Teacher**: teacher / teacher
- **Parent**: parent / parent

## System Requirements
- Visual Studio 2026 or later
- .NET Framework
- C++/CLR support

## How to Compile
1. Create a new **C++/CLR Windows Forms Project** in Visual Studio 2026
2. Add all `.h` files to the project
3. Add all `.cpp` files to the project
4. Build and run!

## Features by Role

| Feature | Admin | Nurse | Teacher | Parent |
|---------|-------|-------|---------|--------|
| Students | ✅ | ✅ | View | View |
| Visits | ✅ | ✅ | View | View |
| Queue | ✅ | ✅ | — | — |
| Inventory | ✅ | ✅ | — | — |
| Reports | ✅ | ✅ | View | View |
| Users | ✅ | — | — | — |

## Data Storage
All data is stored **in-memory** and resets when the application closes. No database or file storage is used.
