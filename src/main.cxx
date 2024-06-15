#include <iostream>
#include "menuItem.hxx"
#include "menuCard.hxx"

using namespace std;
using namespace HOTEL::MENU;

int main()
{
    HOTEL::MENUCARD::MenuCard *menuCard = new HOTEL::MENUCARD::MenuCard();
    menuCard->menuChoices();
}