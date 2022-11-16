#include "Booking.h"

Booking::Booking()
{
	ifstream input(FILENAME);
	if (!input) {
		cout << "File do not exist" << endl;
	}
	else {
		string line;
		cin.ignore();
		while (getline(input, line)) {
			stringstream s(line);
			string text;
			Record r;
			getline(s, text, ',');
			r.HolidayID = text;
			getline(s, text, ',');
			r.Country = text;
			getline(s, text, ',');
			r.Category = text;
			getline(s, text, ',');
			r.Description = text;
			getline(s, text, ',');
			r.StartDate = text;
			getline(s, text, ',');
			r.Duration = text;
			getline(s, text, ',');
			r.Price = stod(text);
			records.push_back(r);
		}
	}

	input.close();
}

Booking::~Booking()
{
	ofstream ofs;
	ofs.open(BOOKINGFILE, ofstream::out | ofstream::trunc);
	for (int i = 0; i < bookings.size(); i++) {
		BookingRecord r = bookings[i];
		ofs << r.name << "," << r.emailAddress << "," << r.HolidayID << endl;
	}
	ofs.close();
}

void Booking::searchByCountry()
{
	cin.ignore();
	cout << "Enter Country : ";
	string country;
	getline(cin, country);
	for (int i = 0; i < records.size(); i++) {
		if (records[i].Country == country) {
			cout << "Holiday ID : " << records[i].HolidayID << endl;
			cout << "Country : " << records[i].Country << endl;
			cout << "Category : " << records[i].Category << endl;
			cout << "Description : " << records[i].Description << endl;
			cout << "Start Date : " << records[i].StartDate << endl;
			cout << "Duration : " << records[i].Duration << endl;
			cout << "Price : " << records[i].Price << endl;
			cout << "-----------------------------------------------------" << endl;
		}
	}
}

void Booking::searchByCategory()
{
	cin.ignore();
	cout << "Enter Category : ";
	string category;
	getline(cin, category);
	for (int i = 0; i < records.size(); i++) {
		if (records[i].Category == category) {
			cout << "Holiday ID : " << records[i].HolidayID << endl;
			cout << "Country : " << records[i].Country << endl;
			cout << "Category : " << records[i].Category << endl;
			cout << "Description : " << records[i].Description << endl;
			cout << "Start Date : " << records[i].StartDate << endl;
			cout << "Duration : " << records[i].Duration << endl;
			cout << "Price : " << records[i].Price << endl;
			cout << "-----------------------------------------------------" << endl;
		}
	}
}

void Booking::makeBooking()
{
	cin.ignore();
	BookingRecord b;
	cout << "Enter the customer name : ";
	getline(cin, b.name);
	cout << "Enter the email address : ";
	getline(cin, b.emailAddress);
	cout << "Enter valid Holiday id : ";
	getline(cin, b.HolidayID);
	bookings.push_back(b);
}
