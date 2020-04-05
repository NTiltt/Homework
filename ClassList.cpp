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
          Element(Item x) : inf(x), next(0) {}
     };
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
               : head(0), size(0)
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
                    out << cur -> inf << " ";
               }
               out << endl;
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
};

int main () {


}
