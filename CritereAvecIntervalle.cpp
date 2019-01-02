/*************************************************************************
                           CRITEREAVECINTERVALLE -  description
                             -------------------
    début                : 20/11/18
    copyright            : (C) Romain Perrone, Chanèle Jourdan - GROUPE 2_1
*************************************************************************/

//---------- Réalisation de la classe <CRITEREAVECINTERVALLE> (fichier CritereAvecIntervalle.cpp) -------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "CritereAvecIntervalle.h"

//------------------------------------------------------------- Constantes
//----------------------------------------------------- Méthodes publiques

 bool CritereAvecIntervalle::ValidationCritere(Trajet *unTrajet){

    bool valide=false;
        cout<<"index : "<<indexTrajet<<endl;
    if (indexTrajet>=borneInf && indexTrajet<=borneSup)
    {
        valide=true;

    }
    indexTrajet++;

    return valide;
 }

//------------------------------------------------- Surcharge d'opérateurs
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
//----------------------------------------------------- Méthodes protégées
