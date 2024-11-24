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

