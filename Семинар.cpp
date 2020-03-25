#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <iterator>
#include <sstream>

#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define forn(i, n) fore(i, 0, n)
#define pb push_back
#define x first
#define y second
#define mp make_pair

using namespace std;

typedef long double ld;
const int N = int(1e6) + 111;
const ld PI = 3.141592653589793238462643;

class Triangle {
     int a, b, c;
     public:
          Triangle() : a(0), b(0), c(0) {};
          Triangle(int a) : a(a), b(a), c(a) {};
          Triangle(int a, int b, int c) : a(a), b(b),c(c) {};
          bool setsize(int a, int b, int c) {
               if (a + c > b && a + b > c && b + c > a) {
                    this -> c = c;
                    this -> a = a;
                    this -> b = b;
                    return true;
               }
               else return false;
          }
          void print() {
               cout << a << " " << b << " " << c << endl;
          }
          int per(int a, int b, int c) {
               return a + b + c;
          }
          int per(int a) {
               return 3*a;
          }
          double area(int a, int b, int c) {
               double p = double(per(a,b,c)) / 2;

               return sqrt(p*(p - a)*(p - b)*(p - c));
          }
};
class Circle {
     int x,y;
     int r;
public:
     Circle() : x(0), y(0), r(0) {};
     Circle(int x, int y, int r) {};
     void print(int r) {
          cout << "X^2" << " " << "+" << " " << "Y^2 = " << r*r << endl;
     }
     double len(int r) {
          return 2*PI*r;
     }

};

int main () {
     Triangle s(5);           //Равносторонний треугольник
     Triangle w(5,3,8);
     Triangle t;
     int a,b,c;
     cout << "Введите размеры треугольника: " << endl;
     cin >> a >> b >> c;
     if (t.setsize(a,b,c)) {
          cout << "Треугольник существует." << endl;
     }
     else {
          cout << "Треугольник не существует." << endl;
          return 0;
     }
     cout << "Периметр треугольника равен: " << t.per(a,b,c) << endl;
     cout << endl;
     cout << "Площадь треугольника равна: "<<  t.area(a,b,c) << endl;
     Circle q;
     int x,y,r;
     cout << "Введите координаты центра и радиус окружности: " << endl;
     cin >> x >> y >> r;
     cout << "Ваша окружность: ";
     q.print(r);
     cout << endl;
     cout << "Длина окружности равна: " << q.len(r) << endl;

}
