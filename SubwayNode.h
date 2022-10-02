//
// Created by takak on 10/1/2022.
//

#ifndef CLASSNOTE_SUBWAYNODE_H
#define CLASSNOTE_SUBWAYNODE_H
#include <string>

class SubwayNode {
public:
    SubwayNode* next;
    SubwayNode* prev;

    int subwayId;
    string subwayName;
    float nextDistance;
    float nextFare;
    float nextTime;
    string sightseeing;

    SubwayNode(int subwayId, string subwayName, float nextDistance, float nextFare, float nextTime,
               string sightseeing){
    this->subwayId = subwayId;
    this->subwayName = subwayName;
    this->nextDistance = nextDistance;
    this->nextFare = nextFare;
    this->nextTime = nextTime;
    this->sightseeing = sightseeing;

    this->next = nullptr;
    this->prev = nullptr;
    }

    SubwayNode(int subwayId, string subwayName, float nextDistance, float nextFare, float nextTime){
        this->subwayId = subwayId;
        this->subwayName = subwayName;
        this->nextDistance = nextDistance;
        this->nextFare = nextFare;
        this->nextTime = nextTime;
        this->sightseeing = sightseeing;

        this->next = nullptr;
        this->prev = nullptr;
    }
};

#endif //CLASSNOTE_SUBWAYNODE_H
