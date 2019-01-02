/*************************************************************************
                           TRAJET  -  description
                             -------------------
    début                : 20/11/18
    copyright            : (C) Romain Perrone, Chanèle Jourdan - GROUPE 2_1
*************************************************************************/

//---------- Réalisation de la classe <TRAJET> (fichier Trajet.cpp) -------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes
//----------------------------------------------------- Méthodes publiques
void Trajet::Afficher() const {}
string Trajet::Script() {}
const char * Trajet::getVilleDep() { return vDep;  }
const char * Trajet::getVilleArr() { return vArr;  }

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

Trajet::Trajet()
{
	#if defined (MAP)
		cout << "Appel au constructeur protected de Trajet" << endl;
	#endif
}


Trajet::~Trajet() 
{
	#if defined (MAP)
		cout << "Appel au destructeur de Trajet" << endl;
	#endif
	
	delete[] vArr;
	delete[] vDep;
}

//------------------------------------------------------------------ PRIVE
//----------------------------------------------------- Méthodes protégées




