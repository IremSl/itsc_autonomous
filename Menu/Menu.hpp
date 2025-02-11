 #ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

class User {

public:
    enum class Gender { Mr, Mrs }; 
    Gender genderToUse;

    void setGender(char genderInput);
    void printGender() const;
};

     enum class TempType { Hot, Cold, None };
     enum class AppetizerType { Before, After, None };
     enum class CarbonatedType { Carbonated, NonCarbonated, None };
     enum class AlcoholType { WithAlcohol, WithoutAlcohol, None };
     enum class ChocolateType { WithChocolate, WithoutChocolate, None };

struct TasteBalance {
    int sweet;
    int sour;
    int bitter;
    int salty;
    int savory;
};

class MenuItem {
  
public:
     string name;
     double price;
     TasteBalance taste_balance;
     TempType tempType = TempType::None;
     vector<string> toppings;
     AppetizerType appetizerType = AppetizerType::None;
     CarbonatedType carbonatedType = CarbonatedType::None;
     AlcoholType alcoholType = AlcoholType::None;
     ChocolateType chocolateType = ChocolateType::None;
  
    MenuItem(const string& name, double price, const TasteBalance& taste_balance)

        : name(name), price(price), taste_balance(taste_balance) {} 

    double compareTasteBalance(const TasteBalance& targetBalance) const {
        double diff = 0.0;
        diff += abs(taste_balance.sweet - targetBalance.sweet);
        diff += abs(taste_balance.sour - targetBalance.sour);
        diff += abs(taste_balance.bitter - targetBalance.bitter);
        diff += abs(taste_balance.salty - targetBalance.salty);
        diff += abs(taste_balance.savory - targetBalance.savory);
        return diff;
    }

    string getName() const { return name; }
    double getPrice() const { return price; }
    TasteBalance getTasteBalance() const {return taste_balance;}
    TempType getTempType() const { return tempType; }
    void setTempType(TempType type) { tempType = type; }  
    vector<string> getToppings() const { return toppings; }
    void addTopping(const string& topping) { toppings.push_back(topping); 

    }

     AppetizerType getAppetizerType() const { return appetizerType; }
     void setAppetizerType(AppetizerType type) { appetizerType = type; }
     void displayToppings() const {
        if (!toppings.empty()) {
            cout << " | Toppings: ";
            for (const auto& topping : toppings) {
                cout << topping << " ";
            }
        }
    }

    CarbonatedType getCarbonatedType() const { return carbonatedType; }
    void setCarbonatedType(CarbonatedType type) { carbonatedType = type; }
    AlcoholType getAlcoholType() const { return alcoholType; }
    void setAlcoholType(AlcoholType type) { alcoholType = type; }
    ChocolateType getChocolateType() const { return chocolateType; }
    void setChocolateType(ChocolateType type) { chocolateType = type; }
};

class Menu {

private:
    map<string, vector<MenuItem>> categories;
    vector<MenuItem> customMenu;

public:
    Menu(); 

    void loadFromJSON(const string& menuJson);
    void displayMenu() const;
    void displayCategory(const string& category) const;
    void addItemToCustomMenu(const MenuItem& item);
    void showCustomMenu() const;
    void selectItemFromMenu(const string& category, int itemIndex);
    double getTotalPrice() const;
    

    void addTempType(const string& category, int itemIndex, TempType tempType); 
    vector<MenuItem> getItemsFromCategory(const string& category);
    void displayTasteBalance(const TasteBalance& balance) const;
    void addAppetizerType(const string& category, int itemIndex, AppetizerType appetizerType);
    void addCarbonatedType(const string& category, int itemIndex, CarbonatedType carbonatedType);
    void addAlcoholType(const string& category, int itemIndex, AlcoholType alcoholType);
    void addChocolateType(const string& category, int itemIndex, ChocolateType chocolateType);
    void generateRandomCustomMenu();
    void createCustomMenuByTasteBalance(const TasteBalance& userBalance);
    void removeItemFromCustomMenu(); 
    void askForTasteBalanceAndCreateMenu();

};

#endif
