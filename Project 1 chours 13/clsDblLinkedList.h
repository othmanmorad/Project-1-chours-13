#pragma once
#include <iostream>
using namespace std;	
template <class T>
class clsDblLinkedList
{
public :

	class Node
	{
	public:
	     T Value;
		Node* Next;
		Node* Previous;
		
	};

	Node* head = NULL;


	// Find Node
	Node* Find(int value)
	{
		// Start from Head
		Node* current = head;
		// Loop Until End of List
		while (current != NULL)
			
		{
			// Check if Value is Found
			if (current->Value == value)
				// Return Current Node
				return current ;
			// Move to Next Node
			current = current->Next;
		}
		return NULL;
	}


	// Print List
	void PrintList()
	{
		Node* current = head;
		// Start from Head
		while (current != NULL)
		{
			// Print Value
			cout << current->Value << " ";
			// Move to Next Node
			current = current->Next;
		}
		cout << endl;
	}


	// Insert At Biginning
	void InsertAtBiginning(T value)
	{
		// Create New Node
		Node* newNode = new Node();

		// Set Value
		newNode->Value = value;

		// Set Next and Previous
		newNode->Next = head;
		newNode->Previous = NULL;

		// Set Previous of Old Head to New Node
		if (head != NULL)
		{
			head->Previous = newNode;
		}

		// Set New Node as Head
		head = newNode;

	}

	// Insert After
	void InsertAfter(Node* current , T value)
	{
		// Create New Node
		Node* newNode = new Node();

		// Set Value
		newNode->Value = value;

		// Set Next and Previous
		newNode->Next = current->Next;
		newNode->Previous = current;

		// Set Previous of Next Node to New Node
		if (current->Next != NULL)
		{
			current->Next->Previous = newNode;
		}

		// Set Next of Current Node to New Node
		current->Next = newNode;

	}


	// Insert At End
	void InsertAtEnd(T value)
	{
		//create new node

		Node* newNode = new Node();
		// Set Value
		newNode->Value = value;
		newNode->Next = NULL;

		// If List is Empty
		if (head == NULL)
		{
			newNode->Previous = NULL;
			head = newNode;
			return;
		}
		else
		{
			// Find Last Node
			Node* LastNode = head;
			// Loop Until Last Node
			while (LastNode->Next != NULL)
			{
				// Move to Next Node
				LastNode = LastNode->Next;
			}
			// Set Next of
			LastNode->Next = newNode;
			// Set Previous of New Node to Last Node
			newNode->Previous = LastNode;
		}
	}


	// Delete Node
	void DeleteNode(Node* NodeToDelete)
	{
		// If List is Empty or Node to Delete is NULL
		if (head == NULL || NodeToDelete == NULL)
		{
			return;
		}

		// If Node to Delete is Head
		if (head == NodeToDelete)
		{
			head = NodeToDelete->Next;
			
		}

		// Set Next of Previous Node to Next Node
		if (NodeToDelete->Next != NULL)
		{
			// Set Previous of Next Node to Previous Node
			NodeToDelete->Next->Previous = NodeToDelete->Previous;
		}
		// Set Previous of Next Node to Previous Node
		if (NodeToDelete->Previous != NULL)
		{
			// Set Next of Previous Node to Next Node
			NodeToDelete->Previous->Next = NodeToDelete->Next;
		}
		
		delete NodeToDelete;
	}

	// Delete First Node
	void DeleteFirstNode()
	{
		// If List is Empty
		if (head == NULL)
		{
			// Nothing to Delete
			return;
		}
		
		
		
			// Store First Node to Delete
			Node* FirstNodeToDelete = head;

			// Move Head to Next Node
			head = head->Next;

			// Set Previous of New Head to NULL
			if (head != NULL)
			{
				
				head->Previous = NULL;
			}
			delete FirstNodeToDelete;
		
	}



	/// Delete Last Node
	void DeleteLastNode()
	{
		// If List is Empty
		if (head == NULL)
		{
			return;
		}
		// If List has Only One Node
		if (head->Next == NULL)
		{
			delete head;
			head = NULL;
			return;
		}
		
		//Current Node is not the last node
		// Current Node is Node before the last node
		// Find Last Node
			Node* Current = head;
			// we need to find the node before the last node to update its next pointer to NULL
			while (Current->Next->Next != NULL)
			{
				Current = Current->Next;
			}

			// Store Last Node to Delete
			Node* LastNodeToDelete = Current->Next;

			// Set Next of Current Node to NULL
			Current->Next = NULL;
			delete LastNodeToDelete;
		
	}
};

