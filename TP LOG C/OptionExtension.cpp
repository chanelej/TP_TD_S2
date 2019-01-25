/*************************************************************************
                           OptionExtension
                             -------------------
    d�but                : 25/01/2019
    copyright            : B3228 - Chan�le Jourdan - Quentin Ferro
*************************************************************************/

//---------- R�alisation de la classe <OptionExtension> (fichier OptionExtension.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "OptionExtension.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

/*bool OptionExtension :: Valider ( const LigneLog & uneLigne ){
  bool validation=true;
  for (int i=0;i<getExtension.size();i++)
  {
    if (!(compare(LigneLog.getExtension(),extensionInterdite.at(i)) //Si les extensions correspondent
    {
        validation=false;
    }
  }
  return validation;
}*/

void OptionExtension::AjouterExtension(string ext){
    extensionInterdite.push_back(ext);
}

//------------------------------------------------- Surcharge d'op�rateurs

//-------------------------------------------- Constructeurs - destructeur

OptionExtension::OptionExtension (vector<string> &listeExtension)
{
extensionInterdite=listeExtension;
#ifdef MAP
    cout << "Appel au constructeur de <OptionExtension>" << endl;
#endif
} //----- Fin de OptionExtension


OptionExtension::~OptionExtension ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <OptionExtension>" << endl;
#endif
} //----- Fin de ~OptionExtension


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es


