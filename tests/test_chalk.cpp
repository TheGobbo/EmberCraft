#include "Chalk.hpp"

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace color;

// void tests();
// void tests2();
// void demo();
// void demo2();
void colorTable();
void colorCodes();
void initStyles();

std::vector<Chalk> modifiers;
std::vector<Chalk> colors;
std::vector<Chalk> brightColors;
std::vector<Chalk> bgColors;
std::vector<Chalk> bgBright;

const std::string modifNames[] = {
    "bold",  "dim",    "italic",  "underline", "doubleUnderline",
    "blink", "hidden", "inverse", "strike",    "overline"};
const std::string colorNames[] = {"black", "red",     "green", "yellow",
                                  "blue",  "magenta", "cyan",  "white"};
const std::string bgColorNames[] = {"(none)",    "bgBlack",  "bgRed",
                                    "bgGreen",   "bgYellow", "bgBlue",
                                    "bgMagenta", "bgCyan",   "bgWhite"};

int main() {
    initStyles();
    colorTable();
    colorCodes();

    return 0;
}

void colorCodes() {
    Chalk chalk;

    std::cout << "\n\n+----------------------+\n";
    std::cout << ">>    COLOR CODES    <<\n";
    std::cout << "+----------------------+\n\n";

    // A formatting function using a lambda inside the outer function
    auto format = [](int number) -> std::string {
        std::ostringstream ss;
        ss << std::internal << std::setw(4) << std::setfill(' ') << number;
        return ss.str() + " ";
    };

    std::cout << "Standard: ";
    int i = 0;
    for (; i < 8; i++) {
        if (i == 7) {
            std::cout << chalk.black().bold().bgCode(i)(format(i));
        } else {
            std::cout << chalk.white().bold().bgCode(i)(format(i));
        }
    }
    std::cout << "\nIntense:  ";
    for (; i < 16; i++) {
        if (i == 8) {
            std::cout << chalk.white().bgCode(i)(format(i));
        } else {
            std::cout << chalk.black().bgCode(i)(format(i));
        }
    }
    std::cout << "\n\n";

    /* GRADIENTS */
    for (int i = 16; i <= 28; i += 6) {
        for (int j = 0; j <= 180; j += 36) {
            for (int code = j + i; code < j + i + 6; ++code) {
                std::cout << chalk.white().bold().bgCode(code)(format(code));
            }
            std::cout << "    ";

            for (int code = j + i + 18; code < j + i + 24; ++code) {
                std::cout << chalk.black().bgCode(code)(format(code));
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    /* GRAYS */

    std::cout << "Grays:    ";

    for (int code = 232; code < 244; ++code) {
        std::cout << chalk.white().bold().bgCode(code)(format(code));
    }

    std::cout << "\n          ";

    for (int code = 244; code < 256; ++code) {
        std::cout << chalk.black().bold().bgCode(code)(format(code));
    }

    std::cout << "\n\n";
}

void colorTable() {
    std::cout << "\n\n+----------------------+\n";
    std::cout << ">>    COLOR TABLE    <<\n";
    std::cout << "+----------------------+\n\n";

    /* List modifier methods */
    for (size_t i = 0; i < modifiers.size(); i++) {
        if (i > 0 && i % 2 == 0) std::cout << '\n';

        std::cout << std::left << std::setw(20) << modifNames[i] + "()";
        std::cout << " : " << std::setfill(' ') << modifiers.at(i)("Sample")
                  << "\t\t";
    }
    std::cout << "\n\n";

    /* Matrix of colors*/

    // column (colors)
    std::cout << std::left << std::setw(12) << std::setfill(' ')
              << "bg \\ addStyle";
    for (const std::string& col : colorNames) {
        std::cout << std::right << std::setw(6) << std::setfill(' ') << col
                  << " ";
    }
    std::cout << std::endl;

    // rows (backgrounds)
    Chalk addStyle, bg;
    Chalk dim = Chalk{}.dim().save();
    Chalk bold = Chalk{}.bold().save();
    for (size_t i = 0; i < bgColors.size(); i++) {
        std::cout << std::left << std::setw(12) << bgColorNames[i] << " "
                  << std::right;
        for (size_t j = 0; j < colors.size(); j++) {
            bg = bgColors.at(i);
            addStyle = colors.at(j);
            // dnbDNB
            std::cout << colors.at(j)(bgColors.at(i)(dim("d")));
            std::cout << colors.at(j)(i == 0 ? "n" : bgColors.at(i)("n"));
            std::cout << colors.at(j)(bgColors.at(i)(bold("b")));
            std::cout << brightColors.at(j)(bgColors.at(i)(dim("D")));
            std::cout << brightColors.at(j)(i == 0 ? "N" : bgColors.at(i)("N"));
            std::cout << brightColors.at(j)(bgColors.at(i)(bold("B"))) << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\nLegend:\n";
    std::cout << "\tNormal addStyle :  d = dim, n = normal, b = bold.\n";
    std::cout << "\tIntense addStyle:  D = Dim, N = normal, B = bold.\n\n";
}

void initStyles() {
    // Style Modifiers
    modifiers.push_back(Chalk().bold().save());
    modifiers.push_back(Chalk().dim().save());
    modifiers.push_back(Chalk().italic().save());
    modifiers.push_back(Chalk().underline().save());
    modifiers.push_back(Chalk().doubleUnderline().save());
    modifiers.push_back(Chalk().blink().save());
    modifiers.push_back(Chalk().hidden().save());
    modifiers.push_back(Chalk().inverse().save());
    modifiers.push_back(Chalk().strike().save());
    modifiers.push_back(Chalk().overline().save());

    // Style Colors
    colors.push_back(Chalk().black().save());
    colors.push_back(Chalk().red().save());
    colors.push_back(Chalk().green().save());
    colors.push_back(Chalk().yellow().save());
    colors.push_back(Chalk().blue().save());
    colors.push_back(Chalk().magenta().save());
    colors.push_back(Chalk().cyan().save());
    colors.push_back(Chalk().white().save());
    // bright
    brightColors.push_back(Chalk().blackBright().save());
    brightColors.push_back(Chalk().redBright().save());
    brightColors.push_back(Chalk().greenBright().save());
    brightColors.push_back(Chalk().yellowBright().save());
    brightColors.push_back(Chalk().blueBright().save());
    brightColors.push_back(Chalk().magentaBright().save());
    brightColors.push_back(Chalk().cyanBright().save());
    brightColors.push_back(Chalk().whiteBright().save());

    // Style Background colors
    bgColors.push_back(Chalk());
    bgColors.push_back(Chalk().bgBlack().save());
    bgColors.push_back(Chalk().bgRed().save());
    bgColors.push_back(Chalk().bgGreen().save());
    bgColors.push_back(Chalk().bgYellow().save());
    bgColors.push_back(Chalk().bgBlue().save());
    bgColors.push_back(Chalk().bgMagenta().save());
    bgColors.push_back(Chalk().bgCyan().save());
    bgColors.push_back(Chalk().bgWhite().save());

    bgBright.push_back(Chalk().bgBlackBright().save());
    // bgBright.push_back(Chalk().bgGray().save());
    // bgBright.push_back(Chalk().bgGrey().save());
    bgBright.push_back(Chalk().bgRedBright().save());
    bgBright.push_back(Chalk().bgGreenBright().save());
    bgBright.push_back(Chalk().bgYellowBright().save());
    bgBright.push_back(Chalk().bgBlueBright().save());
    bgBright.push_back(Chalk().bgMagentaBright().save());
    bgBright.push_back(Chalk().bgCyanBright().save());
    bgBright.push_back(Chalk().bgWhiteBright().save());
}
