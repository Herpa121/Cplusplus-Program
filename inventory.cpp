#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>

using namespace std;

class inventory
{
private:
	map <string, int> myMap;
	map<string, int>::iterator myItr;
	ifstream inFS;      // Input fstream
	ofstream onFS;      // Output fstream
public:
	inventory() {
		cout << "Empty inventory object created";
	}
	/*
	Constructor with input file as parameter. Opens the file using private member fstream
	*/
	inventory(string inputFile) {
		inFS.open("C:\\Users\\James Megacomp\\source\\repos\\ProjectThreeCS210\\inputFile.dat.txt", ios::in);
	}
	/*
	Assuming an open read stream, populates map private member with data
	*/
	void processData() {
		string tempStr;
		inFS >> tempStr;; //initial input
		if (myMap.count(tempStr) == 0) {//check if new item
			myMap[tempStr] = 1;//if new item, make equal to 1
		}
		else {
			myItr = myMap.find(tempStr); //if present item
			myItr->second = myItr->second + 1; //add one to second/count
		}
		while (!inFS.fail()) {
			inFS >> tempStr;;
			if (myMap.count(tempStr) == 0) {
				myMap[tempStr] = 1;
			}
			else {
				myItr = myMap.find(tempStr);
				myItr->second = myItr->second + 1;
			}
		}
		inFS.close(); //no need for input file anymore
	}
	/*
	Given a string parameter, searches for such string in given map and prints a user friendly result
	*/
	void menuSearch(string menuSearch) {
		if (myMap.count(menuSearch) == 0) { //case of none in inventory
			cout << "There is no " << menuSearch << " in stock\n.";
		}
		else { //thus found, print amount
			myItr = myMap.find(menuSearch);
			cout << "There are " << myItr->second << " " << menuSearch << " in stock\n";
		}
	}
	/*
	Prints how many of each item is in inventory via number representation
	*/
	void printData() {
		myItr = myMap.begin(); //point iterator to beginning
		while (myItr != myMap.end())//iterate to end while printing values
		{
			cout << myItr->first << ", Value: " << myItr->second << endl;
			++myItr;
		}
	}
	/*
	Prints how many of each item is in inventory via astrerisk representation
	*/
	void printDataAsterisk() {
		myItr = myMap.begin(); //point iterator too beginning

		while (myItr != myMap.end()) //iterate to end while printing asterisks
		{
			cout << myItr->first << " ";
			for (int a = 0; a < myItr->second; a++) { //print asterisk for however many of type in inventory
				cout << "*";
			}
			++myItr;
			cout << endl;
		}
	}
	/*
	Provides object with the output file path as parameter and outputs any data in map member
	*/
	void outputFileSend(string outputFilePath) {
		onFS.open(outputFilePath);
		if (!onFS.is_open()) { //check if successfully opened
			cout << "Cannot open file output.txt." << endl;
		}
		myItr = myMap.begin(); //point iterator to beginning
		while (myItr != myMap.end()) //iterate while printing data to file
		{
			onFS <<  myItr->first << " " << myItr->second << endl;
			++myItr;
		}
	}
};