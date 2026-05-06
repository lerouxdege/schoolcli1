#pragma once

namespace SchoolClinic360 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class frmQueue : public Form {
    public:
        frmQueue(void) {
            InitializeComponent();
            LoadQueue();
        }

    protected:
        ~frmQueue() {
            if (components) {
                delete components;
            }
        }

    private:
        DataGridView^ dgvQueue;
        Button^ btnAddToQueue;
        Button^ btnInProgress;
        Button^ btnComplete;
        Button^ btnRemove;
        Button^ btnClose;
        System::ComponentModel::Container^ components;

        void InitializeComponent(void) {
            this->SuspendLayout();

            this->Text = L"Queue Management";
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->ClientSize = System::Drawing::Size(900, 500);
            this->StartPosition = FormStartPosition::CenterScreen;
            this->BackColor = System::Drawing::Color::WhiteSmoke;

            dgvQueue = gcnew DataGridView();
            dgvQueue->Location = System::Drawing::Point(10, 50);
            dgvQueue->Size = System::Drawing::Size(880, 350);
            dgvQueue->AllowUserToAddRows = false;
            dgvQueue->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
            this->Controls->Add(dgvQueue);

            btnAddToQueue = gcnew Button();
            btnAddToQueue->Text = L"Add to Queue";
            btnAddToQueue->Location = System::Drawing::Point(10, 410);
            btnAddToQueue->Size = System::Drawing::Size(120, 30);
            btnAddToQueue->Click += gcnew System::EventHandler(this, &frmQueue::btnAddToQueue_Click);
            this->Controls->Add(btnAddToQueue);

            btnInProgress = gcnew Button();
            btnInProgress->Text = L"In Progress";
            btnInProgress->Location = System::Drawing::Point(140, 410);
            btnInProgress->Size = System::Drawing::Size(120, 30);
            btnInProgress->Click += gcnew System::EventHandler(this, &frmQueue::btnInProgress_Click);
            this->Controls->Add(btnInProgress);

            btnComplete = gcnew Button();
            btnComplete->Text = L"Complete";
            btnComplete->Location = System::Drawing::Point(270, 410);
            btnComplete->Size = System::Drawing::Size(120, 30);
            btnComplete->Click += gcnew System::EventHandler(this, &frmQueue::btnComplete_Click);
            this->Controls->Add(btnComplete);

            btnRemove = gcnew Button();
            btnRemove->Text = L"Remove";
            btnRemove->Location = System::Drawing::Point(400, 410);
            btnRemove->Size = System::Drawing::Size(120, 30);
            btnRemove->Click += gcnew System::EventHandler(this, &frmQueue::btnRemove_Click);
            this->Controls->Add(btnRemove);

            btnClose = gcnew Button();
            btnClose->Text = L"Close";
            btnClose->Location = System::Drawing::Point(790, 410);
            btnClose->Size = System::Drawing::Size(100, 30);
            btnClose->Click += gcnew System::EventHandler(this, &frmQueue::btnClose_Click);
            this->Controls->Add(btnClose);

            this->ResumeLayout(false);
        }

        void LoadQueue() {
            dgvQueue->DataSource = nullptr;
            dgvQueue->DataSource = DataStore::Queue;
        }

        System::Void btnAddToQueue_Click(System::Object^ sender, System::EventArgs^ e) {
            if (DataStore::Students->Count > 0) {
                Random^ rnd = gcnew Random();
                QueueEntry^ entry = gcnew QueueEntry();
                entry->StudentRef = DataStore::Students[rnd->Next(DataStore::Students->Count)];
                entry->Complaint = "General Checkup";
                entry->ArrivalTime = DateTime::Now;
                entry->Status = "Waiting";
                entry->Priority = (rnd->Next(0, 10) > 7) ? "Urgent" : "Normal";

                DataStore::Queue->Add(entry);
                LoadQueue();
                MessageBox::Show("Student added to queue!");
            }
        }

        System::Void btnInProgress_Click(System::Object^ sender, System::EventArgs^ e) {
            if (dgvQueue->SelectedRows->Count > 0) {
                int index = dgvQueue->SelectedRows[0]->Index;
                DataStore::Queue[index]->Status = "In Progress";
                LoadQueue();
                MessageBox::Show("Status updated!");
            } else {
                MessageBox::Show("Please select a queue entry!");
            }
        }

        System::Void btnComplete_Click(System::Object^ sender, System::EventArgs^ e) {
            if (dgvQueue->SelectedRows->Count > 0) {
                int index = dgvQueue->SelectedRows[0]->Index;
                DataStore::Queue[index]->Status = "Done";
                LoadQueue();
                MessageBox::Show("Queue entry completed!");
            } else {
                MessageBox::Show("Please select a queue entry!");
            }
        }

        System::Void btnRemove_Click(System::Object^ sender, System::EventArgs^ e) {
            if (dgvQueue->SelectedRows->Count > 0) {
                int index = dgvQueue->SelectedRows[0]->Index;
                DataStore::Queue->RemoveAt(index);
                LoadQueue();
                MessageBox::Show("Queue entry removed!");
            } else {
                MessageBox::Show("Please select a queue entry!");
            }
        }

        System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
            this->Close();
        }
    };
}
