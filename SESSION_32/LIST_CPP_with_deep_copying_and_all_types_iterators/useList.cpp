#include "list.hpp"

void test_list_copy_control(void);

int main(void){
    int data; 
    status_t status; 
    
    list* pList = new list; 
    std::cout << *pList;
    
    status = pList->get_start(&data); 
    assert(status == LIST_EMPTY); 

    status = pList->get_end(&data); 
    assert(status == LIST_EMPTY); 

    status = pList->pop_start(&data); 
    assert(status == LIST_EMPTY); 

    status = pList->pop_end(&data); 
    assert(status == LIST_EMPTY); 

    status = pList->remove_start(); 
    assert(status == LIST_EMPTY); 

    status = pList->remove_end(); 
    assert(status == LIST_EMPTY); 

    assert(pList->length() == 0); 
    assert(pList->is_empty() == true); 
    
    status = pList->insert_end(200); 
    assert(status == SUCCESS); 
    std::cout << *pList;

    status = pList->insert_after(200, 300); 
    assert(status == SUCCESS); 
    std::cout << *pList; 

    for(data = 1500; data <= 9500; data = data + 1000){
        status = pList->insert_end(data); 
        assert(status == SUCCESS); 
    }

    for(data = 550; data <= 950; data += 100){
        status = pList->insert_start(data); 
        assert(status == SUCCESS); 
    }

    std::cout << "after repeated calls to insert_after and insert_before" << std::endl; 
    std::cout << *pList; 

    std::cout << "Iterator :" << std::endl; 
    for(
        list::iterator iter = pList->begin(); 
        iter != pList->end(); 
        ++iter
    )
    {
        std::cout << "*iter:" << *iter << std::endl; 
        *iter = *iter + 5;
    }

    std::cout << "Const Iterator :" << std::endl;

    for(
        list::const_iterator iter = pList->cbegin();
        iter != pList->cend();
        ++iter
    ){
        std::cout << "*iter :" << *iter << std::endl;
        // *iter = *iter + 5;
    }

    std::cout << "Reverse Iterator :" << std::endl;

    for(
        list::reverse_iterator iter = pList->rbegin();
        iter != pList->rend();
        ++iter
    )
    {
        std::cout << "*iter :" << *iter << std::endl;
        *iter = *iter - 5;    
    }

    std::cout << "Const Reverse Iterator :" << std::endl;

    for(list::const_reverse_iterator iter = pList->rcbegin();
       iter != pList->rcend();
       ++iter
    ){
        std::cout << "*iter :" << *iter << std::endl;
    }

    status = pList->insert_after(-100, 300); 
    assert(status == LIST_INVALID_DATA); 

    status = pList->insert_before(-300, 1000); 
    assert(status == LIST_INVALID_DATA); 

    status = pList->get_start(&data); 
    assert(status == SUCCESS); 
    std::cout << "start_data:" << data << std::endl; 

    status = pList->get_end(&data); 
    assert(status == SUCCESS); 
    std::cout << "end_data:" << data << std::endl; 

    status = pList->pop_start(&data); 
    assert(status == SUCCESS); 
    std::cout << "start_data:" << data << std::endl; 
    std::cout << "after pList->pop_start(&data):" << *pList; 

    status = pList->pop_end(&data); 
    assert(status == SUCCESS); 
    std::cout << "start_data:" << data << std::endl; 
    std::cout << "after pList->pop_end(&data):" << *pList; 

    status = pList->remove_start(); 
    assert(status == SUCCESS); 
    std::cout << "after pList->remove_start(&data):" << *pList; 

    status = pList->remove_end(); 
    assert(status == SUCCESS); 
    std::cout << "after pList->remove_end(&data):" << *pList; 

    status = pList->remove_data(5500); 
    assert(status == SUCCESS); 
    std::cout << "after pList->remove_data(5500):"  << *pList; 

    status = pList->remove_data(-500); 
    assert(status == LIST_INVALID_DATA); 

    if(pList->is_empty() == false)
        std::cout << "List is not empty" << std::endl; 

    std::cout << "Length:" << pList->length() << std::endl; 

    delete pList; 
    pList = 0; 

    std::cout << "List destroyed successfully" << std::endl; 
    test_list_copy_control(); 
     std::cout << "List unit testing: all ok" << std::endl; 

    return EXIT_SUCCESS; 
}

void test_list_copy_control(void){
    list L1; 

    std::cout << "Testing copy control" << std::endl; 

    for(int data = 5; data <= 55; data = data + 10)
        L1.insert_end(data); 

    std::cout << "L1:" << L1 << std::endl; 

    list L2(L1);    // DEEP COPY 
    std::cout << "L2:" << L2 << std::endl; 

    // makes changes in L1 and print both L1 and L2 
    // make changes in L2 and print both L1 and L2 
    // expected behaviour: changes made in the one 
    // are NOT VISIBLE in the other due to deep copying 
    
    list L3; 
    for(int data = 100; data <= 800; data += 100)
        L3.insert_end(data); 

    L1 = L3; // DEEP COPY 
    std::cout << "L3:" << L3 << std::endl; 

    // makes changes in L1 and print both L1 and L3
    // make changes in L3 and print both L1 and L3
    // expected behaviour: changes made in the one 
    // are NOT VISIBLE in the other due to deep copying 
}


