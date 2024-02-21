#pragma once

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

class PowerPlantCollection {
public:
    PowerPlant* head;
    PowerPlant* tail;
    int size;


    // default constructor
    PowerPlantCollection() {
        head = NULL;
        tail = NULL;
        size = 0;
    }


    // copy constructor
    PowerPlantCollection(const PowerPlantCollection& old) {
        // if the given list is empty
        if (old.head == NULL) {
            head = NULL;
            tail = NULL;
            size = 0;
        }
        else {
            // copying the list and creating a new list
            head = new PowerPlant(old.head->id, old.head->uC, old.head->rA, old.head->cA, old.head->cG);
            PowerPlant* oldCurrent = old.head->next;
            PowerPlant* newCurrent = head;
            while (oldCurrent != NULL) {
                newCurrent->next = new PowerPlant(oldCurrent->id, oldCurrent->uC, oldCurrent->rA, oldCurrent->cA, oldCurrent->cG);
                newCurrent = newCurrent->next;
                oldCurrent = oldCurrent->next;
            }
            tail = newCurrent;
            size = old.size;
        }
    }


    // insert method
    void insert(int key, bool resource, float capacity, float cost, float generation) {
        PowerPlant* temp = new PowerPlant(key, cost, resource, capacity, generation); // new node created

        if (size == 0) { // data list is empty
            head = tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }


    void deleteId(int Id) {
        PowerPlant* current = head;
        PowerPlant* prev = NULL;
        bool isDeleted = false;
        bool idFound = false;

        // Check if the list is empty
        if (size == 0) {
            cout <<RED<< "                               List is empty. Cannot delete." <<RESET<< endl;
            return;
        }

        while (current != NULL && !isDeleted) {
            if (current->id == Id) {
                idFound = true;
                if (prev == NULL) {
                    // If the node to be deleted is the head node
                    head = current->next;
                }
                else {
                    prev->next = current->next;
                }
                delete current;
                size--;
                isDeleted = true;
                cout <<GREEN<< "                               Power plant with id " << Id << " successfully deleted!" <<RESET<< endl;
            }
            else {
                prev = current;
                current = current->next;
            }
        }

        if (!idFound) {
            cout <<RED<< "                               ID not found in the list. Cannot delete." <<RESET<< endl;
        }
    }

    void deleteRecursive(PowerPlant* node) {
        if (node == NULL) {
            return;
        }
        deleteRecursive(node->next);
        delete node;
        size--;
    }

    void deleteAll() {
        deleteRecursive(head); 
        head = NULL; 
    }


    // print method
    void printData() {
        if (size == 0) {
            cout << RED << "                               No data available!" << RESET<< endl;
        }
        else {

            PowerPlant* current = head;
            cout << "id" << "| " << "RA" << "| " << "CA " << " | " << "UC" << " | " << "CG" << endl;
            for (int i = 0; i < size; i++) {
                cout << current->id << " | " << current->rA << " | " << current->cA << " | " << current->uC << " | " << current->cG << endl;
                current = current->next;
            }
            cout << endl;
        }
    }


    // filter method
    PowerPlant* filter(PowerPlant* head) {

        // base condition
        if (head == NULL) {
            return NULL;
        }


        // recursively going to last node
        head->next = filter(head->next);

        // checking the conditions
        if (head->rA == 0) {
            PowerPlant* next = head->next;
            delete head;
            size--;
            return next;
        }
        else {
            return head;
        }

    }

    // Helper function to merge two sorted linked lists
    PowerPlant* merge(PowerPlant* left, PowerPlant* right) {
        PowerPlant* result = NULL;

        // Base cases
        if (left == NULL)
            return right;
        if (right == NULL)
            return left;

        // Compare the unit cost and merge accordingly
        if (left->uC <= right->uC) {
            result = left;
            result->next = merge(left->next, right);
        }
        else {
            result = right;
            result->next = merge(left, right->next);
        }
        return result;
    }

    // Merge sort function for the linked list
    PowerPlant* mergeSort(PowerPlant* head) {
        if (head == NULL || head->next == NULL)
            return head;

        // Find the middle of the list
        PowerPlant* slow = head;
        PowerPlant* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        PowerPlant* middle = slow->next;
        slow->next = NULL;

        PowerPlant* left = mergeSort(head);
        PowerPlant* right = mergeSort(middle);

        return merge(left, right);
    }

    void sortList() {
        head = mergeSort(head);
    }


};

