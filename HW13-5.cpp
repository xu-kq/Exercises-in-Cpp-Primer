#include <iostream>
#include <string>

class HasPtr{
public:
    HasPtr(const std::string &s = std::string()) : 
        ps(new std::string(s)), i(0){}
        
    //todo: copy constructor
    HasPtr(const HasPtr& rhs) : 
        ps(new std::string(*rhs.ps)) { }

    std::string get_string(){
        return *(this->ps);
    }
    int* get_addr(){

        return reinterpret_cast<int*>(this->ps);
    }

    std::string *ps;
    int i;
};

int main(){
    HasPtr p0("hello world");
    HasPtr p1(p0);

    // std::cout<<typeid(p0.get_addr()).name()<<std::endl;
    // std::cout << (int*) p0.ps << "\t" << reinterpret_cast<int*>(p0.ps) << std::endl;

    std::cout << "p0->str: " << p0.get_string() << "\taddr: "<< p0.get_addr() << std::endl;
    std::cout << "p1->str: " << p0.get_string() << "\taddr: "<< p1.get_addr() << std::endl;
    return 0;
}