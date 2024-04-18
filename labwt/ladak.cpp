/**
 * \file
 * \brief LadaOszlop osztaly megvalositasa.
 */

#include "ladak.h"

bool LadaOszlop::elbir(int t, size_t i) const {
    for (size_t j = 0; j < i; j++) {
        t += oszlop[j].tomeg();
    }
    return oszlop[i].terhelheto()>=t;
}

void LadaOszlop::rarak(Lada l) {
    for (int i=oszlop.size()-1; i>=0; i--) {  //lentrol fel
        if (!elbir(l.tomeg(),i)) {            //keresunk gyenge ladakat
            oszlop.erase(oszlop.begin()+i);   //es toroljuk
        }
    }
    oszlop.push_front(l);                     //tetejere kerul az uj
}

size_t LadaOszlop::magassag() const {
    return oszlop.size();
}
   
Lada& LadaOszlop::operator[](size_t i) {
    return oszlop[i];
}

