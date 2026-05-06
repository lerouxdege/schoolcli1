#pragma once

namespace SchoolClinic360 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class frmVisit : public Form {
    public:
        frmVisit(void) {
            InitializeComponent();
            LoadStudents();
        }

    protected:
        ~frmVisit() {
            if (components) {
                delete components;
            }
        }

    private:
        ComboBox^ cmbStudents;
        TextBox^ txtTemperature;
        TextBox^ txtBP;
        TextBox^ txtPulse;
        RichTextBox^ rtxSymptoms;
        RichTextBox^ rtxDiagnosis;
        RichTextBox^ rtxTreatment;
        Button^ btnSave;
        Button^ btnClose;
        DataGridView^ dgvVisits;
        Label^ lblStudent;
        Label^ lblTemp;
        Label^ lblBP;
        Label^ lblPulse;
        Label^ lblSymptoms;
        Label^ lblDiagnosis;
        Label^ lblTreatment;
        System::ComponentModel::Container^ components;

        void InitializeComponent(void) {
            this->SuspendLayout();

            this->Text = L"Record Visit";
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->ClientSize = System::Drawing::Size(800, 700);
            this->StartPosition = FormStartPosition::CenterScreen;
            this->BackColor = System::Drawing::Color::WhiteSmoke;

            lblStudent = gcnew Label();
            lblStudent->Text = L"Student:";
            lblStudent->Location = System::Drawing::Point(10, 20);
            lblStudent->Size = System::Drawing::Size(80, 20);
            this->Controls->Add(lblStudent);

            cmbStudents = gcnew ComboBox();
            cmbStudents->Location = System::Drawing::Point(100, 20);
            cmbStudents->Size = System::Drawing::Size(200, 20);
            cmbStudents->DropDownStyle = ComboBoxStyle::DropDownList;
            this->Controls->Add(cmbStudents);

            lblTemp = gcnew Label();
            lblTemp->Text = L"Temperature:";
            lblTemp->Location = System::Drawing::Point(10, 60);
            lblTemp->Size = System::Drawing::Size(80, 20);
            this->Controls->Add(lblTemp);

            txtTemperature = gcnew TextBox();
            txtTemperature->Location = System::Drawing::Point(100, 60);
            txtTemperature->Size = System::Drawing::Size(200, 20);
            this->Controls->Add(txtTemperature);

            lblBP = gcnew Label();
            lblBP->Text = L"Blood Pressure:";
            lblBP->Location = System::Drawing::Point(10, 100);
            lblBP->Size = System::Drawing::Size(80, 20);
            this->Controls->Add(lblBP);

            txtBP = gcnew TextBox();
            txtBP->Location = System::Drawing::Point(100, 100);
            txtBP->Size = System::Drawing::Size(200, 20);
            this->Controls->Add(txtBP);

            lblPulse = gcnew Label();
            lblPulse->Text = L"Pulse:";
            lblPulse->Location = System::Drawing::Point(10, 140);
            lblPulse->Size = System::Drawing::Size(80, 20);
            this->Controls->Add(lblPulse);

            txtPulse = gcnew TextBox();
            txtPulse->Location = System::Drawing::Point(100, 140);
            txtPulse->Size = System::Drawing::Size(200, 20);
            this->Controls->Add(txtPulse);

            lblSymptoms = gcnew Label();
            lblSymptoms->Text = L"Symptoms:";
            lblSymptoms->Location = System::Drawing::Point(10, 180);
            lblSymptoms->Size = System::Drawing::Size(80, 20);
            this->Controls->Add(lblSymptoms);

            rtxSymptoms = gcnew RichTextBox();
            rtxSymptoms->Location = System::Drawing::Point(100, 180);
            rtxSymptoms->Size = System::Drawing::Size(300, 80);
            this->Controls->Add(rtxSymptoms);

            lblDiagnosis = gcnew Label();
            lblDiagnosis->Text = L"Diagnosis:";
            lblDiagnosis->Location = System::Drawing::Point(10, 280);
            lblDiagnosis->Size = System::Drawing::Size(80, 20);
            this->Controls->Add(lblDiagnosis);

            rtxDiagnosis = gcnew RichTextBox();
            rtxDiagnosis->Location = System::Drawing::Point(100, 280);
            rtxDiagnosis->Size = System::Drawing::Size(300, 80);
            this->Controls->Add(rtxDiagnosis);

            lblTreatment = gcnew Label();
            lblTreatment->Text = L"Treatment:";
            lblTreatment->Location = System::Drawing::Point(10, 380);
            lblTreatment->Size = System::Drawing::Size(80, 20);
            this->Controls->Add(lblTreatment);

            rtxTreatment = gcnew RichTextBox();
            rtxTreatment->Location = System::Drawing::Point(100, 380);
            rtxTreatment->Size = System::Drawing::Size(300, 80);
            this->Controls->Add(rtxTreatment);

            btnSave = gcnew Button();
            btnSave->Text = L"Save Visit";
            btnSave->Location = System::Drawing::Point(100, 480);
            btnSave->Size = System::Drawing::Size(100, 30);
            btnSave->Click += gcnew System::EventHandler(this, &frmVisit::btnSave_Click);
            this->Controls->Add(btnSave);

            btnClose = gcnew Button();
            btnClose->Text = L"Close";
            btnClose->Location = System::Drawing::Point(700, 480);
            btnClose->Size = System::Drawing::Size(80, 30);
            btnClose->Click += gcnew System::EventHandler(this, &frmVisit::btnClose_Click);
            this->Controls->Add(btnClose);

            dgvVisits = gcnew DataGridView();
            dgvVisits->Location = System::Drawing::Point(10, 530);
            dgvVisits->Size = System::Drawing::Size(780, 150);
            dgvVisits->AllowUserToAddRows = false;
            dgvVisits->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
            this->Controls->Add(dgvVisits);

            this->ResumeLayout(false);
        }

        void LoadStudents() {
            cmbStudents->Items->Clear();
            for each (Student^ student in DataStore::Students) {
                cmbStudents->Items->Add(student->Name);
            }
            LoadVisits();
        }

        void LoadVisits() {
            dgvVisits->DataSource = nullptr;
            dgvVisits->DataSource = DataStore::Visits;
        }

        System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
            if (cmbStudents->SelectedIndex < 0) {
                MessageBox::Show("Please select a student!");
                return;
            }

            Visit^ visit = gcnew Visit();
            visit->StudentRef = DataStore::Students[cmbStudents->SelectedIndex];
            visit->Temperature = Convert::ToDouble(txtTemperature->Text);
            visit->BloodPressure = txtBP->Text;
            visit->Pulse = Convert::ToInt32(txtPulse->Text);
            visit->Symptoms = rtxSymptoms->Text;
            visit->Diagnosis = rtxDiagnosis->Text;
            visit->Treatment = rtxTreatment->Text;
            visit->Time = DateTime::Now;

            DataStore::Visits->Add(visit);
            LoadVisits();
            MessageBox::Show("Visit recorded successfully!");
            rtxSymptoms->Clear();
            rtxDiagnosis->Clear();
            rtxTreatment->Clear();
            txtTemperature->Clear();
            txtBP->Clear();
            txtPulse->Clear();
        }

        System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
            this->Close();
        }
    };
}
