// linkedlist_operations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Node
{
	int value;
	Node* next;
};

void createNode(Node** head, int data) {
	//receive head of linked list as node
	Node * tmpNode = new Node();
	tmpNode->value = data;
	tmpNode->next = NULL;
	//check if there are other nodes in list
	if (*head == NULL)
	{	
		*head = tmpNode;
		return;
	}

	//insert Node after last node
	Node * last = *head;
	while (last->next != NULL)
	{
		last = last->next;
	}

	last->next = tmpNode;

}


//insert at the beginning
void insert_at_beginning(Node ** head, int data) {
	Node * tmp = new Node();
	tmp->value = data;
	tmp->next = *head;
	*head = tmp;
}

//insert at any location
void insert_anywhere(Node ** head, int loc, int data) {
	Node * tmp = new Node();
	
	tmp->value = data;
	Node * location = *head;
	while (location != NULL)
	{	
		if (location->value == loc ) {
			tmp->next = location->next;
			location->next = tmp;
			break;
		}

		location = location->next;
	}
}

void delete_last_node(Node * head) {

	if (head->next == NULL)
	{
		delete head;
		return ;
	}
}


int main()
{
    //create a new node
	Node * head = new Node();
	head = NULL;
	createNode(&head, 3);
	createNode(&head, 7);
	createNode(&head, 9);
	createNode(&head, 11);

	insert_at_beginning(&head, 1);
	insert_anywhere(&head, 7, 20);
	delete_last_node(head);

	while (head != NULL)
	{
		std::cout << head->value << std::endl;
		head = head->next;
	}
}


