/* Assignment: 3
Author: Guy Shabtay, ID: 209298272*/
#define MAX_PRICE 100
#define MIN_PRICE 10
#include "kidsbooks.h"

using namespace std;



KidsBooks::KidsBooks(char* name, int pages, int outYear, int minAge) :Books(pages), Store(name, outYear)//ctor
{

	this->minAge = minAge;
	priceCalculate();
}
void KidsBooks::priceCalculate()//pricing the item by the given instuctions
{

	price = pages / 2.0;
	if (price > MAX_PRICE)
		price = MAX_PRICE;
	if (price < MIN_PRICE)
		price = MIN_PRICE;

}
void KidsBooks::toOs(ostream& os) const//prints the additional information of this product type
{
	os << name << "> <" << pages << "> <" << outYear << "> <" << minAge << ">" << endl;
}
KidsBooks::KidsBooks(const KidsBooks& other)//copy ctor
{
	this->name = new char[strlen(other.name) + 1];//creats a string dinamiclly
	strcpy(this->name, other.name);//copys the given string(parameter) in to the location of the dinamic string
	this->pages = other.pages;
	this->outYear = other.outYear;
	this->minAge = other.minAge;
	this->serialNumber = other.serialNumber;
	priceCalculate();
	this->price = other.price;

}

