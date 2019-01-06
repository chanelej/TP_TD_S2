
/*************************************************************************
                           CRITEREAVECINTERVALLE  -  description
                             -------------------
    dÈbut                : 20/11/18
    copyright            : (C) Romain Perrone, Chanèle Jourdan - GROUPE 2_1
				+ Quentin Ferro - Groupe 2_28
*************************************************************************/

//---------- Interface du module <CRITEREAVECINTERVALLE> (fichier CritereAvecIntervalle.h) -------------------
#if ! defined ( CRITEREAVECINTERVALLE_H )
#define CRITEREAVECINTERVALLE_H

//------------------------------------------------------------------------
// RÙle du module <CRITEREAVECINTERVALLE>
// ReprÈsente un critËre de sÈlection qui permet de valider les trajets
// selon leur indice de classement dans le catalogue, par rapport ‡ un
// intervalle dÈfini par l'utilisateur
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisÈes
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

//----------------------------------------------- Surchages d'opÈrateurs

//---------------------------------------------------- Destructeur
        CritereAvecIntervalle(int borneI, int borneS);
		// Mode d'emploi :
		//	Constructeur de CritereDeType, dont le paramËtre sont les deux bornes de
		// l'intervalle dÈfini par l'utilisateur
		// Contrat :
		// Les bornes ne peuvent pas Ítre nÈgatives ou nulles, et borneI doit Ítre infÈrieure
		// ou Ègale ‡ borneS (ces cas paticuliers ont dÈj‡ ÈtÈ traitÈs dans Catalogue)

        virtual ~CritereAvecIntervalle();
		// Mode d'emploi :
		//	LibÈration de la mÈmoire allouÈe
		// Contrat :
		//	Aucun

//////////////////////////////////////////////////////////////////  PROTECTED
	protected:
		int borneSup;
		int borneInf;
		int indexTrajet;

};
#endif
