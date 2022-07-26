# Exercises-in-Cpp-Primer
A loose collection of interesting Exercises in the book.

# 14.1 基本概念
重载运算符是一种特殊函数，名字由如下形式构成： **operator** + *symbol*

对于一个运算符函数，必须含有一个class类型参数；换句话说，不能为内置类型的运算符重载。
```cpp
int operator(int, int); $ wrong declaration
```