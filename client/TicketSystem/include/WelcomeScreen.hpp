#pragma once
#include <iostream>
#include "Movies.hpp"
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
	private: System::Windows::Forms::Button^ btnChoose;
	private: System::Windows::Forms::CheckBox^ option1;
	private: System::Windows::Forms::CheckBox^ option2;
	private: System::Windows::Forms::CheckBox^ option3;
	private: System::Windows::Forms::Label^ cinemaName;

	private: System::ComponentModel::IContainer^ components;
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
			   this->heading->Font = (gcnew System::Drawing::Font(L"Britannic Bold", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->heading->Location = System::Drawing::Point(268, 116);
			   this->heading->Name = L"heading";
			   this->heading->RightToLeft = System::Windows::Forms::RightToLeft::No;
			   this->heading->Size = System::Drawing::Size(776, 71);
			   this->heading->TabIndex = 0;
			   this->heading->Text = L"WELCOME TO CINEMA CITY";
			   this->heading->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			   this->heading->Click += gcnew System::EventHandler(this, &WelcomeScreen::label1_Click);
			   // 
			   // btnBook
			   // 
			   this->btnBook->BackColor = System::Drawing::Color::DarkSalmon;
			   this->btnBook->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->btnBook->FlatAppearance->BorderColor = System::Drawing::Color::LightCoral;
			   this->btnBook->FlatAppearance->BorderSize = 3;
			   this->btnBook->FlatAppearance->MouseDownBackColor = System::Drawing::Color::IndianRed;
			   this->btnBook->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightCoral;
			   this->btnBook->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
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
			   this->btnExit->BackColor = System::Drawing::Color::DarkSalmon;
			   this->btnExit->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->btnExit->FlatAppearance->BorderColor = System::Drawing::Color::LightCoral;
			   this->btnExit->FlatAppearance->BorderSize = 3;
			   this->btnExit->FlatAppearance->MouseDownBackColor = System::Drawing::Color::IndianRed;
			   this->btnExit->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightCoral;
			   this->btnExit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
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
			   this->BackColor = System::Drawing::Color::IndianRed;
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
		   void ChooseCinema();
		   Movies^ movies = gcnew Movies();
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void cinemaHeadingListener(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void btnBookListener(System::Object^ sender, System::EventArgs^ e) {
		this->ChooseCinema();
		this->btnBook->Visible = false;
		this->btnExit->Visible = false;

		Image^ image = Image::FromFile("./assets/cinema.png");

		int x = (this->Width - image->Width) / 2;
		int y = (this->Height - image->Height) / 2;

		Graphics^ g = this->CreateGraphics();
		for (int i = 0, j = 63; i < 3; i++, j += 400) {
			g->DrawImage(image, j, y - 50);
		}
	}
	private: System::Void btnExitListener(System::Object^ sender, System::EventArgs^ e) { Application::Exit(); }
	private: System::Void WelcomeScreen_Load(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void btnChooseListener(System::Object^ sender, System::EventArgs^ e);
	};
}
