/**
 *  \file rajztabla.cpp
 *   Ebben a fájlban valósítsa meg a Rajztábla osztály nem inline tagfüggvényeit
 */


#include "rajztabla.h"

void Rajztabla::felrak(Alakzat *ap){
  if(db == MAXDB) throw "ez mar tobb a soknal";
  tabla[db++] = ap;
}

/// Kirajzolja az összes alakzatot
void Rajztabla::rajzol() const {
  for(size_t i = 0; i < db; ++i) tabla[i]->rajzol(); 
}

/// Az összes alakzatot elmozdítja
/// @param d - eltolás vektora
void Rajztabla::mozgat(const Pont& d) const {
  for(size_t i = 0; i < db; ++i) tabla[i]->mozgat(d);
}

void Rajztabla::torol(){
  for(size_t i = 0; i < db; ++i) delete tabla[i];
  db = 0;
}

Rajztabla::~Rajztabla(){
  torol();
}

std::ostream& operator<<(std::ostream& os, const Rajztabla& t){
  return os << t.size() << std::endl;
}
