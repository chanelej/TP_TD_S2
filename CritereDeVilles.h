
/*************************************************************************
                           CRITEREDEVILLES  -  description
                             -------------------
    début                : 20/11/18
    copyright            : (C) Romain Perrone, Chanèle Jourdan - GROUPE 2_1
*************************************************************************/

//---------- Interface du module <CRITEREDEVILLES> (fichier CritereDeVilles.h) -------------------
#if ! defined ( CRITEREDEVILLES_H )
#define CRITEREDEVILLES_H

//------------------------------------------------------------------------
// Rôle du module <CRITEREDEVILLES>
// Représente un critère de sélection qui permet de valider les trajets
// selon leur ville de départ et/ou leur ville d'arrivée
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "Critere.h"
//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types

class CritereDeVilles : public Critere
{
//////////////////////////////////////////////////////////////////  PUBLIC
	public:

//---------------------------------------------------- Fonctions publiques
        bool ValidationCritere(Trajet *unTrajet);
		// Mode d'emploi :
		//	Renvoie true si unTrajet a ses villes de départ et d'arrivée qui
		// correspondent à villeD et villeA
		// Contrat :
		//	Aucune

//----------------------------------------------- Surchages d'opérateurs

//---------------------------------------------------- Destructeur
        CritereDeVilles(string vD, string vA);
		// Mode d'emploi :
		//	Constructeur de CritereDeType, dont les paramètres sont les villes
		//  de départ et d'arrivée choisies par l'utilisateur pour sélectionner les trajets
        // Contrat :
		//  La ville est "0" si l'utilisateur n'a pas souhaité la spécifier
		//  Les deux villes ne peuvent pas être "0" simultanément


        virtual ~CritereDeVilles();
		// Mode d'emploi :
		//	Libération de la mémoire allouée
		// Contrat :
		//	Aucun

//////////////////////////////////////////////////////////////////  PROTECTED
	protected:
		string villeD;
		string villeA;

};
#endif
