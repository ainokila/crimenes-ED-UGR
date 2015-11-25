#include "conjunto.h"
//INICIO PRACTICA 3


// ================================= ITERADORCONJUNTO ========================================/


conjunto::iterator conjunto::begin(){
	return iterator(vc.begin());
}

conjunto::iterator conjunto::end(){
	return iterator(vc.end());
}

conjunto::iterator::iterator(vector<conjunto::conjunto::entrada>::iterator itn ){
	itv=itn;
}
conjunto::iterator::iterator(const conjunto::iterator & it){
	itv = it.itv;
}
       
const conjunto::entrada & conjunto::iterator::operator*() const{
		return *itv;
}
	   
       
conjunto::iterator conjunto::iterator::operator++( int ){
	//Aquí hay que hacer una copia e incrementar el iterador, pero devolver la copia, porque es el operador de Pre-incremento.
		vector<entrada>::iterator copia = itv;
		++itv;
		return copia;
			
}
conjunto::iterator & conjunto::iterator::operator++(){
		itv++;
		return *this;
}
conjunto::iterator conjunto::iterator::operator--(int){
	//Aquí hay que hacer una copia e decrementar el iterador, pero devolver la copia, porque es el operador de Pre-decremento.
		vector<entrada>::iterator copia = itv;
		--itv;
		return copia;
}			
			
conjunto::iterator & conjunto::iterator::operator--(){
		itv--;
		return *this;
	   
}
bool conjunto::iterator::operator==(const iterator & it){
		return it.itv==itv;
}
bool conjunto::iterator::operator!=(const iterator & it){
		return it.itv!=itv;
}


// ================================= FIN-ITERADORCONJUNTO ========================================/




// ================================= CONST__ITERADORCONJUNTO ========================================/

conjunto::const_iterator conjunto::cbegin()const{
	return const_iterator(vc.begin());
}

conjunto::const_iterator conjunto::cend()const{
	return const_iterator(vc.end());
}

conjunto::const_iterator::const_iterator(vector<conjunto::conjunto::entrada>::const_iterator itn ){
	c_itv=itn;
}
conjunto::const_iterator::const_iterator(const conjunto::const_iterator & it){
	c_itv = it.c_itv;
}
       
const conjunto::entrada & conjunto::const_iterator::operator*() const{
		return *c_itv;
}
	   
       
conjunto::const_iterator conjunto::const_iterator::operator++( int ){
	//Aquí hay que hacer una copia e incrementar el iterador, pero devolver la copia, porque es el operador de Pre-incremento.
		vector<entrada>::const_iterator copia = c_itv;
		++c_itv;
		return copia;
			
}
conjunto::const_iterator & conjunto::const_iterator::operator++(){
		c_itv++;
		return *this;
}
conjunto::const_iterator conjunto::const_iterator::operator--(int){
	//Aquí hay que hacer una copia e decrementar el iterador, pero devolver la copia, porque es el operador de Pre-decremento.
		vector<entrada>::const_iterator copia = c_itv;
		--c_itv;
		return copia;
}			
			
conjunto::const_iterator & conjunto::const_iterator::operator--(){
		c_itv--;
		return *this;
	   
}
bool conjunto::const_iterator::operator==(const const_iterator & it){
		return it.c_itv==c_itv;
}
bool conjunto::const_iterator::operator!=(const const_iterator & it){
		return it.c_itv!=c_itv;
}





// ================================= FIN-CONST__ITERADORCONJUNTO ========================================/

//Constructor por defecto

conjunto::conjunto(){
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
		
		for(unsigned int i = 0; i< vc.size()-1 && solucion; i++){
			if(vc[i+1]<vc[i]){
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



