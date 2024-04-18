/**
 * \file
 * \brief LadaWidget osztaly deklaracioja
 */

#ifndef LADAWIDGET_H
#define LADAWIDGET_H

#include <Wt/WContainerWidget>
#include <Wt/WTable>

#include "ladak.h"

/** A ladakbol epitett oszlopot reprezentalo webes kezeloelem (widget).
 */
class LadaWidget : public Wt::WTable, public LadaOszlop {
public:
  /** Konstruktor. 
   */
  LadaWidget(Wt::WContainerWidget* parent = 0);
  /** Uj lada hozzaadasa. Szimulalja az oszlop mukodeset: a nem elegendo
   *  terhelhetosegu ladak megsemmisulnek. A megjelenitesben az uj allapot
   *  tukrozodik.
   */
  void hozzaad(Lada l);
  /** Megjeleniti a ladakat. Pirossal jeloli azokat, amik nem birjak a
   *  megadott extra terhet.
   *  @param t extra tomeg, amit az oszlop tetejere szeretnenk tenni
   */
  void rajzol(int t);
private:
};

#endif
