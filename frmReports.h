#pragma once

namespace SchoolClinic360 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class frmReports : public Form {
    public:
        frmReports(void) {
            InitializeComponent();
        }

    protected:
        ~frmReports() {
            if (components) {
                delete components;
            }
        }

    private:
        ListBox^ lstReport;
        Button^ btnMonthlyReport;
        Button^ btnDiagnosisReport;
        Button^ btnClose;
        System::ComponentModel::Container^ components;

        void InitializeComponent(void) {
            this->SuspendLayout();

            this->Text = L"Reports";
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->ClientSize = System::Drawing::Size(600, 500);
            this->StartPosition = FormStartPosition::CenterScreen;
            this->BackColor = System::Drawing::Color::WhiteSmoke;

            lstReport = gcnew ListBox();
            lstReport->Location = System::Drawing::Point(20, 60);
            lstReport->Size = System::Drawing::Size(560, 350);
            this->Controls->Add(lstReport);

            btnMonthlyReport = gcnew Button();
            btnMonthlyReport->Text = L"Monthly Report";
            btnMonthlyReport->Location = System::Drawing::Point(20, 420);
            btnMonthlyReport->Size = System::Drawing::Size(130, 30);
            btnMonthlyReport->Click += gcnew System::EventHandler(this, &frmReports::btnMonthlyReport_Click);
            this->Controls->Add(btnMonthlyReport);

            btnDiagnosisReport = gcnew Button();
            btnDiagnosisReport->Text = L"Diagnosis Report";
            btnDiagnosisReport->Location = System::Drawing::Point(160, 420);
            btnDiagnosisReport->Size = System::Drawing::Size(130, 30);
            btnDiagnosisReport->Click += gcnew System::EventHandler(this, &frmReports::btnDiagnosisReport_Click);
            this->Controls->Add(btnDiagnosisReport);

            btnClose = gcnew Button();
            btnClose->Text = L"Close";
            btnClose->Location = System::Drawing::Point(450, 420);
            btnClose->Size = System::Drawing::Size(130, 30);
            btnClose->Click += gcnew System::EventHandler(this, &frmReports::btnClose_Click);
            this->Controls->Add(btnClose);

            this->ResumeLayout(false);
        }

        System::Void btnMonthlyReport_Click(System::Object^ sender, System::EventArgs^ e) {
            lstReport->Items->Clear();
            lstReport->Items->Add("=== MONTHLY VISIT REPORT ===");
            lstReport->Items->Add("");
            
            int totalVisits = DataStore::Visits->Count;
            lstReport->Items->Add("Total Visits: " + totalVisits);
            lstReport->Items->Add("");
            lstReport->Items->Add("=== VISITS BY MONTH ===");
            lstReport->Items->Add("January: " + CountVisitsByMonth(1));
            lstReport->Items->Add("February: " + CountVisitsByMonth(2));
            lstReport->Items->Add("March: " + CountVisitsByMonth(3));
            lstReport->Items->Add("April: " + CountVisitsByMonth(4));
            lstReport->Items->Add("May: " + CountVisitsByMonth(5));
            lstReport->Items->Add("June: " + CountVisitsByMonth(6));
        }

        System::Void btnDiagnosisReport_Click(System::Object^ sender, System::EventArgs^ e) {
            lstReport->Items->Clear();
            lstReport->Items->Add("=== DIAGNOSIS SUMMARY ===");
            lstReport->Items->Add("");
            
            for each (Visit^ visit in DataStore::Visits) {
                if (visit->Diagnosis != "") {
                    lstReport->Items->Add("Student: " + visit->StudentRef->Name);
                    lstReport->Items->Add("Diagnosis: " + visit->Diagnosis);
                    lstReport->Items->Add("Date: " + visit->Time.ToString());
                    lstReport->Items->Add("---");
                }
            }
        }

        System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
            this->Close();
        }

        int CountVisitsByMonth(int month) {
            int count = 0;
            for each (Visit^ visit in DataStore::Visits) {
                if (visit->Time.Month == month) {
                    count++;
                }
            }
            return count;
        }
    };
}
