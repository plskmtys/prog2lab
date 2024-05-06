#include <cstddef>
#include <stdexcept>
#include "point.h"


#define ELKESZULT 4
#ifndef MYSET_H
#define MYSET_H

template<typename T>
bool equal(const T& a, const T& b){
  return a == b;
}

template<>
bool equal(const Point& a, const Point& b){
  return a.getX() == b.getX();
}

template<typename T, unsigned int maxsiz = 10>
class Set {
  size_t siz;
	T t[maxsiz];            // elemek tömbje
public:
    // minden default tagfüggvény jó, nem kell átdefiniálni
  class iterator;	        // elõdeklaráció

    /// Konstruktor T-ket tartalmazó tömbből
    /// @param p  - poninter T elemeket tartalmazó tömb elejére
    /// @param pe - poninter a tömb utolsó eleme után
  Set(T *p, T*pe): siz(0) {	    // két pointer közötti elemekbõl inicializaló konstruktor
   for (unsigned int i = 0; p != pe && i < maxsiz; i++){
    t[i] = *p++;
    siz++;
   }
  
  }

  Set(): siz(0) {}

  /// Iterátor létrehozása az elejére
  iterator begin() {      // létrehoz egy iterátort és az elejére állítja
    return iterator(*this);
  }

    /// Iterátor létrehozása a végére
  iterator end() {        // létrehozza és az utolsó elem után állítja
    return iterator(*this, siz);
  }

    /// iterator osztály
  class iterator {
        T *p, *pe;	        // pointer az akt elemre, és az utolsó utánira
    public:
        // Van benne pointer, mégis jó a default másoló konstruktor és az értékadó op. Miért ?

        /// Konstruktorok
        iterator() :p(0), pe(0) {}  // default kontruktor
        iterator(Set& a, int ix = 0)
            :p(a.t+ix), pe(a.t+maxsiz) {} // kontruktor Array-ról

        /// Pre-inkremens
        iterator& operator++() {    // növeli az iterátort (pre)
            if (p != pe) ++p;
            return *this;
        }

        /// Post-inkemens
        iterator operator++(int) {  // növeli az iterátort (post)
                                    // nem referencia értékû (miért ?)
            iterator tmp = *this;
            if (p != pe) p++;
            return tmp;
        }

        /// operator!=
        bool operator!=(const iterator &i) { // összehasonlít
            return(p != i.p);
        }

        /// operator*
        T& operator*() {            // indirekció
            if (p != pe) return *p;
            else throw std::out_of_range("Array: Hibas indirekcio");
        }

        /// operator->
        T* operator->() {           // indirekció
            if (p != pe) return p;
            else throw std::out_of_range("Array: Hibas indirekcio");
        }

  };  // iterator osztály vége

  size_t size(){
    return siz;
  }

  bool isElement(T adat){
    for(const auto& i: *this){
      if(equal(i, adat)) return true;
    }
    return false;
  }

  Set& insert(const T adat){
    if(isElement(adat)) return *this;
    if(siz == maxsiz) throw "ez mar tobb a soknal";
    t[siz] = adat;
    siz++;
    return *this;
  }

};

bool operator==(const Point& p1, const Point& p2){
  return (p1.getX() == p2.getX() && p1.getY() == p2.getY());
}
#endif
