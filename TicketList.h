//
// Created by takak on 10/1/2022.
//

#ifndef CLASSNOTE_TICKETLIST_H
#define CLASSNOTE_TICKETLIST_H

#include "TicketNode.h"

class TicketList {
public:
    TicketNode* head;
    TicketNode* tail;
    int listSize;

    void insertLast(TicketNode* newNode);
    TicketNode* searchByTicketId(int ticketId);
    void deleteByTicketId(int ticketId);

    //sorting - merge sort
    TicketList* split(TicketNode* tNode);
    TicketList* merge(TicketNode* firstNode, TicketNode* secondNode);
    TicketList* mergeSort(TicketNode* tHead);

    TicketList() {
        this->head = nullptr;
        this->tail = nullptr;
        this->listSize = 0;
    }
};

#endif //CLASSNOTE_TICKETLIST_H
