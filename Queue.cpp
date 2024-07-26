#include "Header.h"

class Queue {
	int* QueArr;
	int size, front, rear;
public:
	Queue(int capacity = 10) :size(capacity), front(0), rear(0) {
		QueArr = new int[size];
	}

	bool isFull()const {
		return !front && rear == size;
	}

	bool isEmpty()const {
		return front == rear;
	}

	void push(int val) {
		if (isFull())
			return;

		QueArr[rear] = val;
		rear++;
	}

	void pop() {
		if (isEmpty())
			return;

		front++;
	}

	int getFront() {
		if (isEmpty())
			return INT_MIN;

		return QueArr[front];
	}

	void print()const {
		for (int i = front; i < rear; i++) {
			cout << QueArr[i] << space;
		}
		cout << line;
	}
};

int main(){
    Queue myQue(3);

    myQue.isEmpty() ? cout << "Queue is Empty" : cout << "Queue is not Empty";
    cout << line;

    myQue.push(1);

    //  Check after push()
    myQue.isEmpty() ? cout << "Queue is Empty" : cout << "Queue is not Empty";
    cout << line;

    myQue.isFull() ? cout << "Queue is Full" : cout << "Queue is not Full";
    cout << line;

    myQue.push(2);
    myQue.push(3);

    cout << "Queue holds:\t";
    myQue.print();

    cout << "Value at Front: " << myQue.getFront() << line;

    myQue.pop();

    cout << "Value at Front: " << myQue.getFront() << line;

    cout << "Final Queue:\t";
    myQue.print();

    return 0;
}