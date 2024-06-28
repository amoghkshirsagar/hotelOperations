#ifndef DEFINE_menuCard
#define DEFINE_menuCard
#include <iostream>
#include <vector>
#include "json.hpp"
#include "menuItem.hxx"

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
        };
        void addItemToMenuCard(MenuCard *menuCard);
        void listMenuCardItems(MenuCard *menuCard);
        void writeMenuCard(MenuCard *menuCard, std::string name);
        void menuChoices(MenuCard *menuCard);
    }
}
#endif