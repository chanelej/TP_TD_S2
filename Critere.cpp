/*************************************************************************
                           CRITERE  -  description
                             -------------------
    début                : 20/11/18
    copyright            : (C) Romain Perrone, Chanèle Jourdan - GROUPE 2_1
*************************************************************************/

//---------- Réalisation de la classe <CRITERE> (fichier Critere.cpp) -------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Critere.h"

//------------------------------------------------------------- Constantes
//----------------------------------------------------- Méthodes publiques

bool Critere :: ValidationCritere(Trajet *unTrajet)
{
    return true;
}
//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur


Critere::Critere()
{
	#if defined (MAP)
		cout << "Appel au constructeur protected de Critere" << endl;
	#endif
}


Critere::~Critere()
{
	#if defined (MAP)
		cout << "Appel au destructeur de Critere" << endl;
	#endif
}

//------------------------------------------------------------------ PRIVE
//----------------------------------------------------- Méthodes protégées
