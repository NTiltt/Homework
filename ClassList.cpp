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
          Element(Item x, Element* ref = nullptr) : inf(x), next(ref) {}
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
               : head(nullptr), size(0), last(nullptr) {};
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
               size--;
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
          }
          void print() {
               for (Element *cur = head; cur != NULL; cur = cur -> next) {
                    cout << cur -> inf << " ";
               }
               cout << endl;
          }
          void insert(int ind, Item data) {
               Element *newPtr = new Element(data);
               size = len() + 1;
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
               if (last != nullptr) {
                    last->next = item;
               }
               last = item;
               if (head == nullptr) {
                    head = last;
               }
          }
          void doubleX(Item x) {
               for (Element *t = head; t!= nullptr; t = t -> next) {
                    if (t -> inf == x) {
                         size++;
                         Element *newElement = new Element(x, t -> next);
                         t -> next = newElement;
                         t = t -> next;
                    }
               }
          }
          void del(Item x) {
               int n = 1;
               for (Element *t = head; t != nullptr; t = t -> next) {
                    if (t -> inf == x && n != 1) {
                         remove(n - 1);
                    }
                    else {
                         n++;
                    }
               }
          }
          List ret(Item x) {
               List <Item> l1;
               int n = 2;
               for (Element *t = head + 1; t != nullptr; t = t -> next) {
                    if (t -> inf == x) {
                         l1.add(t -> inf);   
                         n++;
                    }
                    else {
                         Element *r = find(n - 1);
                         Item i = r -> inf;
                         l1.add(i);
                         l1.add(t -> inf);
                         n++;
                    }
               }
               return l1;
          }
};

int main () {
     List <int> l;
     List <int> lst;
     l.add(5);
     l.add(2);
     l.add(3);
     l.add(5);
     l.add(4);
     l.add(5);
     lst = l.ret(5);
     l.print();


}
