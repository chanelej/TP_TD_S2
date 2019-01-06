/*************************************************************************
                           CRITERE  -  description
                             -------------------
    dÈbut                : 20/11/18
    copyright            : (C) Romain Perrone, Chanèle Jourdan - GROUPE 2_1
				+ Quentin Ferro - Groupe 2_28
*************************************************************************/

//---------- RÈalisation de la classe <CRITERE> (fichier Critere.cpp) -------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include systËme
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Critere.h"

//------------------------------------------------------------- Constantes
//----------------------------------------------------- MÈthodes publiques

bool Critere :: ValidationCritere(Trajet *unTrajet)
{
    return true;
}
//------------------------------------------------- Surcharge d'opÈrateurs
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
//----------------------------------------------------- MÈthodes protÈgÈes
