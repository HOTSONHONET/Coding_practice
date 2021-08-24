// C++ program to return first node of loop
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	struct Node* next;
};

Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->next = NULL;
	return temp;
}

// A utility function to print a linked list
void printList(Node* head)
{
	while (head != NULL) {
		cout << head->key << " ";
		head = head->next;
	}
	cout << endl;
}

// Function to detect first node of loop
// in a linked list that may contain loop
Node* detectLoop(Node* head)
{

	// Create a temporary node
	Node* temp = new Node;
	while (head != NULL) {

		// This condition is for the case
		// when there is no loop
		if (head->next == NULL) {
			return NULL;
		}

		// Check if next is already
		// pointing to temp
		if (head->next == temp) {
			break;
		}

		// Store the pointer to the next node
		// in order to get to it in the next step
		Node* nex = head->next;

		// Make next point to temp
		head->next = temp;

		// Get to the next node in the list
		head = nex;
	}

	return head;
}

/* Driver program to test above function*/
int main()
{
	Node* head = newNode(50);
	head->next = newNode(20);
	head->next->next = newNode(15);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(10);

	/* Create a loop for testing */
	head->next->next->next->next->next = head->next->next;

	Node* res = detectLoop(head);
	if (res == NULL)
		cout << "Loop does not exist";
	else
		cout << "Loop starting node is " << res->key;

	return 0;
}
