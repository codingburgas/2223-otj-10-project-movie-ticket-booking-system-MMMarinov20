#include "pch.h"
#include "MovieInformation.hpp"

void MovieInformation::PanelMouseEnter(Object^ sender, EventArgs^ e) {
	Panel^ panel = dynamic_cast<Panel^>(sender);
	if (panel != nullptr) {
		panel->Cursor = Cursors::Hand;
		panel->BackColor = Color::DarkOrange;
	}
}

void MovieInformation::PanelMouseLeave(Object^ sender, EventArgs^ e) {
	Panel^ panel = dynamic_cast<Panel^>(sender);
	if (panel != nullptr) {
		panel->Cursor = Cursors::Default;
		panel->BackColor = Color::Orange;
	}
}