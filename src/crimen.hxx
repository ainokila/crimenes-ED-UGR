/** @brief fichero de implementacion de la clase crimen

*/
#include "crimen.h"

//CONSTRUCTORES
crimen::crimen(){
   ID=0;
   case_number="";
   date = fecha();
   iucr="";
   primary_type="";
   descr="";
   local_description="";
   arrest=false;
   domestic=false;
   latitude = 0;
   longitude = 0;

}

crimen::crimen(const crimen& x){
 ID = x.getID();
 case_number = x.getCaseNumber();
 date = x.getDate();
 iucr = x.getIUCR();
 primary_type = x.getPrimaryType();
 descr = x.getDescr();
 local_description = x.getLocalDescription();
 arrest = x.getArrest();
 domestic = x.getDomestic();
 latitude = x.getLatitude();
 longitude = x.getLongitude();

}
//SETS

void crimen::setID(long int &id){
   this->ID = id;
}

void crimen::setCaseNumber(const string &s){
   case_number = s;
}

void crimen::setDate(const fecha &d){
   date = d;
}

void crimen::setIUCR(string iucr){
   this->iucr = iucr;   
}

void crimen::setPrimaryType(string primary_type){
   this->primary_type = primary_type;
}

void crimen::setDescr(string descripcion){
   descr = descripcion;
}

void crimen::setLocalDescription(string descripcion_local){
   local_description = descripcion_local;
}

void crimen::setArrest(bool a){

   if( a == true)
      arrest = true;
   else 
      arrest = false;

}

void crimen::setDomestic(bool d){

      if( d == true )
         domestic = true;
      else
	 domestic = false;
}

void crimen::setLatitude(double latitud){
   latitude = latitud;
}

void crimen::setLongitude(double longuitud){
   longitude = longuitud;
}

//GETS

long int crimen::getID( ) const{
   return ID;
}

string crimen::getCaseNumber( ) const{
   return case_number;
}

fecha crimen::getDate( ) const{
   return date;
}

string crimen::getIUCR( ) const{
   return iucr;
}
string crimen::getPrimaryType( ) const{
   return primary_type;
}

string crimen::getDescr( ) const{
   return descr;
}

string crimen::getLocalDescription( ) const{
   return local_description;
}

bool crimen::getArrest( ) const{
   return arrest;
}

bool crimen::getDomestic( ) const{
   return domestic;
}

double crimen::getLatitude( ) const{
   return latitude;
}

double crimen::getLongitude( ) const{
   return longitude;
}

//Operadores relacionales
crimen & crimen::operator=(const crimen &c){
    c.setID(ID);
    c.setCaseNumber(case_number);
    c.setDate(date);
    c.setIUCR(iucr);
    c.setPrimaryType(primary_type);
    c.setDescr(descr);
    c.setLocalDescription(local_description);
    c.setArrest(arrest);
    c.setDomestic(domestic);
    c.setLatitude(latitude);
    c.setLonguitude(longitude)
}

bool crimen::operator==(const crimen &x) const{
   bool sol;

   if ( ( ID == x.getID( ) ) && ( case_number == x.getCaseNumber() ) && ( date = x.getDate( ) ) && ( iucr == x.getIUCR( ) ) && ( primary_type == x.getPrimaryType( ) ) && ( descr == x.getDescr( ) ) && ( local_description == x.getLocalDescription( ) ) && ( arrest == x.getArrest( ) ) && ( domestic == x.getDomestic( ) ) && ( latitude == x.getLatitude( ) ) && (longitude == x.getLongitude( ) ) ) {
	sol = true;
   }else{
	sol = false;
   }			
return sol;
}

bool crimen::operator<(const crimen &x) const{
   bool sol;
   if ( ID < x.getID( ) )
	sol = true;
   else
	sol = false;

return sol;
}

std::ostream& operator << ( ostream &os, const crimen &c ){
  os << c.toString();

}

