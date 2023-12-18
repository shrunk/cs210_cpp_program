// Implementations for methods of the GrocerMenu class
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>
#include "GrocerMenu.h"

void GrocerMenu::loadFrequencies(const char* filename) {
	ifstream f;
	f.open(filename);
	if (!f.is_open()) {
		cout << "warning: failed to open " << filename << endl;
		return;
	}
	string line;
	while (f.good()) {
		f >> line;
		count.add(line);
	}
	f.close();
}

void GrocerMenu::menuInterface() {
	cout << "Welcome to the Grocer Corner sales frequency interface." << endl;
	bool done = false;
	while (!done) {
		cout << endl;
		cout << "1. Look up item frequency" << endl;
		cout << "2. List all item frequencies" << endl;
		cout << "3. Display item frequency histogram" << endl;
		cout << "4. Exit" << endl;
		cout << "Choose a an option: ";
		int choice;
		cin >> choice;
		if (cin.fail()) {
			// handle invalid inputs
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			choice = -1;
		}
		switch (choice) {
		case 1: lookupFrequency(); break;
		case 2: displayFrequencies(); break;
		case 3: displayHistogram(); break;
		case 4: done = true; break;
		default: cout << "Invalid option" << endl; break;
		}
	}
	cout << "Exiting" << endl;
}

void GrocerMenu::lookupFrequency() {
	cout << "Enter an item name to look up its sales frequency: ";
	string name;
	cin >> name;
	int freq = count.get(name);
	if (freq == 0) cout << "No records of sales for " << name << " were recorded." << endl;
	else cout << freq << " sales of " << name << " recorded." << endl;
}

void GrocerMenu::displayFrequencies() {
	cout << "All item sales frequencies:" << endl;
	for (map<string, int>::iterator it = count.iterate(); it != count.end(); ++it) {
		cout << "  " << it->first << " " << it->second << endl;
	}
}

void GrocerMenu::displayHistogram() {
	// histogram version, eg Potatoes ****
	cout << "All item sales histogram:" << endl;
	for (map<string, int>::iterator it = count.iterate(); it != count.end(); ++it) {
		cout << "  " << setw(12) << it->first << " " << string(it->second, '*') << endl;
	}
}

void GrocerMenu::saveFrequencyBackup() {
	// write the frequencies to frequency.day
	ofstream outf;
	outf.open("frequency.dat");
	for (map<string, int>::iterator it = count.iterate(); it != count.end(); ++it) {
		outf << it->first << " " << it->second << endl;
	}
	outf.close();
}
