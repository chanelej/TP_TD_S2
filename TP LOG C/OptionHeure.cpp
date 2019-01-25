/*************************************************************************
                           OptionHeure
                             -------------------
    d�but                : 25/01/2019
    copyright            : B3228 - Chan�le Jourdan - Quentin Ferro
*************************************************************************/

//---------- R�alisation de la classe <OptionHeure> (fichier OptionHeure.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "OptionHeure.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

/*bool OptionHeure :: Valider ( const LigneLog & uneLigne ){
  bool validation=false;
  if (LigneLog.getHeure().h==heure){
    validation=true;
  }
  return validation;
}*/

//------------------------------------------------- Surcharge d'op�rateurs

//-------------------------------------------- Constructeurs - destructeur

OptionHeure::OptionHeure (int uneHeure)
{
    heure=uneHeure;
#ifdef MAP
    cout << "Appel au constructeur de <OptionHeure>" << endl;
#endif
} //----- Fin de OptionHeure


OptionHeure::~OptionHeure ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <OptionHeure>" << endl;
#endif
} //----- Fin de ~OptionHeure


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es


