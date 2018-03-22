#--------------------------------------------------------------------
#Makefile Laboratorio 0 - Programacion 4
#
#Esto es un comentario
#--------------------------------------------------------------------

#Objetivo predeterminado
all: principal
    

#Objetivos que no son archivos

#directorios
HDIR = Cabezales
CPPDIR = Logica
ODIR = Obj

MODULES = A B C

#lista de archivos, con directorio y extension
HS = $(MODULES:%=$(HDIR)/%.h)
CPPS = $(MODULES:%=$(CPPDIR)/%.cpp)
OS = $(MODULES:%=$(ODIR)/%.o)

PRINCIPAL = principal
EJECUTABLE = principal

#compilador
CC = g++
#flags
CCFLAGS = -std=c++11 -g -Wall -Werror -I$(HDIR) 

$(ODIR)/%.o: $(CPPDIR)/%.cpp $(HDIR)/%.h
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/$(PRINCIPAL).o:$(PRINCIPAL).cpp
	$(CC) $(CCFLAGS) -c $< -o $@

$(EJECUTABLE): $(ODIR)/$(PRINCIPAL).o $(OS) 
	$(CC) $(CCFLAGS) $^ -o $@

run1: principal
	./principal

clean:
	rm -f $(EJECUTABLE) $(ODIR)/$(PRINCIPAL).o $(OS)
