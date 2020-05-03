//
// @author: Nikita 
//

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
#define in cin
#define out cout


using namespace std;

//ifstream in("/Users/nikita/Documents/Atom/input.txt");
//ofstream out("/Users/nikita/Documents/Atom/output.txt");

typedef long double ld;

const int N = int(1e6) + 111;
const ld EPS = 1e-7;


int main () {
    string s;
    list<char> s1;
    list<char> s2;
    list<char> lst;
    cin >> s;
    forn(i,sz(s)) {
        lst.pb(s[i]);
    }
    forn(i,sz(s)) {
        int x;
        char c;
        cin >> c >> x;
        if (x == 1) {
            int cnt = 0;
            while (lst.back() != c) {
                s2.pb(lst.back());
                lst.pop_back();
                cnt++;
            }
            s1.push_front(lst.back());
            lst.pop_back();
            while (cnt > 0) {
                lst.pb(s2.back());
                s2.pop_back();
                cnt--;
            }
            cout << "На рельсах: ";
            for (auto el : lst) {
                cout << el << " ";
            }
            cout << endl;
            cout << "В тупике №1: ";
            for (auto el : s1) {
                cout << el << " ";
            }
            cout << endl;
            cout << "В тупике №2: ";
            for (auto el : s2) {
                cout << el << " ";
            }
            cout << endl;
        }
        else {
            int cnt = 0;
            while (lst.back() != c) {
                s1.pb(lst.back());
                lst.pop_back();
                cnt++;
            }
            s2.push_front(lst.back());
            lst.pop_back();
            while (cnt > 0) {
                lst.pb(s1.back());
                s1.pop_back();
                cnt--;
            }
            cout << "На рельсах: ";
            for (auto el : lst) {
                cout << el << " ";
            }
            cout << endl;
            cout << "В тупике №1: ";
            for (auto el : s1) {
                cout << el << " ";
            }
            cout << endl;
            cout << "В тупике №2: ";
            for (auto el : s2) {
                cout << el << " ";
            }
            cout << endl;
        }
    }
}
