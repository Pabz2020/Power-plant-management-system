#pragma once
#include <iostream>


using namespace std;

class PowerPlant {
public:
    int id; // plant iditifier
    float uC; // unit cost
    bool rA; // resource availability
    float cA; // capacity availability
    float cG; // current generation
    PowerPlant* next;

    PowerPlant() { // default constructor
        id = INT_MIN;
        uC = INT_MIN;
        rA = INT_MIN;
        cA = INT_MIN;
        cG = INT_MIN;
        next = NULL;
    }


    PowerPlant(int key, float cost, bool resource, float capacity, float generation) {  // overloaded constructor
        id = key;
        uC = cost;
        rA = resource;
        cA = capacity;
        cG = generation;
        next = NULL;
    }

};
