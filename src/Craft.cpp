#include "Craft.hpp"

#include <stdexcept>

#include "Material.hpp"

using namespace ember;

const std::vector<std::string> Craft::categories = {
    "Sword",  "Shield", "Arrow",   "Axe",      "Staff",  "Orb",
    "Wand",   "Dagger", "Hammer",  "Bow",      "Spear",  "Armor",
    "Amulet", "Ring",   "Helm",    "Gauntlet", "Robe",   "Talisman",
    "Quiver", "Cloak",  "Chalice", "Greaves",  "Scepter"};

// Weapon Descriptions
// clang-format off
const std::vector<std::string> Craft::legacy = {"Mighty", "Searing", "Thunderous", "Venomous", "Divine", "Infernal", "Heroic", "Cursed", "Ancient", "Royal", "Fabled", "Mythical"};
const std::vector<std::string> Craft::style = {"Elegant", "Brutal", "Swift", "Mystic", "Fierce", "Graceful"};
const std::vector<std::string> Craft::enhancement = {"Enchanted", "Cursed", "Radiant", "Vorpal", "Abyssal", "Luminous"};
const std::vector<std::string> Craft::material = {"Adamantine", "Obsidian", "Crystaline", "Ebony", "Mithril", "Dragonbone"};
const std::vector<std::string> Craft::alignment = {"Righteous", "Malevolent", "Neutral", "Chaotic", "Lawful", "Harmonious"};
const std::vector<std::string> Craft::effect = {"Flaming", "Freezing", "Shocking", "Smiting", "Draining", "Banishing"};
const std::vector<std::string> Craft::origin = {"Celestial", "Demonic", "Forged", "Legendary", "Mystical", "Ancient"};
// clang-format on

Craft::Craft() : Item{} {
    this->category_idx = Item::uniformDice(Craft::categories.size() - 1);

    this->randomCraft();
}

Craft::Craft(const std::string& material, int qualidade) : Item{} {
    this->category_idx = Item::uniformDice(Craft::categories.size() - 1);
    this->qualidade = std::min(100, qualidade + 10);
    this->nome = randomName();
    this->desc = material;
}

int Craft::getCost() const { return Item::getCost() * this->getCategoryModifier(); }

void Craft::setCategory(size_t index) {
    if (index > Craft::categories.size() || index <= 0) {
        throw std::invalid_argument("Index of Craft Category is out of range: " +
                                    std::to_string(index));
    }

    this->category_idx = index;
}

std::string Craft::getCategory() const {
    return Craft::categories[this->category_idx];
}

std::string Craft::randomName() {
    std::string nome;
    // Randomly select attributes from the vectors
    short roll = Item::uniformDice(20);
    if (roll >= 15) {
        nome = this->getRandomAttribute(legacy);
    } else if (roll >= 10) {
        nome = this->getRandomAttribute(style);
    } else {
        nome = this->getRandomAttribute(enhancement);
    }

    nome += " " + this->getRandomAttribute(effect);
    nome += " " + this->getRandomAttribute(alignment);
    nome += " " + this->getCategory();

    return nome;
}

std::string Craft::randomCraft() {
    this->desc = Material().getDescricao();

    return this->randomName() + ", " + this->desc;
}

float Craft::getCategoryModifier() const {
    switch (this->category_idx + 1) {
        // EnumCraftCategory::Sword
        case 1:
            return 1.42;

        // EnumCraftCategory::Shield
        case 2:
            return 2.12;

        // EnumCraftCategory::Arrow
        case 3:
            return 0.15;

        // EnumCraftCategory::Axe
        case 4:
            return 1.45;

        // EnumCraftCategory::Staff
        case 5:
            return 2.55;

        // EnumCraftCategory::Orb
        case 6:
            return 3.68;

        // EnumCraftCategory::Wand
        case 7:
            return 1.33;

        // EnumCraftCategory::Dagger
        case 8:
            return 1.81;

        // EnumCraftCategory::Hammer
        case 9:
            return 1.15;

        // EnumCraftCategory::Bow
        case 10:
            return 1.10;

        // EnumCraftCategory::Spear
        case 11:
            return 1.50;

        // EnumCraftCategory::Armor
        case 12:
            return 7.42;

        // EnumCraftCategory::Amulet
        case 13:
            return 0.5;

        // EnumCraftCategory::Ring
        case 14:
            return 0.05;

        // EnumCraftCategory::Helm
        case 15:
            return 1.15;

        // EnumCraftCategory::Gauntlet
        case 16:
            return 1.16;

        // EnumCraftCategory::Robe
        case 17:
            return 1.17;

        // EnumCraftCategory::Talisman
        case 18:
            return 0.90;

        // EnumCraftCategory::Quiver
        case 19:
            return 0.6;

        // EnumCraftCategory::Cloak
        case 20:
            return 1.20;

        // EnumCraftCategory::Chalice
        case 21:
            return 0.5;

        // EnumCraftCategory::Greaves
        case 22:
            return 1.70;

        // EnumCraftCategory::Scepter
        case 23:
            return 3.23;

        default:
            throw std::runtime_error("Impossible EnumCraftCategory reached");
            return 0.0;
    }
}
