#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <iterator>
#include <list>
#include <queue>
#include <stack>
#include <ctime>
#include <cstddef>


#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define forn(i, n) fore(i, 0, n)
#define pb push_back
#define x first
#define y second
#define mp make_pair

using namespace std;



typedef long double ld;

const int N = int(1e6) + 111;
const ld EPS = 1e-7;

void print(int mas[10][10], int n) {
    forn(i,n) {
        forn(j,n) {
            cout << mas[i][j] << " ";
        }
        cout << endl;
    }
}
void read(int mas[10][10], int n) {
    forn(i,n) {
        forn(j,n) {
            cin >> mas[i][j];
        }
    }
}
void quickSort(int *num, int l, int r) {
    int p;
    int left_hold = l;
    int right_hold = r;
    p = num[l];
    while (l < r) {
        while ((num[r] >= p) && (l < r)) {
            r--;
        }
        if (l != r) {
            num[l] = num[r];
            l++;
        }
        while ((num[l] <= p) && (l < r)) {
            l++;
        }
        if (l != r) {
            num[r] = num[l];
            r--;
        }
    }
    num[l] = p;
    p = l;
    l = left_hold;
    r = right_hold;
    if (l < p) {
        quickSort(num, l, p - 1);
    }
    if (r > p) {
        quickSort(num, p + 1, r);
    }
}

int main () {
    int n;
    int arr[10][10];
    cin >> n;
    read(arr,n);
    int mas[10];
    for (int j = 1; j < n; j+=2) {
        forn(i,n) {
            mas[i] = arr[i][j];
        }
        quickSort(mas, 0, n - 1);
        forn(i,n) {
            arr[i][j] = mas[i];
        }
    }
    for (int j = 0; j < n; j+=2) {
        forn(i,n) {
            mas[i] = arr[i][j];
        }
        quickSort(mas,0, n - 1);
        int q = n - 1;
        forn(i,n) {
            arr[i][j] = mas[q];
            q--;
        }
    }
    print(arr, n);
}

/*
 *              Тестовые примеры:
 *
 *      1) Ввод:
 *       5
         1 1 1 1 1
         2 2 2 2 2
         9 9 9 9 9
         0 0 0 0 0
         3 3 3 3 3

         Вывод:
         9 0 9 0 9
         3 1 3 1 3
         2 2 2 2 2
         1 3 1 3 1
         0 9 0 9 0

         2) Ввод:
            5
            1 2 3 4 5
            5 4 3 2 1
            1 1 1 1 1
            -1 4 9 5 0
            8 8 8 8 8

            Вывод:
            8 1 9 1 8
            5 2 8 2 5
            1 4 3 4 1
            1 4 3 5 1
            -1 8 1 8 0
 *
 * */