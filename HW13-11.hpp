#include <iostream>
#include <string>

class HasPtr{
public:
    HasPtr(const std::string &s = std::string()) : 
        ps(new std::string(s)), i(0){}
    HasPtr(const HasPtr&);
    ~HasPtr() { delete ps; }
    HasPtr& operator =(HasPtr&);

    std::string get_string(){
        return *(this->ps);
    }
    int* get_addr(){

        return reinterpret_cast<int*>(this->ps);
    }

private:
    std::string *ps;
    int i;
};
HasPtr::HasPtr(const HasPtr& rhs) : 
    ps(new std::string(*rhs.ps)), i(rhs.i) {}

HasPtr& HasPtr::operator =(HasPtr& rhs){
    ps = new std::string(*rhs.ps);
    i = rhs.i;
    return *this;
}