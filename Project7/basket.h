/* Assignment: 3
Author: Guy Shabtay, ID: 209298272*/
#pragma warning(disable: 4996)
#ifndef __BASKET_H__
#define __BASKET_H__
using namespace std;
#include <iostream> 
#include "kidsbooks.h"
#include "readingbooks.h"
#include "musicalbum.h"
#include "song.h"
#include "scifi.h"
#include "action.h"
#include "thriller.h"


class Basket
{
private:
	Store** items;
	static long basketCounter;
	long id;
	int numOfItems;


public:

	int getNumOfItems() { return numOfItems; }
	Store* getItem(int i) { return items[i]; }
	Basket(const Basket& other);
	void increaseId() { id = ++basketCounter; }
	long getId() { return id; }
	void setId(long id);
	Basket();
	void operator+=(Store* item);//operator +=
	void addItem(Store& item);
	Basket* addAmountOfItems(Store& item, int amount);
	int countAmountOfItem(char* name);
	int amountOfItem(Store& printer);
	bool isEqual(const char* str, const char* other);
	void print();
	int amountOfDifferentItems();

};
#endif __BASKET_H__

