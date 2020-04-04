#include "Tests.h"
#include "Array.h"
#include "List.h"
#include "BinaryHeap.h"
#include "RBTree.h"

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

//FUNKCJE S£U¯¥CE DO PRZEPROWADZENIA TESTÓW

Tests::Tests() {
	timer = new Timer();
	generator = std::mt19937(time(NULL));
}

Tests::~Tests() {
	delete timer;
}

void Tests::startArrayTesting() {
	Array* array;
	int choice;

	do {
		std::cout << "\n\n====TABLICA====" << std::endl;
		std::cout << ARRAY_MENU_TEXT;
		std::cout << "Wybierz opcje (cyfra): ";
		std::cin.clear();
		std::cin.ignore();
		std::cin >> choice;
		if (choice == 0) continue;
		std::cout << "Podaj nazwe pliku wyjsciowego (.csv): ";
		std::string fileName;
		std::cin >> fileName;
		std::fstream file(fileName, std::ios::out | std::ios::app);
		array = new Array();
		switch (choice) {
		case 1: {
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

			std::cout << "\n\nRozpoczynanie testu dodawania z przodu...\n" << std::endl;
			std::uniform_int_distribution<int> dist(-max, max);
			for (int iii = 0; iii < size; iii++) {
				int value = dist(generator);
				timer->startTimer();
				array->pushFront(value);
				double time = timer->getTimer();

				std::cout << iii << ": " << time << " ms\n";
				file << time << std::endl;
			}
			std::cout << "\n\nTestowanie zakoñczone!" << std::endl;

			break;
		}
		case 2: {
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

			std::cout << "\n\nRozpoczynanie testu dodawania z tylu...\n" << std::endl;
			std::uniform_int_distribution<int> dist(-max, max);
			for (int iii = 0; iii < size; iii++) {
				int value = dist(generator);
				timer->startTimer();
				array->pushBack(value);
				double time = timer->getTimer();

				std::cout << iii << ": " << time << " ms\n";
				file << time << std::endl;
			}
			std::cout << "\n\nTestowanie zakoñczone!" << std::endl;

			break;
		}
		case 3: {
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

			std::cout << "\n\nRozpoczynanie testu dodawania pod indeksem...\n" << std::endl;
			std::uniform_int_distribution<int> dist(-max, max);
			for (int iii = 0; iii < size; iii++) {
				std::uniform_int_distribution<int> dist2(0, iii+1);
				int index = dist2(generator);
				int value = dist(generator);
				timer->startTimer();
				array->addAtIndex(index, value);
				double time = timer->getTimer();

				std::cout << iii << ": " << time << " ms\n";
				file << time << std::endl;
			}
			std::cout << "\n\nTestowanie zakoñczone!" << std::endl;

			break;
		}
		case 4: {
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

			std::cout << "\n\nRozpoczynanie testu usuwania z przodu...\n" << std::endl;
			array->createRandom(size, max);
			for (int iii = 0; iii < size; iii++) {
				timer->startTimer();
				array->popFront();
				double time = timer->getTimer();

				std::cout << iii << ": " << time << " ms\n";
				file << time << std::endl;
			}
			std::cout << "\n\nTestowanie zakoñczone!" << std::endl;
			break;
		}
		case 5: {
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

			std::cout << "\n\nRozpoczynanie testu usuwania z tylu...\n" << std::endl;
			array->createRandom(size, max);
			for (int iii = 0; iii < size; iii++) {
				timer->startTimer();
				array->popBack();
				double time = timer->getTimer();

				std::cout << iii << ": " << time << " ms\n";
				file << time << std::endl;
			}
			std::cout << "\n\nTestowanie zakoñczone!" << std::endl;
			break;
		}
		case 6: {
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

			std::cout << "\n\nRozpoczynanie testu usuwania pod indeksem...\n" << std::endl;
			array->createRandom(size, max);
			for (int iii = 0; iii < size; iii++) {
				std::uniform_int_distribution<int> dist2(0, size-iii-1);
				int index = dist2(generator);
				timer->startTimer();
				array->removeAtIndex(index);
				double time = timer->getTimer();

				std::cout << iii << ": " << time << " ms\n";
				file << time << std::endl;
			}
			std::cout << "\n\nTestowanie zakoñczone!" << std::endl;

			break;
		}
		case 7: {
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

			std::cout << "\n\nRozpoczynanie testu znajdowania...\n" << std::endl;
			array->createRandom(size, max);
			for (int iii = 0; iii < size; iii++) {
				std::uniform_int_distribution<int> dist(-max, max);
				int value = dist(generator);
				timer->startTimer();
				array->contains(value);
				double time = timer->getTimer();

				std::cout << iii << ": " << time << " ms\n";
				file << time << std::endl;
			}
			std::cout << "\n\nTestowanie zakoñczone!" << std::endl;

			break;
		}
		}
		delete array;
		file.close();
	} while (choice != 0);
	
}

void Tests::startListTesting() {
	List* list;
	int choice;

	do {
		std::cout << "\n\n====LISTA====" << std::endl;
		std::cout << ARRAY_MENU_TEXT;
		std::cout << "Wybierz opcje (cyfra): ";
		std::cin.clear();
		std::cin.ignore();
		std::cin >> choice;
		if (choice == 0) continue;
		std::cout << "Podaj nazwe pliku wyjsciowego (.csv): ";
		std::string fileName;
		std::cin >> fileName;
		std::fstream file(fileName, std::ios::out | std::ios::app);
		list = new List();
		switch (choice) {
		case 1: {
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

			std::cout << "\n\nRozpoczynanie testu dodawania z przodu...\n" << std::endl;
			std::uniform_int_distribution<int> dist(-max, max);
			for (int iii = 0; iii < size; iii++) {
				int value = dist(generator);
				timer->startTimer();
				list->pushFront(value);
				double time = timer->getTimer();

				std::cout << iii << ": " << time << " ms\n";
				file << time << std::endl;
			}
			std::cout << "\n\nTestowanie zakoñczone!" << std::endl;

			break;
		}
		case 2: {
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

			std::cout << "\n\nRozpoczynanie testu dodawania z tylu...\n" << std::endl;
			std::uniform_int_distribution<int> dist(-max, max);
			for (int iii = 0; iii < size; iii++) {
				int value = dist(generator);
				timer->startTimer();
				list->pushBack(value);
				double time = timer->getTimer();

				std::cout << iii << ": " << time << " ms\n";
				file << time << std::endl;
			}
			std::cout << "\n\nTestowanie zakoñczone!" << std::endl;

			break;
		}
		case 3: {
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

			std::cout << "\n\nRozpoczynanie testu dodawania pod indeksem...\n" << std::endl;
			std::uniform_int_distribution<int> dist(-max, max);
			for (int iii = 0; iii < size; iii++) {
				std::uniform_int_distribution<int> dist2(0, iii + 1);
				int index = dist2(generator);
				int value = dist(generator);
				timer->startTimer();
				list->addAtIndex(index, value);
				double time = timer->getTimer();

				std::cout << iii << ": " << time << " ms\n";
				file << time << std::endl;
			}
			std::cout << "\n\nTestowanie zakoñczone!" << std::endl;

			break;
		}
		case 4: {
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

			std::cout << "\n\nRozpoczynanie testu usuwania z przodu...\n" << std::endl;
			list->createRandom(size, max);
			for (int iii = 0; iii < size; iii++) {
				timer->startTimer();
				list->popFront();
				double time = timer->getTimer();

				std::cout << iii << ": " << time << " ms\n";
				file << time << std::endl;
			}
			std::cout << "\n\nTestowanie zakoñczone!" << std::endl;
			break;
		}
		case 5: {
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

			std::cout << "\n\nRozpoczynanie testu usuwania z tylu...\n" << std::endl;
			list->createRandom(size, max);
			for (int iii = 0; iii < size; iii++) {
				timer->startTimer();
				list->popBack();
				double time = timer->getTimer();

				std::cout << iii << ": " << time << " ms\n";
				file << time << std::endl;
			}
			std::cout << "\n\nTestowanie zakoñczone!" << std::endl;
			break;
		}
		case 6: {
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

			std::cout << "\n\nRozpoczynanie testu usuwania pod indeksem...\n" << std::endl;
			list->createRandom(size, max);
			for (int iii = 0; iii < size; iii++) {
				std::uniform_int_distribution<int> dist2(0, size - iii - 1);
				int index = dist2(generator);
				timer->startTimer();
				list->removeAtIndex(index);
				double time = timer->getTimer();

				std::cout << iii << ": " << time << " ms\n";
				file << time << std::endl;
			}
			std::cout << "\n\nTestowanie zakoñczone!" << std::endl;

			break;
		}
		case 7: {
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

			std::cout << "\n\nRozpoczynanie testu znajdowania...\n" << std::endl;
			list->createRandom(size, max);
			for (int iii = 0; iii < size; iii++) {
				std::uniform_int_distribution<int> dist(-max, max);
				int value = dist(generator);
				timer->startTimer();
				list->contains(value);
				double time = timer->getTimer();

				std::cout << iii << ": " << time << " ms\n";
				file << time << std::endl;
			}
			std::cout << "\n\nTestowanie zakoñczone!" << std::endl;

			break;
		}
		}
		delete list;
		file.close();
	} while (choice != 0);

}

void Tests::startHeapTesting() {
	BinaryHeap* heap;
	int choice;

	do {
		std::cout << "\n\n====KOPIEC BINARNY====" << std::endl;
		std::cout << HEAP_MENU_TEXT;
		std::cout << "Wybierz opcje (cyfra): ";
		std::cin.clear();
		std::cin.ignore();
		std::cin >> choice;
		if (choice == 0) continue;
		std::cout << "Podaj nazwe pliku wyjsciowego (.csv): ";
		std::string fileName;
		std::cin >> fileName;
		std::fstream file(fileName, std::ios::out | std::ios::app);
		heap = new BinaryHeap();
		switch (choice) {
		case 1: {
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

			std::cout << "\n\nRozpoczynanie testu dodawania...\n" << std::endl;
			std::uniform_int_distribution<int> dist(-max, max);
			for (int iii = 0; iii < size; iii++) {
				int value = dist(generator);
				timer->startTimer();
				heap->add(value);
				double time = timer->getTimer();

				std::cout << iii << ": " << time << " ms\n";
				file << time << std::endl;
			}
			std::cout << "\n\nTestowanie zakoñczone!" << std::endl;

			break;
		}
		case 2: {
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

			std::cout << "\n\nRozpoczynanie testu usuwania...\n" << std::endl;
			heap->createRandom(size, max);
			for (int iii = 0; iii < size; iii++) {
				std::uniform_int_distribution<int> dist2(0, size - iii - 1);
				int index = dist2(generator);
				timer->startTimer();
				heap->remove(index);
				double time = timer->getTimer();

				std::cout << iii << ": " << time << " ms\n";
				file << time << std::endl;
			}
			std::cout << "\n\nTestowanie zakoñczone!" << std::endl;
			break;
		}
		case 3: {
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

			std::cout << "\n\nRozpoczynanie testu znajdowania...\n" << std::endl;
			heap->createRandom(size, max);
			for (int iii = 0; iii < size; iii++) {
				std::uniform_int_distribution<int> dist(-max, max);
				int value = dist(generator);
				timer->startTimer();
				heap->contains(value);
				double time = timer->getTimer();

				std::cout << iii << ": " << time << " ms\n";
				file << time << std::endl;
			}
			std::cout << "\n\nTestowanie zakoñczone!" << std::endl;

			break;
		}
		}
		delete heap;
		file.close();
	} while (choice != 0);
}

void Tests::startRBTreeTesting() {
	RBTree* tree;
	int choice;

	do {
		std::cout << "\n\n====DRZEWO CZERWONO-CZARNE====" << std::endl;
		std::cout << HEAP_MENU_TEXT;
		std::cout << "Wybierz opcje (cyfra): ";
		std::cin.clear();
		std::cin.ignore();
		std::cin >> choice;
		if (choice == 0) continue;
		std::cout << "Podaj nazwe pliku wyjsciowego (.csv): ";
		std::string fileName;
		std::cin >> fileName;
		std::fstream file(fileName, std::ios::out | std::ios::app);
		tree = new RBTree();
		switch (choice) {
		case 1: {
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

			std::cout << "\n\nRozpoczynanie testu dodawania...\n" << std::endl;
			std::uniform_int_distribution<int> dist(-max, max);
			for (int iii = 0; iii < size; iii++) {
				int value = dist(generator);
				timer->startTimer();
				tree->add(value);
				double time = timer->getTimer();

				std::cout << iii << ": " << time << " ms\n";
				file << time << std::endl;
			}
			std::cout << "\n\nTestowanie zakoñczone!" << std::endl;

			break;
		}
		case 2: {
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

			std::cout << "\n\nRozpoczynanie testu usuwania...\n" << std::endl;
			tree->createRandom(size, max);
			for (int iii = 0; iii < size; iii++) {
				std::uniform_int_distribution<int> dist2(0, size - iii - 1);
				int index = dist2(generator);
				timer->startTimer();
				tree->remove(index);
				double time = timer->getTimer();

				std::cout << iii << ": " << time << " ms\n";
				file << time << std::endl;
			}
			std::cout << "\n\nTestowanie zakoñczone!" << std::endl;
			break;
		}
		case 3: {
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

			std::cout << "\n\nRozpoczynanie testu znajdowania...\n" << std::endl;
			tree->createRandom(size, max);
			for (int iii = 0; iii < size; iii++) {
				std::uniform_int_distribution<int> dist(-max, max);
				int value = dist(generator);
				timer->startTimer();
				tree->contains(value);
				double time = timer->getTimer();

				std::cout << iii << ": " << time << " ms\n";
				file << time << std::endl;
			}
			std::cout << "\n\nTestowanie zakoñczone!" << std::endl;

			break;
		}
		}
		delete tree;
		file.close();
	} while (choice != 0);
}