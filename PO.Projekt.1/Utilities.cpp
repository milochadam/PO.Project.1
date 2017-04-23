#include "Utilities.h"
#include <time.h>
#include <Windows.h>
#include <random>
#include <iostream>
using namespace std;

void Utilities::gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int Utilities::randomMovement() {
	std::default_random_engine generator;
	std::discrete_distribution<int> distribution{ 1,1,1,1, };
	return distribution(generator);
}

void Utilities::setColour(int k) {
	SetConsoleTitle(TEXT("Virtual world - Adam Miloch 165178"));
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, k);
}

void Utilities::hideCursor() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

int Utilities::randomize(int a, int b) {
	/*std::random_device generator;
	std::uniform_int_distribution<int> distribution{ a, b };
	return distribution(generator);*/
	//std::random_device rd;     // only used once to initialise (seed) engine
	//std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	//std::uniform_int_distribution<int> uni(a, b); // guaranteed unbiased

	return rand() % (b - a + 1) + a;
}

void Utilities::gameOver(int turnCount, int OrganismCount) {
	gotoxy(0, 0);
	system("cls");
	setColour(4);
	cout << endl;
	cout << "GAME OVER" << endl;
	cout << endl;
	cout << endl;


	setColour(14);
	//cout << " *** " + ostatni_komunikat + " ***";
	cout << endl;
	cout << endl;
	setColour(12);
	cout << " * Udalo ci sie przezyc " << turnCount << " tur" << endl;
	cout << " * Liczba stworzen na mapie: " << OrganismCount << endl;
	cout << endl;
}

Utilities::Utilities()
{
	//std::random_device generator;
	srand(time(NULL));
}


Utilities::~Utilities()
{
}
