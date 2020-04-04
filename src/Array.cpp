#include "Array.h"
#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <string>


//Konstruktor nowej tablicy (wstępna inicjalizacja)
Array::Array()
{
    array = new int[0];
    size = 0;
}

//Destruktor tablicy (usuniecie z pamieci poszczegolnych elementow)
Array::~Array()
{
    delete[] array;
    array = nullptr;
}

//Dodawanie nowego elementu tablicy na końcu (roszerzenie tablicy i wstawienie elementu)
void Array::pushBack(int value) {
    int* tmpArray = array;
    array = new int[++size];
    for(int iii = 0; iii < size-1; iii++) {
        array[iii] = tmpArray[iii];
    }
    delete[] tmpArray;
    array[size-1] = value;
}

//Usuwanie elementu z końca tablicy (usunięcie elementu i zmniejszenie rozmiaru tablicy)
void Array::popBack() {
    int* tmpArray = array;
    array = new int[--size];
    for(int iii = 0; iii < size; iii++) {
        array[iii] = tmpArray[iii];
    }
    delete[] tmpArray;
}

//Dodawanie nowego elementu tablicy na początku (rozszerzenie tablicy i dodanie elementu)
void Array::pushFront(int value) {
    int* tmpArray = array;
    array = new int[++size];
    array[0] = value;
    for(int iii = 1; iii < size; iii++) {
        array[iii] = tmpArray[iii-1];
    }
    delete[] tmpArray;
}

//Usuwanie elementu z końca tablicy (usunięcie elementu i zmniejszenie rozmiaru tablicy)
void Array::popFront() {
    int* tmpArray = array;
    array = new int[--size];
    for(int iii = 0; iii < size; iii++) {
        array[iii] = tmpArray[iii+1];
    }
    delete[] tmpArray;
}

//Dodawanie nowego elementu na podanym indekse (szukanie wybranego indeksu, rozsuwanie tablicy i wstawianie elementu)
void Array::addAtIndex(int index, int value) {
    if(index < 0 || index > size) {
        std::cout << "Brak podanego indeksu w tablicy" << std::endl; //moze exception?
        return;
    }
    int* tmpArray = array;
    array = new int[++size];
    for(int iii = 0; iii < index; iii++) {
        array[iii] = tmpArray[iii];
    }

    array[index] = value;

    for(int iii = index+1; iii < size; iii++) {
        array[iii] = tmpArray[iii-1];
    }

    delete[] tmpArray;
}

//Usuwanie elementu z podanego indeksu (szukanie wybranego indeksu, usuniecie elementu, zmniejszenie tablicy)
void Array::removeAtIndex(int index) {
    if(index < 0 || index > size) {
        std::cout << "Brak podanego indeksu w tablicy" << std::endl; //moze exception?
        return;
    }
    int* tmpArray = array;
    array = new int[--size];
    for(int iii = 0; iii < index; iii++) {
        array[iii] = tmpArray[iii];
    }

    for(int iii = index; iii < size; iii++) {
        array[iii] = tmpArray[iii+1];
    }

    delete[] tmpArray;
}

//Pobranie aktualnej wielkości tablicy
int Array::getSize() {
    return size;
}

//Wyswietelnie tablicy w jednej linie w formie: "Tablica: [element1 element2 ...]"
void Array::print() {
    std::cout << "Tablica: [";
    for(int iii=0; iii < size; iii++) {
        std::cout << " " << array[iii];
    }
    std::cout << " ]" << std::endl;
}

//Sprawdzenie czy element o podanej wartosci jest umieszczony w tablicy (zwraca true lub false)
bool Array::contains(int value) {
    for(int iii = 0; iii < size; iii++) {
        if(array[iii] == value) return true;
    }
    return false;
}

//Wczytanie elementow tablicy z pliku tekstowego
void Array::loadFromFile() {
    std::string fileName;
    std::cout << "Podaj nazwe pliku: ";
    std::cin >> fileName;
    std::ifstream file(fileName);
    if (file.is_open()) {
        delete[] array;
        array = new int[0];
        std::string input;
        std::getline(file, input);
        int elements = std::stoi(input);
        for (int iii = 0; iii < elements; iii++) {
            std::getline(file, input);
            this->pushBack(std::stoi(input));
        }
    }
    else std::cout << "Nie udalo sie otworzyc pliku!" << std::endl;
    file.close();
}

//Funkcja tworząca tablicę wypełnioną losowymi elementami (wielkosc tablicy i maksymalna wartosc elementow do wybrania)
void Array::createRandom(int elements, int max) {
    delete[] array;
    array = new int[0];
    unsigned int seed = time(NULL);
    std::mt19937 generator(seed);

    std::uniform_int_distribution<int> dist(-max, max);

    for(int iii = 0; iii < elements; iii++) {
        this->pushBack(dist(generator));
    } 
}