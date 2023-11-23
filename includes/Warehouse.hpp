#ifndef WAREHOUSE_HPP
#define WAREHOUSE_HPP

#include <vector>

#include "Craft.hpp"
#include "Material.hpp"

namespace ember {
class Warehouse {
   public:
    Warehouse(unsigned int default_materials, unsigned int default_crafts);
    Warehouse();
    ~Warehouse();

    void listMaterials() const;
    void listCrafted() const;

    void removeMaterial(size_t index);
    void removeCrafted(const size_t index);

    const Craft& getCrafted(const size_t index) const;
    const Material& getMaterial(const size_t index) const;

    void clearMaterials();
    void clearCrafted();

    void addMaterial(Material* material);
    void addCrafted(Craft* crafted);

   private:
    std::vector<Craft*> crafted;
    std::vector<Material*> materials;
};
}  // namespace ember

#endif  // WAREHOUSE_HPP
