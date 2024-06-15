#ifndef DEFINE_menuItem
#define DEFINE_menuItem
#include <iostream>
#include "config.hxx"

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
            float price;
        };
        HOTEL::MENU::FoodItem *createFood();
    }
}
#endif