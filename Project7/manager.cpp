/* Assignment: 3
Author: Guy Shabtay, ID: 209298272*/

#include "manager.h"
#include <iostream> 
#include <string.h> 
#include <cstring> 
using namespace std;


Manager::Manager()//ctor
{
	numOfItems = 0;
	this->st = new Store * [numOfItems];
}

void Manager::operator-=(Store* item) //operator-=
{
	int index, i;
	int count = 0;
	long* serialNumbers = new long[numOfItems];
	Store** TempArr = NULL;//Temporary array
	if (numOfItems == 0)//The array is empty
	{
		exit(1);
	}
	else//The array is not empty
	{
		TempArr = new Store * [numOfItems];//Dynamic memory allocation
		for (i = 0; i < numOfItems; i++)
		{
			if (st[i]->getSerialNumber() == item->getSerialNumber())
				index = i;;
			TempArr[i] = st[i];//Copy to temporary array
			serialNumbers[i] = st[i]->getSerialNumber();

		}

		delete[] st;//Deleting the previous array
		numOfItems--;//Decreasing the array by one
		st = new Store * [numOfItems]; //Dynamic memory allocation
		for (i = 0; i < index; i++)
		{

			st[i] = TempArr[i];
			st[i]->setSerialNumber(serialNumbers[i]);
		}
		for (i = index; i < numOfItems; i++)
		{

			st[i] = TempArr[i + 1];
			st[i]->setSerialNumber(serialNumbers[i + 1]);
		}
	}
	delete[] TempArr;//Deleting Temporary array
	delete[] serialNumbers;
}
//operator+=
void Manager::operator+=(Store* item)
{
	int i;
	Store** TempArr = NULL;//Temporary array
	if (numOfItems == 0)//The array is empty
	{
		numOfItems = 1;
		this->st = new Store * [numOfItems];//Dynamic memory allocation
		st[0] = item->clone();//Inserting the address into the array
		st[0]->setSerialNumber(1);
	}
	else//The array is not empty
	{
		TempArr = new Store * [numOfItems];//Dynamic memory allocation
		for (int i = 0; i < numOfItems; i++)
		{

			TempArr[i] = st[i]->clone();  //Copy to temporary array

		}
		delete[] st;//Deleting the previous array
		numOfItems++;//Increasing the array by one
		this->st = new Store * [numOfItems]; //Dynamic memory allocation
		for (i = 0; i < numOfItems - 1; i++)
		{

			this->st[i] = TempArr[i]->clone();


		}
		this->st[numOfItems - 1] = item->clone();
		delete[] TempArr;//Deleting Temporary array
	}
}
void Manager::addItem(Store& item) //adding item
{
	*this += &item;
}
bool Manager::isExistsByName(Store& product) //check if item exists by name
{
	if (numOfItems == 0)
	{
		return false;
	}
	for (int i = 0; i < numOfItems; i++)
	{
		if (isEqual(st[i]->getName(), product.getName()))
			return true;
		//else
		return false;
	}
}
bool Manager::isExists(long serialNumber) //check if items exixsts
{
	for (int i = 0; i < numOfItems; i++)
	{
		if (st[i]->getSerialNumber() == serialNumber)
			return true;

	}
	//else
	return false;
}
bool Manager::operator==(Store& product) //operator==
{
	if (isExistsByName(product) == true)
		return true;
	//else
	return false;

}
bool Manager::removeItem(const long& other) //removes a client
{
	if (isExists(other) == true) //if he is exists
	{
		*this -= &find(other);//removes him from data base
		return true;
	}
	//else 
	return false;

}

Store& Manager::find(const long& serialNumber) // finds an i tem by a serial number
{
	for (int i = 0; i < numOfItems; i++)
	{
		if (st[i]->getSerialNumber() == serialNumber)// checks if it is indeed the item
		{
			return *st[i];
		}
	}
}
bool Manager::printItem(long& serialNumber) //prints specific item
{
	if (isExists(serialNumber) == true)
	{
		cout << find(serialNumber);
		return true;
		// else
		return false;
	}
}

void Manager::print()const //prints all the data
{
	cout << "the items are:\n";
	for (int i = 0; i < numOfItems; i++)
	{
		cout << *st[i];
	}
}
bool Manager::isEqual(char* str, const char* other) //checking if noth strings are equal
{
	int i;
	for (i = 0; str[i] != '\0'; i++)//while thw string isnt over
	{
		if (str[i] != other[i]) //checks if its the same char
			return false;
	}
	if (other[i] != '\0') //confirms that the secins string isnt longer than the first one
		return false;
	//else
	return true;
}



