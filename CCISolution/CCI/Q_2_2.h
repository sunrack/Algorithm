#pragma once
#include "QBase.h"

class Node
{
public:
	int Data;
	Node* Next;

	Node(int data, Node* next) :Data(data), Next(next)
	{

	}

	Node* Add(int data, Node* head)
	{
		Node* node = new Node(data, head);
		return node;
	}
};

class Q_2_2 :
	public QBase
{
public:
	static Node* FindKthNode(Node* head, int k);

	static int GetNode(Node *head, int positionFromTail);

	static int Test();
	static int Test2();
};

