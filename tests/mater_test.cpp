#include <iostream>

#include "ConsoleItem.hpp"
#include "Item.hpp"
#include "Material.hpp"

using namespace ember;

void print(const Item& item) {
    std::cout << item.getNome() << ", " << item.getDescricao();
    std::cout << " [ Rarity: " << item.getQualidade() << " ]\n";
}

int main() {
    Material randomMaterial1;
    Material randomMaterial2;

    randomMaterial1.generateMaterial();
    randomMaterial2.generateMaterial();

    print(randomMaterial1);
    print(randomMaterial2);

    randomMaterial1.generateRandomMaterial();
    randomMaterial2.generateRandomMaterial();

    print(randomMaterial1);
    print(randomMaterial2);

    // std::cout << randomMaterial1.getCost() << '\n';
    // std::cout << randomMaterial2.getCost() << '\n';

    ConsoleItem::printItem(randomMaterial1);
    ConsoleItem::printItem(randomMaterial2);

    Item test1{"Ordinary Item", "Test", 0};
    Item test2{"Magical Item", "Test", 61};
    Item test3{"Heroic Item", "Test", 81};
    Item test4{"Legendary Item", "Test", 95};
    Item test5{"Mythical Item", "Test", 100};

    ConsoleItem::printItem(test1);
    ConsoleItem::printItem(test2);
    ConsoleItem::printItem(test3);
    ConsoleItem::printItem(test4);
    ConsoleItem::printItem(test5);

    return 0;
}