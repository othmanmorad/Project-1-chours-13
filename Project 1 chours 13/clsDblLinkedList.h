#pragma once
#include <iostream>
using namespace std;	
template <class T>
class clsDblLinkedList
{
protected: 
	int _Size = 0;
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

		// Increment Size
		_Size++;

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

		// Increment Size
		_Size++;

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

		// Increment Size
		_Size++;
	}


	// Delete Node
	void DeleteNode(Node*& NodeToDelete)
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

		// Decrement Size
		_Size--;
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
		

			// Decrement Size
			_Size--;
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

			// Decrement Size
			_Size--;
		
	}

	
	// Size By Counter
	// This Function Loops Through the List and Counts the Number of Nodes
	// This is a Simple Way to Get the Size of the List but it is not Efficient as it takes O(n) Time Complexity
     int SizeByCounter()
	{
		int Count = 0;	
		Node* current = head;
		// Start from Head
		while (current != NULL)
		{
			// Increment Count
			Count++;
			// Move to Next Node
			current = current->Next;
		}
		return Count;

		
	}

	 // Size
	 // This Function Returns the Size of the List by Using a Counter that is Updated Whenever a Node is Added or Deleted
	 // This is a More Efficient Way to Get the Size of the List as it takes O(1) Time Complexity
	 int Size()
	 {
		 return _Size;
	 }

	 // Is Empty
	 // This Function Checks if the List is Empty by Checking if the Head is NULL
	 // This is a Simple Way to Check if the List is Empty
	 // This Function takes O(1) Time Complexity
	 bool IsEmptyByHead()
	 {
		 return head == NULL;
	 }

	 // Is Empty By Size
	 // This Function Checks if the List is Empty by Checking if the Size is 0
	 // This is a More Efficient Way to Check if the List is Empty as it takes O(1) Time Complexity
	 bool IsEmpty()
	 {
		 return (_Size == 0 ? true : false);
	 }

	 // Clear By Loop
	 // This Function Clears the List by Looping Through the List and Deleting Each Node
	 // This is a Simple Way to Clear the List but it is not Efficient as it takes O(n) Time Complexity
	 // This Function also Sets the Head to NULL and Size to 0 after Clearing the List
	 void ClearByLoop()
	 {
		 Node* current = head;
		 while (current != NULL)
		 {
			 Node* NodeToDelete = current;
			 current = current->Next;
			 delete NodeToDelete;
			 _Size--;
		 }
		 head = NULL;
		 _Size = 0;
	 }

	 // Clear
	 // This Function Clears the List by Setting the Head to NULL and Size to 0
	 // This is Uses DeleteFirstNode repeatedly Clear the List as it takes O(n) Time Complexity
	 void Clear()
	 {
		 while (_Size > 0)
		 {
			 DeleteFirstNode();
		 }
	 }
};

