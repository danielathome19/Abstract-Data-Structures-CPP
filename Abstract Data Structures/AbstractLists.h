/*
 *
 * Author: Daniel Szelogowski (C) 2016
 * Created: 9/19/16
 * Purpose: A collection of data structures written in C++ using templates.
 * Currently implemented:
 * 	-Linked List
 * 	-Doubly Linked list
 * 	-Stack
 * 	-Queue
 * 	-Set
 * 	-Binary (Search) Tree
 * 	-Priority Queue
 * 	-ArrayList
 * 	-Double Ended Queue (Deque)
 * 	-Circular Queue
 * 	-Circular Linked List
 *
 * In progress:
 * 	-Heap
 * 	-Map
 * 	-Skip List
 * 	-Graph
 * 	-Multiset
 * 	-Bag
 * 	-Adjacency List
 *
 **************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

#ifndef ABSTRACTLISTS_H
#define ABSTRACTLISTS_H

namespace adscol {

template<class T> class Node {
	public:
		T myObj;
		Node *myPrev;
		Node *myNext;

		~Node() {
			delete myObj;
			delete myNext;
			delete myPrev;
		}

		Node(T t) {
			myObj = t;
			myNext = NULL;
			myPrev = NULL;
		}
};

template<class T> class LinkedList {
	private:
		Node<T> *myList;
		Node<T> *myLast;

		inline void addLast(T t) {
			myLast = myList;
			while (myLast->myNext != NULL) {
				myLast = myLast->myNext;
			}

			Node<T> *temp = new Node<T>(t);
			myLast->myNext = temp;
		}
	public:
		~LinkedList() {
			delete myList;
			delete myLast;
		}

		LinkedList() {
			myList = NULL;
			myLast = NULL;
		}

		LinkedList(T t) {
			myList = new Node<T>(t);
			myLast = myList;
		}

		inline void add(T t) {
			if (myList == NULL) {
				Node<T> *temp = new Node<T>(t);
				myList = temp;
				myLast = temp;
			} else {
				this->addLast(t);
			}
		}

		inline void add(int index, T t) {
			if (index == 0) {
				Node<T> *temp = new Node<T>(t);
				temp->myNext = myList;
				myList = temp;
			} else if (index >= this->size() - 1) {
				this->addLast(t);
			} else {
				int cnt = 0;
				myLast = myList;
				Node<T> *temp = new Node<T>(t);
				while ((myLast->myNext != NULL) && (cnt <= index)) {
					if (cnt == (index - 1)) {
						temp->myNext = myLast->myNext;
						myLast->myNext = temp;
					}
					cnt++;
					myLast = myLast->myNext;
				}
			}
		}

		inline void remove(int index) {
			if (index == 0) {
				myLast = myList;
				Node<T> *temp = myLast->myNext;
				myList = temp;
				myLast = myList;
			} else if (index == (this->size() - 1)) {
				myLast = myList;
				while (myLast->myNext->myNext != NULL) {
					myLast = myLast->myNext;
				}
				myLast->myNext = NULL;
			} else {
				int cnt = 0;
				myLast = myList;
				Node<T> *tempx;
				while ((myLast->myNext != NULL) && (cnt <= index)) {
					if (cnt == (index - 1)) {
						tempx = myLast;
						tempx->myNext = myLast->myNext->myNext;
						myLast = tempx;
					}
					cnt++;
					myLast = myLast->myNext;
				}
			}
		}

		inline void set(int index, T t) {
			Node<T> *temp = new Node<T>(t);
			if (index == 0) {
				temp->myNext = myList->myNext;
				myList = temp;
				myLast = myList;
			} else if (index == (this->size() - 1)) {
				myLast = myList;
				while (myLast->myNext->myNext != NULL) {
					myLast = myLast->myNext;
				}
				myLast->myNext = temp;
			} else {
				int cnt = 0;
				myLast = myList;
				while ((myLast->myNext != NULL) && (cnt <= index)) {
					if (cnt == (index - 1)) {
						temp->myNext = myLast->myNext->myNext;
						myLast->myNext = temp;
					}
					cnt++;
					myLast = myLast->myNext;
				}
			}
		}

		inline T get(int index) {
			int cnt = 0;
			myLast = myList;
			T obj = NULL;
			while ((myLast->myNext != NULL) && (cnt <= index)) {
				if (cnt == index) obj = myLast->myObj;
				myLast = myLast->myNext;
				cnt++;
			}
			if (cnt == index) obj = myLast->myObj;
			myLast = myList;
			return obj;
		}

		inline void print() {
			myLast = myList;
			while (myLast != NULL) {
				std::cout << myLast->myObj << std::endl;
				myLast = myLast->myNext;
			}
		}

		inline void clear() { myLast, myList = NULL; }

		inline int size() {
			int cnt = 0;
			myLast = myList;
			while (myLast != NULL) {
				cnt++;
				myLast = myLast->myNext;
			}
			return cnt;
		}

		inline bool isEmpty() {
			return (this->size() == 0);
		}
};

template<class T> class DoublyLinkedList {
	private:
		Node<T> *myList;
	public:
		//TODO: add remove(index), add(index), set(index)
		~DoublyLinkedList() {
			delete myList;
		}

		DoublyLinkedList() {
			myList = NULL;
		}

		DoublyLinkedList(T t) {
			myList = new Node<T>(t);
			myLast = myList;
		}

		inline void add(T t) {
			Node<T> *temp = new Node<T>(t);
			if (myList == NULL) {
				myList = temp;
				myList->myNext = myList;
				myList->myPrev = myList;
			} else {
				temp->myNext = myList;
				temp->myPrev = myList->myPrev;
				myList->myPrev = temp;
				temp->myPrev->myNext = temp;
			}
		}

		inline void removeLast() {
			myList->myPrev = myList->myPrev->myPrev;
			myList->myPrev->myNext = myList;
			return;
		}

		inline void removeFirst() {
			Node<T> *temp = myList->myNext;
			temp->myPrev = myList->myPrev;
			temp->myNext = myList->myNext->myNext;
			myList->myPrev->myNext = temp;
			myList = temp;
		}

		inline void print() {
			Node<T> *temp = myList;
			std::cout << myList->myObj << std::endl;
			temp = temp->myNext;

			while (temp != myList) {
				std::cout << temp->myObj << std::endl;
				temp = temp->myNext;
			}

		}

		inline T get(int index) {
			int cnt = 0;
			Node<T> *temp = myList;
			if (cnt == index) {
				return temp->myObj;
			} else {
				cnt++;
				if (cnt == index) return temp->myNext->myObj;
			}
			temp = temp->myNext;

			while ((temp != myList) && (cnt <= index)) {
				if (cnt == index) return temp->myObj;
				temp = temp->myNext;
				cnt++;
			}
			if (cnt == index) return temp->myObj;
		}

		inline void clear() { myList = NULL; }

		inline int size() {
			if (myList == NULL) return 0;

			int cnt = 0;

			Node<T> *temp = myList;
			cnt++;
			temp = myList->myNext;

			while (temp != myList) {
				cnt++;
				std::cout << cnt << " ";
				temp = temp->myNext;
			}

			return cnt;
		}

		inline bool isEmpty() {
			return (this->size() == 0);
		}
};

template<class T> class Stack {
	private:
		Node<T> *myList;
		Node<T> *myLast;

		inline void addFirst(T t) {
			Node<T> *temp = new Node<T>(t);
			temp->myNext = myList;
			myList = temp;
		}
	public:
		~Stack() {
			delete myList;
			delete myLast;
		}

		Stack() {
			myList = NULL;
			myLast = NULL;
		}

		Stack(T t) {
			myList = new Node<T>(t);
			myLast = myList;
		}

		inline void push(T t) {
			Node<T> *temp = new Node<T>(t);
			if (myList == NULL) {
				myList = temp;
				myLast = temp;
			}
			else {
				this->addFirst(t);
			}
		}

		inline T pop() {
			T obj = myList->myObj;
			myLast = myList;
			Node<T> *temp = myLast->myNext;
			myList = temp;
			myLast = myList;
			return obj;
		}

		inline T peek() {
			return myList->myObj;
		}

		inline void print() {
			myLast = myList;
			while (myLast != NULL) {
				std::cout << myLast->myObj << std::endl;
				myLast = myLast->myNext;
			}
		}

		inline void clear() { myLast, myList = NULL; }

		inline int size() {
			int cnt = 0;
			myLast = myList;
			while (myLast != NULL) {
				cnt++;
				myLast = myLast->myNext;
			}
			return cnt;
		}

		inline bool isEmpty() {
			return (this->size() == 0);
		}
};

template<class T> class Queue {
	private:
		Node<T> *myList;
		Node<T> *myLast;

	public:
		~Queue() {
			delete myList;
			delete myLast;
		}

		Queue() {
			myList = NULL;
			myLast = NULL;
		}

		Queue(T t) {
			myList = new Node<T>(t);
			myLast = myList;
		}

		Queue(Queue<T> *copy) {
			this->myLast = copy->myLast;
			this->myList = copy->myList;
		}

		inline void enqueue(T t) {
			Node<T> *temp = new Node<T>(t);
			if (myList == NULL) {
				myList = temp;
				myLast = temp;
			} else {
				myLast = myList;
				while (myLast->myNext != NULL) {
					myLast = myLast->myNext;
				}
				myLast->myNext = temp;
			}
		}

		inline T dequeue() {
			T obj = myList->myObj;
			myLast = myList;
			Node<T> *temp = myLast->myNext;
			myList = temp;
			myLast = myList;
			return obj;
		}

		inline T peek() {
			return myList->myObj;
		}

		inline void print() {
			myLast = myList;
			Queue<T> *listx = new Queue<T>(this);
			while (!listx->isEmpty()) {
				std::cout << listx->dequeue() << std::endl;
			}
		}

		inline std::vector<T>* getList() {
			std::vector<T> *list = new std::vector<T>();
			Queue<T> *listx = new Queue<T>(this);
			while (!listx->isEmpty()) {
				list->push_back(listx->dequeue());
			}
			return list;
		}

		inline void clear() { myLast, myList = NULL; }

		inline int size() {
			int cnt = 0;
			myLast = myList;
			while (myLast != NULL) {
				cnt++;
				myLast = myLast->myNext;
			}
			return cnt;
		}

		inline bool isEmpty() {
			return (this->size() == 0);
		}
};

template<class T> class Set {
	private:
		Node<T> *myList;
		Node<T> *myLast;

		inline void addSorted(T t) {
			myLast = myList;
			Node<T> *temp = new Node<T>(t);
			if (temp->myObj < myLast->myObj) {
				temp->myNext = myLast;
				myList = temp;
				return;
			}
			while (myLast->myNext != NULL) {
				if (temp->myObj < myLast->myNext->myObj) {
					temp->myNext = myLast->myNext;
					myLast->myNext = temp;
					return;
				}
				myLast = myLast->myNext;
			}

			myLast->myNext = temp;
		}

		inline void checkDuplicates(T t) {
			T item = t;
			bool dupeFound = false;

			myLast = myList;
			while (myLast != NULL) {
				if (item == myLast->myObj) dupeFound = true;
				myLast = myLast->myNext;
			}

			if (!dupeFound) this->addSorted(t);

		}
	public:
		~Set() {
			delete myList;
			delete myLast;
		}

		Set() {
			myList = NULL;
			myLast = NULL;
		}

		Set(T t) {
			myList = new Node<T>(t);
			myLast = myList;
		}

		inline void add(T t) {
			Node<T> *temp = new Node<T>(t);
			if (myList == NULL) {
				myList = temp;
				myLast = temp;
			}
			else {
				this->checkDuplicates(t);
			}
		}

		inline void print() {
			myLast = myList;
			while (myLast != NULL) {
				std::cout << myLast->myObj << std::endl;
				myLast = myLast->myNext;
			}
		}

		inline void remove(int index) {
			if (index == 0) {
				myLast = myList;
				Node<T> *temp = myLast->myNext;
				myList = temp;
				myLast = myList;
			} else if (index == (this->size() - 1)) {
				myLast = myList;
				while (myLast->myNext->myNext != NULL) {
					myLast = myLast->myNext;
				}
				myLast->myNext = NULL;
			} else {
				int cnt = 0;
				myLast = myList;
				Node<T> *tempx;
				while ((myLast->myNext != NULL) && (cnt <= index)) {
					if (cnt == (index - 1)) {
						tempx = myLast;
						tempx->myNext = myLast->myNext->myNext;
						myLast = tempx;
					}
					cnt++;
					myLast = myLast->myNext;
				}
			}
		}

		inline T get(int index) {
			int cnt = 0;
			myLast = myList;
			T obj = NULL;
			while ((myLast->myNext != NULL) && (cnt <= index)) {
				if (cnt == index) obj = myLast->myObj;
				myLast = myLast->myNext;
				cnt++;
			}
			if (cnt == index) obj = myLast->myObj;
			myLast = myList;
			return obj;
		}

		inline void clear() { myLast, myList = NULL; }

		inline int size() {
			int cnt = 0;
			myLast = myList;
			while (myLast != NULL) {
				cnt++;
				myLast = myLast->myNext;
			}
			return cnt;
		}

		inline bool isEmpty() {
			return (this->size() == 0);
		}
};

template<class T> class TreeNode {
	public:
		T myObj;
		TreeNode *myLeft;
		TreeNode *myRight;

		~TreeNode() {
			delete myObj;
			delete myLeft;
			delete myRight;
		}

		TreeNode(T t) {
			myObj = t;
			myLeft = NULL;
			myRight = NULL;
		}
	};

template<class T> class BinaryTree {
	private:
		TreeNode<T> *root;

		inline static void printInOrderT(TreeNode<T> *r) {
			if (r == NULL) { return; }
			printInOrderT(r->myLeft);
			std::cout << r->myObj << std::endl;
			printInOrderT(r->myRight);
		}

		inline static void printPreOrderT(TreeNode<T> *r) {
			if (r == NULL) { return; }
			std::cout << r->myObj << std::endl;
			printPreOrderT(r->myLeft);
			printPreOrderT(r->myRight);
		}

		inline static void printPostOrderT(TreeNode<T> *r) {
			if (r == NULL) { return; }
			printPostOrderT(r->myLeft);
			printPostOrderT(r->myRight);
			std::cout << r->myObj << std::endl;
		}

		inline static void invertTree(TreeNode<T> *r) {
			if (r == NULL) { return; }
			TreeNode<T> *temp = r->myLeft;
			r->myLeft = r->myRight;
			r->myRight = temp;
			invertTree(r->myLeft);
			invertTree(r->myRight);
		}

		inline static int countItems(TreeNode<T> *r) {
			if (r == NULL) { return 0; }
			return countItems(r->myLeft) + 1 + countItems(r->myRight);
		}

		inline static int numCounter(TreeNode<T> *r, T t) {
			if (r == NULL) { return 0; }

			if (r->myObj == t) {
				return numCounter(r->myLeft, t) + 1 + numCounter(r->myRight, t);
			} else {
				return numCounter(r->myLeft, t) + 0 + numCounter(r->myRight, t);
			}
		}

		int maxWidth = 0;

		inline int findMaxWidth(TreeNode<T> *r) {
			Queue<TreeNode<T>*> *q = new Queue<TreeNode<T>*>();
			int levelNodes = 0;
			if (r == NULL) return 0;
			q->enqueue(r);

			while (!q->isEmpty()) {
				levelNodes = q->size();

				if (levelNodes > maxWidth) {
					maxWidth = levelNodes;
				}

				while (levelNodes > 0) {
					TreeNode<T> *n = q->dequeue();
					if (n->myLeft != NULL) q->enqueue(n->myLeft);
					if (n->myRight != NULL) q->enqueue(n->myRight);
					levelNodes--;
				}
			}

			return maxWidth;
		}

		inline int findMaxHeight(TreeNode<T> *r) {
			if (r == NULL) { return 0; }
			return (1 + std::max(findMaxHeight(r->myLeft), findMaxHeight(r->myRight)));
		}

	public:
		~BinaryTree() {
			delete root;
		}

		BinaryTree() {
			root = NULL;
		}

		inline void add(T t) {
			TreeNode<T> *temp = new TreeNode<T>(t);

			if (root == NULL) {
				root = temp;
			} else {
				TreeNode<T> *prev = root;
				TreeNode<T> *spot = root;

				while (spot != NULL) {
					if (temp->myObj < spot->myObj) {
						prev = spot;
						spot = spot->myLeft;
					} else {
						prev = spot;
						spot = spot->myRight;
					}
				}

				if (temp->myObj < prev->myObj) {
					prev->myLeft = temp;
				} else {
					prev->myRight = temp;
				}
			}
		}

		inline void remove(T t) {
			TreeNode<T> *prev = root;
			TreeNode<T> *spot = root;
			while (numCounter(root, t) != 0) {
				while (spot->myObj != t) {
					if (t < spot->myObj) {
						prev = spot;
						spot = spot->myLeft;
					} else {
						prev = spot;
						spot = spot->myRight;
					}
				}

				if ((spot->myLeft == NULL) && (spot->myRight == NULL)) {
					if (t < prev->myObj) {
						prev->myLeft = NULL;
					} else {
						prev->myRight = NULL;
					}
				} else {
					if ((spot->myLeft == NULL) || (spot->myRight == NULL)) {
						if (t < prev->myObj) {
							if (spot->myLeft == NULL) {
								prev->myLeft = spot->myRight;
							} else {
								prev->myLeft = spot->myLeft;
							}
						} else {
							if (spot->myRight == NULL) {
								prev->myRight = spot->myRight;
							} else {
								prev->myRight = spot->myLeft;
							}
						}
					} else {
						TreeNode<T> *pmover = spot->myRight;
						TreeNode<T> *mover = spot->myRight;
						while (mover->myLeft != NULL) {
							pmover = mover;
							mover = mover->myLeft;
						}
						if (pmover == mover) {
							spot->myObj = mover->myObj;
							spot->myRight = mover->myRight;
						} else {
							spot->myObj = mover->myObj;
							pmover->myLeft = mover->myRight;
						}
					}
				}
			}
		}

		inline int width() {
			int w = findMaxWidth(root);
			maxWidth = 0;
			return w;
		}

		inline int height() { return findMaxHeight(root); }

		inline void invert() { invertTree(root); }

		inline void printPreOrder() { printPreOrderT(root); }
		inline void printInOrder() { printInOrderT(root); }
		inline void printPostOrder() { printPreOrderT(root); }

		inline void clear() { root = NULL; }

		inline int size() { return countItems(root); }

		inline bool isEmpty() {
			return (this->size() == 0);
		}

};

template<class T> class PQNode {
	private:
		int priority;
		Queue<T> *queue;
	public:
		~PQNode() {
			delete priority;
			delete queue;
		}

		PQNode(int p) {
			priority = p;
			queue = new Queue<T>();
		}

		inline void add(T t) {
			queue->enqueue(t);
		}

		inline int compareTo(PQNode<T> *o) {
			if (o->getPriority() == this->getPriority()) {
				return 0;
			}
			else if (o->getPriority() < this->getPriority()) {
				return 1;
			}
			else if (o->getPriority() > this->getPriority()) {
				return -1;
			}
			return -1;
		}

		inline int getPriority() {
			return priority;
		}

		inline Queue<T>* getList() {
			return queue;
		}

		inline int size() {
			return queue->size();
		}

		inline bool isEmpty() {
			return queue->isEmpty();
		}
};

template<class T> class PriorityQueue {
	private:
		std::vector<PQNode<T>*> *list;
	public:
		~PriorityQueue() {
			delete list;
		}

		PriorityQueue() {
			list = new std::vector<PQNode<T>*>();
		}

		inline void enqueue(T t, int priority) {
			PQNode<T> *temp = new PQNode<T>(priority);
			temp->add(t);
			enqueue(temp);
		}

		inline void enqueue(PQNode<T> *item) {
			for (int i = 0; i < list->size(); i++) {
				PQNode<T> *temp = list->at(i);
				if (item->compareTo(temp) > 0) {
					list->insert(list->begin() + i, item);
					return;
				} else if (item->compareTo(temp) == 0) {
					for (int j = 0; j < item->getList()->getList()->size(); j++) {
						temp->add(item->getList()->getList()->at(j));
					}
					list->erase(list->begin() + i);
					list->insert(list->begin() + i, temp);
					return;
				}
			}

			list->push_back(item);
		}

		inline PQNode<T> dequeue() {
			for (int i = 0; i < list->size(); i++) {
				PQNode<T> temp = list[i];
				if (!temp->isEmpty()) {
					list->erase(list->begin() + i);
					return temp;
				}
			}
			return new PQNode<T>(0);
		}

		inline PQNode<T> peek() {
			for (int i = 0; i < list->size(); i++) {
				PQNode<T> *temp = list[i];
				if (!temp->isEmpty()) {
					return temp;
				}
			}
			return new PQNode<T>(0);
		}

		inline void print() {
			for (int i = 0; i < list->size(); i++) {
				PQNode<T> *temp = list->at(i);
				temp->getList()->print();
			}
		}

		inline int size() {
			if (list->size() == 0) return 0;
			else {
				int cnt = 0;
				for (int i = 0; i < list->size(); i++) {
					PQNode<T> *temp = list[i];
					cnt += temp->size();
				}
			}
		}

		inline bool isEmpty() {
			return (this->size() == 0);
		}

		inline std::vector<PQNode<T>> getList() {
			return list;
		}
};

template<class T> class ArrayList {
	private:
		T* array;
		unsigned int _size;
		unsigned int memsize;
		const static int basesize = 16;

		inline void copy(const ArrayList<T> &a) {
			array = new T[a.memsize];
			if (array == NULL) {
				memFail();
			}
			for (int i = 0; i<a._size; i++) {
				array[i] = a.array[i];
			}
			memsize = a.memsize;
			_size = a._size;
		}

		inline void doublesize() {
			T* temp = NULL;
			int new_size;
			if (memsize == 0) {
				temp = new T[basesize];
				new_size = 1;
			}
			else {
				temp = new T[memsize * 2];
				new_size = memsize * 2;
			}
			if (temp == NULL) {
				memFail();
			}
			for (int i = 0; i<_size; i++) {
				temp[i] = array[i];
			}
			delete[] array;
			array = temp;
			memsize = new_size;
		}

		inline void halfsize() {
			int resize = memsize / 2;
			if (memsize < (basesize * 2)) {
				resize = basesize;
			}
			T* temp = new T[resize];
			if (temp == NULL) {
				memFail();
			}
			for (int i = 0; i<_size; i++) {
				temp[i] = array[i];
			}
			delete[] array;
			array = temp;
			memsize = resize;
		}

		inline void memFail() {
			std::cout << "Memory Allocation Failed" << std::endl;
		}

		inline void badAccess() {
			std::cout << "Attempting to subscript array element that doesn't exist" << std::endl;
		}

	public:
		~ArrayList() {
			if (array) {
				delete[] array;
				array = NULL;
			}
		}

		ArrayList() {
			array = new T[basesize];
			if (array == NULL) {
				memFail();
			}
			_size = 0;
			memsize = basesize;
		}

		ArrayList(unsigned int size) {
			if (size == 0) {
				array = NULL;
			}
			else {
				array = new T[size];
				if (array == NULL) {
					memFail();
				}
			}
			_size = 0;
			memsize = size;
		}

		ArrayList(const ArrayList<T> &a) {
			copy(a);
		}

		inline T& operator [] (unsigned int index) {
			return get(index);
		}

		inline void add(unsigned int index, const T &item) {
			if (index > _size) {
				badAccess();
			}
			if ((_size + 1) > memsize) {
				doublesize();
			}
			for (int i = _size; i>index; i--) {
				array[i] = array[i - 1];
			}
			array[index] = item;
			_size++;
		}

		inline void add(const T &item) {
			if ((_size + 1) > memsize) {
				doublesize();
			}
			array[_size] = item;
			_size++;
		}

		inline void appendAll(const ArrayList<T> &items) {
			for (int i = 0; i<items._size; i++) {
				add(items.array[i]);
			}
		}

		inline bool contains(const T &item) {
			for (int i = 0; i<_size; i++) {
				if (array[i] == item) {
					return true;
				}
			}
			return false;
		}

		inline bool equals(const ArrayList<T> &a) {
			if (_size != a._size) {
				return false;
			}
			for (int i = 0; i<_size; i++) {
				if (array[i] != a.array[i]) {
					return false;
				}
			}
			return true;
		}

		inline T& get(unsigned int index) {
			if (index >(_size - 1)) {
				badAccess();
			}
			return array[index];
		}


		inline void remove(unsigned int index) {
			if (index > (_size - 1)) {
				badAccess();
			}
			for (unsigned int i = index; i<_size - 1; i++) {
				array[i] = array[i + 1];
			}
			_size--;
			if (_size <= (memsize / 4) && memsize > basesize) {
				halfsize();
			}
		}

		inline void clear() {
			for (int i = _size - 1; i >= 0; i--) {
				remove(i);
			}
		}

		inline void reverse() {
			T* temp = new T[memsize];
			if (temp == NULL) {
				memFail();
			}
			for (int i = _size - 1; i >= 0; i--) {
				temp[_size - 1 - i] = array[i];
			}
			delete[] array;
			array = temp;
		}


		inline void set(unsigned int index, const T &item) {
			if (index > _size) {
				badAccess();
			}
			array[index] = item;
		}


		inline int size() {
			return _size;
		}

		inline bool isEmpty() {
			return (_size == 0);
		}

		inline ArrayList<T>* subList(unsigned int fromIndex, unsigned int toIndex) {
			ArrayList<T>* temp = new ArrayList();
			if (temp == NULL) {
				memFail();
			}
			if (toIndex >= _size || fromIndex >= _size) {
				badAccess();
			}
			if (fromIndex >= toIndex) {
				return temp;
			}
			for (int i = fromIndex; i<toIndex; i++) {
				temp->append(array[i]);
			}
			return temp;
		}

		inline void trimToSize() {
			if (_size == memsize) {
				return;
			}
			T* temp = new T[_size];
			if (temp == NULL) {
				memFail();
			}
			for (int i = 0; i<_size; i++) {
				temp[i] = array[i];
			}
			delete[] array;
			array = temp;
			memsize = _size;
		}
};

template<class T> class Deque {
	private:
		std::vector<T> *myList;

	public:
		~Deque() {
			delete myList;
		}

		Deque() {
			myList = new std::vector<T>;
		}

		inline void pushFront(T t) {
			myList->push_back(T);
		}

		inline void pushBack(T t) {
			myList->insert(myList->begin(), t);
		}

		inline T popFront() {
			T obj = myList->back();
			myList->pop_back();
			return obj;
		}

		inline T popBack() {
			T obj = myList->at(0);
			myList->erase(myList->begin());
			return obj;
		}

		inline T peekFront() {
			return myList->at(0);
		}

		inline T peekBack() {
			return myList->back();
		}

		inline void print() {
			for (int i = 0; i < this->size(); i++) {
				std::cout << myList[i] << std::endl;
			}
		}

		inline void clear() { myList->clear(); }

		inline int size() {
			int s = myList->size();
			return s;
		}

		inline bool isEmpty() {
			return (this->size() == 0);
		}
};

template<class T> class CircularQueue {
	private:
		const int DEFAULT_SIZE = 10;

		int myMaxSize;
		int myCurrentSize;
		int myStart;
		int myEnd;

		T *myBuffer;

		CircularQueue(CircularQueue<T> *copy) {
			myMaxSize = copy->myMaxSize;
			myCurrentSize = copy->myCurrentSize;
			myStart = copy->myStart;
			myEnd = copy->myEnd;
			myBuffer = copy->myBuffer;
		}

	public:
		~CircularQueue() {
			delete DEFAULT_SIZE;
			delete myMaxSize;
			delete myCurrentSize;
			delete myStart;
			delete myEnd;
			delete[] myBuffer;
		}

		CircularQueue() {
			myMaxSize = DEFAULT_SIZE;
			myBuffer = new T[myMaxSize];
			myStart = 0;
			myEnd = 0;
			myCurrentSize = 0;
		}

		CircularQueue(int size) {
			myMaxSize = size;
			myBuffer = new T[myMaxSize];
			myStart = 0;
			myEnd = 0;
			myCurrentSize = 0;
		}

		inline void enqueue(T t) {
			myEnd = (myEnd + 1) % myMaxSize;
			myBuffer[myEnd] = t;
			if (myCurrentSize == myMaxSize) {
				myStart = (myStart + 1) % myMaxSize;
			} else {
				myCurrentSize++;
			}
		}

		inline T dequeue() {
			if (myCurrentSize == 0) {
				std::cout << "The buffer is empty!" << std::endl;
				return NULL;
			} else {
				myStart = (myStart + 1) % myMaxSize;
				myCurrentSize--;
				return myBuffer[myStart];
			}
		}

		inline T peek() {
			if (myCurrentSize == 0) {
				std::cout << "The buffer is empty!" << std::endl;
				return NULL;
			} else {
				myStart = (myStart + 1) % myMaxSize;
				return myBuffer[myStart];
			}
		}

		inline void print() {
			CircularQueue<T> *temp = new CircularQueue<T>(this);

			while (!(temp->isEmpty())) {
				std::cout << temp->dequeue() << std::endl;
			}
		}

		inline void clear() {
			myCurrentSize = 0;
			myStart = 0;
			myEnd = 0;
			myBuffer = new T[myMaxSize];
		}

		inline int size() {
			return myCurrentSize;
		}

		inline bool isEmpty() {
			return (myCurrentSize == 0);
		}

		inline bool isFull() {
			return (myCurrentSize == myMaxSize);
		}
};

template<class T> class CircularLinkedList {
	private:
		Node<T> *myList;

	public:
		~CircularLinkedList() {
			delete myList;
		}

		CircularLinkedList() {
			myList = NULL;
		}

		inline void addFront(T t) {
			Node<T> *temp = new Node<T>(t);

			if (myList == NULL) {
				temp->myNext = temp;
				myList = temp;
				return;
			}

			Node<T> *myLast = myList;

			while (myLast->myNext != myList) {
				myLast = myLast->myNext;
			}

			if (myList != NULL) {
				temp->myNext = myList;
				myLast->myNext = temp;
				myList = temp;
			}
		}

		inline void addBack(T t) {
			Node<T> *temp = new Node<T>(t);

			if (myList == NULL) {
				temp->myNext = temp;
				myList = temp;
				return;
			}

			Node<T> *myLast = myList;
			while (myLast->myNext != myList) {
				myLast = myLast->myNext;
			}

			myLast->myNext = temp;
			temp->myNext = myList;
		}

		inline T popFront() {
			Node<T> *temp = myList;
			Node<T> *myLast = myList;

			if (myList != NULL) {
				while (myLast->myNext != myList) {
					myLast = myLast->myNext;
				}
				myList = temp->myNext;
				myLast->myNext = myList;
				T obj = temp->myObj;
				temp = NULL;
				return obj;
			}
			return NULL;
		}

		inline T popBack() {
			Node<T> *temp = myList;
			Node<T> *myLast = myList;

			if (myList != NULL) {
				while (myLast->myNext != myList) {
					temp = myLast;
					myLast = myLast->myNext;
				}
				T obj = temp->myObj;
				temp->myNext = myList;
				myLast = NULL;
				return obj;
			}
			return NULL;
		}

		inline void print() {
			Node<T> *myLast = myList;

			if (myList != NULL) {
				while (myLast->myNext != myList) {
					std::cout << myLast->myObj << std::endl;
					myLast = myLast->myNext;
				}
				std::cout << myLast->myObj << std::endl;
			}
		}

		inline void clear() { myLast, myList = NULL; }

		inline int size() {
			Node<T> *myLast = myList;
			int cnt = 0;
			if (myList != NULL) {
				cnt++;
				while (myLast->myNext != myList) {
					myLast = myLast->myNext;
					cnt++;
				}
				return cnt;
			}
			return 0;
		}

		inline bool isEmpty() {
			return (this->size() == 0);
		}
};


//NOT FINISHED
template<class T> class Heap {
	private:
		std::vector<T> *data;

		T maxValue;
		T minValue;
		bool minHeaped = false;
		bool maxHeaped = false;

		inline void maxHeapify(int i) {
			int left = (2 * i) + 1;
			int right = (2 * i) + 2;
			int largest = i;
			int size = data->size();
			if (left < size && data[left] > data[largest]) {
				largest = left;
			}
			if (right < size && data[right] > data[largest]) {
				largest = right;
			}
			if (largest != i) {
				swap(data[largest], data[i]);
				maxHeapify(largest);
			}
		}

		inline void minHeapify(int i) {
			int left = (2 * i) + 1;
			int right = (2 * i) + 2;
			int smallest = i;
			int size = data->size();
			if (left < size && data[left] < data[smallest]) {
				smallest = left;
			}
			if (right < size && data[right] < data[smallest]) {
				smallest = right;
			}
			if (smallest != i) {
				swap(data[smallest], data[i]);
				minHeapify(smallest);
			}
		}

		inline void siftDown(int start, int end) {
			int root = start;
			while (getLeftChild(root) != -1 && getLeftChild(root) <= end) {
				int left = getLeftChild(root);
				int iswap = root;
				if (data[iswap] < data[left]) {
					iswap = left;
				}
				int right = left + 1;
				if (right != 0 && right <= end && data[iswap] < data[right]) {
					iswap = right;
				}
				if (root == iswap) {
					break;
				}
				else {
					swap(data[iswap], data[root]);
					root = iswap;
				}
			}
		}

		inline void siftDownMin(int start, int end) {
			int root = start;
			while (getLeftChild(root) <= end && getLeftChild(root) != -1) {
				int left = getLeftChild(root);
				int iswap = root;
				if (data[iswap] > data[left]) {
					iswap = left;
				}
				int right = left + 1;
				if (right <= end && right != 0 && data[iswap] > data[right]) {
					iswap = right;
				}
				if (iswap == root) {
					break;
				}
				else {
					swap(data[iswap], data[root]);
					root = iswap;
				}
			}
		}

	public:
		~Heap() {
			delete[] data;
			delete maxValue;
			delete minValue;
			delete minHeaped;
			delete maxHeaped;
		}

		Heap() {
			data = new std::vector<T>();
		}

		inline T at(int i) {
			return data->at(i);
		}

		inline bool insert(T t) {
			if (data->size() == 0) {
				minValue = t;
				maxValue = t;
			} else if (t > maxValue) {
				maxValue = t;
			} else if (t < minValue) {
				minValue = t;
			}

			data->push_back(t);
			return true;
		}

		inline bool sortedInsert(T t) {
			if (data->size() == 0) {
				minValue = x;
				maxValue = x;
			} else if (x > maxValue) {
				maxValue = x;
			} else if (x < minValue) {
				minValue = x;
			}

			for (int i = 0; i, data->size(); i++) {
				if (t < data->at(i)) {
					data->insert(data->begin + i, t);
					return true;
				}
			}
			data->push_back(t);
			return true;
		}

		inline bool erase(int i) {
			if (i >= data->size()) {
				return false;
			} else {
				data->erase(data->begin() + i);
				return true;
			}
		}

		inline int maxElement() {
			return maxValue;
		}

		inline int minElement() {
			return minValue;
		}

		inline int getParent(int i) {
			int parentIndex;
			if (i == 0) {
				parentIndex = 0;
			} else {
				parentIndex = floor((i - 1) / 2);
			}
			return parentIndex;
		}

		inline int getLeftChild(int i) {
			int leftChildIndex = (2 * i) + 1;
			if (leftChildIndex >= data->size()) {
				leftChildIndex = -1;
			}
			return leftChildIndex;
		}

		inline int getRightChild(int i) {
			int rightChildIndex = (2 * i) + 2;
			if (rightChildIndex >= data->size()) {
				rightChildIndex = -1;
			}
			return rightChildIndex;
		}

		inline void buildMaxHeap() {
			for (int i = floor(data->size() / 2); i >= 0; i--) {
				maxHeapify(i);
			}
			minHeaped = false;
			maxHeaped = true;
		}

		inline void buildMinHeap() {
			for (int i = floor(data->size() / 2); i >= 0; i--) {
				minHeapify(i);
			}
			minHeaped = true;
			maxHeaped = false;
		}

		inline void maxHeapSort() {
			if (!maxHeaped) {
				buildMaxHeap();
			}
			int i = data->size() - 1;
			while (i > 0) {
				std::swap(data[i], data[0]);
				i--;
				siftDown(0, i);
			}
		}

		inline void minHeapSort() {
			if (!minHeaped) {
				buildMinHeap();
			}

			int i = data->size() - 1;
			while (i > 0) {
				std::swap(data[i], data[0]);
				i--;
				siftDownMin(0, i);
			}
		}

		inline void print() {
			if(data->size() == 0) {
				std::cout << "Heap is empty" << std::endl;
			} else {
			   for (int i = 0; i < data->size(); i++) {
				   T obj = data->at(i);
				   std::cout << obj << " ";
			   }
			   std::cout << std::endl;
		   }
		}

		inline void clear() {
			maxHeaped = false;
			minHeaped = false;
			data->clear();
		}

		inline int size() {
			return data->size();
		}

		inline bool isEmpty() {
			return (this->size == 0);
		}

};

template<class K, class V> class Map {};

template<class T> class SkipList {};

template<class T> class Graph {};

template<class T> class Multiset {};

template<class T> class Bag {};

template<class T> class AdjacencyList {};

}
#endif