#include <iostream>
#include <stdio.h>

using namespace std;

#define SIZE 10

class Queue {
  int *arr;
  int capacity, front, rear, count;

  public:
    Queue(int size);
    ~Queue();

    void enqueue(int);
    void dequeue();
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};

Queue :: Queue(int size){
  arr = new int[size];
  capacity = size;
  front = 0;
  rear = -1;
  count = 0;
}
Queue :: ~Queue(){
	delete arr;
}
void Queue :: enqueue(int n){
  if(isFull()){
    std::cout << "Overflow" << '\n';
    exit(EXIT_FAILURE);
  }
  std::cout << "Inserting " << n << '\n';
  rear = (rear + 1) % capacity;
  arr[rear] = n;
  count ++;
}
void Queue :: dequeue(){
  if(isEmpty()){
    std::cout << "Underflow" << '\n';
    exit(EXIT_FAILURE);
  }
  std::cout << "Removing " << peek() << '\n';
  front = (front + 1) % capacity;
  count --;
}
int Queue :: peek(){
  if(isEmpty()){
    std::cout << "Underflow" << '\n';
    exit(EXIT_FAILURE);
  }
  return arr[front];
}
int Queue :: size() {
  return count;
}
bool Queue :: isEmpty(){
  return (size() == 0);
}
bool Queue :: isFull(){
  return (size() == capacity);
}

int main() {
  // create a queue of capacity 5
	Queue q(5);

	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);

	cout << "Front element is: " << q.peek() << endl;
	q.dequeue();

	q.enqueue(4);

	cout << "Queue size is " << q.size() << endl;

	q.dequeue();
	q.dequeue();
	q.dequeue();

	if (q.isEmpty())
		cout << "Queue Is Empty\n";
	else
		cout << "Queue Is Not Empty\n";

	return 0;
  return 0;
}
