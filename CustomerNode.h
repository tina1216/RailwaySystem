//
// Created by takak on 10/1/2022.
//

#ifndef CLASSNOTE_CUSTOMERNODE_H
#define CLASSNOTE_CUSTOMERNODE_H
#include <string>

class CustomerNode {
    public:
        int customerId;
        string customerName;
        string idNum;
        string psw;
        CustomerNode* next;
        CustomerNode* prev;

        CustomerNode(int customerId, string customerName, string idNum, string psw) {
            this->customerId = customerId;
            this->customerName = customerName;
            this->idNum = idNum;
            this->psw = psw;

            this->next = nullptr;
            this->prev = nullptr;
        }
};

#endif //CLASSNOTE_CUSTOMERNODE_H
