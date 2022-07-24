#include "HW13-11.hpp"

int main(){
    {
        HasPtr p0("hello world");
        HasPtr p1("hi");
        p1 = p0;
    } 


    return 0;
}