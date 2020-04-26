//
// Created by Никита Ясеник on 26.04.2020.
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

using namespace std;

//ifstream in("/Users/nikita/Documents/Atom/input.txt");
//ofstream out("/Users/nikita/Documents/Atom/output.txt");

typedef long double ld;

const int N = int(1e6) + 111;
const ld EPS = 1e-7;

int main () {
    vector <pair<int,int>> v;
    int n;
    cin >> n;
    forn(i,n) {
        int a,b;
        cin >> a >> b;
        v.pb(mp(a,b));
    }
    int cnt = count_if(all(v),[](pair<int,int> p) {
        return p.y > p.x;
    });
    cout << cnt << endl;
}
