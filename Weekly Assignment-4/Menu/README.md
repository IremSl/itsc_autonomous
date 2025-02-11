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

### Add an item to your menu,

 Allows you to add a selected item to your custom menu, with options like toppings or drink preferences.
 
### Remove an item from your  menu

Lets you remove an item from your custom menu .

### Get a menu suggestion

Generates a random menu by selecting one item from each category.

### Create a Menu based on taste preferences

Customizes a menu by selecting items that match your specified taste balance.

### Print your menu

Displays your custom menu along with the total price.

### Exit

Closes the program.




### Output of a Smart Pointers Example

![](https://github.com/user-attachments/assets/5b71de0f-1385-4023-8b6c-127bfdaee869)


## CONTACT

For any issues or questions please reach out to Irem Aslan at iremaslan0420@hotmail.com.
