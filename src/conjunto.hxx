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
			unsigned int aux = id;

		if (busquedaBinaria(aux) != -1){
			if(vc[busquedaBinaria(aux)].getID() == id){
				solucion.first = vc[busquedaBinaria(id)];
				solucion.second = true;
		
			}
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
int conjunto::busquedaBinaria(const long int & e)const{
		int primero = 0 ;
			int ultimo = vc.size()-1;

			while(primero<=ultimo){
				int central = (int) (primero+ultimo)/2;
			
				if(e == vc[central].getID()){
						primero = -1;
						ultimo = -2;
				}else if ( e < vc[central].getID() ) {
					ultimo = central -1 ;
				}else{
					primero = central +1 ;
				}
			}
			
return primero;
}
bool conjunto::insert( const conjunto::entrada & e){
		
		bool solucion = true;
		if(empty()){
			vc.push_back(e);
		}else{

			int posicion = busquedaBinaria(e.getID());
			if(posicion == -1){
					solucion = false;
			}
			else{
				vc.insert(vc.begin()+posicion, e);
			}
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
	bool solucion = false;
		if (vc.size() == 0){
				solucion = true;
		}
return solucion;	

}

bool conjunto::cheq_rep( ) const{

  bool solucion=true;
 
		if(vc[0].getID() <= 0){
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
//INICIO PRACTICA 3


/*! Implementacion  de la clase conjunto

*/

/** @todo implementar la funcion
*/

conjunto::conjunto(){
  lo que se tenga que poner
}

conjunto::iterator conjunto::begin() const{
conjunto::iterator sal;
	sal.itv = vc.begin();
        return sal;
}


conjunto::iterator conjunto::end() const{
conjunto::iterator sal;
	sal.itv = vc.end();
        return sal;
}
/** @brief constructor defecto iterator
*/
conjunto::iterator::iterator(){

}

/** @brief constructor copia iterator
*/
conjunto::iterator::iterator(const conjunto::iterator & i)
  itv = i.itv;
}


