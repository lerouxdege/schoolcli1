#pragma once
#include "frmMain.h"

namespace SchoolClinic360 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class frmLogin : public Form {
    public:
        frmLogin(void) {
            InitializeComponent();
        }

    protected:
        ~frmLogin() {
            if (components) {
                delete components;
            }
        }

    private:
        TextBox^ txtUsername;
        TextBox^ txtPassword;
        Button^ btnLogin;
        Label^ lblUsername;
        Label^ lblPassword;
        Label^ lblTitle;
        System::ComponentModel::Container^ components;

        void InitializeComponent(void) {
            this->SuspendLayout();

            this->Text = L"SchoolClinic360 - Login";
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->ClientSize = System::Drawing::Size(400, 300);
            this->StartPosition = FormStartPosition::CenterScreen;
            this->BackColor = System::Drawing::Color::LightBlue;

            lblTitle = gcnew Label();
            lblTitle->Text = L"SchoolClinic360";
            lblTitle->Font = gcnew Font("Arial", 18, FontStyle::Bold);
            lblTitle->Location = System::Drawing::Point(100, 30);
            lblTitle->Size = System::Drawing::Size(200, 40);
            lblTitle->TextAlign = ContentAlignment::MiddleCenter;
            this->Controls->Add(lblTitle);

            lblUsername = gcnew Label();
            lblUsername->Text = L"Username:";
            lblUsername->Location = System::Drawing::Point(50, 100);
            lblUsername->Size = System::Drawing::Size(100, 20);
            this->Controls->Add(lblUsername);

            txtUsername = gcnew TextBox();
            txtUsername->Location = System::Drawing::Point(150, 100);
            txtUsername->Size = System::Drawing::Size(200, 20);
            this->Controls->Add(txtUsername);

            lblPassword = gcnew Label();
            lblPassword->Text = L"Password:";
            lblPassword->Location = System::Drawing::Point(50, 150);
            lblPassword->Size = System::Drawing::Size(100, 20);
            this->Controls->Add(lblPassword);

            txtPassword = gcnew TextBox();
            txtPassword->Location = System::Drawing::Point(150, 150);
            txtPassword->Size = System::Drawing::Size(200, 20);
            txtPassword->UseSystemPasswordChar = true;
            this->Controls->Add(txtPassword);

            btnLogin = gcnew Button();
            btnLogin->Text = L"Login";
            btnLogin->Location = System::Drawing::Point(150, 220);
            btnLogin->Size = System::Drawing::Size(100, 40);
            btnLogin->BackColor = System::Drawing::Color::Green;
            btnLogin->ForeColor = System::Drawing::Color::White;
            btnLogin->Font = gcnew Font("Arial", 10, FontStyle::Bold);
            btnLogin->Click += gcnew System::EventHandler(this, &frmLogin::btnLogin_Click);
            this->Controls->Add(btnLogin);

            this->ResumeLayout(false);
        }

        System::Void btnLogin_Click(System::Object^ sender, System::EventArgs^ e) {
            String^ username = txtUsername->Text;
            String^ password = txtPassword->Text;

            if (SessionManager::Login(username, password)) {
                frmMain^ mainForm = gcnew frmMain();
                mainForm->Show();
                this->Hide();
            } else {
                MessageBox::Show("Invalid credentials!", "Login Failed", 
                    MessageBoxButtons::OK, MessageBoxIcon::Error);
                txtUsername->Clear();
                txtPassword->Clear();
            }
        }
    };
}
