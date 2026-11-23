#include "pch.h"
#include "gtest/gtest.h"
#include "MergeSort.h"

#include <vector>
#include <algorithm>
#include <random>

using namespace std;


// 1. 
TEST(MergeSortTest, TablicaPosortowanaRosnaco)
{
    int tab[] = { 1, 2, 3, 4, 5, 6 };
    int oczekiwane[] = { 1, 2, 3, 4, 5, 6 };

    MergeSort<int> sortowanie;
    sortowanie.sortuj(tab, 6);

    for (int i = 0; i < 6; i++)
        EXPECT_EQ(tab[i], oczekiwane[i]);
}

// 2. 
TEST(MergeSortTest, TablicaPosortowanaOdwrotnie)
{
    int tab[] = { 6, 5, 4, 3, 2, 1 };
    int oczekiwane[] = { 1, 2, 3, 4, 5, 6 };

    MergeSort<int> sortowanie;
    sortowanie.sortuj(tab, 6);

    for (int i = 0; i < 6; i++)
        EXPECT_EQ(tab[i], oczekiwane[i]);
}

// 3.
TEST(MergeSortTest, TablicaLosowa)
{
    int tab[] = { 8, 3, 5, 1, 9, 2, 7, 4 };
    int oczekiwane[] = { 1, 2, 3, 4, 5, 7, 8, 9 };

    MergeSort<int> sortowanie;
    sortowanie.sortuj(tab, 8);

    for (int i = 0; i < 8; i++)
        EXPECT_EQ(tab[i], oczekiwane[i]);
}

// 4.
TEST(MergeSortTest, TylkoLiczbyUjemne)
{
    int tab[] = { -5, -1, -9, -3, -7 };
    int oczekiwane[] = { -9, -7, -5, -3, -1 };

    MergeSort<int> sortowanie;
    sortowanie.sortuj(tab, 5);

    for (int i = 0; i < 5; i++)
        EXPECT_EQ(tab[i], oczekiwane[i]);
}

// 5.
TEST(MergeSortTest, LiczbyUjemneIDodatnie)
{
    int tab[] = { -3, 5, -1, 8, 0, -7, 2 };
    int oczekiwane[] = { -7, -3, -1, 0, 2, 5, 8 };

    MergeSort<int> sortowanie;
    sortowanie.sortuj(tab, 7);

    for (int i = 0; i < 7; i++)
        EXPECT_EQ(tab[i], oczekiwane[i]);
}

// 6.
TEST(MergeSortTest, PustaTablica)
{
    int* tab = nullptr;

    MergeSort<int> sortowanie;

    EXPECT_NO_THROW(sortowanie.sortuj(tab, 0));
}

// 7.
TEST(MergeSortTest, JedenElement)
{
    int tab[] = { 42 };

    MergeSort<int> sortowanie;
    sortowanie.sortuj(tab, 1);

    EXPECT_EQ(tab[0], 42);
}

// 8.
TEST(MergeSortTest, TablicaZDuplikatami)
{
    int tab[] = { 4, 2, 4, 1, 3, 2 };
    int oczekiwane[] = { 1, 2, 2, 3, 4, 4 };

    MergeSort<int> sortowanie;
    sortowanie.sortuj(tab, 6);

    for (int i = 0; i < 6; i++)
        EXPECT_EQ(tab[i], oczekiwane[i]);
}

// 9.
TEST(MergeSortTest, UjemneZDuplikatami)
{
    int tab[] = { -3, -1, -3, -5, -1, -2 };
    int oczekiwane[] = { -5, -3, -3, -2, -1, -1 };

    MergeSort<int> sortowanie;
    sortowanie.sortuj(tab, 6);

    for (int i = 0; i < 6; i++)
        EXPECT_EQ(tab[i], oczekiwane[i]);
}

// 10.
TEST(MergeSortTest, UjemneDodatnieIDuplikaty)
{
    int tab[] = { -2, 3, -2, 5, 3, -1, 0, 5 };
    int oczekiwane[] = { -2, -2, -1, 0, 3, 3, 5, 5 };

    MergeSort<int> sortowanie;
    sortowanie.sortuj(tab, 8);

    for (int i = 0; i < 8; i++)
        EXPECT_EQ(tab[i], oczekiwane[i]);
}

// 11.
TEST(MergeSortTest, DwaElementyRosnaco)
{
    int tab[] = { 1, 2 };

    MergeSort<int> sortowanie;
    sortowanie.sortuj(tab, 2);

    EXPECT_EQ(tab[0], 1);
    EXPECT_EQ(tab[1], 2);
}

// 12.
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

// 13.
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

    sort(oczekiwane, oczekiwane + rozmiar);

    MergeSort<int> sortowanie;
    sortowanie.sortuj(tab, rozmiar);

    for (int i = 0; i < rozmiar; i++)
    {
        EXPECT_EQ(tab[i], oczekiwane[i]);
    }
}