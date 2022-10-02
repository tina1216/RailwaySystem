#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "TicketList.h"
#include "Utils.h"
using namespace std;

int getId()
{
    int randomId = rand();
    return randomId;
}

SubwayList* createSubwayList() {
    SubwayList* subwayList = new SubwayList();

    SubwayNode* titiwangsa = new SubwayNode(subwayList->listSize + 1, "Titiwangsa", 0.40, 3, 4, "test");
    subwayList->insertFirst(titiwangsa);

    SubwayNode* pwtc = new SubwayNode(subwayList->listSize +1, "PWTC", 0.80, 7, 8, "test");
    subwayList->insertLast(pwtc);

    SubwayNode* SultanIsmail = new SubwayNode(subwayList->listSize + 1, "Sultan Ismail", 0.80, 7, 8, "test");
    subwayList->insertLast(SultanIsmail);

    SubwayNode* majlisJamek = new SubwayNode(subwayList->listSize + 1, "Majlis Jamek", 0.60, 5, 6, "test");
    subwayList->insertLast(majlisJamek);

    SubwayNode* plazaRakyat = new SubwayNode(subwayList->listSize + 1, "Plaza Rakyat", 1.00, 9, 10, "test");
    subwayList->insertLast(plazaRakyat);

    SubwayNode* hangTuah = new SubwayNode(subwayList->listSize + 1, "Hang Tuah", 0.50, 4, 5, "test");
    subwayList->insertLast(hangTuah);

    SubwayNode* pudu = new SubwayNode(subwayList->listSize + 1, "Pudu", 0.50, 4, 5, "test");
    subwayList->insertLast(pudu);

    SubwayNode* chanSowLin = new SubwayNode(subwayList->listSize + 1, "Chan Sow Lin", 0, 0, 0, "test");
    subwayList->insertLast(chanSowLin);

    return subwayList;
}

TicketList* createSampleTicketList() {
    TicketList* ticketList = new TicketList();

    TicketNode* ticket01 = new TicketNode(ticketList->listSize + 1, getId(), "Titiwangsa", "Majlis Jamek", "23-08-2022 20-28-90", "23-08-2022 20-38-00", 15, "Tina", "23-08-2022 21-28-90");
    ticketList->insertLast(ticket01);

    TicketNode* ticket02 = new TicketNode(ticketList->listSize + 1, getId(), "Majlis Jamek", "Majlis Jamek", "23-08-2022 20-28-90", "23-08-2022 20-38-00", 11, "Colson", "23-08-2022 21-28-90");
    ticketList->insertLast(ticket02);

    TicketNode* ticket03 = new TicketNode(ticketList->listSize + 1, getId(), "PWTC", "Pudu", "23-08-2022 20-28-90", "23-08-2022 20-38-00", 13, "Lee", "23-08-2022 21-28-90");
    ticketList->insertLast(ticket03);

    return ticketList;
}

void printLogin() {
    cout << endl;
    cout << "1. Login as current customer" << endl;
    cout << "2. Sign up as a new customer" << endl;
    cout << "3. Login as an admin" << endl;
    cout << "4. Quit" << endl;
}

CustomerList* createSampleCustomer() {
    CustomerList* cList = new CustomerList();

    CustomerNode* customer01 = new CustomerNode(10, "Tina Sekiya", "A00092371", "111111");
    cList->insertCustomerAtEnd(customer01);

    CustomerNode* customer02 = new CustomerNode(5, "Matthew Musto", "B00072372", "222222");
    cList->insertCustomerAtEnd(customer02);

    CustomerNode* customer03 = new CustomerNode(7, "Lee Felix", "E00072372", "333333");
    cList->insertCustomerAtEnd(customer03);

    CustomerNode* customer04= new CustomerNode(2, "Hwang Hyunjin", "C00072372", "444444");
    cList->insertCustomerAtEnd(customer04);

    CustomerNode* customer05 = new CustomerNode(12, "Colson Baker", "B00072372", "555555");
    cList->insertCustomerAtEnd(customer05);

    CustomerNode* customer06 = new CustomerNode(1, "Casey Luong", "A00092371", "666666");
    cList->insertCustomerAtEnd(customer06);

    return cList;
}


int loginCustomer(CustomerList *cList) {
    int id;
    string psw;
    cout << "Enter your id: ";
    cin >> id;

    cout << "Enter your password: ";
    getline(cin,psw);

    CustomerNode* node = cList->searchCustomer(id);

    if (node == NULL) {
        cout << "No such id found" << endl;
        return NULL;
    }
    if (node->psw != psw) {
        cout << "Wrong id or password" << endl;
        return NULL;
    }
    cout << endl << "Welcome, " << node->customerName << endl;
    return id;
}


int signupCustomer(CustomerList* cList) {
    string psw;
    string name;
    string idNum;
    int id = getId();


    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your i-cad(or passport) number: ";
    getline(cin, idNum);

    cout << "Enter your password: ";
    getline(cin, psw);

    cout << "Welcome " << name << ". Your id : " << id << endl;

    CustomerNode* node = new CustomerNode(id, name, idNum, psw);
    cList->insertCustomerAtEnd(node);
    return id;
}


bool loginAdmin(Admin admins[]) {
    int id;
    string psw;

    cout << "Enter your id: ";
    cin >> id;
    cout << "Enter your password: ";
    getline(cin, psw);

    if (admins[id - 1].psw == psw) {
        return true;
    }

    return false;
}


void printSubwayInfo(SubwayNode* node) {
    cout << endl;
    cout << "Subway Name:\t" << node->subwayName << endl;
    cout << "Subway Id:\t" << node->subwayId << endl;

    if(node->prev != nullptr) {
        cout << "Previous station:\t" << node->prev->subwayName << endl;
    }

    if(node->next != nullptr) {
        cout << "Next station:\t" << node->next->subwayName << endl;
    }

    cout << endl;
}

void printSubwayInfoBtwTwo(SubwayList* subwayList, int s1, int s2) {
    SubwayNode* cSubway = subwayList->searchBySubwayId(s1);
    SubwayNode* dSubway = subwayList->searchBySubwayId(s2);

    if (cSubway == NULL || dSubway == NULL) {
        cout << "Invalid Subway Id." << endl;
        return;
    }

    cout << endl << "Subway Information Between 2 Cities: " << endl;
    cout << "Travel Time:\t " << subwayList->calcTime(s1, s2) << " min" << endl;
    cout << "Distance:\t " << subwayList->calcDistance(s1, s2) << " KM" << endl;
    cout << "Travel Fare:\t " <<  "RM " << subwayList->calcFare(s1, chooses2nSubway2) << endl;
    cout << endl;
}

void adminChoices(SubwayList* subwayList, TicketList* tList) {
    while (true) {
        cout << endl << "1. Add subway station" << endl;
        cout << "2. Edit a subway station" << endl;
        cout << "3. View all purchase transactions" << endl;
        cout << "4. Sort purchases based on name" << endl;
        cout << "5. Search specific customer ticket purchase information" << endl;
        cout << "6. Edit specific ticket purchase information" << endl;
        cout << "7. Delete specific customer ticket purchase information" << endl;
        cout << "8. Log out" << endl;

        int choice;
        cout << endl << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                int choice1;
                cout << "1. Insert at the beginning" << endl;
                cout << "2. Insert at the end" << endl;
                cout << "3. Insert after a specific station" << endl;

                cout << endl << "Enter your choice: ";
                cin >> choice1;
                //cin.ignore(numeric_limits<streamsize>::max(), '\n');

                string sName;
                float nextDistance, nextFare, nextTime;
                SubwayNode *newNode;

                switch (choice1) {
                    case 1: //insert at the front
                        cout << "Enter new name of station: ";
                        getline(cin, sName);

                        cout << "Enter fare (RM) to next station: ";
                        cin >> nextFare;
                        //cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        cout << "Enter time (min) to reach next station: ";
                        cin >> nextTime;
                        //cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        cout << "Enter distance (KM) to next station: ";
                        cin >> nextDistance;
                        //cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        newNode = new SubwayNode(subwayList->listSize + 1, sName, nextDistance, nextFare, nextTime);
                        subwayList->insertFirst(newNode);
                        cout << "Successfully added a new station." << endl;
                        break;

                    case 2: // insert at the end
                        cout << "Enter new name of station: ";
                        getline(cin, sName);

                        cout << "Enter fare (RM) to this station: ";
                        cin >> nextFare;
                        //cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        cout << "Enter time (min) to reach this station: ";
                        cin >> nextTime;
                        //cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        cout << "Enter distance (KM) from previous station: ";
                        cin >> nextDistance;
                        //cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        subwayList->insertLastByAdmin(sName, nextFare, nextTime, nextDistance);
                        cout << "Successfully added a new station." << endl;
                        break;

                    case 3:
                        int targetSubwayId;
                        cout << endl << "Enter subway ID you wish to add after: ";
                        cin >> targetSubwayId;
                        //cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        if (targetSubwayId == subwayList->listSize) {
                            cout << "Choose 2nd option to insert at the end" << endl;
                            break;
                        }

                        cout << "Enter new station name : ";
                        getline(cin, sName);

                        cout << "Enter fare (RM) to next station: ";
                        cin >> nextFare;
                        //cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        cout << "Enter time (min) to reach next station: ";
                        cin >> nextTime;
                        //cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        cout << "Enter distance (KM) to next station: ";
                        cin >> nextDistance;
                        //cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        newNode = new SubwayNode(subwayList->listSize + 1, sName, nextDistance, nextFare, nextTime);
                        subwayList->insertAfterThis(targetSubwayId, newNode);
                        cout << "Successfully added a new station." << endl;
                        break;

                    default:
                        cout << "Invalid choice." << endl;
                        break;
                }
                break;
            }

            case 2: {
                // edit a subway station
                subwayList->printSubways();

                int subwayId;
                cout << endl << "Enter Subway id: ";
                cin >> subwayId;
                //cin.ignore(numeric_limits<streamsize>::max(), '\n');

                SubwayNode* editableSubway = subwayList->searchBySubwayId(subwayId);

                if (editableSubway == NULL) {
                    cout << "No station with the id found." << endl;
                }

                if (editableSubway == NULL) {
                    cout << "No such station found." << endl;
                    break;
                }

                float nextFare;
                float nextTravelTime;
                string sName;

                // reading new info
                cout << "Enter new fare to next station: ";
                cin >> nextFare;
                //cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Enter new time to reach next staion: ";
                cin >> nextTravelTime;
                //cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Enter new name of station: ";
                getline(cin, sName);

                editableSubway->nextFare = nextFare;
                editableSubway->nextTime = nextTravelTime;
                editableSubway->subwayName = sName;
                cout << "Modified successfully." << endl;

                break;
            }

            case 3: {
                // view all purchase transactions
                int counter = 0;
                TicketNode* currNode = tList->head;
                cout << "----------------------------------------------\n" << endl;

                while (currNode != nullptr) {
                    printTicketInfo(currNode);
                    currNode = currNode->next;
                    counter++;
                }

                if (counter == 0) {
                    cout << "No ticket info found." << endl;
                }
                cout << "----------------------------------------------\n" << endl;
                break;
            }

            case 4: {
                // sort purchase based on name
                tList->MergeSort(&tList->head);
                cout << "Sorted by customer name" << endl;
                break;
            }

            case 5: {
                // show specific customer info
                int customerId;
                cout << endl << "Enter Customer id: ";
                cin >> customerId;
                //cin.ignore(numeric_limits<streamsize>::max(), '\n');

                printThisCustomerTicketInfo(tList, customerId);
                break;
            }

            case 6: {
                // Edit specific customer ticket purchase information
                int ticketId;
                cout << endl << "Enter Ticket id: ";
                cin >> ticketId;
                //cin.ignore(numeric_limits<streamsize>::max(), '\n');

                string transactionTime;
                string departureTime;
                string sourceSubway;
                string destinationSubway;

                TicketNode* editableNode = tList->searchByTicketId(ticketId);
                if (editableNode == NULL) {
                    cout << "No such ticket id found." << endl;
                    break;
                }

                // read new information
                cout << "Enter ticket's transaction time: ";
                getline(cin, transactionTime);

                cout << "Enter ticket's departure time: ";
                getline(cin, departureTime);

                cout << "Enter ticket's source station name: ";
                getline(cin, sourceSubway);

                cout << "Enter ticket's destination station name: ";
                getline(cin, destinationSubway);

                // insert new information
                editableNode->transactionTime = transactionTime;
                editableNode->departureTime = departureTime;
                editableNode->sourceSubway = sourceSubway;
                editableNode->targetSubway = destinationSubway;

                cout << endl << "Modified successfully." << endl;
                break;
            }

            case 7: {
                // delete ticket node
                int deleteTicketId;
                cout << endl << "Enter Ticket to delete! (-1 to go back): ";
                cin >> deleteTicketId;
                //cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (deleteTicketId == -1) {
                    break;
                }

                else {
                    tList->deleteByTicketId(deleteTicketId);
                }

                break;
            }
            case 8:
                return;

            default:
                cout << "Invalid input." << endl;
        }
    }
}

void customerChoices(SubwayList* subwayList, TicketList *tList, int customerId, CustomerList *cList) {
    subwayList->printSubways();

    while (true) {
        cout << "Customer Menu: " << endl;
        cout << "1. Search Subway Details" << endl;
        cout << "2. View details between 2 cities" << endl;
        cout << "3. Make a purchase" << endl;
        cout << "4. View purchase transaction history" << endl;
        cout << "5. Delete purchase transaction" << endl;
        cout << "6. Log out" << endl;

        int choice;
        cout << endl << "Enter your choice: ";
        cin >> choice;
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                // show details of 1 station
                int s1;
                cout << endl << "Enter station number: ";
                cin >> s1;
                //cin.ignore(numeric_limits<streamsize>::max(), '\n');

                SubwayNode* sNode = subwayList->searchBySubwayId(s1);
                if (sNode != NULL) {
                    printSubwayInfo(sNode);
                }
                else {
                    cout << "No such station found." << endl;
                }
                break;
            }
            case 2: {
                // show details between 2 station
                int s1, s2;

                cout << endl << "Enter current subway number: ";
                cin >> s1;
                //cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Enter destination subway number: ";
                cin >> s2;
                //cin.ignore(numeric_limits<streamsize>::max(), '\n');

                printSubwayInfoBtwTwo(subwayList, s1, s2);
                break;
            }

            case 3: {
                // make a purchase
                int s1, s2, cChoice;
                string cName = cList->searchCustomer(customerId)->customerName;
                cout << endl << "Enter current station number: ";
                cin >> s1;
                //cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Enter destination station number: ";
                cin >> s2;
                //cin.ignore(numeric_limits<streamsize>::max(), '\n');

                SubwayNode* cSubway = subwayList->searchBySubwayId(s1);
                SubwayNode* dSubway = subwayList->searchBySubwayId(s2);

                if (cSubway == NULL || dSubway == NULL) {
                    cout << "Invalid Subway." << endl;
                    break;
                } else if (cSubway == dSubway) {
                    cout << "Current and Destination Subway are same, Try again." << endl;
                    break;
                }

                string departureTime = getDepartureTime(subwayList, s1, s2);

                string arrivalTime = addTime(departureTime, subwayList->calcTime(s1, s2));

                printSubwayInfoBtwTwo(subwayList, s1, s2);

                cout << "Next LRT coming at: " << departureTime.substr(11) << endl;
                cout << "Estimated Arrival at: " << arrivalTime.substr(11) << endl;

                cout << endl << "Enter (1) to make the payment: ";
                cin >> cChoice;
                //cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (cSubway != NULL && dSubway != NULL) {
                    if (cChoice == 1) {
                        string cDateTime = getDateTime();

                        TicketNode* newNode = new TicketNode(tList->listSize + 1, getId(), cSubway->subwayName, dSubway->subwayName, cDateTime, departureTime, customerId, customerName, arrivalTime);
                        tList->insertLast(newNode);
                        cout << "Payment Completed!!" << endl;
                        printTicketInfo(newNode);
                    }
                }
                break;
            }

            case 4: {
                printThisCustomerTicketInfo(tList, customerId);
                break;
            }

            case 5: {
                int deleteTicketId;
                cout << endl << "Enter Ticket id you wish to delete (-1 to go back): ";
                cin >> deleteTicketId;
                //cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (deleteTicketId == -1) {
                    break;
                } else {
                    tList->deleteByTicketId(deleteTicketId);
                }
                break;
            }

            case 6:
                return;

            default:
                cout << "Invalid Choice!" << endl;
                break;
        }
    }

}

void showTicketDetails(TicketNode* node) {
    cout << "----------------" << endl;
    cout << "Ticket Details" << endl;
    cout << "----------------" << endl;
    cout << "Customer ID:\t " << node->customerId << endl;
    cout << "Customer Name:\t " << node->customerName << endl;
    cout << "Ticket ID:\t " << node->ticketId << endl;
    cout << "Transaction ID:\t "<< node->transactionId <<   endl;
    cout << "Purchase Time:\t" << node->transactionTime << endl;
    cout << "Source Subway:\t" << node->sourceSubway << endl;
    cout << "Destination:\t" << node->targetSubway << endl;
    try {
        cout << "Departure Time:\t" << node->departureTime.substr(11) << endl;
        cout << "Arrival Time:\t" << node->arrivalTime.substr(11) << endl;
    }
    catch (exception) {
        cout << "Not valid date." << endl;
    }
    cout << "----------------" << endl;
}
//
//void showSpecificCustomerTicketInfo(TicketList *tList, int customerId) {
//    int count = 0;
//    TicketNode* current_node = tList->head;
//    cout << "====================================================\n" << endl;
//
//    while (current_node != nullptr) {
//        if (current_node->customerId == customerId) {
//            showTicketDetails(current_node);
//            count++;
//        }
//        current_node = current_node->next;
//
//    }
//    if (count == 0) {
//        cout << "No ticket info found!" << endl;
//    }
//    cout << "====================================================\n" << endl;
//
//    cout << endl;
//}



string getDateTime() {
    time_t currTime;
    struct tm * timeInfo;
    char dateTimeStr[80];

    time(&currTime);
    timeInfo = localtime(&currTime);

    strftime(dateTimeStr, sizeof(dateTimeStr), "%d-%m-%Y %H:%M:%S",timeInfo);
    string str(dateTimeStr);

    return dateTimeStr;
}


string getDepartureTime(SubwayList* subwayList, int cStation, int dStation) {
    string nextDepartureFromRoot;
    string departureFromCurr;

    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    int d = tm.tm_mday;
    int mn = tm.tm_mon + 1;
    int y = tm.tm_year + 1900;
    int h = tm.tm_hour;
    int m = tm.tm_min;
    int s = 00;
    if (m <= 30) {
        m = 30;
    }
    else {
        m = 00;
        h++;
    }
    if (h > 1 && h < 6) {
        h = 6;
    }
    if (h == 24) {
        h = 00;
    }

    // next_departure time from root station
    nextDepartureFromRoot = "" + to_string(d) + "-" + to_string(mn) + "-" + to_string(y) + " " + to_string(h) + "-" + to_string(m) + "-" + to_string(s);
    int time_duration;
    if (cStation < dStation) {

        time_duration = subwayList->calcTime(1, cStation); // time to reach current station

        departureFromCurr = addTime(nextDepartureFromRoot, time_duration); // departure time from current station

    }
    else {
        time_duration = subwayList->calcTime(subwayList->listSize, cStation); // time to reach current station
        cout << time_duration << endl;
        departureFromCurr = addTime(nextDepartureFromRoot, time_duration); // departure time from current station
    }
    return departureFromCurr;

}