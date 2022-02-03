#pragma once
#include "Firma.h"
class c_Directory
{
private:
	Firma* mas;
	unsigned int size;

	void showElement(int v);
	std::string stringForSave(int v);
	
public:
	c_Directory();

	void add(Firma v);
	void remove(std::string name);
	void print();
	

	void searchByName(std::string name);
	void searchByOwner(std::string owner);
	void searchByNumber(std::string number);
	void searchByOccupation(std::string occupation);

	void saveToFile();
	void loadFromFile();
	
};

