#include <iostream> 
#include <typeinfo>

class Base{
    public: 
        void f(){
            std::cout << "Base::f():Inheritor" << std::endl; 
        }

        void g(){
            std::cout << "Base::g():Overridden but not virtual" << std::endl; 
        }

        virtual void h(){
            std::cout << "Base::h():Overridden and virtual" << std::endl; 
        }
}; 

class Derived : public Base{
    public: 
        void g(){
            std::cout << "Derived::g():Overridden but not virtual" << std::endl; 
        }

        void h(){
            std::cout << "Derived::h():Overridden and virtual" << std::endl; 
        }

        void k(){
            std::cout << "Derived::k():Derived specific function" << std::endl; 
        }
}; 

void test_all(void); 

int main(void){
    test_all(); 
    return EXIT_SUCCESS; 
}

void test_all(void){
    Derived D; 
    Base* pB = &D; 
    Derived* pD = &D; 

    std::cout << "Accessing, B::f(), B::g(), D::g(), B::h(), D::h(), D::k() from Base pointer" 
                << std::endl; 

    pB->f();    // INHERITOR 
    pB->g();    // Base::g(), overridden but not virtual 
    pB->Base::h();  // Base::h(), overridden and virtual
    dynamic_cast<Derived*>(pB)->g(); // Derived::g(), overridden but not virtual 
    pB->h();        // Derived::h(), overridden and virtual 
    dynamic_cast<Derived*>(pB)->k();    // Derived specific function 

    std::cout << "Accessing, B::f(), B::g(), D::g(), B::h(), D::h(), D::k() from Derived pointer" 
                << std::endl; 

    pD->f();    // B::f(), INHERITOR 
    pD->Base::g(); // B::g(), overriden & non-virtual 
    pD->Base::h();  // B::h(), overridden and virtual 
    pD->g();    // D::g(), overridden & non-virtual 
    pD->h();    // D::h(), overridden and virtual 
    pD->k();    // Derived speicifc function 

    std::cout   << "typeid(dynamic_cast<Derived*>(pB)):" 
                <<  typeid(dynamic_cast<Derived*>(pB)).name()
                << std::endl; 
}

