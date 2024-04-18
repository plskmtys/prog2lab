/**
 * \file 
 * \brief LadaApplication osztaly megvalositasa.
 */

#include <string>
#include <sstream>

#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WLabel>
#include <Wt/WTable>
#include <Wt/WLineEdit>
#include <Wt/WIntValidator>
#include <Wt/WPushButton>
#include <Wt/WComboBox>

#include "ladawidget.h"
#include "tortadiagram.h"

using namespace Wt;

/** A webalkalmazas osztaly.
 */
class LadaApplication : public WApplication {
  int db;                /**< Szamlalo a ladak egyedi cimkezesehez. */ 
  LadaWidget *ladak;     /**< A ladak tablazatos formaban a weboldalon. */
  WLineEdit *tomegLine;  /**< Tomeg beviteli mezo. */
  // a lokalis valtozok meg bovulhetnek

  /** Segedfuggveny: Szovegmezo tartalmanak int-te konvertalasa. 
   */
  int lineToint(WLineEdit *line) {
     std::istringstream ss(line->text().narrow());
     int i;
     if (ss >> i) 
        return i;
     return 1;
  }

  /** Uj lada hozzaadasa a szovegmezokben megadott adatoknak megfeleloen.
   */
  void hozzaad() {
     int tomeg = lineToint(tomegLine);
     int max = 10;	// it kell kiolvasnia a max beviteli mezot
     std::ostringstream ss;
     ss << ++db << ". lada (" << tomeg << ";" << max << ")";
     ladak->hozzaad(*new Lada(ss.str(), tomeg, max));
  }

  /** A tomeg szovegmezo valtozasanak esemenykezeloje. Ujra kell rajzolni 
   *  a ladakat, mert a pirositas valtozhat.
   */
  void tomegValtozott() {
     ladak->rajzol(lineToint(tomegLine));
  }

  // Celszeruen Ide kerul a comboBox (nyelvvalaszto) esemenykezeloje

public:
  /** Konstruktor. 
   */
  LadaApplication(const WEnvironment& env);
};

/** Konstruktor. Letrehozza a widget-eket: 
 *    - beviteli mezok a tomegnek es a terhelhetosegnek
 *    - nyomogomb uj lada hozzaadasara
 *    - LadaWidget a ladak oszlopanak kezelesere es tablazatos
 *      megjelenitesere.
 *
 *  A nyomogomb clicked() esemenyet osszekapcsolja a hozzaad() metodussal.
 *  A tomeg mezo keyWentUp() esemenyet meg a tomegValtozott()-tal.
 */
LadaApplication::LadaApplication(const WEnvironment& env)
  : WApplication(env), db(0) {

  // a Wstring::tr a ladaapp.xml fajlbol veszi a stringeket
  messageResourceBundle().use("ladaapp");	

  // letrehozunk egy tablazatot kulonbozo elemekkel
  WTable* layout = new WTable(); 		
  root()->addWidget(layout);				// ez lesz az alkalmazás fo ablaka
  WTable* panel = new WTable(layout->elementAt(0,0));	// panel a beviteli mezokhoz
  ladak = new LadaWidget(layout->elementAt(0,1));	// ladaoszlopot megjelenito widget
  layout->elementAt(0,1)->setPadding(5);		// csinositas

  // beviteli panel kialakitasa (tomeg mezo, nyomogomb)
  // label a panel 0. sor 0. oszlobpaba
  WLabel* label = new WLabel(WString::tr("TOMEG"), panel->elementAt(0,0)); // felirat (Tomeg)
  tomegLine = new WLineEdit("2", panel->elementAt(0,0));// egysoros editbox
  tomegLine->setValidator(new WIntValidator(0, 200));	// 0 es 200 kozott lehet az erteke
  label->setBuddy(tomegLine);				// a felirat melle teszuk 
  // a nyomogombot pedig a 2. sor 0. oszlopaba tesszuk
  WPushButton* button = new WPushButton(WString::tr("HOZZAAD"), panel->elementAt(2,0));

  // Ide jon majd a tobbi felhasznaloi elem: a masik beviteli mezo
//  label = new WLabel(WString::tr("MAX"), panel->elementAt(1,0)); // felirat (Max)
// ...

  // ide jon a combobox letrehozasa
//  combo = new WComboBox(panel->elementAt(3, 0));       	// panel 3. sora
// ..





  // Ide jon a tortadiagram letrehozasa




  
  // esemenykezelo fuggvenyek bekotese
  button->clicked().connect(this, &LadaApplication::hozzaad); // nyomogomb megnyomasa
  tomegLine->keyWentUp().connect(this, &LadaApplication::tomegValtozott); // billentyu felengedese az editboxban
}

/* 
 * Alkalmazas osztaly peldanyositasa a megfelelo kornyezeti valtozokkal.
 * Minden http kapcsolathoz (session) onallo peldany keletkezik.
 */
WApplication *createApplication(const WEnvironment& env) {
  return new LadaApplication(env);
}

/* 
 * Foprogram.
 * Mehgivja a WApplication osztaly WRun tagfuggvenyet.
 * Ez minden sesson-hoz keszit egy LadaaApplication peldanyt
 */
int main(int argc, char **argv) {
  return WRun(argc, argv, &createApplication);
}

