# RESTAURANT BOT

---
This project implements a menu management system using C++. The system allows users to view a menu, customize their selection based on preferences, and get recommendations.



## Features


- **Load Menu from JSON:**: Reads menu items from `menu.json`.
- **View the menu**: Displays different menu categories and their items.
- **Custom menu creation**: Users can add items to their custom menu and specify preferences like toppings, temperature, drink carbonation, extra shot alcohol, adn extra chocolate..
- **Remove Items from Custom Menu:**: Allows users to remove items from their custom selection.
- **Random menu generation:**: Generates a menu with random items from each category.
- **Taste-Based Menu Creation:**: Suggests items based on user-defined taste preferences.
- **Total Price Calculation:**: Calculates and displays the total price of the custom menu.
- **Printing custom menu:**: Displays custom menu.

---

## Requirements

- **C++11 or later**
- **nlohmann/json.hpp for JSON parsing**

---

 ## Setup and Compilation

1. Ensure that `menu.json` is in the same directory as the executable.
2. Compile the project using:
 ```bash

g++ main.cpp Menu.cpp -o Menu

   ```
3. Run the program:

```bash

./Menu

   ```
---

## Usage

1. Enter your name, surname, and gender.
2. Choose from the available options:

- [**View the menu**](#view-the-menu)
- [**Add an item to your menu**](#add-an-item-to-your-menu)
  - [starters](#starters)
  - [salads](#salads)
  - [main_courses](#main_courses)
  - [appetizers](#appetizers)
  - [desserts](#desserts)
  - [drinks](#drinks)
- [**Remove an item from your  menu**](#remove-an-item-from-your-menu)
- [**Get a menu suggestion**](#get-a-menu-suggestion)
- [**Create a Menu based on taste preferences**](#create-a-Menu-based-on-taste-preferences)
- [**Print your menu**](#print-your-menu)
- [**Exit**](#exit)

---

### View the menu

Displays all available menu items categorized for easy browsing.

![](https://github.com/user-attachments/assets/113cf485-c647-4cb6-8274-9a77ba6519cf)


### Add an item to your menu,

 Allows you to add a selected item to your custom menu, with options like toppings or drink preferences.

#### starters

Displays the 'Starters' category and prompts you to choose between a hot or cold option before adding your selected item to the custom menu.

#### salads

Displays the 'Salads' category and allows you to choose whether or not to add a topping to your salad. If you decide to add a topping, a list of options will be provided, with an extra topping costing $2.25. Once you've made your selection, the item is added to your custom menu.

#### main_courses

Displays the 'Main Courses' category and allows you to choose your desired meal, including vegetarian options. After making your selection, it is added to your custom menu.

#### appetizers

Displays the 'Appetizers' and asks whether you prefer your appetizer before or after the main course. Based on your choice, it adds the item to your custom menu.

#### desserts

Displays the 'Desserts' and offers the option to add extra chocolate for an additional charge of $1.50. Once the selection is made, the item is added to your custom menu.

#### drinks

Displays the drinks and asks whether you would like your drink carbonated or with an extra shot of alcohol. If you decide on carbonation, the price increases by $1.50, and if you decide on an extra shot of alcohol, the price increases by $2.50. After making your decision, the item is added to your custom menu.

### Remove an item from your  menu

Allows you to remove an item from your custom menu .

### Get a menu suggestion

Generates a random menu by selecting one item from each category.

### Create a Menu based on taste preferences

Customizes a menu by selecting items that match your specified taste balance.

### Print your menu

Displays your custom menu along with the total price.

![](https://github.com/user-attachments/assets/3867ac16-251c-4565-9a72-dbaf8d5ba2a9)


### Exit

Closes the program.

---

## CONTACT

For any issues or questions please reach out to Irem Aslan at iremaslan0420@hotmail.com.
