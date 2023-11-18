
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
    virtual ~Craft() = default;

    void setCategory(size_t index);
    std::string getCategory() const;
    virtual int getCost() const override;

   private:
    static const std::vector<std::string> categories;
    uint8_t category_idx = 0;

    float getCategoryModifier() const;
};
}  // namespace ember

#endif  // CRAFT_HPP
