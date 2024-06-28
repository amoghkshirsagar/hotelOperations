#ifndef DEFINE_CONFIG
#define DEFINE_CONFIG
#include <iostream>
#include "json.hpp"
#include <fstream>
#include <vector>
#include "menuCard.hxx"

using json = nlohmann::json;

namespace HOTEL
{

    namespace UTILS
    {
        std::string getPrecisionValue(double value, int dPlaces);
    };
    namespace CONFIG
    {
        json readConfig(std::string name);
        void writeConfig(json config, std::string name);
    };
    namespace CONTEXT
    {
        using namespace HOTEL;
        class AppContext
        {
        private:
            AppContext();
            static AppContext *appContext;
            MENUCARD::MenuCard *menuCard;
            // static HOTEL::ORDER::Order *activeOrder;

        public:
            static AppContext *getAppContext();
            void setMenuCard(HOTEL::MENUCARD::MenuCard *menuCard);
            HOTEL::MENUCARD::MenuCard *getMenuCard();
            // void setActiveOrder(HOTEL::ORDER::Order *order);
            // HOTEL::ORDER::Order *getActiveOrder();
            // void addOrder(HOTEL::ORDER::Order order);
            // void listOrders();
        };
    };
}
#endif