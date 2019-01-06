.PHONY: $(clean)

#variables

CC=g++
RM=rm
CLEAN=clean

CFLAGS=-c -ansi -pedantic -g -std=c++11 -DMAP
LDFLAGS=-ansi -pedantic -g -std=c++11 -DMAP

SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=GestionDeTrajets


#édition des liens :
$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $(EXECUTABLE) $(OBJECTS) $(LDFLAGS)
	
#compilation :	
%.o: %.cpp
	 $(CC) -o $@ $(CFLAGS) $<
	
#suppression :	
$(CLEAN):
	@$(RM) $(OBJECTS) $(EXECUTABLE) core

#liens entre les fichiers
main.o: Catalogue.h
Tableau.o: Tableau.h Trajet.h Graphe.h
Trajet.o:Trajet.h
TrajetSimple.o: Trajet.h TrajetSimple.h
TrajetCompose.o: TrajetCompose.h Trajet.h Tableau.h
Catalogue.o: Catalogue.h Tableau.h Graphe.h TrajetSimple.h TrajetCompose.h Critere.h
Noeud.o: Noeud.h
Graphe.o: Graphe.h Noeud.h
Critere.o: Critere.h Trajet.h
CritereDeVilles.o: CritereDeVilles.h Critere.h
CritereAvecIntervalle.o: CritereAvecIntervalle.h Critere.h
CritereDeType.o: CritereDeType.h Critere.h
