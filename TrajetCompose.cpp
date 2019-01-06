/*************************************************************************
                           TRAJET_COMPOSE -  description
                             -------------------
    début                : 20/11/18
    copyright            : (C) Romain Perrone, Chanèle Jourdan - GROUPE 2_1
				+ Quentin Ferro - Groupe 2_28
*************************************************************************/

//---------- Réalisation de la classe <TRAJET_COMPOSE> (fichier TrajetCompose.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes
//----------------------------------------------------- Méthodes publiques

void TrajetCompose::Ajouter(Trajet *t)
{
	// Ajout d'un trajet simple à la liste de trajet
	listeTrajets->InsererTrajet(t);

	// lors du premier ajout, définir la ville de départ du trajet.
	if (strcmp(Trajet::vDep, "") == 0) {
		Trajet::vDep = t->getVilleDep();
	}

	Trajet::vArr = t->getVilleArr();
	nbTrajetsSimple++;
}

void TrajetCompose::Afficher() const
{
// Algorithme :
// Parcourt du tableau et appel de la méthode Afficher de chacun de ses éléments

	cout << "Trajet composé :" << endl;

	for (int i = 0; i < nbTrajetsSimple; i++) {
		cout << "Etape " << i+1 << ": ";
		listeTrajets->AfficherElement(i);
	}
}

string TrajetCompose::Script(){
	string vD=vDep;
	string vA=vArr;
	string chaine ="TC :"+vD+","+vA+" nombres d’étapes - "+std::to_string(nbTrajetsSimple)+"\n";
	for (int i = 0; i < nbTrajetsSimple; i++) {
		chaine += "\t"+listeTrajets->Element(i)->Script();
	}
	return chaine;
}

Trajet * TrajetCompose::copy()
{
	Trajet *t;
	TrajetCompose *t_compose = new TrajetCompose(*this);
	t = t_compose;

	return t;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

TrajetCompose::TrajetCompose() : Trajet(), nbTrajetsSimple(0)
{
// Algorithme :
// Création d'un Tableau représentant la liste des trajets et définition des villes de départ et d'arrivée

	#if defined (MAP)
		cout << "Appel au constructeur TrajetCompose" << endl;
	#endif

	listeTrajets = new Tableau();
	Trajet::vDep = "";
	Trajet::vArr = "";
}

TrajetCompose::TrajetCompose(TrajetCompose const& unTrajetCompose)
{
	if (this != &unTrajetCompose)
	{
		char * villeDep = new char[strlen(unTrajetCompose.vDep) + 1];
		char * villeArr = new char[strlen(unTrajetCompose.vArr) + 1];

		strcpy(villeDep, unTrajetCompose.vDep);
		strcpy(villeArr, unTrajetCompose.vArr);

		Trajet::vDep = villeDep;
		Trajet::vArr = villeArr;

		nbTrajetsSimple = unTrajetCompose.nbTrajetsSimple;
		Tableau listeTrajets(*unTrajetCompose.listeTrajets);
	}
}

TrajetCompose::~TrajetCompose()
{
	#if defined (MAP)
		cout << "Appel au destructeur TrajetCompose" << endl;
	#endif
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


