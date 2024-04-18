#include <iostream>
#include <ostream>

#ifndef BICIKLI_H
#define BICIKLI_H

class Kerek {
private:
  int atmero;
public:
  Kerek(): atmero(0) {}

  Kerek(int a): atmero(a) {
    std::cout << "\tKerek ctor\n";
  }

  virtual ~Kerek(){
    std::cout << "\tKerek dtor\n";
  }

  Kerek(Kerek& k): atmero(k.atmero) {
    std::cout << "\tKerek copy\n";
  }

  void kiir()         { std::cout << "atmero=" << atmero << std::endl; }
};

class Monocikli {
  private:
    Kerek k;
  public:
    Monocikli(): k(16) {
      std::cout << "\tMonocikli ctor\n";
    }
    
    Monocikli(Monocikli& m): k(m.k) {
      std::cout << "\tMonocikli copy\n";
    }

    void kiir()         { std::cout << "\tk."; k.kiir(); }
};

class Jarmu{
  private:
    double vMax;
  public:
    Jarmu(): vMax(0) {}

    Jarmu(double v): vMax(v) {
      std::cout << "\tJarmu ctor vMax=" << vMax << std::endl;
    }

    Jarmu(Jarmu& j): vMax(j.vMax) {
      std::cout << "\tJarmu copy vMax=" << vMax << std::endl;
    }

    virtual ~Jarmu(){
      std::cout << "\tJarmu dtor vMax=" << vMax << std::endl;
    }
};

class Szan : public Jarmu {
  private:
    int kutyakSzama;
  public:
    Szan(double v = 0, int n = 0): Jarmu(v), kutyakSzama(n) {
      std::cout << "\tSzan ctor kutyakSzama=" << kutyakSzama << std::endl;
    }

    Szan(Szan& sz): Jarmu(sz), kutyakSzama(sz.kutyakSzama) {
      std::cout << "\tSzan copy kutyakSzama=" << kutyakSzama << std::endl;
    }

    ~Szan() override {
      std::cout << "\tSzan dtor kutyakSzama=" << kutyakSzama << std::endl;
    }
};

class Bicikli : public Jarmu {
  private:
    Kerek elso, hatso;
  public:
    Bicikli(double v = 0, int d = 0): Jarmu(v), elso(d), hatso(d) {
      std::cout << "\tBicikli ctor atmero=" << d << std::endl;
    }

    Bicikli(Bicikli& b): Jarmu(b), elso(b.elso), hatso(b.hatso) {
      std::cout << "\tBicikli copy ";
      b.hatso.kiir();
    }

    ~Bicikli() override {
      std::cout << "\tBicikli dtor ";
      hatso.kiir();
    }
};

#endif // !BICIKLI_H
