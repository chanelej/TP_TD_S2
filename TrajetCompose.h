/*************************************************************************
                           TRAJET_COMPOSE -  description
                             -------------------
    début                : 20/11/18
    copyright            : (C) Romain Perrone, Chanèle Jourdan - GROUPE 2_1
*************************************************************************/

//---------- Interface du module <TRAJET_COMPOSE> (fichier TrajetComposé.h) -------------------
#if ! defined (TRAJET_COMPOSE_H )
#define TRAJET_COMPOSE_H

#include <cstring>
#include "Trajet.h"
#include "Tableau.h"


//------------------------------------------------------------------------
// Rôle du module <TRAJET_COMPOSE>
// Représente une sorte de Trajet, constitué de plusieurs trajets simples consécutifs (minimum deux)
//Il va bien d'une ville de départ à une ville d'arrivée mais en passant par plusieurs villes étapes.

//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées


//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

class TrajetCompose : public Trajet
{
//////////////////////////////////////////////////////////////////  PUBLIC
	public:
//---------------------------------------------------- Fonctions publiques
		void Ajouter(Trajet *t);
		// Mode d'emploi :
		//	Ajouter une étape au trajet composé.
		// Contrat :
		//	Aucun

		virtual void Afficher() const;
		// Mode d'emploi :
		//	Affiche l'ensemble des trajets simples qui composent le trajet composé.
		// Contrat :
		//	Aucun
		
		std::string Script();
		// Mode d'emploi :
		//Retourne la chaine de caractère correspondant à ce que l'on va stocker dans le fichier de sauvegarde
		// Contrat :
		//	Aucun	

		Trajet * copy();
		// Mode d'emploi :
		//	Construit une copie de TrajetCompose et retourne son pointeur.
		// Contrat :
		//	Aucun

//----------------------------------------------- Surchages d'opérateurs

//------------------------------------------------Constructeur-Destructeur
		TrajetCompose();
		// Mode d'emploi :
		//	Construit un trajet composé constitué d'une liste de trajets simples.
		// Contrat :
		//	Aucun

		TrajetCompose(TrajetCompose const& unTrajetCompose);
		// Mode d'emploi :
		//	Constructeur de copie de TrajetCompose
		// Contrat :
		//	Aucun

		virtual ~TrajetCompose();
		// Mode d'emploi :
		//	Libération de la mémoire allouée
		// Contrat :
		//	Aucun

//////////////////////////////////////////////////////////////// PROTECTED
	protected:
		Tableau *listeTrajets;
		int nbTrajetsSimple;
};
#endif
