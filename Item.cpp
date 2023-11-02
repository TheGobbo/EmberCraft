#include "Item.hpp"

using namespace ember;

Item::Item(const std::string& nome, const std::string& desc,
           short int qualidade, int custo)
    : nome{nome}, desc{desc}, qualidade{qualidade}, custo{custo} {}

Item::~Item() {}
