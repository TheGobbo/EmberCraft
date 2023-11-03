#ifndef PLAYER_HPP
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
    int money;
};
}  // namespace ember

#endif