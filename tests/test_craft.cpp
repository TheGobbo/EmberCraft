#include "Console.hpp"
#include "Craft.hpp"

using namespace ember;

int main() {
    Craft c = Craft();

    Console::printCraft(c);

    c.setCategory(5);

    Console::printCraft(c);

    Craft *ptr = new Craft();

    Console::printCraft(*ptr);

    delete ptr;

    return 0;
}
