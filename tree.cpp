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
  while(current != NULL){
    node* placeholder = current;
    placeholder->next = NULL; 
    if(current->precedence == 0){
      this->push(placeholder);
    }
    else{
      placeholder->left = this->pop();
      placeholder->right = this->pop();
      this->push(placeholder);
    }
    current = current->next;
  }
}
void tree::infix(){
  
}
void tree::postfix(){

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
