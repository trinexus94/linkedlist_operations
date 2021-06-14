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
	//tmpNode->next = NULL;
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

//insert after specified location
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

//delete a node
Node * delete_a_node(Node * head, int data) {
	Node * location = new Node();
	Node * prev = new Node();

	//check if list is empty
	while (head != NULL)
	{

		if (head->value == data) {
			location = head;
			break;
		}
		prev = head;
		head = head->next;
	}

	//first if to delete the first node in the list
	if (prev->value == NULL)
	{
		head = location->next;
		delete location;

		return head;
	}
	else 
	{
		//delete node unless it is the last node in the list
		if (location->next != NULL) {
	
			prev->next = location->next;
			delete location;
			return head;
		}
		//delete last node in the list
		else
		{
			prev->next = NULL;
			delete location;
			return head;
		}
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
	createNode(&head, 15);

	insert_at_beginning(&head, 1);
	insert_anywhere(&head, 15, 20);

	std::cout << "Initial list: " << std::endl;
	Node * tmp = new Node();
	tmp = head;
	while (tmp != NULL)
	{

		std::cout << tmp->value << std::endl;

		tmp = tmp->next;
	}

	head = delete_a_node(head, 1);

	std::cout << "Final list: " << std::endl;

	while (head != NULL)
	{
		std::cout << head->value << std::endl;

		head = head->next;
	}
}


