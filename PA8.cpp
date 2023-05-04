/*
David Sosa Vidal
CPSC 122
Professor Jacob Shea
Programming Assignment 8, Doubly Linked List and Queues
PA8 Function File
*/

#include "PA8.h"

/***********************************************************
Member Function: runPrimesPrompt()
Inputs: Nohting
Outputs: Nothing
General Description: 

This function prompts the user and runs the main program
***********************************************************/
void runPrimesPrompt() {
	Sieve sieve; // reuse same Sieve object
	int n = -1;
	cout << "This program computes all prime numbers up to a maximum using the Sieve of Eratosthenes." << endl;
	do {
		cout << endl << "Please enter n, where n is max value to show primes up to and including (-1 to quit): ";
		cin >> n;
		if (n != -1) {
			sieve.setN(n);
			sieve.run();
		}
	} while (n != -1);
}