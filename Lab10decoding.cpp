// Lab10decoding.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Ashton Tran
//Pual Koester
//COSC 1436
//4-29-19

//DECODING just for fun

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream infile;
	ofstream outfile;
	string coded;

	//Checking if decoded.txt is created
	outfile.open("decoded.txt", ios::in);
	if (outfile.fail())
	{
		//If code.txt is missing.
		//Delete decoded.txt while stepping through it to get error.
		outfile.open("decoded.txt", ios::out);
		cout << "ERROR! decoded.txt does not exists\n";
		return 0;
	}
	else
	{
		cout << "File decoded.txt already exists.\n";
	}

	//Checking for coded
	infile.open("coded.txt", ios::in);
	if (!infile)
	{
		cout << "ERROR! coded.txt does not exists.\n"
			<< "Please place coded.txt in proper location.\n";
		return 0;
	}

	if (infile)
	{
		while (getline(infile, coded))
		{

			for (int index = 0; index < coded.size(); index++)
			{
				coded[index] -= 3;
			}
			cout << coded << endl;
			outfile << coded << '\n';
		}
	}

	infile.close();
	outfile.close();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
