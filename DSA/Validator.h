#pragma once
#include <iostream>

using namespace std;


void idValidator(bool ok, int Id) {
	while (!ok) {
		cout << "id: ";
		if (cin >> Id) {
			// Input was successful, set idOk to true to exit the loop
			ok = true;
		}
		else {
			// Clear the error state of the input stream and ignore invalid input
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid id" << std::endl;
		}
	}
}