/**
 * \file
 * \brief Tortadiagram osztaly deklaracioja
 */

#ifndef TORTADIAGRAM_H
#define TORTADIAGRAM_H

#include <Wt/WContainerWidget>
#include <Wt/WStandardItemModel>
#include <Wt/Chart/WPieChart>

/**
 * Tortadiagram.
 */
class Tortadiagram : public Wt::Chart::WPieChart {
public:
    Tortadiagram(Wt::WStandardItemModel* model, Wt::WContainerWidget* parent = 0);
};

#endif // TORTADIAGRAM_H

