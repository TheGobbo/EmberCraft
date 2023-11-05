#include "Item.hpp"

#include <random>

using namespace ember;

Item::Item(const std::string& nome, const std::string& desc,
           short int qualidade)
    : nome{nome}, desc{desc}, qualidade{qualidade} {}

Item::Item() : nome{"Nameless"}, desc{"Descpriptionless"} {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<short> d100(1, 100);

    // roll a d100 for quality
    this->qualidade = d100(gen);
}

std::string Item::getNome() const { return this->nome; }

std::string Item::getDescricao() const { return this->desc; }

short int Item::getQualidade() const { return this->qualidade; }

int Item::getCost() const {
    if (this->qualidade == 0) {
        return 100;
    }
    return (this->qualidade * this->qualidade) * 42;
}