/* Assignment: 3
Author: Guy Shabtay, ID: 209298272*/
#define _CRT_SECURE_NO_WARNINGS
#ifndef __MENU_H__
#define __MENU_H__
#pragma warning(disable: 4996)
#include "manager.h"
#include "client.h"
#include "basket.h"
#include "string.h"
#include <iostream>
#include <cstring>
#define MAX_STRING_SIZE 120//max size of strings in this program.
//main class - provide the main menu for the user to activate and manage the Employess database.
class Menu {
public:
    typedef enum { MANAGER = 1, CLIENT, EXIT } MenuOption;
    //enum of menu options.
    typedef enum { ADD_ITEM = 1, REMOVE_ITEM, PRINT_ITEM, PRINT_ALL_ITEMS, RETURN } ManagerOption;
    //enum of menu options.
    typedef enum { ADD_BASKET = 1, PRINT_BASKET, PRINT_ALL_BASKETS, REMOVE_BASKET, RETURNTOMENU } ClientOption;
    //enum of menu options.
    typedef enum { SELECT_PRODUCTS = 1, COPY_EXISTING_BASKET, UNION_OF_TWO_BASKETS, INTERSECTION_OF_TWO_BASKETS, RETURNTOCLIENT } AddClientOption;
    //enum of menu options.
    void mainMenu();//the methods that run the main menu for this program. Resposible to input / ouput with the user.
    void ManagerMenu();
    void ClientMenu();
    void BasketMenu();
private:
    Manager db;
    Client cl;



    //private menthods:

    void printMenuOptions() const;//print all the menu options to screen.
    void printManagerOptions() const;//print all the menu options to screen.
    void printClientOptions() const;//print all the menu options to screen.
    void printBasketOptions() const;//print all the menu options to screen.
    void addItem();//input all the nessesary data to create a new client and add it to the Data-Base
    void removeItem();//input the id and remove the asked client from the database
    void printAllItems() const;//print the entire database
    void printItem();////prints the matching clients 
    void cleanBuffer();//letting the user insert a name with a space
    void newProductBasket();
    void printAllBaskets();
    void printBasket();
    void removeBasket();
    void selectProducts();
    void copyBasket();
    void unionOfTwoBaskets();
    void intersectionOfTwoBaskets();
    bool isEqual(char* str, const char* other);

};

#endif __MENU_H__


