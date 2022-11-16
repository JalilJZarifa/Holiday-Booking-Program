// HolidayClient.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Booking.h"

int main()
{
    Booking b;
    bool cont = true;
    while (cont) {
        cout << "1. Search by Country" << endl;
        cout << "2. Search by category" << endl;
        cout << "3. Book a holiday" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice : ";
        int n;
        cin >> n;
        switch (n) {
        case 1: b.searchByCountry(); break;
        case 2: b.searchByCategory(); break;
        case 3: b.makeBooking(); break;
        case 4: cont = false; break;
        default: cout << "Enter correct choice" << endl;
        }
    }
}

