/*
PIC 10B Homework 6, List_Int.h
Author: Charlotte Weymer
UID: 005760636
Discussion Section: 1C
Date: 03/10/2023
*/
#ifndef List_Int_h
#define List_Int_h
#include <iostream>
#include <cassert>
class Node;
class Iterator;
class Node {
    public:
        Node(int element); //constructs node with given element    
    private:
        int data; //value in each node
        Node* previous; //each node has a previous pointer to backwards data element
        Node* next; //each node has a next pointer to forward data element
        void swap (Node* other); //swaps data for sort
        friend class List; 
        friend class Iterator;
};
class List {
    public:
        List();
        ~List(); //destructor to remove nodes
        Iterator begin();
        Iterator end();
        Iterator erase(Iterator iter); //removes an element from the list
        void push_back(int element); //inserts element at end of list
        void insert(Iterator iter, int element); //inserts element at given position
        void display(); //prints current list
        Iterator move(int index);
        void sort(); //sorts elements
        void merge(List* obj1, List* obj2); //accepts another list object and merges the two lists into one alternating element
        void reverse(); //reverses nodes 
        void push_front(int element); //adds value to beginning of list
     private:
        Node* firstnode; 
        Node* lastnode;
        friend class Iterator;
};

class Iterator {
    public:
        Iterator();//constructs iterator that does not point into list
        Iterator operator++ (int);  //overloads ++ operator for iterating
        Iterator operator-- (int); //overloads -- operator for iterating
        int operator* (); //overloads * operator for dereferencing node pointers
    private:
        Node* position;
        List* container;
        friend class List; //permits private data member use from list
};
#endif
