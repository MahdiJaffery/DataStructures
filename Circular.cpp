#include "Header.h"

class Circular {
	Node* head, * tail;
public:
	Circular() :head(nullptr), tail(nullptr) {}

	void insertAtHead(int val) {
		if (!head)
		{
			head = tail = new Node(val);
			return;
		}

		Node* newNode = new Node(val);
		tail->right = newNode;
		newNode->right = head;

		head = newNode;

		newNode = nullptr;
		delete newNode;
	}

	void insertAtTail(int val) {
		if (!head) {
			head = tail = new Node(val);
			return;
		}

		Node* newNode = new Node(val);
		tail->right = newNode;
		newNode->right = head;

		tail = newNode;

		newNode = nullptr;
		delete newNode;
	}

	bool searchElement(int val) {
		Node* temp = head;
		do {
			if (temp->val == val)
				return true;
			temp = temp->right;
		} while (temp->right != head);
		return false;
	}

	void removeFromHead() {
		if (!head)
			return;
		else if (head == tail) {
			head = tail = nullptr;
			delete head, tail;
			return;
		}

		Node* temp = head->right;
		tail->right = temp;

		head->right = nullptr;
		head = nullptr;
		delete head;

		head = temp;

		temp = nullptr;
		delete temp;
	}

	void removeFromTail() {
		if (!head)
			return;
		else if (head == tail) {
			head = tail = nullptr;
			delete head, tail;
			return;
		}

		Node* temp = head;
		while (temp->right != tail)
			temp = temp->right;

		temp->right = nullptr;
		temp->right = head;

		tail->right = nullptr;
		tail = nullptr;
		delete tail;

		tail = temp;

		temp = nullptr;
		delete temp;
	}

	void printCircular() {
		Node* temp = head;
		do {
			cout << temp->val << space;
			temp = temp->right;
		} while (temp != head);
		cout << line;
	}
};

int main(){
    Circular List;

    List.insertAtHead(2);
    List.insertAtHead(1);
    List.insertAtTail(3);

    List.searchElement(4) ? cout << "Element Found" : cout << "Element Not Found";
    cout << line;

    List.printCircular();

    return 0;
}