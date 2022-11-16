#include "HolidaysOffer.h"

HolidaysOffer::HolidaysOffer()
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

HolidaysOffer::~HolidaysOffer()
{
	ofstream ofs;
	ofs.open(FILENAME, ofstream::out | ofstream::trunc);
	for (int i = 0; i < records.size(); i++) {
		Record r = records[i];
		ofs << r.HolidayID << "," << r.Country << "," << r.Category << "," << r.Description << "," << r.StartDate << "," << r.Duration << "," << r.Price << endl;
	}
	ofs.close();
}

void HolidaysOffer::addOffer()
{
	Record r;
	cin.ignore();
	cout << "Enter Holiday ID (max length-8) : ";
	getline(cin,r.HolidayID);
	cout << "Enter country : ";
	getline(cin,r.Country);
	cout << "Enter Category (walking, city break or skiing) : ";
	getline(cin, r.Category);
	cout << "Enter Description : ";
	getline(cin, r.Description);
	cout << "Enter Start Date : ";
	getline(cin, r.StartDate);
	cout << "Enter Duration : ";
	getline(cin, r.Duration);
	cout << "Enter price : ";
	cin >> r.Price;
	cin.ignore();
	records.push_back(r);
}

void HolidaysOffer::deleteOffer()
{
	cout << "Enter holiday id : ";
	string id;
	cin >> id;
	int k = -1;
	for (int i = 0; i < records.size(); i++) {
		if (records[i].HolidayID == id) {
			k = i;
			break;
		}
	}
	if (k < 0) {
		cout << "Record not found !!!" << endl;
		return;
	}
	records.erase(records.begin() + k);
	cout << "Record deleted successfully" << endl;
}

void HolidaysOffer::updateOffer()
{
	Record r;
	cin.ignore();
	cout << "Enter Holiday ID (max length-8) to update : ";
	getline(cin, r.HolidayID);
	cout << "Enter country : ";
	getline(cin, r.Country);
	cout << "Enter Category (walking, city break or skiing) : ";
	getline(cin, r.Category);
	cout << "Enter Description : ";
	getline(cin, r.Description);
	cout << "Enter Start Date : ";
	getline(cin, r.StartDate);
	cout << "Enter Duration : ";
	getline(cin, r.Duration);
	cout << "Enter price : ";
	cin >> r.Price;
	cin.ignore();
	for (int i = 0; i < records.size(); i++) {
		if (records[i].HolidayID == r.HolidayID) {
			records[i] = r;
			cout << "Record updated successfully!!" << endl;
			return;
		}
	}
	cout << "Record not found !" << endl;

}
