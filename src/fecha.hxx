/** @brief fichero de implementacion de la clase fecha

*/
#include "fecha.h"



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
	
	string XM;
	string aux;
	
	mday = atoi(dato.substr( 0, 2 ).c_str());
	mon = atoi(dato.substr( 3, 2 ).c_str());
	year = atoi(dato.substr( 6, 4 ).c_str());
	
	hour = atoi(dato.substr( 11, 2 ).c_str());
	min = atoi(dato.substr(14, 2 ).c_str());
	sec = atoi(dato.substr(17, 2 ).c_str());

	XM = dato.substr(20, 2 ).c_str();

	if(XM.compare("PM")){
		hour += 12 ;
	}

}


fecha::fecha(const fecha & s){
 
	mday = s.mday;
	mon = s.mon;
	year = s.year;
	hour = s.hour;
	min = s.min;
	sec = s.sec;
        
}
  
fecha & fecha::operator=(const fecha & f){

	 if (this != &f) {

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

	

		string XM;

		mday = atoi ( s.substr( 0, 2 ).c_str());
		mon = atoi ( s.substr( 3, 2 ).c_str());
		year = atoi ( s.substr( 6, 4 ).c_str());
	
		hour = atoi ( s.substr( 11, 2 ).c_str());
		min = atoi ( s.substr(14, 2 ).c_str());
		sec = atoi ( s.substr(17, 2 ).c_str());
	
		XM = s.substr(20, 2 );

		if(XM.compare("PM")){
			hour += 12 ;
		
		
        
    }
    return *this;

}
string fecha::toString( ) const{

	stringstream ss;
	int hourAux;
	string XM;

	if(hour>=12){
		hourAux = hour - 12 ;
		XM = "PM";
	}else{
		hourAux = hour;
		XM = "AM";
	}

	ss <<  mday << "/" << mon << "/" << year << " " << hourAux << ":" << min << ":" << sec << " " << XM;

	return ss.str();

}

// Operadores relacionales
 /*bool fecha::operator==(const fecha & f) const{

	bool sol;
	sol = (mday == f.getDay() && mon == f.getMon() && year == f.getYear() && hour == f.getHour() && min == f.getMin() && sec == f.getSec());
	return sol;

}*/
 /*bool fecha::operator<(const fecha & f)const{

	bool sol;

	if(year < fecha.getYear()){
		sol = true;

	}else if ( year == fecha.getYear() ){

			if(mon < fecha.getMon()){
				sol = true;

			}else if ( year == fecha.getYear() ){

					if(day < fecha.getDay()){
						sol = true;

					}else if ( day == fecha.getDay() ){

							if(hour < fecha.getHour){
								sol = true;

							}else if ( hour == fecha.getHour ){

								if(min < fecha.getMin()){
									sol = true;

								}else if ( min == fecha.getMin() ){

									if(sec < fecha.getSec()){
										sol = true;

									}else if ( sec == fecha.getSec() ){
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
}*/
 bool fecha::operator>(const fecha & f) const{

	return !operator<(f);

}
 bool fecha::operator<=(const fecha & f)const{
	
	return operator<(f)||operator==(f);

	
}
 bool fecha::operator>=(const fecha & f) const{

	return operator>(f) || operator==(f);
	
}
 bool fecha::operator!=(const fecha & f)const{

	return !operator==(f);
}
 
 ostream& operator << ( ostream &os ,const fecha &f){
      
    os << f.toString();


   return os;
 }
   
   
 
