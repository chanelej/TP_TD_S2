/*************************************************************************
                           CRITEREDETYPE -  description
                             -------------------
    début                : 20/11/18
    copyright            : (C) Quentin Ferro, Chanèle Jourdan - GROUPE 2_28
*************************************************************************/

//---------- Réalisation de la classe <CRITEREDETYPE> (fichier CritereDeType.cpp) -------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "CritereDeType.h"

//------------------------------------------------------------- Constantes
//----------------------------------------------------- Méthodes publiques

 bool CritereDeType::ValidationCritere(Trajet *unTrajet){

    bool valide=false;
    string script = (*unTrajet).Script();
    if(typeTrajet==21 && script[1]=='S'){
        return true;
    } else if (typeTrajet==22 && script[1]=='C'){
        return true;
    }
 return valide;

 }

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

CritereDeType::CritereDeType(int type) : Critere()
{
	#if defined (MAP)
		cout << "Appel au constructeur de CritereDeType" << endl;
	#endif

	typeTrajet=type;
}


CritereDeType::~CritereDeType()
{
	#if defined (MAP)
		cout << "Appel au destructeur de CritereDeType" << endl;
	#endif
}

//------------------------------------------------------------------ PRIVE
//----------------------------------------------------- Méthodes protégées
