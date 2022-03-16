/* Assignment: 3
Author: Guy Shabtay, ID: 209298272*/
#define MOVIE_PRICE 20
#include "movies.h"
#include <iostream> 
#include <string.h> 
using namespace std;



Movies::Movies()//ctor
{
	priceCalculate();
}
Movies::Movies(int level)//ctor
{
	this->level = level;
	priceCalculate();
}
void Movies::priceCalculate() //Calculate price
{
	price = MOVIE_PRICE;
}
Movies::~Movies()
{
}

