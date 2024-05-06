#include <iostream>

#define ELKESZULT 17

template <typename T>
void printEach(T start, T end, std::ostream& os = std::cout, const char *sep = ",") {
  while (start != end) {
    os << *start++;
    if (start != end) os << sep;
    else os << std::endl;
  }
}

template <typename T>
int szamol_ha_negativ(T start, T end){
  int cnt = 0;
  while(start != end){
    if(*start++<0) cnt++;
  }
  return cnt;
}

template <typename T>
class nagyobb_mint {
  T mint_mi;
public:
  nagyobb_mint(const T& a): mint_mi(a) {}
  bool operator()(const T& b){
    return b > mint_mi;
  }
};

template<typename T, typename P>
int szamol_ha(T start, T end, P pred){
  int cnt = 0;
  while(start != end){
    if (pred(*start++)) cnt++;
  }
  return cnt;
}


/// Függvénysablon, ami kiírja egy generikus tömb adatait
/// Feltételezzük, hogy a generikus tömbnek van: 
///   - ForwardIteratora, size(), valamint capacity() tagfüggvénye
/// @param T   - sablon paraméter: iterátoros tömb típus
/// @param txt - kiírandó szöveg
/// @param arr - konkrét tömb
/// @param os  - output steram 
template <class T>
void PrintArray(const char *txt, const T& arr, std::ostream& os = std::cout) {
    os << txt << " size=" << arr.size()
         << " capacity=" << arr.capacity() << std::endl;
    os << "\t data=";
    // kiírjuk az adatokat
    printEach(arr.begin(), arr.end());
}

template <typename InputIterator, class Func>
Func forEach(InputIterator first, InputIterator last, Func func){
  while(first != last) func(*first++);
  return func;
}

template<typename T>
class ostreamFunctor{
  std::ostream& os;
  const char* delim;
public:
  ostreamFunctor(std::ostream& _os, const char* _delim = ""): os(_os), delim(_delim) {}
  void operator()(const T& d){
    os << d << delim;
  }
};
