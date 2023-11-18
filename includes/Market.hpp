#if !defined(MARKET_HP)
#define MARKET_HPP

// should be able to add/remove items from the cart ?

#include <chrono>
#include <map>
#include <vector>

#include "Item.hpp"
#include "Material.hpp"
#include "Smithy.hpp"
#include "Warehouse.hpp"

namespace ember {
class Market {
   public:
    Market();
    ~Market();

    void listStore();

    // controller takes care of figuring out the indexes?
    void addToCart(int index);
    void removeFromCart(int index);

    int getCartCost();

    // returns cost of cart
    void finalizeBuy(Warehouse& warehouse, Smithy* smithy);
    void finalizeMaterialSell(Warehouse& warehouse, Smithy* smithy);
    void finalizeCraftSell(Warehouse& warehouse, Smithy* smithy);

    void cancel();

   private:
    std::vector<Material*> store;
    // get the cost of each one, remove them from warehouse
    std::map<Item*, int> cart;
    // last store refresh time
    std::chrono::time_point<std::chrono::steady_clock> last_refresh;

    // how frequently the store updates
    static std::chrono::duration<double> refresh_rate;
    static int store_capacity;

    void depleteStore();
    void stockUpStore();
    void updatesStore();
};

}  // namespace ember

#endif  // MARKET_HPP
