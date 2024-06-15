#include <iostream>
#include "menuItem.hxx"

using namespace std;

namespace HOTEL
{
    namespace MENU
    {
        FoodItem::FoodItem()
        {
            this->name = "";
            this->type = "";
            this->price = 0;
        }
        void FoodItem::printFood()
        {
            cout << "   " << name << "   " << type << "   " << price << price << endl;
        }

        void FoodItem::deleteFood()
        {
            std::cout << "Menu Food Item:" << endl;
            cout << "   " << name << "   " << type << "   " << price << endl;
        }

        void FoodItem::editFood()
        {
            system("clear");
            std::cout << "Menu Food Item:" << endl;
            cout << "   " << name << "   " << type << "   " << price << endl;
            std::cout << "Name" << endl;
            cin >> this->name;
            std::cout << "Type" << endl;
            cin >> this->type;
            std::cout << "Price" << endl;
            cin >> this->price;
        }

        FoodItem *createFood()
        {
            FoodItem *menuItem = new FoodItem;
            return menuItem;
        }
    }
}