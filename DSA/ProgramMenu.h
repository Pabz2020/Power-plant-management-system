#pragma once
#include <iostream>
#include <sstream>
#include "PowerPlantCollection.h"
#include "DegenerationStack.h"
#include "Validator.h"

#define RESET "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033;35m"
#define CYAN "\033;36m"
#define WHITE "\033;37m"



using namespace std;


void Addition(PowerPlantCollection& list) {
	int id;
	bool res;
	float cap;
	float cost;
	float gen;


	bool isExist = false;
	bool resOk = false;
	bool idOk = false;
	bool capOk = false;
	bool costOk = false;
	bool genOk = false;
	PowerPlant* start = list.head;

	do {
		isExist = false;
		while (!idOk) {
			cout << YELLOW << "                                Welcome to Addition Menu" << endl;
			cout << "                            -------------------------------------" << RESET << endl;
			cout << "                                      1.    id                            : ";
						if (cin >> id) {
				// Input was successful, set idOk to true to exit the loop
				idOk = true;
				if (id < 0) {
					cout <<RED<< "                                Error: Negative id" <<RESET << endl << endl;
					
					idOk = false;
				}
			}
			else {
				// Clear the error state of the input stream and ignore invalid input
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << RED << "                                Error: Non-numeric id" << RESET << endl << std::endl;
			}
		}


		PowerPlant* current = list.head;  

		while (current != NULL) { 
			if (current->id == id) { 
				isExist = true; 
				break; 
			} 
			current = current->next; 
		} 

		if (isExist == true) {
			cout << RED << "                                Power plant is already inserted!" << RESET << endl << endl;
			idOk = false;
		}

		

	} while (isExist == true );


	/*while (!resOk) {
		cout << "Resource availability: ";
		if (cin >> res) {
			if (res >= 0) {
				resOk = true;
			}
			else {
				cout << "Error: Negative resource availability" << endl;
			}
		}
		else {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Error: Non-numeric input for resource availability" << endl;
		}
	}*/
	
	/*cout << endl << "Resource availability: ";
	cin >> res;*/

	/*while (!resOk) {
		cout << "Resource availability: ";
		if (cin >> res) {
			if (res >= 0) {
				resOk = true;
			}
			else {
				cout << "Error: Negative resource availability" << endl;
			}
		}
		else {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Error: Non-numeric input for resource availability" << endl;
		}
	}*/

	string input;

	while (!resOk) {
		cout << "                                      2.    Resource availability (1/0)   " << endl;
		cout << "                                     (if Available - 1 Not Available - 0) :";
		cin >> input;

		if (input == "1" || input == "0") {
			if (input == "1") {
				res = true;
			}
			else {
				res = false;
			}
			resOk = true;
		}
		else {
			cout << RED << "                                Error: Invalid input. Please enter '1' or '0'." << RESET << endl << endl;
		}
	}

	while (!capOk) {
		cout << "                                      3.    Capacity available (MW)       : ";
				if (cin >> cap) {
			if (cap >= 0) {
				capOk = true;
			}
			else {
				cout << RED << "                                Error: Negative capacity available" << RESET << endl << endl;
			}
		}
		else {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << RED << "                                Error: Non-numeric input for capacity available" << RESET << endl << endl;
		}
	}

	/*cout << endl << "Capacity available: ";
	cin >> cap;*/

	while (!costOk) {
		cout << "                                      4.    Unit cost per generation (LKR): ";
				if (cin >> cost) {
			if (cost >= 0) {
				costOk = true;
			}
			else {
				cout << RED << "                                Error: Negative unit cost per generation" << RESET << endl << endl;
			}
		}
		else {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << RED << "                                Error: Non-numeric input for unit cost per generation" << RESET << endl << endl;
		}
	}

	while (!genOk) {
		cout << "                                      5.    Current generation (MW)       : ";
				if (cin >> gen) {
			if (gen >= 0) {
				genOk = true;
				cout <<GREEN<<endl<< "                                Successfully Added the Data set No. " << id <<	RESET<< endl;
			}
			else {
				cout << RED << "                                Error: Negative current generation" << RESET << endl << endl;
			}
		}
		else {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << RED << "                                Error: Non-numeric input for current generation" << RESET << endl << endl;
		}
	}

	/*cout << endl << "Unit cost per generation: ";
	cin >> cost;
	cout << endl << "Current generation: ";
	cin >> gen;*/
	list.insert(id, res, cap, cost, gen);

}

void Deletion(PowerPlantCollection& list) {

	string command; 
	do {

		cout <<YELLOW<< "                                Welcome to Deletion Menu" <<endl;
		cout << "                            -------------------------------------" << RESET << endl;
		cout << "                                What do you want to delete ? " << endl << endl;
		cout << "                                    1: Delete a particular power plant" << endl;
		cout << "                                    2: Delete all" << endl;
		cout << endl<<endl;

		cout << "                                Command                   : ";
		cin >> command;

		if (command == "1") {
			int name;
			cout << "                                Enter Id to delete: ";
			while (!(std::cin >> name)) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout <<RED<< "Error: Non-numeric Id " <<RESET<<endl<<endl;
				cout << "Enter Id to delete: ";
			}
			list.deleteId(name);
			//cout << "Power plant with id " << name << " successfully deleted!" << endl;
		}
		else if (command == "2") {
			list.deleteAll();
			cout << GREEN << "                                All data successfully deleted!" << RESET << endl << endl;
		}
		else {
			cout << RED << "                                Invalid input" << RESET << endl << endl;
		}
	} while (command != "1" && command != "2");
}

void ControlRequest(PowerPlantCollection& list) {

	PowerPlantCollection copy(list);

	copy.head = copy.filter(copy.head);
	copy.sortList(); 

	bool demandOk = false;
	float demand;

	cout <<YELLOW<< "                                Welcome to control request section" << endl;
	cout << "                                -------------------------------------" << RESET << endl;

	while (!demandOk) {
		cout << "                                What is your current demand (MW) :  ";
		if (cin >> demand) {
			demandOk = true; // Set to true if input is successfully read
		}
		else {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << RED << "                                Error: Non-numeric input for demand. Please enter a numeric value." << RESET << endl << endl;
		}
	}


	if (demand > 0) {
		
		PowerPlant* current = copy.head; 
		while (demand > 0) {

			if (current == NULL) {
				cout << RED << "                                Supply is not sufficient to cater the demand" << RESET << endl << endl;
				break;
			}

			demand = demand - current->cA; 
			if (demand >= 0) {
				cout<< GREEN << "                                Increase the power generation: " << endl << endl;
				cout << "                                                ";
				cout << " Power Plant " << current->id << " = " << current->cA << " MW" << RESET <<endl<<endl;
			}
			else {
				cout << GREEN << "                                Increase the power generation: " << endl << endl;
				cout << "                                                ";
				cout << " Power Plant " << current->id << " = " << demand+current->cA <<" MW" << RESET << endl << endl;
			}
			current = current->next;
		}

	}
	else if (demand < 0) {
		stack degeneration;
		PowerPlant* current = copy.head;
		for (int i = 0; i < copy.size; i++) {
			degeneration.push(current->id, current->rA, current->cA, current->uC, current->cG);
			current = current->next;
		}
		degeneration.traverse(demand);
	} 
	else {
		cout << GREEN << "                                Supply and demand is balanced" <<RESET << endl << endl;
	}

}

void Menu(PowerPlantCollection& rawData) {

	string command;

	do {
		

		cout <<endl<< YELLOW << "                                     Welcome to power plant management system"<<endl;
		cout << "                                ----------------------------------------------------" <<RESET<< endl << endl;
		cout << "                                               1: View database" << endl;
		cout << "                                               2: Add data" << endl;
		cout << "                                               3: Delete data" << endl;
		cout << "                                               4: Control request" << endl;
		cout << "                                               5: Demostration" << endl;
		cout << "                                               6: Exit" << endl << endl;

		cout << "                                           Command (respective number): ";
		cin >> command;
		cout << endl;

		if (command == "1") {
			cout << "Power plant statistics:" << endl;
			rawData.printData();
			cout << endl;
		}
		else if (command == "2") {
			Addition(rawData);

		}
		else if (command == "3") {
			Deletion(rawData);
		}
		else if (command == "4") {
			ControlRequest(rawData);
		}
		else if (command == "5") {
			rawData.insert(1, 1, 505, 11, 325); 
			rawData.insert(2, 0, 201, 20, 200); 
			rawData.insert(3, 1, 103, 17, 479); 
			rawData.insert(4, 1, 126, 25, 156); 
			rawData.insert(5, 1, 302, 15, 600); 
			rawData.insert(6, 0, 325, 19, 325);  
			rawData.insert(7, 1, 524, 30, 214); 
			rawData.insert(8, 0, 179, 24, 179); 
			rawData.insert(9, 1, 458, 14, 200); 

			
			cout << GREEN << "                                      Demostration mode is activated!" <<RESET<< endl << endl;
			
			

		}
		else if(command!="6") {
			cout << RED << "                                Error: Invalid input. Please enter a command between 1 and 6." << RESET << endl;
		}


	} while (command!= "6");

	

	

}







