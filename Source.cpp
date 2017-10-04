#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include "Playlist.h"
using namespace std;

void ls(string directory);

void main()
{
	string directory= "c:\\";
	string operation="";
	do 
	{
		cout << directory << ' ';
		getline(cin,operation);
		if (operation.find("ls") == 0) 
		{
			ls(directory);
		}
		if (operation.find("exit") == 0)
		{
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
		cout << "We couldn't find such file" << endl;
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
