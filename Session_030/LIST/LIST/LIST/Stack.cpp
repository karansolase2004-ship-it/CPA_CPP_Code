#include "Stack.hpp"

Stack::Stack() : pList(new list)
{
}

Stack::~Stack()
{
	delete pList; 
}

status_t Stack::push(int data)
{
	return pList->insert_end(data); 
}

status_t Stack::top(int* p_data) const
{
	return pList->get_end(p_data); 
}

status_t Stack::pop(int* p_data)
{
	return pList->pop_end(p_data); 
}

bool Stack::is_empty() const
{
	return pList->is_empty(); 
}
