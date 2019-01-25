/*************************************************************************
                           OptionHeure
                             -------------------
    d�but                : 25/01/2019
    copyright            : B3228 - Chan�le Jourdan - Quentin Ferro
*************************************************************************/

//---------- Interface de la classe <OptionHeure> (fichier OptionHeure.h) ----------------
#if ! defined ( OPTIONHEURE_H )
#define OPTIONHEURE_H

//--------------------------------------------------- Interfaces utilis�es

#include "Option.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <OptionHeure>
// Classe fille de Option qui permet de mat�rialiser l'option -t rentr�e dans la
// ligne de commande. Cette classe va donc valider une ligne du fichier de logs
// si son heure correspond � celle que l'utilisateur a sp�cifi�.

//------------------------------------------------------------------------

class OptionHeure : public Option
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    // bool Valider ( const LigneLog & uneLigne );
    // Mode d'emploi :
    // Permet de valider une ligne (et renvoyer true) si son heure est comprise
    // entre h et h+1, h �tant l'heure sp�cifi�e par l'utilisateur pour cette option.
    // Contrat :
    // Aucun


//------------------------------------------------- Surcharge d'op�rateurs

//-------------------------------------------- Constructeurs - destructeur
    OptionHeure(int uneHeure);
    // Mode d'emploi :
    // Constructeur de OptionHeure
    // Contrat :
    // Aucun

    virtual ~OptionHeure ( );
    // Mode d'emploi :
    // Destructeur de OptionHeure, lib�ration de la m�moire allou�e
    // Contrat :
    // Aucun

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s
 unsigned int heure;

};

//-------------------------------- Autres d�finitions d�pendantes de <OptionHeure>

#endif // OPTIONHEURE_H
