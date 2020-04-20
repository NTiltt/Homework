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

//ifstream in("/Users/nikita/Documents/Atom/input.txt");
//ofstream out("/Users/nikita/Documents/Atom/output.txt");

typedef long double ld;

const int N = int(1e6) + 111;
const ld EPS = 1e-7;
 void print(vector <int> x) {
      forn(i,sz(x)) {
           cout << x[i] << " ";
      }
      cout << endl;
}

int main () {
     int n;
     cin >> n;
     vector <int> a;
     int cnt = 0;
     forn(i,n) {
          int x;
          cin >> x;
          if (x < 0) {
               cnt++;
          }
          a.pb(x);
     }
     if (cnt == 0) {
          cout << "Невозможно найти максимальный отрицательный элемент." << endl;
          print(a);
          return 0;
     }
     if (sz(a) % 2 == 0) {
          cout << "Количество элементов четное." << endl;
          print(a);
          return 0;
     }
     vector <int>::iterator m = min_element(all(a)); // Работает за O(n - 1)
     int k = *m;
     a.erase(a.begin() + (n / 2)); // Работает за O(n);
     vector <int>::iterator it = a.begin() + (n / 2);
     a.insert(it,k); //Работает за O(n + const);
     print(a);

}
//Если подвести итог, получаем что задача работает за O(n).
