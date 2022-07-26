#include<iostream>

class A{
public:
    A() = default;
    A(int ii) : i(ii) { }
    int get_v(){
        return i;
    }
private:
    int i;
};
// overload std::ostream for class type A
std::ostream &operator <<(std::ostream &os, A& a){
    os << a.get_v();
    return os;
}

int main(){
    A a(3);
    std::cout << a<< std::endl;
    return 0;
}