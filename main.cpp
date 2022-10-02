#include <iostream>

#include "SubwayList.h"
#include "SubwayNode.h"
#include "TicketNode.h"
#include "CustomerList.h"
#include "TicketList.h"
#include "CustomerNode.h"
#include "Utils.h"
#include "Admin.h"
using namespace std;


int main() {
    SubwayList* subwayList = createSubwayList();
    CustomerList* customerList = createSampleCustomer();
    TicketList* ticketList = createSampleTicketList();
    Admin* admins;
    admins = createAdmin();

    cout << endl << "Railway System" << endl;
    cout << "-------------------------------" << endl;
    bool flag = true;
    int loginChoice;

    while(flag) {
        printLogin();

        cout << endl << "Enter menu number: ";
        cin >> loginChoice;

        switch(loginChoice) {
            case 1: {
                break;
            }

            default:
                cout << endl << "Invalid input." << endl;
        }
    }

    return 0;
}
