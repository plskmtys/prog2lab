/*
 * \file teglalap.cpp
 * (Latin-2 kodolasu fajl. Allitsa at a kodolast,
 *  ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * Egyszerû osztály létrehozása
 */
#include <iostream>

/**
 * Az Ön feladata megvalósítani az egyes tagfüggvényeket.
 * Ahogyan halad a megvalósítással egyre több tesztesetet kell
 * lefuttatni, ezért az ELKESZULT makró értéket folyamatosan növelje a
 * feladatsorszámoknak megfelelõen!
 */
#define ELKESZULT 2

/**
 * Feladatok:
 * 1. ELKESZULT=1
 *    Valósítsa meg (definiálja) a hiányzó tagfüggvényeket! (kerulet(), terulet())
 *
 * 2. ELKESZULT=2
 *    Egészítse ki az osztályt úgy, hogy tömb is létrehozható legyen belõle
 *    (Tipp: tömb csak olyan osztályból példányosítható, aminek van paraméter
 *    nélkül hívható konstruktora)
 *
 */

class Teglalap {
    double a, b;        // oldalak hossza
public:
    Teglalap(double, double);
    Teglalap(); // konstruktor
    void kiir() const;          // kiírja az oldalakat
    double kerulet() const;     // kerület kiszámítása
    double terulet() const;     // terület kiszámítása
};

Teglalap::Teglalap(double a, double b) {
    this->a = a;
    this->b = b;
}

Teglalap::Teglalap(){
  this->a = 0;
  this->b = 0;
}

void Teglalap::kiir() const {
  std::cout << "a:" << a << " b:" << b << std::endl;
}

// ELKESZULT 1
// 1. feladat
double Teglalap::terulet() const {
// Ezt Önnek kell kiegészítenie
  return this->a * this->b;
}

// Itt pedig a kerület számítást kell megvalósítania
double Teglalap::kerulet() const {
  return 2 * (this->a + this->b);
}



int main() {
    Teglalap ta(1,4);
    std::cout << "ta: ";
    ta.kiir();
    Teglalap tb(3,8);
    std::cout << "tb: ";
    tb.kiir();
#if ELKESZULT >= 1
    std::cout << "ta kerülete:" << ta.kerulet() << std::endl;
    std::cout << "tb kerülete:" << tb.kerulet() << std::endl;
    std::cout << "ta területe:" << ta.terulet() << std::endl;
    std::cout << "tb területe:" << tb.terulet() << std::endl;
#endif

#if ELKESZULT >= 2
    const int N = 5;
    Teglalap teglak[N];
    for (int i = 0; i < N; i++) {
        std::cout << "teglak[" << i << "]: ";
        teglak[i].kiir();
    }
#endif
    return 0;
}
