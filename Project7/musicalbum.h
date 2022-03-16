/* Assignment: 3
Author: Guy Shabtay, ID: 209298272*/
#pragma warning(disable: 4996)
#ifndef __MUSICALBUM_H__
#define __MUSICALBUM_H__
#include "song.h"
#include "store.h"
#include <iostream> 
using namespace std;

class MusicAlbum : public Store
{
private:
	Song** list;
	int numOfSongs;
public:
	MusicAlbum(char* name, int outYear, Song** list);
	virtual void priceCalculate();
	~MusicAlbum();
	virtual void toOs(ostream& os) const;
	virtual const char* getType() const { return "Music Album"; }
	virtual Store* clone() const { return new MusicAlbum(*this); }

	MusicAlbum(const MusicAlbum& other);
	void operator+=(Song* item);//operator +=
	void addSong(Song& item);
};
#endif __MUSICALBUM_H__

