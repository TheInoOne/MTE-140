#include <iostream>
#include "a2_dynamic_stack.hpp"

typedef DynamicStack::StackItem StackItem;  // for simplicity
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
	size_ = 0;
	init_capacity_ = 16;
	capacity_ = init_capacity_;
	items_ = new int[capacity_];
	for (int i = 0; i < capacity_; i++ ) {
		items_[i] = 0;
	}
}

DynamicStack::DynamicStack(unsigned int cap)
{
	size_ = 0;
	capacity_ = cap;
	init_capacity_ = cap;
	items_ = new int[capacity_];
	for (int i = 0; i < capacity_; i++ ) {
		items_[i] = 0;
	}
}

DynamicStack::~DynamicStack()
{
	delete [ ]items_;
	items_ = NULL;
}

bool DynamicStack::empty() const
{
	if (size_ == 0) {
		return true;
	}
	else {
		return false;
	}
}

int DynamicStack::size() const
{
	return size_;
}

void DynamicStack::push(StackItem value)
{	
	if (size_ == capacity_) {
		capacity_ = capacity_ * 2;
		StackItem * temp = new StackItem[capacity_];
		for (int i = 0; i < size_; i++) {
			temp[i] = items_[i];
		}
		temp[size_] = value;
		size_++;
		delete items_;
		items_ = temp;
	}
	else {
		items_[size_] = value;
		size_++;
	}
}

StackItem DynamicStack::pop()
{
	if (size_ > 0) {
		int temp = items_[size_-1];
		items_[size_ -1] = NULL;
		size_ --;
		if (size_ <= ((0.25) * capacity_ )) {
			if (capacity_ * 0.5 > init_capacity_) {
				capacity_ = capacity_ * 0.5;
			}
			else {
				capacity_ = init_capacity_;
			}
			StackItem * tempArray = new StackItem[capacity_];
			for (int i = 0; i < size_; i++) {
				tempArray[i] = items_[i];
			}
			items_ = tempArray;
		}
		return temp;
	}
	else {
		return EMPTY_STACK;
	}
	
}

StackItem DynamicStack::peek() const
{
	if (size_ > 0) {
		return items_[size_-1];
	}
	else {
		return EMPTY_STACK;
	}
}

void DynamicStack::print() const
{
	
}
