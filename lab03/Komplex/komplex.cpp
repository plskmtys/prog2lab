/**
 * \file komplex.cpp
 *
 * Komplex osztályt megvalósító függvények definíciója.
 *
 * Folytassa a megvalósítást sorrendben a komplex.h fájlban levő feladatoknak megfelelően!
 *
 */


#include <ios>
#include <iostream>         // Valószínű, hogy a kiíráshoz majd kell
#include <iomanip>          // ... és ez is.
#include <cmath>            // az sqrt miatt kell.

#include "komplex.h"        // Ebben van a Komplex osztály, és néhány globális függvény deklarációja

///using namespace std;  // ha nagyon kell, akkor csak itt nyissuk ki a névteret, a headerben soha!

/// Előre elkészített tagfüggvények

/// 0, 1 és 2 paraméteres konstruktor
/// Figyelje meg, hogy a default argumentumokat CSAK a deklarációnál
/// adtuk meg!
Komplex::Komplex(double r, double im) {
    re = r; // ha nincs névütközés, nem kell kiírni a this-t
    this->im = im;
}

///---- Egy példa a konstans tagfüggvényre, ehhez hasonlóan kell
///     elkészíteni a gettereket az 1. feladatban (ELKESZULT=1)
/// Abszolút érték lekérdezése
/// @return - abszolút érték
double Komplex::abs() const { return sqrt(re*re + im*im); }

#if ELKESZULT >= 3
// 3. feladathoz (ELKESZULT 3)
// összehasonlítás
/// Egyenlőtlenség vizsgálat
/// @param rhs_k - jobb oldali operandus (Komplex)
/// @return hamis - ha a képzetes és a valós rész is azonos, egyébként false

bool Komplex::operator==(const Komplex& rhs_k) const {
  if(re == rhs_k.re && im == rhs_k.im) return true;
  return false;
}

bool Komplex::operator!=(const Komplex& rhs_k) const {  // visszavezetjük az egyenlőség vizsgálatra
    return !(*this == rhs_k);
}
#endif

#if ELKESZULT >= 6
// 6. feladathoz (ELKESZULT 6)
// a += művelet viszont módosítja önmagát!
/// Komplex + double
/// @param rhs_d - jobb oldali operandus (double)
/// @return eredeti (bal oldali) objektum ref., amihez hozzáadtuk rhd_d-t
Komplex& Komplex::operator+=(double rhs_d) {
    re += rhs_d;
    return *this;
}

Komplex& Komplex::operator+=(const Komplex& z2) {
  re += z2.getRe();
  im += z2.getIm();
  return *this;
}

#endif

// ------------------------ Eddig elkészítettük -------------------------
// TODO: A hiányzó tag- és globális függvények itt következnek

double Komplex::getRe() const {
  return this->re;
}

double Komplex::getIm() const{
  return this->im;
}

void Komplex::setRe(double r){
  this->re = r;
}

void Komplex::setIm(double i){
  this->im = i;
}

Komplex Komplex::operator+(const Komplex& z2) const {
  return Komplex(getRe() + z2.getRe(), getIm() + z2.getIm());
}

Komplex Komplex::operator+(const double a) const {
  return Komplex(getRe() + a, getIm());
}

Komplex Komplex::operator~() const {
  return Komplex(this->getRe(), -1 * this->getIm());
}


std::ostream& operator<<(std::ostream& os, const Komplex& rhs_k){
  os << rhs_k.getRe() << std::showpos << rhs_k.getIm() << std::noshowpos << 'j';
  return os;
}

std::istream& operator>>(std::istream& is, Komplex& rhs_k){
  double r, i;
  char op, j;
  is >> r;
  is >> op;
  is >> i;
  is >> j;
  if(op == '-') i*=-1;
  std::cout << i << std::endl;
  rhs_k.setRe(r);
  rhs_k.setIm(i);
  return is;
}

// (a + ib) (c + id) = (ac - bd) + i(ad + bc)
Komplex Komplex::operator*(const Komplex& rhs_k) const {
    double real_part = getRe() * rhs_k.getRe() - getIm() * rhs_k.getIm();
    double imag_part = getRe() * rhs_k.getIm() + getIm() * rhs_k.getRe();
    return Komplex(real_part, imag_part);
}



Komplex Komplex::operator*(double rhs_d) const{
  return Komplex(getRe() * rhs_d, getIm() * rhs_d);
}
 
Komplex& Komplex::operator*=(const Komplex& rhs_k) {
  *this = *this * rhs_k;
  return *this;
}

Komplex& Komplex::operator*=(double rhs_d) {
  *this = *this * rhs_d;
  return *this;
}

Komplex operator+(double lhs_d, const Komplex& rhs_k){
  return Komplex(rhs_k.getRe() + lhs_d, rhs_k.getIm());
}
