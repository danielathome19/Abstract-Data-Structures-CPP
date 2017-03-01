#include "AbstractLists.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <time.h>

using namespace adscol;

void linkedlisttest() {
	LinkedList<char> *list = new LinkedList<char>();
	list->add('x');
	list->add('y');
	list->add('d');
	list->add('q');
	list->add('u');
	list->add('i');
	//list->addFirst('a');
	//list->addFirst('b');
	//list->addLast('p');
	//list->addLast('q');
	list->print();

	std::cout << std::endl << list->size();
	list->clear();
	list->print();
	std::cout << std::endl;

	std::string st = "abcdefghijklmnopqrstuvwxyz";

	std::cout << std::endl << "coolio" << std::endl;

	//list->addFirst(st[0]);
	list->print();
	list->clear();
	std::cout << std::endl;

	LinkedList<int> *nums = new LinkedList<int>();

	for (int i = 0; i < st.length(); i++) {
		list->add(st[i]);
	}

	/*
	list->removeFirst();
	list->removeFirst();
	list->removeFirst();
	list->removeLast();
	list->removeLast();
	list->print();
	*/

	for (int i = 0; i < st.length(); i++) {
		nums->add(i);
	}

	std::cout << std::endl << "cool " << nums->size() << std::endl;
	nums->print();
	std::cout << std::endl << nums->isEmpty() << std::endl;

	LinkedList<int> *numsList = new LinkedList<int>();

	for (int i = 0; i < 10; i++) {
		numsList->add(i);
	}

	for (int i = 0; i < 10; i++) {
		std::cout << numsList->get(i) << std::endl;
	}
}

void doublylinkedlisttest() {

	DoublyLinkedList<int> *nums = new DoublyLinkedList<int>();

	nums->add(5);

	for (int i = 1; i <= 10; i++) {
		nums->add(i);
	}

	nums->print();

	std::cout << std::endl;
	nums->print();

	std::cout << std::endl;
	std::cout << "Is Empty: " << std::endl;
	std::cout << nums->isEmpty() << std::endl;

	std::cout << "Size: " << std::endl;
	std::cout << nums->size() << std::endl;

	nums->clear();
	std::cout << "Is Empty: " << std::endl;
	std::cout << nums->isEmpty() << std::endl;

	std::cout << "Size: " << std::endl;
	std::cout << nums->size() << std::endl;

}

void linkedliststacktest() {
	LinkedListStack<int> *nums = new LinkedListStack<int>();

	for (int i = 1; i <= 10; i++) {
		nums->push(i);
	}

	std::cout << nums->peek() << std::endl;

	std::cout << nums->pop() << std::endl;
	std::cout << nums->pop() << std::endl;
	std::cout << nums->pop() << std::endl;
	std::cout << nums->size() << std::endl;
	std::cout << nums->isEmpty() << std::endl;

	std::cout << std::endl;
	nums->print();
}

void stacktest() {
	Stack<int> *nums = new Stack<int>();

	for (int i = 1; i <= 10; i++) {
		nums->push(i);
	}

	std::cout << nums->peek() << std::endl;

	std::cout << nums->pop() << std::endl;
	std::cout << nums->pop() << std::endl;
	std::cout << nums->pop() << std::endl;
	std::cout << nums->size() << std::endl;
	std::cout << nums->isEmpty() << std::endl;

	std::cout << std::endl;
	nums->print();
}

void linkedlistqueuetest() {
	LinkedListQueue<int> *nums = new LinkedListQueue<int>();

	for (int i = 1; i <= 10; i++) {
		nums->enqueue(i);
	}

	std::cout << nums->peek() << std::endl;

	std::cout << nums->dequeue() << std::endl;
	std::cout << nums->dequeue() << std::endl;
	std::cout << nums->dequeue() << std::endl;
	std::cout << nums->size() << std::endl;
	std::cout << "Is empty: " << nums->isEmpty() << std::endl << std::endl;
	nums->print();
	nums->clear();
	std::cout << std::endl << std::endl;

	for (int i = 1; i <= 10; i++) {
		nums->enqueue(i);
	}
	nums->print();
}

void queuetest() {
	Queue<int> *nums = new Queue<int>();

	for (int i = 1; i <= 10; i++) {
		nums->enqueue(i);
	}

	std::cout << nums->peek() << std::endl;

	std::cout << nums->dequeue() << std::endl;
	std::cout << nums->dequeue() << std::endl;
	std::cout << nums->dequeue() << std::endl;
	std::cout << nums->size() << std::endl;
	std::cout << "Is empty: " << nums->isEmpty() << std::endl << std::endl;
	nums->print();
	nums->clear();
	std::cout << std::endl << std::endl;

	for (int i = 1; i <= 10; i++) {
		nums->enqueue(i);
	}
	nums->print();
}

void settest() {
	Set<int> *numsList = new Set<int>();

	for (int i = 0; i < 10; i++) {
		numsList->add(i);
	}

	for (int i = 0; i < 10; i++) {
		numsList->add(i);
	}

	numsList->print();
}

void settest2() {
	Set<int> *nums = new Set<int>();

	srand(time(NULL));

	for (int i = 0; i < 100; i++) {

		int x = rand() % 10 + 1;

		nums->add(x);
	}

	nums->print();

	std::cout << "Size: " << nums->size() << std::endl;
}

void bintreetest() {
	BinaryTree<int> *nums = new BinaryTree<int>();
	//BinaryTree<char> *nums = new BinaryTree<char>();

	srand(time(NULL));

	for (int i = 0; i < 100; i++) {

		int x = rand() % 10 + 1;
		//char x = (char)(rand() % (127 - 33) + 33);

		nums->add(x);
	}

	nums->printInOrder();

	std::cout << std::endl << std::endl;
	std::cout << "Size: " << nums->size() << std::endl;
	std::cout << "Height: " << nums->height() << std::endl;
	std::cout << "Width: " << nums->width() << std::endl;
	std::cout << std::endl << std::endl;

	nums->remove(9);
	nums->invert();

	nums->printInOrder();

	std::cout << std::endl << std::endl;
	std::cout << "Size: " << nums->size() << std::endl;
	std::cout << std::endl << std::endl;

	//TODO: Sometimes remove deletes some 2s
}

void bintreetest2() {
	BinaryTree<char> *tree = new BinaryTree<char>();


	tree->add('2');
	tree->add('+');
	tree->add('3');
	tree->add('*');
	tree->add('6');

	tree->printPreOrder();
	std::cout << std::endl;
	tree->printInOrder();
	std::cout << std::endl;
	tree->printPostOrder();
	std::cout << std::endl;

}

void arraylisttest() {
	ArrayList<int> *list = new ArrayList<int>();

	for (int i = 0; i < 100; i++) {
		list->add(i);
	}

	for (int i = 0; i < 100; i++) {
		std::cout << list->get(i) << std::endl;
	}
}

void pqtest() {
	PriorityQueue<int> *queue = new PriorityQueue<int>();

	for (int i = 0; i < 10; i++) {
		queue->enqueue(i, i * 2);
	}

	queue->print();
}

void dequetest() {
	Deque<int> *list = new Deque<int>();

	try {
		if (list->isEmpty())
		{
			std::cout << "Deque is empty" << std::endl;
		}

		// Push elements
		list->pushBack(100);
		list->pushBack(200);
		list->pushBack(300);

		// Size of queue
		std::cout << "Size of dequeue = " << list->size() << std::endl;

		// Pop elements
		std::cout << list->popBack() << std::endl;
		std::cout << list->popBack() << std::endl;
		std::cout << list->popBack() << std::endl;
	}
	catch (...) {
		std::cout << "Some exception occured" << std::endl;
	}

	Deque<int> *list2 = new Deque<int>();

	try {
		if (list2->isEmpty())
		{
			std::cout << "Deque is empty" << std::endl;
		}

		// Push elements
		list2->pushBack(100);
		list2->pushBack(200);
		list2->pushBack(300);

		// Size of queue
		std::cout << "Size of dequeue = " << list2->size() << std::endl;

		// Pop elements
		std::cout << list2->popFront() << std::endl;
		std::cout << list2->popFront() << std::endl;
		std::cout << list2->popFront() << std::endl;
	}
	catch (...) {
		std::cout << "Some exception occured" << std::endl;
	}
}

void circularqueuetest() {
	CircularQueue<int> *list = new CircularQueue<int>(5);

	for (int i = 0; i < 5; i++) {
		list->enqueue(i);
		//std::cout << "Added " << i << std::endl;
	}

	list->print();

	std::cout << std::endl;
	std::cout << "Size: " << list->size() << std::endl;
	list->clear();
	std::cout << "Size: " << list->size() << std::endl;

	CircularQueue<char*> *q = new CircularQueue<char*>(3);

	q->enqueue("The");
	q->enqueue("end");
	q->enqueue("is");
	q->enqueue("nigh!");

	q->enqueue("Cool");

	q->print();
}

void circularlinkedlisttest() {
	CircularLinkedList<int> *list = new CircularLinkedList<int>();

	std::cout << "Starting" << std::endl;

	list->addBack(43);
	list->addBack(83);
	list->addBack(98);
	list->addBack(65);
	list->addBack(4983);
	list->addBack(9898);
	list->addFront(5555555);

	std::cout << "Size: " << list->size() << std::endl;

	list->print();

	list->popBack();
	std::cout << "Size: " << list->size() << std::endl;
	list->print();

	list->popFront();
	std::cout << "Size: " << list->size() << std::endl;
	list->print();

	std::cout << "Finished" << std::endl;
}

void heaptest() {
	Heap<int> *heap = new Heap<int>();
	heap->insert(9);
	heap->insert(3);
	heap->insert(89);
	heap->insert(35);
	heap->insert(42);
	heap->insert(99);
	heap->insert(17);
	heap->insert(37);
	heap->insert(-1);
	heap->insert(0);
	heap->insert(17);
	heap->print();


	std::cout << "Min Heap Sort (lesser values to the right)..." << std::endl;
	heap->minHeapSort();
	heap->print();

	std::cout << "Max Heap Sort (greater values to the right)..." << std::endl;
	heap->maxHeapSort();
	heap->print();

}

int main() {
	// Call method to test data structure methods
	// bintreetest();
	std::cout << "Hello world!" << std::endl;

	heaptest();

	getchar();
	return 0;
}