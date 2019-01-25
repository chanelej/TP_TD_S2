/*************************************************************************
                           OptionExtension
                             -------------------
    d�but                : 25/01/2019
    copyright            : B3228 - Chan�le Jourdan - Quentin Ferro
*************************************************************************/

//---------- Interface de la classe <OptionExtension> (fichier OptionExtension.h) ----------------
//#if ! defined ( OPTIONEXTENSION_H )
#define OPTIONEXTENSION_H

//--------------------------------------------------- Interfaces utilis�es
#include<vector>
#include "Option.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <OptionExtension>
// Classe fille de Option qui permet de mat�rialiser l'option -e rentr�e dans la
// ligne de commande. Cette classe va donc valider une ligne du fichier de logs
// si son extension ne fait pas partie de la liste extensionInterdite

//------------------------------------------------------------------------

class OptionExtension : public Option
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
  //   bool Valider ( const LigneLog & uneLigne );
    // Mode d'emploi :
    // Permet de valider une ligne (et renvoyer true) si son extension n'est pas
    // une des extensions interdites (qui sont stock�es dans l'attribut de cette classe)
    // Contrat :
    // Aucun

   void AjouterExtension(string ext);
    // Mode d'emploi :
    // Permet d'ajouter une extension interdite � la liste
    // Contrat :
    // Aucun


//------------------------------------------------- Surcharge d'op�rateurs

//-------------------------------------------- Constructeurs - destructeur
    OptionExtension(std::vector<std::string> &listeExtension);
    // Mode d'emploi :
    // Constructeur de OptionExtension
    // Contrat :
    // Aucun

    virtual ~OptionExtension( );
    // Mode d'emploi :
    // Destructeur de OptionExtension, lib�ration de la m�moire allou�e
    // Contrat :
    // Aucun

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- M�thodes prot�g�es
std::vector<std::string> extensionInterdite;

//----------------------------------------------------- Attributs prot�g�s
 unsigned int heure;

};
