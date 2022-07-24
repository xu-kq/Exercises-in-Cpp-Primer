#include "HW13-8.hpp"

int main(){
    HasPtr p0("hello world");
    HasPtr p1(p0);  // copy constructor

    HasPtr p2 = p0; // copy-assignment function 

    std::cout << sizeof(HasPtr) <<std::endl;
    int * p = new int();
    int * pp = new int();
    std::cout<< p <<"\t"<<pp<<std::endl;
    std::cout << "p0->str: " << p0.get_string() << "\taddr: "<< p0.get_addr() << std::endl;
    std::cout << "p1->str: " << p1.get_string() << "\taddr: "<< p1.get_addr() << std::endl;
    std::cout << "p2->str: " << p2.get_string() << "\taddr: "<< p2.get_addr() << std::endl;
    return 0;
}