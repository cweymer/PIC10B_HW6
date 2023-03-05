/*
PIC 10B Homework 6, List_Int.cpp
Author: Charlotte Weymer
UID: 005760636
Discussion Section: 2A
Date: 03/10/2023
*/
#include "List_Int.h"
using namespace std;
Node::Node (int element)
{
    data = element;
    previous == nullptr;
    next = nullptr;
   /*
   does this work? doesn't this 
   just reset each pointer to null
    as you iterate through the list?
   */
}

List::List()
{

}

void List:: push_back(int element)
{

}

void List::insert (Iterator iter, int element)
{

}

Iterator List::erase(Iterator iter)
{  
   assert(iter.position != NULL);
   Node* remove = iter.position;
   Node* before = remove->previous;
   Node* after = remove->next;
   if (remove == first)
      first = after;
   else
      before->next = after;
   if (remove == last)
      last = before;
   else
      after->previous = before;
   delete remove;
   Iterator r;
   r.position = after;
   r.container = this;
   return r;
}
void List::display(list <int> input1)
{
//need to iterate through list and print with correct spacing
}

//need to implement operator overloading
/*
overload the ++ operator to increment list
overload -- to decrement list
overload * to deference iterator
need to deal with both pre-increment and post-increment (++i vs i++ and --i vs i--)
post-increment: must always create a new object
need to write 4 function: for post and pre increment for ++ and --
*/

//deal with something that is 0 in the data set (needs to be nullptr?)
//Node operator+ (const Node& a) -- overloads the + operator
//Node C = A + B