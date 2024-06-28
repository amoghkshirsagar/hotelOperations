#ifndef DEFINE_menuItem
#define DEFINE_menuItem
#include <iostream>

using namespace std;

namespace HOTEL
{
    namespace MENU
    {
        class FoodItem
        {
        public:
            FoodItem();
            void printFood();
            void editFood();
            void deleteFood();
            bool isInitialized = false;
            string name;
            string type;
            double price;
        };
        HOTEL::MENU::FoodItem *createFood();
    }
}
#endif