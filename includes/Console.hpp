#if !defined(CONSOLE_ITEM_HPP)
#define CONSOLE_ITEM_HPP

#include "Chalk.hpp"
#include "Craft.hpp"
#include "Item.hpp"

namespace ember {
class Console {
   public:
    virtual ~Console() = default;

    static void printItem(const Item& item);
    static void printMarketItem(const Item& item);
    static void printCraft(const Craft& craft);

    static std::string displayItem(const Item& item);
    static std::string displayCraft(const Craft& craft);
    static std::string displayMarketItem(const Item& item);
    static std::string displayMoney(const int cost);

   private:
    static std::string getItemFormat(const Item& item);
    static std::string getCategoryFormat(const Craft& craft);
    static std::string getCostFormat(const Item& item);

    static std::string getField(const std::string& name, int width,
                                const std::string& content,
                                color::Chalk* style);
    static std::string getField(const std::string& name, int width,
                                const std::string& content);
    static std::string trim(const std::string& text, int maxLength);
};
}  // namespace ember

#endif  // CONSOLE_ITEM_HPP
