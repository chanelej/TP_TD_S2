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
#include <cstring>

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

string Catalogue::ConstruireScript(int choixCritere, int &borneInf, int &borneSup, string &villeA, string &villeD) const{

	//NB pour toi : tous les paramètres au dessus là, c'est pour pouvoir mettre en place les diff critères mais ça
	//               je m'en occupe dans les classes que je vais créer comme je t'ai expliqué sur fb :)


	//1)Creer un Critère général (à faire une fois que j'aurai créer les classes)
	//2)Selon la valeur de choixCritere l'initialiser comme le critère correspondant (idem)
	//Pour chaque trajet du catalogue, vérifier s'il valide le critère, et si oui alors faire la suite :

	string chaine= "Nombre de trajets : "+std::to_string(nbItineraires)+"\n";
	for (int i = 0; i < nbItineraires; i++) {
		chaine += listeItineraires->Element(i)->Script();
	}
	return chaine;
}

bool Catalogue::ChargerScript(int choixCritere, int &borneInf, int &borneSup, string &villeA, string &villeD, string script) const{

    //Creer un Critère général (à faire une fois que j'aurai créer les classes)
	//Selon la valeur de choixCritere l'initialiser comme le critère correspondant (idem)
	//Pour chaque ligne du script envoyé, crée un trajet temporaire t
	// regarder s'il valide le critère, et si oui on l'ajoute au catalogue (comme tu as fait dans le main mais faut le mettre ici)

	//NB : ATTENTION : le trajet temporaire t doit être crée avec un pointeur et supprimé ensuite sinon on aura des pb ac valgrind

	/*

	Trajet *t;

	if(c'est un trajet simple){
        t=new TrajetSimple etc
	} if(c'est un trajet composé){
        t=new TrajetCompose etc
	}

	Tester si t passe les critères

	Si oui alors on l'ajoute avec une copie en profondeur et ensuite il faut bien penser à delete t ! ->

	t.Ajouter etc
	delete t;

	*/

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



	
