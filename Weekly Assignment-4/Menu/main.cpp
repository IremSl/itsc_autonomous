 #include <iostream>
#include <fstream>
#include <unistd.h>
#include <memory>
#include "Menu.hpp"

using namespace std;

int main() {
    cout << "Welcome!\nPlease enter your name: ";
    string name;
    getline(cin, name);

    cout << "Please enter your last name: ";
    string lastname;
    cin >> lastname;

    cout << "Please enter your gender (M/F): ";
    char gender;
    cin >> gender;

    User user;

    while (true) {
        if (gender == 'M' || gender == 'm' || gender == 'F' || gender == 'f') {
            user.setGender(gender);
            break;
        } else {
            cout << "Please enter a valid gender (M/F): ";
            cin >> gender;
        }
    }

    user.printGender();
    string genderStr = (gender == 'M' || gender == 'm') ? "Mr" : "Mrs";

  
    cout << "Hello " << genderStr << " " << name << " " << lastname << "!\n";
    sleep(1);

    Menu menu;
    menu.loadFromJSON("menu.json");

    while (true) {
        
        cout << "Please select an option:\n";
        cout << "1. View the menu\n";
        cout << "2. Add an item to your menu\n";
        cout<<"3. Remove an item from your menu \n";
        cout<<"4. Get a menu suggestion\n";
        cout<<"5. Create a Menu based on taste preferences\n";
        cout << "6. Print your menu\n";
        cout << "7. Exit\n";

      int choice;

    while(true){

      cin >> choice;

 if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input! Please enter a valid integer: ";
        } else {
            break; 
        }
    }
      
        if (choice == 1) {
            system("clear");
            menu.displayMenu();
            cout << "Select a category to view: ";
            int categoryChoice;
            cin >> categoryChoice;

            string category;
            switch (categoryChoice) {
                case 1: category = "starters"; break;
                case 2: category = "salads"; break;
                case 3: category = "main_courses"; break;
                case 4: category = "drinks"; break;
                case 5: category = "appetizers"; break;
                case 6: category = "desserts"; break;
                default:
                    cout << "Invalid category selection!\n";
                    continue;
            }
            system("clear");
            sleep(1);
            menu.displayCategory(category);
        }

        else if (choice == 2) {
            system("clear");
            string category;
            int itemIndex;
            cout << "Enter category (starters, salads, main_courses, appetizers, desserts, drinks): ";
            cin >> category;
            sleep(1);
            menu.displayCategory(category);
            cout<< endl;

         if(category=="main_courses"){
         
           cout << "Enter item index: ";
           cin >> itemIndex;

           menu.selectItemFromMenu(category, itemIndex);

         }

         if (category == "starters") {

            cout << "Enter item index: ";
            cin >> itemIndex;
            cout << "Would you like your starter to be served cold or hot ? (cold/hot): ";
            string temp;

            while(true){

              cin >> temp;
                
                  if (temp =="cold"|| temp == "hot"){

                  TempType tempType = (temp == "cold") ? TempType::Cold : TempType::Hot;
                  sleep(1);
                  menu.addTempType(category, itemIndex, tempType);
                  menu.selectItemFromMenu(category, itemIndex);
                  break;

                }

                  else{

                  cout<<"Invalid input."<<endl;
                  cout<<"Please enter 'cold' or 'hot' : ";

                }

            }

         }

          if (category == "salads") {
        
            cout << "Enter item index: ";
            cin >> itemIndex;
            cout << "Would you like to add a topping to your salad ? (Y/N): ";
            char response;

           while(true){

                    cin >> response;

                    if (response == 'Y' || response == 'y') {

                      while(true){
                       cout << "Available toppings: cheese, avocado, nuts, beans, chickpea\n";
                       cout << "Enter the topping name: ";
                       string topping;
                       cin >> topping;
                       sleep(1);
            
                    if(topping== "cheese" || topping == "nuts" || topping == "avacado" || topping == "beans" || topping == "chickpea"){

                      vector<MenuItem> items = menu.getItemsFromCategory(category);
                      if (itemIndex > 0 && itemIndex <= (int)items.size()) {

                      MenuItem selectedItem = items[itemIndex - 1]; 
                      selectedItem.addTopping(topping); 
                      selectedItem.price += 2.25;

                     menu.addItemToCustomMenu(selectedItem);

            cout << "Topping '" << topping << "' added to " << selectedItem.getName() << ".\n";

            break;
                
            } 
            
            else {

                 cout << "Invalid selection.\n";

            }

        }

            else {
                  
                sleep(1);
                cout<<"Invalid topping. \n ";
               
            }

        }
            break;

    }

            else if (response == 'n' || response == 'N') {

               menu.selectItemFromMenu(category, itemIndex);
               break;

    }

            else{

               cout<<"Invalid input."<<endl;
               cout<<"Please enter 'Y' or 'N' : " ;
               
            }

       }

    }

             if (category == "drinks") {

               cout << "Enter item index: ";
               cin >> itemIndex;

              char carbonated;

                   do {

                    cout << "Would you like your drink carbonated? (Y/N): ";
                    cin >> carbonated;

                     if (carbonated != 'Y' && carbonated != 'y' && carbonated != 'N' && carbonated != 'n') {
                     cout << "Invalid input! Please enter Y or N." << endl;
              }
                    } while (carbonated != 'Y' && carbonated != 'y' && carbonated != 'N' && carbonated != 'n');
                     
            sleep(1);

             char alcohol;

                   do {

                    cout << "Would you like to have an extra alcohol shot in your drink? (Y/N): ";
                    cin >> alcohol;
                     
                     if (alcohol != 'Y' && alcohol != 'y' && alcohol != 'N' && alcohol != 'n') {
                     cout << "Invalid input! Please enter Y or N." << endl;
        }

                    } while (alcohol != 'Y' && alcohol != 'y' && alcohol != 'N' && alcohol != 'n');

             sleep(1);

           vector<MenuItem> items = menu.getItemsFromCategory(category);

            if (itemIndex > 0 && itemIndex <= (int)items.size()) {

            MenuItem selectedItem = items[itemIndex - 1];

            CarbonatedType carbonatedType = (carbonated == 'Y' || carbonated == 'y') ? CarbonatedType::Carbonated : CarbonatedType::NonCarbonated;
            menu.addCarbonatedType(category, itemIndex, carbonatedType);

            if (carbonatedType == CarbonatedType::Carbonated) {
             selectedItem.price += 0.5;
         }

           AlcoholType alcoholType = (alcohol == 'Y' || alcohol == 'y') ? AlcoholType::WithAlcohol : AlcoholType::WithoutAlcohol;
           menu.addAlcoholType(category, itemIndex, alcoholType);
    
            if (alcoholType == AlcoholType::WithAlcohol) {
            selectedItem.price += 2.5;
        }

         menu.addItemToCustomMenu(selectedItem);

        sleep(1);

        cout << "Item added to your menu.\n";

    }    

          else {

        cout << "Invalid item index.\n";

    }
}

            if(category=="appetizers"){

            cout << "Enter item index: ";
            cin >> itemIndex;
            cout<<"Would you like your appetizer after or before the main course? (A/B): ";
            char appetizer;

              while(true){

            cin>>appetizer;
               if(appetizer == 'A' || appetizer == 'a' || appetizer == 'B' || appetizer == 'b'){

               AppetizerType appetizerType = (appetizer == 'A' || appetizer == 'a') ? AppetizerType::After : AppetizerType::Before;
               sleep(1);
               menu.addAppetizerType(category, itemIndex, appetizerType);
               menu.selectItemFromMenu(category, itemIndex);
               break;
       }

            else{

             sleep(1);
             cout<<"Invalid input.\n";
             cout<<"Please enter 'A' for after and 'B' for before :" ;
  
       }

    }

 }

            if(category== "desserts"){

            cout << "Enter item index: ";
            cin >> itemIndex;
            cout<<"Would you like to add extra chocolate? (Y/N): ";
            char chocolate;

                 while(true){
                 cin>>chocolate;
                 sleep(1);
            
                    if( chocolate == 'Y' || chocolate == 'y' || chocolate == 'N' || chocolate == 'n' ){

                    ChocolateType chocolateType = (chocolate == 'Y' || chocolate == 'y') ? ChocolateType::WithChocolate : ChocolateType::WithoutChocolate;
                    vector<MenuItem> items = menu.getItemsFromCategory(category);

                       if (itemIndex > 0 && itemIndex <= (int)items.size()) {

                       MenuItem selectedItem = items[itemIndex - 1];
                       menu.addChocolateType(category, itemIndex, chocolateType);  
                       if (chocolateType == ChocolateType::WithChocolate) {
                       selectedItem.price += 1.5;
           
        }
            sleep(1);

             menu.addItemToCustomMenu(selectedItem);

           }

                break;

    }

            else{

            cout<<"Invalid input."<<endl;
            cout<<"Please write 'Y' for additional chocolate and 'N' for no additional chocolate : ";

     }
        }
            }
        
    }

            else if( choice== 3){

                system("clear");
                menu.removeItemFromCustomMenu();

    }
        
            else if (choice == 4) {

            char userChoice;

              do {
               system("clear");
               menu.generateRandomCustomMenu();
               sleep(1);

                  do {
                     cout << "Do you like this menu? (Y/N): ";
                     cin >> userChoice;

                    if (userChoice != 'y' && userChoice != 'Y' && userChoice != 'n' && userChoice != 'N') {
                    cout << "Invalid input! Please enter 'Y' or 'N'." << endl;

            }

                     } while (userChoice != 'y' && userChoice != 'Y' && userChoice != 'n' && userChoice != 'N');

                } while (userChoice == 'n' || userChoice == 'N');

             sleep(1);
}




            else if (choice == 5) {

            system("clear");
            menu.askForTasteBalanceAndCreateMenu();  

        }

           else if (choice == 6) {

           system("clear");
           sleep(1);
           menu.showCustomMenu();

        }

           else if (choice == 7) {

           system("clear");
           cout << "Have a nice day! "<<genderStr << " " << name << " " << lastname << "!\n";
           sleep(2);
           break;

        }

        else {

            cout << "Invalid option! Try again.\n";

        }

    }

     system("clear");
    
     return 0;

}