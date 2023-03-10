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
void Node::swap(Node* other)
{
   int temp = other->data; //helper function that moves the data between two nodes
   other->data = this->data;
   this->data = temp;
}
List::List()
{
   //assigns pointers for head and tail to null
   firstnode = nullptr;
   lastnode = nullptr;
}
 List::~List()
{
   Node *todelete = firstnode;
   while (todelete != nullptr)
   {
      Node *tracker = todelete->next;
      delete todelete;
      todelete = tracker;
   }
   /*
   moves the pointer to node to delete along with a tracker pointer 
   and deletes nodes along list
   */
}
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
            if (i.position == lastnode)
            {
               cout << *i; //does not print comma if position is last node
               break;
            }
            cout << *i << ", ";
            i++;
         }
   cout << ")" << endl;
}
Iterator List::move(int index)
{
   Iterator it = this->begin(); //begin iterator at first node
   for (int i = 0; i < index; i++)
   { //moves iterator until desired position is reached
      if (it.position == nullptr)
      {
         break; //i think it's always somehow breaking here
      }
      it++; //moves iterator to desired position
   }
   return it;
}
void List::sort() 
{
   Node* i = firstnode;
   if (i == nullptr || i->next == nullptr)
   {
      return; //exits if list is of 0 or 1 elements
   }

   while (i != nullptr)
   {
      Node* j = i->next; //initializes node next to node i
         while (j != nullptr)
      {
            if (i->data > j->data)
            {
               i->swap(j);  //if left is greater than right, swaps
            }
            j = j->next; //increment second node
      }
      i = i->next; //increment first node
   }
}
void List::merge(List* obj1, List* obj2, List* obj3)
{
   Iterator list1 = obj1->begin();
   Iterator list2 = obj2->begin(); //starts iterators out at beg of list
   int count = 0;  
   while (list1.position != nullptr || list2.position != nullptr)
   {
      if (count % 2 == 0)
      {
          if (list1.position != nullptr)
          {
               obj3->push_back(*list1); //alternates between the two list to push back data
               list1++;
          }
      }
      else 
      {
         if (list2.position != nullptr)
         {
            obj3->push_back(*list2);
            list2++;
         }
      }
      count++;
   }
}
void List::reverse ()
{
   Node* first = firstnode;
   while (first != nullptr)
   {
      Node* temp = first->next;
      first->next = first->previous;
      first->previous = temp; //switches first node forward and backward pointers
      if (first == lastnode)
      {
         break; //escapes once reached last node
      }
      first = first->previous; //moves first and second pointers along list
   }
   Node* tempswap = lastnode;
   lastnode = firstnode; //reverses list pointers to first and last node
   firstnode = tempswap;
}
void List::push_front(int element)
{
   Node* new_node = new Node(element);
   if (lastnode == nullptr) //if the given list is empty
   {  
      firstnode = new_node;
      lastnode = new_node;
   }
   else
   {  
      new_node->next = firstnode; //move next pointer to point to old first node
      firstnode->previous = new_node; //move previous of old firstnode to point to current node
      firstnode = new_node; //firstnode points to current node
   }
}
Iterator::Iterator () 
{
   //
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
      return this->position->data; //returns derefenced value @ node
}
