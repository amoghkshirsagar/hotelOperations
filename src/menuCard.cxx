#include <iostream>
#include "menuCard.hxx"
#include "menuItem.hxx"
#include "config.hxx"
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

namespace HOTEL
{
    namespace MENUCARD
    {
        MenuCard::MenuCard()
        {
            cout << "Creating MenuCard...";
        }
        void MenuCard::addItem(HOTEL::MENU::FoodItem item)
        {
            this->items.push_back(item);
        }

        vector<HOTEL::MENU::FoodItem> MenuCard::getMenuItems()
        {
            return this->items;
        }
        HOTEL::MENU::FoodItem &MenuCard::getMenuItemAtIndex(int index)
        {
            return this->items[index];
        }
        void MenuCard::deleteMenuItemAtIndex(int index)
        {
            this->items.erase(std::next(this->items.begin(), index));
        }

        void editItemMenuCard(MenuCard *menuCard)
        {
            int choice;
            menuCard->printMenuCard();
            cout << "select item :" << endl;
            cin >> choice;
            HOTEL::MENU::FoodItem &itemToEdit = menuCard->getMenuItemAtIndex(choice - 1);
            cout << &itemToEdit << " | ";
            itemToEdit.editFood();
        }

        void MenuCard::deleteItem()
        {
            int choice;
            this->printMenuCard();
            cout << "select item :" << endl;
            cin >> choice;
            this->deleteMenuItemAtIndex(choice - 1);
        }

        void MenuCard::printMenuCard()
        {
            for (size_t i = 0; i < this->items.size(); i++)
            {
                cout << (i + 1) << " | " << &(this->items[i]) << " | ";
                this->items[i].printFood();
            }
        }

        json MenuCard::getMenuCardAsJson()
        {
            json menuCardJson = {};
            for (size_t i = 0; i < this->items.size(); i++)
            {
                menuCardJson[i] = {
                    {"name", this->items[i].name},
                    {"type", this->items[i].type},
                    {"price", this->items[i].price}};
            }

            return menuCardJson;
        }

        void listMenuCardItems(MenuCard *menuCard)
        {
            menuCard->printMenuCard();
            int inChoice = 1;
            while (inChoice != 0)
            {
                std::cout << "0. Exit To Menu" << endl;
                cin >> inChoice;
                system("clear");
            }
        }
        void writeMenuCard(HOTEL::MENUCARD::MenuCard *mCard, string name)
        {
            json jMenuCard = mCard->getMenuCardAsJson();
            HOTEL::CONFIG::writeConfig(jMenuCard, name);
        }

        void addItemToMenuCard(MenuCard *menuCard)
        {
            HOTEL::MENU::FoodItem *item = new HOTEL::MENU::FoodItem();
            item->editFood();
            menuCard->addItem(*item);
        }

        void MenuCard::menuChoices()
        {
            bool cont = true;
            int inChoice;
            while (cont)
            {
                system("clear");
                std::cout << endl;
                std::cout << "---------------------------------------------" << endl;
                std::cout << "__               Menu Card                 __" << endl;
                std::cout << "---------------------------------------------" << endl;
                std::cout << "1. add item" << endl;
                std::cout << "2. edit item" << endl;
                std::cout << "3. delete item" << endl;
                std::cout << "4. List Menu" << endl;
                std::cout << "5. Save Menu" << endl;
                std::cout << "0. Exit Menu" << endl;
                std::cout << "---------------------------------------------" << endl;
                std::cout << "select choice :" << endl;
                cin >> inChoice;
                switch (inChoice)
                {
                case 1:
                    addItemToMenuCard(this);
                    break;
                case 2:
                    // code block
                    editItemMenuCard(this);
                    break;
                case 3:
                    // code block
                    this->deleteItem();
                    break;
                case 4:
                    // code block
                    listMenuCardItems(this);
                    break;
                case 5:
                    // code block
                    writeMenuCard(this, "config/menuCard.json");
                    break;
                case 0:
                    // code block
                    cont = false;
                    break;
                default:
                    // code block
                    break;
                }
            }
        }
    }
}
