#include "Menu.h"
#include <iostream>

Menu::Menu() {
    tests = new Tests();
    array = nullptr;
    list = nullptr;
    heap = nullptr;
    tree = nullptr;
}

Menu::~Menu() {
    delete tests;
}

//Funkcja wyœwietlaj¹ca menu g³owne programu
void Menu::showMenu() {
    bool isFinished = false;

    while(!isFinished) {
        std::cout << MAIN_MENU_TEXT <<std::endl;
        std::cout << "Wybierz opcje (cyfra): ";
        char choice;
        std::cin >> choice;

        switch(choice) {
        case '0': isFinished = true; break;
        case '1': {
            showTableMenu();
            break;
        }
        case '2': {
            showListMenu();
            break;
        }
        case '3': {
            showHeapMenu();
            break;
        }
        case '4': {
            showRBTreeMenu();
            break;
        }

        default: std::cout << "Wybor nieprawidlowy!" << std::endl;
    }
    }
    
}

//Funkcja wyœwietlaj¹ca menu odpowiadaj¹ce za tablicê
void Menu::showTableMenu() {
    array = new Array();

    bool isFinished = false;
    while(!isFinished) {
        std::cout << "\n\n====TABLICA====" << std::endl;
        std::cout << STRUCT_MENU_TEXT;
        std::cout << "Wybierz opcje (cyfra): ";
        char choice;
        std::cin >> choice;
        switch(choice) {
            case '0': isFinished = true; break;
            case '1': {
                array->loadFromFile();
                break;
            }
            case '2': {
                std::cout << "\n\nPodaj indeks elementu: ";
                int index;
                std::cin.clear();
                std::cin.ignore();
                std::cin >> index;
                array->removeAtIndex(index);
                break;
            }
            case '3': {
                std::cout << "\n\nPodaj wartosc elementu: ";
                int value;
                std::cin.clear();
                std::cin.ignore();
                std::cin >> value;
                std::cout << "Podaj indeks elementu: ";
                int index;
                std::cin.clear();
                std::cin.ignore();
                std::cin >> index;
                array->addAtIndex(index, value);
                break;
            }
            case '4': {
                std::cout << "\n\nPodaj wartosc szukanego elementu: ";
                int value;
                std::cin.clear();
                std::cin.ignore();
                std::cin >> value;
                if(array->contains(value))
                    std::cout << "Tablica zawiera podany element!" << std::endl;
                else
                    std::cout << "Tablica nie zawiera podanego elementu" << std::endl;
                break;
            }
            case '5': {
                std::cout << "Podaj liczbe elementow: ";
                int size;
                std::cin.clear();
                std::cin.ignore();
                std::cin >> size;
                std::cout << "Podaj zakres liczb (x-x): ";
                int max;
                std::cin.clear();
                std::cin.ignore();
                std::cin >> max;
                array->createRandom(size, max);
                break;
            }
            case '6': {
                std::cout << "\n\n";
                array->print();
                break;
            }
            case '7': {
                tests->startArrayTesting();
                break;
            }
            default: std::cout << "Nieprawidlowa opcja!" << std::endl;
        }
        std::cout << std::endl;
        array->print();
    }
    delete array;
    array = nullptr;
}

//Funkcja wyœwietlaj¹ca menu odpowiadaj¹ce za listê
void Menu::showListMenu() {
list = new List();

    bool isFinished = false;
    while(!isFinished) {
        std::cout << "\n\n====LISTA====" << std::endl;
        std::cout << STRUCT_MENU_TEXT;
        std::cout << "Wybierz opcje (cyfra): ";
        char choice;
        std::cin >> choice;
        switch(choice) {
            case '0': isFinished = true; break;
            case '1': {
                list->loadFromFile();
                break;
            }
            case '2': {
                std::cout << "\n\nPodaj wartosc elementu: ";
                int value;
                std::cin.clear();
                std::cin.ignore();
                std::cin >> value;
                list->remove(value);
                break;
            }
            case '3': {
                std::cout << "\n\nPodaj wartosc elementu: ";
                int value;
                std::cin.clear();
                std::cin.ignore();
                std::cin >> value;
                std::cout << "Podaj indeks elementu: ";
                int index;
                std::cin.clear();
                std::cin.ignore();
                std::cin >> index;
                list->addAtIndex(index, value);
                break;
            }
            case '4': {
                std::cout << "\n\nPodaj wartosc szukanego elementu: ";
                int value;
                std::cin.clear();
                std::cin.ignore();
                std::cin >> value;
                if(list->contains(value))
                    std::cout << "Lista zawiera podany element!" << std::endl;
                else
                    std::cout << "Lista nie zawiera podanego elementu" << std::endl;
                break;
            }
            case '5': {
                std::cout << "Podaj liczbe elementow: ";
                int size;
                std::cin.clear();
                std::cin.ignore();
                std::cin >> size;
                std::cout << "Podaj zakres liczb (x-x): ";
                int max;
                std::cin.clear();
                std::cin.ignore();
                std::cin >> max;
                list->createRandom(size, max);
                break;
            }
            case '6': {
                std::cout << "\n\n";
                list->print();
                break;
            }
            case '7': {
                tests->startListTesting();
                break;
            }
            default: std::cout << "Nieprawidlowa opcja!" << std::endl;
        }
        std::cout << std::endl;
        list->print();
    }
    delete list;
}

//Funkcja wyœwietlaj¹ca menu odpowiadaj¹ce za kopiec binarny
void Menu::showHeapMenu() {
heap = new BinaryHeap();

    bool isFinished = false;
    while(!isFinished) {
        std::cout << "\n\n====KOPIEC BINARNY====" << std::endl;
        std::cout << STRUCT_MENU_TEXT;
        std::cout << "Wybierz opcje (cyfra): ";
        char choice;
        std::cin >> choice;
        switch(choice) {
            case '0': isFinished = true; break;
            case '1': {
                heap->loadFromFile();
                break;
            }
            case '2': {
                std::cout << "\n\nPodaj wartosc elementu: ";
                int value;
                std::cin.clear();
                std::cin.ignore();
                std::cin >> value;
                heap->remove(value);
                break;
            }
            case '3': {
                std::cout << "\n\nPodaj wartosc elementu: ";
                int value;
                std::cin.clear();
                std::cin.ignore();
                std::cin >> value;
                heap->add(value);
                break;
            }
            case '4': {
                std::cout << "\n\nPodaj wartosc szukanego elementu: ";
                int value;
                std::cin.clear();
                std::cin.ignore();
                std::cin >> value;
                if(heap->contains(value))
                    std::cout << "Kopiec zawiera podany element!" << std::endl;
                else
                    std::cout << "Kopiec nie zawiera podanego elementu" << std::endl;
                break;
            }
            case '5': {
                std::cout << "Podaj liczbe elementow (max 30000): ";
                int size;
                std::cin.clear();
                std::cin.ignore();
                std::cin >> size;
                std::cout << "Podaj zakres liczb (x-x): ";
                int max;
                std::cin.clear();
                std::cin.ignore();
                std::cin >> max;
                heap->createRandom(size, max);
                break;
            }
            case '6': {
                std::cout << "\n\n";
                heap->printTree("","",0);
                break;
            }
            case '7': {
                tests->startHeapTesting();
                break;
            }
            default: std::cout << "Nieprawidlowa opcja!" << std::endl;
        }
        std::cout << std::endl;
        heap->printTree("","",0);
    }
    delete heap;
}

//Funkcja wyœwietlaj¹ca menu odpowiadaj¹ce za drzewo czerwono-czarne
void Menu::showRBTreeMenu() {
tree = new RBTree();

    bool isFinished = false;
    while(!isFinished) {
        std::cout << "\n\n====DRZEWO CZERWONO-CZARNE====" << std::endl;
        std::cout << STRUCT_MENU_TEXT;
        std::cout << "Wybierz opcje (cyfra): ";
        char choice;
        std::cin >> choice;
        switch(choice) {
            case '0': isFinished = true; break;
            case '1': {
                tree->loadFromFile();
                break;
            }
            case '2': {
                std::cout << "\n\nPodaj wartosc elementu: ";
                int value;
                std::cin.clear();
                std::cin.ignore();
                std::cin >> value;
                tree->remove(value);
                break;
            }
            case '3': {
                std::cout << "\n\nPodaj wartosc elementu: ";
                int value;
                std::cin.clear();
                std::cin.ignore();
                std::cin >> value;
                tree->add(value);
                break;
            }
            case '4': {
                std::cout << "\n\nPodaj wartosc szukanego elementu: ";
                int value;
                std::cin.clear();
                std::cin.ignore();
                std::cin >> value;
                if(tree->contains(value))
                    std::cout << "Drzewo zawiera podany element!" << std::endl;
                else
                    std::cout << "Drzewo nie zawiera podanego elementu" << std::endl;
                break;
            }
            case '5': {
                std::cout << "Podaj liczbe elementow: ";
                int size;
                std::cin.clear();
                std::cin.ignore();
                std::cin >> size;
                std::cout << "Podaj zakres liczb (x-x): ";
                int max;
                std::cin.clear();
                std::cin.ignore();
                std::cin >> max;
                tree->createRandom(size, max);
                break;
            }
            case '6': {
                std::cout << "\n\n";
                tree->printTree();
                break;
            }
            case '7': {
                tests->startRBTreeTesting();
                break;
            }
            default: std::cout << "Nieprawidlowa opcja!" << std::endl;
        }
        std::cout << std::endl;
        tree->printTree();
    }
    delete tree;
}