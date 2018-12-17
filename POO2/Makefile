.PHONY: clean

CC=g++
CFLAGS=-c -ansi -pedantic -g -std=c++11 -DMAP
LDFLAGS=-ansi -pedantic -g -std=c++11 -DMAP
SOURCES=main.cpp Tableau.cpp Trajet.cpp TrajetSimple.cpp TrajetCompose.cpp Catalogue.cpp Graphe.cpp Noeud.cpp
OBJECTS=$(SOURCES:.cpp=.o)

GestionDeTrajets: $(OBJECTS)
	$(CC) -o GestionDeTrajets $(OBJECTS) $(LDFLAGS)

main.o: main.cpp
	$(CC) -o $@ $(CFLAGS) $< 
	
Tableau.o: Tableau.cpp Tableau.h
	$(CC) -o $@ $(CFLAGS) $< 

Trajet.o: Trajet.cpp Trajet.h
	$(CC) -o $@ $(CFLAGS) $< 

TrajetSimple.o: TrajetSimple.cpp Trajet.h TrajetSimple.h
	$(CC) -o $@ $(CFLAGS) $< 

TrajetCompose.o: TrajetCompose.cpp TrajetCompose.h Trajet.h Tableau.h
	$(CC) -o $@ $(CFLAGS) $< 

Catalogue.o: Catalogue.cpp Catalogue.h Trajet.h Tableau.h
	$(CC) -o $@ $(CFLAGS) $< 

Noeud.o: Noeud.cpp Noeud.h
	$(CC) -o $@ $(CFLAGS) $<

Graphe.o: Graphe.cpp Graphe.h
	$(CC) -o $@ $(CFLAGS) $<
	
clean:
	rm $(OBJECTS) $(EXECUTABLE) core
