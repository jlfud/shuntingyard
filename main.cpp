//imports
#include <iostream>
#include <cstring>
#include <cctype>
#include "tree.h" //includes node struct
#include "list.h"

using namespace std;
int main(){
  char in[100]; //for input
  list* l = new list(); //list contains stack and queue
  //push pushes to l's stack, enqueue queues to l's queue 
  cout << "enter your expression separated by spaces: " << endl;
  cin >> in;
  cout << endl;
  for(int i = 0; i < strlen(in); i++){
    //if it's an operator
    if(in[i] == '+' || in[i] == '-' || in[i] == '*' || in[i] == '/' || in[i] == '^' || in[i] == '(' || in[i] == ')'){
      node* n = new node();
      n->data = in[i];
      l->push(n); //made push specific to shuntingyard
      //pushes to the stack, push function has shunting yard algorithm
    }
    else if(isalnum(in[i])){ //if it's a number/varaible
      node* n = new node();
      n->data = in[i];
      n->precedence = 0; //indicates it is an operand
      l->enqueue(n);
    }
  }
  l->build(); //pop from stack to queue
  l->display(); //display the new list
  
  tree* t = new tree();
  //builds the binary expression tree
  t->build(l->getQueue());
  while(true){
    cout << "prefix, infix, postfix, quit: " << endl;
    cin >> in;
    //gets prefix, infix, or postfix, and calls the corresponding function
    if(strcmp("prefix", in) == 0){
      t->prefix(t->getHead());
    }
    else if(strcmp("infix", in)==0){
      t->infix(t->getHead());
    }
    else if(strcmp("postfix", in)==0){
      t->postfix(t->getHead());
    }
    else if(strcmp("quit", in)==0){
      return 0; 
    }
    else{
      cout << "invalid input, try again." << endl;
    }
    cout << endl;
  }
  return 0;
}

