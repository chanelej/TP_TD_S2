/*************************************************************************
                           OptionHeure
                             -------------------
    début                : 25/01/2019
    copyright            : B3228 - Chanèle Jourdan - Quentin Ferro
*************************************************************************/

//---------- Interface de la classe <OptionHeure> (fichier OptionHeure.h) ----------------
#if ! defined ( OPTIONHEURE_H )
#define OPTIONHEURE_H

//--------------------------------------------------- Interfaces utilisées

#include "Option.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <OptionHeure>
// Classe fille de Option qui permet de matérialiser l'option -t rentrée dans la
// ligne de commande. Cette classe va donc valider une ligne du fichier de logs
// si son heure correspond à celle que l'utilisateur a spécifié.

//------------------------------------------------------------------------

class OptionHeure : public Option
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // bool Valider ( const LigneLog & uneLigne );
    // Mode d'emploi :
    // Permet de valider une ligne (et renvoyer true) si son heure est comprise
    // entre h et h+1, h étant l'heure spécifiée par l'utilisateur pour cette option.
    // Contrat :
    // Aucun


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    OptionHeure(int uneHeure);
    // Mode d'emploi :
    // Constructeur de OptionHeure
    // Contrat :
    // Aucun

    virtual ~OptionHeure ( );
    // Mode d'emploi :
    // Destructeur de OptionHeure, libération de la mémoire allouée
    // Contrat :
    // Aucun

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
 unsigned int heure;

};

//-------------------------------- Autres définitions dépendantes de <OptionHeure>

#endif // OPTIONHEURE_H
