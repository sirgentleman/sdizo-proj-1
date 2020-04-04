#ifndef TESTS_H
#define TESTS_H

#include "Timer.h"
#include <random>

class Tests {
private:
	const std::string ARRAY_MENU_TEXT = "------TESTOWANIE------\n"
		"Wybierz strukture:\n"
		"1. Dodaj element na poczatek\n"
		"2. Dodaj element na koniec\n"
		"3. Dodaj element w miejscu\n"
		"4. Usun element z poczatku\n"
		"5. Usun element z konca\n"
		"6. Usun element z indeksu\n"
		"7. Znajdz element\n"
		"0. Wyjscie\n";

	const std::string HEAP_MENU_TEXT = "------TESTOWANIE------\n"
		"Wybierz strukture:\n"
		"1. Dodaj element.\n"
		"2. Usun element.\n"
		"3. Znajdz element\n"
		"0. Wyjscie\n";

	Timer* timer;
	std::mt19937 generator;

public:
	Tests();
	~Tests();

	void startArrayTesting();
	void startListTesting();
	void startHeapTesting();
	void startRBTreeTesting();

};

#endif TESTS_H
