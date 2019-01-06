/*************************************************************************
                           CATALOGUE  -  description
                             -------------------
    début                : 20/11/18
    copyright            : (C) Romain Perrone, Chanèle Jourdan - GROUPE 2_1
				+ Quentin Ferro - Groupe 2_28
*************************************************************************/

//---------- Interface du module <CATALOGUE> (fichier Catalogue.h) -------------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

#include <cstring>

#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Graphe.h"
#include "Tableau.h"

using namespace std;

//------------------------------------------------------------------------
// Rôle du module <CATALOGUE>
// Représente un catalogue constitué d'un ensemble de trajets.
// Permet d'ajouter des trajets au catalogue, de  rechercher un itinéraire
//(recherche simple et recherche avancée) et d'afficher la liste des trajets.

//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées


//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

class Catalogue {

//////////////////////////////////////////////////////////////////  PUBLIC
		public :
//---------------------------------------------------- Fonctions publiques
		void AjouterTrajet(Trajet *t);
		// Mode d'emploi :
		//	Ajoute un trajet au catalogue.
		// Contrat :
		//	Aucun

		void Rechercher(char* villeDep, char* villeArr) const;
		// Mode d'emploi :
		//	Recherche un itinéraire à partir d'une ville de
		//      départ et d'une ville d'arrivée.
		//  Remarque: Un trajet composé ne peut pas être interrompu
		//      en cours de route.
		// Contrat :
		//	Aucun

		string ConstruireScript(int choixCritere, int &borneInf, int &borneSup, string &villeA, string &villeD) const;
		// Mode d'emploi :
		// 		Construit le script correspondant à la sauvegarde dans le fichier, en prenant
		// en compte le critère de sélection choisi par l'utilisateur
		// Contrat :
		//	Aucun

		void ChargerScript(std::string name, int nbSkip, int choixCritere, int &borneInf, int &borneSup, string &villeA, string &villeD);
		// Mode d'emploi :
		// 		Ajoute dans le catalogue courant, tous les trajets correspondant au script passé en paramètre,
		// en prenant en compte le critère de sélection choisi par l'utilisateur
		// Contrat :
		//	Aucun

		int ChargerScript(TrajetCompose *traj, std::string name, int nbSkip, int choixCritere, int &borneInf, int &borneSup, string &villeA, string &villeD);
		// Mode d'emploi :
		// 		Utilisé pour un appel récursif lorsque l’on tombe sur un trajet composé
		// Contrat :
		//	Aucun
		
		void Concat(Catalogue &c) const;
		// Mode d'emploi :
		// 	Ajoute les trajets du catalogue courant au catalogue c
		// Contrat :
		//	Aucun

		void Afficher() const;
		// Mode d'emploi :
		//	Affiche l'ensemble des trajets qui constituent le catalogue.
		// Contrat :
		//	Aucun

//------------------------------------------------Constructeur-Destructeur

	 	Catalogue();
		// Mode d'emploi :
		//	Construit un catalogue de trajets.
		// Contrat :
		//	Aucun

		~Catalogue();
		// Mode d'emploi :
		//	Libération de la mémoire allouée.
		// Contrat :
		//	Aucun

//////////////////////////////////////////////////////////////// PRIVATE
	private:
		Tableau *listeItineraires;
		Graphe GrapheTrajets;
		int nbItineraires;
};
#endif
