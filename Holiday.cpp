// Holiday.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "HolidaysOffer.h"

void printMenu() {
    cout << "Choose a option :" << endl;
    cout << "1. Add Record" << endl;
    cout << "2. Delete Record" << endl;
    cout << "3. Update Record" << endl;
    cout << "4. Exit" << endl;
}

int main()
{
    HolidaysOffer offer;
    bool cont = true;
    while (cont) {
        printMenu();
        cout << "Enter your choice : ";
        int n;
        cin >> n;
        switch (n) {
        case 1: offer.addOffer(); break;
        case 2: offer.deleteOffer(); break;
        case 3: offer.updateOffer(); break;
        case 4: cont = false; break;
        default: cout << "Enter correct choice" << endl;
        }
    }
}
