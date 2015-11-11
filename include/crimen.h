/* 
 * meteorito.h
 * 
 * Copyright  (C) Juan F. Huete
*/
#ifndef __CRIMEN_H
#define __CRIMEN_H

#include <string>
#include <iostream> 
#include <sstream>
#include <stdlib.h> 
#include "fecha.h"


//! Clase crimen, asociada a la definición de un crimen 
/*! crimen::crimen,  .....
 * Descripción contiene toda la información asociada a un crimen.
 
 @todo Implementa esta clase, junto con su documentación asociada

*/

using namespace std;

class crimen {
 private:
   long int ID; 
   string case_number;
   fecha date;
   string iucr;
   string primary_type;
   string descr;
   string local_description;
   bool arrest;
   bool domestic;
   double latitude;
   double longitude;
 public:
/** @brief Constructor por defecto de Crimen
	@post inicializa todo a 0.
*/


  crimen(); // Constructor por defecto de Crimen


/** @brief Constructor con parametro Crimen
	@param x Crimen a convertir , para inicializar la clase
*/ 

 
  crimen(const crimen& x); // Constructor por paramentros


/** @brief Fija un Crimen con parametro String 
	@param cadena string a convertir , para inicializar un crimen
*/


  void setCrimen(const string & cadena); // Cadena es un string con todos los datos de un crimen.


/** @brief Fija un ID a un Crimen
	@param id es un entero , para inicializar el valor de valor de ID de un crimen
*/


  void setID(long int & id);


/** @brief Fija un CaseNumber a un Crimen
	@param s es un String , para inicializar el valor de CaseNumber de un Crimen
*/


  void setCaseNumber(const string &  s);


/** @brief Fija una Fecha a un Crimen
	@param d es un objeto de la clase Fecha , para inicializar el valor de Date de un Crimen
*/


  void setDate(const fecha & d);


/** @brief Fija un IUCR a un Crimen
	@param iucr es un String, para inicializar el valor de IUCR de un Crimen
*/


  void setIUCR(string iucr);

/** @brief Fija un Tipo Primario a un Crimen
	@param primary_type es un String, para inicializar el valor de Primary Type de un Crimen
*/

  void setPrimaryType(string primary_type);

/** @brief Fija una Descripcion a un Crimen
	@param descripcion es un String, para inicializar el valor de DESCR de un Crimen
*/


  void setDescr(string descripcion);

/** @brief Fija una Descripcion del lugar a un Crimen
	@param descripcion_local es un String, para inicializar el valor de Local_description de un Crimen
*/


  void setLocalDescription(string descripcion_local);

/** @brief Fija un valor al Arresto en un Crimen
	@param a es un Bool, que indica el valor de Arrest de un Crimen
*/


  void setArrest(bool a);

/** @brief Fija un valor a la variable Domestic de un Crimen
	@param d es un Bool, que indica el valor de Domestic de un Crimen
*/


  void setDomestic(bool d); 

/** @brief Fija un valor a la variable Latitud de un Crimen
	@param latitud es un Double, que indica el valor de la Latitud de un Crimen
*/

  void setLatitude(double latitud);

/** @brief Fija un valor a la variable Longitud de un Crimen
	@param longitud es un Double, que indica el valor de la Longitud de un Crimen
*/


  void setLongitude(double longitud);

/** @brief Devuelve el valor de la ID del Crimen
	@return int , ID
	@post no modifica la clase.
	
*/


  long int getID( ) const;

/** @brief Devuelve el valor del CaseNumber de un Crimen
	@return string , CaseNumber
	@post no modifica la clase.
	
*/


  string getCaseNumber( ) const;

/** @brief Devuelve el valor de la fecha de un Crimen
	@return fecha , Date
	@post no modifica la clase.
	
*/

  fecha getDate( ) const;

/** @brief Devuelve el valor del IUCR de un Crimen
	@return string , IUCR
	@post no modifica la clase.
	
*/


  string getIUCR( ) const;

/** @brief Devuelve el valor del PrimaryType de un Crimen
	@return string , PrimaryType
	@post no modifica la clase.
	
*/


  string getPrimaryType( ) const;

/** @brief Devuelve el valor de la Description de un Crimen
	@return string , Description
	@post no modifica la clase.
	
*/


  string getDescr( ) const;

/** @brief Devuelve el valor del LocalDescription de un Crimen
	@return string , LocalDescription
	@post no modifica la clase.
	
*/


  string getLocalDescription( ) const;

/** @brief Devuelve el valor del Arrest de un Crimen
	@return bool , Arrest
	@post no modifica la clase.
	
*/

  bool getArrest( ) const;

/** @brief Devuelve el valor del Domestic de un Crimen
	@return bool , Domestic
	@post no modifica la clase.
	
*/




  bool getDomestic( ) const;

/** @brief Devuelve el valor de la Latitude de un Crimen
	@return double , Latitude
	@post no modifica la clase.
	
*/

  double getLatitude( ) const;

/** @brief Devuelve el valor de la Longitude de un Crimen
	@return double , Longitude
	@post no modifica la clase.
	
*/



  double getLongitude( ) const;


/** @brief Sobrecarga del operador igual (=) con parametro de tipo Crimen
	@param c tipo de dato Crimen
	@return Devuelve una refencia con la clase igual a la pasada por parametro
	
*/


  crimen & operator=(const crimen & c);

/** @brief Sobrecarga del operador (==) con parametro tipo Crimen
	@param c tipo de dato Crimen
	@return True si es el mismo Crimen , false si es distinta
	@post no modifica la clase.
*/


  bool operator==(const crimen & x) const;

/** @brief Sobrecarga del operador (<) con parametro tipo Crimen 
	@param x tipo de dato Crimen
	@return True si this es menor que x , false si es mayor
	@post no modifica la clase.
	
*/


  bool operator<(const crimen & x) const;


  bool operator<=(const crimen &x) const;
 
};




/** @brief imprime todas las entradas del Crimen
@post  No se modifica el conjunto.

	*/


  ostream& operator<< ( ostream& , const crimen& );


#include "../src/crimen.hxx"
#endif
