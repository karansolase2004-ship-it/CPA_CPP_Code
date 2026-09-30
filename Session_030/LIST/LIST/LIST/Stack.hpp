#ifndef _STACK_HPP 
#define _STACK_HPP 

#include "list.hpp"

const int STACK_EMPTY = LIST_EMPTY; 

class Stack
{
private: 
	list* pList; 
public: 
	Stack(); 
	~Stack(); 
	status_t push(int data); 
	status_t top(int* p_data) const; 
	status_t pop(int* p_data); 
	bool is_empty() const; 
};


#endif 
