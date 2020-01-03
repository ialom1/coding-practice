#include <iostream>
#include <stdio.h>

using namespace std;

class Stack {
  int *arr;
  int top, capacity;

  public:
    Stack(int size);
    ~Stack();

    void push(int);
    int pop();
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};

Stack :: Stack(int size){
  arr = new int[size];
  capacity = size;
  top = -1;
}
Stack :: ~Stack(){
  delete arr;
}

void Stack :: push(int n){
  if(isFull()){
    std::cout << "Overflow" << '\n';
    exit(EXIT_FAILURE);
  }
  std::cout << "Inserting " << n << '\n';
  top = (top + 1) % capacity;
  arr[top] = n;
}
int Stack :: pop(){
  if(isEmpty()){
    std::cout << "Underflow" << '\n';
    exit(EXIT_FAILURE);
  }
  std::cout << "Removing " << peek() << '\n';
  top --;
}
int Stack :: peek(){
  if(isEmpty()){
    std::cout << "Underflow" << '\n';
    exit(EXIT_FAILURE);
  }
  return arr[top];
}
int Stack :: size(){
  return top + 1;
}
bool Stack :: isEmpty(){
  return (size() == 0);
}
bool Stack :: isFull(){
  return (size() == capacity);
}


int main() {
  Stack pt(3);

	pt.push(1);
	pt.push(2);

	pt.pop();
	pt.pop();

	pt.push(3);

	cout << "Top element is: " << pt.peek() << endl;
	cout << "Stack size is " << pt.size() << endl;

	pt.pop();

	if (pt.isEmpty())
		cout << "Stack Is Empty\n";
	else
		cout << "Stack Is Not Empty\n";

	return 0;
  return 0;
}
