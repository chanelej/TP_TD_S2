
/*************************************************************************
                           CRITEREDETYPE  -  description
                             -------------------
    début                : 20/11/18
    copyright            : (C) Quentin Ferro, Chanèle Jourdan - GROUPE 2_28
*************************************************************************/

//---------- Interface du module <CRITEREDETYPE> (fichier CritereDeType.h) -------------------
#if ! defined ( CRITEREDETYPE_H )
#define CRITEREDETYPE_H

//------------------------------------------------------------------------
// Rôle du module <CRITEREDETYPE>
// Représente un critère de sélection qui permet de valider les trajets
// selon leur type (tous les simples ou tous les composés selon la demande
// de l'utilisateur)
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
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
		//	Renvoie true si unTrajet est du type correspondant à typeTrajet,
		//  et false sinon
		// Contrat :
		//	Aucune

//----------------------------------------------- Surchages d'opérateurs

//---------------------------------------------------- Destructeur
        CritereDeType(int type);
		// Mode d'emploi :
		//	Constructeur de CritereDeType, dont le paramètre est un entier qui correspond,
		//  à la demande de l'utilisateur, à un trajet simple ou composé
		// Contrat :
		// type vaut soit 21 (=trajet simple), soit 22 (=trajet composé)

        virtual ~CritereDeType();
		// Mode d'emploi :
		//	Libération de la mémoire allouée
		// Contrat :
		//	Aucun

//////////////////////////////////////////////////////////////////  PROTECTED
	protected:
		int typeTrajet;

};
#endif
