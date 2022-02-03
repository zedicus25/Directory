#include "c_Directory.h"
#include <fstream>
void c_Directory::showElement(int v)
{
	std::cout << this->mas[v].name << "\t" << this->mas[v].occupation << "\t" << this->mas[v].owner <<
		"\t" << this->mas[v].adress << "\t" << this->mas[v].number << "\n";
}

std::string c_Directory::stringForSave(int v)
{
	std::string res;
	res += mas[v].adress;
	res += ':';
	res += mas[v].name;
	res += ':';
	res += mas[v].number;
	res += ':';
	res += mas[v].occupation;
	res += ':';
	res += mas[v].owner;
	return res;
}

c_Directory::c_Directory()
{
	this->mas = new Firma[0];
	this->size = 0;
}

void c_Directory::add(Firma v)
{
	Firma* tmp = new Firma[this->size];
	for (size_t i = 0; i < this->size; i++)
	{
		tmp[i].adress = mas[i].adress;
		tmp[i].name = mas[i].name;
		tmp[i].number = mas[i].number;
		tmp[i].occupation = mas[i].occupation;
		tmp[i].owner = mas[i].owner;
	}
	this->mas = nullptr;
	this->mas = new Firma[this->size + 1];

	for (size_t i = 0; i < this->size; i++)
	{
		mas[i].adress = tmp[i].adress;
		mas[i].name = tmp[i].name;
		mas[i].number = tmp[i].number;
		mas[i].occupation = tmp[i].occupation;
		mas[i].owner = tmp[i].owner;
	}

	mas[this->size].adress = v.adress;
	mas[this->size].name = v.name;
	mas[this->size].number= v.number;
	mas[this->size].occupation= v.occupation;
	mas[this->size].owner= v.owner;

	this->size++;
	delete[] tmp;
}

void c_Directory::remove(std::string name)
{
	Firma* tmp = new Firma[this->size];
	for (size_t i = 0; i < this->size; i++)
	{
		tmp[i].adress = mas[i].adress;
		tmp[i].name = mas[i].name;
		tmp[i].number = mas[i].number;
		tmp[i].occupation = mas[i].occupation;
		tmp[i].owner = mas[i].owner;
	}
	mas = nullptr;
	this->mas = new Firma[this->size - 1];
	
	int pos = 0;
	for (size_t i = 0; i < this->size; i++)
	{
		if (tmp[i].name == name) {
			pos = i;
			break;
		}
	}

	for (size_t i = 0; i < pos; i++)
	{
		mas[i].adress = tmp[i].adress;
		mas[i].name = tmp[i].name;
		mas[i].number = tmp[i].number;
		mas[i].occupation = tmp[i].occupation;
		mas[i].owner = tmp[i].owner;
	}
	for (size_t i = pos+1; i < this->size; i++)
	{
		mas[i-1].adress = tmp[i].adress;
		mas[i-1].name = tmp[i].name;
		mas[i-1].number = tmp[i].number;
		mas[i-1].occupation = tmp[i].occupation;
		mas[i-1].owner = tmp[i].owner;
	}
	this->size--;
	delete[] tmp;
}

void c_Directory::print()
{
	for (size_t i = 0; i < this->size; i++)
	{
		std::cout << this->mas[i].name << "\t" << this->mas[i].occupation << "\t" << this->mas[i].owner <<
			"\t" << this->mas[i].adress << "\t" << this->mas[i].number << "\n";
;	}
}

void c_Directory::searchByName(std::string name)
{
	for (size_t i = 0; i < this->size; i++)
	{
		if (mas[i].name == name) {
			showElement(i);
		}	
	}
}

void c_Directory::searchByOwner(std::string owner)
{
	for (size_t i = 0; i < this->size; i++)
	{
		if (mas[i].owner == owner) {
			showElement(i);
		}	
	}
}

void c_Directory::searchByNumber(std::string number)
{
	for (size_t i = 0; i < this->size; i++)
	{
		if (mas[i].number == number) {
			showElement(i);
		}
	}
}

void c_Directory::searchByOccupation(std::string occupation)
{
	for (size_t i = 0; i < this->size; i++)
	{
		if (mas[i].occupation == occupation) {
			showElement(i);
		}	
	}
}

void c_Directory::saveToFile()
{
	if (this->size < 0) {
		return;
	}
	std::ofstream out("Data.txt");
	if (out.is_open() == false) {
		std::cout << "Error\n";
		return;
	}

	for (size_t i = 0; i < this->size; i++)
	{
		out << this->stringForSave(i) << "\n";
	}
	out.close();
	std::cout << "Done!\n";
}

void c_Directory::loadFromFile()
{
	std::ifstream in("Data.txt");
	if (in.is_open() == false) {
		std::cout << "Error\n";
		return;
	}
	std::string str;
	std::string sep = ":";
	size_t pos = 0;
	while (!in.eof())
	{
		std::getline(in, str);
		Firma fr;
		pos = str.find(sep);
		fr.adress = str.substr(0, pos);
		str.erase(0, pos + sep.length());
		pos = str.find(sep);
		fr.name = str.substr(0, pos);
		str.erase(0, pos + sep.length());
		pos = str.find(sep);
		fr.number = str.substr(0, pos);
		str.erase(0, pos + sep.length());
		pos = str.find(sep);
		fr.occupation = str.substr(0, pos);
		str.erase(0, pos + sep.length());
		pos = str.find(sep);
		fr.owner = str.substr(0, pos);
		str.erase(0, pos + sep.length());
		pos = str.find(sep);
		this->add(fr);
		
	}
	std::cout << "Done!\n";
}
