#include "pch.h"
#include "Seats.hpp"

void Seats::GenerateRandomSeats() {
	srand(time(NULL));
	for (int i = 0; i < 20; i++) {
		int randomIndex = rand() % 100;
		if (seatsArray[randomIndex]->isTaken == false) {
			seatsArray[randomIndex]->isTaken = true;
			seats[randomIndex]->BackColor = System::Drawing::Color::Red;
		}
		else i--;
	}
}