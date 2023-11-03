#if !defined(SMITHY_HPP)
#define SMITHY_HPP

class Smithy {
   public:
    Smithy(/* args */);
    ~Smithy();

   private:
    // Stock -> Items, Materials, Tools, ...
    int coins;
};

Smithy::Smithy(/* args */) {}

Smithy::~Smithy() {}

#endif  // SMITHY_HPP
