
/*************************************************************************
                           TRAJET  -  description
                             -------------------
    début                : 20/11/18
    copyright            : (C) Romain Perrone, Chanèle Jourdan - GROUPE 2_1
*************************************************************************/

//---------- Interface du module <TRAJET> (fichier Trajet.h) -------------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//------------------------------------------------------------------------
// Rôle du module <TRAJET>
// Représente un Trajet allant d'une ville de départ
// à une ville d'arrivée.
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types

class Trajet
{	
//////////////////////////////////////////////////////////////////  PUBLIC
	public:
	
//---------------------------------------------------- Fonctions publiques
		virtual void Afficher() const = 0;
		// Mode d'emploi :
		//	Affiche les villes de départ et d'arrivée.
		// Contrat :
		//	Aucun

		virtual std::string Script() =0;
		// Mode d'emploi :
		// Retourne la chaine de caractère correspondant à ce que l'on va stocker dans le fichier de sauvegarde
		// Contrat :
		//	Aucun	
		
		const char * getVilleDep();
		// Mode d'emploi :
		//	Renvoie un pointeur vers la ville de départ du trajet
		// Contrat :
		//	Aucun

		const char * getVilleArr();
		// Mode d'emploi :
		//	Renvoie un pointeur vers la ville d'arrivée du trajet
		// Contrat :
		//	Aucun

		virtual Trajet * copy() = 0;
		// Mode d'emploi :
		//	Construit une copie de Trajet et retourne son pointeur.
		// Contrat :
		//	Aucun

//----------------------------------------------- Surchages d'opérateurs

//---------------------------------------------------- Destructeur
		virtual ~Trajet();
		// Mode d'emploi :
		//	Libération de la mémoire allouée
		// Contrat :
		//	Aucun

//////////////////////////////////////////////////////////////////  PROTECTED
	protected:
		Trajet();
		// Mode d'emploi :
		//	Constructeur de trajet
		// Contrat :
		//	Aucun

		const char * vArr;
		const char * vDep;

};
#endif
