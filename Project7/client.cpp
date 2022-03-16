/* Assignment: 3
Author: Guy Shabtay, ID: 209298272*/
#define _CRT_SECURE_NO_WARNINGS
#include "client.h"
#include "menu.h"
#include <string.h>
#include <iostream> 
using namespace std;

Client::Client() //ctor
{
	numOfBaskets = 0;
	this->bs = new Basket * [numOfBaskets];
}

void Client::operator-=(Basket* basket) //operator -=
{
	int index, i;
	int count = 0;
	long* serialNumbers = new long[numOfBaskets];
	Basket** TempArr = NULL;//Temporary array
	if (numOfBaskets == 0)//The array is empty
	{
		exit(1);
	}
	else//The array is not empty
	{
		TempArr = new Basket * [numOfBaskets];//Dynamic memory allocation
		for (i = 0; i < numOfBaskets; i++)
		{
			if (bs[i]->getId() == basket->getId())
				index = i;;
			TempArr[i] = bs[i];//Copy to temporary array
			serialNumbers[i] = bs[i]->getId();

		}

		delete[] bs;//Deleting the previous array
		numOfBaskets--;//Decreasing the array by one
		bs = new Basket * [numOfBaskets]; //Dynamic memory allocation
		for (i = 0; i < index; i++)
		{

			bs[i] = TempArr[i];
			bs[i]->setId(serialNumbers[i]);
		}
		for (i = index; i < numOfBaskets; i++)
		{

			bs[i] = TempArr[i + 1];
			bs[i]->setId(serialNumbers[i + 1]);
		}
	}
	delete[] TempArr;//Deleting Temporary array
	delete[] serialNumbers;
}

//operator+=
void Client::operator+=(Basket* newBasket)
{
	int i;
	Basket** TempArr = NULL;//Temporary array
	if (numOfBaskets == 0)//The array is empty
	{
		numOfBaskets = 1;
		this->bs = new Basket * [numOfBaskets];//Dynamic memory allocation
		bs[0] = newBasket;//Inserting the address into the array

	}
	else//The array is not empty
	{
		TempArr = new Basket * [numOfBaskets];//Dynamic memory allocation
		for (int i = 0; i < numOfBaskets; i++)
		{

			TempArr[i] = bs[i];  //Copy to temporary array

		}
		delete[] bs;//Deleting the previous array
		numOfBaskets++;//Increasing the array by one
		this->bs = new Basket * [numOfBaskets]; //Dynamic memory allocation
		for (i = 0; i < numOfBaskets - 1; i++)
		{
			this->bs[i] = TempArr[i];

		}
		this->bs[numOfBaskets - 1] = newBasket;

		delete[] TempArr;//Deleting Temporary array

	}
}
void Client::addnewProductBasket(Basket& newBasket) //adding a new basket
{
	newBasket.increaseId();
	*this += &newBasket;
}
void Client::print() const //prints
{
	cout << "the baskets are:\n";
	for (int i = 0; i < numOfBaskets; i++)
	{
		cout << "<" << "Product Basket" << "> <" << bs[i]->getId() << ">" << endl;
		bs[i]->print();
	}
}
void Client::removeBasket(const long& other)
{
	*this -= &find(other);//removes him from data base
}


void Client::printBasket(long id) //print specific basket
{
	cout << "<" << "Product Basket" << "> <" << find(id).getId() << ">" << endl;
	find(id).print();

}

bool Client::isExists(long id) //cheking if exists
{
	for (int i = 0; i < numOfBaskets; i++)
	{
		if (bs[i]->getId() == id)
			return true;
	}
	//else
	return false;
}
Basket& Client::find(const long& id) //finds basket by id
{
	for (int i = 0; i < numOfBaskets; i++)
	{
		if (bs[i]->getId() == id)// checks if it is indeed the client
		{
			return *bs[i];
		}
	}
}



