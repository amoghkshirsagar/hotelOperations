#ifndef DEFINE_menuCard
#define DEFINE_menuCard
#include <iostream>
#include <vector>
#include "menuItem.hxx"
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

namespace HOTEL
{
    namespace MENUCARD
    {
        class MenuCard
        {
        private:
            vector<HOTEL::MENU::FoodItem> items;

        public:
            MenuCard();
            ~MenuCard();
            void addItem(HOTEL::MENU::FoodItem item);
            vector<HOTEL::MENU::FoodItem> getMenuItems();
            HOTEL::MENU::FoodItem &getMenuItemAtIndex(int index);
            void printMenuCard();
            json getMenuCardAsJson();
            // HOTEL::MENU::FoodItem *getItemByIndex(int index);
            // HOTEL::MENU::FoodItem *getItemByName(string index);
            void deleteItem();
            void deleteMenuItemAtIndex(int index);
            void menuChoices();
        };
        void addItemToMenuCard(MenuCard *menuCard);
        void listMenuCardItems(MenuCard *menuCard);
        void writeMenuCard(HOTEL::MENUCARD::MenuCard *menuCard, std::string name);
    }
}
#endif