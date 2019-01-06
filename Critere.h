
/*************************************************************************
                           CRITERE  -  description
                             -------------------
    d�but                : 20/11/18
    copyright            : (C) Romain Perrone, Chan�le Jourdan - GROUPE 2_1
				+ Quentin Ferro - Groupe 2_28
*************************************************************************/

//---------- Interface du module <CRITERE> (fichier Critere.h) -------------------
#if ! defined ( CRITERE_H )
#define CRITERE_H

//------------------------------------------------------------------------
// R�le du module <CRITERE>
// Classe abstraite repr�sentant un crit�re de selection.
// Permet de manipuler les diff�rents crit�res (qui sont les classes filles de
// celle-ci) sans distinction de type.
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilis�es
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
		//	Renvoie true si unTrajet respecte le crit�re, et false sinon
		// Contrat :
		//	Aucun

//----------------------------------------------- Surchages d'op�rateurs

//---------------------------------------------------- Destructeur
        Critere();
		// Mode d'emploi :
		//	Constructeur de Critere
		// Contrat :
		//	Aucun

		virtual ~Critere();
		// Mode d'emploi :
		//	Lib�ration de la m�moire allou�e
		// Contrat :
		//	Aucun

//////////////////////////////////////////////////////////////////  PROTECTED
	protected:

};
#endif
