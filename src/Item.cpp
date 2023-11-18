#include "Item.hpp"

#include <climits>
#include <stdexcept>

using namespace ember;

std::random_device rd;
std::mt19937 Item::dice_gen{rd()};

Item::Item(const std::string& nome, const std::string& desc,
           int qualidade)
    : nome{nome}, desc{desc}, qualidade{qualidade} {}

Item::Item(const std::string& nome, const std::string& desc)
    : nome{nome}, desc{desc} {
    this->randomQuality();
}

Item::Item() : nome{"Nameless"}, desc{"Descpriptionless"} {
    this->randomQuality();
}

// rolls a d100 with uniform distribution to assign a quality to the item
void Item::randomQuality() {
    // roll a d100 for quality
    this->qualidade = uniformDice(100);
}

// creates a uniform dice that returns from 1-max
int Item::uniformDice(int max) {
    if (max > INT_MAX) {
        throw std::invalid_argument(
            "Max dice size exceeded the variable limit: " +
            std::to_string(INT_MAX));
    }

    std::uniform_int_distribution<int> dice(1, max);

    return dice(Item::dice_gen);
}

void Item::setNome(const std::string& nome) { this->nome = nome; }

void Item::setDescricao(const std::string& desc) { this->desc = desc; }

void Item::setQualidade(int qualidade) { this->qualidade = qualidade; }

std::string Item::getNome() const { return this->nome; }

std::string Item::getDescricao() const { return this->desc; }

int Item::getQualidade() const { return this->qualidade; }

int Item::getCost() const {
    if (this->qualidade == 0) {
        return 100;
    }
    return (this->qualidade * this->qualidade) * 4.2;
}