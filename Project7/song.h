/* Assignment: 3
Author: Guy Shabtay, ID: 209298272*/
#pragma warning(disable: 4996)
#ifndef __SONG_H__
#define __SONG_H__
using namespace std;

class Song
{
private:
	char* songName;
	int length;

public:
	Song(char* songName, int length);
	Song();
	char* getSongName() { return songName; }
	int getLength() { return length; }
	~Song();
};
#endif __SONG_H__


