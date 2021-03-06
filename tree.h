#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <cstring>
using namespace std;

struct node{
  char data;
  int precedence; 
  node* right; //for tree
  node* left; //for tree
  node* next; //for list
};

class tree{
 public:
  tree();
  ~tree();
  void build(node*); 
  void infix(node*);
  void postfix(node*);
  void prefix(node*);
  //more generic push function for the tree
  void push(node*);
  node* pop();
  node* getHead();
private:
  node* head = NULL; //for stack 
};

#endif
