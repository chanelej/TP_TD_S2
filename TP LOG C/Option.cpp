/*************************************************************************
                           Option
                             -------------------
    d�but                : 25/01/2019
    copyright            : B3228 - Chan�le Jourdan - Quentin Ferro
*************************************************************************/

//---------- R�alisation de la classe <Option> (fichier Option.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Option.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

//------------------------------------------------- Surcharge d'op�rateurs

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

//----------------------------------------------------- M�thodes prot�g�es

