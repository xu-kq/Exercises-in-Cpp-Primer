#include<iostream>
class A{
public:
	friend A& operator+(A&, A&);
	void print(){
		std::cout << i << std::endl;
	}
private:
	int i = 1;
};

A& operator+(A& a, A& b){
	A *tmp = new A();
	tmp->i = a.i + b.i;
	return *tmp;
}

int main(){
	A a,b;
	A tmp = a+b;
	tmp.print();
	return 0;
}
