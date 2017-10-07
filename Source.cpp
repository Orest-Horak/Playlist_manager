#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include "Playlist.h"
using namespace std;

void ls(string directory);

void main()
{

	string directory= "c:\\NVIDIA\\";
	Playlist C(directory, "minus2.m3u");
	Playlist B(directory,"minus.m3u");
	B.getSongs();

	string operation="";
	do 
	{
		cout << directory << ' ';
		getline(cin,operation);
		if (operation.find("ls") == 0) 
		{
			ls(directory);
		}
		else if (operation.find("cd") == 0) 
		{
			if (operation.find("..") == 3) 
			{
				if (directory.length() <= 4) 
				{
					cout << "Operations can't be performed" << endl;
				}
				else 
				{
					directory.erase((directory.substr(0,directory.length()-2)).rfind("\\")+1);
				}
			}
			else if (operation.find("\\") == operation.length() - 2) 
			{
				directory += operation.substr(3, operation.length() - 2);
			}
			else if (operation.find(":\\") == 4) 
			{
				directory= operation.substr(3);
			}
			else
			{
				cout << "Uncorrect form!" << endl;
			}
		}
		else if (operation.find("create") == 0) 
		{
			if (operation.find("create_null") == 0) 
			{
				Playlist A(operation.substr(12));
			}
			else
			{
				Playlist A(directory, operation.substr(7));
				A.getSongs();
			}
		}
		else if (operation.find("plus") == 0)
		{
			if (operation.find("_file") == 4)
			{
				B += operation.substr(11);
			}
			else if (operation.find("_playlist") == 4)
			{
				B += C;
			}
			else
			{
				B + directory;
			}
		}
		else if (operation.find("minus") == 0)
		{

			if (operation.find("_file") == 5)
			{
				B -= operation.substr(11);
			}
			else if(operation.find("_playlist") == 5)
			{
				B -= C;
			}
			else
			{
				B - directory;
			}
		}
		else if (operation.find("exit") == 0)
		{
		}
		else if (operation.find("help") == 0)
		{
			cout << "ls" << endl;
			cout << "cd .." << endl;
			cout << "cd subfolder\\" << endl;
			cout << "cd full_adress\\" << endl;
			cout << "create <PlaylistName.m3u>" << endl;
			cout << "create_null <PlaylistName.m3u>" << endl;
			cout << "plus_file <full_adress.mp3>" << endl;
			cout << "plus_folder" << endl;
			cout << "plus_playlist" << endl;
			cout << "minus_file <full_adress.mp3>" << endl;
			cout << "minus_folder" << endl;
			cout << "minus_playlist" << endl;
		}
		else 
		{
			cout << "Unsupported operation!" << endl;
		}
	} while (operation != "exit");


	system("pause");
}

void ls(string directory)
{
	WIN32_FIND_DATA ffd;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	directory += "\\*";
	hFind = FindFirstFile(directory.c_str(), &ffd);
	if (INVALID_HANDLE_VALUE == hFind)
	{
		cout << "We couldn't find such directory" << endl;
	}
	else
	{
		do
		{
			if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				cout << ffd.cFileName << TEXT(" <DIR>\n");
			}
			else
			{
				cout << ffd.cFileName << TEXT(" \n");
			}
		} while (FindNextFile(hFind, &ffd) != 0);
	}
}
/*string directory = "D:\\Steam\\steamapps\\common\\Deponia The Complete Journey\\bonus\\Soundtrack\\Goodbye Deponia\\German\\MP3";*/