/*************************************************************************
                           TRAJET_SIMPLE  -  description
                             -------------------
    début                : 20/11/18
    copyright            : (C) Romain Perrone, Chanèle Jourdan - GROUPE 2_1
*************************************************************************/

//---------- Réalisation de la classe <TRAJET_SIMPLE> (fichier TrajetSimple.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes
//------------------------------------------------------------- Méthodes publiques

void TrajetSimple::Afficher() const
{
	cout << "Trajet de " << Trajet::vDep << " à " << Trajet::vArr << " en " << transport << endl;
}

string TrajetSimple::Script(){
	string vD=vDep;
	string vA=vArr;
	string tr=transport;
	string chaine = "TS:"+vD+","+vA+","+tr+"\n";
	return chaine;
}

Trajet * TrajetSimple::copy()
{
	Trajet *t;
	TrajetSimple * t_simple = new TrajetSimple(Trajet::vDep, Trajet::vArr, transport);
	t = t_simple;

	return t;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple(const char* vDep, const char* vArr , const char* t) : Trajet()
{
// Algorithme :
// Allocation de la mémoire et copie en profondeur, dans les attributs, des chaines qui sont en paramètres de la méthode 

	#if defined (MAP)
		cout << "Appel au constructeur TrajetSimple" << endl;
	#endif

	char * villeDep =  new char[strlen(vDep)+1];
	char * villeArr =  new char[strlen(vArr)+1];

   	transport = new char[strlen(t)+1];

	strcpy(villeDep, vDep);
  	strcpy(villeArr, vArr);
    strcpy(transport, t);

	Trajet::vDep = villeDep;
	Trajet::vArr = villeArr;
}

TrajetSimple::~TrajetSimple() {
	
	#if defined (MAP)
		cout << "Appel au destructeur TrajetSimple" << endl;
	#endif

	delete[] transport;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
