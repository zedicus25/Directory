#include "c_Directory.h"

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
