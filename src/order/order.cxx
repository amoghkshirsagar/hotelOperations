#include <iostream>
#include "order.hxx"
#include "menuItem.hxx"
#include "config.hxx"
#include "menuCard.hxx"

using namespace std;

namespace HOTEL
{
    namespace ORDER
    {
        int ORDER_COUNTER = 0;
        int getNextOrderCounter()
        {
            return HOTEL::ORDER::ORDER_COUNTER++;
        }
        void addItemToOrder(HOTEL::MENUCARD::MenuCard *menuCard)
        {
            int choice, cQty;
            menuCard->printMenuCard();
            cout << "select item :" << endl;
            cin >> choice;
            HOTEL::MENU::FoodItem fItem = menuCard->getMenuItemAtIndex(choice - 1);
            cout << "Quantity :" << endl;
            cin >> cQty;
            OrderItem *orderItem = new OrderItem;
            orderItem->setFoodItemAndQuantity(fItem, cQty);
            OrderContext *orderContext = OrderContext::getInstance();
            Order *order = orderContext->getActiveOrder();
            order->addOrderItemToOrder(*orderItem);
        };
        void Order::addOrderItemToOrder(OrderItem orderItem)
        {
            orderItems.push_back(orderItem);
        };
        Order OrderContext::getOrderByNumber(int orderNum)
        {
            return orders[orderNum];
        }
        Order::Order()
        {
            this->orderNumber = getNextOrderCounter();
        };
        OrderItem &Order::createOrderItem()
        {
            OrderItem *orderItem = new OrderItem;
            this->orderItems.push_back(*orderItem);
            return this->orderItems[this->orderItems.size() - 1];
        };
        void Order::setCustomerName(string cName)
        {
            this->customerName = cName;
        };
        void OrderItem::setFoodItemAndQuantity(HOTEL::MENU::FoodItem item, int qty)
        {
            this->foodItem = item;
            this->quantity = qty;
        };
        void Order::print()
        {
            cout << orderNumber << " | " << customerName << endl;
        }
        OrderContext::OrderContext(){};
        OrderContext *OrderContext::orderContext;
        OrderContext *OrderContext::getInstance()
        {
            if (orderContext == nullptr)
            {
                orderContext = new OrderContext;
            }
            return orderContext;
        }
        void createOrderByName()
        {
            Order *order = new Order;
            OrderContext *orderContext = OrderContext::getInstance();
            string custName;
            cout << "customer name:" << endl;
            cin >> custName;
            order->setCustomerName(custName);
            orderContext->addOrder(*order);
            orderContext->setActiveOrder(order);
        }
        void OrderContext::addOrder(Order order)
        {
            orders.push_back(order);
        }
        OrderItem::OrderItem(){};
        void OrderContext::setActiveOrder(Order *order)
        {
            activeOrder = order;
        }
        Order *OrderContext::getActiveOrder()
        {
            return activeOrder;
        }
        void OrderContext::printOrders()
        {
            for (int i = 0; i < orders.size(); i++)
            {
                cout << "Order Index : " << i << endl;
                orders[i].print();
            }
        }
        void orderChoices(MENUCARD::MenuCard *menuCard, OrderContext *orderContext)
        {
            int inChoice;
            bool cont = true;
            int extChoice;
            bool isEnded = false;
            while (cont)
            {
                system("clear");
                std::cout << endl;
                std::cout << "---------------------------------------------" << endl;
                std::cout << "__               Order Menu                __" << endl;
                std::cout << "---------------------------------------------" << endl;
                std::cout << "1. Create Order" << endl;
                std::cout << "2. Add Items to Order" << endl;
                std::cout << "3. Set Active Order" << endl;
                std::cout << "4. List Orders" << endl;
                std::cout << "0. Exit Order Menu" << endl;
                std::cout << "---------------------------------------------" << endl;
                std::cout << "select choice :" << endl;
                cin >> inChoice;
                switch (inChoice)
                {
                case 1:
                    createOrderByName();
                    break;
                case 2:
                    addItemToOrder(menuCard);
                    // code block
                    break;
                case 3:
                    cout << "delete from vector" << endl;
                    // code block
                    break;
                case 4:
                    orderContext->printOrders();
                    cout << "Press 0 to exit" << endl;
                    cin >> extChoice;
                    while (!isEnded)
                    {
                        if (extChoice == 0)
                        {
                            isEnded = true;
                        }
                    }
                    // code block
                    break;
                case 0:
                    cont = false;
                    // code block
                    break;
                default:
                    // code block
                    break;
                }
            }
        };
    }
}