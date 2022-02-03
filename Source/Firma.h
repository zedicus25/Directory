#pragma once
#include <iostream>
#include <string>
struct Firma
{
	std::string name;
	std::string owner;
	std::string number;
	std::string adress;
	std::string occupation;

	Firma()
	{

	}

	Firma(std::string name, std::string owner, std::string number, std::string adress, std::string occupation)
	{
		this->name = name;
		this->owner = owner;
		this->number = number;
		this->adress = adress;
		this->occupation = occupation;
	}
};