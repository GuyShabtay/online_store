/* Assignment: 3
Author: Guy Shabtay, ID: 209298272*/
#include "basket.h"
#include <iostream> 
#include <string.h> 
using namespace std;


long Basket::basketCounter;


void Basket::setId(long id)
{
	this->id = id;
}
Basket::Basket() //ctor
{
	numOfItems = 0;
	this->id = basketCounter;
}
Basket::Basket(const Basket& other) //ctor
{
	id = other.id;
	numOfItems = other.numOfItems;
	items = new Store * [numOfItems];
	for (int i = 0; i < numOfItems; i++)
	{
		items[i] = other.items[i]->clone();

	}



}

//operator+=
void Basket::operator+=(Store* item)
{
	int i;
	Store** TempArr = NULL;//Temporary array
	if (numOfItems == 0)//The array is empty
	{
		numOfItems = 1;
		this->items = new Store * [numOfItems];//Dynamic memory allocation
		items[0] = item->clone();//Inserting the address into the array

	}
	else//The array is not empty
	{
		TempArr = new Store * [numOfItems];//Dynamic memory allocation
		for (int i = 0; i < numOfItems; i++)
		{
			TempArr[i] = items[i]->clone();  //Copy to temporary array
		}
		delete[] items;//Deleting the previous array
		numOfItems++;//Increasing the array by one
		this->items = new Store * [numOfItems]; //Dynamic memory allocation
		for (i = 0; i < numOfItems - 1; i++)
		{

			this->items[i] = TempArr[i]->clone();
		}
		this->items[numOfItems - 1] = item->clone();
		delete[] TempArr;//Deleting Temporary array

	}
}
void Basket::addItem(Store& item) //adding item
{
	*this += &item;
}




void Basket::print() //prints
{
	for (int i = 0; i < numOfItems; i++)
	{
		cout << *items[i];
		cout << "<Amount> <" << this->amountOfItem(*items[i]) << ">" << endl;
		i += ((this->amountOfItem(*items[i])) - 1);
	}
}
int Basket::amountOfItem(Store& printer) //counting amount of times that item in the basket
{
	int amount = 0;
	for (int i = 0; i < numOfItems; i++)
	{
		if (isEqual(items[i]->getName(), printer.getName()))
			amount++;
	}
	return amount;
}
int Basket::countAmountOfItem(char* name) //counting amount of times that item in the basket by name
{
	int amount = 0;
	for (int i = 0; i < numOfItems; i++)
	{
		if (isEqual(items[i]->getName(), name))
			amount++;
	}
	return amount;
}
int Basket::amountOfDifferentItems() //counting how many different items in the basket
{
	char* check = items[0]->getName();
	int amount = 0;
	for (int i = 0; i < numOfItems; i++)
	{
		if (isEqual(items[i]->getName(), check) == false)
		{
			check = items[i]->getName();
			amount++;
		}
	}
	amount++;
	return amount;
}


bool Basket::isEqual(const char* str, const char* other)
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
