#include "list.cpp"
// #include "Date.hpp"
#include <cstring> 

int main(void){
    cpa::dsa::list<int> lst; 
    for(
        int data = 0; 
        data < 5; 
        ++data
    )
        lst.insert_end((data+1) * 100); 
    std::cout   << "After insert_start():" << std::endl
                <<  lst; 

    cpa::dsa::list<char> clist; 
    const char* name = "CoreCode Programming Academy"; 
    for(
        std::size_t i = 0; 
        i < strlen(name); 
        ++i
    )
        clist.insert_end(name[i]); 
    std::cout << clist; 

    /* cpa::dsa::list<Date> date_list; 
    date_list.insert_end(Date(1, 12, 1977)); 
    date_list.insert_end(Date(2, 11, 1999));
    date_list.insert_end(Date(3, 10, 2023));
    date_list.insert_end(Date(4, 9, 2022));
    date_list.insert_end(Date(5, 8, 1965));
    std::cout << date_list; 

    std::cout << "iterator on int:" << std::endl; 
    for(
        cpa::dsa::list<int>::iterator iter = lst.begin(); 
        iter != lst.end(); 
        ++iter
    )
        std::cout << "*iter=" << *iter << std::endl; 

    std::cout << "iterator on char:" << std::endl; 
    for(
        cpa::dsa::list<char>::iterator iter = clist.begin(); 
        iter != clist.end(); 
        ++iter
    ) 
        std::cout << "*iter=" << *iter << std::endl; 

    std::cout << "iterator on Date:" << std::endl; 
    for(
        cpa::dsa::list<Date>::iterator iter = date_list.begin(); 
        iter != date_list.end(); 
        ++iter
    ) 
        std::cout << "*iter=" << *iter << std::endl;  */

    return 0; 
}

