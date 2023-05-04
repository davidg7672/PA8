/*
David Sosa Vidal
CPSC 122
Professor Jacob Shea
Programming Assignment 8, Doubly Linked List and Queues
Doubly Linked List Function File
*/

#include "DoublyLinkedList.h"

// Constructor
DoublyLinkedList::DoublyLinkedList() {
	head = NULL;
	tail = NULL;
}

// Destructor
DoublyLinkedList::~DoublyLinkedList() {
	// free each Node's memory in the list
	destroyList();
}

// Getter
Node * DoublyLinkedList::getHead() const {
	return head;
}

// Getter
Node * DoublyLinkedList::getTail() const {
	return tail;
}

// Setter
void DoublyLinkedList::setHeadAndTail(Node * newHead, Node * newTail) {
	if (head != NULL) {
		destroyList();
	}
	head = newHead;
	tail = newTail;
}

/***********************************************************
Member Function: destroyList()
Inputs: Nohting
Outputs: Nothing
General Description: 

This funciton walks through each node in the doubly linked 
list and free memory for each node. 
***********************************************************/
void DoublyLinkedList::destroyList() {
	Node * currNode = head;
	Node * nextNode = NULL;

	while (currNode != NULL) {
		// save the link to the next node
		nextNode = currNode->next;
		// can safely delete currNode
		delete currNode;
		currNode = nextNode;
	}
	head = NULL;
	tail = NULL;
}

/***********************************************************
Member Function: displayList()
Inputs: Nohting
Outputs: Nothing
General Description: 

This funciton displays the doubly linked list
***********************************************************/
void DoublyLinkedList::displayList() {
	Node * currNode = head;
	
	cout << "head->";
	while (currNode != NULL) {
		cout << currNode->value << "<->";
		// progress towards BC being false
		currNode = currNode->next;
	}
	cout << "NULL" << endl;
	if (tail != NULL) {
		cout << "tail->" << tail->value << endl;
	}
	else {
		cout << "tail->NULL" << endl;
	}
}

/***********************************************************
Member Function: addToEnd()
Inputs: integer for new value
Outputs: Nothing
General Description: 

This funciton adds a new node to the end of the doubly linked
list, does this by getting the value
***********************************************************/
void DoublyLinkedList::addToEnd(int newValue) {
	Node *newNode = new Node;
    newNode->value = newValue;
    newNode->prev = tail;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
		tail = newNode;
        return;
    }
	else {
		tail->next = newNode;
		tail = newNode;
	}
}

/***********************************************************
Member Function: deleteAtFront()
Inputs: Nohting
Outputs: The value of the node that was a deleted
General Description: 

This function will delete the node at the front
***********************************************************/
int DoublyLinkedList::deleteAtFront() {
	int value;
	
	if(head == NULL) {
		return -1;
	}

	value = head->value;

	Node *tempNode = head;
	head = head->next;

	if(head == NULL) {
		tail = NULL;
	}
	else {
		head->prev = NULL;
	}

	delete tempNode;
	return value;
}

/***********************************************************
Member Function: deleteNode()
Inputs: Target Value
Outputs: Returns the value of the node that was deleted
General Description: 

This funciton will take in a target value, find that value,
and the delete the node that holds the value
***********************************************************/
int DoublyLinkedList::deleteNode(int targetValue) {
	// List empty
	// Node to delete is the first
	// Node to delete isn't the first node
	// node to delete is tail
	int value = -1;

	if (head == NULL) {
		return value;
	}

	Node *currNode = head;

	while (currNode != NULL && currNode->value != targetValue) {
		currNode = currNode->next;
	}

	if (currNode == NULL) {
		return value;
	}

	value = currNode->value;

	if (currNode == head) {
		head = currNode->next;

		if (head == NULL) {
			tail = NULL;
		} 
		else {
			head->prev = NULL;
		}
	} 
	else if (currNode == tail) {
		tail = currNode->prev;
		tail->next = NULL;
	} 
	else {
		currNode->prev->next = currNode->next;
		currNode->next->prev = currNode->prev;
	}

	delete currNode;
	return value;
}

/*
EXTRA CREDIT
*/
void DoublyLinkedList::addToFront(int newValue) {

}

/*
EXTRA CREDIT
*/
int DoublyLinkedList::deleteAtEnd() {
	
	return -1; // 
}

/*
EXTRA CREDIT
*/
void DoublyLinkedList::insertInOrder(int newValue) {
	
}