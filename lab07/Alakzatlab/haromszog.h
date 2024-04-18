/**
 *  \file haromszog.h
 *  Haromszog osztály deklarációja
 */
#ifndef HAROMSZOG_H
#define HAROMSZOG_H

/// Ügyeljen arra, hogy a csúcspontokat az alaposztály orgiójához relatívan tárolja!
#include "alakzat.h"
#include "pont.h"

class Haromszog : public Alakzat {
private:
  Pont p1, p2;
public:
  Haromszog(const Pont& _p0, const Pont& _p1, const Pont& _p2, const Szin& _sz): Alakzat(_p0, _sz), p1(_p1), p2(_p2) {}

  void rajzol() const;
  
  friend std::ostream& operator<<(std::ostream&, const Haromszog&);
};

#endif // KOR_H

