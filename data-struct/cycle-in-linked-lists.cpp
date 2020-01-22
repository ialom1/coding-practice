#include <iostream>

using namespace std;

struct Node{
  int data;
  Node* next;
};
void _print(Node* head){
  while (head != NULL) {
    std::cout << head->data << ' ';
    head = head->next;
  }
  std::cout << '\n';
}
void insertAt(Node** head, int pos, int x){
  Node* newNode = new Node;
  newNode->data = x;
  newNode->next = NULL;

  if(pos == 0) {
    newNode->next = *head;
    *head = newNode;
    return;
  }

  Node* temp = *head;
  for(int i = 0; i < pos-1; i++){
    temp = temp->next;
  }
  newNode->next = temp->next;
  temp->next = newNode;
}
Node* newNode(int key) {
  struct Node* temp = new Node();
  temp->data = key;
  temp->next = NULL;
  return temp;
}
void removeLoop(Node* loop_node, Node* head){
  Node *ptr1 = head;
  Node *ptr2;
  while (1) {
    ptr2 = loop_node;
    while (ptr2->next != ptr1 && ptr2->next != loop_node) {
      ptr2 = ptr2->next;
    }
    if(ptr2->next == ptr1) break;
    else ptr1 = ptr1->next;
  }
  ptr2->next = NULL;
}

int detectAndRemoveLoop(Node* head){
  Node *slow = head;
  Node *fast = head;
  while(slow && fast && fast->next){
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast){
      removeLoop(slow, head);
      return 1;
    }
  }
  return 0;
}


int main() {
  struct Node* head = newNode(50);
  head->next = newNode(20);
  head->next->next = newNode(15);
  head->next->next->next = newNode(4);
  head->next->next->next->next = newNode(10);

  /* Create a loop for testing */
  head->next->next->next->next->next = head->next->next;

  int loop_exists = detectAndRemoveLoop(head);
  if(loop_exists) {
    std::cout << "Loop was removed" << '\n';
  } else {
    std::cout << "There was no loop" << '\n';
  }
  _print(head);
  return 0;
}
