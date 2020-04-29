//
// @author: Nikita 
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

class Toy {
private:
    string manufacturer;
    string model;
    int age_1;
    int age_2;
    static int total;
public:
    Toy() {
        total++;
    }
    Toy(int x): age_1(x) {}
    ~Toy() {
        total--;
    }
    static void show_total() {
        cout << total << endl;
    }
    void get_manufacturer(string s) {
        this->manufacturer = s;
    }
    void print_manufacturer() {
        cout << this->manufacturer << endl;
    }
    void get_model(string s) {
        this->model = s;
    }
    void print_model() {
        cout << this->model << endl;
    }
    void get_age(int x, int y) {
        this->age_1 = x;
        this->age_2 = y;
    }
    void print_age() {
        cout << age_1 << " " << age_2 << endl;
    }
    void print() {
        cout << "Производитель: " << this->manufacturer << endl;
        cout << "Модель: " << this->model << endl;
        cout << "Возраст от: " << this->age_1 << " до: " << this->age_2 << endl;
    }
    bool operator < (Toy t) {
        return manufacturer < t.manufacturer;
    }
    bool operator > (Toy t) {
        return manufacturer > t.manufacturer;
    }
    bool operator == (Toy t) {
        if (manufacturer!=t.manufacturer) {
            return model == t.model;
        }
        else {
            return manufacturer == t.manufacturer;
        }

    }
    bool operator != (Toy t) {
        return manufacturer != t.manufacturer;
    }
    friend bool operator == (const Toy& q, const Toy& q1);


};
/*bool operator == (const Toy& q, const Toy& q1) {
    if (q.manufacturer == q1.manufacturer) {
        return q.model == q1.model;
    }
    else {
        return q.manufacturer == q1.manufacturer;
    }

}*/
int Toy::total = 0;

int main () {
    Toy t;
    t.get_manufacturer("Lego");
    t.get_model("big_constructor");
    t.get_age(0,12);
    Toy z;
    z.get_manufacturer("Lego");
    z.get_model("little_constructor");
    z.get_age(5,12);
    t.print();
    z.print();
    if (z != t) {
        cout << "Yes" << endl;
    }
    else {
        cout << "N0" << endl;
    }
}
