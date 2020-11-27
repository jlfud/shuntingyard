#include <iostream>
#include <cstring>
#include "tree.h"

using namespace std;

tree::tree(){

}
tree::~tree(){

}
void tree::build(node* qhead){
  node* current = qhead;
  //traverse through queue
  while(current != NULL){
    //copy of current without link
    node* placeholder = current;
    node* temp = current->next; 
    placeholder->next = NULL; 
    if(current->precedence == 0){
      this->push(placeholder); //push if it is an operand
    }
    else{
      placeholder->left = this->pop(); //pop for left
      placeholder->right = this->pop(); //pop for right
      this->push(placeholder); //push the tree
    }
    current = temp; 
  }
}
//different algorithms for binary expression tree
void tree::infix(node* current){
  if(current != NULL){
    if(current->precedence != 0){
      cout << "( "; 
    }
    infix(current->left);
    cout << current->data << " ";
    infix(current->right);
    if(current->precedence != 0){
      cout << ") ";
    }
  }
}
void tree::postfix(node* current){
  if(current != NULL){
    postfix(current->left);
    postfix(current->right);
    cout << current->data << " "; 
  }
}
void tree::prefix(node* current){
  if(current != NULL){
    cout << current->data << " "; 
    this->prefix(current->left);
    this->prefix(current->right);
  }
}
void tree::push(node* n){
  //general push function for generic stack
  if(head == NULL){
    head = n; 
  }
  else{
    n->next = head;
    head = n; 
  }
}
node* tree::pop(){
  if(head == NULL){
    return NULL; 
  }
  else{
    node* placeholder = head;
    head = head->next;
    return placeholder; 
  }
}
node* tree::getHead(){
  return head;
}
