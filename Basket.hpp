#pragma once
#include<memory>
#include<set>
#include"Quote.hpp"

class Basket{
public:
    // Basket类使用默认构造函数和拷贝控制成员
    void add_item(const Quote& sale){
        items.insert(std::shared_ptr<Quote>(sale.clone()));
    }
    void add_item(Quote&& sale){
        items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
    }
    // 打印每本书的总价和购物篮中所有书的总价
    double total_receipt(std::ostream&) const;
private:
    // 用于辅助比较shared_ptr, multiset成员会用到
    static bool compare(const std::shared_ptr<Quote> &lhs,
        const std::shared_ptr<Quote> &rhs){
        return lhs->isbn() < rhs->isbn();
    }
    // multiset保存多个报价，按照compare排序成员
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*>
        items{compare};
};

double Basket::total_receipt(std::ostream &os) const{
    double sum = 0.0;
    // upper_boundhui返回一个迭代器，指向大于*iter的下一个元素 或 尾后指针
    for(auto iter = items.cbegin();
            iter != items.cend();
            iter = items.upper_bound(*iter)){
                sum += print_total(os, **iter, items.count(*iter));
            }
    os << "Total Sale: " << sum << std::endl; //打印最终价格
    return sum;
}