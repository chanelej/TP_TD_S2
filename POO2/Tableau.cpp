/*************************************************************************
                           TABLEAU -  description
                             -------------------
    début                : 20/11/18
    copyright            : (C) Romain Perrone, Chanèle Jourdan - GROUPE 2_1
*************************************************************************/

//---------- Réalisation de la classe <TABLEAU (fichier Tableau.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include "Tableau.h"

using namespace std;

//------------------------------------------------------------- Méthodes publiques

void Tableau::InsererTrajet(Trajet *T)
{	
// Algorithme :
// Ajoute un pointeur vers un trajet à la suite des éléments du tableau, et le réalloue si nécessaire

	listeTrajets[nbElements] = T;
	nbElements++;

	if (nbElements >= size)	{
		Realloc();
	}
}

void Tableau::Rechercher(char* villeDep, char* villeArr) const
{
	// Algorithme :
	// Recherche simple.
	// Parcourt le tableau et affiche tous les trajets (simples/composés).
	// partant de villeDep et allant à villeArr.

	int count = 0;

	for (int i = 0; i < nbElements; i++) {

		// pour chaque élément, on récupère les villes de départ et d'arrivée
		const char * vDep = listeTrajets[i]->getVilleDep();
		const char * vArr = listeTrajets[i]->getVilleArr();

		// si elles correspondent à l'itinéraire recherché, on affiche le Trajet.
		if (strcmp(vDep, villeDep) == 0 && strcmp(vArr, villeArr) == 0)
		{
			cout << count + 1 << ": ";
			listeTrajets[i]->Afficher();

			count++;
		}
	}

	if (count == 0) {
		cout << "Aucun trajet ne correspond à la demande." << endl;
	}

	cout << endl;
}

void Tableau::Afficher() const
{	
	// Algorithme :
	// Parcourt le tableau et fait appel à la méthode Afficher pour chaque trajet pointé

	if (nbElements == 0)
	{
		cout << "Aucun élément à afficher." << endl;
		return;
	}

	for(int i=0; i<nbElements; i++){
		listeTrajets[i]->Afficher();
	}
}

void Tableau::AfficherElement(int i) const
{	
	if (nbElements == 0 || i > nbElements)
	{
		cout << "Aucun élément à afficher." << endl;
		return;
	}

	listeTrajets[i]->Afficher();
}

Trajet* Tableau::Element(int i) const {
	
	return listeTrajets[i];
	
}


void Tableau::Realloc()
{	
	size = size * FACTEUR_REALLOC_TABLEAU;
	Trajet **reallocListeTrajets = new Trajet*[size];

	for (int i = 0; i<nbElements; i++) {
		Trajet * t = listeTrajets[i]->copy();
		reallocListeTrajets[i] = t;
	}

	delete[] listeTrajets;
	listeTrajets = reallocListeTrajets;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Tableau::Tableau(int s) : size (s), nbElements(0) {
	#if defined (MAP)
		cout << "Appel au constructeur Tableau, size = " << size << endl;
	#endif

	listeTrajets = new Trajet*[ALLOC_INITIALE_TABLEAU];
}

Tableau::Tableau(Tableau const& unTableau)
{
	if (this != &unTableau)
	{
		size = unTableau.size;
		nbElements = unTableau.nbElements;
		listeTrajets = new Trajet*[size];

		for (int i = 0; i < nbElements; i++) {
			Trajet * t = unTableau.listeTrajets[i]->copy();
			listeTrajets[i] = t;
		}
	}
}

Tableau::~Tableau() {
	#if defined (MAP)
		cout << "Appel au destructeur Tableau" << endl;
	#endif

	delete[] listeTrajets;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
