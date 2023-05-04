/*
David Sosa Vidal
CPSC 122
Professor Jacob Shea
Programming Assignment 8, Doubly Linked List and Queues
Doubly Linked Queue Functions File
*/

#include "DoublyLinkedQueue.h"

/***********************************************************
Member Function: displayQueue()
Inputs: Nothing
Outputs: Nothing
General Description: 

This function displays the queue
***********************************************************/
void DoublyLinkedQueue::displayQueue() {
	Node *currNode = head;
	
	while (currNode != NULL) {
		cout << currNode->value << " ";
		// progress towards BC being false
		currNode = currNode->next;
	}
	cout << endl;
}

/***********************************************************
Member Function: enqueue()
Inputs: Integer value
Outputs: Nothing
General Description: 

This function will adds value at the end of the list
***********************************************************/
void DoublyLinkedQueue::enqueue(int newValue) {
	addToEnd(newValue);
}

/***********************************************************
Member Function: dequeue()
Inputs: Nothing
Outputs: The value that was deleted
General Description: 

This function will delete value at the front of the list
***********************************************************/
int DoublyLinkedQueue::dequeue() {
	return deleteAtFront(); 
}

/***********************************************************
Member Function: clear()
Inputs: Nothing
Outputs: Nothing
General Description: 

THis funciton will destory the list/queue
***********************************************************/
void DoublyLinkedQueue::clear() {
	destroyList();
}

/***********************************************************
Member Function: isEmpty()
Inputs: Nothing
Outputs: Bool expression
General Description: 

This funciton checks to if there is head, if there is, wil 
return false, because list isn't empty.
***********************************************************/
bool DoublyLinkedQueue::isEmpty() {
	if(head != NULL) {
		return false;
	}

	return true;
}

/***********************************************************
Member Function: size()
Inputs: Nothing
Outputs: integer of size
General Description: 

This function goes through the the loop and the finds the 
number of primes
***********************************************************/
int DoublyLinkedQueue::size() {
	Node *currNode = head;
	int counter = 0;

	while(currNode != NULL) {
		counter++;
		currNode = currNode->next;
	}
	
	return counter;
}

/***********************************************************
Member Function: removeDivisibleBy()
Inputs: Int p
Outputs: Nothing
General Description: 

This funciton will read in an int and check if the currNode
in queue is divisble by it, if not, then it will remove it. 
***********************************************************/
void DoublyLinkedQueue::removeDivisibleBy(int p) {
	Node *currNode = head;
	Node *tempNode = NULL;

	while(currNode != NULL) {

		if(currNode->value % p == 0) {
			tempNode = currNode;
			currNode = currNode->next;

			deleteNode(tempNode->value);
		} 
		
		else {
			currNode = currNode->next;
		}
	}
}