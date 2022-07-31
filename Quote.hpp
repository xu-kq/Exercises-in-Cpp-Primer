#include<iostream>
#include<string>

class Quote{
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price) :
        bookNo(book), price(sales_price) { }
    std::string isbn() const{
        return bookNo;
    }
    // 派生类自行修改不同的折扣记法
    virtual double net_price(std::size_t n) const{
        return n * price;
    }
    // 位于继承关系根节点的类，通常都需要一个虚析构函数
    virtual ~Quote() = default;
private:
    std::string bookNo;
protected:
    double price = 0.0;     // 不打折价格
};

// example for dynamic binding
// also called run-time binding
double print_total(std::ostream &os, const Quote &item, std::size_t n){
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
        <<" # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}