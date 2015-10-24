/** @brief fichero de implementacion de la clase fecha

*/
fecha::fecha(){

	sec = 0;   // seconds of minutes from 0 to 59
	min = 0;   // minutes of hour from 0 to 59
	hour = 0;  // hours of day from 0 to 24
	mday = 0;  // day of month from 1 to 31
	mon = 0;   // month of year from 0 to 11
	year = 0;  // year since 2000
}

fecha::fecha (const string & dato){
	//String format imput dd/mm/yyyy hh:mm:ss XM
	//					  0123456789

	String XM;

	mday = atoi ( dato.substr( 0, 2 ));
	mon = atoi ( dato.substr( 3, 2 ));
	year = atoi ( dato.substr( 6, 4 ));
	
	hour = atoi ( dato.substr( 11, 2 ));
	min = atoi ( dato.substr(14, 2 ));
	sec = atoi ( dato.substr(17, 2 ));
	
	XM = dato.substr(20, 2 );

	if(XM.compare("PM")){
		hour += 12 ;
	}

}


fecha::fecha(const fecha & x){
 // @todo implementar esta funcion
	mday = x.mday;
	mon = x.mon;
	year = x.year;
	hour = x.hour;
	min = x.min;
	sec = x.sec;
}
  
    
 
 ostream& operator<< ( ostream& os, const fecha & f){
   // @todo implementa esta funcion
     
   // os << f.getYear() ;
   return os;
 }
   
   
 
