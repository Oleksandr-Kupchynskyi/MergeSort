
#include <iostream>
#include "MergeSort.h"

using namespace std;

int main()
{
    // Tablica typu int
    int liczby[] = { 8, 3, 5, 1, 9, 2, 7, 4 };
    int rozmiarInt = sizeof(liczby) / sizeof(liczby[0]);

    // Tablica typu double
    double liczbyDouble[] = { 4.5, 2.1, 8.7, 1.3, 5.6 };
    int rozmiarDouble = sizeof(liczbyDouble) / sizeof(liczbyDouble[0]);

    // Tworzenie obiektow klasy
    MergeSort<int> sortowanieInt;
    MergeSort<double> sortowanieDouble;

    // Sortowanie tablic
    sortowanieInt.sortuj(liczby, rozmiarInt);
    sortowanieDouble.sortuj(liczbyDouble, rozmiarDouble);

    // Wyswietlanie tablicy int
    cout << "Posortowana tablica int: ";

    for (int i = 0; i < rozmiarInt; i++)
    {
        cout << liczby[i] << " ";
    }

    cout << endl;

    // Wyswietlanie tablicy double
    cout << "Posortowana tablica double: ";

    for (int i = 0; i < rozmiarDouble; i++)
    {
        cout << liczbyDouble[i] << " ";
    }

    cout << endl;

    return 0;
}
