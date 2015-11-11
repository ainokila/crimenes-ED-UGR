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

void crimen::setCrimen(const string & cadena){
	
	int pos_inicio=0, pos_fin=0; 
	int comas=0, tamanio=0;
	
	
	//Compruebo que tamaño tiene que tener el vector de strings
	for(size_t i=0; i<cadena.length(); i++){

	   if(cadena[i] == ','){
				
		tamanio++;
		}
	
	  
	}
	string aux[tamanio];

	//Recorro string y formo subcadenas dentro de un vector de strings
	for(size_t i=0; i<cadena.length(); i++){

	   if(cadena[i] == ','){
				
		 pos_fin = i - pos_inicio;
		  aux[comas] = cadena.substr(pos_inicio, pos_fin).c_str();
		 
		 
		  pos_inicio += pos_fin+1;
		   comas++;
		  
		}
	
	  
	}

	//inicializo
	ID = atoi (aux[0].c_str()); //convierto string a entero
	case_number = aux[1]; 
	date = fecha(aux[2]);
	iucr = aux[4];
	primary_type = aux[5];
	descr = aux[6];
	local_description = aux[7];

	if( aux[8] == "false" ){
	   arrest = false;
	}else if (aux[8] == "true" ){
	   arrest = true;
	}

	if( aux[9] == "false" ){ 
	   domestic = false;
	}else if (aux[9] == "true" ){
	   domestic = true;
	}

	latitude = atof(aux[19].c_str());
	longitude = atof(aux[20].c_str());
	

}


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

void crimen::setLongitude(double longitud){
   longitude = longitud;
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
   ID = c.getID();
   case_number = c.getCaseNumber();
   date = c.getDate();
   iucr = c.getIUCR();
   primary_type = c.getPrimaryType();
   descr = c.getDescr();
   local_description = c.getLocalDescription();
   arrest = c.getArrest();
   domestic = c.getDomestic();
   latitude = c.getLatitude();
   longitude = c.getLongitude();
   return *this;
}

bool crimen::operator==(const crimen &x) const{
   bool sol=false;

   if ( ( ID == x.getID( ) ) && ( case_number == x.getCaseNumber() ) && ( date == x.getDate( ) ) && ( iucr == x.getIUCR( ) ) && ( primary_type == x.getPrimaryType( ) ) && ( descr == x.getDescr( ) ) && ( local_description == x.getLocalDescription( ) ) && ( arrest == x.getArrest( ) ) && ( domestic == x.getDomestic( ) ) && ( latitude == x.getLatitude( ) ) && (longitude == x.getLongitude( ) ) ) {
	sol = true;
   }			
return sol;
}

bool crimen::operator<(const crimen &x) const{
   bool sol=false;
   if ( ID < x.getID( ) )
	sol = true;
return sol;
}

bool crimen::operator<=(const crimen &x) const{
   bool sol=false;
   if ( ID <= x.getID( ) )
	sol = true;

 return sol;
}

ostream& operator << ( ostream &os, const crimen &c ){

	string aux1, aux2;

//Ajusto valor al aux para que muestre Si o No
	if (c.getArrest()){
	
		aux1 = "Si";
	
	}
	else{

		aux1= "No";

	}
//Ajusto valor para que muestre Si o No.
	if(c.getDomestic()){

		aux2 = "Si";

	}
	else{
	
		aux2= "No";
	}

	os << "ID : " << c.getID() << " - " << "Numero de caso: " << c.getCaseNumber() << " - " << "Fecha: "<< c.getDate().toString() << " - " << "IUCR: "<< c.getIUCR()<< " - " << "Tipo Primario: " << c.getPrimaryType() << " - " <<"Descripcion del caso: "<<  c.getDescr() << " - " <<"Descripcion del lugar: " << c.getLocalDescription() << " - " <<"Arresto: "<< aux1 << " - " <<"Crimen domestico: " << aux2 << " - " << "Latitud: " << c.getLatitude() << " - " <<"Longitud: "<< c.getLongitude()<< endl;
   return os;
}

