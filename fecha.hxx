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
 
	mday = x.mday;
	mon = x.mon;
	year = x.year;
	hour = x.hour;
	min = x.min;
	sec = x.sec;
}
  
fecha & fecha::operator=(const fecha & f){

	 if (this != &other) {

		mday = f.mday;
		mon = f.mon;
		year = f.year;
		hour = f.hour;
		min = f.min;
		sec = f.sec;
        
    }
    return *this;

}
fecha & fecha::operator=(const string & s){

	 if (this != &other) {

		String XM;

		mday = atoi ( s.substr( 0, 2 ));
		mon = atoi ( s.substr( 3, 2 ));
		year = atoi ( s.substr( 6, 4 ));
	
		hour = atoi ( s.substr( 11, 2 ));
		min = atoi ( s.substr(14, 2 ));
		sec = atoi ( s.substr(17, 2 ));
	
		XM = s.substr(20, 2 );

		if(XM.compare("PM")){
			hour += 12 ;
		}

		
        
    }
    return *this;

}
string fecha::toString( ) const{

}

// Operadores relacionales
 bool fecha::operator==(const fecha & f) const{
	bool sol;
	sol = (mday == f.mday && mon == f.mon && year == f.year && hour == f.hour && min == f.min && sec == f.sec );
	return sol;

}
 bool fecha::operator<(const fecha & f)const{

}
 bool fecha::operator>(const fecha & f) const{

}
 bool fecha::operator<=(const fecha & f)const{

}
 bool fecha::operator>=(const fecha & f) const{

}
 bool fecha::operator!=(const fecha & f)const{

}
 
 ostream& operator<< ( ostream& os, const fecha & f){
   // @todo implementa esta funcion
     
   // os << f.getYear() ;
   return os;
 }
   
   
 
