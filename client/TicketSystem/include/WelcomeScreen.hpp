#pragma once

namespace TicketSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for WelcomeScreen
	/// </summary>
	public ref class WelcomeScreen : public System::Windows::Forms::Form
	{
	public:
		WelcomeScreen(void)
		{
			InitializeComponent();
			//void InitializeCinema();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~WelcomeScreen()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ heading;
	private: System::Windows::Forms::Label^ cinemaHeading;
	private: System::Windows::Forms::Button^ btnBook;
	private: System::Windows::Forms::Button^ btnExit;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void) {
			this->heading = (gcnew System::Windows::Forms::Label());
			this->btnBook = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// heading
			// 
			this->heading->AutoSize = true;
			this->heading->Font = (gcnew System::Drawing::Font(L"Britannic Bold", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->heading->Location = System::Drawing::Point(413, 146);
			this->heading->Name = L"heading";
			this->heading->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->heading->Size = System::Drawing::Size(448, 41);
			this->heading->TabIndex = 0;
			this->heading->Text = L"WELCOME TO CINEMA CITY";
			this->heading->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->heading->Click += gcnew System::EventHandler(this, &WelcomeScreen::label1_Click);
			// 
			// btnBook
			// 
			this->btnBook->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->btnBook->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnBook->FlatAppearance->BorderSize = 0;
			this->btnBook->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Silver;
			this->btnBook->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Silver;
			this->btnBook->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBook->Location = System::Drawing::Point(532, 270);
			this->btnBook->Name = L"btnBook";
			this->btnBook->Size = System::Drawing::Size(195, 40);
			this->btnBook->TabIndex = 1;
			this->btnBook->Text = L"Book tickets";
			this->btnBook->UseVisualStyleBackColor = false;
			this->btnBook->Click += gcnew System::EventHandler(this, &WelcomeScreen::btnBookListener);
			// 
			// btnExit
			// 
			this->btnExit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->btnExit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnExit->FlatAppearance->BorderSize = 0;
			this->btnExit->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Silver;
			this->btnExit->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Silver;
			this->btnExit->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnExit->Location = System::Drawing::Point(532, 339);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(195, 40);
			this->btnExit->TabIndex = 2;
			this->btnExit->Text = L"Exit";
			this->btnExit->UseVisualStyleBackColor = false;
			this->btnExit->Click += gcnew System::EventHandler(this, &WelcomeScreen::btnExitListener);
			// 
			// WelcomeScreen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ClientSize = System::Drawing::Size(1264, 681);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->btnBook);
			this->Controls->Add(this->heading);
			this->Name = L"WelcomeScreen";
			this->Text = L"WelcomeScreen";
			this->Load += gcnew System::EventHandler(this, &WelcomeScreen::WelcomeScreen_Load);
			this->ResumeLayout(false);
			this->PerformLayout();
		}
		void InitializeCinema();
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void cinemaHeadingListener(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void btnBookListener(System::Object^ sender, System::EventArgs^ e) {
		this->InitializeCinema();
		this->btnBook->Visible = false;
		this->btnExit->Visible = false;
	}
	private: System::Void btnExitListener(System::Object^ sender, System::EventArgs^ e) {Application::Exit();}
	private: System::Void WelcomeScreen_Load(System::Object^ sender, System::EventArgs^ e) {}
	};
}
