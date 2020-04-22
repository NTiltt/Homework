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

ifstream in("/Users/nikita/Documents/Clion/Homework/SchoolSGU/input.txt");
ofstream out("/Users/nikita/Documents/Clion/Homework/SchoolSGU/output.txt");

typedef long double ld;

const int N = int(1e6) + 111;
const ld EPS = 1e-7;

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

int main () {
    vector <student> mas(10);
    int num;
    in >> num;
    int n = 0;
    while (in.peek() != EOF) {
        in >> mas[n].fam;
        in >> mas[n].name;
        in >> mas[n].secondname;
        in >> mas[n].year;
        forn(j, 5) {
            in >> mas[n].ses[j];
            mas[n].key += mas[n].ses[j];
        }
        n++;
    }
    mas.resize(n);
    sort(all(mas),[](student &s1, student &s2) {
        return s1.key > s2.key;
    });
    out << num << endl;
    forn(i,sz(mas)) {
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
