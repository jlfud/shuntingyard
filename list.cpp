#include <iostream>
#include <cstring>
#include "tree.h"
#include "list.h"

using namespace std;

list::list(){
  qhead = NULL; //queue head
  shead = NULL; //stack head
}
list::~list(){

}
void list::push(node* n){
  //give operator precedence
  switch(n->data){
  case '+':
    n->precedence = 1;
    break;
  case '-':
    n->precedence = 1;
    break;
  case '*':
    n->precedence = 2;
    break;
  case '/':
    n->precedence = 2;
    break;
  case '^':
    n->precedence = 3;
    break;
  case ')':
    n->precedence = 4;
    break;
  case '(':
    n->precedence = 4;
    break;
  }
  //while there the stack head's precendece is larger than the current
  //if not paranthases
  if(n->precedence != 4){
    while(shead != NULL){ 
      if(shead->precedence >= n->precedence && shead->precedence != 4){
	//queue the popped node
	this->enqueue(this->pop());
      }
      else{
	break;
      }
    }
    //push
    n->next = shead;
    shead = n;
  }
  else if(n->data == '('){
    n->next = shead;
    shead = n; 
  }
  else if(n->data == ')'){
    //loop and queue until find left, then discard both
    while(shead != NULL){
      if(shead->data != '('){
	this->enqueue(this->pop());
      }
      else{
	node* temp = this->pop();
	delete temp;
	break;
      }
    }
  }
}
node* list::pop(){
  //replace head and return old head
  if(shead == NULL){
    return NULL; 
  }
  else{
    node* placeholder = shead;
    shead = shead->next;
    placeholder->next = NULL;
    return placeholder;
  }
}
node* list::peek(){
  return shead; 
}
void list::enqueue(node* n){
  if(qhead == NULL){
    qhead = n;
    return;
  }
  //loop until find end
  node* current = qhead;
  while(current->next != NULL){
    current = current->next;
  }
  current->next = n;
}
void list::dequeue(){
  if(qhead == NULL){
    return; 
  }
  else{
    //dequeues front of queue
    node* placeholder = qhead;
    qhead = qhead->next;
    delete qhead; 
  }
}
void list::build(){
  //queue the remaining stack
  while(shead != NULL){ 
    this->enqueue(this->pop());
  }
}
void list::display(){
  //loop through queue and print
  node* current = qhead;
  while(current != NULL){
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl; 
}
node* list::getQueue(){
  return qhead;
}
