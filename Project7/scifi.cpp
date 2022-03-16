/* Assignment: 3
Author: Guy Shabtay, ID: 209298272*/
#include "scifi.h"
#include <iostream> 
#include <string.h> 
using namespace std;



SciFi::SciFi(char* name, int  outYear, int level) :Movies(level), Store(name, outYear)
{
	levelSelect(level);

}
bool SciFi::levelSelect(int level) //confirms the level is correct
{

	while (this->level < 1 || this->level>9)
	{
		cout << "Wrong level number! please try again:" << endl;
		cin >> level;
		this->level = level;

	}
	return true;
}
void SciFi::toOs(ostream& os) const//prints the additional information of this product type
{
	os << name << "> <" << outYear << "> <" << level << ">" << endl;

}
SciFi::SciFi(const SciFi& other)//copy ctor
{
	this->name = new char[strlen(other.name) + 1];//creats a string dinamiclly
	strcpy(this->name, other.name);//copys the given string(parameter) in to the location of the dinamic string
	this->outYear = other.outYear;
	this->serialNumber = other.serialNumber;
	priceCalculate();
	this->price = other.price;

	this->level = other.level;

}