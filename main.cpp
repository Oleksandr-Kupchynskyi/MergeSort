
/**
 * @file main.cpp
 * @brief Program prezentujący działanie algorytmu Merge Sort.
 *
 * Program demonstruje wykorzystanie szablonowej klasy MergeSort
 * do sortowania tablic zawierających liczby całkowite
 * oraz liczby zmiennoprzecinkowe.
 */

#include <iostream>
#include "MergeSort.h"

using namespace std;

/**
 * @brief Główna funkcja programu.
 *
 * Funkcja tworzy dwie tablice z danymi różnych typów,
 * oblicza ich rozmiary, tworzy obiekty klasy MergeSort,
 * a następnie sortuje obie tablice rosnąco.
 *
 * Po zakończeniu sortowania wyświetla zawartość tablic
 * na standardowym wyjściu.
 *
 * @return 0 Program zakończył działanie poprawnie.
 */
int main()
{
    /**
     * @brief Tablica liczb całkowitych.
     *
     * Zawiera osiem elementów w przypadkowej kolejności.
     */
    int liczby[] = { 8, 3, 5, 1, 9, 2, 7, 4 };

    /**
     * @brief Rozmiar tablicy liczb całkowitych.
     *
     * Rozmiar obliczany jest przez podzielenie
     * całkowitego rozmiaru tablicy przez rozmiar jednego elementu.
     */
    int rozmiarInt = sizeof(liczby) / sizeof(liczby[0]);

    /**
     * @brief Tablica liczb zmiennoprzecinkowych.
     *
     * Zawiera pięć elementów typu double.
     */
    double liczbyDouble[] = { 4.5, 2.1, 8.7, 1.3, 5.6 };

    /**
     * @brief Rozmiar tablicy liczb zmiennoprzecinkowych.
     */
    int rozmiarDouble = sizeof(liczbyDouble) / sizeof(liczbyDouble[0]);

    // Utworzenie obiektu sortującego liczby całkowite.
    MergeSort<int> sortowanieInt;

    // Utworzenie obiektu sortującego liczby zmiennoprzecinkowe.
    MergeSort<double> sortowanieDouble;

    // Sortowanie tablicy liczb całkowitych.
    sortowanieInt.sortuj(liczby, rozmiarInt);

    // Sortowanie tablicy liczb zmiennoprzecinkowych.
    sortowanieDouble.sortuj(liczbyDouble, rozmiarDouble);

    // Wyświetlenie posortowanej tablicy typu int.
    cout << "Posortowana tablica int: ";

    for (int i = 0; i < rozmiarInt; i++)
    {
        cout << liczby[i] << " ";
    }

    cout << endl;

    // Wyświetlenie posortowanej tablicy typu double.
    cout << "Posortowana tablica double: ";

    for (int i = 0; i < rozmiarDouble; i++)
    {
        cout << liczbyDouble[i] << " ";
    }

    cout << endl;

    return 0;
}
