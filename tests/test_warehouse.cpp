#include <iostream>

#include "Warehouse.hpp"

using namespace ember;

int main() {
    Warehouse a = Warehouse();

    a.listCrafted();
    a.listMaterials();

    Material* mat = new Material();
    a.addMaterial(mat);
    a.listMaterials();

    a.removeMaterial(1);
    a.listMaterials();

    Craft* craft = new Craft();
    a.addCrafted(craft);
    a.listCrafted();

    a.removeCrafted(1);
    a.listCrafted();

    Warehouse w = Warehouse(10, 10);
    w.listMaterials();
    w.listCrafted();

    // w.removeMaterial(0);
    w.removeMaterial(10);
    std::cout << "removed material 10\n";
    w.removeCrafted(10);
    std::cout << "removed crafted 10\n";

    w.listMaterials();
    w.listCrafted();

    w.clearMaterials();
    w.clearCrafted();

    w.listMaterials();
    w.listCrafted();
}