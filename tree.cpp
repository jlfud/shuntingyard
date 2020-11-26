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
    placeholder->next = NULL; 
    if(current->precedence == 0){
      this->push2(placeholder); //push if it is an operand
    }
    else{
      placeholder->left = this->pop2(); //pop for left
      placeholder->right = this->pop2(); //pop for right
      this->push2(placeholder); //push the tree
    }
    current = current->next;
  }
}
void tree::infix(node* current){
  
}
void tree::postfix(node* current){

}
void tree::prefix(node* current){
  cout << "here" << endl;
  if(current != NULL){
    cout << current->data << " "; 
    this->prefix(current->left);
    this->prefix(current->right);
  }
}
void tree::push2(node* n){
  //general push function for generic stack
  if(head == NULL){
    head = n; 
  }
  else{
    n->next = head;
    head = n; 
  }
}
node* tree::pop2(){
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
