#include <iostream>
#include <string>
#include "Playlist.h"
#include <fstream>
#include <Windows.h>
using namespace std;


Playlist::Playlist() 
{
	directory.assign("c:\\");
	name.assign("");
}
Playlist::Playlist(string _name) 
{
	name.assign(_name);
	fstream file(name);
	file << "#EXTM3U /n" << endl;
}
Playlist::Playlist(string _directory, string _name)
{

}
Playlist::~Playlist() 
{
	_fcloseall();
}