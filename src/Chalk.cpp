#include "Chalk.hpp"

#include <deque>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

using namespace color;

// Constructor
Chalk::Chalk() : saved{false} {}

// Copy constructor
Chalk::Chalk(const Chalk& other)
    : saved{other.saved},
      style_stack(other.style_stack),
      text_buffer(other.text_buffer.str()) {}

/* --------------------------------------------------------------------------------
 * COLORS (resets with 39)
 * ------------------------------------------------------------------------------*/

Chalk& Chalk::rgb(int r, int g, int b) {
    this->addStyle(38);
    this->addStyle(2);
    this->addStyle(r);
    this->addStyle(g);
    this->addStyle(b);
    return *this;
}

Chalk& Chalk::rgb(uint32_t rgb) {
    this->addStyle(38);
    this->addStyle(2);
    this->addStyle((rgb >> 24) & 0xFF);
    this->addStyle((rgb >> 16) & 0xFF);
    this->addStyle((rgb >> 8) & 0xFF);
    return *this;
}

Chalk& Chalk::code(int code) {
    this->addStyle(38);
    this->addStyle(5);
    this->addStyle(code);
    return *this;
}

Chalk& Chalk::hex(const std::string& hex) {
    hex2rgb(hex, 38);
    return *this;
}

/* --------------------------------------------------------------------------------
 * BACKGROUNDS (resets with 49)
 * ------------------------------------------------------------------------------*/

Chalk& Chalk::bgRgb(int r, int g, int b) {
    this->addStyle(48);
    this->addStyle(2);
    this->addStyle(r);
    this->addStyle(g);
    this->addStyle(b);
    return *this;
}

Chalk& Chalk::bgHex(const std::string& hex) {
    hex2rgb(hex, 48);
    return *this;
}

Chalk& Chalk::bgCode(int code) {
    this->addStyle(48);
    this->addStyle(5);
    this->addStyle(code);
    return *this;
}

/* --------------------------------------------------------------------------------
 * OPERATORS
 * ------------------------------------------------------------------------------*/

std::ostream& operator<<(std::ostream& os, Chalk& chalk) {
    os << chalk.str();
    chalk.restart();
    return os;
}

// Overloaded operator+ to add a Chalk object to a string (string + Chalk)
std::string operator+(const std::string& str, Chalk& chalk) {
    std::string result = str + chalk.str();
    return result;
}

// // Chalk + string
// template <typename T>
std::string Chalk::operator+(Chalk& other) {
    std::cout << "The problem is here;\n";
    // other.text_buffer << this->str();
    // std::string result = other.str();
    this->text_buffer << other.str();
    std::string result = this->str();
    return result;
}

// Copy assignment operator
Chalk& Chalk::operator=(const Chalk& other) { return *this; }

// conversion to string
Chalk::operator std::string() { return this->str(); }

/* --------------------------------------------------------------------------------
 * FUNCTIONS
 * --------------------------------------------------------------------------------
 */

// saves the given code in a sytles stack
Chalk& Chalk::addStyle(int code) {
    this->style_stack.push_back(code);
    return *this;
}

// build the style format and join with the text arguments
// Base of recursion
std::string Chalk::str() {
    std::string result = this->text_buffer.str();
    this->restart();
    return result;
}

// prevent the erasing of the style in a Chalk variable after printing
Chalk Chalk::save() {
    if (this->saved) return *this;

    this->saved = true;

    // delimits what was saved and what wasn't
    if (this->style_stack.back() != -1) {
        this->style_stack.push_back(-1);
    }
    return *this;
}

// build the style with the current object style stack from bottom to top
std::string Chalk::formatter() const {
    std::deque<int>::const_iterator it, start = this->style_stack.begin();
    it = start;

    std::string style = "\e[";
    for (; it != this->style_stack.end(); ++it) {
        if (this->saved && *it == -1) continue;
        style +=
            (it == start) ? std::to_string(*it) : ";" + std::to_string(*it);
    }

    style += "m";
    return style;
}

// restart the chalk object state without styles nor text in the buffer
// if it is a saved chalk, it removes attributes added to it after the save
void Chalk::restart() {
    this->text_buffer.str("");
    this->text_buffer.clear();
    if (this->saved == false) {
        this->style_stack.clear();
    } else {
        // remove elements that are not saved
        while (!this->style_stack.empty() && this->style_stack.back() != -1) {
            this->style_stack.pop_back();
        }
    }
}

// Base case for recursion (no more arguments to concat)
void Chalk::concat() {}

// Auxiliar function to convert hex to rgb
void Chalk::hex2rgb(const std::string& hex, const int code) {
    // Validate hex string
    // const std::regex pattern("^#([A-Fa-f0-9]{6}|[A-Fa-f0-9]{3})$");
    // if (!std::regex_match(hex, pattern)) {
    //     std::cerr << "Hex syntax differs from hex(\"#FFF\") or
    //     hex(\"#FFFFFF\") : "
    //     << hex << std::endl; exit(-1);
    // }

    // if (code != 38 && code != 48) {
    //     std::cerr << "Invalid code given for hex2rgb, codes are 38(fg) or
    //     48(bg)"
    //     << std::endl; exit(-1);
    // }

    int r, g, b;
    // Define a function to convert a single hex digit to its decimal
    // equivalent
    auto hexToDecimal = [](char hexDigit) -> uint8_t {
        if (hexDigit >= '0' && hexDigit <= '9') {
            return static_cast<uint8_t>(hexDigit - '0');
        } else if (hexDigit >= 'A' && hexDigit <= 'F') {
            return static_cast<uint8_t>(hexDigit - 'A' + 10);
        } else if (hexDigit >= 'a' && hexDigit <= 'f') {
            return static_cast<uint8_t>(hexDigit - 'a' + 10);
        }
        return 0;  // Invalid hex digit
    };

    r = (hexToDecimal(hex[0]) << 4) | hexToDecimal(hex[1]);
    g = (hexToDecimal(hex[2]) << 4) | hexToDecimal(hex[3]);
    b = (hexToDecimal(hex[4]) << 4) | hexToDecimal(hex[5]);

    // // Extract the red, green, and blue components
    // if (hex.size() == 7) {
    //     std::sscanf(hex.c_str(), "#%02x%02x%02x", &r, &g, &b);

    // } else {
    //     std::sscanf(hex.c_str(), "#%1x%1x%1x", &r, &g, &b);
    //     r *= 17;
    //     g *= 17;
    //     b *= 17;
    // }

    // formats to \e[<gf|bg>;2(rgb);r;g;bm
    this->addStyle(code).addStyle(2).addStyle(r).addStyle(g).addStyle(b);
}