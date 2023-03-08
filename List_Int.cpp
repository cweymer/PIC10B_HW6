/*
PIC 10B Homework 6, List_Int.cpp
Author: Charlotte Weymer
UID: 005760636
Discussion Section: 1C
Date: 03/10/2023
*/
#include "List_Int.h"
using namespace std;
Node::Node (int element)
{
   //constructs node with data and pointers to previous and next (doubly linked)
    data = element;
    previous = nullptr;
    next = nullptr;
   
}

List::List()

{
   //assigns pointers for head and tail to null
   firstnode = nullptr;
   lastnode = nullptr;

}
// List::List()
// {
//    //delete Node(element) ??
// }

void List::push_back(int element)
{
      Node* new_node = new Node(element); //creates pointer to new node object
   if (lastnode == nullptr) //if the given list is empty
   {  
      firstnode = new_node;
      lastnode = new_node;
   }
   else
   {  
      new_node->previous = lastnode; //move previous to point to old last node
      lastnode->next = new_node; //move next to point to current node
      lastnode = new_node; //lastnode points to current node
   }
}

void List::insert (Iterator iter, int element)
{
   if (iter.position == nullptr)
   {  
      push_back(element);
      return; //simply creates new node with given data when list is empty
   }
   Node* after = iter.position; //pointer to current position
   Node* before = after->previous; //pointer to previous position
   Node* new_node = new Node(element); //creates new node object
   new_node->previous = before; 
   new_node->next = after;
   after->previous = new_node;
   if (before == nullptr) // inserts at beginning of list
      {firstnode = new_node;}
   else
      {before->next = new_node;} //inserts at indicated position
}
Iterator List::begin()
{
   Iterator obj; 
   obj.position = firstnode; //assigns head pointer to position of first node
   obj.container = this;  //points to list object (implicit argument)
   return obj; //returns iterator type object
}

Iterator List::end()
{
   Iterator obj; 
   obj.position = nullptr; //assigns tail pointer to nullptr
   obj.container = this; //points to list object(implicit argument)
   return obj; //returns iterator type object
}

Iterator List::erase(Iterator iter)
{  
   assert(iter.position != NULL); //throws error if position is empty (illegal to check position if nullptr)
   Node* remove = iter.position;
   Node* before = remove->previous;
   Node* after = remove->next;
   //above assigns pointers to all aspects of Node object
   if (remove == firstnode)
   {
      firstnode = after; //assigns the first node position to the next node
   }
   else
   {
      before->next = after;
   }
   if (remove == lastnode)
   {
      lastnode = before;
   }
   else
   {
      after->previous = before;
   }
   delete remove;
   Iterator newiter;
   newiter.position = after;
   newiter.container = this;
   return newiter;
}
void List::display()
{
   Iterator i = this->begin(); //begin iterator at first node
   cout << "(";
      while(i.position != nullptr) //continues until tail is reached
         {
            if (i.position== lastnode)
            {
               cout << *i; //does not print comma if position is last node
               break;
            }
            cout << *i << ", ";
            i++;
         }
   cout << ")" << endl;
}
Iterator::Iterator () 
{
   
}
int Iterator::get() const
{
   return position->data; //retrieves data from where position is
}
Iterator Iterator::operator++ (int)
{
   position = position->next; //increments iterator to next node
   return *this;
}
Iterator Iterator::operator--(int)
 {
   position = position->previous;
   return *this; //decrements iterator to previous node
 }

int Iterator::operator* () 
{
      return this->get(); //returns derefenced value @ node
}

// bool Iterator::equals(Iterator currentiter) const
// {
//    return position == currentiter.position; //checks if the position is equal to where you want to be
// }


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

/*
operator++ for singly linked list
iterator pos = *this; 
pos.point = pos.point->next;
return pos;
*/

/*
set bool flag to see if 
if flag == true
   increment implicit list iterator
if flag == false

*/