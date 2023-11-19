#ifndef SMITHY_HPP
#define SMITHY_HPP

#include <string>

namespace ember {
class Smithy {
   public:
    Smithy(/* args */);
    ~Smithy();

    int getCoins() const;
    void addCoins(const int coins);
    bool subtractCoins(const int coins);

   private:
    std::string name;
    int coins;
    int exp;
    int level;

    // has in store both crafts and materials, manages aditions and removals
    // Warehouse stock;
};
}  // namespace ember

#endif  // SMITHY_HPP
