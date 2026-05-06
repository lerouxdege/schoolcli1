#pragma once
#include "frmStudents.h"
#include "frmVisit.h"
#include "frmQueue.h"
#include "frmInventory.h"
#include "frmReports.h"
#include "frmUsers.h"
#include "SessionManager.h"
#include "DataStore.h"

namespace SchoolClinic360 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class frmMain : public Form {
    public:
        frmMain(void) {
            InitializeComponent();
        }

    protected:
        ~frmMain() {
            if (components) {
                delete components;
            }
        }

    private:
        Button^ btnStudents;
        Button^ btnVisit;
        Button^ btnQueue;
        Button^ btnInventory;
        Button^ btnReports;
        Button^ btnUsers;
        Button^ btnLogout;
        Label^ lblTotalStudents;
        Label^ lblVisitsToday;
        Label^ lblQueueCount;
        Label^ lblLowStock;
        Label^ lblWelcome;
        System::ComponentModel::Container^ components;

        void InitializeComponent(void) {
            this->SuspendLayout();

            this->Text = L"SchoolClinic360 - Dashboard";
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->ClientSize = System::Drawing::Size(800, 600);
            this->StartPosition = FormStartPosition::CenterScreen;
            this->BackColor = System::Drawing::Color::WhiteSmoke;

            lblWelcome = gcnew Label();
            lblWelcome->Text = "Welcome, " + SessionManager::CurrentUser->Username + " (" + SessionManager::CurrentUser->Role + ")";
            lblWelcome->Font = gcnew Font("Arial", 12, FontStyle::Bold);
            lblWelcome->Location = System::Drawing::Point(20, 20);
            lblWelcome->Size = System::Drawing::Size(400, 30);
            this->Controls->Add(lblWelcome);

            btnStudents = gcnew Button();
            btnStudents->Text = L"Students";
            btnStudents->Location = System::Drawing::Point(20, 80);
            btnStudents->Size = System::Drawing::Size(100, 40);
            btnStudents->Click += gcnew System::EventHandler(this, &frmMain::btnStudents_Click);
            this->Controls->Add(btnStudents);

            btnVisit = gcnew Button();
            btnVisit->Text = L"Visits";
            btnVisit->Location = System::Drawing::Point(130, 80);
            btnVisit->Size = System::Drawing::Size(100, 40);
            btnVisit->Click += gcnew System::EventHandler(this, &frmMain::btnVisit_Click);
            this->Controls->Add(btnVisit);

            btnQueue = gcnew Button();
            btnQueue->Text = L"Queue";
            btnQueue->Location = System::Drawing::Point(240, 80);
            btnQueue->Size = System::Drawing::Size(100, 40);
            btnQueue->Click += gcnew System::EventHandler(this, &frmMain::btnQueue_Click);
            this->Controls->Add(btnQueue);

            btnInventory = gcnew Button();
            btnInventory->Text = L"Inventory";
            btnInventory->Location = System::Drawing::Point(350, 80);
            btnInventory->Size = System::Drawing::Size(100, 40);
            btnInventory->Click += gcnew System::EventHandler(this, &frmMain::btnInventory_Click);
            this->Controls->Add(btnInventory);

            btnReports = gcnew Button();
            btnReports->Text = L"Reports";
            btnReports->Location = System::Drawing::Point(460, 80);
            btnReports->Size = System::Drawing::Size(100, 40);
            btnReports->Click += gcnew System::EventHandler(this, &frmMain::btnReports_Click);
            this->Controls->Add(btnReports);

            btnUsers = gcnew Button();
            btnUsers->Text = L"Users";
            btnUsers->Location = System::Drawing::Point(570, 80);
            btnUsers->Size = System::Drawing::Size(100, 40);
            btnUsers->Click += gcnew System::EventHandler(this, &frmMain::btnUsers_Click);
            if (SessionManager::CurrentUser->Role != "Admin") {
                btnUsers->Enabled = false;
            }
            this->Controls->Add(btnUsers);

            lblTotalStudents = gcnew Label();
            lblTotalStudents->Text = "Total Students: " + DataStore::Students->Count;
            lblTotalStudents->Location = System::Drawing::Point(20, 150);
            lblTotalStudents->Size = System::Drawing::Size(200, 30);
            lblTotalStudents->Font = gcnew Font("Arial", 10, FontStyle::Bold);
            this->Controls->Add(lblTotalStudents);

            lblVisitsToday = gcnew Label();
            lblVisitsToday->Text = "Visits Today: " + DataStore::Visits->Count;
            lblVisitsToday->Location = System::Drawing::Point(20, 190);
            lblVisitsToday->Size = System::Drawing::Size(200, 30);
            lblVisitsToday->Font = gcnew Font("Arial", 10, FontStyle::Bold);
            this->Controls->Add(lblVisitsToday);

            lblQueueCount = gcnew Label();
            lblQueueCount->Text = "Queue Count: " + DataStore::Queue->Count;
            lblQueueCount->Location = System::Drawing::Point(20, 230);
            lblQueueCount->Size = System::Drawing::Size(200, 30);
            lblQueueCount->Font = gcnew Font("Arial", 10, FontStyle::Bold);
            this->Controls->Add(lblQueueCount);

            int lowStockCount = 0;
            for each (InventoryItem^ item in DataStore::Inventory) {
                if (item->Quantity < item->MinStock) {
                    lowStockCount++;
                }
            }

            lblLowStock = gcnew Label();
            lblLowStock->Text = "Low Stock Items: " + lowStockCount;
            lblLowStock->Location = System::Drawing::Point(20, 270);
            lblLowStock->Size = System::Drawing::Size(200, 30);
            lblLowStock->Font = gcnew Font("Arial", 10, FontStyle::Bold);
            if (lowStockCount > 0) {
                lblLowStock->ForeColor = Color::Red;
            }
            this->Controls->Add(lblLowStock);

            btnLogout = gcnew Button();
            btnLogout->Text = L"Logout";
            btnLogout->Location = System::Drawing::Point(680, 20);
            btnLogout->Size = System::Drawing::Size(100, 40);
            btnLogout->BackColor = System::Drawing::Color::Red;
            btnLogout->ForeColor = System::Drawing::Color::White;
            btnLogout->Click += gcnew System::EventHandler(this, &frmMain::btnLogout_Click);
            this->Controls->Add(btnLogout);

            this->ResumeLayout(false);
        }

        System::Void btnStudents_Click(System::Object^ sender, System::EventArgs^ e) {
            frmStudents^ form = gcnew frmStudents();
            form->ShowDialog();
        }

        System::Void btnVisit_Click(System::Object^ sender, System::EventArgs^ e) {
            frmVisit^ form = gcnew frmVisit();
            form->ShowDialog();
        }

        System::Void btnQueue_Click(System::Object^ sender, System::EventArgs^ e) {
            frmQueue^ form = gcnew frmQueue();
            form->ShowDialog();
        }

        System::Void btnInventory_Click(System::Object^ sender, System::EventArgs^ e) {
            frmInventory^ form = gcnew frmInventory();
            form->ShowDialog();
        }

        System::Void btnReports_Click(System::Object^ sender, System::EventArgs^ e) {
            frmReports^ form = gcnew frmReports();
            form->ShowDialog();
        }

        System::Void btnUsers_Click(System::Object^ sender, System::EventArgs^ e) {
            frmUsers^ form = gcnew frmUsers();
            form->ShowDialog();
        }

        System::Void btnLogout_Click(System::Object^ sender, System::EventArgs^ e) {
            SessionManager::Logout();
            this->Close();
        }
    };
}
