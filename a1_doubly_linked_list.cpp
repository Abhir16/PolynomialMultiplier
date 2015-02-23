#include "a1_doubly_linked_list.hpp"
#include <cstddef>
#include <iostream>
using namespace std;

DoublyLinkedList::Node::Node(DataType data)
{
	value=data;
	prev= NULL;
	next = NULL;
}

DoublyLinkedList::DoublyLinkedList()
{
	head_ = NULL;
	tail_ = NULL;
	size_ = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
	if(size_==0)
		return;
	Node* temp = head_;
	while (temp->next != NULL)
	{
		Node* temp2 = temp->next;		
		delete temp;	
		temp = temp2;
	}
}

unsigned int DoublyLinkedList::size() const
{
	return size_;
}

unsigned int DoublyLinkedList::capacity() const
{
	return CAPACITY;
}

bool DoublyLinkedList::empty() const
{
	return (size_==0);
}

bool DoublyLinkedList::full() const
{
	return (size_ == CAPACITY);
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
	if (index >= size_ || index < 0)
		return tail_ -> value;
	else {
		Node* temp = head_;
		for ( int i =0; i< index; i++)
			temp = temp -> next;
		return temp-> value;
	}
}

unsigned int DoublyLinkedList::search(DataType value) const
{
	Node* temp = head_;
	for (int i = 0; i < size_; i++)
	{
		if (temp->value == value)
			return i;
		temp= temp->next;
	}
	return size_;
}

void DoublyLinkedList::print() const
{
	Node* temp = head_;
	for (int i = 0; i < size_; i++)
	{
		cout << i << " : " << temp -> value << endl;
		temp= temp -> next; 
	}
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
	Node* temp = head_;
	for(int i = 0; i < index; i++)
	{
		temp = temp->next;
	}
	return temp;
}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
	if (size_ == CAPACITY)
		return false;
	
	if (size_ == 0)
	{	
		Node* neo1 = new Node(value);
		head_ = neo1;
		tail_ = neo1;
		head_ ->prev = NULL;
		tail_-> next = NULL;
		neo1 = NULL;
	}
	else if (index == 0)
	{
		Node* neo2 = new Node(value);
		head_->prev = neo2;
		neo2 -> next = head_;
		neo2 -> prev = NULL; 
		head_ = neo2;
		neo2 = NULL;
	}
	else if (index == size_)
	{
		Node* neo3 = new Node(value);
		tail_->next = neo3;
		neo3->prev = tail_;
		tail_ = neo3;
		tail_ ->next = NULL;
		neo3=NULL;
	}
	else
	{
		Node* temp = head_;
		for (int i = 0; i < index - 1; i++)
		{
			temp = temp->next;
		}
		
		Node* neo = new Node(value);
		Node* temp2 = temp->next;
		temp2->prev = neo;
		temp->next = neo;
		neo->prev = temp;
		neo->next = temp2;	
		temp = NULL;
		temp2 = NULL;
		neo = NULL;
	}
	
	size_++;
	return true;
	
}

bool DoublyLinkedList::insert_front(DataType value)
{
	return insert (value,0);
}

bool DoublyLinkedList::insert_back(DataType value)
{
	return insert(value, size_);
}

bool DoublyLinkedList::remove(unsigned int index)
{
	
	if(size_ == 0 && index >= size_)
		return false;
	Node* temp;
	if(index == 0)
	{
		temp = head_->next;
		delete head_;
		temp->prev = NULL;
		head_ = temp;
		temp = NULL;
				
	}
	
	else if(index == size_-1)
	{
		temp = tail_->prev;
		delete tail_;
		temp->next = NULL;
		tail_ = temp;
		temp = NULL;		
	}
	else{
		temp = head_;
	
		for (int i = 0; i< index; i++)
		{
			temp = temp->next;
		}
		Node* temp2 = temp->next;
		temp2->prev = temp->prev;
		temp2 = temp->prev;
		temp2->next = temp->next;
		delete temp;
		temp = NULL;
		temp2 = NULL;
	}
	size_--;
	return true;
}

bool DoublyLinkedList::remove_front()
{
	return remove(0);
}

bool DoublyLinkedList::remove_back()
{
	return remove(size_-1);
}

bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
	if(size_ == 0 && index >= size_)
		return false;
	Node* temp = head_;
	for(int i = 0; i < index; i++)
	{
		temp = temp->next;		
	}
	
	temp->value = value;
	temp = NULL;
	return true;
}
