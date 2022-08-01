#include<iostream>

class B{
public:
    B();
    B(const B&) = delete;
};

class D : public B{
};
int main(){
    D d;
    D d2(d);
    return 0;
}