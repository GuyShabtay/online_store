/* Assignment: 3
Author: Guy Shabtay, ID: 209298272*/
#include "song.h"
#include <iostream> 
#include <string.h> 
using namespace std;



Song::Song()//ctor
{

	this->songName = nullptr;
	this->length = 0;
}
Song::Song(char* songName, int length)//ctor
{
	if (songName != NULL)
		this->songName = new char[strlen(songName) + 1];
	this->songName = songName;
	this->length = length;
}
Song::~Song()//dtor
{
	delete[]songName;
	songName = nullptr;// makes it null
}
