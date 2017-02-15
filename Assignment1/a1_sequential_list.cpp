#include <iostream>
#include "a1_sequential_list.hpp"
using namespace std;

SequentialList::SequentialList(unsigned int cap)
{
	capacity_ = cap;
	data_ = new DataType[cap];
	size_ = 0;
}

SequentialList::~SequentialList()
{
	delete data_;
	data_ = NULL;
}

unsigned int SequentialList::size() const
{
		return size_;
}

unsigned int SequentialList::capacity() const
{
	return capacity_;
}

bool SequentialList::empty() const
{
	if (size_ == 0)
	return true;
	else return false;
}

bool SequentialList::full() const
{
	if (size_ == capacity_)
	return true;
	else return false;
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
	if (index <= capacity_) {
		return data_[index];
	}
	else {
		return data_[size_];
	}
}

unsigned int SequentialList::search(DataType val) const
{
	int index = 0;
	bool found = false;
	
	while (index <= size_ && !found) {
		if (data_[index] == val) {
			found = true;
		}
		else
			index++;
	}
	if (found)
		return index;
	else
		return size_;
}

void SequentialList::print() const
{
	for (int i = 0; i < size_; i++) {
		cout << data_[i] << " ";
	}
}

bool SequentialList::insert(DataType val, unsigned int index)
{
	if (index > size_) {
		return false;
	} 
	if(index <= capacity_ && size_ != capacity_ && capacity_ != 0) {
		int newArray[size_-index+1];
		for(int i = index; i < size_; i++) {
			newArray[i] = data_[i];
		}
		data_[index] = val;
		size_ += 1;
		for(int i = index + 1; i < size_; i++) {
				data_[i] = newArray[i-1];
		}
		return true;
	}
	else
		return false;
}

bool SequentialList::insert_front(DataType val)
{
	if(capacity_ != 0 && size_ != capacity_) {
		int newArray[size_];
		for(int i = 0; i < size_; i++) {
			newArray[i] = data_[i];
			//data_[i+1] = data_[i];
		}
		data_[0] = val;
		size_ += 1; 
		for(int i = 1; i < size_; i++) {
			data_[i] = newArray[i-1];
		}
		return true;
	}
	else {
		return false;
	}
}

bool SequentialList::insert_back(DataType val)
{

	if(capacity_ != 0 && size_ != capacity_) {
		size_ += 1;
		data_[size_ - 1] = val;
		return true;
	}
	else
		return false;
}

bool SequentialList::remove(unsigned int index)
{
	if (size_ != 0 && index <= size_) {
		data_[index] = NULL;
		for(int i = index; i < size_; i++) {
			data_[i] = data_[i+1];
		}
		size_ -= 1;	
		return true;
	}
	else
		return false;
}

bool SequentialList::remove_front()
{
	if (remove(0))
		return true;
	else
		return false;
}

bool SequentialList::remove_back()
{
	if (size_ != 0) {
		data_[size_-1] = NULL;
		size_ -= 1;
		return true;
	}
	else
		return false;	
}

bool SequentialList::replace(unsigned int index, DataType val)
{
	if (index < capacity_) {
		data_[index] = val;
		return true;
	}
	else
		return false;
}

bool SequentialList::is_sorted_asc() const {
	if(size_ == 0){
		return true;
	}
	for(int i = 0; i < size_-1; i++) {
		if (data_[i+1] < data_[i]) 
			return false;	
	}
	return true;
}

bool SequentialList::is_sorted_desc() const {
	if(size_ == 0){
		return true;
	}
	for(int i =0; i < size_-1; i++) {
		if (data_[i+1] > data_[i]) 
			return false;	
	}
	return true;
}

bool SequentialList::insert_sorted_asc(DataType val) {
	if(size_ == 0) {
		data_[0] = val;
		size_ += 1;
		return true;
	}
	else if(capacity_ != 0 && size_ != capacity_ && is_sorted_asc() == 1){
		for(int i = 0; i < size_; i++) {
			if(data_[i] > val) {
				insert(val, i);
				return true;
			}
		}
		size_ += 1;
		data_[size_-1] = val;
		return true;
	}
	else
		return false;
}

bool SequentialList::insert_sorted_desc(DataType val) {
	if(size_ == 0) {
		data_[0] = val;
		size_ += 1;
		return true;
	}
	else if(capacity_ != 0 && size_ != capacity_ && is_sorted_desc() == 1){
		for(int i = 0; i < size_; i++) {
			if(data_[i] < val) {
				insert(val, i);
				return true;
			}
		}
		size_ += 1;
		data_[size_-1] = val;
		return true;
	}
	else
		return false;
}

void SequentialList::sort_asc() {
	int temp;
	for (int i = 0; i < size_; i++) {
		for (int j = i+1; j < size_; j++) {
			if(data_[j] < data_[i]) {
				temp = data_[i];
				data_[i] = data_[j];
				data_[j] = temp;
			}
		}	
	}
}
    
void SequentialList::sort_desc() {
	int temp;
	for (int i = 0; i < size_; i++) {
		for (int j = i+1; j < size_; j++) {
			if(data_[j] > data_[i]) {
				temp = data_[i];
				data_[i] = data_[j];
				data_[j] = temp;
			}
		}	
	}
}

