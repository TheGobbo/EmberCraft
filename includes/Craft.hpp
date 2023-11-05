
#ifndef CRAFT_HPP
#define CRAFT_HPP

#include <string>
#include <vector>

#include "Item.hpp"

namespace ember {
enum class EnumCraftCategory {
    Sword,
    Shield,
    Arrow,
    Axe,
    Staff,
    Orb,
    Wand,
    Dagger,
    Hammer,
    Bow,
    Spear,
    Armor,
    Amulet,
    Ring,
    Helm,
    Gauntlet,
    Robe,
    Talisman,
    Quiver,
    Cloak,
    Chalice,
    Greaves,
    Scepter
};

class Craft : public Item {
   public:
    Craft(/* name must be category + highest material name, description == highest material description*/);
    ~Craft() = default;

    virtual int getCost() const override;
    // virtual short int getQualidade() const;

   private:
    static const std::vector<std::string> categories;
    EnumCraftCategory category;

    float getCategoryModifier() const;
};
}  // namespace ember

#endif  // CRAFT_HPP
