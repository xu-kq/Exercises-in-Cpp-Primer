#include<iostream>
#include<string>
#include<initializer_list>
class test{
public:

// only aggregate class can be initialized by a initializer_list
    int i=2;
    float f;
    std::string s = "non value";
};



int main(){
    test T{1,2.};
    std::cout<< T.i << T.f << T.s<<std::endl;
    return 0;
}