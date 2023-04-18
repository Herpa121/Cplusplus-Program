/*
James Moore
CS210
Project Three
4/16/23
Purpose: Create a program that reads data from a file and writes to a file, and 
allows the user to use one of three menu styles to view the data.
*/

#include <iostream>
#include <string>

#include "inventory.cpp"
using namespace std;

void printChoices() {
    cout << "---------------------------------" << endl;
    cout << "Which menu style would you like?" << endl;
    cout << "Enter 1 for search\nEnter 2 for count by number\nEnter 3 for count by asterisk\nEnter 4 to exit\n";
}

int main()
{
    int menuChoiceInput;
    string menuSearch;

    inventory inv("C:\\Users\\James Megacomp\\source\\repos\\ProjectThreeCS210\\inputFile.dat.txt");
    inv.processData();
    inv.outputFileSend("C:\\Users\\James Megacomp\\source\\repos\\ProjectThreeCS210\\frequency.dat.txt");

    printChoices(); //initial choice print
    cin >> menuChoiceInput; //initial input
    while (menuChoiceInput != 4) {
        if (menuChoiceInput == 1) {//menu search option
            cout << "What item would you like to search for?\n";
            cin >> menuSearch;
            inv.menuSearch(menuSearch);
        }
        else if (menuChoiceInput == 2) {//basic data print option
            inv.printData();
        }
        else if (menuChoiceInput == 3) {//asterisk print option
            inv.printDataAsterisk();
        }
        //recurring print and input after loop
        printChoices();
        cin >> menuChoiceInput;
    }
    
}

