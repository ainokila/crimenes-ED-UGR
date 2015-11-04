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
  crimen();
  void setCrimen(string & cadena);
  crimen(const crimen& x);
  
  void setID(long int & id);
  void setCaseNumber(const string &  s);
  void setDate(const fecha & d);
  void setIUCR(string iucr);
  void setPrimaryType(string primary_type);
  void setDescr(string descripcion);
  void setLocalDescription(string descripcion_local);
  void setArrest(bool a);
  void setDomestic(bool d); 
  void setLatitude(double latitud);
  void setLongitude(double longuitud);
  // ...
  long int getID( ) const;
  string getCaseNumber( ) const;
  fecha getDate( ) const;
  string getIUCR( ) const;
  string getPrimaryType( ) const;
  string getDescr( ) const;
  string getLocalDescription( ) const;
  bool getArrest( ) const;
  bool getDomestic( ) const;
  double getLatitude( ) const;
  double getLongitude( ) const;
  
  // -...
   crimen & operator=(const crimen & c);
   bool operator==(const crimen & x) const;
   bool operator<(const crimen & x) const;
 
};

  ostream& operator<< ( ostream& , const crimen& );


#include "../src/crimen.hxx"
#endif
