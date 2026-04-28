#include <iostream>
#include "clsDblLinkedList.h"
using namespace std;

int main()
{


	clsDblLinkedList<int> MydblLinkedList;

	if (MydblLinkedList.IsEmpty())
	{
		cout << "\nLinked List is Empty\n";
	}
	else
	{
		cout << "\nLinked List is Not Empty\n";
	}

	MydblLinkedList.InsertAtBiginning(5);
	MydblLinkedList.InsertAtBiginning(4);
	MydblLinkedList.InsertAtBiginning(3);
	MydblLinkedList.InsertAtBiginning(2);
	MydblLinkedList.InsertAtBiginning(1);
	cout << "\nLinked List Contenet: \n";
	MydblLinkedList.PrintList();

	clsDblLinkedList<int>::Node* N1 = MydblLinkedList.Find(2);
	if (N1 != NULL)
	{
		cout << "\nNode Found with Value: " << N1->Value << endl;
	}
	else
	{
		cout << "\nNode Not Found\n";
	}

	MydblLinkedList.InsertAfter(N1, 25);
	cout << "\nLinked List Contenet After Inserting 25 After 2: \n";
	MydblLinkedList.PrintList();



	MydblLinkedList.InsertAtEnd(50);
	cout << "\nLinked List Contenet After Inserting 50 At End: \n";
	MydblLinkedList.PrintList();


	clsDblLinkedList<int>::Node* NodeToDelete = MydblLinkedList.Find(25);
	MydblLinkedList.DeleteNode(NodeToDelete);
	cout << "\nLinked List Contenet After Delete 25 : \n";
	MydblLinkedList.PrintList();

	MydblLinkedList.DeleteFirstNode();
	cout << "\nLinked List Contenet After Delete First Node : \n";
	MydblLinkedList.PrintList();

	MydblLinkedList.DeleteLastNode();
	cout << "\nLinked List Contenet After Delete Last Node : \n";
	MydblLinkedList.PrintList();
	cout << endl;
	cout << "\n";

	cout<<"Linked List Size By counter : " << MydblLinkedList.SizeByCounter();
	cout << "\nLinked List Size By Loop : " << MydblLinkedList.Size() << endl;


	if (MydblLinkedList.IsEmpty())
	{
		cout << "\nLinked List is Empty\n";
	}
	else
	{
		cout << "\nLinked List is Not Empty\n";
	}


	cout << "\nLinked List size Before Clear: \n";
	cout << MydblLinkedList.Size() << endl;


	MydblLinkedList.Clear();
	cout << "\nLinked List size After Clear: \n";
	cout << MydblLinkedList.Size() << endl;
}

