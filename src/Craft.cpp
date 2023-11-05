#include "Craft.hpp"

#include <stdexcept>

using namespace ember;

const std::vector<std::string> Craft::categories = {
    "Sword",  "Shield", "Arrow",   "Axe",      "Staff",  "Orb",
    "Wand",   "Dagger", "Hammer",  "Bow",      "Spear",  "Armor",
    "Amulet", "Ring",   "Helm",    "Gauntlet", "Robe",   "Talisman",
    "Quiver", "Cloak",  "Chalice", "Greaves",  "Scepter"};

int Craft::getCost() const {
    return Item::getCost() * this->getCategoryModifier();
}

// short int Craft::getQualidade(){}

float Craft::getCategoryModifier() const {
    switch (this->category) {
        case EnumCraftCategory::Sword:
            return 1.42;
        case EnumCraftCategory::Shield:
            return 2.12;
        case EnumCraftCategory::Arrow:
            return 0.15;
        case EnumCraftCategory::Axe:
            return 1.45;
        case EnumCraftCategory::Staff:
            return 2.55;
        case EnumCraftCategory::Orb:
            return 3.68;
        case EnumCraftCategory::Wand:
            return 1.33;
        case EnumCraftCategory::Dagger:
            return 1.81;
        case EnumCraftCategory::Hammer:
            return 1.15;
        case EnumCraftCategory::Bow:
            return 1.10;
        case EnumCraftCategory::Spear:
            return 1.50;
        case EnumCraftCategory::Armor:
            return 7.42;
        case EnumCraftCategory::Amulet:
            return 0.5;
        case EnumCraftCategory::Ring:
            return 0.05;
        case EnumCraftCategory::Helm:
            return 1.15;
        case EnumCraftCategory::Gauntlet:
            return 1.16;
        case EnumCraftCategory::Robe:
            return 1.17;
        case EnumCraftCategory::Talisman:
            return 0.90;
        case EnumCraftCategory::Quiver:
            return 0.6;
        case EnumCraftCategory::Cloak:
            return 1.20;
        case EnumCraftCategory::Chalice:
            return 0.5;
        case EnumCraftCategory::Greaves:
            return 1.70;
        case EnumCraftCategory::Scepter:
            return 3.23;
        default:
            throw std::runtime_error("Impossible EnumCraftCategory reached");
            return 0.0;
    }
}
