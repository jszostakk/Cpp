#include "Hero.h"
#include "Enemy.h"
#include "Exception.h"
#include "time.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <exception>
#include <unistd.h>

using namespace std;
/**
 * Funkcja sprawdza poziom trudnosci
 * @param order wpisany poziom trudnosci
 * @return mnoznik
 */
double checkDifficulty(string order);
/**
 * Funkcja wyswietla pomoc w starcie programu
 */
void help();
/**
 * Funkcja symulująca walkę między dwoma identycznymi obiektami
 * @param hero obiekt klasy - gracz
 */
void fight(Hero &hero);
/**
 * Funkcja symulująca walkę między obiektem klasy Hero i obiektem klasy Enemy
 * @param hero obiekt Hero - gracz
 * @param enemy obiekt Enemy
 */
void fight(Hero &hero, Enemy *enemy);
/**
 * Glowna petla programu w ktorej wlaczamy konkretne funkcje
 * @param hero obiekt Hero - gracz
 * @param vector kontener zawierajacy informacje o misjach
 * @param difficulty mnoznik poziomu trudnosci
 * @param items tablica z obiektami Item w sklepie
 * @param equipment tablica ekwipunku
 * @param backpack tablica plecaka
 */
void tavern(Hero &hero, vector<string> &vector, double difficulty, Item items[], Item equipment[], Item backpack[]);
/**
 * Funkcja misji - wywswietla misje majace konkretny czas trwania, nagrode i nazwe
 * @param hero obiekt Hero - gracz
 * @param vector kontener zawierajacy informacje o misjach
 * @param level poziom z ktorym generujemy przeciwnika
 * @param difficulty mnoznik poziomu trudnosci
 * @return nagroda za misje
 */
int mission(Hero &hero, vector<string> &vector, int level, double difficulty);
/**
 * Funkcja sklepu posiadajaca mozliwosc kupowania przedmiotow do plecaka
 * @param hero obiekt Hero - gracz
 * @param items tablica z obiektami Item w sklepie
 * @param equipment tablica ekwipunku
 * @param backpack tablica plecaka
 */
void shop(Hero &hero, Item items[], Item equipment[], Item backpack[]);
/**
 * Funkcja wyswietlania statystyk bohatera
 * @param hero obiekt Hero - gracz
 * @param equipment tablica ekwipunku
 * @param backpack tablica plecaka
 */
void heroF(Hero &hero, Item equipment[], Item backpack[]);
/**
 * Funkcja zmieniania pliku na kontener stringów
 * @param file plik
 * @param vector wektor docelowy
 */
void getFile(string file, vector<string> &vector);
/**
 * Funkcja z uzyciem template, zgadywanie ktora wartosc liczbowa jest wieksza
 * @tparam T typ zmiennych
 * @param a zmienna pierwsza
 * @param b zmienna druga
 * @return true dla sukcesu false dla porazki
 */
template<typename T>
bool whatsBigger(T a, T b) {
    cout << "Guess which is bigger: \n-a\n-b\n-equal" << endl;
    string choice;
    while (1) {
        cin >> choice;
        if (choice == "a" || choice == "b" || choice == "equal")
            break;
    }
    if (choice == "a" && a > b) {
        cout << "Congratulations!" << endl;
        return true;
    } else if (choice == "b" && b > a) {
        cout << "Congratulations!" << endl;
        return true;
    } else if (choice == "equal" && a == b) {
        cout << "Congratulations!" << endl;
        return true;
    }
    cout << "Maybe next time!" << endl;
    return false;
}
/**
 * Funkcja prosi o inwestycje, w przypadku sukcesu dodaje graczowi tyle beneficjum ile zainwestowal
 * @param hero obiekt Hero -gracz
 * @return nagroda badz ubytek
 */
int gambling(Hero hero);
/**
 * Funkcja przypisujaca przedmioty do tablicy obiektow
 * @param items tablica docelowa
 * @param sitems kontener z informacjami do przekazania
 */
void itemsArray(Item items[], vector<string> &sitems);
/**
 * Funkcja zamienia string na male litery
 * @param string string do zamiany
 */
void toLower(string &string);