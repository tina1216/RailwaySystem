//
// Created by takak on 10/1/2022.
//
#ifndef CLASSNOTE_CUSTOMERLIST_H
#define CLASSNOTE_CUSTOMERLIST_H

#include "CustomerNode.h"

class CustomerList {
    public:
        CustomerNode* head;
        CustomerNode* tail;
        int listSize;

        void insertCustomerAtEnd(CustomerNode* cNode);
        void printCustomerInOrder(CustomerNode* node);
        CustomerNode* searchCustomer(int cId);

    CustomerList() {
        this->head = nullptr;
        this->tail = nullptr;
        this->listSize = 0;
    }
};

#endif //CLASSNOTE_CUSTOMERLIST_H
