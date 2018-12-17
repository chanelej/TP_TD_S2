/*************************************************************************
                           TRAJET  -  description
                             -------------------
    début                : 20/11/18
    copyright            : (C) Romain Perrone, Chanèle Jourdan - GROUPE 2_1
*************************************************************************/

//---------- Réalisation de la classe <CATALOGUE> (fichier Catalogue.cpp) -------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

using namespace std;

//------------------------------------------------------------- Constantes

void Catalogue::Afficher() const
{
	listeItineraires->Afficher();
}

void Catalogue::AjouterTrajet(Trajet *t)
{
	listeItineraires->InsererTrajet(t);
	GrapheTrajets.AjouterTrajet(t->getVilleDep(), t->getVilleArr());
	nbItineraires++;
}

string Catalogue::ConstruireScript(int i) const{
	string chaine= "Nombre de trajets : "+std::to_string(nbItineraires);
	for (int i = 0; i < nbItineraires; i++) {
		chaine += listeItineraires->Element(i)->Script();
	}
	return chaine;
}

void Catalogue::Rechercher(char* villeDep, char* villeArr) const
{
	GrapheTrajets.RechercheAvancee(villeDep, villeArr);
}


//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue()
{
	#if defined (MAP)
		cout << "Appel au constructeur de Catalogue" << endl;
	#endif

	nbItineraires = 0;

	listeItineraires = new Tableau();
	Graphe GrapheTrajets;
}

Catalogue::~Catalogue() {
	#if defined (MAP)
		cout << "Appel au destructeur de Catalogue" << endl;
	#endif
		
	delete[] listeItineraires;
}

 //------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

	
