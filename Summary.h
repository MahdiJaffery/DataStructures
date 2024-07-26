#include <iostream>
#include <climits>
#include <vector>
#include <stack>
#include <queue>
#include <list>

#define line "\n\n"
#define space "\t"

using namespace std;

struct Node
{
	int val, height;
	Node *right, *left;
	Node(int val) : val(val), right(nullptr), left(nullptr), height(1) {}
};

struct Item
{
	int key, status; //	0-Empty	1-Deleted	2-Occupied
	Item() : key(0), status(0) {}
	Item(int key) : key(key), status(2) {}
};

class Singly
{
	Node *head, *tail;

public:
	Singly() : head(nullptr), tail(nullptr) {}

	void insertAtHead(int val)
	{
		if (!head)
		{
			tail = head = new Node(val);
			return;
		}

		Node *temp = new Node(val);
		temp->right = head;
		head = temp;

		temp = nullptr;
		delete temp;
	}

	void insertAtTail(int val)
	{
		if (!head)
		{
			tail = head = new Node(val);
			return;
		}

		Node *temp = new Node(val);
		tail->right = temp;
		tail = temp;

		temp = nullptr;
		delete temp;
	}

	bool searchElement(int val)
	{
		Node *temp = head;
		while (temp)
		{
			if (temp->val == val)
				return true;
			temp = temp->right;
		}
		return false;
	}

	void removeFromHead()
	{
		if (!head)
			return;
		else if (head == tail)
		{
			tail = head = nullptr;
			delete head, tail;
			return;
		}
		Node *temp = head->right;

		head->right = nullptr;
		delete head;

		head = temp;

		temp = nullptr;
		delete temp;
	}

	void removeFromTail()
	{
		if (!head)
			return;
		else if (head == tail)
		{
			tail = head = nullptr;
			delete head, tail;
			return;
		}

		Node *temp = head;

		while (temp->right != tail)
			temp = temp->right;

		temp->right = nullptr;
		delete tail;

		tail = temp;

		temp = nullptr;
		delete temp;
	}

	void printSingly()
	{
		Node *temp = head;
		while (temp)
		{
			cout << temp->val << space;
			temp = temp->right;
		}
		cout << line;
	}
};

class Doubly
{
	Node *head, *tail;

public:
	Doubly() : head(nullptr), tail(nullptr) {}

	void insertAtHead(int val)
	{
		if (!head)
		{
			tail = head = new Node(val);
			return;
		}

		Node *temp = new Node(val);

		temp->right = head;
		head->left = temp;
		head = temp;

		temp = nullptr;
		delete temp;
	}

	void insertAtTail(int val)
	{
		if (!head)
		{
			tail = head = new Node(val);
			return;
		}

		Node *temp = new Node(val);

		temp->left = tail;
		tail->right = temp;
		tail = temp;

		temp = nullptr;
		delete temp;
	}

	bool searchElement(int val)
	{
		Node *temp = head;
		while (temp)
		{
			if (temp->val == val)
				return true;
			temp = temp->right;
		}
		return false;
	}

	void removeFromHead()
	{
		if (!head)
			return;
		else if (head == tail)
		{
			head = tail = nullptr;
			delete head, tail;
			return;
		}

		Node *temp = head->right;
		temp->left = nullptr;
		head->right = nullptr;

		head = nullptr;
		delete head;

		head = temp;

		temp = nullptr;
		delete temp;
	}

	void removeFromTail()
	{
		if (!head)
			return;
		else if (head == tail)
		{
			head = tail = nullptr;
			delete head, tail;
			return;
		}

		Node *temp = tail->left;

		temp->right = nullptr;
		tail->left = nullptr;

		tail = nullptr;
		delete tail;

		tail = temp;

		temp = nullptr;
		delete temp;
	}

	void printDoubly()
	{
		Node *temp = head;
		while (temp)
		{
			cout << temp->val << space;
			temp = temp->right;
		}
		cout << line;
	}
};

class Circular
{
	Node *head, *tail;

public:
	Circular() : head(nullptr), tail(nullptr) {}

	void insertAtHead(int val)
	{
		if (!head)
		{
			head = tail = new Node(val);
			return;
		}

		Node *newNode = new Node(val);
		tail->right = newNode;
		newNode->right = head;

		head = newNode;

		newNode = nullptr;
		delete newNode;
	}

	void insertAtTail(int val)
	{
		if (!head)
		{
			head = tail = new Node(val);
			return;
		}

		Node *newNode = new Node(val);
		tail->right = newNode;
		newNode->right = head;

		tail = newNode;

		newNode = nullptr;
		delete newNode;
	}

	bool searchElement(int val)
	{
		Node *temp = head;
		do
		{
			if (temp->val == val)
				return true;
			temp = temp->right;
		} while (temp->right != head);
		return false;
	}

	void removeFromHead()
	{
		if (!head)
			return;
		else if (head == tail)
		{
			head = tail = nullptr;
			delete head, tail;
			return;
		}

		Node *temp = head->right;
		tail->right = temp;

		head->right = nullptr;
		head = nullptr;
		delete head;

		head = temp;

		temp = nullptr;
		delete temp;
	}

	void removeFromTail()
	{
		if (!head)
			return;
		else if (head == tail)
		{
			head = tail = nullptr;
			delete head, tail;
			return;
		}

		Node *temp = head;
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

	void printCircular()
	{
		Node *temp = head;
		do
		{
			cout << temp->val << space;
			temp = temp->right;
		} while (temp != head);
		cout << line;
	}
};

class Stack
{
	int *stackArr;
	int size, curSize;

public:
	Stack(int capacity = 10) : size(capacity), curSize(0)
	{
		stackArr = new int[size];
	}

	bool isEmpty() const
	{
		return curSize == 0;
	}

	bool isFull() const
	{
		return curSize == size;
	}

	void push(int val)
	{
		if (isFull())
			return;

		stackArr[curSize] = val;
		curSize++;
	}

	int top()
	{
		if (isEmpty())
			return INT_MIN;
		return stackArr[curSize - 1];
	}

	void pop()
	{
		if (isEmpty())
			return;

		curSize--;
	}

	void printStack()
	{
		for (int i = 0; i < curSize; i++)
		{
			cout << stackArr[i] << space;
		}
		cout << line;
	}
};

class Queue
{
	int *QueArr;
	int size, front, rear;

public:
	Queue(int capacity = 10) : size(capacity), front(0), rear(0)
	{
		QueArr = new int[size];
	}

	bool isFull() const
	{
		return !front && rear == size;
	}

	bool isEmpty() const
	{
		return front == rear;
	}

	void push(int val)
	{
		if (isFull())
			return;

		QueArr[rear] = val;
		rear++;
	}

	void pop()
	{
		if (isEmpty())
			return;

		front++;
	}

	int getFront()
	{
		if (isEmpty())
			return INT_MIN;

		return QueArr[front];
	}

	void print() const
	{
		for (int i = front; i < rear; i++)
		{
			cout << QueArr[i] << space;
		}
		cout << line;
	}
};

class BST
{
	Node *root;

	void insert(Node *&root, int val)
	{
		if (!root)
		{
			root = new Node(val);
			return;
		}

		if (root->val > val)
			insert(root->left, val);
		else
			insert(root->right, val);
	}

	bool searchElement(Node *root, int val)
	{
		if (!root)
			return false;

		if (val > root->val)
			searchElement(root->right, val);
		else if (val < root->val)
			searchElement(root->left, val);
		else
			return true;
	}

	void getPredecessor(Node *root, int &data)
	{
		while (root->right)
			root = root->right;
		data = root->val;
	}

	void deleteNode(Node *&root)
	{
		Node *temp = root;
		int data;

		if (!temp->left)
		{
			root = root->right;
			delete temp;
		}
		else if (!temp->right)
		{
			root = root->left;
			delete temp;
		}
		else
		{
			getPredecessor(root->left, data);
			root->val = data;
			remove(root->left, data);
		}
	}

	void remove(Node *&root, int val)
	{
		if (val > root->val)
			remove(root->right, val);
		else if (val < root->val)
			remove(root->left, val);
		else
			deleteNode(root);
	}

	void inOrder(Node *root)
	{
		if (!root)
			return;

		inOrder(root->left);
		cout << root->val << space;
		inOrder(root->right);
	}

public:
	BST() : root(nullptr) {}

	void insertVal(int val)
	{
		insert(root, val);
	}

	bool search(int val)
	{
		return searchElement(root, val);
	}

	void remove(int val)
	{
		if (!search(val))
			return;
		remove(root, val);
	}

	void inOrder()
	{
		inOrder(root);
		cout << line;
	}
};

class AVL
{
	Node *root;

	int Height(Node *root)
	{
		if (!root)
			return 0;
		return root->height;
	}

	int Balance(Node *root)
	{
		if (!root)
			return 0;
		return Height(root->left) - Height(root->right);
	}

	Node *rotateRight(Node *root)
	{
		if (!root)
			return root;

		Node *middle = root->right;
		Node *middleRight = middle->right;

		middle->right = root;
		root->left = middleRight;

		root->height = max(Height(root->left), Height(root->left)) + 1;
		middle->height = max(Height(middle->left), Height(middle->right)) + 1;

		return middle;
	}

	Node *rotateLeft(Node *root)
	{
		if (!root)
			return root;

		Node *middle = root->right;
		Node *middleLeft = middle->left;

		middle->left = root;
		root->right = middleLeft;

		root->height = max(Height(root->left), Height(root->right)) + 1;
		middle->height = max(Height(middle->left), Height(middle->right)) + 1;

		return middle;
	}

	void insert(Node *&root, int val)
	{
		if (!root)
		{
			root = new Node(val);
			return;
		}

		if (root->val > val)
			insert(root->left, val);
		else
			insert(root->right, val);

		root->height = max(Height(root->left), Height(root->right)) + 1;
		int balanceFactor = Balance(root);

		if (balanceFactor == 2 && val < root->left->val)
			root = rotateRight(root);
		if (balanceFactor == -2 && val > root->right->val)
			root = rotateLeft(root);
		if (balanceFactor == 2 && val > root->left->val)
		{
			root->left = rotateLeft(root->left);
			root = rotateRight(root);
		}
		if (balanceFactor == -2 && val < root->right->val)
		{
			root->right = rotateRight(root->right);
			root = rotateLeft(root);
		}
	}

	void removeNode(Node *&root)
	{
		Node *temp = root;
		int data;

		if (!root->left)
		{
			root = root->right;
			delete temp;
		}
		else if (!root->right)
		{
			root = root->left;
			delete temp;
		}
		else
		{
			getPredecessor(root->left, data);
			root->val = data;
			deleteNode(root->left, data);
		}

		if (!root)
			return;

		root->height = max(Height(root->left), Height(root->right)) + 1;
		int balanceFactor = Balance(root);

		if (balanceFactor == 2)
			root = rotateRight(root);
		else if (balanceFactor == -2)
			root = rotateLeft(root);
	}

	void deleteNode(Node *&root, int val)
	{
		if (!root)
			return;

		if (val > root->val)
			deleteNode(root->right, val);
		else if (val < root->val)
			deleteNode(root->left, val);
		else
			removeNode(root);
	}

	void getPredecessor(Node *root, int &val)
	{
		while (root->right)
			root = root->right;
		val = root->val;
	}

	bool searchNode(Node *root, int val)
	{
		if (!root)
			return false;

		if (val > root->val)
			searchNode(root->right, val);
		else if (val < root->val)
			searchNode(root->left, val);
		else
			return true;
	}

	void inOrder(Node *root)
	{
		if (!root)
			return;

		inOrder(root->left);
		cout << root->val << space;
		inOrder(root->right);
	}

	void levelOrder(Node *root)
	{
		queue<Node *> Que;

		Que.push(root);
		Node *newNode;

		while (!Que.empty())
		{
			newNode = Que.front();
			Que.pop();

			cout << newNode->val << space;

			if (newNode->left)
				Que.push(newNode->left);
			if (newNode->right)
				Que.push(newNode->right);
		}
	}

public:
	AVL() : root(nullptr) {}

	void insert(int val)
	{
		insert(root, val);
	}

	bool searchNode(int val)
	{
		return searchNode(root, val);
	}

	void deleteNode(int val)
	{
		if (!searchNode(val))
			return;
		deleteNode(root, val);
	}

	void inOrder()
	{
		inOrder(root);
		cout << line;
	}

	void levelOrder()
	{
		levelOrder(root);
	}
};

class MinHeap
{
	int *heapArr;
	int size, curSize;

	bool isFull() const
	{
		return curSize == size;
	}

	bool isEmpty() const
	{
		return curSize == 0;
	}

	void reheapUp(int child)
	{
		if (child < 0)
			return;

		int parent = (child - 1) / 2;
		if (heapArr[parent] > heapArr[child])
		{
			swap(heapArr[parent], heapArr[child]);
			reheapUp(parent);
		}
	}

	void reheapDown(int index)
	{
		int left = index * 2 + 1;
		int right = index * 2 + 2;

		if (heapArr[left] < heapArr[right] && heapArr[left] < heapArr[index] && left < curSize)
		{
			swap(heapArr[left], heapArr[index]);
			reheapDown(left);
		}
		else if (heapArr[right] < heapArr[left] && heapArr[right] < heapArr[index] && right < curSize)
		{
			swap(heapArr[right], heapArr[index]);
			reheapDown(right);
		}
		else
			return;
	}

public:
	MinHeap(int size = 10) : size(size), curSize(0)
	{
		heapArr = new int[size];
	}

	void insert(int val)
	{
		if (isFull())
			return;

		heapArr[curSize] = val;
		reheapUp(curSize);
		curSize++;
	}

	void remove()
	{
		if (isEmpty())
			return;

		heapArr[0] = heapArr[curSize - 1];
		curSize--;
		reheapDown(0);
	}

	void printHeap()
	{
		for (int i = 0; i < curSize; i++)
			cout << heapArr[i] << space;
		cout << line;
	}
};

class MaxHeap
{
	int *heapArr, size, curSize;

	bool isFull()
	{
		return curSize == size;
	}

	bool isEmpty()
	{
		return curSize == 0;
	}

	void Heapify(int index)
	{
		if (index < 0)
			return;

		int parent = (index - 1) / 2;
		if (heapArr[parent] < heapArr[index])
		{
			swap(heapArr[parent], heapArr[index]);
			Heapify(parent);
		}
	}

	void reheapDown(int index)
	{
		int left = index * 2 + 1;
		int right = index * 2 + 2;

		if (heapArr[left] > heapArr[right] && heapArr[left] > heapArr[index] && left < curSize)
		{
			swap(heapArr[left], heapArr[index]);
			reheapDown(left);
		}
		else if (heapArr[right] > heapArr[left] && heapArr[right] > heapArr[index] && right < curSize)
		{
			swap(heapArr[right], heapArr[index]);
			reheapDown(right);
		}
		else
			return;
	}

public:
	MaxHeap(int size = 10) : size(size), curSize(0)
	{
		heapArr = new int[size];
	}

	void insert(int val)
	{
		heapArr[curSize] = val;
		Heapify(curSize);
		curSize++;
	}

	void remove()
	{
		heapArr[0] = heapArr[curSize - 1];
		curSize--;
		reheapDown(0);
	}

	void printHeap()
	{
		for (int i = 0; i < curSize; i++)
			cout << heapArr[i] << space;
		cout << line;
	}
};

class LinHashMap
{
	Item *hashArr;
	int capacity, curSize;
	float loadFactor;

	void setLoadFactor()
	{
		loadFactor = static_cast<float>(curSize) / capacity;
	}

	int Hash(int val)
	{
		return val % capacity;
	}

	int resolveCollision(int index, int i)
	{
		return (index + i) % capacity;
	}

	void doubleCapacity()
	{
		int oldCapacity = capacity;
		Item *tempHash = new Item[oldCapacity];

		capacity *= 2;

		for (int i = 0; i < oldCapacity; i++)
			tempHash[i] = hashArr[i];

		hashArr = new Item[capacity];
		loadFactor = 0, curSize = 0;

		for (int i = 0; i < oldCapacity; i++)
			if (tempHash[i].status == 2)
				insert(tempHash[i].key);

		setLoadFactor();
	}

	void reHash()
	{
		Item *newHash = new Item[capacity];
		int index, helper = 1;
		for (int i = 0; i < capacity; i++)
		{
			if (hashArr[i].status == 2)
			{
				index = Hash(hashArr[i].key);

				helper = 1;
				while (newHash[index].status == 2)
				{
					index = resolveCollision(index, helper);
					helper++;
				}

				newHash[index] = hashArr[i];
			}
		}

		hashArr = nullptr;
		delete hashArr;

		hashArr = newHash;

		newHash = nullptr;
		delete[] newHash;
	}

public:
	LinHashMap(int size = 8) : capacity(size), curSize(0)
	{
		loadFactor = static_cast<float>(curSize) / capacity;
		hashArr = new Item[capacity];
	}

	void insert(int val)
	{
		int index = Hash(val), helper = 1;

		while (hashArr[index].status == 2)
		{
			index = resolveCollision(index, helper);
			helper++;
		}

		hashArr[index] = Item(val);
		curSize++;

		setLoadFactor();
		if (loadFactor > 0.5)
			doubleCapacity();
	}

	bool searchElement(int val)
	{
		int index = Hash(val), helper = 1;

		while (hashArr[index].status == 2)
		{
			if (hashArr[index].key == val)
				return true;
			else
			{
				index = resolveCollision(index, helper);
				helper++;
			}
		}
		return false;
	}

	void removeElement(int val)
	{
		if (!searchElement(val))
			return;

		int index = Hash(val), helper = 1;

		while (hashArr[index].status == 2)
		{
			if (hashArr[index].key == val)
			{
				hashArr[index] = Item();
				curSize--;
				reHash();
				setLoadFactor();

				return;
			}
			else
			{
				index = resolveCollision(index, helper);
				helper++;
			}
		}
	}

	void printMap()
	{
		for (int i = 0; i < capacity; i++)
			if (hashArr[i].status == 2)
				cout << "Index " << i << ": " << hashArr[i].key << endl;
			else
				cout << "Index " << i << ": " << "\n";
		cout << line;
	}
};

class QuadHashMap
{
	Item *hashArr;
	int capacity, curSize;
	float loadFactor;

	void setLoadFactor()
	{
		loadFactor = static_cast<float>(curSize) / capacity;
	}

	int Hash(int val)
	{
		return val % capacity;
	}

	int resolveCollision(int index, int i)
	{
		return (index + i * i) % capacity;
	}

	void doubleCapacity()
	{
		int oldCapacity = capacity;
		Item *tempHash = new Item[oldCapacity];

		capacity *= 2;

		for (int i = 0; i < oldCapacity; i++)
			tempHash[i] = hashArr[i];

		hashArr = new Item[capacity];
		loadFactor = 0, curSize = 0;

		for (int i = 0; i < oldCapacity; i++)
			if (tempHash[i].status == 2)
				insert(tempHash[i].key);

		setLoadFactor();
	}

	void reHash()
	{
		Item *newHash = new Item[capacity];
		int index, helper = 1;
		for (int i = 0; i < capacity; i++)
		{
			if (hashArr[i].status == 2)
			{
				index = Hash(hashArr[i].key);

				helper = 1;
				while (newHash[index].status == 2)
				{
					index = resolveCollision(index, helper);
					helper++;
				}

				newHash[index] = hashArr[i];
			}
		}

		hashArr = nullptr;
		delete hashArr;

		hashArr = newHash;

		newHash = nullptr;
		delete[] newHash;
	}

public:
	QuadHashMap(int size = 8) : capacity(size), curSize(0)
	{
		loadFactor = static_cast<float>(curSize) / capacity;
		hashArr = new Item[capacity];
	}

	void insert(int val)
	{
		int index = Hash(val), helper = 1;

		while (hashArr[index].status == 2)
		{
			index = resolveCollision(index, helper);
			helper++;
		}

		hashArr[index] = Item(val);
		curSize++;

		setLoadFactor();
		if (loadFactor > 0.5)
			doubleCapacity();
	}

	bool searchElement(int val)
	{
		int index = Hash(val), helper = 1;

		while (hashArr[index].status == 2)
		{
			if (hashArr[index].key == val)
				return true;
			else
			{
				index = resolveCollision(index, helper);
				helper++;
			}
		}
		return false;
	}

	void removeElement(int val)
	{
		if (!searchElement(val))
			return;

		int index = Hash(val), helper = 1;

		while (hashArr[index].status == 2)
		{
			if (hashArr[index].key == val)
			{
				hashArr[index] = Item();
				curSize--;
				reHash();
				setLoadFactor();

				return;
			}
			else
			{
				index = resolveCollision(index, helper);
				helper++;
			}
		}
	}

	void printMap()
	{
		for (int i = 0; i < capacity; i++)
			if (hashArr[i].status == 2)
				cout << "Index " << i << ": " << hashArr[i].key << endl;
			else
				cout << "Index " << i << ": " << "\n";
		cout << line;
	}
};
