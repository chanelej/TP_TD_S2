/*************************************************************************
                           CATALOGUE  -  description
                             -------------------
    début                : 20/11/18
    copyright            : (C) Romain Perrone, Chanèle Jourdan - GROUPE 2_1
*************************************************************************/

//---------- Interface du module <CATALOGUE> (fichier Catalogue.h) -------------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Graphe.h"
#include "Tableau.h"

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
		
		std::string ConstruireScript(int i) const;
		// Mode d'emploi :
		// 		Construit le script correspondant à la sauvegarde dans le fichier, en prenant
		// en compte le critère de sélection choisi par l'utilisateur
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
