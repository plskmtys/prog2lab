/**
 * \file
 * \brief Lada es LadaOszlop osztaly deklaracioja
 */

#ifndef LADAK_H
#define LADAK_H

#include <deque>
#include <string>

/** Lada osztaly. 
 */
class Lada {
    std::string cimke_;  /**< A lada felirata. */
    int tomeg_;          /**< A lada tomege. */
    int terhelheto_;     /**< A lada maximalis terhelhetosege. */
public:
    /** Konstruktor.
     */
    Lada(std::string cimke, int tomeg = 10, int max = 100)
        :cimke_(cimke), tomeg_(tomeg), terhelheto_(max) {}
    /** Visszaadja a lada tomeget.
     */
    int tomeg() const { return tomeg_ ;}
    /** Visszaadja a lada maximalis terhelhetoseget.
     */
    int terhelheto() const { return terhelheto_; }
    /** Visszaadja a lada szoveges cimkejet.
     */
    std::string cimke() const { return cimke_; }
};


/** Egymas tetejere rakott ladakbol allo oszlop.
 */
class LadaOszlop {
    std::deque<Lada> oszlop; /**< Az egymasra helyezett ladak (elso legfelul) */
public:
    /** Megallapitja, hogy elbirja-e egy lada a terhet. 
     *  @param t extra tomeg, amit az oszlop tetejere szeretnenk tenni
     *  @param i a lada indexe (0 a legfelsoe, size()-1 a legalsoe)
     *  @return true, ha az i indexu lada elbirja az osszes felette levot, 
     *  plusz a parameterkent megadott t tomeget
     */
    bool elbir(int t, size_t i) const ;
    /** Uj ladat helyez az oszlop tetejere. Szimulalja a tul gyenge ladak
     *  megsemmisuleset alulrol kezdve.
     *  @param l masolata kerul az oszlop tetejere
     */
    void rarak(Lada l); 
    /** Ladak szama az oszlopban. */
    size_t magassag() const;
    /** A ladak eleresere. 
     *  @param i a lada indexe (0 a legfelsoe, size()-1 a legalsoe) 
     *  @return az i indexu lada*/
    Lada& operator[](size_t i);
};

#endif
