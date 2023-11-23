#include "Warehouse.hpp"

#include <cassert>
#include <iomanip>
#include <iostream>
#include <stdexcept>

#include "Console.hpp"

using namespace ember;

Warehouse::Warehouse(unsigned int default_materials, unsigned int default_crafts) {
    for (unsigned int i = 1; i <= default_materials || i == 0; ++i) {
        this->addMaterial(new Material());
    }

    for (unsigned int i = 1; i <= default_crafts || i == 0; ++i) {
        this->addCrafted(new Craft());
    }
}

Warehouse::Warehouse(/* args */) {}

Warehouse::~Warehouse() {
    this->clearCrafted();
    this->clearMaterials();
}

void Warehouse::removeMaterial(size_t index) {
    if (index > this->materials.size() || index <= 0) {
        throw std::invalid_argument(
            "Index of material from Warehouse is out of range: " +
            std::to_string(index));
    }

    Material* ptr = this->materials.at(index - 1);
    this->materials.erase(this->materials.begin() + index - 1);

    delete ptr;
}

void Warehouse::removeCrafted(const size_t index) {
    if (index > this->crafted.size() || index <= 0) {
        throw std::invalid_argument(
            "Index of crafted from Warehouse is out of range: " +
            std::to_string(index));
    }

    Craft* ptr = this->crafted.at(index - 1);
    this->crafted.erase(this->crafted.begin() + index - 1);

    delete ptr;
}

const Craft& Warehouse::getCrafted(const size_t index) const {
    if (index > this->crafted.size() || index <= 0) {
        throw std::invalid_argument(
            "Index of crafted from Warehouse is out of range: " +
            std::to_string(index));
    }

    return *this->crafted.at(index - 1);
}
const Material& Warehouse::getMaterial(const size_t index) const {
    if (index > this->materials.size() || index <= 0) {
        throw std::invalid_argument(
            "Index of material from Warehouse is out of range: " +
            std::to_string(index));
    }

    return *this->materials.at(index - 1);
}

void Warehouse::clearMaterials() {
    std::vector<Material*>::iterator it;
    Material* ptr;
    for (it = this->materials.begin(); it != this->materials.end();) {
        ptr = *it;
        it = this->materials.erase(it);
        delete ptr;
    }
}

void Warehouse::clearCrafted() {
    std::vector<Craft*>::iterator it;
    Craft* ptr;
    for (it = this->crafted.begin(); it != this->crafted.end();) {
        ptr = *it;
        it = this->crafted.erase(it);
        delete ptr;
    }
}

void Warehouse::addMaterial(Material* material) {
    if (material == nullptr) {
        throw std::invalid_argument("Warehouse received nullptr material");
    }

    this->materials.push_back(material);
}

void Warehouse::addCrafted(Craft* crafted) {
    if (crafted == nullptr) {
        throw std::invalid_argument("Warehouse received nullptr crafted");
    }

    this->crafted.push_back(crafted);
}

// void Warehouse::listMaterials() const { listGeneric(this->materials); }
void Warehouse::listMaterials() const {
    std::cout << "LIST OF MATERIALS:\n";
    int i = 1;
    for (Material* mat : this->materials) {
        std::cout << std::setw(2) << std::setfill(' ') << i << ". ";
        Console::printMarketItem(*mat);
        ++i;
    }
}

// void Warehouse::listCrafted() const { listGeneric(this->crafted);
void Warehouse::listCrafted() const {
    std::cout << "LIST OF CRAFTS:\n";
    int i = 1;
    for (Craft* craft : this->crafted) {
        std::cout << std::setw(2) << std::setfill(' ') << i << ". ";
        Console::printCraft(*craft);
        ++i;
    }
}

int Warehouse::countMythCrafs() const {
    int count = 0;
    for(auto craft : this->crafted){
        count += craft->getQualidade() == 100;
    }
    std::cout << "count myths : " << count << '\n';
    return count;
}
