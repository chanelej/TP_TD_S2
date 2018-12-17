/*************************************************************************
                           TRAJET_SIMPLE  -  description
                             -------------------
    début                : 20/11/18
    copyright            : (C) Romain Perrone, Chanèle Jourdan - GROUPE 2_1
*************************************************************************/

//---------- Interface du module <TRAJET_SIMPLE> (fichier TrajetSimple.h) -------------------
#if ! defined ( TRAJET_SIMPLE_H )
#define TRAJET_SIMPLE_H
#include "Trajet.h"
#include <cstring>

//------------------------------------------------------------------------
// Rôle du module <TRAJET_SIMPLE>
// Représente un Trajet direct allant d'une ville de départ
// à une ville d'arrivée en utilisant un moyen de transport.

//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées


//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

class TrajetSimple : public Trajet
{
//////////////////////////////////////////////////////////////////  PUBLIC
	public:
//---------------------------------------------------- Fonctions publiques
		virtual void Afficher() const;
		// Mode d'emploi :
		//	Affiche les villes de départ et d'arrivée ainsi que le moyen de transport utilisé.
		// Contrat :
		//	Aucun
		
		std::string Script();
		// Mode d'emploi :
		//Retourne la chaine de caractère correspondant à ce que l'on va stocker dans le fichier de sauvegarde
		// Contrat :
		//	Aucun		
		
		Trajet * copy();
		// Mode d'emploi :
		//	Construit une copie de TrajetSimple et retourne son pointeur.
		// Contrat :
		//	Aucun
//----------------------------------------------- Surchages d'opérateurs

//------------------------------------------------Constructeur-Destructeur
		TrajetSimple(const char* villeDep, const char* villeArr , const char* transport);
		// Mode d'emploi :
		//	Construit un trajet simple (=direct) entre une ville de départ et une ville d'arrivée
		// 	en utilisant un moyen de transport donné.
		// Contrat :
		//	Aucun

		virtual ~TrajetSimple();
		// Mode d'emploi :
		//	Libération de la mémoire allouée
		// Contrat :
		//	Aucun

//////////////////////////////////////////////////////////////// PROTECTED
	protected:
		 char* transport;
};
#endif
