#ifndef _grocer_menu_h
#define _grocer_menu_h

#include "ItemCounter.h"

class GrocerMenu {
public:
	GrocerMenu() {
		loadFrequencies("CS210_Project_Three_Input_File.txt");
		saveFrequencyBackup();
	}

	~GrocerMenu() {}

	/** Each line in the file will be treated as an item to count, and added to the frequency tables */
	void loadFrequencies(const char* filename);

	/** Display menu prompt to user until they choose to exit */
	void menuInterface();

	/* Prompt user for the name of an item to retrieve its frequency */
	void lookupFrequency();

	/* List all items with their frequencies, in order*/
	void displayFrequencies();

	/* Display a histogram of item frequencies */
	void displayHistogram();

	/* Store a backup table of the item frequences to frequency.dat */
	void saveFrequencyBackup();

private:
	ItemCounter count;
};

#endif
