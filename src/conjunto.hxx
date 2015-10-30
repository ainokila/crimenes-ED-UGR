#include "conjunto.h"

//Constructor por defecto
  
conjunto::conjunto( ){

	size_type = 0;
}

	
//Constructor de copia
	
conjunto::conjunto (const conjunto & d){

	entrada = d.entrada;
	size_type = d.size_type;
	vc = d.getVector();
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
	
conjunto<conjunto::entrada>  conjunto::findIUCR( const string & iucr) const{
			
		
	conjunto<conjunto::entrada> solucion;
	
	for(size_t i =0;  i<vc.size() && ; i++){
		if(vc[i].getIUCR() == iucr){
				
			solucion.push_back(vc[i]);
			size_type++;
		
		}
		
	}


return solucion;

}


conjunto<conjunto::entrada>  conjunto::findDESCR( const string & descr) const{

	conjunto<conjunto::entrada> solucion;

	for(size_t i =0;  i<vc.size() && ; i++){
		if(vc[i].getDescr() == descr){
				
			solucion.push_back(vc[i]);
			size_type++;
		
		}
		
	}

return solucion;
}

bool conjunto::insert( const conjunto::entrada & e){

	bool solucion = false;

	if(!(findID(e.getID()).second)){
		
		solucion = true;
		vc.push_back(e);
		size_type++;
		
	}
return solucion;
}


bool conjunto::erase(const long int & id){
	
	bool solucion = false;
	
	for (vector<conjunto::entrada>::iterator it = vc.begin() ; it != vc.end(); it++){
		if(it.getID() == id){
			solucion = true;
			vc.erase(it);
			size_type--;
		}
	}

return solucion;  

}

bool conjunto::erase(const  conjunto::entrada & e){

		bool solucion = false;
	
	for (vector<conjunto::entrada>::iterator it = vc.begin() ; it != vc.end(); it++){
		if(it.getID() == e.getID){
			solucion = true;
			vc.erase(it);
		}
	}

return solucion;  
}

conjunto & conjunto::operator=( const conjunto & org){

		entrada = org.entrada;
		size_type = org.size_type;
		vc = org.getVector();

return *this;
}

size_type conjunto::size() const {
	
return size_type;
}

bool conjunto::empty() const{
	
return size_type == 0;	

}

bool conjunto::cheq_rep( ) const{

  bool solucion=true;
 
	for(int i = 0; i < vc.size() && solucion ; i++){
	
		if(vc[i].ID <= 0){
			solucion = false;
		}

return solucion;

}

ostream &  conjunto::operator << ( ostream &sal, const conjunto & D){

		if(D.empty()){
			sal << "Conjunto vacio." ;

		}else{
			for(int i = 0; i< D.vc.size(); i++){
				sal << D.vc[i];
				sal << endl;
			}
		}

	return sal;
}

#endif