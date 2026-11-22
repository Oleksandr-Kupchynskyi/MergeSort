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
