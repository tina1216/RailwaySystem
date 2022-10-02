//
// Created by takak on 10/1/2022.
//

#ifndef CLASSNOTE_TICKETNODE_H
#define CLASSNOTE_TICKETNODE_H

#include "SubwayNode.h"

class TicketNode {
    public:
        TicketNode* next;
        int ticketId, transactionId;
        string sourceSubway, targetSubway, transactionTime, departureTime;
        int customerId;
        string customerName, arrivalTime;

        TicketNode(int ticketId, int transactionId, string sourceSubway, string targetSubway,
                   string transactionTime, string departureTime, int customerId, string customerName,
                   string arrivalTime) {
            this->ticketId = ticketId;
            this->transactionId = transactionId;
            this->sourceSubway = sourceSubway;
            this->targetSubway = targetSubway;
            this->transactionTime = transactionTime;
            this->departureTime = customerId;
            this->customerName = customerName;
            this->arrivalTime = arrivalTime;

            this->next = nullptr;
        }


    TicketNode(int ticketId, int transactionId, string sourceSubway, string targetSubway, string departureTime, int customerId, string customerName,
               string arrivalTime) {
        this->ticketId = ticketId;
        this->transactionId = transactionId;
        this->sourceSubway = sourceSubway;
        this->targetSubway = targetSubway;
        this->departureTime = customerId;
        this->customerName = customerName;
        this->arrivalTime = arrivalTime;

        this->next = nullptr;
    }
};



#endif //CLASSNOTE_TICKETNODE_H
