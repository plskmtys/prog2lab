/**
 * \file resistor.cpp
 *   (UTF-8 kodolasu fajl. Allitsa at a megjenetes kodolasat,
 *    ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * Ohmikus ellenállást modellező osztály megvalósítása
 */

/**
 * Itt kell megvalósítani a resistor.h-ban deklarált nem inline függvényeket.
 * A Jportára ezt a fájlt kell feltölteni.
 */

#include "resistor.h"
#include <limits>
#include <cmath>
#include <ostream>

double Resistor::defR = 104;

void Resistor::setDef(double r){
  Resistor::defR = r;
  Pr("ctor1");
}

Resistor::Resistor() {
  R = Resistor::defR;
  Pr("ctor0");
}

Resistor::Resistor(double d) {
  R = d;
}

Resistor Resistor::operator+(const Resistor& r) const {
  return Resistor(getR() + r.getR());
}

Resistor Resistor::operator%(const Resistor& r) const {
  return Resistor(1.0 / (1.0 / getR() + 1.0 / r.getR()));
}

Resistor operator*(int n, const Resistor& r){
  if(n <= 0) throw "EM0G6P";
  return Resistor(n * r.getR());
}

Resistor::Resistor(const Resistor& rhs){
  R = rhs.getR();
  Pr("copy");
}

Resistor::~Resistor(){
  Pr("dtor");
}

Resistor& Resistor::operator=(const Resistor& rhs){
  this->R = rhs.getR();
  Pr("assign");
  return *this;
}

double Resistor::getI(double u) const{
  return u/getR();
}

double Resistor::getU(double i) const{
  return getR() * i;
}

template <typename T>
bool almostEQ(T a, T  b) {
    // eps: ha a relatív, vagy abszolút hiba ettől kisebb, akkor elfogadjuk
    T eps = 10 * std::numeric_limits<T>::epsilon(); // 10-szer a legkisebb érték
    if (a == b) return true;
    if (fabs(a - b) < eps)
       return true;
    double aa = fabs(a);
    double ba = fabs(b);
    if (aa < ba) {
        aa = ba;
        ba = fabs(a);
    }
    return (aa - ba) < aa * eps;
}

bool Resistor::operator==(const Resistor& r) const{
  if(almostEQ(getR(), r.getR())) return true;
  return false;
}

std::ostream& operator<<(std::ostream& os, const Resistor& rhs){
  os << rhs.getR();
  return os;
}
