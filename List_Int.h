/*
PIC 10B Homework 6, List_Int.h
Author: Charlotte Weymer
UID: 005760636
Discussion Section: 2A
Date: 03/10/2023
*/
#ifndef List_Int_h
#define List_Int_h
#include <iostream>
#include <list>
class Node;
class Iterator;
class Node {
    public:
        Node(int element); //constructs node with given element    
    private:
        int data;
        Node* previous;
        Node* next;
        //permits use of private members from list and iterator
        friend class List; 
        friend class Iterator;
};
class List {
    public:
        List();
        Iterator erase(Iterator iter); //removes an element from the list
        Iterator begin();
        Iterator end();
        void push_back(int element); //inserts element at end of list
        void insert(Iterator iter, int element); //inserts element at given position
        void display(std::list<int> inputlist); //prints current list
        void push_front(); //adds value to beginning of list
        void sort(); //sorts elements
        void merge(); //accepts another list object and merges the two lists into one alternating element
        void reverse(); //reverses nodes   
        void operator ++ ();  //overloads ++ operator for iterating
        void operator -- (); //overloads -- operator for iterating
        void operator * (); //overloads * operator for dereferencing node pointers
    private:
        Node* first;
        Node* last;
        friend class Iterator;
};

class Iterator {
    public:
        Iterator(); //constructs iterator that does not point into list
        string get() const; //checks value at position
        void next(); //advances iterator forward one position
        void previous(); //moves iterator to previous node
        bool equals(Iterator other) const;
    private:
        Node* position;
        List* container;
        friend class List; //permits private data member use from list
};
#endif
