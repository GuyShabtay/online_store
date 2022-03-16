/* Assignment: 3
Author: Guy Shabtay, ID: 209298272*/
#define MAX_PRICE 100
#define MIN_PRICE 10
#include "musicalbum.h"
#include <iostream> 
using namespace std;




MusicAlbum::MusicAlbum(char* name, int outYear, Song** list) :Store(name, outYear)//ctor
{

	this->list = new Song * [numOfSongs];//Dynamic memory allocation
	for (int i = 0; i < numOfSongs; i++)
	{
		this->numOfSongs = 0;
		addSong(*list[i]);


	}


}

//operator+=
void MusicAlbum::operator+=(Song* item)
{
	int i;
	Song** TempArr = NULL;//Temporary array
	if (numOfSongs == 0)//The array is empty
	{
		numOfSongs = 1;
		this->list = new Song * [numOfSongs];//Dynamic memory allocation
		list[0] = item;//Inserting the address into the array

	}
	else//The array is not empty
	{
		TempArr = new Song * [numOfSongs];//Dynamic memory allocation
		for (int i = 0; i < numOfSongs; i++)
		{

			TempArr[i] = list[i];  //Copy to temporary array

		}
		delete[] list;//Deleting the previous array
		numOfSongs++;//Increasing the array by one
		this->list = new Song * [numOfSongs]; //Dynamic memory allocation
		for (i = 0; i < numOfSongs - 1; i++)
		{

			this->list[i] = TempArr[i];

			this->list[numOfSongs - 1] = item;



			delete[] TempArr;//Deleting Temporary array

		}
	}
}
void MusicAlbum::addSong(Song& item)//adding a song
{
	*this += &item;
}
void MusicAlbum::priceCalculate() //pricing the item by the given instuctions
{
	price = numOfSongs * 5;
	if (price > MAX_PRICE)
		price = MAX_PRICE;
	if (price < MIN_PRICE)
		price = MIN_PRICE;
}
MusicAlbum::~MusicAlbum()//dtor
{

	for (int i = 0; i < numOfSongs; i++)
	{
		list[i]->~Song();
		delete list[i];
	}
	delete[] list;
}
void MusicAlbum::toOs(ostream& os) const//prints the additional information of this product type
{
	os << name << "> <" << outYear << ">" << endl;
	for (int i = 0; i < numOfSongs; i++)
	{
		os << "<" << list[i]->getSongName() << "> <" << list[i]->getLength() << ">" << "hey im song" << endl;
	}

}

MusicAlbum::MusicAlbum(const MusicAlbum& other)//copy ctor
{
	this->name = new char[strlen(other.name) + 1];//creats a string dinamiclly
	strcpy(this->name, other.name);//copys the given string(parameter) in to the location of the dinamic string
	this->outYear = other.outYear;
	this->serialNumber = other.serialNumber;
	priceCalculate();
	this->price = other.price;
	this->list = new Song * [other.numOfSongs];//Dynamic memory allocation
	for (int i = 0; i < other.numOfSongs; i++)
	{
		addSong(*list[i]);

	}

}

