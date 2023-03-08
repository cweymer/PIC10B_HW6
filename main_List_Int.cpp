/*
PIC 10B Homework 6, main_List_Int.cpp
Author: Charlotte Weymer
UID: 005760636
Discussion Section: 2A
Date: 03/10/2023
*/
#include "List_Int.h"
using namespace std;
int main()
{
    cout << "Please input a set of nonnegative numbers for a list" << endl;
    cout << "(Enter -1 when you are finished):" << endl;
    //cin list
    int input; //defines first list input
    List tempobj;
    while (cin >> input)
    {
        if (input == -1)
            {break;}
        tempobj.push_back(input); //initializes list input
    }
    cout << "Your list is " << endl;
    tempobj.display(); //calls display for format of list
    cout << "Select an index for insertion (enter -1 when finished:): ";
    //cin index1
    cout << "Select a value for insertion: ";
    //cin value
    cout << "Select an index for insertion (enter -1 when finished): ";
    //cin index2
    cout << "The augmented list is" << endl;
    //cout << augmentedlist << endl;
    cout << "When we sort the previous list we obtain" << endl;
    //cout << sortedlist << endl;
    cout << "And this sorted list in reverse order is" << endl;
    //cout << reverselist << endl;
    cout << "If we merge this list with the list (2, 3, 5, 7, 11) we obtain" << endl;
    //cout << mergedlist << endl;
    //
    return 0;
}

