#ifndef MENU_H
#define MENU_H

#include <string>
#include "Array.h"
#include "BinaryHeap.h"
#include "List.h"
#include "RBTree.h"

class Menu {
private:
    const std::string MAIN_MENU_TEXT = "===MENU GLOWNE===\n"
                                        "Wybierz strukture:\n"
                                        "1. Tablica\n"
                                        "2. Lista\n"
                                        "3. Kopiec binarny\n"
                                        "4. Drzewo czerwono-czarne\n"
                                        "0. Wyjscie\n";


    
    const std::string STRUCT_MENU_TEXT = "Wybierz strukture:\n"
                                        "1. Zaladuj z pliku\n"
                                        "2. Usun element\n"
                                        "3. Dodaj element\n"
                                        "4. Znajdz element\n"
                                        "5. Utworz losowo\n"
                                        "6. Wyswietl\n"
                                        "7. Testowanie\n"
                                        "0. Wyjscie\n";

    Array *array;
    List *list;
    BinaryHeap *heap;
    RBTree *tree;


    void showTableMenu();
    void showListMenu();
    void showHeapMenu();
    void showRBTreeMenu();
public:
    Menu();
    ~Menu();

    void showMenu();                                   
};


#endif