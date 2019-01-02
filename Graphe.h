/*************************************************************************
                           GRAPHE  -  description
                             -------------------
    début                : 20/11/18
    copyright            : (C) Romain Perrone, Chanèle Jourdan - GROUPE 2_1
*************************************************************************/

//---------- Interface du module <GRAPHE> (fichier Graphe.h) -------------------
#if ! defined ( GRAPHE_H )
#define GRAPHE_H

#include "Noeud.h"
#include "Constantes.h"

//------------------------------------------------------------------------
// Rôle du module <GRAPHE>
// Représente une étape dans un trajet. Utilisé pour la recherche avancée (graphe)


//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées


//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

class Graphe
{
//////////////////////////////////////////////////////////////////  PUBLIC
		public:
//---------------------------------------------------- Fonctions publiques
		void Realloc();
		// Mode d'emploi :
		//	Réalloue le tableau de pointeur listeNoeuds.
		// Contrat :
		//	Aucun

		void AjouterTrajet(const char * dep, const char * arr);
		// Mode d'emploi :
		//  Ajoute un trajet dans le graphe.
		// Contrat :
		//	Aucun

		void RechercheAvancee(const char* villeDep, const char* villeArr) const;
		// Mode d'emploi :
		//	 Affiche l'ensemble des itinéraires permettant de se rendre 
		//   d’une ville de départ à une ville d’arrivée.
		//   Remarque: Un trajet composé ne peut pas être interrompu en cours de route.
		// Contrat :
		//	Aucun	

//------------------------------------------------Constructeur-Destructeur
		Graphe(int size = ALLOC_INITIALE_GRAPHE);
		// Mode d'emploi :
		//	Construit un graphe d’étapes en allouant un tableau de pointeurs vers des nœuds.
		// Contrat :
		//	Aucun

		~Graphe();
		// Mode d'emploi :
		//	Libération de la mémoire pour le tableau de pointeurs vers des noeuds 
		// Contrat :
		//	Aucun

//----------------------------------------------- Surchages d'opérateurs

//////////////////////////////////////////////////////////////// PRIVATE	

	private:
		Noeud * rechercherNoeud(const char * nom) const;
		// Mode d'emploi :
		//	Recherche récursivement un noeud dans le graphe.
		// Contrat :
		//	Aucun

		static int distanceDeLevenshtein(const char *, const char *);
		// Mode d'emploi :
		//	Calcule la distance de Levenshtein (nombre minimal de caractères qu'il faut supprimer, 
		//  insérer ou remplacer pour passer d'une chaîne de caractères à l'autre)
		// Contrat :
		//	Aucun

		inline static int min(int a, int b) {
			return (a < b) ? a : b;
		}

		int size; 
		int nbNoeuds; 
		Noeud **listeNoeuds; 



};
#endif
