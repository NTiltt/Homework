//
// Created by Никита Ясеник on 27.04.2020.
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

class Queue {
struct Element {
    int inf;
    Element *next;
    Element(int x) : inf(x), next(0) {}
};
Element *head, *tail;
public:
    Queue(): head(0), tail(0) {}
    friend ostream& operator<<(ostream &out, const Queue &q) {
        for (Element *cur = q.head; cur !=0; cur = cur->next) {
            out << cur->inf << ' ';
        }
        return out;
    }
    bool empty() {
        return head == 0;
    }
    int get() {
        Element *t = head;
        int i = t -> inf;
        head = t -> next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete t;
        return i;
    }
    void push(int x) {
        Element *t = tail;
        tail = new Element(x);
        if (!head) {
            head = tail;
        }
        else {
            t->next = tail;
        }
    }
    void pop() {
        Element *cur;
        cur = head;
        head = head -> next;
        delete cur;
    }
    void read(int n) {
        forn(i,n) {
            int x;
            cin >> x;
            this -> push(x);
        }
    }
};

int main () {
    Queue q;
    q.read(5);
    q.pop();
    q.push(5);
    cout << q;
}
