
/*************************************************************************
                           CRITEREDETYPE  -  description
                             -------------------
    dÈbut                : 20/11/18
    copyright            : (C) Romain Perrone, Chanèle Jourdan - GROUPE 2_1
				+ Quentin Ferro - Groupe 2_28
*************************************************************************/

//---------- Interface du module <CRITEREDETYPE> (fichier CritereDeType.h) -------------------
#if ! defined ( CRITEREDETYPE_H )
#define CRITEREDETYPE_H

//------------------------------------------------------------------------
// RÙle du module <CRITEREDETYPE>
// ReprÈsente un critËre de sÈlection qui permet de valider les trajets
// selon leur type (tous les simples ou tous les composÈs selon la demande
// de l'utilisateur)
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisÈes
#include "Trajet.h"
#include "Critere.h"
//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types

class CritereDeType : public Critere
{
//////////////////////////////////////////////////////////////////  PUBLIC
	public:

//---------------------------------------------------- Fonctions publiques
        bool ValidationCritere(Trajet *unTrajet);
		// Mode d'emploi :
		//	Renvoie true si unTrajet est du type correspondant ‡ typeTrajet,
		//  et false sinon
		// Contrat :
		//	Aucune

//----------------------------------------------- Surchages d'opÈrateurs

//---------------------------------------------------- Destructeur
        CritereDeType(int type);
		// Mode d'emploi :
		//	Constructeur de CritereDeType, dont le paramËtre est un entier qui correspond,
		//  ‡ la demande de l'utilisateur, ‡ un trajet simple ou composÈ
		// Contrat :
		// type vaut soit 21 (=trajet simple), soit 22 (=trajet composÈ)

        virtual ~CritereDeType();
		// Mode d'emploi :
		//	LibÈration de la mÈmoire allouÈe
		// Contrat :
		//	Aucun

//////////////////////////////////////////////////////////////////  PROTECTED
	protected:
		int typeTrajet;

};
#endif
