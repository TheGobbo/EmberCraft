#include <iostream>

#include "Console.hpp"
#include "Item.hpp"
#include "Material.hpp"

using namespace ember;

int main() {
    Console::printItem(Item{"Ordinary Item", "Test 1", 0});
    Console::printItem(Item{"Magical Item", "Test 2", 61});
    Console::printItem(Item{"Heroic Item", "Test 3", 81});
    Console::printItem(Item{"Legendary Item", "Test 4", 95});
    Console::printItem(Item{"Mythical Item", "Test 5", 100});

    std::cout << std::endl;

    Material randomMaterial1;
    Material randomMaterial2;

    randomMaterial1.generateMaterial();
    randomMaterial2.generateMaterial();

    Console::printItem(randomMaterial1);
    Console::printItem(randomMaterial2);

    randomMaterial1.generateRandomMaterial();
    randomMaterial2.generateRandomMaterial();

    Console::printItem(randomMaterial1);
    Console::printItem(randomMaterial2);

    Material man_made = Material("A nice name", "With a cool description");
    Console::printItem(man_made);

    std::cout << std::endl;

    Craft longo = Craft{
        "A very long and detailed name that could overflow the limit assigned "
        "to this slot",
        "A Description, as long as the Name itself, to test the limits of this "
        "field"};

    Console::printCraft(longo);

    // for (int i = 0; i < 10; i++) {
    //     Console::printItem(Material{});
    // }

    return 0;
}