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
public:
	Playlist();
	Playlist(string _name);
	Playlist(string _directory, string _name);
	~Playlist();
};