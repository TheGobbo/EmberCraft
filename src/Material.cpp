#include "Material.hpp"

// https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution

using namespace ember;

// clang-format off
const std::vector<std::string> Material::baseMaterials = {
    "Dragon", "Mineral", "Slime", "Bone", "Phoenix Feathers", "Void Crystal", 
    "Starlight Metal", "Shadow Silk", "Mithril Bark", "Astral Stone", 
    "Thunderwood", "Ectoplasmic Resin", "Celestial Coral", "Bloodmoon Obsidian"
};
const std::vector<std::string> Material::modifierMaterials = {
    "Wyvern", "Ogre", "Goblin", "Spirit", "Nether Demon", "Eldritch Entity", 
    "Cosmic Serpent", "Abyssal Specter", "Dreamweaver", "Infernal Gargoyle", 
    "Cursed Lich", "Void Wyrm", "Enigmatic Djinn", "Solar Empyrean"
};

const std::vector<std::string> Material::historical = {"Cursed", "Demonic", "Corrupted", "Blessed", "Godly", "Holy"};
const std::vector<std::string> Material::age = {"Ancient", "Timeless", "Eternal", "Forgotten", "Archaic"};
const std::vector<std::string> Material::colors = {"Scarlet", "Aquamarine", "Emerald", "Amethyst", "Golden", "Pale"};
const std::vector<std::string> Material::texture = {"Smooth", "Rough", "Iridescent", "Glowing", "Pristine"};
const std::vector<std::string> Material::element = {"Fire", "Ice", "Electric", "Earth", "Air", "Lava", "Frost"};
const std::vector<std::string> Material::source = {"Underground", "Celestial", "Volcanic", "Oceanic", "Unearthed"};
const std::vector<std::string> Material::process = {"Extracted", "Mined", "Grown", "Harvested", "Foraged", "Smelted", "Synthesized"};
// clang-format on

// Construtor
Material::Material(const std::string& base, const std::string& modifier)
    : Item{base, modifier} {}

Material::Material() : Item{} { this->generateRandomMaterial(); }

int Material::getCost() const { return Item::getCost() * 0.5; }

int Material::getQuantidade() const { return this->quantidade; }

std::string Material::generateMaterial() { return this->nome; }

std::string Material::generateRandomMaterial() {
    std::string excitingMaterial = "";

    // Randomly select attributes from the vectors
    short roll = Item::uniformDice(20);
    if (roll >= 15) {
        this->nome = this->getRandomAttribute(historical);
    } else if (roll >= 10) {
        this->nome = this->getRandomAttribute(age);
    } else {
        this->nome = this->getRandomAttribute(colors);
    }

    this->nome += " " + this->getRandomAttribute(texture);
    this->nome += " " + this->getRandomAttribute(baseMaterials);

    this->desc = this->getRandomAttribute(process);
    this->desc += " from the " + this->getRandomAttribute(source);
    this->desc += " " + this->getRandomAttribute(element);
    this->desc += " " + this->getRandomAttribute(modifierMaterials);

    return this->nome + ", " + this->desc;
}