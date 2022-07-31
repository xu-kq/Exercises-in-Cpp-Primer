#include"Disc_quote.hpp"

class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string& book, double price, std::size_t qty, double disc) :
                Disc_quote(book, price, qty, disc) { }

    // derivate class must re-declarate all the virtual function 
    double net_price(std::size_t) const override;
private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

double Bulk_quote::net_price(std::size_t cnt) const{
    if( cnt >= min_qty){
        return cnt * (1 - discount) * price;
    }
    else{
        return cnt * price;
    }
}