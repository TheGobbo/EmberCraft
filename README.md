# EmberCraft

- [ ] create WareHouse screen to display current Smithy balance, Items and materials, here you can list or destroy them;

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



MVC:
    M (chama func the materiais, banco, items, etc)
    V (mostra as opcoes acima dependendo do estado)
    C (valida opcao escolhida para estado corrente)

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

- [x] Access modifiers public/private
- [x] Constructors
- [ ] Dynamic allocation with new/delete
- [x] This, references, and asserts
- [ ] Standard Template Library (STL)
- [x] Forward declarations & friendship
- [x] Static members
- [ ] Destructors
- [x] Const
- [x] Parametric polymorphism <T>
- [ ] Inheritance
- [ ] Virtual functions
- [x] Namespaces

---

# Chalk Styles

| Modifiers    | Colors       | Backgrounds    |
|--------------|--------------|----------------|
| bold         | black        | bgBlack        |
| dim          | red          | bgRed          |
| italic       | green        | bgGreen        |
| underline    | yellow       | bgYellow       |
| overline     | blue         | bgBlue         |
| blink        | magenta      | bgMagenta      |
| inverse      | cyan         | bgCyan         |
| hidden       | white        | bgWhite        |
| strike       | blackBright  | bgBlackBright  |
|doubleOverline| grey         | bgGrey         |
| addStyle     | gray         | bgGray         |
| normal       | redBright    | bgRedBright    |
| notItalic    | greenBright  | bgGreenBright  |
| notOverline  | yellowBright | bgYellowBright |
| notUnderline | blueBright   | bgBlueBright   |
| notBlink     | magentaBright| bgMagentaBright|
| notInverse   | cyanBright   | bgCyanBright   |
| reveal       | whiteBright  | bgWhiteBright  |
| notStrike    | rgb          | bgRgb          |
|              | hex          | bgHex          |
|              | code         | bgCode         |

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
