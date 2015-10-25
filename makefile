#Makefile
#
#Carpetas:
BIN = bin
SRC = src
OBJ = obj
LIB = lib
DOC = doc
INCLUDE = include
#
#
#Compiladores
CXX = g++ -Ofast
CC = gcc -Ofast
#
#
#Flags
LDFLAGS =
CPPFLAGS = -Wall -g -c
#
#
#
#
#TODO
all: clean $(BIN)/principal
#
#COMPILACION
$(BIN)/principal : $(OBJ)/principal.o $(LIB)/libcrimenes.a
	$(CXX) -o $(BIN)/principal $(OBJ)/principal.o -I$(INCLUDE) -L$(LIB) -lcrimenes

$(LIB)/libcrimenes.a : $(OBJ)crimen.o $(OBJ)fecha.o
	ar rvs $(LIB)/libcrimenes.a $(OBJ)crimen.o $(OBJ)fecha.o

$(OBJ)/fecha.o : $(SRC)/fecha.hxx
	$(CXX) $(CPPFLAGS) -c -o $(OBJ)/fecha.o $(SRC)/fecha.hxx -I$(INCLUDE)

$(OBJ)/crimen.o : $(SRC)/crimen.hxx $(OBJ)/fecha.o
	$(CXX) $(CPPFLAGS) -c -o $(OBJ)/crimen.o $(SRC)/crimen.hxx $(OBJ)/fecha.o -I$(INCLUDE)

$(OBJ)/principal.o : $(SRC)/principal.cpp $(OBJ)/crimen.o $(OBJ)/fecha.o
	$(CXX) $(CPPFLAGS) -c -o $(OBJ)/principal.o $(SRC)/principal.cpp $(OBJ)/crimen.o $(OBJ)/fecha.o -I$(INCLUDE)
#
#
#
#
clean:
	@echo "Limpiando archivos objetos "
	@rm -f $(OBJ)/*
	@rm -f $(LIB)/*
	@rm -f $(BIN)/*
	   

