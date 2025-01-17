#ifndef DRONES_MANAGER_TEST
#define DRONES_MANAGER_TEST

#include "lab2_drones_manager.hpp"

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

class DronesManagerTest {
public:
	// PURPOSE: New empty list is valid
	bool test1() {
		DronesManager manager;
		ASSERT_TRUE(manager.get_size() == 0)
		ASSERT_TRUE(manager.empty() == true)
		ASSERT_TRUE(manager.first == NULL)
		ASSERT_TRUE(manager.last == NULL)
	    return true;
	}
	
	// PURPOSE: insert_front() and insert_back() on zero-element list
	bool test2() {
		DronesManager manager1, manager2;
		manager1.insert_front(DronesManager::DroneRecord(100));
		manager2.insert_back(DronesManager::DroneRecord(100));
	    
		ASSERT_TRUE(manager1.get_size() == manager2.get_size() && manager1.get_size() == 1)
		ASSERT_TRUE(manager1.first != NULL && manager1.first == manager1.last)
		ASSERT_TRUE(manager2.first != NULL && manager2.first == manager2.last)
		ASSERT_TRUE(manager1.first->prev == NULL && manager1.last->next == NULL)
		ASSERT_TRUE(manager2.first->prev == NULL && manager2.last->next == NULL)
		ASSERT_TRUE(manager1.select(0) == manager2.select(0) && manager1.select(0) == DronesManager::DroneRecord(100))		
	    return true;
	}
	
	// TODO: Implement all of the test cases below
	
	// PURPOSE: select() and search() work properly
	bool test3() {
		// select
		DronesManager manager1;
		DronesManager::DroneRecord record1(100);
		manager1.insert_front(record1);
		ASSERT_TRUE(manager1.select(0) == record1);
		//search
		ASSERT_TRUE(manager1.search(record1)==0);
	    return true;
	}
	
	// PURPOSE: remove_front() and remove_back() on one-element list
	bool test4() {
		// remove front
		DronesManager manager1;
		DronesManager::DroneRecord record1(100);
		manager1.insert_front(record1);
		manager1.remove_front();
		ASSERT_TRUE(manager1.get_size()==0);
		
		// remove back
		DronesManager manager2;
		DronesManager::DroneRecord record2(101);
		manager2.insert_back(record2);
		manager2.remove_back();
		ASSERT_TRUE(manager1.get_size()==0);
		return true;
		
	}
	
	// PURPOSE: replace() and reverse_list() work properly
	bool test5() {
		
		// -------------REPLACE-----------------
		DronesManager manager1;
		DronesManager::DroneRecord record1(100);
		DronesManager::DroneRecord record2(101);
		manager1.insert_front(record1);
		
		// replacement should get rejected if index is false
		ASSERT_FALSE(manager1.replace(1, record2));
		
		manager1.replace(0, record2);
		ASSERT_TRUE(manager1.select(0)==record2);
	    
	    
	    // -------------REVERSE LIST-----------------
	    DronesManager manager2;
	    manager2.insert_front(record1);
	    manager2.insert_back(record2);
	    manager2.reverse_list();
	    ASSERT_TRUE(manager2.select(0)==record2);
	    ASSERT_TRUE(manager2.select(1)==record1);
	    
	    return true;
	}
	
	// PURPOSE: insert_front() keeps moving elements forward
	bool test6() {
		
		DronesManager inTest;
		
		DronesManager::DroneRecord nDrone1(100);
		DronesManager::DroneRecord nDrone2(200);
		DronesManager::DroneRecord nDrone3(300);
		DronesManager::DroneRecord nDrone4(400);
		
		bool success = true;
		
		inTest.insert_front(nDrone1);
		inTest.insert_front(nDrone2);
		inTest.insert_front(nDrone3);
		inTest.insert_front(nDrone4);
		
		success = success && (inTest.select(0)==nDrone4);
	    	success = success && (inTest.select(1)==nDrone3);
	    	success = success && (inTest.select(2)==nDrone2);
	  	success = success && (inTest.select(3)==nDrone1);
	    
		return success;
	}
	
	// PURPOSE: inserting at different positions in the list
	bool test7() {
		
		DronesManager inTest;
		
		DronesManager::DroneRecord nDrone1(100);
		DronesManager::DroneRecord nDrone2(200);
		DronesManager::DroneRecord nDrone3(300);
		DronesManager::DroneRecord nDrone4(400);
		
		bool success = true;
		
		inTest.insert(nDrone1,3);
		inTest.insert(nDrone2,4);
		inTest.insert(nDrone3,6);
		inTest.insert(nDrone4,7);
		
		success = success && (inTest.select(7) == nDrone4);
		success = success && (inTest.select(6) == nDrone3);
		success = success && (inTest.select(4) == nDrone2);
		success = success && (inTest.select(3) == nDrone1);
		
	   	return success;
	}
	
	// PURPOSE: try to remove too many elements, then add a few elements
	bool test8() {
	
	bool success = true;
	DronesManager manager;
	DronesManager::DroneRecord record(100);
	//removing an excess amount of elements
	for (int i = 0; i < record.size + 5; i++)
	{
		delete record[i];
		success = true;
	}
	//checking to see if removal occured
	ASSERT_TRUE(record.size == 0);
	//adding elements
	DronesManager:: DroneRecord record1(100);
	record = record1;
	for(int i = 0; i < record1.size(); i++)
	{
		if (record[i] == record1[i])
		{
			success = true;
		}

	}
	//checking to see if elements were added
	ASSERT_TRUE(success);
	return success;
	}
	
	// PURPOSE: lots of inserts and deletes, some of them invalid
	bool test9() {
	
	bool success = true;
	DronesManager manager;
	DronesManager::DroneRecord record1(100);
	DronesManager::DroneRecord record2(100);
	manager.insert_front(record1);
	manager.insert_back(record2);
	
	//checks for inserts
	ASSERT_TRUE(manager.size != NULL);
		
	for(int i = 0; i < record1.size(); i++)
	{
		//deleting elements with check for invalid
		if(record[i] != NULL)
			delete record1[i]
			
		success = true;
	}
	
	
	//check to see if elements were deleted
	ASSERT_TRUE(record1 == NULL);

	return success;
	}    
	    	
	// PURPOSE: lots of inserts, reverse the list, and then lots of removes until empty
	bool test10() {
	DronesManager manager2;
		
	//add elements
	for(int i = 0; i < 10; i++)
	{
		record1[i] = 5;
		record2[i] = 7;
	}
	ASSERT_TRUE(record1.size == record2.size == 9);
		
	//reverse list
	DronesManager::DroneRecord record1(100);
	DronesManager::DroneRecord recorde2(100);
	manager2.insert_front(record1);
	manager2.insert_back(record2);
	manager2.reverse_list();
	ASSERT_TRUE(manager2.select(0)==record2);
	ASSERT_TRUE(manager2.select(1)==record1);
		
	//remove until empty
	for (int i = 0; i < record1.size; i++)
	{
		delete record[i];
	}

	ASSERT_TRUE(record.size == 0);


	return success;
	} 
};

#endif
