#include "Queue.hpp"

Queue::Queue() : pList(new list)
{
}

Queue::~Queue()
{
    delete pList; 
}

status_t Queue::enqueue(int data)
{
    return pList->insert_end(data); 
}

status_t Queue::peek(int* p_data) const
{
    return pList->get_start(p_data); 
}

status_t Queue::dequeue(int* p_data)
{
    return pList->pop_start(p_data); 
}

bool Queue::is_empty() const
{
    return pList->is_empty(); 
}
