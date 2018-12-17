/*************************************************************************
                           TABLEAU  -  description
                             -------------------
    début                : 20/11/18
    copyright            : (C) Romain Perrone, Chanèle Jourdan - GROUPE 2_1
*************************************************************************/

//---------- Interface du module <TABLEAU> (fichier Tableau.h) -------------------
#if ! defined ( TABLEAU_H )
#define TABLEAU_H

#include<cstring>
#include "Trajet.h"
#include "Graphe.h"
#include "Constantes.h"


//------------------------------------------------------------------------
// Rôle du module <TABLEAU>
// Représente un Tableau dynamique de pointeurs sur des Trajets. On peut 
// afficher les trajets dont il est constitué, en ajouter des nouveaux, ainsi
//qu'effectuer une recherche de Trajet (recherche simple)

//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées


//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

class Tableau
{
//////////////////////////////////////////////////////////////////  PUBLIC
		public:
//---------------------------------------------------- Fonctions publiques
		void Realloc();
		// Mode d'emploi :
		//	Réalloue le tableau de pointeurs de Trajet
		// Contrat :
		//	Aucun

		void InsererTrajet(Trajet *T);
		// Mode d'emploi :
		//	Insère le pointeur vers un Trajet dans le tableau
		// Contrat :
		//	Aucun
		
		void Afficher() const;
		// Mode d'emploi :
		//	Affiche l'ensemble des trajets pointés par les éléments du tableau
		// Contrat :
		//	Aucun

		void Rechercher(char* villeDep, char* villeArr) const;
		// Mode d'emploi :
		//	Recherche d'un itinéraire à partir d'une ville de départ et d'une ville d'arrivée.
		//  	Affiche uniquement les trajets (simples/composés) correspondant aux villes de départ et d'arrivée.
		// Contrat :
		//	Aucun	
		
		Trajet* Element(int i) const ;
		// Mode d'emploi :
		//	Renvoie l'élément i du tableau de trajets
		// Contrat :
		//	Aucun	

		void AfficherElement(int i) const;
		// Mode d'emploi :
		//	Affiche le trajet pointé par le pointeur d'indice i	
		// Contrat :
		//	Aucun: pas de vérification nécessaire pour l'indice passé en paramètre.


//----------------------------------------------- Surchages d'opérateurs
//------------------------------------------------Constructeur-Destructeur

		Tableau(int size=ALLOC_INITIALE_TABLEAU);
		// Mode d'emploi :
		//	Construit un tableau de pointeurs vers des Trajets
		// Contrat :
		//	Aucun

		Tableau(Tableau const& unTableau);
		// Mode d'emploi :
		//	Constructeur de copie de Tableau
		// Contrat :
		//	Aucun

		~Tableau();
		// Mode d'emploi :
		//	Libère la mémoire allouée
		// Contrat :
		//	Aucun

//////////////////////////////////////////////////////////////// PROTECTED

	protected:
		int size;
		int nbElements;
		Trajet **listeTrajets;
};
#endif
