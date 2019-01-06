
/*************************************************************************
                           CRITERE  -  description
                             -------------------
    début                : 20/11/18
    copyright            : (C) Quentin Ferro, Chanèle Jourdan - GROUPE 2_28
*************************************************************************/

//---------- Interface du module <CRITERE> (fichier Critere.h) -------------------
#if ! defined ( CRITERE_H )
#define CRITERE_H

//------------------------------------------------------------------------
// Rôle du module <CRITERE>
// Classe abstraite représentant un critère de selection.
// Permet de manipuler les différents critères (qui sont les classes filles de
// celle-ci) sans distinction de type.
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types

class Critere
{
//////////////////////////////////////////////////////////////////  PUBLIC
	public:

//---------------------------------------------------- Fonctions publiques
         virtual bool ValidationCritere(Trajet *unTrajet);
		// Mode d'emploi :
		//	Renvoie true si unTrajet respecte le critère, et false sinon
		// Contrat :
		//	Aucun

//----------------------------------------------- Surchages d'opérateurs

//---------------------------------------------------- Destructeur
        Critere();
		// Mode d'emploi :
		//	Constructeur de Critere
		// Contrat :
		//	Aucun

		virtual ~Critere();
		// Mode d'emploi :
		//	Libération de la mémoire allouée
		// Contrat :
		//	Aucun

//////////////////////////////////////////////////////////////////  PROTECTED
	protected:

};
#endif
