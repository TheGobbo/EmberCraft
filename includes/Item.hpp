#if !defined(ITEM_HPP)
#define ITEM_HPP

#include <string>

namespace ember {
class Item {
   public:
    Item(const std::string& nome, const std::string& desc, short int qualidade);
    Item();
    ~Item() = default;

    Item& setNome(const std::string& nome);
    Item& setDescricao(const std::string& desc);
    Item& setQualidade(short int qualidade);

    std::string getNome() const;
    std::string getDescricao() const;
    short int getQualidade() const;

    virtual int getCost() const;

   protected:
    std::string nome;
    std::string desc;
    short int qualidade;
};
}  // namespace ember

#endif  // ITEM_HPP
