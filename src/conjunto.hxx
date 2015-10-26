#include "conjunto.h"

//Constructor por defecto
  
conjunto::conjunto( ){
	
	entrada;
	size_type=0;
		
	
	

//Constructor de copia
	
conjunto::conjunto (const conjunto & d){

	entrada = d.entrada;
	size_type = d.size_type;

}

pair<conjunto::entrada,bool>  findID( const long int & id) const;


conjunto<conjunto::entrada>  findIUCR( const string & iucr) const;

conjunto<conjunto::entrada>  findDESCR( const string & descr) const;

bool insert( const conjunto::entrada & e);

bool erase(const long int & id);

bool erase(const  conjunto::entrada & e);

conjunto & operator=( const conjunto & org);

size_type size() const ;

bool empty() const;

bool cheq_rep( ) const;

ostream &  operator << ( ostream & sal, const conjunto & D);

#endif
