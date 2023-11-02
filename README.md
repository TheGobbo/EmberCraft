# EmberCraft


MENU:
    1. Move to Merchant's Store
    2. Move to Smithy's Workshop
    3. Show Smithy's balance

WORKSHOP
    1. Move to Merchant's Store
    2. Craft New Item
    3. List available materials
    4. Destroy materials

MERCHANT
    1. Move to Smithy's Workshop
    2. See Merchant's offers
    3. Sell Items
    4. Show Smithy's balance

SELL (shows balance)
    a. smithy item a with price X
    b. smithy item b with price Y
    n. Show Smithy's balance
    1. Go back (MERCHANT)

BUY (shows balance)
    a. merchant item a with price X
    b. merchant material b with price Y
    1. Go back (MERCHANT)







Name of the Game: EmberCraft

A structure for a TEXT-BASED smithy game where you craft fantastical items, using software engineering concepts, using the C++ language:

1. Model-View-Controller (MVC) Architecture: The game will have a Model that represents the game world and its objects, a View that displays the game to the user,
   and a Controller that handles user input and updates the game state accordingly.
2. Object-Oriented Design: The game's objects will be represented as classes in C++. Each class will have attributes (data
   members) and methods (functions) that describe the behavior of the object.
3. Data Structures and Algorithms: The game will use data structures such as arrays, linked lists, and trees to store and manipulate objects and information. It
   will also use algorithms to perform tasks such as searching, sorting, and pathfinding.
4. User Interface: The game's user interface (UI) will be TEXT-BASED, with the player entering commands through a keyboard or other input device. The UI will
   display information about the player's inventory, equipment, and current location in the game world.
5. Game Loop: The game loop will handle the basic flow of the game, updating the game state and rendering the UI on each iteration.
6. Storage and Loading: The game will use a storage system to save and load the player's progress, allowing them to pick up where they left off or continue from a
   previous save.
7. Testing and Debugging: The game will be thoroughly tested and debugged to ensure that it is functioning correctly and providing a fun and engaging experience
   for the player.

---

## Possible player locations:

- Workshop
- Merchant

### In the Merchant Location, the possible actions are:

Possible action the player can have:

- Buy Item, Material, Blueprint, Tools, or Rune in the Merchant's inventory
- Sell Item, Material, Blueprint, Tools or Rune in the Smithy's (player) inventory
- Can see all of them, but each one requires a minimum level of the smithy

### In the Workshop Location, the possible actions are:

Possible action the player can have:

- Destroys something listed in the inventory, yields nothing
- Dismantle something listed in the inventory, can yield Material and/or EXP depending on smithy's level

## Relevant Game Objects

- Crafted Items: The product of processing materials with a Tool
- Materials: The ingredients for crafting Items
- Tools: standard tools for crafting items with materials
- Blueprint: Easily reproduce a crafted items recipy
- Runes: Can add Atributes to Items, Tools, Materials and blueprints
- Attributes: Modifiers stacked on top of an Object characteristics, could be quality, durability, etc.

### Possible Attributes

Attributes:

- Holy, Godly, Cursed, Element-Infused, Element-Enchanted, Pure, Purified, Enchanted, Runed, Ancient, Shadowed, Electric, Prismatic, Arcane, Luminous, Venomous, Ethereal, Radiant, Celestial, Abyssal, Enigmatic, Dwarven-Crafted, Elven-Made, Dragonforged, Haunted, Titanic, Volcanic, Oceanic, Thunderstruck, Gilded
- Elements : Fire, Water, Earth, Wind, Spirit

### Possible crafted items category

Category:

- Sword, Shield, Arrow, Axe, Staff, Orb, Wand, Dagger, Hammer, Bow, Spear, Armor, Potion, Scroll, Amulet, Ring, Helm, Gauntlet, Robe, Talisman, Quiver, Cloak, Elixir, Rune, Relic, Chalice, Greaves, Scepter, Horn, Crystal

## Workshop

    - receives list of materials
    - has a list of tools to use
    - can craft new items
    - items crafted will have their materials used removed from the stock
    - new item will be added to the stock
    - Can have a saved blueprint of the sequence of tools used

### Merchant

    - Trades materails (maybe resources like coal too) for coins
    - Trades tools for money
    - Can buy items from the stock at a lower price
    - Items bought need to be removed from the smithy
    - Have a ledger (list) with items it can buy
    - Can 'imagine' possible items for the player to create and sell at a high price
    - Can buy the item that matches the request close enough
    - Needs to remove bought item from the stock

# CODE REQUIREMENTS:

THE PROJECT NEEDS TO UTILIZE THE FOLLOWING FUNCTIONALITY FROM C++11

- [ ] Access modifiers public/private
- [ ] Constructors
- [ ] Dynamic allocation with new/delete
- [ ] This, references, and asserts
- [ ] Standard Template Library (STL)
- [ ] Forward declarations & friendship
- [ ] Static members
- [ ] Destructors
- [ ] Const
- [ ] Parametric polymorphism <T>
- [ ] Inheritance
- [ ] Virtual functions
- [ ] Namespaces

---

Dismantler class

- Dismantles anything
- Can provide source materials
- Can earn exp depending on the quality of the Item and the level of the smithy

- Workshop

Craft blueprint x
Improve blueprint x (N rune stones) (min level Y)
Destroy blueprint x

Improve tool x (M rune stones)
Dismantle tool x
Destroy tool x

Improve material x (N rune stones) (min level Y)
Destroy material x

Improve Item x
Dismantle Item x
Destroy Item x

- Merchant

inspect Merchant inventory
Sell blueprint x
Sell tool x
Sell material x
Sell Item x

-- inventory

1. 2. 3. Item, Description, Quality, Modifiers, Price
         Can sell any item with given probability
         Sells items that match smithy level

Buy number(s):

---

Smithy:

- level (gains exp by crafting/selling/destroying Items)
- Exp
- stock (Items, Materials, Tools)
- Coins
- Runes

Merchant:

- 10 random items based on smithy level
- Can sell Runes from level 3
- Can sell Rune blueprints from level 7
- Buys any item from the smithy

Item (Crafted, Materias, Tools, Runes)

- Name
- Description
- Quality
- Price
- Durability (Material can have 1, which reduces to 0 once used)
- Attribute(s)

Attributes

- Holy, Godly, Cursed, Element-Infused, Element-Enchanted, Pure, Purified, Enchanted, Runed, Ancient, Shadowed, Electric, Prismatic, Arcane, Luminous, Venomous, Ethereal, Radiant, Celestial, Abyssal, Enigmatic, Dwarven-Crafted, Elven-Made, Dragonforged, Haunted, Titanic, Volcanic, Oceanic, Thunderstruck, Gilded
- Elements : Fire, Water, Earth, Wind, Spirit

Category

- Sword, Shield, Arrow, Axe, Staff, Orb, Wand, Dagger, Hammer, Bow, Spear, Armor, Potion, Scroll, Amulet, Ring, Helm, Gauntlet, Robe, Talisman, Quiver, Cloak, Elixir, Rune, Relic, Chalice, Greaves, Scepter, Horn, Crystal

Crafted : Item

- Category
- Description = A (quality) (Category) that boasts the attribute(s) of (Attributes), is imbued with (Enhancements) and is (durability)
- Enhancements (Rune of X, Y, Z)

Material : Item

- Category
- Source (Ore, Mineral, Crystal, Magic, Alchemic, Natural)
- Description
- Enhancements

Tools : Item

- Attributes
- Enhancements

Blueprint

- Category
- Requires level X of smithy
- Requires N,... of material(s) M,...
- Enhancements

Runes

- Modifies an Items (quality/price/Durability/Attribute)
- Unknown rune, could increase quality to legendary, as well as reduce the durability to 1
- Appraised Runes (more $$$) have known modifiers

* Enhancements são herdados, but they are normalized by the smaller enhancement
* Blueprints have oo durability
* Every time a tool is used it decreases its durability by 1
* Runes can be made with magic materials
* Some items are only available after a certain smithy level

---

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

    - Have a ledger (list) with items they request
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
