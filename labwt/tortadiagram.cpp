/**
 * \file
 * \brief Tortadiagram osztaly megvalositas
 */

#include "tortadiagram.h" 

using namespace Wt;
using namespace Wt::Chart;

/**
 * Konstruktor.
 */
Tortadiagram::Tortadiagram(WStandardItemModel* model, WContainerWidget* parent)
    : WPieChart(parent)
{
    setModel(model);       // beallitjuk a modellt
    setLabelsColumn(0);    // ez az oszlop lesz a felirat oszlopa
    setDataColumn(1);      // ez az oszlop lesz az adat

    // tipus es hely megadasa
    setDisplayLabels(Outside | TextLabel | TextPercentage);

    // engedelyezzuk a 3D-t
    setPerspectiveEnabled(true, 0.2);

    // a 0. elemeit kiemeljuk
    setExplode(0, 0.3);
    resize(800, 300);

    // margok beallitasa
    setMargin(10, Top | Bottom);            
    setMargin(WLength::Auto, Left | Right); 
}

