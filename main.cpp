#include"Quote.hpp"
#include"Bulk_quote.hpp"
#include"Basket.hpp"

int main(){
    Basket bsk;
    Quote q1("123", 45);
    Bulk_quote q2("345", 45, 3, .15);
    bsk.add_item(q1);
    bsk.add_item(q2);

    bsk.total_receipt(std::cout);
    return 0;
}