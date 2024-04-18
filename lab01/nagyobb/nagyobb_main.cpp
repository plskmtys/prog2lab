// Fájl: nagyobb_main.cpp
// Egyszerű demo program.
// Bekér két egész számot és kiírja a nagyobbat.

#include <iostream>
#include <iomanip>
#include "fuggvenyeim.h"
#include <limits>
using namespace std;

int main() {
    double an[] = { 3, 2, 1 }; // együtthatók: a0=3, a1=2, a3=1      
    cout << "polinom(x=1)(x^2+2x+3):" << polinom(1.0, an, 2) << endl;
    double res[] = { 3, 6, 11, 18, 27, 38, 51 };
    cout << setprecision(50) << std::numeric_limits<double>::epsilon() << endl; // 50-szer a legkisebb absz. (!=0) érték: ~1e-14
    int hibak = 0;
    for (int i = 0; i < 7; i++) {
        const double Z = 3.141e2;
        double x = i / Z - 1;
        x++;
        x = x * Z;
        double fx = polinom(x, an, 2);
        if (!almostEQ(res[i], fx)) {    // Helyes ez így? 
           cout << "Hibas: " << setprecision(50) << res[i] << "!=" << fx << endl;
           hibak++;
        }
    }
    if (hibak == 0)
        cout << "Nem volt elteres" << endl;
}
