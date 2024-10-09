#include<iostream>
typedef int itemType;
using namespace std;

class Queue {
private:
	itemType* items;
	int front;
	int rear;
	int maxQue;

public:
	Queue();
	Queue(int n);
	~Queue();
	void insert(itemType item);
	void remove();
	bool isEmpty();
	bool isFull();
	int peek();
};
Queue::Queue() {
	maxQue=100;
	items = new itemType[maxQue];
	front = -1;
	rear = -1;
}
Queue::Queue(int n) {
	maxQue = n;
	items = new itemType[n];
	front = -1;
	rear = -1;
}
Queue::~Queue() {
	delete[] items;
}
void Queue::insert(itemType item) {
	if (isFull()) {
		cout << "QUEUE OVERFLOW";
		exit(1);
	}
	else if (isEmpty()) {
		front = 0;
		rear = 0;
	}
	else {
		rear = (rear + 1) % maxQue;
	}
	
	items[rear] = item;
}
void Queue::remove() {
	if (isEmpty()) {
		cout << "QUEUE UNDERFLOW";
		return;
	}
	else if (front == rear) {
		front = -1;
		rear = -1;
	}
	else {
		front=(front+1)%maxQue;
	}
	
}
bool Queue::isEmpty() {
	return front == -1 && rear == -1;  
}
bool Queue::isFull() {
	return (rear + 1) % maxQue==front;
}
int Queue::peek() {
	if (isEmpty()) {
		cout << "QUEUE IS EMPTY";
		return -1;
	}
	return items[front];
}

int main() {
	int size;
	string choice;
	char con = 'y';
	cout << "Enter size of queue: ";
	cin >> size;
	Queue q(size);
	do {
		cout << "Queue Operations:\n1. Insert\n2. Delete\n3. Peek\n";
		cout << "Enter Choice: ";
		cin >> choice;
		if (choice == "1") {
			cout << "\nEnter element you wish to insert in Queue: ";
			int x;
			cin >> x;
			q.insert(x);
		}
		else if (choice == "2") {
			if (!q.isEmpty()) {
				int removedElement = q.peek();
				q.remove();
				cout << "\nElement Removed: " << removedElement;
			}
			else
				cout << "No elements present in Queue";
			
		}
		else if (choice == "3") {
			if (!q.isEmpty()) {
				cout << "Element at Front of Queue: " << q.peek();
			}
			else {
				cout << "No elements present in Queue";
			}
		}
		else {
			cout << "Invalid choice";
		}
		cout << "\nWould you like to continue?(Y/N)";
		cin >> con;
		if (con == 'n' || con == 'N') {
			cout << "Exiting Program...";
		}
		else if (con == 'y' || con == 'Y') {}
		else {
			cout << "invalid input: enter Y/N";
			continue;
		}
	} while (con == 'y' || con == 'Y');
	

	return 0;
}