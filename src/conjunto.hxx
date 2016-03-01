#include "conjunto.h"
//INICIO PRACTICA 4

// __________________________________IMPLEMENTACION CrecienteIUCR ____________________________________________

		 
   		bool CrecienteIUCR::operator()(const crimen &a, const crimen &b){
				return (a.getIUCR()<b.getIUCR());
		}

		bool CrecienteID::operator()(const crimen &a, const crimen &b){
				return (a.getID()<b.getID());
		}

		bool DecrecienteID::operator()(const crimen &a, const crimen &b){
				return (a.getID()>b.getID());
		}


		bool CrecienteFecha::operator()(const crimen &a, const crimen &b){
				return (a.getDate()<b.getDate());
		}

		bool DecrecienteFecha::operator()(const crimen &a, const crimen &b){
				return (a.getDate()>b.getDate());
		}

	


// __________________________________FIN_IMPLEMENTACION CrecienteIUCR ____________________________________________

// ================================= ITERADORCONJUNTO ========================================/

	template <typename CMP> 
	typename conjunto<CMP>::iterator conjunto<CMP>::begin(){
		iterator iterador;
  		iterador.itv=vc.begin();
  		return iterador;
	}

	template <typename CMP> 
	typename conjunto<CMP>::iterator conjunto<CMP>::end(){
		iterator iterador;
  		iterador.itv=vc.end();
  		return iterador;
	}

	template <typename CMP> 
	conjunto<CMP>::iterator::iterator(){
		
	}
	template <typename CMP> 
	conjunto<CMP>::iterator::iterator(const conjunto<CMP>::iterator & it){
		itv = it.itv;
	}
	template <typename CMP> 
	conjunto<CMP>::iterator::iterator(const vector<conjunto<CMP>::entrada>::iterator n){
		itv=n;
	}
		
	template <typename CMP>    
	const typename conjunto<CMP>::entrada & conjunto<CMP>::iterator::operator*() const{
			return *itv;
	}
		   
	template <typename CMP>    
	typename conjunto<CMP>::iterator conjunto<CMP>::iterator::operator++( int ){
		//Aquí hay que hacer una copia e incrementar el iterador, pero devolver la copia, porque es el operador de Pre-incremento.
			conjunto<CMP>::iterator copia(itv);
			++itv;
			return copia;
			
	}

	template <typename CMP> 
	typename conjunto<CMP>::iterator & conjunto<CMP>::iterator::operator++(){
			itv++;
			return *this;
	}

	template <typename CMP> 
	typename conjunto<CMP>::iterator conjunto<CMP>::iterator::operator--(int){
		//Aquí hay que hacer una copia e decrementar el iterador, pero devolver la copia, porque es el operador de Pre-decremento.
			conjunto<CMP>::iterator copia(itv);
			--itv;
			return copia;
	}	
		
	template <typename CMP> 	
	typename conjunto<CMP>::iterator & conjunto<CMP>::iterator::operator--(){
			itv--;
			return *this;
		   
	}

	template <typename CMP> 
	bool conjunto<CMP>::iterator::operator==(const iterator & it){
			return it.itv==itv;
	}
	
	template <typename CMP>
	bool conjunto<CMP>::iterator::operator!=(const iterator & it){
			return it.itv!=itv;
	}


// ================================= FIN-ITERADORCONJUNTO ========================================/







// ================================= CONST__ITERADORCONJUNTO ========================================/
	template <typename CMP>
	typename conjunto<CMP>::const_iterator conjunto<CMP>::cbegin()const{
		const_iterator iterador;
  		iterador.c_itv=vc.begin();
  		return iterador;
	}

	template <typename CMP>
	typename conjunto<CMP>::const_iterator conjunto<CMP>::cend()const{
		const_iterator iterador;
  		iterador.c_itv=vc.end();
  		return iterador;
	}

	template <typename CMP>
	conjunto<CMP>::const_iterator::const_iterator(){
		
	}

	template <typename CMP>
	conjunto<CMP>::const_iterator::const_iterator(const vector<conjunto::entrada>::const_iterator n){
		c_itv=n;
	}

	template <typename CMP>
	conjunto<CMP>::const_iterator::const_iterator(const conjunto::const_iterator & it){
		c_itv = it.c_itv;
	}

	template <typename CMP>   
	const typename conjunto<CMP>::entrada & conjunto<CMP>::const_iterator::operator*() const{
			return *c_itv;
	}
		   
	template <typename CMP>	   
	typename conjunto<CMP>::const_iterator conjunto<CMP>::const_iterator::operator++( int ){
		//Aquí hay que hacer una copia e incrementar el iterador, pero devolver la copia, porque es el operador de Pre-incremento.
			conjunto::const_iterator copia(c_itv);
			++c_itv;
			return copia;
			
	}
	
	template <typename CMP>
	typename conjunto<CMP>::const_iterator & conjunto<CMP>::const_iterator::operator++(){
			c_itv++;
			return *this;
	}

	template <typename CMP>
	typename conjunto<CMP>::const_iterator conjunto<CMP>::const_iterator::operator--(int){
		//Aquí hay que hacer una copia e decrementar el iterador, pero devolver la copia, porque es el operador de Pre-decremento.
			conjunto::const_iterator copia(c_itv);
			--c_itv;
			return copia;
	}			
		
	template <typename CMP>	
	typename conjunto<CMP>::const_iterator & conjunto<CMP>::const_iterator::operator--(){
			c_itv--;
			return *this;
		   
	}

	template <typename CMP>
	bool conjunto<CMP>::const_iterator::operator==(const const_iterator & it){
			return it.c_itv==c_itv;
	}

	template <typename CMP>
	bool conjunto<CMP>::const_iterator::operator!=(const const_iterator & it){
			return it.c_itv!=c_itv;
	}





// ================================= FIN-CONST__ITERADORCONJUNTO ========================================/






//Constructor por defecto

template <typename CMP> 
conjunto<CMP>::conjunto(){
}

	
//Constructor de copia
template <typename CMP> 
conjunto<CMP>::conjunto(const conjunto<CMP> & d){

	
	this->vc = d.vc;
}

//Constructor de copia
template <typename CMP> 
conjunto<CMP>::conjunto(typename conjunto<CMP>::iterator & inicio, typename conjunto<CMP>::iterator &fina){

	while(inicio!=fina){

		insert(*inicio);
		inicio++;
	}
	
}

template <typename CMP>
typename conjunto<CMP>::iterator conjunto<CMP>::find(const crimen &c){
	
		conjunto<CMP>::iterator salida;
		salida.itv = vc.begin() + busquedaBinaria(c);
		return salida;


}

template <typename CMP>
typename conjunto<CMP>::const_iterator conjunto<CMP>::find(const crimen &c)const{
	
		conjunto<CMP>::const_iterator salida;
		salida.c_itv = vc.begin() + busquedaBinaria(c);
		return salida;


}

template <typename CMP>
typename conjunto<CMP>::iterator conjunto<CMP>::find(const long int &id){
	
		conjunto<CMP>::iterator solucion;
		solucion.itv = vc.begin();
		bool encontrado = false;

		while(solucion != vc.end() && !encontrado){
	
			if((*solucion).getID() == id){
				solucion = true;
			}else{
				solucion++;
			}



		}
		return solucion;


}

template <typename CMP>
typename conjunto<CMP>::const_iterator conjunto<CMP>::find(const long int &id)const{
	
		conjunto<CMP>::const_iterator solucion;
		solucion = this->find(id);
		return solucion;


}

template <class CMP>
typename conjunto<CMP>::iterator conjunto<CMP>::lower_bound (const conjunto<CMP>::entrada & x){

	 	typename conjunto<CMP>::iterator solucion;
		solucion.itv = vc.begin();
		bool encontrado = false;		
			
		while (solucion < vc.end() && !encontrado){
				if (cmp(x, *solucion) || x == *solucion){
					encontrado = true;
				}else{ 
					solucion++;
				}
			
		}


		return solucion;
}

template <class CMP>
typename conjunto<CMP>::const_iterator conjunto<CMP>::lower_bound (const conjunto<CMP>::entrada & x)const{

	 	typename conjunto<CMP>::const_iterator solucion;
		solucion = this-> lower_bound(x);
		return solucion;
}

template <class CMP>
typename conjunto<CMP>::iterator conjunto<CMP>::upper_bound (const conjunto<CMP>::entrada & x){

		 typename conjunto<CMP>::iterator solucion;
		solucion.itv = vc.begin();
		bool encontrado = false;		
			
		while (solucion < vc.end() && !encontrado){
				if (cmp(x, *solucion)){
					encontrado = true;
				}else{ 
					solucion++;
				}
			
		}


		return solucion;

}

template <class CMP>
typename conjunto<CMP>::const_iterator conjunto<CMP>::upper_bound (const conjunto<CMP>::entrada & x)const{

		 typename conjunto<CMP>::const_iterator solucion;
		 solucion = this->upper_bound(x);

		return solucion;

}











template <typename CMP> 
pair< typename conjunto<CMP>::entrada,bool>  conjunto<CMP>::findID( const long int & id) const{

	pair<conjunto<CMP>::entrada, bool> solucion;
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
	
template <typename CMP> 
conjunto<CMP> conjunto<CMP>::findIUCR( const string & iucr) const{
			
		
	conjunto<CMP> solucion;
	
	for(size_t i =0;  i<vc.size() ; i++){
		if(vc[i].getIUCR() == iucr){
				
			solucion.insert(vc[i]);
			
		
		}
		
	}


return solucion;

}

template <typename CMP> 
conjunto<CMP> conjunto<CMP>::findDESCR( const string & descr) const{

	conjunto<CMP> solucion;

	for(size_t i =0;  i<vc.size()  ; i++){
		if(vc[i].getDescr() == descr){
				
			solucion.insert(vc[i]);
		
		
		}
		
	}

return solucion;
}

template <typename CMP> 
int conjunto<CMP>::busquedaBinaria(const crimen & e)const{

		int fin=vc.size()-1;
    	int inicio = 0;
		int medio = 0;
		bool encontrado=false;

		while (fin > inicio && !encontrado) {

      			medio = (inicio+fin)/2;

      			if (!comp(vc[medio],e) && !comp(e,vc[medio]) ){ 
					encontrado=true;
  
      			}else if (comp(vc[medio],e)){
					inicio = medio+1;
 
      			}else{ 
					fin = medio-1;
				}
    		}

    		return medio;
}

template <typename CMP> 
bool conjunto<CMP>::insert( const conjunto<CMP>::entrada & e){
		
 		bool insertado = false;
        for (int i =0; !insertado && i < vc.size(); )
            if (comp(vc[i],e) ){
				 i++;
			}else {
              vc.insert(vc.begin()+i,e);
              insertado = true;
            }
		    if (!insertado){
				vc.push_back(e);
				insertado = true;
			}

return true;
}			

template <typename CMP> 
bool conjunto<CMP>::erase(const long int & id){
	
	bool solucion = false;
	
	for (vector<conjunto<CMP>::entrada>::iterator it = vc.begin() ; it != vc.end(); it++){
		if(it->getID() == id){
			solucion = true;
			vc.erase(it);
			
		}
	}

return solucion;  

}

template <typename CMP> 
bool conjunto<CMP>::erase(const  conjunto<CMP>::entrada & e){

		bool solucion = false;
	
	for (vector<conjunto<CMP>::entrada>::iterator it = vc.begin() ; it != vc.end(); it++){
		if(it->getID() == e.getID()){
			solucion = true;
			vc.erase(it);
		}
	}

return solucion;  
}

template <typename CMP> 
conjunto<CMP> & conjunto<CMP>::operator=( const conjunto<CMP> & org){

		
		this->vc = org.vc;

return *this;
}

template <typename CMP> 
typename conjunto<CMP>::size_type conjunto<CMP>::size() const {
	
return vc.size();
}

template <typename CMP> 
bool conjunto<CMP>::empty() const{
	bool solucion = false;
		if (vc.size() == 0){
				solucion = true;
		}
return solucion;	

}

template <typename CMP> 
bool conjunto<CMP>::cheq_rep( ) const{

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

template <typename CMP> 
ostream& operator << ( ostream &sal, const conjunto<CMP> & D){

		if(D.empty()){
			sal << "Conjunto vacio." ;

		}else{
			for(unsigned int i = 0; i < D.size(); i++){
				sal << D.getPos(i);
				sal << endl;
			}
		}
	return sal;
}



