#include "lab2_drones_manager.hpp"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
// TODO: Implement all of the listed functions below

DronesManager::DronesManager() {
	DroneRecord* first(NULL);
	DroneRecord* last(NULL);
	unsigned int size(0);
}

DronesManager::~DronesManager() {
		DroneRecord* current = first;
	while(current) {
		current = current->next;
		delete first;
		first = current;
	}
	first = last = NULL;
	size = 0;
}

bool operator==(const DronesManager::DroneRecord& lhs, const DronesManager::DroneRecord& rhs) {
	bool comparison = false;
	comparison = comparison && (lhs.droneID == rhs.droneID);
	return comparison;
}

unsigned int DronesManager::get_size() const {
	int counter = 0;
	DroneRecord* p = first;
	while(p != NULL)
	{
		counter++;
		p = p->next;
	}
	return counter;
}

bool DronesManager::empty() const {
	if (first == NULL)
		return true;
	else
		return false;
}

DronesManager::DroneRecord DronesManager::select(unsigned int index) const {
	int length = get_size();
	if (index < 0 || index > length)
	{
		return *last;
	}
	else if (empty())
	{
		return DroneRecord(0);
	}
	else
	{
		DroneRecord* end = first;
		for (int i = 0; i < index; i++)
		{
			end -> next;
		}
		return *end;
	}
}

unsigned int DronesManager::search(DroneRecord value) const {
	DroneRecord* check = first;
	int counter = 0;
	if (empty())
	{
		return 0;
	}
	else 
	{
		while(check != NULL)
		{
			if(value == *check)
			{
				return counter;
			}
			check = check -> next;
			counter++;
		}
	}
	return get_size();
}

void DronesManager::print() const {
	int length = get_size();
	DroneRecord print[length];
	DroneRecord* printer = first;
	int i = 0;
	while(printer != NULL)
	{
		print[i] = *printer;
		printer = printer -> next;
		i++;
	}
	for (int i = 0; i < length; i++)
	{
		cout << print[i].droneType << endl;
		cout << print[i].manufacturer << endl;
		cout << print[i].description << endl;
		cout << print[i].batteryType << endl;
	}
}

bool DronesManager::insert(DroneRecord value, unsigned int index) {
	int size = get_size();
	if (size < 0 || index > size)
	{
		return false;
	} else {
		DroneRecord* prevNode = first;
		for (int i = 0; i < (index-1); i++)
		{
			prevNode = prevNode -> next;
		}
		
		// assign the next of the new inserted node to the nextNode in the list
		value.next = prevNode->next;
		
		// the previous of the new node needs to point to the previous node
		value.prev = prevNode;
		
		// the next of the previous Node should point to the adress of the new node
		prevNode->next = &value;
		
		(value.next)->prev = &value;
		size++;
		return true;
	}	

}

bool DronesManager::insert_front(DroneRecord value) {
	if(!first) {
		first = &value;
		size++;
		return true;
}
	else {
		first->prev = &value;
		value.next = first;
		first = &value;
		size++;
		return true;
	}
	
}

bool DronesManager::insert_back(DroneRecord value) {
	if(!last) {
		first = &value;
		last = &value;
		size++;
		return true;
}
	else {
		last->next = &value;
		value.prev = last;
		last = &value;
		size++;
	}
	return true;
}

bool DronesManager::remove(unsigned int index) {
	int size = get_size();
	if (size < 0 || index > size)
	{
		return false;
	} else {
		DroneRecord* prevNode = first; 
		for(int i =0; i< (index-1); i++)
		{
			prevNode = prevNode -> next;
		}
		
		DroneRecord* temp = (prevNode->next);
		
		prevNode->next = prevNode->next->next;
		(prevNode->next)->prev->prev = (prevNode->next)->prev;
		
		delete[] temp;
		temp = NULL;
		size--;
		return true;
}
}

bool DronesManager::remove_front() {
	if(!first) {
		return false;
}
	else if(get_size()==1){
		delete[] first;
		first = NULL;
		size--;
		return true;
	} else {
		DroneRecord* temp = first->next;
		delete[] first;
		first = NULL;
		first = temp;
		first->prev = NULL;
		size--;
		return true;
	}

}

bool DronesManager::remove_back() {
	if(!last) {
		return false;
}
	else if(get_size()==1){
		delete[] last;
		last = NULL;
		size--;
		return true;
	} else {
		DroneRecord* temp = last->prev;
		delete[] last;
		last = NULL;
		last = temp;
		last->next = NULL;
		
		size--;
		return true;
	}
}

bool DronesManager::replace(unsigned int index, DroneRecord value) {
	int size = get_size();
	DroneRecord* p = first;
	
	if (index > size || index < 0)
		return false;
		
	for (int i = 0; i < size; i++)
	{
		if (index == i)
		{
			*p = value;
		}
		p = p -> next;
	}
}

bool DronesManager::reverse_list() {
	DroneRecord* current = first;
	DroneRecord *prev = NULL, *next = NULL;
	bool success = true;
	
	while(current != NULL)
	{
		next = current->next;
		
		current->next = prev;
		
		prev=current;
		current=next;
		success = true;
	}
	first = prev;
	
	return success;
}

