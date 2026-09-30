#include "cpa_list.cpp"
#include <iostream>



int main (void)
{
    cpa::dsa::list<int> L1;
    int data;

    std::cout << "Try To Get Data From Empty List" << std::endl;
    try{
        data = L1.get_start();
    }
    catch(const std::runtime_error& exc){
            std::cout << exc.what() << std::endl;
        }
    catch(const list_empty& exc)
    {
        std::cout << "HI";
        std::cout << exc.what() << std::endl;
    }

    std::cout << "Try  TO get end From Empty List " << std::endl;
    try{
        data = L1.get_end();
    }
    catch(const list_empty& exc){
        std::cout << exc.what() << std::endl;
    }

    for(int i=0; i<10; ++i){
        L1.insert_end(i * 10 + 5);
    }

    cpa::dsa::list<int>::iterator Iter = L1.begin();

    while(Iter != L1.end())
    {
        std::cout << *Iter << std::endl;
        ++Iter;
    }
    
    try{
        L1.insert_after(20, 18);
    }
    catch(const list_invalid_data& exc){
        std::cout << exc.what() << std::endl;
    }

    try{
        L1.insert_before(25, 10);
    }
    catch(const list_invalid_data& exc){
        std::cout << exc.what() << std::endl;
    }

    std::cout << L1;

    try{
        L1.insert_before(14, 2);
    }
    catch(const list_invalid_data& exc){
        std::cout << exc.what() << std::endl;
    }

    L1.pop_start();
    L1.pop_start();
    L1.pop_start();
    L1.pop_start();
    L1.pop_start();
    L1.pop_start();
    L1.pop_start();
    L1.pop_start();
    L1.pop_start();
    L1.pop_start();
    L1.pop_start();

    std::cout << L1;
    bool value = L1.empty();
    std::cout << "Value : " << value << std::endl;

    try{
        L1.get_start();
    }
    catch(const list_empty& exc){
        std::cout << exc.what() << std::endl;
    }

    try{
        L1.get_end();
    }
    catch(const list_empty& exc){
        std::cout << exc.what( )<< std::endl;
    }

    try{
        L1.pop_start();
    }
    catch(const list_empty& exc){
        std::cout << exc.what() << std::endl;
    }

    try{
        L1.pop_end();
    }
    catch(const list_empty& exc){
        std::cout << exc.what() << std::endl;
    }

    try{
        L1.remove_start();
    }
    catch(const list_empty& exc){
        std::cout << exc.what() << std::endl;
    }

    try{
        L1.remove_end();
    }
    catch(const list_empty& exc){
        std::cout << exc.what( ) << std::endl;
    }

    try{
        L1.remove_data(9);
    }
    catch(const list_invalid_data& exc){
        std::cout << exc.what() << std::endl;
    }

    size_t List_length = L1.size();

    std::cout << List_length << std::endl;
}