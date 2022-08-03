# Exercises-in-Cpp-Primer
A loose collection of interesting Exercises in the book.

## 模板与泛型编程
### 1 函数模板(function template)
```cpp
template<typename T>
//      ^^^^^^^^^^^ 
// template parameter list
int compare(const T &v1, const T &v2){
    if(v1 < v2) return -1;
    if(v1 > v2) return 1;
    return 0;
}
```
### 2 实例(instanitiation)/ 实例化(instantiate)
```cpp
// (int, int)
cout << compare(1, 2) << endl;
// (vec, vec)
std::vector<int> vec1{1, 2, 3}, vec2{4, 5, 6};
cout << compare(vec1, vec2) << endl;
```