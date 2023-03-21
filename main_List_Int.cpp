/*
PIC 10B Homework 6, main_List_Int.cpp
Author: Charlotte Weymer
UID: 005760636
Discussion Section: 1C
Date: 03/10/2023
*/
#include "List_Int.h"
using namespace std;
int main()
{
    cout << "Please input a set of nonnegative numbers for a List" << endl;
    cout << "(Enter -1 when you are finished):" << endl;
    cout << endl;
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
    cout << endl;
    cout << "Select an index for insertion (enter -1 when finished): ";
    cin >> index1;
    while (index1 != -1){
        if (count > 0){
        cout << "Select an index for insertion (enter -1 when finished): ";
        cin >> index1;} //only prints after first iteration
        if (index1 == -1)
        { break;} //quits loop if user inputs escape code
        cout << "Select a value for insertion: ";
        cin >> value;  //code stops working here
        Iterator tempit = listreal.move(index1); 
        listreal.insert(tempit, value); //calls insert with user arguments
        count++; //updates count
    }
    cout << endl;
    cout << endl;
    cout << "The augmented List is" << endl;
    listreal.display(); //displays current, modified list
    cout << endl;
    cout << "When we sort the previous list we obtain" << endl;
    listreal.sort();
    listreal.display();
    cout << "And this sorted list in reverse order is" << endl;
    listreal.reverse();
    listreal.display();
    cout << "If we merge this list with the list (2,3,5,7,11) we obtain" << endl;
    List listmerge;
    listmerge.push_back(2);
    listmerge.push_back(3);
    listmerge.push_back(5);
    listmerge.push_back(7);
    listmerge.push_back(11); //creates secondary list called listmerge for merging
    List finalist;
    finalist.merge(&listreal, &listmerge);
    finalist.display();
    return 0;
}

