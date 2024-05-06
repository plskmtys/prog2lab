/**
 *  \file rajztabla.cpp
 *   Ebben a fájlban valósítsa meg a Rajztábla osztály nem inline tagfüggvényeit
 */


#include "rajztabla.h"

void Rajztabla::felrak(Alakzat *ap); 

/// Kirajzolja az összes alakzatot
void Rajztabla::rajzol() const;

/// Az összes alakzatot elmozdítja
/// @param d - eltolás vektora
void Rajztabla::mozgat(const Pont& d) const;
