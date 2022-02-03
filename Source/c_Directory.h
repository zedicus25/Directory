#pragma once
#include "Firma.h"
class c_Directory
{
private:
	Firma* mas;
	unsigned int size;
public:
	c_Directory();

	void add(Firma v);
	void remove(std::string name);
	void print();

	Firma* searchByName(std::string name);
	Firma* searchByOwner(std::string owner);
	Firma* searchByNumber(unsigned int number);
	Firma* searchByOccupation(std::string occupation);

	void saveToFile();
	void loadFromFile();
	
};

