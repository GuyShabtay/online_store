/* Assignment: 3
Author: Guy Shabtay, ID: 209298272*/
#pragma warning(disable: 4996)
#ifndef __MANAGER_H__
#define __MANAGER_H__

#include <iostream> 
#include "kidsbooks.h"
#include "readingbooks.h"
#include "musicalbum.h"
#include "song.h"
#include "scifi.h"
#include "action.h"
#include "thriller.h"
#define MAX_STRING_SIZE 120//max size of strings in this program.

class Manager
{
private:
	Store** st;
	int numOfItems;

public:
	Manager();
	int getNumOfItems() { return numOfItems; }
	bool operator==(Store& product);//operator ==
	void operator+=(Store* item);//operator +=
	void operator-=(Store* item);//operator -=
	void addItem(Store& item);//adding a client to data base
	bool removeItem(const long& other);//removes client 
	void print()const;//print the data base
	Store& find(const long& serialNumber);//finds the client to remove
	bool isExists(long serialNumber);
	bool isExistsByName(Store& product);
	bool printItem(long& serialNumber);
	bool isEqual(char* str, const char* other);


};
#endif __MANAGER_H__

