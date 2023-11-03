#ifndef CHALK_HPP
#define CHALK_HPP

#include <deque>
#include <sstream>
#include <string>

// https://en.wikipedia.org/wiki/ANSI_escape_code#8-bit
// https://github.com/fidian/ansi
// https://github.com/chalk/chalk

// Why the templates where implemented in the .hpp :
// https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl

namespace color {
class Chalk {
    friend std::ostream& operator<<(std::ostream& os, Chalk& chalk);
    friend std::string operator+(const std::string& str, Chalk& chalk);

   public:
    Chalk();
    ~Chalk() = default;
    Chalk(const Chalk& other);  // Copy constructor

    Chalk& addStyle(int code);
    Chalk save();
    void restart();

    // foreground

    Chalk& rgb(int r, int g, int b);
    Chalk& rgb(uint32_t rgb);
    Chalk& code(int code);
    Chalk& hex(const std::string& hex);

    // background

    Chalk& bgRgb(int r, int g, int b);
    Chalk& bgHex(const std::string& hex);
    Chalk& bgCode(int code);

    std::string operator+(Chalk& other);
    Chalk& operator=(const Chalk& other);
    operator std::string();

   private:
    bool saved;
    std::deque<int> style_stack;
    std::stringstream text_buffer;

    std::string formatter() const;
    void hex2rgb(const std::string& hex, const int code);

    /* --------------------------------------------------------------------------------
     * BEGIN TEMPLATE IMPLEMENTATIONS
     * ------------------------------------------------------------------------------*/

    // Recursive function to concatenate multiple printint arguments
    template <typename T, typename... Args>
    void concat(T&& arg, Args&&... args) {
        this->text_buffer << this->formatter();
        this->text_buffer << std::forward<T>(arg) << "\e[m";
        concat(std::forward<Args>(args)...);
    }
    void concat();

   public:
    // Add arguments to text_buffer and return the stream as text;
    template <typename... Args>
    std::string str(Args... args) {
        std::ostringstream os;
        concat(args...);
        os << this->str();
        return os.str();
    }
    std::string str();

    // Function to apply styles to text with call to Chalk("text")
    template <typename... Args>
    std::string operator()(Args... args) {
        return this->str(args...);
    }

    template <typename T>
    std::string operator+(T arg) {
        this->text_buffer << arg;
        return this->str();
    }

    /* --------------------------------------------------------------------------------
     * COLORS (resets with 39)
     * ------------------------------------------------------------------------------*/

    template <typename... Args>
    Chalk& fgReset(Args... args) {
        addStyle(39);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& black(Args... args) {
        addStyle(30);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& red(Args... args) {
        addStyle(31);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& green(Args... args) {
        addStyle(32);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& yellow(Args... args) {
        addStyle(33);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& blue(Args... args) {
        addStyle(34);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& magenta(Args... args) {
        addStyle(35);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& cyan(Args... args) {
        addStyle(36);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& white(Args... args) {
        addStyle(37);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& blackBright(Args... args) {
        addStyle(90);
        concat(args...);
        return *this;
    }

    // blackBright alias
    template <typename... Args>
    Chalk& grey(Args... args) {
        return blackBright(args...);
    }

    // blackBright alias
    template <typename... Args>
    Chalk& gray(Args... args) {
        return blackBright(args...);
    }

    template <typename... Args>
    Chalk& redBright(Args... args) {
        addStyle(91);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& greenBright(Args... args) {
        addStyle(92);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& yellowBright(Args... args) {
        addStyle(93);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& blueBright(Args... args) {
        addStyle(94);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& magentaBright(Args... args) {
        addStyle(95);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& cyanBright(Args... args) {
        addStyle(96);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& whiteBright(Args... args) {
        addStyle(97);
        concat(args...);
        return *this;
    }

    /* --------------------------------------------------------------------------------
     * BACKGROUNDS (resets with 49)
     * ------------------------------------------------------------------------------*/

    template <typename... Args>
    Chalk& bgReset(Args... args) {
        addStyle(49);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& bgBlack(Args... args) {
        addStyle(40);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& bgRed(Args... args) {
        addStyle(41);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& bgGreen(Args... args) {
        addStyle(42);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& bgYellow(Args... args) {
        addStyle(43);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& bgBlue(Args... args) {
        addStyle(44);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& bgMagenta(Args... args) {
        addStyle(45);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& bgCyan(Args... args) {
        addStyle(46);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& bgWhite(Args... args) {
        addStyle(47);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& bgBlackBright(Args... args) {
        addStyle(100);
        concat(args...);
        return *this;
    }

    // bgBlackBright alias
    template <typename... Args>
    Chalk& bgGray(Args... args) {
        bgBlackBright(args...);
        return *this;
    }

    // bgBlackBright alias
    template <typename... Args>
    Chalk& bgGrey(Args... args) {
        bgBlackBright(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& bgRedBright(Args... args) {
        addStyle(101);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& bgGreenBright(Args... args) {
        addStyle(102);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& bgYellowBright(Args... args) {
        addStyle(103);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& bgBlueBright(Args... args) {
        addStyle(104);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& bgMagentaBright(Args... args) {
        addStyle(105);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& bgCyanBright(Args... args) {
        addStyle(106);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& bgWhiteBright(Args... args) {
        addStyle(107);
        concat(args...);
        return *this;
    }

    /* --------------------------------------------------------------------------------
     * MODIFIERS
     * ------------------------------------------------------------------------------*/

    template <typename... Args>
    Chalk& bold(Args... args) {
        addStyle(1);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& dim(Args... args) {
        addStyle(2);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& italic(Args... args) {
        addStyle(3);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& underline(Args... args) {
        addStyle(4);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& overline(Args... args) {
        addStyle(53);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& blink(Args... args) {
        addStyle(5);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& inverse(Args... args) {
        addStyle(7);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& hidden(Args... args) {
        addStyle(8);
        concat(args...);
        return *this;
    }

    // strikethrough
    template <typename... Args>
    Chalk& strike(Args... args) {
        addStyle(9);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& doubleUnderline(Args... args) {
        addStyle(21);
        concat(args...);
        return *this;
    }

    // Neither bold nor faint; color changes where intensity is implemented as
    // such.
    template <typename... Args>
    Chalk& normal(Args... args) {
        addStyle(22);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& notItalic(Args... args) {
        addStyle(23);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& notOverline(Args... args) {
        addStyle(55);
        concat(args...);
        return *this;
    }

    // Neither singly nor doubly underlined
    template <typename... Args>
    Chalk& notUnderline(Args... args) {
        addStyle(24);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& notBlink(Args... args) {
        addStyle(25);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& notInverse(Args... args) {
        addStyle(27);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& reveal(Args... args) {
        addStyle(28);
        concat(args...);
        return *this;
    }

    template <typename... Args>
    Chalk& notStrike(Args... args) {
        addStyle(29);
        concat(args...);
        return *this;
    }
};
}  // namespace color

#endif  // CHALK_HPP

/*
                               ⢀⡀
           ⢀⣤⣄⣠⣤  ⣠⣶⣿⣿⣿⣿⣷⣦⣄⡀⢠⣼⣏⡉⠙⢧⡀
          ⢠⣞⠿⠋⢉⠼⢲⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⣖⢄⡈⠒⢄⠱⡀
         ⢠⡿⠁⡠⠞⠁⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⠙⡄ ⢃⢣
        ⢀⡿⢁⠜ ⢠⣾⡿⠿⣿⡟⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣤⣀⠈⠙ ⠈⠪⣆
       ⢠⠟⠡⠊⢀⡴⠋⠁⣠⣿⡟⢇⠈⠙⠛⢿⣿⣿⣿⣿⠿⣿⣿⣿⣿⢢⡀  ⠈⢦
      ⢠⠃   ⠁ ⣤⣿⣿⠋  ⠿⢶⣴⣞⠏⣏⢹⡿⣶⡆⠹⣿⣿⣮⣳    ⢣
     ⢠⠃    ⢠⣾⣿⣿⡏ ⠸ ⡶⣿⣶⠈⡏⠹⡰⣿⡿⠏⠣⣿⡿ ⠘⡄    ⠱⡄
    ⡠⠃     ⡞⣿⣿⣿⠃    ⢉⡥⢬  ⢷⡄   ⣿⠇  ⠱⢄    ⠈⢦⡀
⢀⣀⡠⠊     ⣠⠞ ⠘⡏⣉⠇     ⣠⣛⣀⢀⣘⣦   ⣿     ⠑⣄    ⠑⢄⡀
⠎⢺⡄    ⡰⠊    ⢱⡈⢁     ⣠⠄⣈⣉⡀⠰⣄ ⢸⠏      ⠘⢆    ⢀⣡⠄
 ⢸⡀   ⡰⠁     ⠐⢿⣿     ⠁⢾⡕⠛⣻  ⢀⡞⢦       ⢸⠉⠉⠉⠉⠁   ⠰
  ⠉⠑⠒⡞⠁      ⡠⢴⠏⢆      ⣈⢀⡀ ⢀⣾  ⠱⣄⡴⠚⠲⢤⣀⠤⡇
     ⡗⠒⠒⠉⠐⠯   ⢸  ⠑⢦⣄⣀     ⡠⠊⣸  ⢠⠃   ⡄  ⢸
     ⡟        ⠈⢢⡀  ⠘⡀⠈⠉⠒⠒⠉⣀⢴⠏⠑⠤⣎⡀   ⢱   ⠇
     ⠃          ⠉⠢⠤⣀⡏⠉⠉⠉⠉⠉ ⡸    ⡇   ⠈⣆
                    ⠛      ⠇   ⠸⠁    ⠘⡄
*/