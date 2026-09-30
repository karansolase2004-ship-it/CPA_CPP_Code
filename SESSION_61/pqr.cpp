#include <iostream>
#include <set>
#include <cstring> // for memcpy

struct valueA {
    int a;
    float b;
};

struct valueB {
    int a;
    double b;
};

class Class1 {
private:
    union {
        valueA A;
        valueB B;
    } ;
    bool isValueA; // To track which type is stored in the union

public:
    // Constructor to initialize with a valueA pointer
    Class1(valueA* x) : isValueA(true) {
        std::memcpy(&A, x, sizeof(valueA));
        std::cout<<"pointer"<<std::endl;
    }

    // Constructor to initialize with a valueA reference
    Class1(valueA& a) : isValueA(true) {
        std::memcpy(&A, &a, sizeof(valueA));
        std::cout << "reference cc entered" << std::endl; 
        std::cout << "reference:this:" << std::hex << this << std::endl; 
        std::cout << "reference:&A:" << std::hex << &A << std::endl;
        std::cout << "reference:&a:" << std::hex << &a << std::endl;
        std::cout<<"reference CC leaving"<<std::endl;
    }

    // Define operator< for ordering in std::set
    bool operator<(const Class1& other) const {
        if (isValueA != other.isValueA) {
            return isValueA < other.isValueA; // Prioritize valueA over valueB
        }
        if (isValueA) {
            // Compare valueA members
            if (A.a != other.A.a) {
                return A.a < other.A.a;
            }
            return A.b < other.A.b;
        } else {
            // Compare valueB members (in case valueB is added later)
            if (B.a != other.B.a) {
                return B.a < other.B.a;
            }
            return B.b < other.B.b;
        }
    }
};

class Class2 {
private:
    std::set<Class1> classSet; // Set to store Class1 instances

public:
    // Add a Class1 instance to the set
    void addMember(const Class1& value) {
        classSet.insert(value);
    }

    // Check if a Class1 instance is a member of the set
    bool hasMember(const Class1& value) const {
        std::cout<<"add of value : "<<&value<<std::endl;
        return classSet.find(value) != classSet.end();
    }
};

int main() {
    valueA v1 = {10, 3.5f};   // First valueA
    valueA v2 = {20, 7.5f};   // Second valueA
    valueA v3 = {15, 2.0f};   // Third valueA

    std::cout << "main:C1 START" << std::endl; 
    Class1 c1(v1); // Create Class1 instances
    std::cout << "after construction of c1:addr(c1):" << std::hex << &c1 << std::endl 
                << "addr (v1):" << std::hex << &v1 << std::endl;  
    std::cout << "main:C1 END" << std::endl; 
    Class1 c2(v2);
    Class1 c3(v3);

    Class2 class2; // Create Class2 instance

    // Add members to the set
    class2.addMember(c1);
    class2.addMember(c2);

    // Check membership
    std::cout << "Has member c1: " << class2.hasMember(c1) << "\n"; // Expected: 1 (true)
    std::cout << "Has member c2: " << class2.hasMember(c2) << "\n"; // Expected: 1 (true)
    std::cout << "Has member c3: " << class2.hasMember(c3) << "\n"; // Expected: 0 (false)
    std::cout << "v1: " <<&v1<<std::endl;
    std::cout << "Has member v1: " << class2.hasMember(v1) << "\n"; // Expected: 0 (true)

    std::cout << "ADDRESS of v1:" << std::hex << &v1 << std::endl; 
    std::cout << "ADDRESS of (const Class1&)v1:" << &(const Class1&)v1 << std::endl; 
    std::cout << "typeof():" << typeid(&(const Class1&)v1).name() << std::endl; 

    return 0;
}

