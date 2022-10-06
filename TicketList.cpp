#include "TicketList.h"
#include <iostream>

void TicketList::insertLast(TicketNode* newNode) {
    if(head == nullptr) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
    listSize++;
}

TicketNode*  TicketList::searchByTicketId(int ticketId) {
    TicketNode* currNode = head;

    while(currNode != nullptr) {
        if(currNode->ticketId != ticketId) {
            currNode = currNode->next;
        } else {
            break;
        }
    }
    return currNode;
}

void TicketList::deleteByTicketId(int ticketId) {
    TicketNode* currNode = head;
    TicketNode* prev = head;

    while(currNode != nullptr) {
        if(currNode->ticketId != ticketId) {
            prev = currNode;
            currNode = currNode->next;
        } else {
            break;
        }
    }

    if(currNode == nullptr) {
        cout << "No ticket found" << endl;
        return;
    }
    if(currNode == head) {
        head = head->next;
        free(currNode);
        cout << "Ticket Deleted successfully." << endl;
        return;
    }

    prev->next = currNode->next;
    free(currNode);
    cout << "Ticket Deleted successfully." << end;
    return;
}

// sorting merge sort --------------------
TicketList* TicketList::split(TicketNode* tNode) {


}
TicketList* TicketList::merge(TicketNode* firstNode, TicketNode* secondNode) {

}


TicketList* TicketList::mergeSort(TicketNode *tNode) {

}