/**
 *
 * \file string5.cpp
 *
 * Itt kell megvalósítania a hiányzó tagfüggvényeket.
 * Segítségül megadtuk a C++ nem OO eszközeinek felhasználásával készített String-kezelő
 * függvényke neveit.
 *
 * Ha valamit INLINE-ként valósít meg, akkor annak a string5.h-ba kell kerülnie,
 * akár kívül akár osztályon belül definiálja. (Az inline függvényeknek minden
 * fordítási egységben elérhetőknek kell lenniük)
 * *
 * A teszteléskor ne felejtse el beállítani a string5.h állományban az ELKESZULT makrót.
 *
 */

#include <cstddef>
#include <ostream>
//#include <strstream>
#ifdef _MSC_VER
// MSC ne adjon figyelmeztető üzenetet a C sztringkezelő függvényeire
  #define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>             // Kiíratáshoz
#include <cstring>              // Sztringműveletekhez

#include "memtrace.h"           // a standard headerek után kell lennie
#include "string5.h"


/// Konstruktorok: egy char karakterből (createString)
///                egy nullával lezárt char sorozatból (createString)
String::String(const char c){
  pData = new char[2];
  pData[0] = c;
  pData[1] = '\0';
  len = 1;
}



String::String(const char* s){
  len = strlen(s);
  pData = new char[len+1];
  std::strcpy(pData, s);
}


/// Másoló konstruktor: String-ből készít (createString)

String::String(const String& s){
  len = s.len;
  pData = new char[len+1];
  std::strcpy(pData, s.pData);
}

/// Destruktor (disposeString)
String::~String(){
  delete [] pData;
}
/// operator=

String& String::operator=(const String& s2) {
  if(this == &s2) return *this;
  delete[] pData;
  len = s2.len;
  pData = new char[len+1];
  std::strcpy(this->pData, s2.pData);
  return *this;
}

/// [] operátorok: egy megadott indexű elem REFERENCIÁJÁVAL térnek vissza (charAtString)
/// indexhiba esetén const char * kivételt dob!


char& String::operator[](const size_t index) const {
  if(index < 0 || index >= len) throw "EM0G6P";
  return pData[index];
}
/// + operátorok:
///                 String-hez jobbról karaktert ad (addString)

String String::operator+(const char c) const {
  String s;
  delete[] s.pData;
  s.len = len+1;
  s.pData = new char[s.len+1];
  std::strcpy(s.pData, pData);
  s.pData[len] = c;
  s.pData[s.len] = '\0';
  return s;
}

String operator+(const char c, const String& s2) {
  String s;
  delete[] s.pData;
  s.len = s2.len+1;
  s.pData = new char[s.len+1];
  s.pData[0] = c;
  std::strcpy(s.pData + 1, s2.pData);
  s.pData[s.len] = '\0';
  return s;
}

///                 String-hez String-et ad (addString)

String String::operator+(const String& s2) const {
  String s;
  delete[] s.pData;
  s.len = len + s2.len;
  s.pData = new char[s.len+1];
  std::strcpy(s.pData, pData);
  std::strcat(s.pData, s2.pData);
  s.pData[s.len] = '\0';
  return s;
}

/// << operator, ami kiír az ostream-re
std::ostream& operator<<(std::ostream& os, const String& s) {
  os << s.pData;
  return os;
}

/// >> operátor, ami beolvas az istream-ről egy szót
