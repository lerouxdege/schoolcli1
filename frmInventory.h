#pragma once

namespace SchoolClinic360 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class frmInventory : public Form {
    public:
        frmInventory(void) {
            InitializeComponent();
            LoadInventory();
        }

    protected:
        ~frmInventory() {
            if (components) {
                delete components;
            }
        }

    private:
        DataGridView^ dgvInventory;
        Button^ btnAdd;
        Button^ btnEdit;
        Button^ btnDelete;
        Button^ btnClose;
        System::ComponentModel::Container^ components;

        void InitializeComponent(void) {
            this->SuspendLayout();

            this->Text = L"Inventory Management";
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->ClientSize = System::Drawing::Size(900, 500);
            this->StartPosition = FormStartPosition::CenterScreen;
            this->BackColor = System::Drawing::Color::WhiteSmoke;

            dgvInventory = gcnew DataGridView();
            dgvInventory->Location = System::Drawing::Point(10, 50);
            dgvInventory->Size = System::Drawing::Size(880, 350);
            dgvInventory->AllowUserToAddRows = false;
            dgvInventory->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
            this->Controls->Add(dgvInventory);

            btnAdd = gcnew Button();
            btnAdd->Text = L"Add Item";
            btnAdd->Location = System::Drawing::Point(10, 410);
            btnAdd->Size = System::Drawing::Size(100, 30);
            btnAdd->Click += gcnew System::EventHandler(this, &frmInventory::btnAdd_Click);
            this->Controls->Add(btnAdd);

            btnEdit = gcnew Button();
            btnEdit->Text = L"Edit";
            btnEdit->Location = System::Drawing::Point(120, 410);
            btnEdit->Size = System::Drawing::Size(100, 30);
            btnEdit->Click += gcnew System::EventHandler(this, &frmInventory::btnEdit_Click);
            this->Controls->Add(btnEdit);

            btnDelete = gcnew Button();
            btnDelete->Text = L"Delete";
            btnDelete->Location = System::Drawing::Point(230, 410);
            btnDelete->Size = System::Drawing::Size(100, 30);
            btnDelete->Click += gcnew System::EventHandler(this, &frmInventory::btnDelete_Click);
            this->Controls->Add(btnDelete);

            btnClose = gcnew Button();
            btnClose->Text = L"Close";
            btnClose->Location = System::Drawing::Point(790, 410);
            btnClose->Size = System::Drawing::Size(100, 30);
            btnClose->Click += gcnew System::EventHandler(this, &frmInventory::btnClose_Click);
            this->Controls->Add(btnClose);

            this->ResumeLayout(false);
        }

        void LoadInventory() {
            dgvInventory->DataSource = nullptr;
            dgvInventory->DataSource = DataStore::Inventory;
        }

        System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e) {
            InventoryItem^ item = gcnew InventoryItem();
            item->Name = "New Item";
            item->Category = "Medicine";
            item->Quantity = 10;
            item->MinStock = 5;
            item->Expiry = DateTime::Now.AddMonths(6);

            DataStore::Inventory->Add(item);
            LoadInventory();
            MessageBox::Show("Item added successfully!");
        }

        System::Void btnEdit_Click(System::Object^ sender, System::EventArgs^ e) {
            if (dgvInventory->SelectedRows->Count > 0) {
                MessageBox::Show("Edit functionality would open a detail form.");
            } else {
                MessageBox::Show("Please select an item to edit.");
            }
        }

        System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
            if (dgvInventory->SelectedRows->Count > 0) {
                int index = dgvInventory->SelectedRows[0]->Index;
                DataStore::Inventory->RemoveAt(index);
                LoadInventory();
                MessageBox::Show("Item deleted!");
            } else {
                MessageBox::Show("Please select an item to delete.");
            }
        }

        System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
            this->Close();
        }
    };
}
