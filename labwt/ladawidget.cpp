/**
 * \file
 * \brief LadaWidget osztaly megvalositasa.
 */

#include <Wt/WContainerWidget>
#include <Wt/WLabel>
#include <Wt/WTable>
#include <Wt/WImage>

#include "ladawidget.h"

using namespace Wt;
LadaWidget::LadaWidget(WContainerWidget* parent)  : WTable(parent) {} 

void LadaWidget::hozzaad(Lada l) { 
    rarak(l);
    rajzol(l.tomeg());
}

void LadaWidget::rajzol(int t) {
    WTable::clear();	// toroljuk a megjelenitett ladakat
    int eros = 0; 	// gyenge ladak szama
    int gyenge = 0;	// eros ladak szama
    for (size_t i = 0; i < magassag(); i++) {
        //lada info kiiras
        WLabel *l = new WLabel((*this)[i].cimke(), elementAt(i,0)); 

        //ha nem birja el a felette levoket, akkor piros ikon lesz
        WImage *kep;
        if (elbir(t,i)) {
            kep = new WImage("img/chest.png");
            eros++;
        } else {
            kep = new WImage("img/chest-red.png");
            gyenge++;
        }
       
        l->setImage(kep);
    }
}

