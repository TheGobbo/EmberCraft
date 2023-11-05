#if !defined(MATERIAL_HPP)
#define MATERIAL_HPP

#include <random>
#include <string>
#include <vector>

#include "Item.hpp"

namespace ember {
class Material : public Item {
   public:
    Material(const std::string& base, const std::string& modifier);
    Material();
    ~Material() = default;

    virtual int getCost() const override;
    int getQuantidade() const;

    std::string generateMaterial();
    std::string generateRandomMaterial();

   private:
    int quantidade;

    static const std::vector<std::string> age;
    static const std::vector<std::string> colors;
    static const std::vector<std::string> source;
    static const std::vector<std::string> texture;
    static const std::vector<std::string> element;
    static const std::vector<std::string> process;
    static const std::vector<std::string> historical;
    static const std::vector<std::string> baseMaterials;
    static const std::vector<std::string> modifierMaterials;

    std::string getRandomAttribute(
        const std::vector<std::string>& attributeList, std::mt19937& gen);
};
}  // namespace ember

#endif  // MATERIAL_HPP
