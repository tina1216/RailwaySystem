#include "CustomerList.h"
#include <iostream>

void CustomerList::insertCustomerAtEnd(CustomerNode* newNode) {
    if(head == nullptr) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
    listSize++;
}

void CustomerList::printCustomerInOrder(CustomerNode* node) {
    if(head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    while(node != nullptr) {
        cout << "ID: " << node->customerId << "\tName: " << node->customerName << "\tIC Number: " << node->idNum << endl;
        node = node->next;
    }
}

CustomerNode* CustomerList::searchCustomer(int cId) {
    CustomerNode* currNode = head;
    int counter = 0;

    while(currNode->customerId != cId && counter != listSize-1) {
        currNode = currNode->next;
        counter++;
    }

    if(currNode->customerId == cId) {
        return currNode;
    }

    return NULL;
}
