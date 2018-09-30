#include "Node.h"

using namespace std;

//remove helper function
Node* remove(Node *head){
  Node *temp_1 = head;
  while(temp_1 != NULL){
    Node *temp_2 = temp_1;
    while(temp_2->next_ != NULL){
      Node *temp_3 = temp_2;
      temp_2 = temp_2->next_;
      if(temp_2->data_ == temp_1->data_){
        temp_3->next_ = temp_2->next_;
        temp_2 = temp_2->next_;//
      }
    }
    temp_1 = temp_1 -> next_;
  }
  return head;
}

//add node to the new linked list
//Node* add_on_heap(Node *head){

//}


void mergeList(Node *first, Node *second) {
  // your code here!
  if(first == NULL){
    first = second;
  }
  if(second == NULL){
    return;
  }
  Node *first_copy = first;
  Node *second_copy = second;

  while((first_copy->next_ != NULL) && (second_copy->next_ != NULL)){
    Node *temp_first = first_copy;
    Node *temp_second = second_copy;

    first_copy = first_copy -> next_;
    second_copy = second_copy -> next_;

    temp_first -> next_ = temp_second;
    temp_second -> next_ = first_copy;
  }

  if(first_copy->next_ == NULL){
    first_copy->next_ = second_copy;
  }
  else{//second_copy->next_ == NULL
    Node *temp = first_copy;
    first_copy = first_copy -> next_;
    temp -> next_ = second_copy;
    second_copy -> next_ = first_copy;
  }
}




Node *listUnion(Node *first, Node *second) {
  // your code here
  //return NULL;
  if(first == NULL && second == NULL){
    return NULL;
  }
  if(first == NULL && second != NULL){
    return remove(second);
  }
  if(first != NULL && second == NULL){
    return remove(first);
  }

  //merge the two lists and call remove
  mergeList(first, second);
  return remove(first);
}

Node::Node() {
    numNodes++;
}

Node::Node(Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;
