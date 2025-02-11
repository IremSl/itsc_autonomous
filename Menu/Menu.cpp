#include "Menu.hpp"
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

Menu::Menu() {}

void User::setGender(char genderInput) {
    if (genderInput == 'M' || genderInput == 'm') {
        genderToUse = Gender::Mr;
    } else if (genderInput == 'F' || genderInput == 'f') {
        genderToUse = Gender::Mrs;
    }
}

void User::printGender() const {
    cout << "Gender: " << (genderToUse == Gender::Mr ? "Mr" : "Mrs") << endl;
}

void Menu::loadFromJSON(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open menu file!" << endl;
        return;
    }

    json j;
    file >> j;

    auto loadCategory = [&](const string& categoryName) {
        vector<MenuItem> categoryItems;
        for (const auto& item : j[categoryName]) {
            categoryItems.push_back({
                item["name"],
                item["price"],
                {item["taste_balance"]["sweet"], item["taste_balance"]["sour"],
                 item["taste_balance"]["bitter"], item["taste_balance"]["salty"],
                 item["taste_balance"]["savory"]}
            });
        }
        categories[categoryName] = categoryItems;
    };

    loadCategory("starters");
    loadCategory("salads");
    loadCategory("main_courses");
    loadCategory("drinks");
    loadCategory("appetizers");
    loadCategory("desserts");
}

   void Menu::displayMenu() const {
      cout << "Menu Categories:\n";
      cout << "1. Starters\n";
      cout << "2. Salads\n";
      cout << "3. Main Courses\n";
      cout << "4. Drinks\n";
      cout << "5. Appetizers\n";
      cout << "6. Desserts\n";
}

void Menu::displayCategory(const string& category) const {
    if (categories.find(category) != categories.end()) {
        cout << category << ":\n";
        for (size_t i = 0; i < categories.at(category).size(); ++i) {
           const MenuItem& item = categories.at(category)[i];
            cout << i + 1 << ". " << item.name << " - $" << item.price << "\n";
            displayTasteBalance(item.taste_balance);
        
        
        }
    } else {
        cout << "Invalid category!\n";
    }
}
void Menu::displayTasteBalance(const TasteBalance& balance) const{

 cout << "Taste Balance: "
         << "Sweet: " << balance.sweet << ", "
         << "Sour: " << balance.sour << ", "
         << "Bitter: " << balance.bitter << ", "
         << "Salty: " << balance.salty << ", "
         << "Savory: " << balance.savory << endl;
}





void Menu::addItemToCustomMenu(const MenuItem& item) {
    customMenu.push_back(item);
}


double Menu::getTotalPrice() const {
    double total = 0.0;
    for (const auto& item : customMenu) {
        total += item.price;

    }
    return total;
}


void Menu::showCustomMenu() const {
    cout << "Your Menu:\n";
    if (customMenu.empty()) {
        cout << "Your menu is empty.\n";
    } else {
           
       double totalPrice = getTotalPrice(); 

        for (const auto& item : customMenu) {
            cout << "- " << item.name << " | Price: $" << item.price;
           

            if (item.tempType != TempType::None) {
                cout << " | Served: " << (item.tempType == TempType::Hot ? "Hot" : "Cold");
            }

           if (item.appetizerType != AppetizerType::None) {
                cout << " | Serving Order: " << (item.appetizerType == AppetizerType::Before ? "Before the main course." : "After the main course. ");
            }
             
           if (item.carbonatedType != CarbonatedType::None) {
                cout << " | Carbonation: " << (item.carbonatedType == CarbonatedType::Carbonated ? "Carbonated" : "Non-Carbonated");
            }
            
            if (item.alcoholType != AlcoholType::None) {
                cout << " | Additional Alcohol: " << (item.alcoholType == AlcoholType::WithAlcohol ? "With Extra Shot Alcohol" : "Without Extra Shot  Alcohol");
            }

            if (item.chocolateType != ChocolateType::None) {
                cout << " | Additional Chocolate: " << (item.chocolateType == ChocolateType::WithChocolate? "With Extra Chocolate" : "Without Extra Chocolate");
            }

           item.displayToppings();
            
            cout << "\n";
            displayTasteBalance(item.getTasteBalance());
            cout << endl;

        }

            cout << "Total Price: $" << getTotalPrice() << endl;


    }
}

void Menu::selectItemFromMenu(const string& category, int itemIndex) {
    if (categories.find(category) != categories.end() && itemIndex > 0 && itemIndex <= (int)categories[category].size()) {
        addItemToCustomMenu(categories[category][itemIndex - 1]);
        cout << "Item added to your menu.\n";
    } else {
        cout << "Invalid selection.\n";
    }
}



void Menu::addTempType(const string& category, int itemIndex, TempType tempType) {
    if (categories.find(category) != categories.end() && itemIndex > 0 && itemIndex <= (int)categories[category].size()) {
        categories[category][itemIndex - 1].tempType = tempType;
       
        cout << "Temperature selected.\n";
    } else {
        cout << "Invalid selection.\n";
    }
}



vector<MenuItem> Menu::getItemsFromCategory(const string& category) {
    if (categories.find(category) != categories.end()) {
        return categories[category];  
    } else {
        cout << "Invalid category!\n";
        return {};  
    }
}


void Menu::addAppetizerType(const string& category, int itemIndex, AppetizerType appetizerType) {
    if (categories.find(category) != categories.end() && itemIndex > 0 && itemIndex <= (int)categories[category].size()) {
        categories[category][itemIndex - 1].appetizerType = appetizerType;
        cout << "Serving order selected.\n";
    } else {
        cout << "Invalid selection.\n";
    }
}


void Menu::addCarbonatedType(const string& category, int itemIndex, CarbonatedType carbonatedType) {
    if (categories.find(category) != categories.end() && itemIndex > 0 && itemIndex <= (int)categories[category].size()) {
        categories[category][itemIndex - 1].carbonatedType = carbonatedType;
        cout << "Carbonation selected.\n";
    } else {
        cout << "Invalid selection.\n";
    }
}


void Menu::addAlcoholType(const string& category, int itemIndex, AlcoholType alcoholType) {
    if (categories.find(category) != categories.end() && itemIndex > 0 && itemIndex <= (int)categories[category].size()) {
        categories[category][itemIndex - 1].setAlcoholType(alcoholType);
        cout << "Additional alcohol selected.\n";

    } else {
        cout << "Invalid selection.\n";
    }
}


void Menu::addChocolateType(const string& category, int itemIndex, ChocolateType chocolateType) {
    if (categories.find(category) != categories.end() && itemIndex > 0 && itemIndex <= (int)categories[category].size()) {
        categories[category][itemIndex - 1].setChocolateType(chocolateType);
        cout << "Additional chocolate selected.\n";
    } else {
        cout << "Invalid selection.\n";
    }
}


void Menu::generateRandomCustomMenu() {
    srand(time(0)); 

    customMenu.clear();

    for (const auto& category : categories) {
        if (!category.second.empty()) {  
            int randomIndex = rand() % category.second.size();  
            addItemToCustomMenu(category.second[randomIndex]);  
        }
    }

    cout << "A random menu has been generated!\n";
    showCustomMenu();  
}

void Menu::createCustomMenuByTasteBalance(const TasteBalance& userBalance) {
    customMenu.clear(); 
   
    for (const auto& categoryPair : categories) {
        const auto& categoryItems = categoryPair.second;


        MenuItem bestMatch = categoryItems[0];
        double minDiff = bestMatch.compareTasteBalance(userBalance);

      
        for (const auto& item : categoryItems) {
            double diff = item.compareTasteBalance(userBalance);
            if (diff < minDiff) {
                minDiff = diff;
                bestMatch = item;
            }
        }

        customMenu.push_back(bestMatch);  
    }

    cout << "Your menu based on the taste balances is ready!\n";
    showCustomMenu();  
}

void Menu::askForTasteBalanceAndCreateMenu() {
    TasteBalance userBalance;

    
    cout << "Enter your desired taste balance (on a scale from 0 to 10):\n";
    cout << "Sweet: "; cin >> userBalance.sweet;
    cout << "Sour: "; cin >> userBalance.sour;
    cout << "Bitter: "; cin >> userBalance.bitter;
    cout << "Salty: "; cin >> userBalance.salty;
    cout << "Savory: "; cin >> userBalance.savory;

   
    createCustomMenuByTasteBalance(userBalance);
}



void Menu::removeItemFromCustomMenu() {
    if (customMenu.empty()) {
        cout << "Your menu is empty.\n";
        return;
    }

    cout << "Your menu:\n";
    for (size_t i = 0; i < customMenu.size(); ++i) {
        cout << i + 1 << ". " << customMenu[i].name << " | Price: $" << customMenu[i].price << endl;
    }

    cout << "Enter the index of the item you want to remove: ";
    int itemIndex;
    cin >> itemIndex;

    if (itemIndex > 0 && itemIndex <= (int)customMenu.size()) {
        customMenu.erase(customMenu.begin() + itemIndex - 1);
        cout << "Item removed from your menu.\n";
    } else {
        cout << "Invalid selection.\n";
    }
}
