#include "patient.h"
#include <iomanip>

class Node{
private:
  Node *nextPtr;
  Node *prevPtr;
  patient person;
public:
  Node(string n = "Unnamed", int a = 0, string r = "Unknown" , float w  = 0.0, float h = 0.0, int p = 0, int g = 0);
 ~Node();
  Node* get_next();
  Node* get_prev();
  void set_next(Node* t);
  void set_prev(Node * t);
};

typedef Node *NodePtr;

Node::Node(string n, int a, string r, float w, float h, int p, int g){
  person(n, a, r, w, h, p, g);
  nextPtr = NULL;
  prevPtr = NULL;
}

Node* Node::get_next(){
  return nextPtr;
}
Node* Node::get_prev(){
  return prevPtr;
}
void Node::set_next(Node* t){
  nextPtr=t; 
}
void Node::set_prev(Node* t){
  prevPtr = t;
}

