//
// Created by takak on 10/1/2022.
//

#ifndef CLASSNOTE_UTILS_H
#define CLASSNOTE_UTILS_H

#include "SubwayList.h"
#include "TicketList.h"
#include "SubwayNode.h"
#include "CustomerList.h"
#include "CustomerNode.h"
#include "Admin.h"

int getId();
SubwayList* createSubwayList();
void printLogin();
TicketList* createSampleTicketList();
CustomerList* createSampleCustomer();


void customerChoices(SubwayList* sList, TicketList *tList, int customerId, CustomerList* cList);

string getDateTime();
int loginCustomer(CustomerList* cList);
int signupCustomer(CustomerList* cList);
bool loginAdmin(Admin admins[]);
void printSubwayInfo(SubwayNode* node);
void printSubwayInfoBtwTwo(SubwayList* sList, int selectedSub1, int selectedSub2);
void adminChoices(SubwayList* sList, TicketList* tList);
string addTime(string ct, float min);
string getDepartureTime(SubwayList* sList, int c_station, int d_station);
void printTicketInfo(TicketNode* new_node);


void printThisCustomerTicketInfo(TicketList* tList, int customerId);

#endif //CLASSNOTE_UTILS_H
