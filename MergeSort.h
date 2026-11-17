
#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

template <typename T>
class MergeSort
{
private:

    void scal(T tab[], T pomocnicza[], int lewy, int srodek, int prawy)
    {
        int i = lewy;
        int j = srodek + 1;
        int k = lewy;

        while (i <= srodek && j <= prawy)
        {
            if (tab[i] <= tab[j])
            {
                pomocnicza[k] = tab[i];
                i++;
            }
            else
            {
                pomocnicza[k] = tab[j];
                j++;
            }

            k++;
        }

        while (i <= srodek)
        {
            pomocnicza[k] = tab[i];
            i++;
            k++;
        }

        while (j <= prawy)
        {
            pomocnicza[k] = tab[j];
            j++;
            k++;
        }

        for (int x = lewy; x <= prawy; x++)
        {
            tab[x] = pomocnicza[x];
        }
    }

    void sortuj(T tab[], T pomocnicza[], int lewy, int prawy)
    {
        if (lewy < prawy)
        {
            int srodek = (lewy + prawy) / 2;

            sortuj(tab, pomocnicza, lewy, srodek);
            sortuj(tab, pomocnicza, srodek + 1, prawy);

            scal(tab, pomocnicza, lewy, srodek, prawy);
        }
    }

public:

    void sortuj(T tab[], int rozmiar)
    {
        if (rozmiar <= 1)
        {
            return;
        }

        std::vector<T> pomocnicza(rozmiar);

        sortuj(tab, pomocnicza.data(), 0, rozmiar - 1);
    }
};

#endif
