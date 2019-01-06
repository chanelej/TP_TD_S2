
/*************************************************************************
                           CRITERE  -  description
                             -------------------
    dÈbut                : 20/11/18
    copyright            : (C) Romain Perrone, Chanèle Jourdan - GROUPE 2_1
				+ Quentin Ferro - Groupe 2_28
*************************************************************************/

//---------- Interface du module <CRITERE> (fichier Critere.h) -------------------
#if ! defined ( CRITERE_H )
#define CRITERE_H

//------------------------------------------------------------------------
// RÙle du module <CRITERE>
// Classe abstraite reprÈsentant un critËre de selection.
// Permet de manipuler les diffÈrents critËres (qui sont les classes filles de
// celle-ci) sans distinction de type.
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisÈes
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
		//	Renvoie true si unTrajet respecte le critËre, et false sinon
		// Contrat :
		//	Aucun

//----------------------------------------------- Surchages d'opÈrateurs

//---------------------------------------------------- Destructeur
        Critere();
		// Mode d'emploi :
		//	Constructeur de Critere
		// Contrat :
		//	Aucun

		virtual ~Critere();
		// Mode d'emploi :
		//	LibÈration de la mÈmoire allouÈe
		// Contrat :
		//	Aucun

//////////////////////////////////////////////////////////////////  PROTECTED
	protected:

};
#endif
