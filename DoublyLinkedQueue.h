/*
David Sosa Vidal
CPSC 122
Professor Jacob Shea
Programming Assignment 8, Doubly Linked List and Queues
Doubly Linked Queue Header File
*/

#ifndef DOUBLY_LINKED_QUEUE_H
#define DOUBLY_LINKED_QUEUE_H

#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

class DoublyLinkedQueue : public DoublyLinkedList {
	public:    
		// common queue operations
		// implementation provided

		void displayQueue();

		// implementations not provided
		void enqueue(int);
		int dequeue();
		void clear();
		bool isEmpty();
		int size();

		// sieve specific queue operation
		// implementation not provided
		void removeDivisibleBy(int);

};

#endif