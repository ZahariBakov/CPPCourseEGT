#include "Drinks.h"
#include "Alcoholic.h"
#include "NonAlcoholic.h"
#include "Order.h"
#include "User.h"
#include "Shop.h"

int main() {

    Drinks* a1Ptr = new Alcoholic("Jack Daniels", 25.80, 1, "whiskey", 38.5, 3);
    Drinks* a2Ptr = new Alcoholic("Finlandia",    28.90, 2, "vodka",   38.5, 3);
    Drinks* a3Ptr = new Alcoholic("Efes",          2.50, 4, "beer",     4.5, 3);
    Drinks* a4Ptr = new Alcoholic("Jameson",      32.65, 2, "whiskey", 38.0, 3);

    Drinks* na1Ptr = new NonAlcoholic("Lavazza",   1.5, 1, "coffee", 0.10, 0.5);
    Drinks* na2Ptr = new NonAlcoholic("NesTea",    3.5, 3, "tea",    1.50, 0.5);
    Drinks* na3Ptr = new NonAlcoholic("Devin",     1.2, 3, "water",  1.50, 0.5);
    Drinks* na4Ptr = new NonAlcoholic("Coca Cola", 2.5, 2, "cola",   0.33, 0.5);

    std::vector<Drinks*> drinks;
    std::vector<Drinks*> drinks2;
    std::vector<Drinks*> drinks3;
    std::vector<Drinks*> drinks4;

    drinks.push_back(a1Ptr);
    drinks.push_back(na1Ptr);

    drinks2.push_back(a2Ptr);
    drinks2.push_back(na2Ptr);

    drinks3.push_back(a3Ptr);
    drinks3.push_back(na3Ptr);

    drinks4.push_back(a4Ptr);
    drinks4.push_back(na4Ptr);

    Order* o1Ptr = new Order(drinks, "20.01.2024");
    Order* o2Ptr = new Order(drinks2, "22.01.2024");
    Order* o3Ptr = new Order(drinks3, "18.01.2024");
    Order* o4Ptr = new Order(drinks4, "21.01.2024");

    std::vector<Order*> orders;
    orders.push_back(o1Ptr);
    orders.push_back(o2Ptr);

    std::vector<Order*> orders2;
    orders2.push_back(o3Ptr);
    orders2.push_back(o4Ptr);

    User* u1Ptr = new User("Ivan", orders);
    User* u2Ptr = new User("Georgi", orders2);

    std::vector<User*> users;
    users.push_back(u1Ptr);
    users.push_back(u2Ptr);

    Shop s1(users);
    // All sold drinks by type and name
    //s1.soldDrinks();
    
    // Best client spend the most money
    //s1.bestClient();

    // Search by drink type
    //s1.searchByDrinks("whiskey");
    //s1.searchByDrinks("coffee");

    // Search by drink type and over price
    s1.searchByDrinksAndMoney("whiskey", 100);

    return 0;
}
