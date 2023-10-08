# EmberCraft

Systems: Crafting System/Trading System/Naming System

- Each class will show/print their own responsibility
- Text decoration on names of materials and items will be handled 

- `Items` and `Materials` are both derived from the `Product` class.
- The `Product` class will be responsible for decorating names depending on their attributes

- The `Items` class has an extra set of attributes that are simillar to Product, but specify Item type and quality


## Workshop
    - receives list of materials
    - has a list of tools to use
    - can craft new items
    - items crafted will have their materials used removed from the stock
    - new item will be added to the stock
    - Can have a saved blueprint of the sequence of tools used

### Clients
    - Have a ledge (list) with items they request
    - Can 'imagine' possible items for the player to create and sell at a high price 
    - Can buy the item that matches the request close enough
    - Needs to remove bought item from the stock 

### Merchant 
    - Trades materails (maybe resources like coal too) for coins
    - Trades tools for money 
    - Can buy items from the stock at a lower price 
    - Items bought need to be removed 




---

**Who is responsible for managing the materials, items and coins?**
- Manager 
    - Needs to receive a request to remove/add material/items/coins from the stock 
    - Anounce if the operation is a success or not to proceed with flow
    - provides a const list of items/materials for the other party to lookup



REQUIREMENTS:
- [ ] Modificadore de acesso public/private
- [ ] Construtores 
- [ ] Alocação dinâmica com new/delete
- [ ] This, referencias e asserts
- [ ] STL
- [ ] Forward declarations & friendship
- [ ] Membros static 
- [ ] Destrutores
- [ ] Const
- [ ] Polimorfismo paramétrico \<T>
- [ ] Herança
- [ ] Funções virtuais
- [ ] 
