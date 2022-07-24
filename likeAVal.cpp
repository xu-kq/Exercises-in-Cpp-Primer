#include <iostream>
#include <string>

class HasPtr{
public:
    HasPtr(const std::string &s = std::string()) : 
        ps(new std::string(s)), i(0), use(new std::size_t(1)){}
    HasPtr(const HasPtr&);
    ~HasPtr() { 
        if(--*use == 0){
            delete ps; 
            delete use;
        }
    }
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
    std::size_t *use;
};
HasPtr::HasPtr(const HasPtr& rhs) : 
    ps(rhs.ps), i(rhs.i), use(rhs.use) { ++*use; }

HasPtr& HasPtr::operator =(HasPtr& rhs){
    // deal with self-assignment
    ++*rhs.use;
    if(--*use == 0){
        delete use;
        delete ps;
    }
    ps = rhs.ps;
    use = rhs.use;
    i = rhs.i;
    return *this;
}

int main(){
    HasPtr a("a");

    a = a;

    std::cout<< a.get_string() << std::endl;
    return 0;
}