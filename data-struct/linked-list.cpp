#include <iostream>
#include <stdio.h>

using namespace std;

struct Node {
  int data;
  Node* next;
};

void printLL(Node* head){
  while (head != NULL) {
    std::cout << head->data << ' ';
    head = head->next;
  }
  std::cout << '\n';
}
void printForward(Node* head){
  if(head == NULL){
    std::cout << '\n';
    return;
  };
  std::cout << head->data << ' ';
  printForward(head->next);
}
void printReverse(Node* head){
  if(head == NULL){
    return;
  }
  printReverse(head->next);
  std::cout << head->data << ' ';
}

void insertAtBegining(Node** head, int x){
  Node* newNode = new Node;
  newNode->data = x;
  newNode->next = *head;
  *head = newNode;
  printLL(*head);
}

void insertAt(Node** head, int pos, int x){
  Node* newNode = new Node;
  newNode->data = x;
  newNode->next = NULL;

  if(pos == 0) {
    newNode->next = *head;
    *head = newNode;
    printLL(*head);
    return;
  }

  Node* temp = *head;
  for(int i = 0; i < pos-1; i++){
    temp = temp->next;
  }
  newNode->next = temp->next;
  temp->next = newNode;
  printLL(*head);
}

void deleteAt(Node** head, int pos){
  Node* temp1 = *head;

   if(pos == 0) {
    *head = temp1->next;
    delete(temp1);
    printLL(*head);
    return;
  }

  for(int i = 0; i < pos-1; i++){
    temp1 = temp1->next;
  }
  Node* temp2 = temp1->next;
  temp1->next = temp2->next;
  delete(temp2);
  printLL(*head);
}

void reverseLL(Node** head){
  Node *curr, *prev, *next;
  curr = *head;
  prev = NULL;
  while (curr != NULL) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  *head = prev;
}
void reverseLLRec(Node** head, Node* curr){
  if(curr->next == NULL){
    *head = curr;
    return;
  }
  reverseLLRec(&(*head), curr->next);
  Node *next = curr->next;
  next->next = curr;
  curr->next = NULL;
}

int main() {
  Node* head = NULL;
  insertAtBegining(&head, 25);
  insertAtBegining(&head, 10);
  insertAtBegining(&head, 15);
  insertAtBegining(&head, 20);


  insertAt(&head, 0, 2);
  insertAt(&head, 1, 4);
  insertAt(&head, 0, 6);
  insertAt(&head, 2, 8);

  std::cout << "\nForward Traversal: " << '\n';
  printForward(head);
  std::cout << "Reverse Traversal: " << '\n';
  printReverse(head);

  std::cout << "\n\nReversing..." << '\n';
  reverseLL(&head);
  std::cout << "Forward Traversal: " << '\n';
  printForward(head);

  std::cout << "\n\nReversing..." << '\n';
  reverseLLRec(&head, head);
  std::cout << "Forward Traversal: " << '\n';
  printForward(head);

  // deleteAt(&head, 1);
  // deleteAt(&head, 0);

  return 0;
}
