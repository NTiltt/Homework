//
// @author: Nikita 
//

/*#include <iostream>
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
//#define in cin
//#define out cout

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

typedef long double ld;

const int N = int(1e6) + 111;
const ld EPS = 1e-7;

int main () {
  queue <char> q;
    int n;
    in >> n;
    char x;
    int cnt = 0;
    while (in >> x) {
        if (x == '*') {
            if (q.empty()) {
                out << x;
            }
            else {
                out << q.front();
                q.pop();
                cnt--;
            }
        }
        else {
            if (cnt != n) {
                q.push(x);
                cnt++;
            }
            else {
                q.front();
                q.pop();
                q.push(x);
            }
        }
    }
}
*/