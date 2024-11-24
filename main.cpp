#include "header.h"
int main()
{
    LinkedList store;

    store.addVehicle(new motor("honda", "CB1300", "red and white", 2020, 150, 500, 20));
    store.addVehicle(new car("bmw", "i8", "black", 2020, 180, 1000));
    store.addVehicle(new bicycle("galant", "c12", "red and black", 2020, 40, 30));

    store.displayAll();
    store.sell(1);

    store.rentItem(0, 4);
    store.rentItem(1, 5);
    store.returnItem(0);
    store.returnItem(1);
    store.sell(1);

    store.displayAll();

    return 0;
}
