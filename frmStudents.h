#pragma once

namespace SchoolClinic360 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class frmStudents : public Form {
    public:
        frmStudents(void) {
            InitializeComponent();
            LoadStudents();
        }

    protected:
        ~frmStudents() {
            if (components) {
                delete components;
            }
        }

    private:
        DataGridView^ dgvStudents;
        Button^ btnAdd;
        Button^ btnEdit;
        Button^ btnDelete;
        Button^ btnClose;
        System::ComponentModel::Container^ components;

        void InitializeComponent(void) {
            this->SuspendLayout();

            this->Text = L"Manage Students";
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->ClientSize = System::Drawing::Size(900, 500);
            this->StartPosition = FormStartPosition::CenterScreen;
            this->BackColor = System::Drawing::Color::WhiteSmoke;

            dgvStudents = gcnew DataGridView();
            dgvStudents->Location = System::Drawing::Point(10, 50);
            dgvStudents->Size = System::Drawing::Size(880, 350);
            dgvStudents->AllowUserToAddRows = false;
            dgvStudents->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
            this->Controls->Add(dgvStudents);

            btnAdd = gcnew Button();
            btnAdd->Text = L"Add Student";
            btnAdd->Location = System::Drawing::Point(10, 410);
            btnAdd->Size = System::Drawing::Size(100, 30);
            btnAdd->Click += gcnew System::EventHandler(this, &frmStudents::btnAdd_Click);
            this->Controls->Add(btnAdd);

            btnEdit = gcnew Button();
            btnEdit->Text = L"Edit";
            btnEdit->Location = System::Drawing::Point(120, 410);
            btnEdit->Size = System::Drawing::Size(100, 30);
            btnEdit->Click += gcnew System::EventHandler(this, &frmStudents::btnEdit_Click);
            this->Controls->Add(btnEdit);

            btnDelete = gcnew Button();
            btnDelete->Text = L"Delete";
            btnDelete->Location = System::Drawing::Point(230, 410);
            btnDelete->Size = System::Drawing::Size(100, 30);
            btnDelete->Click += gcnew System::EventHandler(this, &frmStudents::btnDelete_Click);
            this->Controls->Add(btnDelete);

            btnClose = gcnew Button();
            btnClose->Text = L"Close";
            btnClose->Location = System::Drawing::Point(790, 410);
            btnClose->Size = System::Drawing::Size(100, 30);
            btnClose->Click += gcnew System::EventHandler(this, &frmStudents::btnClose_Click);
            this->Controls->Add(btnClose);

            this->ResumeLayout(false);
        }

        void LoadStudents() {
            dgvStudents->DataSource = nullptr;
            dgvStudents->DataSource = DataStore::Students;
        }

        System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e) {
            Student^ student = gcnew Student();
            student->Id = DataStore::Students->Count + 1;
            student->Name = "New Student";
            student->Grade = "G1-A";
            student->BloodType = "O+";
            student->Conditions = "None";
            student->Allergies = "None";
            student->ParentName = "Parent Name";
            student->Contact = "0000000000";

            DataStore::Students->Add(student);
            LoadStudents();
            MessageBox::Show("Student added successfully!");
        }

        System::Void btnEdit_Click(System::Object^ sender, System::EventArgs^ e) {
            if (dgvStudents->SelectedRows->Count > 0) {
                MessageBox::Show("Edit functionality would open a detail form.");
            } else {
                MessageBox::Show("Please select a student to edit.");
            }
        }

        System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
            if (dgvStudents->SelectedRows->Count > 0) {
                int index = dgvStudents->SelectedRows[0]->Index;
                DataStore::Students->RemoveAt(index);
                LoadStudents();
                MessageBox::Show("Student deleted!");
            } else {
                MessageBox::Show("Please select a student to delete.");
            }
        }

        System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
            this->Close();
        }
    };
}
