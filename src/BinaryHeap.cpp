#include "BinaryHeap.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <random>

//Konstruktor nowego kopca binarnego o stałym rozmiarze wewnętrznej tablicy (30000 elementów)
BinaryHeap::BinaryHeap()
{
    table = new int[30001];
    size = 0;
}

//Destruktor kopca (usuwanie z pamięci wewnętrznej tablicy);
BinaryHeap::~BinaryHeap()
{
    delete[] table;
}

//Dodawanie nowego elementu do kopca (dodajemy nowy element i naprawiamy kopiec w górę)
void BinaryHeap::add(int value)
{
    table[size++] = value;

    int index = size - 1;
    int parent = (index - 1) / 2;

    while (index > 0 && table[index] > table[parent])   //pętla służąca do przejścia z indeksu w górę w celu naprawy własności kopca
    {
        int tmp = table[parent];
        table[parent] = table[index];
        table[index] = tmp;
        index = parent;
        parent = (index - 1) / 2;
    }
}

//Usuwanie elementu z kopca (usuwamy element zastepujac go ostatnio dodanym i naprawiamy kopiec w dół od miejsca usunietego elementu)
void BinaryHeap::remove(int value)
{
    int index = getIndex(value);
    if (index == -1)
        return;

    if (size == 1)
    {
        table[0] = 0;
        size--;
        return;
    }

    table[index] = table[--size];
    table[size] = 0;

    heapifyDown(index);
}

//Funkcja zwracajaca indeks elementu o podanej wartości
int BinaryHeap::getIndex(int value)
{
    int index = 0;
    while (index < size)
    {
        if (table[index] == value)
            return index;
        index++;
    }
    return -1;
}

//Funkcja sprawdzająca czy element o podanej wartości znajduje się w kopcu (true albo false)
bool BinaryHeap::contains(int value) {
    int index = 0;
    while (index < size)
    {
        if (table[index] == value)
            return true;
        index++;
    }
    return false;
}

//Funkcja służąca do naprawiania kopca w dół (używana przy usuwaniu) - używana jest w tym przypadku rekurencja do kolejnych przejść
void BinaryHeap::heapifyDown(int index)
{
    int current = index;
    int child1 = current * 2 + 1;
    int child2 = current * 2 + 2;

    if (child1 < size && table[current] < table[child1])
        current = child1;
    if (child2 < size && table[current] < table[child2])
        current = child2;
    if (current != index)
    {
        int tmp = table[index];
        table[index] = table[current];
        table[current] = tmp;
        heapifyDown(current);
    }
}


//Wyswietlanie kopca w jednej linii (forma tablicy)
void BinaryHeap::print()
{
    std::cout << "Heap: [ ";
    for (int iii = 0; iii < size; iii++)
    {
        std::cout << table[iii] << " ";
    }
    std::cout << "]" << std::endl;
}


//Wyswietlanie kopca w formie drzewa
void BinaryHeap::printTree(std::string sp, std::string sn, int index)
{
    std::string s;
    std::string cr,cp,cl;
    cr = cl = cp = "  ";
    cr [ 0 ] = 218; cr [ 1 ] = 196;
    cl [ 0 ] = 192; cl [ 1 ] = 196;
    cp [ 0 ] = 179;
    if (index < size)
    {
        s = sp;
        if (sn == cr)
            s[s.length() - 2] = ' ';
        printTree(s + cp, cr, 2 * index + 2);

        s = s.substr(0, sp.length() - 2);

        std::cout << s << sn << table[index] << std::endl;

        s = sp;
        if (sn == cl)
            s[s.length() - 2] = ' ';
        printTree(s + cp, cl, 2 * index + 1);
    }
}

//Funkcja ladujaca elementy z pliku tekstowego do nowego kopca
void BinaryHeap::loadFromFile() {
    std::string fileName;
    std::cout << "Podaj nazwe pliku: ";
    std::cin >> fileName;
    std::ifstream file(fileName);
    if (file.is_open()) {
        size = 0;
        std::string input;
        std::getline(file, input);
        int elements = std::stoi(input);
        for (int iii = 0; iii < elements; iii++) {
            std::getline(file, input);
            add(std::stoi(input));
        }
    }
    else std::cout << "Nie udalo sie otworzyc pliku!" << std::endl;
    file.close();
}

//Funkcja generująca nowy kopiec z losowymi elementami (podajemy wielkość struktury i maksymalną wartość elementów)
void BinaryHeap::createRandom(int elements, int max) {
    size = 0;
    unsigned int seed = time(NULL);
    std::mt19937 generator(seed);

    std::uniform_int_distribution<int> dist(-max, max);

    for(int iii = 0; iii < elements; iii++) {
        this->add(dist(generator));
    } 
}