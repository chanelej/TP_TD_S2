/*************************************************************************
                           Option
                             -------------------
    début                : 25/01/2019
    copyright            : B3228 - Chanèle Jourdan - Quentin Ferro
*************************************************************************/

//---------- Réalisation de la classe <Option> (fichier Option.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Option.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Option::Option ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Option>" << endl;
#endif
} //----- Fin de Option


Option::~Option ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Option>" << endl;
#endif
} //----- Fin de ~Option


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

