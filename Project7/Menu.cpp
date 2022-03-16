/* Assignment: 3
Author: Guy Shabtay, ID: 209298272*/

#pragma warning(disable: 4996)
#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h" //this class header - no need to others since they will be included in the database header
#include <iostream> //for output / input
#include <string.h>
#include <stdlib.h>
#include <cstring>

using namespace std;





//Main and only public method of this class - run the entire program.
void Menu::mainMenu() {
    bool run = true;//do we want another iteration?
    int option;//the choosen option for the menu.
    while (run) {//while we still want to run:
        printMenuOptions();//print the menu
        cin >> option;//get the user choise
        switch (option) {//act accordingly:
        case MANAGER:
            ManagerMenu();//activate the methods that resposible for it
            break;//end of this iteration
        case CLIENT:
            ClientMenu();//client menu
            break;
        case EXIT: run = false; //we want to stop running.
            cout << "Goodbye!\n";//tell the user goodbye.
            //since DataBase wasn't dynamically allocated, its Dtor will clean everything for us.
            break;
        default: cout << "Wrong option. Please try again!\n"; //not a supported option
        }//end switch

    }//end while(run)
}//end method Menu::mainMenu()


//Main and only public method of this class - run the entire program.
void Menu::ManagerMenu() {
    bool run = true;//do we want another iteration?
    int option;//the choosen option for the menu.
    while (run) {//while we still want to run:
        printManagerOptions();//print the menu
        cin >> option;//get the user choise
        switch (option) {//act accordingly:
        case ADD_ITEM: //if we want to add a new item
            addItem();//activate the methods that resposible for it
            break;//end of this iteration
        case REMOVE_ITEM:
            removeItem();//a private method in menu class that remove item from the database
            break;
        case PRINT_ITEM:
            printItem();//menu private method that print the item
            break;
        case PRINT_ALL_ITEMS:
            printAllItems();//menu private method that print all items
            break;
        case RETURN:  //we want to stop running.

            run = false;//tell the user goodbye.
            //since DataBase wasn't dynamically allocated, its Dtor will clean everything for us.
            break;
        default: cout << "Wrong option. Please try again!\n"; //not a supported option
        }//end switch

    }//end while(run)
}//end method Menu::mainMenu()


//Main and only public method of this class - run the entire program.
void Menu::ClientMenu() {
    bool run = true;//do we want another iteration?
    int option;//the choosen option for the menu.
    while (run) {//while we still want to run:
        printClientOptions();//print the menu
        cin >> option;//get the user choise
        switch (option) {//act accordingly:
        case ADD_BASKET: //if we want to add a new basket
            newProductBasket();//activate the methods that resposible for it
            break;//end of this iteration
        case PRINT_BASKET:
            printBasket();//a private method in menu class that prints basket
            break;
        case PRINT_ALL_BASKETS:
            printAllBaskets();//menu private method that print the database
            break;
        case REMOVE_BASKET:
            removeBasket();//menu private method that remove a basket 
            break;
        case RETURNTOMENU: run = false; //we want to stop running.
            //since DataBase wasn't dynamically allocated, its Dtor will clean everything for us.
            break;
        default: cout << "Wrong option. Please try again!\n"; //not a supported option
        }//end switch

    }//end while(run)
}//end method 

//Main and only public method of this class - run the entire program.
void Menu::BasketMenu() {
    bool run = true;//do we want another iteration?
    int option;//the choosen option for the menu.
    while (run) {//while we still want to run:
        printBasketOptions();//print the menu
        cin >> option;//get the user choise
        switch (option) {//act accordingly:
        case SELECT_PRODUCTS: //if we want to add a new employee
            selectProducts();//adding basket by selecting products
            break;//end of this iteration
        case COPY_EXISTING_BASKET:
            copyBasket();//adding basket by copy another basket
            break;
        case UNION_OF_TWO_BASKETS:
            unionOfTwoBaskets();//adding basket by union Of Two Baskets
            break;
        case INTERSECTION_OF_TWO_BASKETS:
            intersectionOfTwoBaskets();//adding basket by intersection Of Two Baskets
            break;
        case RETURNTOCLIENT: run = false; //we want to stop running.
            //since DataBase wasn't dynamically allocated, its Dtor will clean everything for us.
            break;
        default: cout << "Wrong option. Please try again!\n"; //not a supported option
        }//end switch

    }//end while(run)
}//end method 




//A method that print the menu to screen.
void Menu::printMenuOptions() const {//use the enum so in case of a change we want have to change it.
    cout << "Please choose one of the following options:\n Press\n"
        << "----------------------------------------------------------------------\n"
        << MANAGER << " in order to enter the manager menu." << endl
        << CLIENT << " in order to enter the client menu." << endl
        << EXIT << " in order to to quit the program." << endl
        << "----------------------------------------------------------------------\n";
}//end method Menu::printOptions()

//A method that print the menu to screen.
void Menu::printManagerOptions() const {//use the enum so in case of a change we want have to change it.
    cout << "Please choose one of the following options:\n Press\n"
        << "----------------------------------------------------------------------\n"
        << ADD_ITEM << " in order to add an item to the database." << endl
        << REMOVE_ITEM << " in order to remove an item from the database." << endl
        << PRINT_ITEM << " in order to print an item." << endl
        << PRINT_ALL_ITEMS << " in order to print all the items." << endl
        << RETURN << " in order to return to the main menu." << endl
        << "----------------------------------------------------------------------\n";
}//end method Menu::printOptions()


//A method that print the menu to screen.
void Menu::printClientOptions() const {//use the enum so in case of a change we want have to change it.
    cout << "Please choose one of the following options:\n Press\n"
        << "----------------------------------------------------------------------\n"
        << ADD_BASKET << " in order to add a basket to the database." << endl
        << PRINT_BASKET << " in order to print a basket." << endl
        << PRINT_ALL_BASKETS << " in order to print all the baskets." << endl
        << REMOVE_BASKET << " in order to remove a basket from the database." << endl
        << RETURNTOMENU << " in order to return to the main menu." << endl
        << "----------------------------------------------------------------------\n";
}//end method Menu::printOptions()


//A method that print the menu to screen.
void Menu::printBasketOptions() const {//use the enum so in case of a change we want have to change it.
    cout << "Please choose one of the following options to add a basket:\n Press\n"
        << "----------------------------------------------------------------------\n"
        << SELECT_PRODUCTS << " by selecting products." << endl
        << COPY_EXISTING_BASKET << " by copying exiting basket." << endl
        << UNION_OF_TWO_BASKETS << " by union of two product baskets." << endl
        << INTERSECTION_OF_TWO_BASKETS << " Intersection of two product baskets." << endl
        << RETURNTOCLIENT << " in order to return to the client menu." << endl
        << "----------------------------------------------------------------------\n";
}//end method Menu::printOptions()





//a method to get all the needed data to create a new Client and add it to the Database.

void Menu::addItem()
{
    //variables to keep information in order to create client:
    char input[MAX_STRING_SIZE];
    char janer[MAX_STRING_SIZE];
    char number[MAX_STRING_SIZE];
    char songName[MAX_STRING_SIZE];
    char movieType[MAX_STRING_SIZE];
    int outYear;
    int minAge;
    char c;
    char product[MAX_STRING_SIZE];
    char name[MAX_STRING_SIZE];
    int pages;
    int count;
    int numOfSongs;
    int length;
    int level;
    int flag = 0;




    //let the user know what we need:
    cout << "Please enter all the needed detailed in order to add a new item to the database\n";
    cleanBuffer();
    cin.getline(input, 1000);// input of name
    int i, j;
    Store* item = nullptr;

    for (i = 1, j = 0; input[i] != '>'; i++, j++) //input of the product type
    {
        product[j] = input[i];
    }
    product[j] = '\0';

    if (isEqual(product, "Children Book") || isEqual(product, "Reading Book"))
    {

        for (i += 3, j = 0; input[i] != '>'; i++, j++)
        {
            name[j] = input[i];
        }
        name[j] = '\0';

        for (i += 3, j = 0; input[i] != '>'; i++, j++)//input of the pages
        {
            number[j] = input[i];
            if (number[j] < '0' || number[j] > '9') flag = 1;
        }
        if (flag)
        {
            cout << "wrong pages input!" << endl;
            return;
        }
        number[j] = '\0';
        pages = atoi(number);

        *number = NULL;
        for (i += 3, j = 0; input[i] != '>'; i++, j++)//input of the out year
        {
            number[j] = input[i];
            if (number[j] < '0' || number[j] > '9') flag = 1;
        }
        if (flag)
        {
            cout << "wrong publish year input!" << endl;
            return;
        }
        number[j] = '\0';

        outYear = atoi(number);

        *number = NULL;
        if (isEqual(product, "Children Book"))
        {

            for (i += 3, j = 0; input[i] != '>'; i++, j++)//input of the mun age
            {
                number[j] = input[i];
                if (number[j] < '0' || number[j] > '9') flag = 1;
            }
            if (flag)
            {
                cout << "wrong age input!" << endl;
                return;
            }
            number[j] = '\0';

            minAge = atoi(number);

            *number = NULL;

            item = new KidsBooks(name, pages, outYear, minAge);
            //create the new Client dynamically 

        }

        else if (isEqual(product, "Reading Book"))
        {

            for (i += 3, j = 0; input[i] != '>'; i++, j++)//input of the janer
            {
                janer[j] = input[i];
            }
            janer[j] = '\0';
            item = new ReadingBooks(name, pages, outYear, janer);


        }
    }
    if (isEqual(product, "Music Album"))
    {
        for (i += 3, j = 0; input[i] != '>'; i++, j++)//input of the name
        {
            name[j] = input[i];
        }
        name[j] = '\0';
        for (i += 3, j = 0; input[i] != '>'; i++, j++)
        {
            number[j] = input[i];
            if (number[j] < '0' || number[j] > '9') flag = 1;//input of the out year
        }
        if (flag)
        {
            cout << "wrong publish year input!" << endl;
            return;
        }
        outYear = atoi(number);
        *number = NULL;

        numOfSongs = 1;
        Song** list = new Song * [numOfSongs];//Dynamic memory allocation

        do {

            cin.getline(input, 1000);
            if (input[0] != '<') break;

            for (i = 1, j = 0; input[i] != '>'; i++, j++)//input of the song name
            {
                songName[j] = input[i];
            }
            songName[j] = '\0';
            for (i += 3, j = 0; input[i] != '>'; i++, j++)//input of the song length
            {
                number[j] = input[i];
                if (number[j] < '0' || number[j] > '9') flag = 1;
            }
            if (flag)
            {
                cout << "wrong length input!" << endl;
                return;
            }
            length = atoi(number);
            *number = NULL;
            list[i] = new Song(songName, length);
        } while (input[0] == '<');

        item = new MusicAlbum(name, outYear, list);
    }




    if (isEqual(product, "Movie"))
    {
        for (i += 3, j = 0; input[i] != '>'; i++, j++)//input of the movie type
        {
            movieType[j] = input[i];
        }
        movieType[j] = '\0';
        for (i += 3, j = 0; input[i] != '>'; i++, j++)//input of the name
        {
            name[j] = input[i];
        }
        name[j] = '\0';
        for (i += 3, j = 0; input[i] != '>'; i++, j++)//input of the publish year
        {
            number[j] = input[i];
            if (number[j] < '0' || number[j] > '9') flag = 1;
        }
        if (flag)
        {
            cout << "wrong publish year input!" << endl;
            return;
        }
        outYear = atoi(number);
        *number = NULL;
        for (i += 3, j = 0; input[i] != '>'; i++, j++)//input of the level
        {
            number[j] = input[i];
            if (number[j] < '0' || number[j] > '9') flag = 1;
        }
        if (flag)
        {
            cout << "wrong level input!" << endl;
            return;
        }
        level = atoi(number);
        *number = NULL;


        if (isEqual(movieType, "Action") || isEqual(movieType, "Sci-Fi") || isEqual(movieType, "Thriller"))// its an action movie
        {
            if (isEqual(movieType, "Action"))
            {
                if (level > 0 && level < 6)
                    item = new Action(name, outYear, level);
            }
            else if (isEqual(movieType, "Sci-Fi"))// its a scifi movie
            {
                if (level > 0 && level < 10)
                    item = new SciFi(name, outYear, level);
            }

            else if (isEqual(movieType, "Thriller"))// its a thriller movie
            {
                if (level < 0 && level < 7)
                    item = new Thriller(name, outYear, level);
            }


            if (item == nullptr)
            {
                cout << "Wrong level number! " << endl;
                return;
            }
        }
    }
    if (item == NULL)
        cout << "Wrong product type! " << endl;

    else if (db.isExistsByName(*item) == false)
    {
        db.addItem(*item);//add the new item to the database!
    }
    else
    {
        cout << "Error: Item already exists in the system." << endl;

    }
}//end method Menu::additem()

//input the id and remove the asked item from the database
void Menu::removeItem()
{
    long serialNumber;
    char Id[MAX_STRING_SIZE];
    cout << "Please enter the serial number of the employee you wish to remove\n";
    cin >> serialNumber;//get the id

    bool ifRemoved = db.removeItem(serialNumber);
    if (ifRemoved == false)//if it wasn't a valid id
        cout << " Error: Item with corresponding serial does not exist.\n";//alart the user
    else {
        cout << "You just removed an item !\n";
    }
}//end method Menu::removeItem()

//The method print all the database
void Menu::printAllItems() const
{

    db.print();//print all the data
}//end method Menu::printItem()

//prints the item
void Menu::printItem()
{
    long serialNumber;
    cout << "Please enter the serial number of the item you want to print:\n";
    cin >> serialNumber;//get the id

    bool isExists = db.printItem(serialNumber);
    if (isExists == false)//if the id wasn't valid:
        cout << "No matching item was found\n";//alart the user

}//end method Menu::printitem()
void Menu::cleanBuffer() //cleans the buffer
{
    int c;
    do
    {
        c = getchar();
    } while (c != EOF && c != '\n');//letting the user insert a name with a space
}


bool Menu::isEqual(char* str, const char* other)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)//while thw string isnt over
    {
        if (str[i] != other[i]) //checks if its the same char
            return false;
    }
    if (other[i] != '\0') //confirms that the secins string isnt longer than the first one
        return false;
    //else
    return true;
}


void Menu::newProductBasket() //go to basket menu
{
    BasketMenu();

}
void Menu::printAllBaskets()
{
    cl.print();//print all the data
}
void Menu::selectProducts()
{
    Store* newItem = nullptr;
    Basket* newBasket = nullptr;
    newBasket = new Basket();

    long id;
    int amount, i;
    cout << "Enter product serial and amount:" << endl;
    do {
        cin >> id >> amount;
        if (db.isExists(id) == true) //if it is exists
        {

            for (int i = 0; i < amount; i++) //add the item by the given amount of times
            {
                newItem = db.find(id).clone();

                newBasket->addItem(*newItem);
            }
        }
        else if (id != 0 & amount != 0)
            cout << "Error: Item with corresponding serial does not exist." << endl;
    } while (id != 0 && amount != 0);

    cl.addnewProductBasket(*newBasket); //adds the basket to data base

}
void Menu::copyBasket()
{
    int i;
    Store* newItem = nullptr;
    Basket* newBasket = nullptr;
    newBasket = new Basket();

    long id;
    cout << "Which product basket to copy?" << endl;
    cin >> id;
    if (cl.isExists(id) == true) //if it exists
    {
        for (i = 0; i < cl.find(id).getNumOfItems(); i++) //copy the items from given basket to new basket
        {
            newItem = cl.find(id).getItem(i)->clone();
            newBasket->addItem(*newItem);
        }
        cl.addnewProductBasket(*newBasket);//adding basket
    }
    else
        cout << "Error: Selected product serial number does not exist.";

}
void Menu::printBasket() //prints the baskets
{
    long id;
    cout << "Please enter basket serial Number to print:" << endl;
    cin >> id;
    if (cl.isExists(id) == true) //if exists
    {
        cl.printBasket(id); //print
    }
    else
        cout << "Error: Product basket with corresponding serial does not exist";
}
void Menu::removeBasket()
{
    long id;

    cout << "Please enter the serial number of the basket you wish to remove\n";
    cin >> id;//get the id
    if (cl.isExists(id) == true)//if exists
    {
        cl.removeBasket(id); //remove item
        cout << "You have removed a basket successfully!" << endl;
    }
    else
        cout << "Error: Product basket with corresponding serial does not exist.";
}
void Menu::unionOfTwoBaskets()
{
    int i;
    Store* newItem = nullptr;
    Basket* newBasket = nullptr;
    newBasket = new Basket();
    long id, secondId;
    Store* item;
    cout << "Which product baskets to use?\n";
    cin >> id >> secondId;//get the id
    if (cl.isExists(id) == true && cl.isExists(secondId) == true) //if both exists
    {
        if (cl.find(id).amountOfDifferentItems() >= cl.find(secondId).amountOfDifferentItems()) //if first basket has more different items
        {
            for (i = 0; i < cl.find(id).amountOfDifferentItems() - 1; i++) //runs on the first basket
            {
                if (isEqual(cl.find(id).getItem(i)->getName(), cl.find(id).getItem(i + 1)->getName()) == false)//cheks that the next item is different
                {
                    if (cl.find(id).countAmountOfItem(cl.find(id).getItem(i)->getName()) >= cl.find(secondId).countAmountOfItem(cl.find(id).getItem(i)->getName()))//if first basket has more items
                    {
                        for (int j = 0; j < cl.find(id).countAmountOfItem(cl.find(id).getItem(i)->getName()); j++)
                        {
                            newItem = cl.find(id).getItem(i)->clone();
                            newBasket->addItem(*newItem);//adds item to basket
                        }
                    }
                    else
                    {
                        for (int j = 0; j < cl.find(secondId).countAmountOfItem(cl.find(secondId).getItem(i)->getName()); j++) //doing the last item
                        {
                            newItem = cl.find(secondId).getItem(i)->clone();
                            newBasket->addItem(*newItem);//adds item to basket
                        }
                    }
                }
            }
            if (cl.find(id).countAmountOfItem(cl.find(id).getItem(i)->getName()) >= cl.find(secondId).countAmountOfItem(cl.find(secondId).getItem(i)->getName())) //if amount of secnd is bigger
            {
                for (int j = 0; j < cl.find(id).countAmountOfItem(cl.find(id).getItem(i)->getName()); j++)
                {
                    newItem = cl.find(id).getItem(i)->clone();
                    newBasket->addItem(*newItem);//adds item to basket
                }
            }

        }
        else //now doing ecxactly the same actions but now in case that the second basket has more different items
        {
            for (i = 0; i < cl.find(secondId).amountOfDifferentItems() - 1; i++)
            {
                if (isEqual(cl.find(secondId).getItem(i)->getName(), cl.find(secondId).getItem(i + 1)->getName()) == false)
                {
                    if (cl.find(secondId).countAmountOfItem(cl.find(id).getItem(i)->getName()) >= cl.find(id).countAmountOfItem(cl.find(id).getItem(i)->getName()))
                    {
                        for (int j = 0; j < cl.find(secondId).countAmountOfItem(cl.find(secondId).getItem(i)->getName()); j++)
                        {
                            newItem = cl.find(secondId).getItem(i)->clone();
                            newBasket->addItem(*newItem);//adds item to basket
                        }
                    }
                    else
                    {
                        for (int j = 0; j < cl.find(id).countAmountOfItem(cl.find(id).getItem(i)->getName()); j++)
                        {
                            newItem = cl.find(id).getItem(i)->clone();
                            newBasket->addItem(*newItem);//adds item to basket
                        }
                    }
                }
            }
            if (cl.find(secondId).countAmountOfItem(cl.find(secondId).getItem(i)->getName()) >= cl.find(id).countAmountOfItem(cl.find(id).getItem(i)->getName()))
            {
                for (int j = 0; j < cl.find(secondId).countAmountOfItem(cl.find(secondId).getItem(i)->getName()); j++)
                {
                    newItem = cl.find(secondId).getItem(i)->clone();
                    newBasket->addItem(*newItem);//adds item to basket
                }
            }

        }
        cl.addnewProductBasket(*newBasket); //adding the basket
    }
    else
        cout << "Error: One of the selected product baskets does not exist.";
}
void Menu::intersectionOfTwoBaskets()
{
    int i;
    Store* newItem = nullptr;
    Basket* newBasket = nullptr;
    newBasket = new Basket();
    long id, secondId;
    Store* item;
    cout << "Which product baskets to use?\n";
    cin >> id >> secondId;//get the id
    if (cl.isExists(id) == true && cl.isExists(secondId) == true) // if the noth exixsts
    {
        if (cl.find(id).amountOfDifferentItems() >= cl.find(secondId).amountOfDifferentItems())//if first basket has more different items
        {
            for (i = 0; i < cl.find(id).amountOfDifferentItems() - 1; i++) //runs on the first basket items
            {
                if (isEqual(cl.find(id).getItem(i)->getName(), cl.find(id).getItem(i + 1)->getName()) == false) //confirms that the next item isnt the same
                {
                    if (cl.find(id).countAmountOfItem(cl.find(id).getItem(i)->getName()) >= cl.find(secondId).countAmountOfItem(cl.find(id).getItem(i)->getName())) //if first basket has mre otems
                    {
                        for (int j = 0; j < cl.find(id).countAmountOfItem(cl.find(id).getItem(i)->getName()); j++) //run on the amount of the item
                        {
                            newItem = cl.find(id).getItem(i)->clone();
                            newBasket->addItem(*newItem);//adds item to basket
                        }
                    }
                    else
                    {
                        for (int j = 0; j < cl.find(secondId).countAmountOfItem(cl.find(secondId).getItem(i)->getName()); j++)//else run amount of item in the other basket
                        {
                            newItem = cl.find(secondId).getItem(i)->clone();
                            newBasket->addItem(*newItem);//adds item to basket
                        }
                    }
                }
            }
            if (cl.find(id).countAmountOfItem(cl.find(id).getItem(i)->getName()) >= cl.find(secondId).countAmountOfItem(cl.find(secondId).getItem(i)->getName()))//doing the last one
            {
                for (int j = 0; j < cl.find(id).countAmountOfItem(cl.find(id).getItem(i)->getName()); j++)
                {
                    newItem = cl.find(id).getItem(i)->clone();
                    newBasket->addItem(*newItem);//adds item to basket
                }
            }

        }
    }
}
