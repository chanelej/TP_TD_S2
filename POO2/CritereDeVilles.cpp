/*************************************************************************
                           CRITEREDEVILLES -  description
                             -------------------
    début                : 20/11/18
    copyright            : (C) Romain Perrone, Chanèle Jourdan - GROUPE 2_1
*************************************************************************/

//---------- Réalisation de la classe <CRITEREDEVILLES> (fichier CritereDeVilles.cpp) -------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "CritereDeVilles.h"

//------------------------------------------------------------- Constantes
//----------------------------------------------------- Méthodes publiques

 bool CritereDeVilles::ValidationCritere(Trajet *unTrajet){

    bool valideVilleA=false;
    bool valideVilleD=false;

    if(villeA=="0"  || (string)((*unTrajet).getVilleArr())==villeA )
    {
        valideVilleA=true;
    }
        if(villeD=="0"  || (string)((*unTrajet).getVilleDep())==villeD )
    {
        valideVilleD=true;
    }

 return (valideVilleA&&valideVilleD);

 }

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

CritereDeVilles::CritereDeVilles(string vD, string vA) : Critere()
{
	#if defined (MAP)
		cout << "Appel au constructeur de CritereDeVilles" << endl;
	#endif

	villeA=vA;
	villeD=vD;
}


CritereDeVilles::~CritereDeVilles()
{
	#if defined (MAP)
		cout << "Appel au destructeur de CritereDeType" << endl;
	#endif
}

//------------------------------------------------------------------ PRIVE
//----------------------------------------------------- Méthodes protégées
