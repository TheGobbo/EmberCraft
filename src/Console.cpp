#include "Console.hpp"

#include <iomanip>
#include <iostream>
#include <regex>

using namespace ember;

// Display rarity:
// Rarity: d100 for quality
// 100  : Mythical  class
// 99-95: Legendary class
// 94-81: Heroic    class
// 80-61: Magical   class
// 61-01: Ordinary  class

// getCategory getItem getCost

// displayItem displayCraft

/* PRINT */

void Console::printItem(const Item& item) {
    std::cout << displayItem(item) << '\n';
}

void Console::printMarketItem(const Item& item) {
    std::cout << displayMarketItem(item) << '\n';
}

void Console::printCraft(const Craft& craft) {
    std::cout << displayCraft(craft) << '\n';
}

/* DISPLAY */

// Returns an Item with its market Cost together
std::string Console::displayMarketItem(const Item& item) {
    return getItemFormat(item) + getCostFormat(item);
}

// Returns an Item without the Cost
std::string Console::displayItem(const Item& item) {
    return getItemFormat(item);
}

// Returns the craft full information: category, cost, and so on
std::string Console::displayCraft(const Craft& craft) {
    return getCategoryFormat(craft) + getItemFormat(craft) +
           getCostFormat(craft);
}

std::string Console::displayMoney(const int money) {
    color::Chalk money_style = color::Chalk{}.rgb(0, 255, 0).bold().save();

    // return getField("$", 6, std::to_string(money), &money_style);

    std::string result = color::Chalk{}.underline().str("$") + ": ";
    std::ostringstream oss;

    oss << std::left << std::setw(6) << std::setfill(' ') << money;

    result += money_style.str(oss.str());

    return result + " | ";
}

/* FORMAT */

// returns a formated string of an Item, without cost
std::string Console::getItemFormat(const Item& item) {
    int quality = item.getQualidade();

    // clang-format off
    color::Chalk rank_style = (quality == 100)  ? color::Chalk{}.disableClean().bold().rgb(255, 223, 0).save()  // Mythical class
                              : (quality >= 95) ? color::Chalk{}.disableClean().bold().rgb(220, 20, 60).save()  // Legendary class
                              : (quality >= 81) ? color::Chalk{}.disableClean().bold().rgb(255, 0, 255).save()  // Heroic   class
                              : (quality >= 61) ? color::Chalk{}.disableClean().bold().rgb(57, 167, 255).save() // Magical  class
                                                : color::Chalk{}.disableClean().bold().white().save();          // Ordinary class
    // clang-format on

    std::string rank = (quality == 100)  ? "Mythical Class"
                       : (quality >= 95) ? "Legendary Class"
                       : (quality >= 81) ? "Heroic Class"
                       : (quality >= 61) ? "Magical Class"
                                         : "Ordinary Class";

    rank += "  [" + std::to_string(quality) + "]";

    std::string stylized;
    stylized = getField("Name", 35, item.getNome());               // 40
    stylized += getField("Description", 45, item.getDescricao());  // 55
    stylized += getField("Rank", 21, rank, &rank_style);

    return stylized;
}

// returns stylized cost
std::string Console::getCostFormat(const Item& item) {
    color::Chalk cost_style = color::Chalk{}.rgb(0, 255, 0).bold().save();

    return getField("$", 6, std::to_string(item.getCost()), &cost_style);
}

// returns a Craft's category following the Console Format
std::string Console::getCategoryFormat(const Craft& craft) {
    return getField("Craft", 8, craft.getCategory());
}

/* FIELD FORMAT */

std::string Console::getField(const std::string& name, int width,
                              const std::string& content) {
    std::ostringstream oss;

    oss << color::Chalk{}.underline().str(name) << ": " << std::left
        << std::setw(width) << std::setfill(' ')
        << Console::trim(content, width) << " | ";

    return oss.str();
}

std::string Console::getField(const std::string& name, int width,
                              const std::string& content, color::Chalk* style) {
    std::string result = color::Chalk{}.underline().str(name) + ": ";
    std::ostringstream oss;

    oss << std::left << std::setw(width) << std::setfill(' ')
        << Console::trim(content, width);

    if (style != nullptr) {
        result += style->str(oss.str());
    } else {
        result += oss.str();
    }

    return result + " | ";
}

std::string Console::trim(const std::string& text, int maxLength) {
    return (int)text.size() > maxLength ? text.substr(0, maxLength - 3) + "..."
                                        : text;
}