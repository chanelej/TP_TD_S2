/*************************************************************************
                           Option
                             -------------------
    d�but                : 25/01/2019
    copyright            : B3228 - Chan�le Jourdan - Quentin Ferro
*************************************************************************/

//---------- Interface de la classe <Option> (fichier Option.h) ----------------
#if ! defined ( OPTION_H )
#define OPTION_H

//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Option>
// Classe abstraite repr�sentant une option sp�cifi�e par l'utilisateur pour
// valider ou non une ligne du fichier de logs.
// Cette classe permet de manipuler les diff�rentes options (qui sont les classes
// filles de celle-ci) sans distinction de type.

//------------------------------------------------------------------------

class Option
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
   // virtual bool Valider ( const LigneLog & uneLigne ) =0;
    // Mode d'emploi :
    // Permet de valider uneLigne si elle correspond � l'option sp�cifi�e par l'utilisateur
    // Contrat :
    // Aucun


//------------------------------------------------- Surcharge d'op�rateurs

//-------------------------------------------- Constructeurs - destructeur
    Option( );
    // Mode d'emploi :
    // Constructeur de Option
    // Contrat :
    // Aucun

    virtual ~Option ( );
    // Mode d'emploi :
    // Destructeur de Option, lib�ration de la m�moire allou�e
    // Contrat :
    // Aucun

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s

};

//-------------------------------- Autres d�finitions d�pendantes de <Xxx>

#endif // OPTION_H

