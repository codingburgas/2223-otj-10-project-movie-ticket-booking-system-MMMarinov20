#include "pch.h"
#include "WelcomeScreen.hpp"

void TicketSystem::WelcomeScreen::InitializeCinema() {
	// 
	// cinemaHeading
	//
	this->cinemaHeading = (gcnew System::Windows::Forms::Label());
	this->heading->AutoSize = true;
	this->heading->Font = (gcnew System::Drawing::Font(L"Britannic Bold", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->heading->Location = System::Drawing::Point(480, 146);
	this->heading->Name = L"cinemaHeading";
	this->heading->RightToLeft = System::Windows::Forms::RightToLeft::No;
	this->heading->Size = System::Drawing::Size(448, 41);
	this->heading->TabIndex = 0;
	this->heading->Text = L"Choose a cinema";
	this->heading->TextAlign = System::Drawing::ContentAlignment::TopCenter;
	this->heading->Click += gcnew System::EventHandler(this, &WelcomeScreen::cinemaHeadingListener);
}