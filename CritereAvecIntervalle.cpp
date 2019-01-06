/*************************************************************************
                           CRITEREAVECINTERVALLE -  description
                             -------------------
    d�but                : 20/11/18
    copyright            : (C) Quentin Ferro, Chan�le Jourdan - GROUPE 2_28
*************************************************************************/

//---------- R�alisation de la classe <CRITEREAVECINTERVALLE> (fichier CritereAvecIntervalle.cpp) -------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include syst�me
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "CritereAvecIntervalle.h"

//------------------------------------------------------------- Constantes
//----------------------------------------------------- M�thodes publiques

 bool CritereAvecIntervalle::ValidationCritere(Trajet *unTrajet){

    bool valide=false;

    if (indexTrajet>=borneInf && indexTrajet<=borneSup)
    {
        valide=true;
    }
    indexTrajet++;

    return valide;
 }

//------------------------------------------------- Surcharge d'op�rateurs
//-------------------------------------------- Constructeurs - destructeur

CritereAvecIntervalle::CritereAvecIntervalle(int borneI, int borneS) : Critere()
{
	#if defined (MAP)
		cout << "Appel au constructeur de CritereAvecIntervalle" << endl;
	#endif

	borneInf=borneI;
	borneSup=borneS;
	indexTrajet=1;
}


CritereAvecIntervalle::~CritereAvecIntervalle()
{
	#if defined (MAP)
		cout << "Appel au destructeur de CritereAvecIntervalle" << endl;
	#endif
}

//------------------------------------------------------------------ PRIVE
//----------------------------------------------------- M�thodes prot�g�es
