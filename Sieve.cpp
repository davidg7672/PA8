/*
David Sosa Vidal
CPSC 122
Professor Jacob Shea
Programming Assignment 8, Doubly Linked List and Queues
Sieve Function File
*/

#include "Sieve.h"

// Constructor
Sieve::Sieve() {
	n = 0;
	numsQ = new DoublyLinkedQueue();
	primesQ = new DoublyLinkedQueue();
}

// Destructor
Sieve::~Sieve() {
	if (numsQ != NULL) {
		delete numsQ;
	}
	if (primesQ != NULL) {
		delete primesQ;
	}
}

// Getter
int Sieve::getN() const {
	return n;
}

// Setter
void Sieve::setN(int nParam) {
	n = nParam;
}

/***********************************************************
Member Function: run()
Inputs: Nohting
Outputs: Nothing
General Description: 

This function computes primes and does a lot with the queue,
this is where a lot of the heavy lifting goes on. 
***********************************************************/
void Sieve::computePrimes(void) {
	int prime;

	// creating an lempty queue to store primes
	primesQ->clear();
	
	// Creating a queue and filling with
	// consecutive integers 2 through n, inclusive
	for (int i = 2; i <= n; i++) {
		numsQ->enqueue(i);
	}
	
	do {
		prime = numsQ->dequeue();
		primesQ->enqueue(prime);
		numsQ->removeDivisibleBy(prime);
	} while (prime < sqrt(n));

	while (!numsQ->isEmpty()) {
		primesQ->enqueue(numsQ->dequeue());
	}
}

/***********************************************************
Member Function: reportResults()
Inputs: Doubly primePercent by reference
Outputs: Integer
General Description:

This funciton outputs data to console
***********************************************************/
int Sieve::reportResults(double& primePercent) {
	int numPrimes = 0;
	
	cout << "Primes up to " << n << " are as follows: " << endl;
	primesQ->displayQueue();
	
	numPrimes = primesQ->size();
	primePercent = static_cast<double>(numPrimes) / n * 100;
	
	return numPrimes;
}

/***********************************************************
Member Function: run()
Inputs: Nohting
Outputs: Nothing
General Description: 

This function runs everything
***********************************************************/
void Sieve::run() {
	int numPrimes = 0;
	double primePercent = 0.0;
	
	computePrimes();
	numPrimes = reportResults(primePercent);
	cout << numPrimes << " / " << n << " = " << fixed << setprecision(2) << primePercent << "\% primes" << endl;
}