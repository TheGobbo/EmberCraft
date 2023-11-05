#if !defined(CONSOLE_ITEM_HPP)
#define CONSOLE_ITEM_HPP

#include "Chalk.hpp"
#include "Item.hpp"

namespace ember {
class ConsoleItem {
   public:
    virtual ~ConsoleItem() = default;

    static void printItem(const Item& item);
    static std::string stylizeItem(const Item& item);

   private:
    static std::string getField(const std::string& name, short int width,
                                const std::string& content,
                                color::Chalk* style);
    static std::string getField(const std::string& name, short int width,
                                const std::string& content);
};
}  // namespace ember

#endif  // CONSOLE_ITEM_HPP
