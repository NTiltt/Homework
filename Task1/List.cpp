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


#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define forn(i, n) fore(i, 0, n)
#define pb push_back
#define x first
#define y second
#define mp make_pair

using namespace std;

//ifstream in("/Users/nikita/Documents/Atom project/input.txt");
//ofstream out("/Users/nikita/Documents/Atom project/output.txt");

typedef long double ld;

const int N = int(1e6) + 111;
const ld EPS = 1e-7;

template <class Item> class List {
     struct Element {
          Item inf;
          Element *next;
          Element(Item x, Element* ref = NULL) : inf(x), next(ref) {}
     };
     Element *last;
     Element *head;
     int size;
     Element *find(int ind) {
          if (ind < 1 || ind > size) {
               return NULL;
          }
          else {
               Element *cur = head;
               for (int i = 1; i < ind; i++) {
                    cur = cur -> next;
               }
               return cur;
          }
     }
     public:
          List()
               : head(0), size(0), last(0)
          {}
          ~List() {
               while (!Empty()) {
                    remove(1);
               }
          }
          bool Empty() {
               return head == 0;
          }
          int len() {
               return size;
          }
          Item get(int ind) {
               Element *r = find(ind);
               Item i = r -> inf;
               return i;
          }
          void remove(int ind) {
               Element *cur;
               if (ind == 1) {
                    cur = head;
                    head = head -> next;
               }
               else {
                    Element *prew = find(ind - 1);
                    cur = prew -> next;
                    prew -> next = cur -> next;
               }
               cur -> next = NULL;
               delete cur;
               size--;
          }
          void print() {
               for (Element *cur = head; cur != 0; cur = cur -> next) {
                    cout << cur -> inf << " ";
               }
               cout << endl;
          }
          void insert(int ind, Item data) {
               Element *newPtr = new Element(data);
               size++;
               if (ind == 1) {
                    newPtr -> next = head;
                    head = newPtr;
               }
               else {
                    Element *prev = find(ind - 1);
                    newPtr -> next = prev -> next;
                    prev -> next = newPtr;
               }
          }
          void add(Item x) {
               size++;
               Element *item = new Element(x);
               if (last != NULL) {
                    last->next = item;
               }
               last = item;
               if (head == NULL) {
                    head = last;
               }
          }
          void read(int n) {
               forn(i,n) {
                    int x;
                    cin >> x;
                    this -> add(x);
               }
          }
          int find_min() {
               int n = 2;
               int ind = 1;
               Element *r = find(1);
               Item m = r -> inf;
               for (Element *cur = head + 1; cur != 0; cur = cur -> next) {
                    if (cur -> inf < m) {
                         m = cur -> inf;
                         ind = n;
                    }
                    n++;
               }
               return ind;
          }
};

int main() {
     int n;
     cin >> n;
     List <int> l;
     l.read(n);
     int ind = l.find_min();
     if (ind == 1) {
          l.insert(1,0);
          l.insert(3,0);
     }
     else {
          if (ind == n) {
               l.insert(n,0);
               l.add(0);
          }
          else {
               l.insert(ind, 0);
               l.insert(ind + 2, 0);
          }

     }
     l.print();

}
