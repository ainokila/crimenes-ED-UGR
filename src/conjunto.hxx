#include "conjunto.h"

//Constructor por defecto
  
conjunto::conjunto( ){

	
}

	
//Constructor de copia
	
conjunto::conjunto (const conjunto & d){

	
	this->vc = d.vc;
}




pair<conjunto::entrada,bool>  conjunto::findID( const long int & id) const{

	pair<conjunto::entrada, bool> solucion;
	solucion.second = false;

		for(size_t i =0;  i<vc.size() && !solucion.second ; i++){
			if(vc[i].getID() == id){
				
				solucion.first = vc[i];
				solucion.second = true;
		
			}
		
		}	
		
		if(!solucion.second){
			
			conjunto::entrada defecto;
			solucion.first = defecto;
			
		}


return solucion;
}
	
conjunto conjunto::findIUCR( const string & iucr) const{
			
		
	conjunto solucion;
	
	for(size_t i =0;  i<vc.size() ; i++){
		if(vc[i].getIUCR() == iucr){
				
			solucion.insert(vc[i]);
			
		
		}
		
	}


return solucion;

}


conjunto conjunto::findDESCR( const string & descr) const{

	conjunto solucion;

	for(size_t i =0;  i<vc.size()  ; i++){
		if(vc[i].getDescr() == descr){
				
			solucion.insert(vc[i]);
		
		
		}
		
	}

return solucion;
}

bool conjunto::insert( const conjunto::entrada & e){

	bool solucion = false;

	if(!(findID(e.getID()).second)){
		
		solucion = true;
		vc.push_back(e);
		
		
	}
return solucion;
}


bool conjunto::erase(const long int & id){
	
	bool solucion = false;
	
	for (vector<conjunto::entrada>::iterator it = vc.begin() ; it != vc.end(); it++){
		if(it->getID() == id){
			solucion = true;
			vc.erase(it);
			
		}
	}

return solucion;  

}

bool conjunto::erase(const  conjunto::entrada & e){

		bool solucion = false;
	
	for (vector<conjunto::entrada>::iterator it = vc.begin() ; it != vc.end(); it++){
		if(it->getID() == e.getID()){
			solucion = true;
			vc.erase(it);
		}
	}

return solucion;  
}

conjunto & conjunto::operator=( const conjunto & org){

		
		this->vc = org.vc;

return *this;
}

conjunto::size_type conjunto::size() const {
	
return vc.size();
}

bool conjunto::empty() const{
	
return vc.size() == 0;	

}

bool conjunto::cheq_rep( ) const{

  bool solucion=true;
 
	for(unsigned int i = 0; i < vc.size() && solucion ; i++){
	
		if(vc[i].getID() <= 0){
			solucion = false;
		}	
	}
return solucion;

}


ostream& operator << ( ostream &sal, const conjunto & D){

		if(D.empty()){
			sal << "Conjunto vacio." ;

		}else{
			for(unsigned int i = 0; i< D.size(); i++){
				sal << D.getPos(i);
				sal << endl;
			}
		}
	return sal;
}

