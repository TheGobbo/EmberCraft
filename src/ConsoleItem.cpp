#include "ConsoleItem.hpp"

#include <iomanip>
#include <iostream>
#include <regex>

using namespace ember;

void ConsoleItem::printItem(const Item& item) {
    std::cout << stylizeItem(item) << '\n';
}

// Rarity: d100 for quality
// 100  : Mythical  class
// 99-95: Legendary class
// 94-81: Heroic    class
// 80-61: Magical   class
// 61-01: Ordinary  class
std::string ConsoleItem::stylizeItem(const Item& item) {
    // clang-format off
    short int quality = item.getQualidade();

    color::Chalk rank_style = (quality == 100)  ? color::Chalk{}.disableClean().bold().rgb(255, 223, 0).save()  // Mythical class
                              : (quality >= 95) ? color::Chalk{}.disableClean().bold().rgb(220, 20, 60).save()  // Legendary class
                              : (quality >= 81) ? color::Chalk{}.disableClean().bold().rgb(255, 0, 255).save()  // Heroic   class
                              : (quality >= 61) ? color::Chalk{}.disableClean().bold().rgb(57, 167, 255).save()  // Magical  class
                                                : color::Chalk{}.disableClean().bold().white().save();          // Ordinary class
    // clang-format on
    color::Chalk cost_style = color::Chalk{}.rgb(0, 255, 0).bold().save();

    std::string rank = (quality == 100)  ? "Mythical Class"
                       : (quality >= 95) ? "Legendary Class"
                       : (quality >= 81) ? "Heroic Class"
                       : (quality >= 61) ? "Magical Class"
                                         : "Ordinary Class";

    rank += "  [" + std::to_string(quality) + "]";

    std::string stylized;
    stylized = getField("Name", 35, item.getNome());
    stylized += getField("Description", 55, item.getDescricao());
    stylized += getField("Rank", 21, rank, &rank_style);
    stylized +=
        getField("Cost", 6, std::to_string(item.getCost()), &cost_style);

    return stylized;
}

std::string ConsoleItem::getField(const std::string& name, short int width,
                                  const std::string& content) {
    std::ostringstream oss;
    oss << color::Chalk{}.underline().str(name) << ": " << std::left
        << std::setw(width) << std::setfill(' ') << content << " | ";

    return oss.str();
}

std::string ConsoleItem::getField(const std::string& name, short int width,
                                  const std::string& content,
                                  color::Chalk* style) {
    std::string result = color::Chalk{}.underline().str(name) + ": ";
    std::ostringstream oss;

    oss << std::left << std::setw(width) << std::setfill(' ') << content;

    if (style != nullptr) {
        result += style->str(oss.str());
    } else {
        result += oss.str();
    }

    return result + " | ";
}
