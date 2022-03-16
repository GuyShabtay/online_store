/* Assignment: 3
Author: Guy Shabtay, ID: 209298272*/
#include "action.h"
#include <iostream> 
#include <string.h> 
using namespace std;



Action::Action(char* name, int  outYear, int level) :Movies(level), Store(name, outYear)
{

	if (levelSelect(level) == false)
	{
		cout << "Wrong level number! please try again:" << endl;

	}
}
bool Action::levelSelect(int level)//confirms the level is correct
{
	if (level < 1 || level>5)
		return false;
	//else
	return true;
}
void Action::toOs(ostream& os) const//prints the additional information of this product type
{
	os << name << "> <" << outYear << "> <" << level << ">" << endl;

}
Action::Action(const Action& other)//copy ctor
{

	this->name = new char[strlen(other.name) + 1];//creats a string dinamiclly
	strcpy(this->name, other.name);//copys the given string(parameter) in to the location of the dinamic string
	this->outYear = other.outYear;
	this->serialNumber = other.serialNumber;
	priceCalculate();
	this->price = other.price;

	this->level = other.level;
}




