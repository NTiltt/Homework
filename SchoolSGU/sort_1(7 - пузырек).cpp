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


#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define forn(i, n) fore(i, 0, n)
#define pb push_back
#define x first
#define y second
#define mp make_pair

using namespace std;


ifstream in("/Users/nikita/Documents/Atom/input.txt");
ofstream out("/Users/nikita/Documents/Atom/output.txt");

const int N = int(1e6) + 111;
struct student {
     string fam,name,secondname;
     int year;
     int ses[5];
     double key;
     void print();
};
void student::print() {
     out << fam << " " << name << " " << secondname << " " << year << " ";
     forn(i,5) {
          out << ses[i] << " ";
     }
     out << endl;
}
void sort (student *a, int n) {
     student temp;
     forn(i,n - 1) {
          for (int j = n - 1; j > i; j--) {
               if (a[j].key > a[j - 1].key) {
                    temp = a[j];
                    a[j] = a[j - 1];
                    a[j - 1] = temp;
               }
          }
     }
}

int main () {
     student mas[10000];
     int num;
     in >> num;
     int n = 0;
     while (in.peek() != EOF) {
          in >> mas[n].fam;
          in >> mas[n].name;
          in >> mas[n].secondname;
          in >> mas[n].year;
          forn(j,5) {
               in >> mas[n].ses[j];
               mas[n].key += mas[n].ses[j];
          }
          n++;
     }
     n--;
     sort(mas,n);
     out << num << endl;
     forn(i,n) {
          mas[i].print();
     }
}

/*
                         Тестовые примеры.

     1)
     Ввод:
     121
     Абрамирова Анна Дмитриевна 1992 4 4 3 3 3
     Иван Иван Иванович 1984 5 5 2 2 5
     Буванова Нина Юрьевна 1990 5 4 5 5 5
     Акимова Варвара Сергеевна 2000 1 1 1 1 1

     Вывод:
     121
     Буванова Нина Юрьевна 1990 5 4 5 5 5
     Иван Иван Иванович 1984 5 5 2 2 5
     Абрамирова Анна Дмитриевна 1992 4 4 3 3 3
     Акимова Варвара Сергеевна 2000 1 1 1 1 1

     2) Ввод:
     121
     Абрамирова Анна Дмитриевна 1992 4 4 3 3 3
     Иван Иван Иванович 1984 5 5 2 2 5
     Буванова Нина Юрьевна 1990 5 4 3 4 4
     Акимова Варвара Сергеевна 2000 1 2 2 1 2

     Вывод:
     121
     Буванова Нина Юрьевна 1990 5 4 3 4 4
     Иван Иван Иванович 1984 5 5 2 2 5
     Абрамирова Анна Дмитриевна 1992 4 4 3 3 3
     Акимова Варвара Сергеевна 2000 1 2 2 1 2 


*/
