/*************************************************************************
                           Option
                             -------------------
    début                : 25/01/2019
    copyright            : B3228 - Chanèle Jourdan - Quentin Ferro
*************************************************************************/

//---------- Interface de la classe <Option> (fichier Option.h) ----------------
#if ! defined ( OPTION_H )
#define OPTION_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Option>
// Classe abstraite représentant une option spécifiée par l'utilisateur pour
// valider ou non une ligne du fichier de logs.
// Cette classe permet de manipuler les différentes options (qui sont les classes
// filles de celle-ci) sans distinction de type.

//------------------------------------------------------------------------

class Option
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
   // virtual bool Valider ( const LigneLog & uneLigne ) =0;
    // Mode d'emploi :
    // Permet de valider uneLigne si elle correspond à l'option spécifiée par l'utilisateur
    // Contrat :
    // Aucun


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Option( );
    // Mode d'emploi :
    // Constructeur de Option
    // Contrat :
    // Aucun

    virtual ~Option ( );
    // Mode d'emploi :
    // Destructeur de Option, libération de la mémoire allouée
    // Contrat :
    // Aucun

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // OPTION_H

