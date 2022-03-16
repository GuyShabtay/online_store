/* Assignment: 3
Author: Guy Shabtay, ID: 209298272*/
#define _CRT_SECURE_NO_WARNINGS
#include "books.h"
#include <string.h>
#include <iostream> 
using namespace std;


Books::Books()//ctor
{
	pages = 0;
}
Books::Books(int pages)//ctor
{
	this->pages = pages;
}
void Books::priceCalculate()//only a pure vitual method
{
}
Books::~Books()
{
}