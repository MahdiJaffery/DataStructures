#include "Header.h"

class Stack {
	int* stackArr;
	int size, curSize;
public:
	Stack(int capacity = 10) :size(capacity), curSize(0) {
		stackArr = new int[size];
	}

	bool isEmpty()const {
		return curSize == 0;
	}

	bool isFull()const {
		return curSize == size;
	}

	void push(int val) {
		if (isFull())
			return;

		stackArr[curSize] = val;
		curSize++;
	}

	int top() {
		if (isEmpty())
			return INT_MIN;
		return stackArr[curSize - 1];
	}

	void pop() {
		if (isEmpty())
			return;

		curSize--;
	}

	void printStack() {
		for (int i = 0; i < curSize; i++) {
			cout << stackArr[i] << space;
		}
		cout << line;
	}
};

int main(){
    Stack myStack(3);   //  default size set to 10 if not provided

    myStack.isEmpty() ? cout << "Stack is Empty" : cout << "Stack is not Empty";
    cout << line;

    myStack.push(3);

    //  Check Funcitons after a push
    myStack.isEmpty() ? cout << "Stack is Empty" : cout << "Stack is not Empty";
    cout << line;
    myStack.isFull() ? cout << "Stack is Full" : cout << "Stack is not Full";
    cout << line;

    myStack.push(2);
    myStack.push(1);

    myStack.isFull() ? cout << "Stack is Full" : cout << "Stack is not Full";
    cout << line;

    myStack.printStack();   //  Stack

    myStack.pop();

    myStack.printStack();   //  Stack after Pop

    return 0;
}