
/**
 * @file MergeSort.h
 * @brief Implementacja algorytmu sortowania przez scalanie (Merge Sort).
 *
 * Plik zawiera szablon klasy MergeSort, która umożliwia sortowanie
 * tablic różnych typów danych, np. int, double.
 *
 * Algorytm wykorzystuje metodę dziel i zwyciężaj.
 * Tablica jest dzielona na mniejsze części, które następnie
 * są sortowane i scalane w jedną uporządkowaną tablicę.
 */

#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

 /**
  * @class MergeSort
  * @brief Szablon klasy realizującej algorytm sortowania przez scalanie.
  *
  * Klasa umożliwia sortowanie tablic dowolnego typu T,
  * dla którego dostępny jest operator porównania <=.
  *
  * Algorytm sortuje tablicę rosnąco.
  *
  * @tparam T Typ danych przechowywanych w tablicy.
  *
  * Przykład użycia:
  * @code
  * int tab[] = { 8, 3, 5, 1 };
  *
  * MergeSort<int> sortowanie;
  * sortowanie.sortuj(tab, 4);
  * @endcode
  */
template <typename T>
class MergeSort
{
private:

    /**
     * @brief Scala dwie posortowane części tablicy w jedną całość.
     *
     * Metoda porównuje elementy z lewej i prawej części tablicy,
     * a następnie zapisuje je w odpowiedniej kolejności
     * do tablicy pomocniczej.
     *
     * Po zakończeniu scalania przepisuje uporządkowane elementy
     * z tablicy pomocniczej do tablicy oryginalnej.
     *
     * @param tab Tablica zawierająca sortowane elementy.
     * @param pomocnicza Tablica tymczasowa wykorzystywana podczas scalania.
     * @param lewy Indeks pierwszego elementu scalanych części.
     * @param srodek Indeks ostatniego elementu lewej części.
     * @param prawy Indeks ostatniego elementu prawej części.
     *
     * @note Obie scalane części muszą być wcześniej posortowane rosnąco.
     */
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

        // Przepisanie pozostałych elementów lewej części.
        while (i <= srodek)
        {
            pomocnicza[k] = tab[i];
            i++;
            k++;
        }

        // Przepisanie pozostałych elementów prawej części.
        while (j <= prawy)
        {
            pomocnicza[k] = tab[j];
            j++;
            k++;
        }

        // Przepisanie posortowanych elementów do tablicy oryginalnej.
        for (int x = lewy; x <= prawy; x++)
        {
            tab[x] = pomocnicza[x];
        }
    }

    /**
     * @brief Rekurencyjnie sortuje fragment tablicy.
     *
     * Metoda dzieli wskazany fragment tablicy na dwie części.
     * Następnie wywołuje samą siebie dla lewej i prawej części.
     * Po posortowaniu obu fragmentów wywołuje metodę scal(),
     * która łączy je w jeden posortowany fragment.
     *
     * @param tab Tablica przeznaczona do sortowania.
     * @param pomocnicza Tablica pomocnicza wykorzystywana podczas scalania.
     * @param lewy Indeks początku sortowanego fragmentu.
     * @param prawy Indeks końca sortowanego fragmentu.
     *
     * @note Rekurencja kończy się, gdy fragment zawiera jeden
     *       element lub jest pusty.
     */
    void sortuj(T tab[], T pomocnicza[], int lewy, int prawy)
    {
        if (lewy < prawy)
        {
            // Wyznaczenie środka sortowanego fragmentu.
            int srodek = (lewy + prawy) / 2;

            // Sortowanie lewej części tablicy.
            sortuj(tab, pomocnicza, lewy, srodek);

            // Sortowanie prawej części tablicy.
            sortuj(tab, pomocnicza, srodek + 1, prawy);

            // Scalanie dwóch posortowanych części.
            scal(tab, pomocnicza, lewy, srodek, prawy);
        }
    }

public:

    /**
     * @brief Sortuje tablicę rosnąco za pomocą algorytmu Merge Sort.
     *
     * Metoda publiczna rozpoczynająca proces sortowania.
     * Tworzy tablicę pomocniczą potrzebną do scalania elementów,
     * a następnie uruchamia rekurencyjną metodę sortującą.
     *
     * Tablica jest modyfikowana bezpośrednio, dlatego po zakończeniu
     * działania metody zawiera posortowane elementy.
     *
     * @param tab Tablica elementów przeznaczona do posortowania.
     * @param rozmiar Liczba elementów znajdujących się w tablicy.
     *
     * @note Dla rozmiaru równego 0 lub 1 metoda nie wykonuje sortowania.
     * @note Dla rozmiaru 0 dopuszczalne jest przekazanie nullptr.
     *
     * @warning Dla rozmiaru większego od 0 wskaźnik tab musi wskazywać
     *          na prawidłową tablicę zawierającą co najmniej rozmiar elementów.
     *
     * @code
     * int liczby[] = { 5, 2, 8, 1, 3 };
     *
     * MergeSort<int> sortowanie;
     * sortowanie.sortuj(liczby, 5);
     *
     * // Wynik: 1, 2, 3, 5, 8
     * @endcode
     */
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

#endif // MERGESORT_H
