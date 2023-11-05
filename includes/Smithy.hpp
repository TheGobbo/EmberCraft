#ifndef SMITHY_HPP
#define SMITHY_HPP

#include <string>

class Warehouse;

class Smithy {
   public:
    Smithy(/* args */);
    ~Smithy();

   private:
    // Stock -> Items, Materials, Tools, ...
    std::string name;
    int exp;
    int level;
    int coins;
    // has in store both crafts and materials, manages aditions and removals
    // Warehouse stock;
};

Smithy::Smithy(/* args */) {}

Smithy::~Smithy() {}

#endif  // SMITHY_HPP

/*#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>

namespace ember {
class Player {
   public:
    Player();
    ~Player();

    const std::string& getName() const;
    void setName(const std::string& name);

   private:
    std::string name;
    int exp;
    int level;
};
}  // namespace ember

#endif*/