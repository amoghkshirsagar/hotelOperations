#ifndef DEFINE_order
#define DEFINE_order
#include <iostream>
#include <vector>
#include "menuItem.hxx"
#include "menuCard.hxx"
#include "json.hpp"

using namespace std;

namespace HOTEL
{
    namespace ORDER
    {
        int getNextOrderCounter();
        class OrderItem
        {
        private:
            HOTEL::MENU::FoodItem foodItem;
            int quantity;
            bool served = false;

        public:
            OrderItem();
            void setFoodItemAndQuantity(HOTEL::MENU::FoodItem item, int qty);
            void setServed(bool isServed);
        };
        class Order
        {
        private:
            vector<OrderItem> orderItems;
            string customerName;
            int orderNumber;

        public:
            Order();
            OrderItem &createOrderItem();
            void setCustomerName(string cName);
            void print();
            void addOrderItemToOrder(OrderItem orderItem);
        };
        void createOrderByName();
        void addItemToOrder(HOTEL::MENUCARD::MenuCard *menuCard);
        class OrderContext
        {
        public:
            static OrderContext *getInstance();
            void addOrder(Order order);
            void setActiveOrder(Order *order);
            Order *getActiveOrder();
            Order getOrderByNumber(int orderNum);
            void printOrders();

        private:
            OrderContext();
            static OrderContext *orderContext;
            vector<Order> orders;
            Order *activeOrder;
        };

        void orderChoices(MENUCARD::MenuCard *menuCard, OrderContext *orderContext);
    }
}

#endif