#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

using namespace std;

class vheicle
{
protected:
    string factory;
    string model;
    string color;
    int year;
    double maxSpeed;

public:
    vheicle();
    vheicle(string factory, string model, string color, int year, double maxSpeed);
    virtual ~vheicle();

    virtual void driving() = 0;
    virtual void display() = 0;
    virtual void sell();
    virtual void rent(int day);
    virtual void returnItem();
};

class car : virtual public vheicle
{
private:
    double price;

public:
    car();
    car(string factory, string model, string color, int year, double maxSpeed, double price);
    virtual ~car();

    void driving() override;
    void display() override;
    void sell() override;
};

class motor : virtual public vheicle
{
private:
    double price;
    double dailyCost;
    bool isRented;

public:
    motor();
    motor(string factory, string model, string color, int year, double maxSpeed, double price, double dailyCost);
    virtual ~motor();

    void driving() override;
    void display() override;
    void sell() override;
    void rent(int day) override;
    void returnItem() override;
};

class bicycle : virtual public vheicle
{
private:
    double dailyCost;
    bool isRented;

public:
    bicycle();
    bicycle(string factory, string model, string color, int year, double maxSpeed, double dailyCost);
    virtual ~bicycle();

    void driving() override;
    void display() override;
    void rent(int day) override;
    void returnItem() override;
};


class node
{
    friend class LinkedList;

private:
    vheicle *item;
    node *next;

public:
    node(vheicle *vehicle);
};

class LinkedList
{
private:
    node *head;

public:
    LinkedList();
    ~LinkedList();

    void addVehicle(vheicle *vehicle);
    bool sell(int index);
    void rentItem(int index, int day);
    void returnItem(int index);
    void displayAll();
    void testItem(int index);
};

#endif 
 