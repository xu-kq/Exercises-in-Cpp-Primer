#include<iostream>

class Base{
public:
    virtual int fcn(){
        std::cout << "int base::fcn()";
        return 0;
    }
};

class D1 : public Base{
public:
    int fcn(int){
        std::cout<< "int D1::fcn(int)" << std::endl;
        return 0;
    }
    virtual void f2(){
        std::cout<<"void D1::f2()" << std::endl;
    }
};

class D2 : public D1{
public:
    int fcn(int);
    int fcn(){
        std::cout << "int D2::fcn()" << std::endl;
        return 0;
    }
    void f2() override{
        std::cout<<"void D2::f2()"<< std::endl;
    }
};

int main(){
    Base base;
    D1 d1;
    D2 d2;
    Base* p = &d2;
    p->fcn();
    return 0;
}