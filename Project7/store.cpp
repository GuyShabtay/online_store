/* Assignment: 3
Author: Guy Shabtay, ID: 209298272*/

#include "store.h"
#include <iostream> 
#include <string.h> 
using namespace std;

long Store::counter;//static counter

void Store::setSerialNumber1()
{
	this->serialNumber = ++counter;
}
void Store::setSerialNumber(long serialNumber)//set Serial Number
{
	this->serialNumber = serialNumber;
}

long Store::getSerialNumber()
{
	return serialNumber;
}
Store::Store()//ctor
{
	name = nullptr;
	if (name != NULL)
		this->name = new char[strlen(name) + 1];
}

Store::Store(char* name, int outYear)//ctor
{
	this->price = 0;

	this->serialNumber = ++counter;
	this->name = nullptr;
	if (name != NULL)
		this->name = new char[strlen(name) + 1];
	this->name = name;
	this->outYear = outYear;
}
Store:: ~Store() //dtor
{
	delete[]name;
	name = nullptr;// makes it null
}
ostream& operator<<(ostream& os, Store& printer) //prints the common data to all the items than sends a method that each item will add his own data 
{
	os << "<" << printer.getSerialNumber() << "> <" << printer.getPrice() << "> <" << printer.getType() << "> <";//prints the parameters
	printer.toOs(os);//method that each product has
	return os;
}
bool Store::operator==(char* other) const //operator==
{
	int i;
	for (i = 0; this->name[i] != '\0'; i++)//while thw string isnt over
	{
		if (this->name[i] != other[i]) //checks if its the same char
			return false;
	}
	if (other[i] != '\0') //confirms that the secins string isnt longer than the first one
		return false;
	//else
	return true;
}




