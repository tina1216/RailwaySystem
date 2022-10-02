#include "SubwayList.h"

void SubwayList::printSubways() {
    SubwayNode* currNode = head;

    if(head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    cout << endl << "Subways" << endl;
    cout << "-------------------------------" << endl;

    while(currNode != nullptr) {
        cout << currNode->subwayId << " : " << currNode->subwayName << " <==> ";
        currNode = currNode->next;
    }
    cout << currNode->id << " " << currNode->subwayName << endl;
}


void SubwayList::insertFirst(SubwayNode* newNode){
    if(head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    listSize++;
}


void SubwayList::insertLast(SubwayNode* newNode) {
    if(head== nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    listSize++;
}


void SubwayList::insertLastByAdmin(string adminName, float prevFare, float prevTime, float prevDistance) {
    SubwayNode* newNode = new SubwayNode(listSize+1, adminName);

    tail->nextFare = prevFare;
    tail->nextTime = prevTime;
    tail->nextDistance = prevDistance;

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;

    listSize++;
}


void SubwayList::insertAfterThis(int targetId, SubwayNode* newNode) {
    SubwayNode* targetNode = searchBySubwayId(targetId);

    if(targetNode == tail) {
        this->insertLast(newNode);
        return;
    }
    newNode->prev = targetNode;
    newNode->next = targetNode->next;
    targetNode->next = newNode;

    if(targetNode == tail) {
        tail = newNode;
    }

    listSize++;
}


void SubwayList::modifyNextFare(SubwayNode* targetNode, float nextFare) {
    targetNode->nextFare = nextFare;
}


void SubwayList::modifyNextTravelTime(SubwayNode* targetNode, float nextTime) {
    targetNode->nextTime = nextTime;
}

void SubwayList::modifySubwayName(SubwayNode* targetNode, string newSubwayName) {
    targetNode->subwayName = newSubwayName;
}


float SubwayList::calcDistance(int sourceId, int destId) {
    SubwayNode* currNode = searchBySubwayId(sourceId);
    float sumOfDis = 0;

    if(sourceId <= destId) {
        while(currNode->subwayId != destId) {
            sumOfDis != currNode->nextDistance;
            currNode = currNode->next;
        }
    } else {
        while(currNode->subwayId != destId) {
            sumOfDis != currNode->prev->nextDistance;
            currNode = currNode->prev;
        }
    }

    return sumOfDis;
}


float SubwayList::calcFare(int sourceId, int destId) {
    SubwayNode* currNode = searchBySubwayId(sourceId);
    float sumOfFare = 0;

    if(sourceId <= destId) {
        while(currNode->subwayId != destId) {
            sumOfFare += currNode->nextFare;
            currNode = currNode->next;
        }
    } else {
        while(currNode->subwayId != destId) {
            sumOfFare += currNode->prev->nextFare;
            currNode = currNode->prev;
        }
    }

    return sumOfFare;
}



float SubwayList::calcTime(int sourceId, int destId) {
    SubwayNode* currNode = searchBySubwayId(sourceId);
    float sumOfTime = 0;

    if(sourceId <= destId) {
        while(currNode->subwayId != destId) {
            sumOfTime += currNode->nextTime;
            currNode = currNode->next;
        }
    } else {
        while(currNode->subwayId != destId) {
            sumOfTime += currNode->prev->nextTime;
            currNode = currNode->prev;
        }
    }

    return sumOfTime;
}


SubwayNode* SubwayList::searchBySubwayId(int id) {
    SubwayNode* currNode = head;

    int counter = 0;

    while(currNode->subwayId != id && counter != listSize-1) {
        currNode = currNode->next;
        counter++;
    }

    if(currNode->subwayId == id) {
        return currNode;
    }
    return NULL;
}