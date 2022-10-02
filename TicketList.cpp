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

// sorting --------------------
TicketList* TicketList::bubbleSort(TicketNode *tNode) {
    int swapped, i;
    TicketNode* currNode;
    TicketNode* temp;
    TicketNode* sortedList = nullptr;

    if(tNode == nullptr) {
        return NULL;
    }
    do {
        swapped = 0;
        currNode = tNode;

        while(currNode->next != temp) {
            if (currNode->ticketId > currNode->next->ticketId) {
                swap(currNode->data, ptr1->next->data);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
        }
    } while(swapped);
}