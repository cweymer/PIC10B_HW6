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
    List listreal;
    while (cin >> input)
    {
        if (input == -1)
            {break;}
        listreal.push_back(input); //initializes list input
    }
    cout << "Your list is " << endl;
    listreal.display(); //calls display for format of list 
    int index1;
    int value;
    int count = 0;
    cout << "Select an index for insertion (enter -1 when finished:): ";
    cin >> index1;
    while (index1 != -1){
        if (count > 0){
        cout << "Select an index for insertion (enter -1 when finished:): ";
        cin >> index1;} //only prints after first iteration
        if (index1 == -1)
        { break; } //quits loop if user inputs escape code
        cout << "Select a value for insertion: ";
        cin >> value;  //code stops working here
        Iterator tempit = listreal.move(index1); 
        listreal.insert(tempit, value); //calls insert with user arguments
        count++; //updates count
    }
    cout << "The augmented list is" << endl;
    listreal.display(); //displays current, modified list
    cout << "When we sort the previous list we obtain" << endl;
    //cout << sortedlist << endl;
    cout << "And this sorted list in reverse order is" << endl;
    //cout << reverselist << endl;
    cout << "If we merge this list with the list (2, 3, 5, 7, 11) we obtain" << endl;
    //cout << mergedlist << endl;
    //
    listreal.~List();
    return 0;
}

