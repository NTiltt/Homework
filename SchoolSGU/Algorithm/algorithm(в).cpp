//
// Created by Никита Ясеник on 26.04.2020.
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

using namespace std;

//ifstream in("/Users/nikita/Documents/Atom/input.txt");
//ofstream out("/Users/nikita/Documents/Atom/output.txt");

typedef long double ld;

const int N = int(1e6) + 111;
const ld EPS = 1e-7;

double len(int x, int y) {
    return sqrt(x*x + y*y);
}
bool cmp(pair<int,double>p1,pair<int,double>p2) {
    return p1.y > p2.y;
}

int main () {
    vector <pair<int,double>> v;
    vector <pair<int,int>> q;
    int n;
    cin >> n;
    forn(i,n) {
        int a,b;
        cin >> a >> b;
        q.pb(mp(a,b));
        v.pb(mp(i,len(a,b)));
    }
    sort(all(v),cmp);
    double w = v[0].y;
    auto ind = find_if(all(v),[w](pair<int,double> p) {
        return p.y != w;
    });
    v.erase(ind,v.end());
    forn(i,sz(v)) {
        cout << q[v[i].x].x << " " << q[v[i].x].y << endl;
    }
}
 */
/*
 *                                  Тестовые примеры:
 *                1) 5
 *                   1 2
 *                   2 1
 *                   4 4
 *                   5 5
 *                   5 5
 *                   Вывод:
 *                   5 5
 *                   5 5
 *
 *                  2) 5
 *                      2 1
 *                      1 2
 *                      0 1
 *                      1 0
 *                      2 1
 *                      Вывод:
 *                      2 1
 *                      1 2
 *                      2 1
 *
 * */