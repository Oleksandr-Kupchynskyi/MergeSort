
/**
 * @file MergeSortTest.cpp
 * @brief Testy jednostkowe algorytmu MergeSort z wykorzystaniem Google Test.
 *
 * Plik zawiera zestaw 13 testów jednostkowych sprawdzających
 * poprawność działania algorytmu sortowania przez scalanie.
 *
 * Testy obejmują tablice:
 * - już posortowane rosnąco,
 * - posortowane odwrotnie,
 * - zawierające liczby w przypadkowej kolejności,
 * - zawierające liczby ujemne i dodatnie,
 * - zawierające duplikaty,
 * - puste oraz jednoelementowe,
 * - zawierające dwa elementy,
 * - duże tablice zawierające ponad 100 elementów.
 *
 * Do weryfikacji wyników wykorzystywane są asercje biblioteki
 * Google Test, między innymi EXPECT_EQ oraz EXPECT_NO_THROW.
 */

#include "pch.h"
#include "gtest/gtest.h"
#include "MergeSort.h"

#include <vector>
#include <algorithm>
#include <random>

using namespace std;

/**
 * @brief Test sortowania tablicy, która jest już posortowana rosnąco.
 *
 * Sprawdza, czy algorytm zachowuje prawidłową kolejność elementów,
 * gdy tablica nie wymaga żadnych zmian.
 *
 * @test Oczekiwany wynik: tablica pozostaje niezmieniona.
 */
TEST(MergeSortTest, TablicaPosortowanaRosnaco)
{
    int tab[] = { 1, 2, 3, 4, 5, 6 };
    int oczekiwane[] = { 1, 2, 3, 4, 5, 6 };

    MergeSort<int> sortowanie;
    sortowanie.sortuj(tab, 6);

    for (int i = 0; i < 6; i++)
        EXPECT_EQ(tab[i], oczekiwane[i]);
}

/**
 * @brief Test sortowania tablicy ułożonej w odwrotnej kolejności.
 *
 * Sprawdza, czy algorytm potrafi zmienić kolejność wszystkich
 * elementów i uzyskać poprawny porządek rosnący.
 *
 * @test Oczekiwany wynik: {1, 2, 3, 4, 5, 6}.
 */
TEST(MergeSortTest, TablicaPosortowanaOdwrotnie)
{
    int tab[] = { 6, 5, 4, 3, 2, 1 };
    int oczekiwane[] = { 1, 2, 3, 4, 5, 6 };

    MergeSort<int> sortowanie;
    sortowanie.sortuj(tab, 6);

    for (int i = 0; i < 6; i++)
        EXPECT_EQ(tab[i], oczekiwane[i]);
}

/**
 * @brief Test sortowania tablicy zawierającej liczby w przypadkowej kolejności.
 *
 * Sprawdza poprawność działania algorytmu dla typowego zbioru
 * danych, w którym elementy nie są wcześniej uporządkowane.
 *
 * @test Oczekiwany wynik: {1, 2, 3, 4, 5, 7, 8, 9}.
 */
TEST(MergeSortTest, TablicaLosowa)
{
    int tab[] = { 8, 3, 5, 1, 9, 2, 7, 4 };
    int oczekiwane[] = { 1, 2, 3, 4, 5, 7, 8, 9 };

    MergeSort<int> sortowanie;
    sortowanie.sortuj(tab, 8);

    for (int i = 0; i < 8; i++)
        EXPECT_EQ(tab[i], oczekiwane[i]);
}

/**
 * @brief Test sortowania tablicy zawierającej wyłącznie liczby ujemne.
 *
 * Sprawdza, czy algorytm prawidłowo porównuje i porządkuje
 * wartości ujemne od najmniejszej do największej.
 *
 * @test Oczekiwany wynik: {-9, -7, -5, -3, -1}.
 */
TEST(MergeSortTest, TylkoLiczbyUjemne)
{
    int tab[] = { -5, -1, -9, -3, -7 };
    int oczekiwane[] = { -9, -7, -5, -3, -1 };

    MergeSort<int> sortowanie;
    sortowanie.sortuj(tab, 5);

    for (int i = 0; i < 5; i++)
        EXPECT_EQ(tab[i], oczekiwane[i]);
}

/**
 * @brief Test sortowania tablicy z liczbami ujemnymi, dodatnimi i zerem.
 *
 * Sprawdza poprawność porównywania wartości o różnych znakach.
 *
 * @test Oczekiwany wynik: {-7, -3, -1, 0, 2, 5, 8}.
 */
TEST(MergeSortTest, LiczbyUjemneIDodatnie)
{
    int tab[] = { -3, 5, -1, 8, 0, -7, 2 };
    int oczekiwane[] = { -7, -3, -1, 0, 2, 5, 8 };

    MergeSort<int> sortowanie;
    sortowanie.sortuj(tab, 7);

    for (int i = 0; i < 7; i++)
        EXPECT_EQ(tab[i], oczekiwane[i]);
}

/**
 * @brief Test obsługi pustej tablicy.
 *
 * Sprawdza, czy wywołanie metody sortującej z pustą tablicą
 * nie powoduje zgłoszenia wyjątku.
 *
 * @test Oczekiwany wynik: brak wyjątku podczas wykonywania metody.
 */
TEST(MergeSortTest, PustaTablica)
{
    int* tab = nullptr;

    MergeSort<int> sortowanie;

    EXPECT_NO_THROW(sortowanie.sortuj(tab, 0));
}

/**
 * @brief Test obsługi tablicy zawierającej jeden element.
 *
 * Sprawdza, czy algorytm poprawnie obsługuje tablicę,
 * która jest już posortowana i nie wymaga żadnych zmian.
 *
 * @test Oczekiwany wynik: element 42 pozostaje bez zmian.
 */
TEST(MergeSortTest, JedenElement)
{
    int tab[] = { 42 };

    MergeSort<int> sortowanie;
    sortowanie.sortuj(tab, 1);

    EXPECT_EQ(tab[0], 42);
}

/**
 * @brief Test sortowania tablicy zawierającej duplikaty.
 *
 * Sprawdza, czy algorytm poprawnie sortuje powtarzające się
 * wartości oraz zachowuje wszystkie elementy tablicy.
 *
 * @test Oczekiwany wynik: {1, 2, 2, 3, 4, 4}.
 */
TEST(MergeSortTest, TablicaZDuplikatami)
{
    int tab[] = { 4, 2, 4, 1, 3, 2 };
    int oczekiwane[] = { 1, 2, 2, 3, 4, 4 };

    MergeSort<int> sortowanie;
    sortowanie.sortuj(tab, 6);

    for (int i = 0; i < 6; i++)
        EXPECT_EQ(tab[i], oczekiwane[i]);
}

/**
 * @brief Test sortowania liczb ujemnych zawierających duplikaty.
 *
 * Sprawdza poprawność sortowania powtarzających się wartości
 * ujemnych oraz zachowanie ich liczby w tablicy.
 *
 * @test Oczekiwany wynik: {-5, -3, -3, -2, -1, -1}.
 */
TEST(MergeSortTest, UjemneZDuplikatami)
{
    int tab[] = { -3, -1, -3, -5, -1, -2 };
    int oczekiwane[] = { -5, -3, -3, -2, -1, -1 };

    MergeSort<int> sortowanie;
    sortowanie.sortuj(tab, 6);

    for (int i = 0; i < 6; i++)
        EXPECT_EQ(tab[i], oczekiwane[i]);
}

/**
 * @brief Test sortowania liczb ujemnych, dodatnich i duplikatów.
 *
 * Sprawdza działanie algorytmu dla bardziej złożonego zbioru
 * danych, który zawiera różne znaki liczb oraz powtarzające
 * się wartości.
 *
 * @test Oczekiwany wynik: {-2, -2, -1, 0, 3, 3, 5, 5}.
 */
TEST(MergeSortTest, UjemneDodatnieIDuplikaty)
{
    int tab[] = { -2, 3, -2, 5, 3, -1, 0, 5 };
    int oczekiwane[] = { -2, -2, -1, 0, 3, 3, 5, 5 };

    MergeSort<int> sortowanie;
    sortowanie.sortuj(tab, 8);

    for (int i = 0; i < 8; i++)
        EXPECT_EQ(tab[i], oczekiwane[i]);
}

/**
 * @brief Test sortowania tablicy zawierającej dwa elementy rosnąco.
 *
 * Sprawdza zachowanie algorytmu dla najmniejszej tablicy
 * zawierającej więcej niż jeden element.
 *
 * @test Oczekiwany wynik: {1, 2}.
 */
TEST(MergeSortTest, DwaElementyRosnaco)
{
    int tab[] = { 1, 2 };

    MergeSort<int> sortowanie;
    sortowanie.sortuj(tab, 2);

    EXPECT_EQ(tab[0], 1);
    EXPECT_EQ(tab[1], 2);
}

/**
 * @brief Test sortowania dużej tablicy zawierającej 150 elementów.
 *
 * Tablica zostaje wypełniona liczbami w odwrotnej kolejności.
 * Po wykonaniu sortowania sprawdzane jest, czy wszystkie elementy
 * znajdują się na właściwych pozycjach.
 *
 * @test Oczekiwany wynik: liczby od 1 do 150 w kolejności rosnącej.
 */
TEST(MergeSortTest, DuzaTablica)
{
    const int rozmiar = 150;
    int tab[rozmiar];

    for (int i = 0; i < rozmiar; i++)
    {
        tab[i] = rozmiar - i;
    }

    MergeSort<int> sortowanie;
    sortowanie.sortuj(tab, rozmiar);

    for (int i = 0; i < rozmiar; i++)
    {
        EXPECT_EQ(tab[i], i + 1);
    }
}

/**
 * @brief Test sortowania dużej tablicy zawierającej różne liczby i duplikaty.
 *
 * Tablica zawiera 200 elementów, w tym liczby ujemne,
 * zero, liczby dodatnie oraz powtarzające się wartości.
 *
 * Do utworzenia wyniku wzorcowego wykorzystywana jest
 * standardowa funkcja sort() z biblioteki algorithm.
 *
 * Następnie wynik algorytmu MergeSort porównywany jest
 * z tablicą wzorcową.
 *
 * @test Oczekiwany wynik: identyczna zawartość obu posortowanych tablic.
 */
TEST(MergeSortTest, DuzaTablicaUjemneDodatnieDuplikaty)
{
    const int rozmiar = 200;
    int tab[rozmiar];

    for (int i = 0; i < rozmiar; i++)
    {
        tab[i] = (i % 21) - 10;
    }

    int oczekiwane[rozmiar];

    for (int i = 0; i < rozmiar; i++)
    {
        oczekiwane[i] = tab[i];
    }

    // Utworzenie wzorcowego wyniku sortowania.
    sort(oczekiwane, oczekiwane + rozmiar);

    MergeSort<int> sortowanie;
    sortowanie.sortuj(tab, rozmiar);

    // Porównanie wyniku MergeSort z wynikiem wzorcowym.
    for (int i = 0; i < rozmiar; i++)
    {
        EXPECT_EQ(tab[i], oczekiwane[i]);
    }
}
