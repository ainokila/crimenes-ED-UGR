/**
  * @file fecha.h
  * @brief Fichero con la cabecera de la clase fecha 
  *
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

/** @brief Constructor por defecto de fecha
	@post inicializa todo a 0.
	
*/
 fecha (); //Constructor de fecha por defecto

/** @brief Constructor con parametro string 
	@param s string a convertir , para inicializar la clase
*/
 fecha (const string & s); // s es un string con el formato mm/dd/aaaa  hh:mm:ss AM/PM

/** @brief Constructor por copia de fecha
	@param s tipo de dato fecha
	
*/
 fecha(const fecha & s);

/** @brief Sobrecarga el operador igual (=) con parametro de tipo fecha
	@param f  tipo dato fecha
	@return Devuelve una refencia con la clase igual a la pasada por parametro
	
*/
 fecha & operator=(const fecha & f);

/** @brief Sobrecarga el operador igual (=) con parametro de tipo string
	@param s tipo de dato string
	@return Devuelve una referencia con la clase creada a partir del string
	
*/
 fecha & operator=(const string & s); // s es un string con el formato mm/dd/aaaa hh:mm:ss AM/PM

/** @brief Metodo que convierte la clase a string
	@return string en formato mm/dd/aaaa  hh:mm:ss AM/PM
	@post no modifica la clase.
	
*/
 string toString( ) const; //convierte la fecha a un string

// Operadores relacionales

/** @brief Sobrescribimos operator == 
	@param fecha f
	@return True si es la misma fecha , false si es distinta
	@post no modifica la clase.
*/
 bool operator==(const fecha & f) const;

/** @brief Sobreescribe operador < 
	@param s fecha f
	@return True si this es menor que f , false si es distinta
	@post no modifica la clase.
	
*/
 bool operator<(const fecha & f)const;

/** @brief Sobreescribe operador > 
	@param s fecha f
	@return True si this es mayor que f , false si es distinta
	@post no modifica la clase.
	
*/
 bool operator>(const fecha & f) const;

/** @brief Sobreescribe operador <= 
	@param s fecha f
	@return True si this es menor o igual que f , false si es distinta
	@post no modifica la clase.
	
*/
 bool operator<=(const fecha & f)const;

/** @brief Sobreescribe operador >= 
	@param s fecha f
	@return True si this es mayor o igual que f , false si es distinta
	@post no modifica la clase.
	
*/
 bool operator>=(const fecha & f) const;

/** @brief Sobreescribe operador !=
	@param s fecha f
	@return True si this es distinto de f , false si es distinta
	@post no modifica la clase.
	
*/
 bool operator!=(const fecha & f)const;

/** @brief Devuelve el valor de sec
	@return int , segundos
	@post no modifica la clase.
	
*/
inline int getSec() const{
  return sec ;
}

/** @brief Devuelve el valor de min
	@return int , minutos
	@post no modifica la clase.
	
*/
inline int getMin() const{
  return min ;
}

/** @brief Devuelve el valor de hou
	@return int , hora
	@post no modifica la clase.
	
*/
inline int getHour() const{
  return hour ;
}

/** @brief Devuelve el valor de day
	@return int , dias
	@post no modifica la clase.
	
*/
inline int getDay() const{
  return mday ;
}

/** @brief Devuelve el valor de mont
	@return int , mes
	@post no modifica la clase.
	
*/
inline int getMon() const{
  return mon ;
}

/** @brief Devuelve el valor de anio
	@return int , anio
	@post no modifica la clase.
	
*/
inline int getYear() const{
  return year ;
}



};

/** @brief Sobreescribe operador <<
	@param ostream os
	@param fecha f
	@return ostream
	@post no modifica la clase.
	
*/
ostream& operator << (ostream &os, const fecha &f);  // imprime fecha con el formato  mm/dd/aaaa hh:mm:ss AM/PM

 


#include "../src/fecha.hxx" // Incluimos la implementacion.


#endif
