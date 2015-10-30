/* 
 * meteorito.h
 * 
 * Copyright  (C) Juan F. Huete
*/
#ifndef __FECHA_H
#define __FECHA_H

#include <string>
#include <iostream> 
#include <sstream>
#include <stdlib.h> 

using namespace std;

//! Clase fecha, asociada a la 
/*! fecha::fecha,  .....
 * Descripción contiene toda la información asociada a una fecha con el formato  mm/dd/aaaa hh:mm:ss AM/PM
 
 @todo Implementa esta clase, junto con su documentación asociada

*/

class fecha {
private:
  int  sec;   // seconds of minutes from 0 to 59
  int  min;   // minutes of hour from 0 to 59
  int  hour;  // hours of day from 0 to 24
  int  mday;  // day of month from 1 to 31
  int  mon;   // month of year from 0 to 11
  int  year;  // year since 2000

public:
 fecha (); //Constructor de fecha por defecto
 fecha (const string & s); // s es un string con el formato mm/dd/aaaa  hh:mm:ss AM/PM
 fecha(const fecha & s);


 fecha & operator=(const fecha & f);
 fecha & operator=(const string & s); // s es un string con el formato mm/dd/aaaa hh:mm:ss AM/PM
 string toString( ) const; //convierte la fecha a un string

// Operadores relacionales
 bool operator==(const fecha & f) const;
 bool operator<(const fecha & f)const;
 bool operator>(const fecha & f) const;
 bool operator<=(const fecha & f)const;
 bool operator>=(const fecha & f) const;
 bool operator!=(const fecha & f)const;

inline int getSec() const{
  return sec ;
}
inline int getMin() const{
  return min ;
}
inline int getHour() const{
  return hour ;
}
inline int getDay() const{
  return mday ;
}
inline int getMon() const{
  return mon ;
}
inline int getYear() const{
  return year ;
}



};

ostream& operator << (ostream &os, const fecha &f);  // imprime fecha con el formato  mm/dd/aaaa hh:mm:ss AM/PM

 


//#include "fecha.hxx" // Incluimos la implementacion.


#endif
