#include "a1_doubly_linked_list.hpp"
#include "a1_tests.hpp"
#include <iostream>

using namespace std;

DoublyLinkedList::Node::Node(DataType data)
{
	next = NULL;
	prev = NULL;
	value = data;
}

DoublyLinkedList::DoublyLinkedList()
{
	head_ = NULL;
	tail_ = NULL;
	size_ = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
	Node* current = head_;
	if (current != NULL){
	
		while (current -> next != NULL)
		{
			current = current -> next;
			delete current -> prev;
			current -> prev = NULL;
		}
		
		if (current != NULL)
		{
			delete current;
			current = NULL;
		}
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
	return (size_ == 0);
}

bool DoublyLinkedList::full() const
{
	return (size_ == CAPACITY);
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
	Node * current = head_;
	if (index >= 0 && index < size_) {
		for (int i = 0; i < index; i++) {
			current = current -> next;
		}	
	}
	else {
		return tail_ -> value;
	}
	return current -> value;
	
}

unsigned int DoublyLinkedList::search(DataType value) const
{
	Node * current = head_;
	for (int i = 0; i < size_; i++) {
		if (current -> value == value) {
			return i;
		}
		current = current -> next;
	}
	return size_;
}

void DoublyLinkedList::print() const
{
	Node * current = head_;
	for (int i = 0; i < size_; i++) {
		cout << current ->  value << " ";
		current = current -> next;
	}
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{	
	Node * current = head_;
	if (index < size_) {
		for (int i = 0; i < index; i++) {
			current = current -> next;
		}
		return current;
	}
	return NULL;
}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
	if (CAPACITY > 0 && index <= size_ && index >= 0 && size_  < CAPACITY) {
		Node * newNode = new Node(value);
		Node * current = head_;
	
		if (size_ == 0) {
			head_ = newNode;
			tail_ = newNode;
			newNode -> next = NULL;
			newNode -> prev = NULL;
		}
		else if (index == size_) {
			tail_ -> next = newNode;
			newNode -> next = NULL;
			newNode -> prev = tail_;
			tail_ = newNode;
		}
		else if (index == 0) {
			head_ -> prev = newNode;
			newNode -> next = head_;
			newNode -> prev = NULL;
			head_ = newNode; 
		}
		else {
			for (int i = 0; i < index; i++ ){
				current = current -> next;
			}
			current -> prev -> next = newNode;
			newNode -> prev = current -> prev;
			newNode -> next = current ;
			current -> prev = newNode;
		}
		size_ ++;
		return true;
	}
	else {
		return false;
	} 
}

bool DoublyLinkedList::insert_front(DataType value)
{
	return insert(value, 0);
}

bool DoublyLinkedList::insert_back(DataType value)
{
	return insert(value, size_); 
}

bool DoublyLinkedList::remove(unsigned int index)
{
	if (CAPACITY > 0 && index >= 0 && index < size_ && size_ > 0)
	{
		Node* old;
		Node * current = head_;

		if (size_ == 1){
			old = head_;
			head_ = NULL;
			tail_ = NULL;
		}
		else if (index == 0){
			old = head_;
			head_ = head_ -> next;
			head_ -> prev = NULL;
		}
		else if (index == size_ - 1){
			old = tail_;
			tail_ = tail_ -> prev;
			tail_ -> next = NULL;
		}
		else {
			for(int i = 0; i < index; i++){
				current = current -> next;
			}
			current -> prev -> next = current -> next;
			current -> next -> prev = current -> prev;
		}
		size_--;
		return true;
		
	}
	else {
		return false;
	}
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
	remove(index);
	insert(value, index);
}

bool DoublyLinkedList::is_sorted_asc() const
{
	if (size_ != 0){
		Node* current = head_;
		while (current -> next){
			if (current -> value > current -> next -> value){
				return false;
			}
			current = current -> next;
		}
	}
	return true;
}

bool DoublyLinkedList::is_sorted_desc() const
{
	if (size_ != 0){
		Node* current = head_;
		while (current -> next){
			if (current -> value < current -> next -> value){
				return false;
			}
			current = current -> next;
		}
	}
	return true;
}

bool DoublyLinkedList::insert_sorted_asc(DataType val)
{
	if (size_== 0){
		return insert(val, 0);
	}
	else if (is_sorted_asc()){
		Node* current = head_;
		int i = 0;
		while (current -> value < val && i < size_){
			i++;
			if (current -> next) 
				current = current -> next;
		}
		return insert (val, i);
	}
	return false;
}


bool DoublyLinkedList::insert_sorted_desc(DataType val)
{
	if (size_== 0){
		return insert(val, 0);
	}
	else if (is_sorted_desc()){
		Node* current = head_;
		int i = 0;
		while (current -> value > val && i < size_){
			i++;
			if (current -> next)
				current = current -> next;
		}
		return insert (val, i);
	}
	return false;
}


void DoublyLinkedList::sort_asc()
{
	if (size_ > 1){
		for(int i = 0; i < size_; i++){
			for(int j = i ; j < size_; j++){
				if (select(i) > select(j)){
					DataType temp = select(j);
					replace(j, select(i));
					replace(i, temp);
				}
			}
		}
	}
}

void DoublyLinkedList::sort_desc()
{
	if (size_ > 1){
		for(int i = 0; i < size_; i++){
			for(int j = i ; j < size_; j++){
				if (select(i) < select(j)){
					DataType temp = select(j);
					replace(j, select(i));
					replace(i, temp);
				}
			}
		}
	}
}
