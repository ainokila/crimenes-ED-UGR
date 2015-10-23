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

fecha::fecha (const string & s){
	//String format imput dd/mm/yyyy hh:mm:ss XM

		int i = 0;
		int caracterRaro = 0;
  		string auxiliar;

		while(s.at(i)!="M" ){
			
			if(s.at(i) == "/" || s.at(i) == ":" || s.at(i) == " "){
				caracterRaro++;

				switch (caracterRaro) {
		
					case 1:
						mday = atol(auxiliar);
						break;
					
					case 2:
						mon = atol(auxiliar);
						break;
					case 3:
						year = atol(auxiliar);
						break;
					case 4:
						hour = atol(auxiliar);
						break;
					case 5:
						min = atol(auxiliar);
						break;
					case 6:
						sec = atol(auxiliar);
						break;
					default :
						cerr << "Error";
						break;
				}
				auxiliar = "";
				
				

			}else if() {

			else{
				auxiliar.append(s.at(i));

			}
			
		i++;	
		}

	



}

fecha::fecha(const fecha & x){
 // @todo implementar esta funcion
}
  
    
 
 ostream& operator<< ( ostream& os, const fecha & f){
   // @todo implementa esta funcion
     
   // os << f.getYear() ;
   return os;
 }
   
   
 
