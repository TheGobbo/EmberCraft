#if !defined(ITEM_HPP)
#define ITEM_HPP

#include <random>
#include <string>

namespace ember {
class Item {
   public:
    Item(const std::string& nome, const std::string& desc, int qualidade);
    Item(const std::string& nome, const std::string& desc);
    Item();

    virtual ~Item() = default;

    virtual void setNome(const std::string& nome);
    virtual void setDescricao(const std::string& desc);
    virtual void setQualidade(int qualidade);

    virtual int getCost() const;

    std::string getNome() const;
    std::string getDescricao() const;
    int getQualidade() const;

    void randomQuality();
    std::string getRandomAttribute(
        const std::vector<std::string>& attributeList);

    static int uniformDice(int max);

   protected:
    std::string nome;
    std::string desc;
    int qualidade;

    static std::mt19937 dice_gen;
};
}  // namespace ember

#endif  // ITEM_HPP
