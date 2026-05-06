#pragma once

namespace SchoolClinic360 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class frmUsers : public Form {
    public:
        frmUsers(void) {
            InitializeComponent();
            LoadUsers();
        }

    protected:
        ~frmUsers() {
            if (components) {
                delete components;
            }
        }

    private:
        DataGridView^ dgvUsers;
        Button^ btnAdd;
        Button^ btnDelete;
        Button^ btnClose;
        System::ComponentModel::Container^ components;

        void InitializeComponent(void) {
            this->SuspendLayout();

            this->Text = L"User Management";
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->ClientSize = System::Drawing::Size(700, 500);
            this->StartPosition = FormStartPosition::CenterScreen;
            this->BackColor = System::Drawing::Color::WhiteSmoke;

            dgvUsers = gcnew DataGridView();
            dgvUsers->Location = System::Drawing::Point(10, 50);
            dgvUsers->Size = System::Drawing::Size(680, 350);
            dgvUsers->AllowUserToAddRows = false;
            dgvUsers->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
            this->Controls->Add(dgvUsers);

            btnAdd = gcnew Button();
            btnAdd->Text = L"Add User";
            btnAdd->Location = System::Drawing::Point(10, 410);
            btnAdd->Size = System::Drawing::Size(100, 30);
            btnAdd->Click += gcnew System::EventHandler(this, &frmUsers::btnAdd_Click);
            this->Controls->Add(btnAdd);

            btnDelete = gcnew Button();
            btnDelete->Text = L"Delete";
            btnDelete->Location = System::Drawing::Point(120, 410);
            btnDelete->Size = System::Drawing::Size(100, 30);
            btnDelete->Click += gcnew System::EventHandler(this, &frmUsers::btnDelete_Click);
            this->Controls->Add(btnDelete);

            btnClose = gcnew Button();
            btnClose->Text = L"Close";
            btnClose->Location = System::Drawing::Point(600, 410);
            btnClose->Size = System::Drawing::Size(90, 30);
            btnClose->Click += gcnew System::EventHandler(this, &frmUsers::btnClose_Click);
            this->Controls->Add(btnClose);

            this->ResumeLayout(false);
        }

        void LoadUsers() {
            dgvUsers->DataSource = nullptr;
            dgvUsers->DataSource = DataStore::Users;
        }

        System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e) {
            User^ user = gcnew User();
            user->Username = "newuser";
            user->Password = "password";
            user->Role = "Teacher";

            DataStore::Users->Add(user);
            LoadUsers();
            MessageBox::Show("User added successfully!");
        }

        System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
            if (dgvUsers->SelectedRows->Count > 0) {
                int index = dgvUsers->SelectedRows[0]->Index;
                DataStore::Users->RemoveAt(index);
                LoadUsers();
                MessageBox::Show("User deleted!");
            } else {
                MessageBox::Show("Please select a user to delete.");
            }
        }

        System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
            this->Close();
        }
    };
}
