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
Material::Material(const std::string& base, const std::string& modifier) {
    this->nome = base + " " + modifier;
    this->desc = "";
    this->qualidade = 0;
}

Material::Material() : Item{} {
    std::random_device rd;
    std::mt19937 gen(rd());

    this->nome = getRandomAttribute(Material::baseMaterials, gen) + " " +
                 getRandomAttribute(Material::modifierMaterials, gen);
}

int Material::getCost() const { return Item::getCost() * 0.5; }

int Material::getQuantidade() const { return this->quantidade; }

std::string Material::getRandomAttribute(
    const std::vector<std::string>& attributeList, std::mt19937& gen) {
    std::uniform_int_distribution<std::size_t> dist(0,
                                                    attributeList.size() - 1);
    return attributeList[dist(gen)];
}

std::string Material::generateMaterial() { return this->nome; }

std::string Material::generateRandomMaterial() {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<short> d20(1, 20);

    std::string excitingMaterial = "";

    // Randomly select attributes from the vectors
    short roll = d20(gen);
    if (roll >= 15) {
        this->nome = this->getRandomAttribute(historical, gen);
    } else if (roll >= 10) {
        this->nome = this->getRandomAttribute(age, gen);
    } else {
        this->nome = this->getRandomAttribute(colors, gen);
    }

    this->nome += " " + this->getRandomAttribute(texture, gen);
    this->nome += " " + this->getRandomAttribute(baseMaterials, gen);

    this->desc = this->getRandomAttribute(process, gen);
    this->desc += " from the " + this->getRandomAttribute(source, gen);
    this->desc += " " + this->getRandomAttribute(element, gen);
    this->desc += " " + this->getRandomAttribute(modifierMaterials, gen);

    return this->nome + ", " + this->desc;
}