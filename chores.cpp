/*

    Author: Mehmet O. Ongel
    Date: 11/01/2017

    Description: This program creates an initial list of chores from an external file
                 Allows you to delete and add items into specific positions
                 Demonstrates the usage of Linked List data structure

    @file chores.cpp 
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "./linked_list/LinkedList.h"

using namespace std;

LinkedList<string>* getList(LinkedList<string>* listPtr);
void displayList(LinkedList<string>* listPtr);

int main() {
   LinkedList<string>* choresPtr = new LinkedList<string>(); // Create a chores list
    int selection; // position selection
    int position;
    string yesNo; // yes/no answer
    string itemToAdd; // chore item to add to the list

    choresPtr = getList(choresPtr); // initial list of chores from a input file

    displayList(choresPtr);

    // Ask which item to delete
    cout << "Which item to delete? (Use -999 to stop)" << endl;
    cin >> selection;

	// Deleting process
    while (selection != -999) {
        choresPtr->remove(selection);
        displayList(choresPtr);
        cout << "Which item to delete? (Use -999 to stop)" << endl;
        cin >> selection;
    }

	// Prompts the user to advance to add item
    cout << "Add an item to your list? (yes or no)" << endl;
    cin >> yesNo;

	// Allowing the user to enter item until something than
	// yes, Yes, YES entered.
    while (yesNo == "yes" || yesNo == "Yes" || yesNo == "YES") {
        cout << "Position: ";
        cin >> position;
        cout << "Item: ";
        cin.ignore();
        getline(cin, itemToAdd);
        choresPtr->insert(position, itemToAdd);

        cout << endl;
        displayList(choresPtr);

        cout << "Add an item to your list? (yes or no)" << endl;
        cin >> yesNo;
        cout << endl;
    }

    displayList(choresPtr);

    return 0;
}

// reads from an input file & pushes the items into a linked list
// returns the list
LinkedList<string>* getList(LinkedList<string>* listPtr)
{
    ifstream input;
    input.open("initialList.txt");
    vector<string> initialList;
    string line;

    if(input.is_open()) {
        while(getline(input, line))
            initialList.push_back(line);


        for(int i = 0; i < initialList.size(); i++)
            listPtr->insert(i+1, initialList[i]);

        return listPtr;
    }
    else {
        cout << "Unable to open file!" << endl;

        return 0; // terminate the program
    }
        
    
}

// displays the chores list
void displayList(LinkedList<string>* listPtr)
{
    cout << "There are " << listPtr->getLength() << " items on the list." << endl;
    cout << "----Today's list----" << endl;
    for (int pos = 1; pos <= listPtr->getLength(); pos++)
    {
        cout << pos << " " << listPtr->getEntry(pos) << endl;
    }
    cout << endl << endl;
}
