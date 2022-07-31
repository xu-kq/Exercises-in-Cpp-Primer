#include"Bulk_quote.hpp"

int main(){
    Bulk_quote q("book", 1.0, 3, 1.0);
    print_total(std::cout, q, 3);
    return 0;
}