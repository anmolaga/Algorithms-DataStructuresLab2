#include "lab2_drones_manager.hpp"
#include <iostream>

// TODO: Implement all of the listed functions below

DronesManager::DronesManager() {
	DroneRecord* first(NULL);
	DroneRecord* last(NULL);
	unsigned int size(0);
}

DronesManager::~DronesManager() {
	delete[] first;
	first = NULL;
	delete[] last;
	last = NULL;
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




	// PURPOSE: Returns the value at the given index in the list
	// if index is invalid, returns last element; if the list is empty, returns DroneRecord(0)
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




// PURPOSE: Searches for the given value, and returns the index of this value if found	
// if not found, returns the size of the list; if the list is empty, returns 0
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




// PURPOSE: Prints all the elements in the list to the console

//HOW TO PRINT?---------------------------------------------------------------------
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


	// MUTATORS
	// PURPOSE: Inserts a value into the list at a given index; the list is not sorted
	// if the index is invalid, insertion is rejected
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
		
		return true;
	}	

}




// PURPOSE: Inserts a value at the beginning of the list; the list is not sorted
bool DronesManager::insert_front(DroneRecord value) {
	if(!first) {
	
		first = &value;
		return true;
}
	else {
		first->prev = &value;
		value.next = first;
		first = &value;
		return true;
	}
	
}



// PURPOSE: Inserts a value at the end of the list; the list is not sorted

bool DronesManager::insert_back(DroneRecord value) {
	if(!last) {
		first = &value;
		return true;
}
	else {
		last->next = &value;
		value.prev = last;
		last = &value;
	}
	return true;
}

// PURPOSE: Deletes a value from the list at the given index
bool DronesManager::remove(unsigned int index) {
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
		
		return true;
	}	

}


// PURPOSE: Deletes a value from the beginning of the list
bool DronesManager::remove_front() {
	return false;
	
	
}
// PURPOSE: Deletes a value at the end of the list
bool DronesManager::remove_back() {
	return false;
}


// PURPOSE: Replaces value at the given index with the given value; the list is not sorted	
// if the index is invalid, replacement is rejected

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




// reverses the list
bool DronesManager::reverse_list() {
	return false;
}

