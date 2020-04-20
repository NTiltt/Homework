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

int main () {
     int n;
     cin >> n;
     vector <int> a;
     forn(i,n) {
          int x;
          cin >> x;
          a.pb(x);
     }
     vector <int>::iterator m = min_element(all(a)); // работает за O(n - 1)
     a.insert(m,0); //insert работает за O(n + const)
     a.insert(m + 2, 0);
     forn(i,sz(a)) {
          cout << a[i] << " ";
     }
}
//Если подвести итог, получаем что задача работает за O(n).
