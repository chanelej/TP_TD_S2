
/*************************************************************************
                           CRITEREDETYPE  -  description
                             -------------------
    d�but                : 20/11/18
    copyright            : (C) Quentin Ferro, Chan�le Jourdan - GROUPE 2_28
*************************************************************************/

//---------- Interface du module <CRITEREDETYPE> (fichier CritereDeType.h) -------------------
#if ! defined ( CRITEREDETYPE_H )
#define CRITEREDETYPE_H

//------------------------------------------------------------------------
// R�le du module <CRITEREDETYPE>
// Repr�sente un crit�re de s�lection qui permet de valider les trajets
// selon leur type (tous les simples ou tous les compos�s selon la demande
// de l'utilisateur)
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilis�es
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
		//	Renvoie true si unTrajet est du type correspondant � typeTrajet,
		//  et false sinon
		// Contrat :
		//	Aucune

//----------------------------------------------- Surchages d'op�rateurs

//---------------------------------------------------- Destructeur
        CritereDeType(int type);
		// Mode d'emploi :
		//	Constructeur de CritereDeType, dont le param�tre est un entier qui correspond,
		//  � la demande de l'utilisateur, � un trajet simple ou compos�
		// Contrat :
		// type vaut soit 21 (=trajet simple), soit 22 (=trajet compos�)

        virtual ~CritereDeType();
		// Mode d'emploi :
		//	Lib�ration de la m�moire allou�e
		// Contrat :
		//	Aucun

//////////////////////////////////////////////////////////////////  PROTECTED
	protected:
		int typeTrajet;

};
#endif
