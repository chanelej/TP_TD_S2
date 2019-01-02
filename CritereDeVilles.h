
/*************************************************************************
                           CRITEREDEVILLES  -  description
                             -------------------
    d�but                : 20/11/18
    copyright            : (C) Romain Perrone, Chan�le Jourdan - GROUPE 2_1
*************************************************************************/

//---------- Interface du module <CRITEREDEVILLES> (fichier CritereDeVilles.h) -------------------
#if ! defined ( CRITEREDEVILLES_H )
#define CRITEREDEVILLES_H

//------------------------------------------------------------------------
// R�le du module <CRITEREDEVILLES>
// Repr�sente un crit�re de s�lection qui permet de valider les trajets
// selon leur ville de d�part et/ou leur ville d'arriv�e
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilis�es
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
		//	Renvoie true si unTrajet a ses villes de d�part et d'arriv�e qui
		// correspondent � villeD et villeA
		// Contrat :
		//	Aucune

//----------------------------------------------- Surchages d'op�rateurs

//---------------------------------------------------- Destructeur
        CritereDeVilles(string vD, string vA);
		// Mode d'emploi :
		//	Constructeur de CritereDeType, dont les param�tres sont les villes
		//  de d�part et d'arriv�e choisies par l'utilisateur pour s�lectionner les trajets
        // Contrat :
		//  La ville est "0" si l'utilisateur n'a pas souhait� la sp�cifier
		//  Les deux villes ne peuvent pas �tre "0" simultan�ment


        virtual ~CritereDeVilles();
		// Mode d'emploi :
		//	Lib�ration de la m�moire allou�e
		// Contrat :
		//	Aucun

//////////////////////////////////////////////////////////////////  PROTECTED
	protected:
		string villeD;
		string villeA;

};
#endif
