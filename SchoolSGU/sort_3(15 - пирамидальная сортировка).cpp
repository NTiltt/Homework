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

void read(int arr[10][10], int n) {
    forn(i,n) {
        forn(j,n) {
            cin >> arr[i][j];
        }
    }
}
void print(int arr[10][10], int n) {
    forn(i,n) {
        forn(j,n) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i=n-1; i>=0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main () {
   int arr[10][10];
   int n;
   cin >> n;
   read(arr,n);
    int mas[10];
    for (int j = 0; j < n; j++) {
        forn(i,n) {
            mas[i] = arr[i][j];
        }
        heapSort(mas,n);
        if (j % 2 == 0) {
            forn(i,n) {
                arr[i][j] = mas[i];
            }
        }
        else {
            int q = n - 1;
            forn(i,n) {
                arr[i][j] = mas[q];
                q--;
            }
        }
    }
   print(arr,n);
}

/*                          Тестовые примеры:
 *
 *          1) Ввод:
 *          5
            1 2 3 4 5
            5 4 2 1 2
            3 3 3 3 3
            0 0 0 0 0
            9 9 9 9 9

            Вывод:
            0 9 0 9 0
            1 4 2 4 2
            3 3 3 3 3
            5 2 3 1 5
            9 0 9 0 9

            2) Ввод:
            3
            1 2 3
            3 2 1
            9 9 9

            Вывод:
            1 9 1
            3 2 3
            9 2 9


 *
 *
 * */
