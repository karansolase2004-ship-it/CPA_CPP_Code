#ifndef _QUEUE_HPP 
#define _QUEUE_HPP 

#include "list.hpp"

int QUEUE_EMPTY = LIST_EMPTY; 

class Queue
{
private: 
	list* pList; 
public: 
	Queue(); 
	~Queue(); 
	status_t enqueue(int data); 
	status_t peek(int* p_data) const; 
	status_t dequeue(int* p_data); 
	bool is_empty() const; 
};


#endif 

