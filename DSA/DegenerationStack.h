#pragma once
#include <iostream>
#include <cmath>
#include "PowerPlant.h"

#define RESET "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033;35m"
#define CYAN "\033;36m"
#define WHITE "\033;37m"

using namespace std;

class stack {
    int size;
    PowerPlant* top;
public:
    stack() {
        size = 0;
        top = NULL;
    }

    void push(int key, bool resource, float capacity, float cost, float generation) {
        PowerPlant* newNode = new PowerPlant(key, cost, resource, capacity, generation);

        // stack validation
        if (size == 0) {
            top = newNode;
        }
        else {
            newNode->next = top;
            top = newNode;
        }
        size++;
    }


    void traverse(float value) {

        // empty stack
        if (size == 0) {
            cout <<RED<< "                               Stack is empty!" <<RESET<< endl;
        }
        else {
            PowerPlant* current = top;
            value = abs(value); 
            while (value > 0) {
                value = value - current->cG;
                if (value >= 0) {
                    cout <<GREEN<< "                                Decrease the power generation: "<<endl<<endl;
                    cout << "                                                ";
                    cout << " Power Plant " << current->id << " = " << current->cG << " MW" <<RESET<<endl<< endl;
                }
                else {
                    cout << GREEN << "                                Decrease the power generation: " << endl<<endl;
                    cout << "                                                ";
                    cout << " Power Plant " << current->id << " = " << value + current->cG << " MW" <<RESET<<endl<< endl;
                }
                current = current->next;
            }

            cout << endl;
        }



    }
};

