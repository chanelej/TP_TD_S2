/*************************************************************************
                           OptionExtension
                             -------------------
    début                : 25/01/2019
    copyright            : B3228 - Chanèle Jourdan - Quentin Ferro
*************************************************************************/

//---------- Interface de la classe <OptionExtension> (fichier OptionExtension.h) ----------------
//#if ! defined ( OPTIONEXTENSION_H )
#define OPTIONEXTENSION_H

//--------------------------------------------------- Interfaces utilisées
#include<vector>
#include "Option.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <OptionExtension>
// Classe fille de Option qui permet de matérialiser l'option -e rentrée dans la
// ligne de commande. Cette classe va donc valider une ligne du fichier de logs
// si son extension ne fait pas partie de la liste extensionInterdite

//------------------------------------------------------------------------

class OptionExtension : public Option
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
  //   bool Valider ( const LigneLog & uneLigne );
    // Mode d'emploi :
    // Permet de valider une ligne (et renvoyer true) si son extension n'est pas
    // une des extensions interdites (qui sont stockées dans l'attribut de cette classe)
    // Contrat :
    // Aucun

   void AjouterExtension(string ext);
    // Mode d'emploi :
    // Permet d'ajouter une extension interdite à la liste
    // Contrat :
    // Aucun


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    OptionExtension(std::vector<std::string> &listeExtension);
    // Mode d'emploi :
    // Constructeur de OptionExtension
    // Contrat :
    // Aucun

    virtual ~OptionExtension( );
    // Mode d'emploi :
    // Destructeur de OptionExtension, libération de la mémoire allouée
    // Contrat :
    // Aucun

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
std::vector<std::string> extensionInterdite;

//----------------------------------------------------- Attributs protégés
 unsigned int heure;

};
