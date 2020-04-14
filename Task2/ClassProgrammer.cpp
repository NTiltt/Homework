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

typedef long double ld;

const int N = int(1e6) + 111;
const ld EPS = 1e-7;


class Programmer {
private:
     string name;
     int experience;
     string level;
public:
     Programmer() {}
     Programmer(string name, int experience, string level): name(name), experience(experience), level(level) {}

     void print() {
          cout << name << " " << experience << " " << level << endl;
     }
     void SetName(string name) {
          this->name = name;
     }
     void SetExpirience(int experience) {
          this -> experience = experience;
     }
     void SetLevel(string level) {
          this -> level = level;
     }
     void LevelUp() {
          cout << "Текущий level: " << this->level << endl;
          if (this->level == "junior") {
               cout << "Хотите повысить программиста: " << this->name << " до level: middle?" << endl;
               cout << "(Введите да, или нет): ";
               string s;
               cin >> s;
               cout << endl;
               if (s == "да") {
                    this->level = "middle";
                    cout << "Level программиста: " << this -> name << " повышен, поздравляю!" << endl;
                    cout << "Текущий level: " << this -> level << endl;
                    cout << endl;
                    cout << "Хотите повысить программиста: " << this->name << " до level: senior?" << endl;
                    metka:cout << "(Введите да, или нет): ";
                    string s1;
                    cin >> s1;
                    cout << endl;
                    if (s1 == "да") {
                         this->level = "senior";
                         cout << "Программист: "  << this -> name << "достиг наивысшего уровня! ПОЗДРАВЛЯЕМ!" << endl;
                         cout << "Текущий level: " << this -> level << endl;
                    }
                    else {
                         if (s1 == "нет") {
                              cout << "Значит в другой раз!" << endl;
                              cout << "Текущий level: " << this -> level << endl;
                         }
                         else {
                              cout << "Повторите попытку :)";
                              goto metka;
                         }

                    }

               }
          }
     }

};

int main () {
     Programmer p;
     p.SetName("Nikita");
     p.SetLevel("junior");
     p.LevelUp();


}
