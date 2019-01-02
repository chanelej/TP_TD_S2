/*************************************************************************
                           CRITEREDEVILLES -  description
                             -------------------
    d�but                : 20/11/18
    copyright            : (C) Romain Perrone, Chan�le Jourdan - GROUPE 2_1
*************************************************************************/

//---------- R�alisation de la classe <CRITEREDEVILLES> (fichier CritereDeVilles.cpp) -------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include syst�me
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "CritereDeVilles.h"

//------------------------------------------------------------- Constantes
//----------------------------------------------------- M�thodes publiques

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

//------------------------------------------------- Surcharge d'op�rateurs
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
//----------------------------------------------------- M�thodes prot�g�es
