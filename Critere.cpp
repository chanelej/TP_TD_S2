/*************************************************************************
                           CRITERE  -  description
                             -------------------
    d�but                : 20/11/18
    copyright            : (C) Romain Perrone, Chan�le Jourdan - GROUPE 2_1
*************************************************************************/

//---------- R�alisation de la classe <CRITERE> (fichier Critere.cpp) -------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include syst�me
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Critere.h"

//------------------------------------------------------------- Constantes
//----------------------------------------------------- M�thodes publiques

bool Critere :: ValidationCritere(Trajet *unTrajet)
{
    return true;
}
//------------------------------------------------- Surcharge d'op�rateurs
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
//----------------------------------------------------- M�thodes prot�g�es
