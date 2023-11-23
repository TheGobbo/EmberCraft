
#ifndef CRAFT_HPP
#define CRAFT_HPP

#include <string>
#include <vector>

#include "Item.hpp"

namespace ember {

class Craft : public Item {
   public:
    using Item::Item;
    Craft();
    Craft(const std::string& material, int qualidade);
    virtual ~Craft() = default;

    void setCategory(size_t index);
    std::string getCategory() const;
    virtual int getCost() const override;

    std::string randomName();
    std::string randomCraft();

   private:
    static const std::vector<std::string> categories;
    uint8_t category_idx = 0;

    float getCategoryModifier() const;

    static const std::vector<std::string> legacy;
    static const std::vector<std::string> style;
    static const std::vector<std::string> enhancement;
    static const std::vector<std::string> material;
    static const std::vector<std::string> alignment;
    static const std::vector<std::string> effect;
    static const std::vector<std::string> origin;
};
}  // namespace ember

#endif  // CRAFT_HPP
