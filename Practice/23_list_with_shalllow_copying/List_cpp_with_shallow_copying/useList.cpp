#include "list.hpp"
#include <cassert>

void test_list_copy_control(void);

int main (void){
    int data;
    status_t status;

    list* plist = new list;
    std::cout << *plist;

    status = plist->get_start(&data);
    assert(status == LIST_EMPTY);

    status =plist->get_end(&data);
    assert(status == LIST_EMPTY);
/* 
    plist->insert_end(200);

    status = plist->get_end(&data);
    assert(status == LIST_EMPTY); */

    status = plist->pop_start(&data); 
    assert(status == LIST_EMPTY); 

    status = plist->pop_end(&data); 
    assert(status == LIST_EMPTY); 

    status = plist->remove_start(); 
    assert(status == LIST_EMPTY); 

    status = plist->remove_end(); 
    assert(status == LIST_EMPTY); 

    assert(plist->length() == 0); 
    assert(plist->is_empty() == true); 

    status = plist->insert_end(200);
    assert(status == SUCCESS);
    std::cout << *plist;

    status = plist->insert_after(200, 300);
    assert(status == SUCCESS);
    std::cout << *plist;

    for(data = 1500; data <= 9500; data += 1000){
        status = plist->insert_end(data);
        assert(status == SUCCESS);
    }

    std::cout << "Iterator :" << std::endl;

    for(
        list::iterator iter = plist->begin();
        iter != plist->end();
        ++iter
    ){
        std::cout << "*iter :" << *iter << std::endl; 
    }


    status = plist->insert_before(-100, 400);
    assert(status == LIST_INVALID_DATA);

    status = plist->get_start(&data);
    assert(status == SUCCESS);
    std::cout << "Start data :" << data << std::endl;

    status = plist->get_end(&data);
    assert(status == SUCCESS);
    std::cout << "End data :" << data << std::endl;

    status = plist->pop_start(&data);
    assert(status == SUCCESS);
    std::cout << "pop Start :" << data << std::endl;

    status  = plist->pop_end(&data);
    assert(status  == SUCCESS);
    std::cout << "POP End :" << data << std::endl;

    std::cout << "Iterator :" << std::endl;

    for(
        list::iterator iter = plist->begin();
        iter != plist->end();
        ++iter
    ){
        std::cout << "*iter :" << *iter << std::endl; 
    }

    status = plist->remove_start();
    assert(status == SUCCESS);

    status = plist->remove_end();
    assert(status == SUCCESS);

    std::cout << "Iterator :" << std::endl;

    for(
        list::iterator iter = plist->begin();
        iter != plist->end();
        ++iter
    ){
        std::cout << "*iter :" << *iter << std::endl; 
    }

    status = plist->remove_data(4500);
    assert(status == SUCCESS); 

   /*  status = plist->remove_data(-5622);
    assert(status == LIST_INVALID_DATA); */

    std::cout << "Iterator :" << std::endl;
    
    for(
        list::iterator iter = plist->begin();
        iter != plist->end();
        ++iter
    )
    {
        std::cout << "*iter :" << *iter << std::endl; 
    }

    status = plist->remove_end();
    assert(status == SUCCESS);

    status = plist->remove_start();
    assert(status == SUCCESS);

    status = plist->remove_end();
    assert(status == SUCCESS);

    status = plist->remove_start();
    assert(status == SUCCESS);

    status = plist->remove_end();
    assert(status == SUCCESS);

    status = plist->remove_start();
    assert(status == SUCCESS);

    if(status = plist->is_empty()){
        std::cout << "List is empty " << std::endl;
    }

    std::cout << "Length :" << plist->length() << std::endl;

    delete plist;
    plist = 0;

    test_list_copy_control();
}

void test_list_copy_control(void){
    int data;
    list  L1;

    std::cout << "testing copy control :" << std::endl;

    for(int data = 5; data <= 55 ; data += 10){
        L1.insert_end(data);
    }

    std::cout << "L1 :" << L1 << std::endl;

    list L2(L1);

    std::cout << "L2 :" << L2 << std::endl;

    std::cout << "L1 :" << std::endl;  
    L1.print_refcount_listsize();
    std::cout << "L2 :" << std::endl;
    L2.print_refcount_listsize();

    L1.insert_end(65);
    std::cout << "After inserting 65 L1 :" << std::endl;  
    L1.print_refcount_listsize();
    std::cout << "After inserting 65 L2 :" << std::endl;  
    L1.print_refcount_listsize();

    list L3;
    for(int data=3; data <= 21; data += 3){
        L3.insert_end(data);
    }

    std::cout << "L3 :" << std::endl;
    L3.print_refcount_listsize();

    list* plist = new list(L3);
    std::cout << "plist :" << std::endl << *plist << std::endl;
    plist->insert_end(24);
    std::cout << "L3 :" << L3 << std::endl; 
    std::cout << "plist :" << std::endl;
    plist->print_refcount_listsize();

    delete plist;
    plist = 0;

    std::cout << "L3 :" << std::endl;
    L3.print_refcount_listsize();

    L3.pop_start(&data);
    std::cout << "L3 :" << std::endl;
    L3.print_refcount_listsize();
}