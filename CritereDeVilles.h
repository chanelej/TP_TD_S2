
/*************************************************************************
                           CRITEREDEVILLES  -  description
                             -------------------
    dÈbut                : 20/11/18
    copyright            : (C) Romain Perrone, Chanèle Jourdan - GROUPE 2_1
				+ Quentin Ferro - Groupe 2_28
*************************************************************************/

//---------- Interface du module <CRITEREDEVILLES> (fichier CritereDeVilles.h) -------------------
#if ! defined ( CRITEREDEVILLES_H )
#define CRITEREDEVILLES_H

//------------------------------------------------------------------------
// RÙle du module <CRITEREDEVILLES>
// ReprÈsente un critËre de sÈlection qui permet de valider les trajets
// selon leur ville de dÈpart et/ou leur ville d'arrivÈe
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisÈes
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
		//	Renvoie true si unTrajet a ses villes de dÈpart et d'arrivÈe qui
		// correspondent ‡ villeD et villeA
		// Contrat :
		//	Aucune

//----------------------------------------------- Surchages d'opÈrateurs

//---------------------------------------------------- Destructeur
        CritereDeVilles(string vD, string vA);
		// Mode d'emploi :
		//	Constructeur de CritereDeType, dont les paramËtres sont les villes
		//  de dÈpart et d'arrivÈe choisies par l'utilisateur pour sÈlectionner les trajets
        // Contrat :
		//  La ville est "0" si l'utilisateur n'a pas souhaitÈ la spÈcifier
		//  Les deux villes ne peuvent pas Ítre "0" simultanÈment


        virtual ~CritereDeVilles();
		// Mode d'emploi :
		//	LibÈration de la mÈmoire allouÈe
		// Contrat :
		//	Aucun

//////////////////////////////////////////////////////////////////  PROTECTED
	protected:
		string villeD;
		string villeA;

};
#endif
