//
// Created by takak on 10/1/2022.
//

#ifndef CLASSNOTE_SUBWAYLIST_H
#define CLASSNOTE_SUBWAYLIST_H

#include "SubwayNode.h"

class SubwayList {
public:
    int listSize;
    SubwayNode* head;
    SubwayNode* tail;

    void printSubways();
    void insertFirst(SubwayNode* newNode);
    void insertLast(SubwayNode* newNode);
    void insertLastByAdmin(string adminName, float prevFare, float prevTime, float prevDistance);
    void insertAfterThis(int targetId, SubwayNode* newNode);
    void modifyNextFare(SubwayNode* targetNode, float nextFare);
    void modifyNextTravelTime(SubwayNode* targetNode, float nextTime);
    void modifySubwayName(SubwayNode* targetNode, string newSubwayName);
    float calcDistance(int sourceId, int destId);
    float calcFare(int sourceId, int destId);
    float calcTime(int sourceId, int destId);
    SubwayNode* searchBySubwayId(int id);

    SubwayList() {
        this->head = nullptr;
        this->tail = nullptr;
        this->listSize = 0;
    }
};

#endif //CLASSNOTE_SUBWAYLIST_H
