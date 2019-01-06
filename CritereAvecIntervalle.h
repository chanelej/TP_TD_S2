
/*************************************************************************
                           CRITEREAVECINTERVALLE  -  description
                             -------------------
    d�but                : 20/11/18
    copyright            : (C) Romain Perrone, Chan�le Jourdan - GROUPE 2_1
				+ Quentin Ferro - Groupe 2_28
*************************************************************************/

//---------- Interface du module <CRITEREAVECINTERVALLE> (fichier CritereAvecIntervalle.h) -------------------
#if ! defined ( CRITEREAVECINTERVALLE_H )
#define CRITEREAVECINTERVALLE_H

//------------------------------------------------------------------------
// R�le du module <CRITEREAVECINTERVALLE>
// Repr�sente un crit�re de s�lection qui permet de valider les trajets
// selon leur indice de classement dans le catalogue, par rapport � un
// intervalle d�fini par l'utilisateur
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilis�es
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

//----------------------------------------------- Surchages d'op�rateurs

//---------------------------------------------------- Destructeur
        CritereAvecIntervalle(int borneI, int borneS);
		// Mode d'emploi :
		//	Constructeur de CritereDeType, dont le param�tre sont les deux bornes de
		// l'intervalle d�fini par l'utilisateur
		// Contrat :
		// Les bornes ne peuvent pas �tre n�gatives ou nulles, et borneI doit �tre inf�rieure
		// ou �gale � borneS (ces cas paticuliers ont d�j� �t� trait�s dans Catalogue)

        virtual ~CritereAvecIntervalle();
		// Mode d'emploi :
		//	Lib�ration de la m�moire allou�e
		// Contrat :
		//	Aucun

//////////////////////////////////////////////////////////////////  PROTECTED
	protected:
		int borneSup;
		int borneInf;
		int indexTrajet;

};
#endif
