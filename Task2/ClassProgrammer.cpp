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

     void info() {
          cout << endl;
          cout << "Name: " << this -> name << endl;
          cout << "Experience: " << this -> experience << endl;
          cout << "Level: " << this -> level << endl;
          cout << endl;
     }
     void SetName(string name) {
          this->name = name;
          cout << "Имя успешно изменено.";
          cout << endl;
     }
     void SetExpirience(int experience) {
          this -> experience = experience;
          cout << "Стаж успешно изменен.";
          cout << endl;
     }
     void SetLevel(string level) {
          this -> level = level;
          cout << "Уровень успешно изменен.";
          cout << endl;
     }
     void LevelUp() {
          cout << endl;
          cout << "Текущий level программиста " << this -> name << ": " << this->level << endl;
          if (this->level == "junior") {
               cout << "Хотите повысить программиста: " << this->name << " до level: middle?" << endl;
               metka1:cout << "(Введите да, или нет): ";
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
                         cout << "Программист: "  << this -> name << " достиг наивысшего уровня! ПОЗДРАВЛЯЕМ!" << endl;
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
               else {
                    if (s == "нет") {
                         cout << "Может быть до level: senior?" << endl;
                         metka2:cout << "(Введите да, или нет): ";
                         string s2;
                         cin >> s2;
                         cout << endl;
                         if (s2 == "да") {
                              this -> level = "senior";
                              cout << "Программист: "  << this -> name << " достиг наивысшего уровня! ПОЗДРАВЛЯЕМ!" << endl;
                              cout << "Текущий level: " << this -> level << endl;
                         }
                         else {
                              if (s2 == "нет") {
                                   cout << "Значит в другой раз!" << endl;
                                   cout << "Текущий level: " << this -> level << endl;
                              }
                              else {
                                   cout << "Повторите попытку :)";
                                   goto metka2;
                              }
                         }
                    }
                    else {
                         cout << "Повторите попытку :)";
                         goto metka1;
                    }
               }
          }
          else if (this -> level == "middle") {
               cout << "Хотите повысить программиста: " << this->name << " до level: senior?" << endl;
               metka4:cout << "(Введите да, или нет): ";
               string s1;
               cin >> s1;
               cout << endl;
               if (s1 == "да") {
                    this->level = "senior";
                    cout << "Программист: "  << this -> name << " достиг наивысшего уровня! ПОЗДРАВЛЯЕМ!" << endl;
                    cout << "Текущий level: " << this -> level << endl;
               }
               else {
                    if (s1 == "нет") {
                         cout << "Значит в другой раз!" << endl;
                         cout << "Текущий level: " << this -> level << endl;
                    }
                    else {
                         cout << "Повторите попытку :)";
                         goto metka4;
                    }

               }
          }
          else {
               cout << "Программист: " << this -> name << " уже достиг наивысшего уровня." << endl;
          }
     }
     void Kod(int x) {
          cout << "Программист: " << this -> name << " написал программу состоящую из " << x << " строк." << endl;
     }
     void search_bug() {
          srand(time(NULL));
          cout << endl;
          if (this->level == "junior") {
               cout << "Ваш программист смог исправить: " << rand() % 100 <<" багов." << endl;
          }
          else {
               if (this->level == "middle") {
                    cout << "Ваш программист смог исправить: " << rand() % 200 <<" багов." << endl;
               }
               else {
                    if (this -> level == "senior") {
                         cout << "Ваш программист смог исправить: " << rand() % 500 <<" багов." << endl;
                    }
               }
          }

     }

};

int main () {
     Programmer p;
     cout << "Введите имя вашего программиста: ";
     string name;
     cin >> name;
     p.SetName(name);
     cout << "Введите стаж вашего программиста: ";
     int cnt;
     cin >> cnt;
     p.SetExpirience(cnt);
     cout << "Выберите уровень вашего программиста: " << endl;
     cout << "1 - junior " << endl;
     cout << "2 - middle " << endl;
     cout << "3 - senior " << endl;
     metka5:cout << "Введите 1,2 или 3: ";
     int x;
     cin >> x;
     if (x == 1) {
          p.SetLevel("junior");
     }
     else {
          if (x == 2) {
               p.SetLevel("middle");
          }
          else {
               if (x == 3) {
                    p.SetLevel("senior");
               }
               else {
                    cout << "Повторите попытку:)";
                    cout << endl;
                    goto metka5;
               }
          }
     }
     cout << endl;
     cout << "Ваш программист:";
     p.info();
     metka9:cout << "Если хотите что-то поменять введите: 1,  иначе: 0." << endl;
     int q;
     metka6:
     cout << "Введите 1 или 0: ";
     cin >> q;
     if (q == 1) {
          cout << "Если хотите поменять 'name' введите - 1, 'level' - 2, 'experience' - 3 " << endl;
          int k;
          metka7:cout << "Введите 1,2 или 3: ";
          cin >> k;
          if (k == 1) {
               cout << "Введите новое имя: ";
               string s3;
               cin >> s3;
               p.SetName(s3);
               p.info();
               goto metka9;
          }
          else {
               if (k == 3) {
                    cout << "Введите новый стаж: ";
                    int x2;
                    cin >> x2;
                    p.SetExpirience(x2);
                    p.info();
                    goto metka9;
               }
               else {
                    if (k == 2) {
                         p.LevelUp();
                         goto metka9;
                    }
                    else {
                         cout << "Повторите попытку)";
                         goto metka7;
                    }
               }
          }
     }
     else {
          if (q == 0) {

          }
          else {
               cout << "Повторите попытку:)";
               cout << endl;
               goto metka6;
          }
     }
     p.LevelUp();
     cout << "Введите число строк, которое необходимо написать вашему программисту: ";
     int kol;
     cin >> kol;
     cout << endl;
     p.Kod(kol);
     p.search_bug();
}
