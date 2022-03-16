/* Assignment: 3
Author: Guy Shabtay, ID: 209298272*/
#pragma warning(disable: 4996)
#ifndef __CLIENT_H__
#define __CLIENT_H__
#include "basket.h"
#include <iostream> 
#include "kidsbooks.h"
#include "readingbooks.h"
#include "musicalbum.h"
#include "song.h"
#include "scifi.h"
#include "action.h"
#include "thriller.h""

using namespace std;

class Client
{
private:
	Basket** bs;

	int numOfBaskets;

public:
	Client();
	void operator+=(Basket* newBasket);//operator +=
	void operator-=(Basket* basket);//operator -=
	void addnewProductBasket(Basket& newBasket);
	Basket* getBasket(int i) { return bs[i]; }
	void print() const;//print the data base

	void removeBasket(const long& other);
	void printBasket(long id);
	bool isExists(long id);
	Basket& find(const long& id);

};

#endif __CLIENT_H__

