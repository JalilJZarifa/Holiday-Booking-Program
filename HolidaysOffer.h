#ifndef HOLIDAYS_OFFER_H
#define HOLIDAYS_OFFER_H

#include<iostream>
#include<vector>
#include <string>
#include <fstream>
#include <sstream>

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

class HolidaysOffer {
private:
    vector<Record> records;
    const string FILENAME = "holidayoffer.txt";
public:
    HolidaysOffer();
    ~HolidaysOffer();
    void addOffer();
    void deleteOffer();
    void updateOffer();
};

#endif