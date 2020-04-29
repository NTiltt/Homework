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

//ifstream in("input.txt");
//ofstream out("output.txt");

typedef long double ld;

const int N = int(1e6) + 111;
const ld EPS = 1e-7;

int main () {
    stack <char> s;
    stack <char> s1;
    string str;
    getline(in,str);
    forn(i,sz(str)) {
        if (s.empty()) {
            if (str[i] == '#') {
                continue;
            }
            else {
                s.push(str[i]);
                continue;
            }
        }
        if (str[i] == '#') {
            s.pop();
        }
        else {
            s.push(str[i]);
        }
    }
    while (!s.empty()) {
        s1.push(s.top());
        s.pop();
    }
    while (!s1.empty()) {
        out << s1.top();
        s1.pop();
    }
}
