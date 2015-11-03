#Makefile
#
#Carpetas:
BIN=./bin
INCLUDE=include
SRC=./src
OBJ=./obj
LIB=./lib
DOC = ./doc
#
#
#Compiladores
CXX = g++
#
#
#Flags
CPPFLAGS = -Wall -g -c -I$(INCLUDE)
#
#
#
#
#TODO
all: clean $(BIN)/principal
#
#COMPILACION

$(BIN)/principal : $(OBJ)/principal.o $(LIB)/libcrimenes.a
	$(CXX) $(OBJ)/principal.o $(LIB)/libcrimenes.a -o $(BIN)/principal 

$(OBJ)/principal.o : $(SRC)/principal.cpp $(INCLUDE)/conjunto.h $(INCLUDE)/crimen.h $(INCLUDE)/fecha.h
	$(CXX) $(CPPFLAGS)  $(SRC)/principal.cpp -o $(OBJ)/principal.o 

$(LIB)/libcrimenes.a : $(OBJ)/crimen.o $(OBJ)/fecha.o $(OBJ)/conjunto.o
	ar -rvs $(LIB)/libcrimenes.a $(OBJ)conjunto.o $(OBJ)crimen.o $(OBJ)fecha.o 

$(OBJ)/conjunto.o : $(SRC)/conjunto.hxx $(INCLUDE)/conjunto.h $(INCLUDE)/fecha.h $(INCLUDE)/crimen.h
	$(CXX) $(CPPFLAGS)  $(SRC)/conjunto.hxx -o $(OBJ)/conjunto.o

$(OBJ)/crimen.o : $(SRC)/crimen.hxx $(INCLUDE)/crimen.h $(INCLUDE)/fecha.h 
	$(CXX) $(CPPFLAGS)   $(SRC)/crimen.hxx -o  $(OBJ)/crimen.o 

$(OBJ)/fecha.o : $(SRC)/fecha.hxx $(INCLUDE)/fecha.h 
	$(CXX) $(CPPFLAGS)  $(SRC)/fecha.hxx -o $(OBJ)/fecha.o



#
#
#
#
# ************ documentación *******

documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************

clean:
	@echo "Limpiando archivos objetos "
	@rm -f $(OBJ)/*
	@rm -f $(LIB)/*
	@rm -f $(BIN)/*

	
	
mrproper: clean

