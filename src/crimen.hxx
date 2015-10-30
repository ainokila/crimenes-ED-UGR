/** @brief fichero de implementacion de la clase crimen

*/
#include "crimen.h"

crimen::crimen(){

}

crimen::crimen(const crimen& x){

}

crimen::setID(long int & id){

ID = id;

}
crimen::setCaseNumber(const string &  s){

}

crimen::setDate(const fecha & d){
s
}

//..

crimen::setArrest(bool a){
bool hay_arrestos = false;

if( a == true)
   hay_arrestos = true;

return hay_arrestos;

}

crimen::setDomestic(bool d){

bool domestico=false;
if( d == true )
   domestico = true;

   return domestico;
}

//..

crimen::getID( ) const{

}

crimen::getCaseNumber( ) const{

}

crimen::getDate( ) const{

}

//Operadores relacionales
crimen::operator=(const crimen & c){

}

crimen::operator==(const crimen & x) const{

}

crimen::operator<(const crimen & x) const{

}
