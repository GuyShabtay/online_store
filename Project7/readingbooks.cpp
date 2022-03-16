/* Assignment: 3
Author: Guy Shabtay, ID: 209298272*/
#define MAX_PRICE 100
#define MIN_PRICE 10
#include "readingbooks.h"
#include <iostream> 
using namespace std;


//constractor:inserts the parameters in to the object
ReadingBooks::ReadingBooks(char* name, int  pages, int outYear, char* janer) :Books(pages), Store(name, outYear)//ctor
{
	this->janer = new char[strlen(janer) + 1];
	this->janer = janer;
	priceCalculate();
}
void ReadingBooks::priceCalculate()//pricing the item by the given instuctions
{
	price = pages * 2;
	if (price > MAX_PRICE)
		price = MAX_PRICE;
	if (price < MIN_PRICE)
		price = MIN_PRICE;

}
ReadingBooks::~ReadingBooks()
{
	delete[] janer;
	janer = nullptr;// makes it null
}

void ReadingBooks::toOs(ostream& os) const//prints the additional information of this product type
{
	os << name << "> <" << pages << "> <" << outYear << "> <" << janer << ">" << endl;
}
ReadingBooks::ReadingBooks(const ReadingBooks& other)//copy ctor
{
	this->name = new char[strlen(other.name) + 1];//creats a string dinamiclly
	strcpy(this->name, other.name);//copys the given string(parameter) in to the location of the dinamic string
	this->pages = other.pages;
	this->outYear = other.outYear;
	this->janer = new char[strlen(other.janer) + 1];//creats a string dinamiclly
	strcpy(this->janer, other.janer);//copys the given string(parameter) in to the location of the dinamic string
	this->serialNumber = other.serialNumber;
	priceCalculate();
	this->price = other.price;

}

