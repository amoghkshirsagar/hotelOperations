#include <iostream>
#include "config.hxx"
#include "menuItem.hxx"
#include "order.hxx"
#include "menuCard.hxx"

using namespace std;
using namespace HOTEL::CONTEXT;
using namespace HOTEL::MENU;
using namespace HOTEL::MENUCARD;
using namespace HOTEL::ORDER;
using namespace HOTEL::ORDER;

int main()
{
    AppContext *appContext = AppContext::getAppContext();
    OrderContext *orderContext = OrderContext::getInstance();
    MenuCard *menuCard = new MenuCard();
    appContext->setMenuCard(menuCard);

    bool isCont = true;
    int inChoice;

    while (isCont)
    {
        system("clear");
        std::cout << endl;
        std::cout << "---------------------------------------------" << endl;
        std::cout << "__              Choose Screen              __" << endl;
        std::cout << "---------------------------------------------" << endl;
        std::cout << "1. Menu Screen" << endl;
        std::cout << "2. Order Screen" << endl;
        std::cout << "0. Exit Menu" << endl;
        std::cout << "---------------------------------------------" << endl;
        std::cout << "select choice :" << endl;

        cin >> inChoice;

        switch (inChoice)
        {
        case 1:
            menuChoices(appContext->getMenuCard());
            // menuChoices(menuCard);
            break;
        case 2:
            orderChoices(appContext->getMenuCard(), orderContext);
            break;
        case 0:
            // code block
            isCont = false;
            break;
        default:
            break;
        }
    }
}