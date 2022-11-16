#ifndef BOOKING_H
#define BOOKING_H

#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

struct Record {
    string HolidayID;
    string Country;
    string Category;
    string Description;
    string StartDate;
    string Duration;
    double Price;
};

struct BookingRecord {
    string name;
    string emailAddress;
    string HolidayID;
};

class Booking {
private:
	vector<Record> records;
    vector<BookingRecord> bookings;
    const string FILENAME = "holidayoffer.txt";
    const string BOOKINGFILE = "booking.txt";

public:
    Booking();
    ~Booking();
    void searchByCountry();
    void searchByCategory();
    void makeBooking();

};


#endif // !BOOKING_H
