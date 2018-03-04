#include "stdafx.h"
#include "Q_2_2.h"
#include <iostream>

using namespace std;


Node* Q_2_2::FindKthNode(Node* head, int k)
{
	Node* p1 = head;
	Node* p2 = head;

	for (int i = 0; i<k; i++)
	{
		if (p1 != NULL)
		{
			p1 = p1->Next;
		}
		else
		{
			return NULL;
		}
	}

	while (p1 != NULL)
	{
		p1 = p1->Next;
		p2 = p2->Next;
	}

	return p2;


	/*
	    Node* fast = head;
    Node* slow = head;
    int delay = 0;
    
    while(fast != NULL)
    {
        fast = fast->next;
        
        delay++;
        
        // positionFromTail + 1 is the real gap
        // after dealy over the real gap, then start move slow
        if(delay > (positionFromTail + 1))
        {
            slow = slow->next;
        }
    }

    return slow->data;
	
	*/
}


int Q_2_2::Test()
{
	Node* head = NULL;
	Node* kNode = NULL;
	int k = 5;

	for (int i = 0; i< 10; i++)
	{
		head = head->Add(i, head);
	}

	kNode = head;

	while (kNode != NULL)
	{
		cout << kNode->Data <<" ";
		kNode = kNode->Next;
	}

	cout << "\n";

	kNode = NULL;

	kNode = FindKthNode(head, k);

	if (kNode != NULL)
	{
		cout << "the "<< k<<"th Node is: " << kNode->Data << endl;
	}
	else
	{
		cout << "the Kth Node is NULL " << endl;
	}



	cout << "OK\n" << endl;

	getchar();

	return 0;
}


int Q_2_2::GetNode(Node *head, int positionFromTail)
{
	static int pos = -1;
	static int data = -1;

	if (head == NULL)
	{
		return data;
	}

	GetNode(head->Next, positionFromTail);

	pos++;

	if (pos == positionFromTail)
	{
		data = head->Data;
	}

	return data;
}


int Q_2_2::Test2()
{
	Node* head = NULL;
	Node* kNode = NULL;
	int k = 0;
	int kData = 0;


	
	head = head->Add(0, head);
	head = head->Add(9, head);
	head = head->Add(8, head);
	head = head->Add(5, head);
	head = head->Add(4, head);
	head = head->Add(1, head);
	head = head->Add(2, head);


	while (kNode != NULL)
	{
		cout << kNode->Data << " ";
		kNode = kNode->Next;
	}

	cout << "\n";


	kData = GetNode(head, k);

	if (kNode != NULL)
	{
		cout << "the " << k << "th Node is: " << kNode->Data << endl;
	}
	else
	{
		cout << "the Kth Node is NULL " << endl;
	}



	cout << "OK\n" << endl;

	getchar();

	return 0;
}