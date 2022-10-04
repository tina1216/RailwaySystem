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
                int customerIds = loginCustomer(customerList);
                if(customerIds != NULL) {
                    customerChoices(subwayList, ticketList, customerIds, customerList);
                }
                break;
            }
            case 2: {
                int customerIds = signupCustomer(customerList);
                if(customerIds != NULL) {
                    customerChoices(subwayList, ticketList, customerIds, customerList);
                }
                break;
            }
            case 3: {
                if(loginAdmin(admins)) {
                    adminChoices(subwayList, ticketList);
                } else {
                    cout << "Login failed." << endl;
                }
                break;
            }
            case 4: {
                loginChoice = -1;
                break;
            }
            default:
                cout << endl << "Invalid input." << endl;
        }
    }

    delete customerList, subwayList, ticketList, admins;
    return 0;
}
