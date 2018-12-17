/*************************************************************************
                           NOEUD  -  description
                             -------------------
    début                : 20/11/18
    copyright            : (C) Romain Perrone, Chanèle Jourdan - GROUPE 2_1
*************************************************************************/

//---------- Interface du module <NOEUD> (fichier Noeud.h) -------------------
#if ! defined ( NOEUD_H )
#define NOEUD_H

#include "Constantes.h"

//------------------------------------------------------------------------
// Rôle du module <NOEUD>
// Représente une étape dans un trajet (=une ville). 
// Les noeuds adjacents correspondent aux noeuds directement 
// accessibles depuis le noeud courrant. (=les destinations possibles depuis la ville actuelle)

//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées


//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

class Noeud
{
//////////////////////////////////////////////////////////////////  PUBLIC
		public:
	
//---------------------------------------------------- Fonctions publiques
		void Realloc();
		// Mode d'emploi :
		//	Réalloue le tableau de pointeurs de noeuds.
		// Contrat :
		//	Aucun
		
		Noeud * RechercherNoeudAdjacent(const char * nom);
		// Mode d'emploi :
		//	Recherche d'un noeud adjacent. 
		//  Renvoie le pointeur associé au noeud recherché, et un pointeur null en cas d'échec.
		// Contrat :
		//	Aucun

		void RechercheRecursive(const char * villeArr, Noeud **path, int &etape, int &count);
		// Mode d'emploi :
		//	 Méthode récursive permettant de trouver tous les itinéraires partant du noeud 
		// 	 courant et allant au noeud correspondant à villeArr
		// Contrat :
		//	Aucun

		void AjouterNoeudAdjacent(Noeud *N);
		// Mode d'emploi :
		//	Ajoute un pointeur vers un noeud adjacent dans le tableau
		// Contrat :
		//	Aucun


//----------------------------------------------- Surchages d'opérateurs
		Noeud & operator = (const Noeud & N);
		// Mode d'emploi :
		//	Surchage opérateur d'affectation
		// Contrat :
		//	Aucun

//------------------------------------------------Constructeur-Destructeur

		Noeud(const char * etape = "" );
		// Mode d'emploi :
		//	Construit un Noeud représentant une étape.
		// Contrat :
		//	Aucun

		~Noeud();
		// Mode d'emploi :
		//	Libère la mémoire allouée
		// Contrat :
		//	Aucun
	
//////////////////////////////////////////////////////////////// PROTECTED
	protected:
		int size; 
		int nbNoeudsAdjacents; 
		Noeud **listeAdjacents; // Tableau de pointeurs vers les noeuds adjacents

		const char * nomEtape; // nom de la ville
		bool parcouru; 

		friend class Graphe;
};
#endif
