#if !defined(ITEM_HPP)
#define ITEM_HPP

#include <string>

namespace ember {
class Item {
   public:
    Item(const std::string& nome, const std::string& desc, short int qualidade,
         int custo);
    ~Item();

   private:
    std::string nome;
    std::string desc;
    short int qualidade;
    int custo;
};

}  // namespace ember

#endif  // ITEM_HPP
