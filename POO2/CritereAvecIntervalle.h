
/*************************************************************************
                           CRITEREAVECINTERVALLE  -  description
                             -------------------
    début                : 20/11/18
    copyright            : (C) Romain Perrone, Chanèle Jourdan - GROUPE 2_1
*************************************************************************/

//---------- Interface du module <CRITEREAVECINTERVALLE> (fichier CritereAvecIntervalle.h) -------------------
#if ! defined ( CRITEREAVECINTERVALLE_H )
#define CRITEREAVECINTERVALLE_H

//------------------------------------------------------------------------
// Rôle du module <CRITEREAVECINTERVALLE>
// Représente un critère de sélection qui permet de valider les trajets
// selon leur indice de classement dans le catalogue, par rapport à un
// intervalle défini par l'utilisateur
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "Critere.h"
//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types

class CritereAvecIntervalle : public Critere
{
//////////////////////////////////////////////////////////////////  PUBLIC
	public:

//---------------------------------------------------- Fonctions publiques
        bool ValidationCritere(Trajet *unTrajet);
		// Mode d'emploi :
		//	Renvoie true si la position de unTrajet dans le fichier est dans l'intervalle
		// Contrat :
		//	Aucun

//----------------------------------------------- Surchages d'opérateurs

//---------------------------------------------------- Destructeur
        CritereAvecIntervalle(int borneI, int borneS);
		// Mode d'emploi :
		//	Constructeur de CritereDeType, dont le paramètre sont les deux bornes de
		// l'intervalle défini par l'utilisateur
		// Contrat :
		// Les bornes ne peuvent pas être négatives ou nulles, et borneI doit être inférieure
		// ou égale à borneS (ces cas paticuliers ont déjà été traités dans Catalogue)

        virtual ~CritereAvecIntervalle();
		// Mode d'emploi :
		//	Libération de la mémoire allouée
		// Contrat :
		//	Aucun

//////////////////////////////////////////////////////////////////  PROTECTED
	protected:
		int borneSup;
		int borneInf;
		int indexTrajet;

};
#endif
