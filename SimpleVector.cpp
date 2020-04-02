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

//ifstream in("/Users/nikita/Documents/Atom project/input.txt");
//ofstream out("/Users/nikita/Documents/Atom project/output.txt");

typedef long double ld;

const int N = int(1e6) + 111;
const ld EPS = 1e-7;

class SimpleVector {
private:
     int *mas;
     int n,m;
     static int cnt;
public:
     SimpleVector() {};
     SimpleVector(int n) {
          mas = new int [n];
          this -> n = n;
     }
     void read() {
          cnt = 0;
          forn(i,n) {
               cin >> mas[i];
               cnt++;
          }
     }
     void read(int m) {
          cnt = 0;
          forn(i,m) {
               cin >> mas[i];
               cnt++;
          }
     }
     int len() {
          return cnt;
     }
     void print() {
          forn(i,cnt) {
               cout << mas[i] << " ";
          }
          cout << endl;
     }
     int push_back(int x) {
          if (cnt < n) {
               mas[cnt] = x;
               cnt++;
          }
          else {
               int *newArray = new int [this -> n * 2];
               forn(i,this->n) {
                    newArray[i] = mas[i];
               }
               newArray[this->n] = x;
               cnt++;
               this -> n *= 2;
               delete[] mas;
               mas = newArray;
          }

     }
     int& operator [] (int ind);
     int find(int x) {
          forn(i,n) {
               if (mas[i] == x) {
                    return i;
               }
          }
          return -1;
     }
     bool remove(int x) {
          if (find(x) != -1) {
               for (int i = find(x); i < n - 1; i++) {
                    mas[i] = mas[i + 1];
               }
               n--;
               cnt--;
               return true;
          }
          else {
               return false;
          }

     }
     bool insert_after(int x, int y) {
          if (find(x) != -1) {
               if (cnt < n) {
                    for (int i = n - 1; i > find(x); i--) {
                         mas[i] = mas[i - 1];
                    }
                    mas[find(x) + 1] = y;
                    cnt++;
                    this -> n++;
                    return true;
               }
               else {
                    int *newArray = new int [this -> n + 1];
                    forn(i,this -> n) {
                         newArray[i] = mas[i];
                    }
                    delete[] mas;
                    mas = newArray;
                    for (int i = n; i > find(x); i--) {
                         mas[i] = mas[i - 1];
                    }
                    mas[find(x) + 1] = y;
                    cnt++;
                    this -> n++;
                    return true;
               }
          }
          else return false;
     }

};
int& SimpleVector::operator [](int ind) {
     return mas[ind];
}
int SimpleVector::cnt = 0;

int main() {
     int n,m;
     cout << "Введите размер массива: ";
     cin >> n;
     SimpleVector v(n);
     cout << "Введите количество элементов в массиве: ";
     cin >> m;
     cout << "Введите " << m << " чисел: " << endl;
     v.read(m);
     cout << "Введите значение, которое необходимо добавить в конец массива: ";
     int x;
     cin >> x;
     v.pb(x);
     v.print();
     metka:cout << "Введите индекс элемента: ";
     int num;
     cin >> num;
     if (num > v.len() - 1) {
          cout << "Такого индекса в массиве нет, попробуйте еще раз)" << endl;
          goto metka;
     }
     else {
          cout << "Элемент с индексом " << num << " равен: " << v[num] << endl;
     }
     metka1: cout << "Введите значение, которое хотите найти: ";
     int k;
     cin >> k;
     if (v.find(k) == -1) {
          cout << "Такого элемента в массиве нет:(" << endl;
          cout << "Попробуйте еще раз." << endl;
          goto metka1;
     }
     else {
          cout << "Индекс элемента " << k << " равен: " << v.find(k) << endl;
     }
     metka2:cout << "Введите значение которое хотите удалить: ";
     int k1;
     cin >> k1;
     if (v.find(k1) != -1) {
          v.remove(k1);
          v.print();
     }
     else {
          cout << "Такого элемента в массиве нет, попробуйте еще раз." << endl;
          goto metka2;
     }
     metka3:cout << "Введите два числа(после которого добавить, и что добавить): ";
     int x1,y1;
     cin >> x1 >> y1;
     if (v.find(x1) != -1) {
          v.insert_after(x1,y1);
          cout << "Всё получилось." << endl;
          v.print();
     }
     else {
          cout << "Такого элемента в массиве нет, попробуйте еще раз" << endl;
          goto metka3;
     }

}
