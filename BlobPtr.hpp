#include<memory>
#include"Blob.hpp"
template<typename T> class BlobPtr{
public:
    BlobPtr() : curr(0) { }
    BlobPtr(Blob<T> &a, size_t sz = 0) : 
            wptr(a.data), curr(sz) { }
    T& operator*() const{
        auto p = check(curr, "dereference past end");
        return (*p)[curr] // (*p)为本对象指向的vector
    }
    // 当处于类模板的作用域中时，可以简写Blob<T>&为
    // 递增和递减
    BlobPtr& operator++();
    BlobPtr& operator--();
    BlobPtr& operator++(int); // 后置
    BlobPtr& operator--(int);

private:
    // 若检查成功，check返回一个指向vector的shared_ptr
    std::shared_ptr<std::vector<T>>
        check(std::size_t, const std::string&) const;
    // 保存一个weak_ptr，表示底层vector可能被销毁
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr; //数组中的当前位置
};

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator++(){
    ++*this;
    return this;
}
// 后置递增
// 直到遇到类名才进入作用域
template<typename T>
BlobPtr<T>& BlobPtr<T>::operator++(int){
    BlobPtr ret = *this;
    *this++;
    return ret;
}