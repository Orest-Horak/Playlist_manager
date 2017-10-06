#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

class Playlist 
{
private:
	string name;
	string songs;
public:
	Playlist();
	Playlist(string _name);
	Playlist(string _directory, string _name);
	void getSongs();
	void songsToFile(string _name);
	Playlist& operator-=(string _file);
	Playlist& operator-(string _file);
	~Playlist();
};
