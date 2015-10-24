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
 
	mday = x.getDay;
	mon = x.getMon;
	year = x.getYear;
	hour = x.hour;
	min = x.getMin;
	sec = x.getSec;
}
  
fecha & fecha::operator=(const fecha & f){

	 if (this != &other) {

		mday = f.getDay;
		mon = f.getMon;
		year = f.getYear;
		hour = f.hour;
		min = f.getMin;
		sec = f.getSec;
        
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

	string sol ; 
	int hourAux;
	string XM;

	if(hour>12){
		hourAux = hour % 12 ;
		XM = "PM";
	}else{
		hourAux = hour;
		XM = "AM";
	}

	sol = to_string(mday)+"/"+to_string(mon)+"/"+to_string(year)+" "+to_string(hourAux)+":"+to_string(min)+":"+to_string(sec)+" "+XM;
	return sol;

}

// Operadores relacionales
 bool fecha::operator==(const fecha & f) const{

	bool sol;
	sol = (mday == f.getDay && mon == f.getMon && year == f.getYear && hour == f.hour && min == f.getMin && sec == f.getSec );
	return sol;

}
 bool fecha::operator<(const fecha & f)const{

	bool sol;

	if(year < fecha.getYear){
		sol = true;

	}else if ( year == fecha.getYear ){

			if(mon < fecha.getMon){
				sol = true;

			}else if ( year == fecha.getYear ){

					if(day < fecha.getDay){
						sol = true;

					}else if ( day == fecha.getDay ){

							if(hour < fecha.getHour){
								sol = true;

							}else if ( hour == fecha.getHour ){

								if(min < fecha.getMin){
									sol = true;

								}else if ( min == fecha.getMin ){

									if(sec < fecha.getSec){
										sol = true;

									}else if ( sec == fecha.getSec ){
										sol = false;
		
									}else{
										sol = false;
									}
					
		
								}else{
									sol = false;
								}
		
							}else{
								sol = false;
							}
		
		
					}else{
						sol = false;
					}
		
			}else{
				sol = false;
			}
		
	}else{
		sol = false;
	}
	return sol;
}
 bool fecha::operator>(const fecha & f) const{
	return !operator<(f);

}
 bool fecha::operator<=(const fecha & f)const{

}
 bool fecha::operator>=(const fecha & f) const{

}
 bool fecha::operator!=(const fecha & f)const{
	return !operator==(f);
}
 
 ostream& operator<< ( ostream& os, const fecha & f){
      
    os << f.toString();


   return os;
 }
   
   
 
