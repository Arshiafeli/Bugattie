#include "header.h"
#include <iostream>
using namespace std;

////////////////////vheicle///////////////////////
vheicle::vheicle() : factory(""), model(""), color(""), year(0), maxSpeed(0.0) {}

vheicle::vheicle(string factory, string model, string color, int year, double maxSpeed)
    : factory(factory), model(model), color(color), year(year), maxSpeed(maxSpeed) {}

vheicle::~vheicle() {}

void vheicle::sell()
{
    cout << "Selling item" << endl;
}

void vheicle::rent(int)
{
    cout << "Renting item" << endl;
}

void vheicle::returnItem()
{
    cout << "Returning item" << endl;
}

//////////////////////////car///////////////////////////////
car::car() : vheicle(), price(0.0) {}

car::car(string factory, string model, string color, int year, double maxSpeed, double price)
    : vheicle(factory, model, color, year, maxSpeed), price(price) {}

car::~car() {}

void car::driving()
{
    cout << "Maxspeed: 0 - " << maxSpeed << endl;
}

void car::display()
{
    cout << "Car Details:" << endl;
    cout << "Factory: " << factory << ", Model: " << model << ", Color: " << color
         << ", Year: " << year << ", MaxSpeed: " << maxSpeed << " km/h, Price: $" << price << endl;
}

void car::sell()
{
    cout << "Car sold successfully!" << endl;
}

/////////////////////////motor///////////////////////////////////
motor::motor() : vheicle(), price(0.0), dailyCost(0.0), isRented(false) {}

motor::motor(string factory, string model, string color, int year, double maxSpeed, double price, double dailyCost)
    : vheicle(factory, model, color, year, maxSpeed), price(price), dailyCost(dailyCost), isRented(false) {}

motor::~motor() {}

void motor::driving()
{
    cout << "Maxspeed: 0 - " << maxSpeed / 2 << " Be careful " << endl;
}

void motor::display()
{
    cout << "Motorbike Details:" << endl;
    cout << "Factory: " << factory << ", Model: " << model << ", Color: " << color
         << ", Year: " << year << ", MaxSpeed: " << maxSpeed << " km/h, Price: $"
         << price << ", Daily Cost: $" << dailyCost << endl;
}

void motor::sell()
{
    if (!isRented)
    {
        cout << "Motorbike sold successfully!" << endl;
    }
    else
    {
        cout << "Motorbike is on rent" << endl;
    }
}

void motor::rent(int day)
{
    if (!isRented)
    {
        cout << "Motorbike is rented for " << day << " days" << endl;
        cout << "Total cost: $" << day * dailyCost << endl;
        isRented = true;
    }
    else
    {
        cout << "Motorbike was rented before" << endl;
    }
}

void motor::returnItem()
{
    if (isRented)
    {
        cout << "Motorbike is returned" << endl;
        isRented = false;
    }
    else
    {
        cout << "Motorbike was not rented" << endl;
    }
}

////////////////////////////////////bicycle////////////////////////////////
bicycle::bicycle() : vheicle(), dailyCost(0.0), isRented(false) {}

bicycle::bicycle(string factory, string model, string color, int year, double maxSpeed, double dailyCost)
    : vheicle(factory, model, color, year, maxSpeed), dailyCost(dailyCost), isRented(false) {}

bicycle::~bicycle() {}

void bicycle::driving()
{
    cout << "Maxspeed: 0 - " << maxSpeed << " Pedaling" << endl;
}

void bicycle::display()
{
    cout << "Bicycle Details:" << endl;
    cout << "Factory: " << factory << ", Model: " << model << ", Color: " << color
         << ", Year: " << year << ", MaxSpeed: " << maxSpeed << " km/h, Daily Cost: $" << dailyCost << endl;
}

void bicycle::rent(int day)
{
    if (!isRented)
    {
        cout << "Bicycle is rented for " << day << " days" << endl;
        cout << "Total cost: $" << day * dailyCost << endl;
        isRented = true;
    }
    else
    {
        cout << "Bicycle was rented before" << endl;
    }
}

void bicycle::returnItem()
{
    if (isRented)
    {
        cout << "Bicycle was returned" << endl;
        isRented = false;
    }
    else
    {
        cout << "Bicycle was not rented" << endl;
    }
}


node::node(vheicle *vehicle) : item(vehicle), next(nullptr) {}

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList()
{
    node *current = head;
    while (current)
    {
        node *nextNode = current->next;
        delete current->item;
        delete current;
        current = nextNode;
    }
}

void LinkedList::addVehicle(vheicle *vehicle)
{
    node *newNode = new node(vehicle);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

bool LinkedList::sell(int index)
{
    if (index < 0)
    {
        cout << "Invalid index." << endl;
        return false;
    }

    if (head == nullptr)
    {
        cout << "The list is already empty. No item to sell." << endl;
        return false;
    }

    node *temp = head;
    node *prev = nullptr;
    int currentIndex = 0;

    while (temp)
    {
        if (currentIndex == index)
        {
            temp->item->sell();

            if (prev == nullptr)
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            delete temp;
            return true;
        }
        prev = temp;
        temp = temp->next;
        currentIndex++;
    }
    cout << "Index " << index << " is out of bounds." << endl;
    return false;
}

void LinkedList::rentItem(int index, int day)
{
    node *current = head;
    int count = 0;
    while (current)
    {
        if (count == index)
        {
            current->item->rent(day);
            return;
        }
        current = current->next;
        count++;
    }
    cout << "Item not found." << endl;
}

void LinkedList::returnItem(int index)
{
    node *current = head;
    int count = 0;
    while (current)
    {
        if (count == index)
        {
            if (auto m = dynamic_cast<motor *>(current->item))
            {
                m->returnItem();
            }
            else if (auto m = dynamic_cast<bicycle *>(current->item))
            {
                m->returnItem();
            }
            else
            {
                cout << "Item cannot be returned (not a motorcycle or bicycle)." << endl;
            }
            return;
        }
        current = current->next;
        count++;
    }
    cout << "Item not found." << endl;
}

void LinkedList::displayAll()
{
    node *temp = head;
    if (!temp)
    {
        cout << "The list is empty." << endl;
        return;
    }
    while (temp)
    {
        temp->item->display();
        temp = temp->next;
    }
}

void LinkedList::testItem(int index)
{
    node *current = head;
    int count = 0;
    while (current != nullptr)
    {
        if (count == index)
        {
            current->item->driving();
            return;
        }
        current = current->next;
        count++;
    }
    cout << "Item not found." << endl;
}

