#include "fancy_iterators.hpp"
#include <algorithm>
#include <cstddef>
#include <iostream>

#define ELKESZULT 7

template <typename T>
void printEach(T start, T end, std::ostream& os = std::cout, const char *sep = ",") {
  while (start != end) {
    os << *start++;
    if (start != end) os << sep;
    else os << std::endl;
  }
}

template <typename T>
size_t szamol_ha_negativ(T start, T end){
  size_t cnt = 0;
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
size_t szamol_ha(T start, T end, P pred){
  size_t cnt = 0;
  while(start != end){
    if (pred(*start++)) cnt++;
  }
  return cnt;
}

