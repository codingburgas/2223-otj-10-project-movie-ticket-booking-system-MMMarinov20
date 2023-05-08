#include "pch.h"
#include "WelcomeScreen.hpp"

void TicketSystem::WelcomeScreen::ChooseCinema() {
	this->heading->AutoSize = true;
	this->heading->Font = (gcnew System::Drawing::Font(L"Britannic Bold", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->heading->Location = System::Drawing::Point(370, 116);
	this->heading->Name = L"heading";
	this->heading->RightToLeft = System::Windows::Forms::RightToLeft::No;
	this->heading->Size = System::Drawing::Size(776, 71);
	this->heading->TabIndex = 0;
	this->heading->Text = L"CHOOSE A CINEMA";
	this->heading->TextAlign = System::Drawing::ContentAlignment::TopCenter;

	this->btnChoose = (gcnew System::Windows::Forms::Button());
	this->Controls->Add(this->btnChoose);

	this->btnChoose->BackColor = System::Drawing::Color::DarkSalmon;
	this->btnChoose->Cursor = System::Windows::Forms::Cursors::Hand;
	this->btnChoose->FlatAppearance->BorderColor = System::Drawing::Color::LightCoral;
	this->btnChoose->FlatAppearance->BorderSize = 3;
	this->btnChoose->FlatAppearance->MouseDownBackColor = System::Drawing::Color::IndianRed;
	this->btnChoose->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightCoral;
	this->btnChoose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
	this->btnChoose->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->btnChoose->Location = System::Drawing::Point(532, 510);
	this->btnChoose->Name = L"btnChoose";
	this->btnChoose->Size = System::Drawing::Size(195, 40);
	this->btnChoose->TabIndex = 1;
	this->btnChoose->Text = L"Choose";
	this->btnChoose->UseVisualStyleBackColor = false;
	this->btnChoose->Click += gcnew System::EventHandler(this, &WelcomeScreen::btnChooseListener);

	this->option1 = (gcnew System::Windows::Forms::CheckBox());
	this->Controls->Add(this->option1);
	this->option1->AutoSize = true;
	this->option1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->option1->Location = System::Drawing::Point(180, 450);
	this->option1->Name = L"option1";
	this->option1->Size = System::Drawing::Size(195, 40);
	this->option1->TabIndex = 1;
	this->option1->TabStop = true;
	this->option1->Text = L"Option 1";

	this->option2 = (gcnew System::Windows::Forms::CheckBox());
	this->Controls->Add(this->option2);
	this->option2->AutoSize = true;
	this->option2->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->option2->Location = System::Drawing::Point(580, 450);
	this->option2->Name = L"option2";
	this->option2->Size = System::Drawing::Size(195, 40);
	this->option2->TabIndex = 2;
	this->option2->TabStop = true;
	this->option2->Text = L"Option 2";
	
	this->option3 = (gcnew System::Windows::Forms::CheckBox());
	this->Controls->Add(this->option3);
	this->option3->AutoSize = true;
	this->option3->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->option3->Location = System::Drawing::Point(980, 450);
	this->option3->Name = L"option3";
	this->option3->Size = System::Drawing::Size(195, 40);
	this->option3->TabIndex = 3;
	this->option3->TabStop = true;
	this->option3->Text = L"Option 3";
}

System::Void TicketSystem::WelcomeScreen::btnChooseListener(System::Object^ sender, System::EventArgs^ e) {
	this->cinemaName = (gcnew System::Windows::Forms::Label());
	this->Controls->Add(this->cinemaName);
	this->cinemaName->AutoSize = true;
	this->cinemaName->Font = (gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->cinemaName->Location = System::Drawing::Point(0, 0);
	this->cinemaName->Name = L"cinemaName";
	this->cinemaName->Size = System::Drawing::Size(776, 71);
	this->cinemaName->TabIndex = 4;
	if (this->option1->Checked) this->cinemaName->Text = this->option1->Text;
	else if (this->option2->Checked) this->cinemaName->Text = this->option2->Text;
	else if (this->option3->Checked) this->cinemaName->Text = this->option3->Text;
	else this->cinemaName->Text = "No cinema selected";
	
	this->movies->fetchMovies();
	this->cinemaName->Text = this->movies->getMovies();
	//create a new movies form
	this->Hide();
	this->movies->Show();
}