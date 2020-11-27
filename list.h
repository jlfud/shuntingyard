#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cstring>
#include "tree.h" 

using namespace std;

class list{
public:
  list();
  ~list();
  //push function has been specialized to include
  //shunting yard algorithm
  void push(node* n);
  node* pop();
  node* peek();
  void enqueue(node* n);
  void dequeue();

  void build();
  void display();
  node* getQueue();
private: 
  node* shead; //stack head
  node* qhead; //queue head 
};

#endif
