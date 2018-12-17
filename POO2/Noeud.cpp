/*************************************************************************
                           NOEUD -  description
                             -------------------
    début                : 20/11/18
    copyright            : (C) Romain Perrone, Chanèle Jourdan - GROUPE 2_1
*************************************************************************/

//---------- Réalisation de la classe <NOEUD (fichier Noeud.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
#include "Noeud.h"

using namespace std;

//------------------------------------------------------------- Méthodes publiques

void Noeud::AjouterNoeudAdjacent(Noeud *N)
{	
// Algorithme :
// Ajoute un pointeur vers un noeud dans le tableau des noeuds adjacent et le réalloue si nécéssaire
	
	listeAdjacents[nbNoeudsAdjacents] = N;
	nbNoeudsAdjacents++;

	if (nbNoeudsAdjacents >= size) {
		Realloc();
	}
}

void Noeud::RechercheRecursive(const char * villeArr, Noeud **path, int &index_etape, int &nbItinerairesPossibles)
{
	// Algorithme :
	// Méthode récursive permettant de trouver tous les itinéraires partant du noeud courrant et allant à villeArr
	// --> path est un tableau de pointeurs mémorisant les noeuds rencontrés 
	// --> parcouru est mis à vrai si le noeud a déjà été parcouru. 
	//     permet d'éviter d'être coincé dans une boucle infinie.
	// --> index_etape correspond au nombre d'élements stocké dans path

	// Marque le noeud actuel comme parcouru et le stocke dans path*[]
	parcouru = true;
	path[index_etape] = this;
	index_etape++;

	// si l'étape du noeud correspond à la ville d'arrivée, on affiche l'itinéraire correspondant
	if (strcmp(nomEtape, villeArr) == 0)
	{
		if (nbItinerairesPossibles == 0)
			cout << "Itinéraires possibles :" << endl;
		
		nbItinerairesPossibles++;
		cout << nbItinerairesPossibles << ": ";

		for (int i = 0; i < index_etape; i++)
		{
			cout << path[i]->nomEtape << ( (i<index_etape-1) ? " -> " : "" );
		}

		cout << endl;
	}
	else
	{
		for (int i = 0; i < nbNoeudsAdjacents; i++)
		{
			if (!listeAdjacents[i]->parcouru)
			{
			// on parcourt l'ensemble des noeuds adjacents de manière récursive jusqu'à atteindre la destination.
				listeAdjacents[i]->RechercheRecursive(villeArr, path, index_etape, nbItinerairesPossibles);
			}
		}
	}

	// on retire le noeud courrant de la liste des étapes effectuées.
	parcouru = false; 
	index_etape--;	
}


Noeud * Noeud::RechercherNoeudAdjacent(const char * nom)
{
// Algorithme :
// Parcours la liste des noeuds adjacent et regarde si il y en a un dont le nom de l'étape correspond au nom passé en 
// paramètre. Si ce n'est pas le cas le pointeur renvoyé est nul.
	
	for (int i = 0; i < nbNoeudsAdjacents; i++) 
	{
		if (strcmp(listeAdjacents[i]->nomEtape, nom) == 0)
			return listeAdjacents[i];
	}

	Noeud *n = nullptr; // retourne un pointeur nul
	return n;
}

void Noeud::Realloc()
{
// Algorithme :
// Réalloue le tableau de pointeurs en multipliant sa taille actuelle par un certain facteur et en copiant les pointeurs
	
	size = size * FACTEUR_REALLOC_NOEUD;
	Noeud **reallocListeAdjacents = new Noeud*[size];

	for (int i = 0; i< nbNoeudsAdjacents; i++) {
		Noeud * N = new Noeud();

		*N = *listeAdjacents[i];
		reallocListeAdjacents[i] = N; 
	}

	delete[] listeAdjacents;
	listeAdjacents = reallocListeAdjacents;
}

//------------------------------------------------- Surcharge d'opérateurs
Noeud & Noeud::operator = (const Noeud & unN)
{
	if (this != &unN)
	{
		delete[] listeAdjacents;

		nomEtape = unN.nomEtape;
		parcouru = unN.parcouru;
		nbNoeudsAdjacents = unN.nbNoeudsAdjacents;
		size = unN.size;

		listeAdjacents = new Noeud*[size];

		for (int i = 0; i < nbNoeudsAdjacents; i++) {
			Noeud * N = new Noeud();

			*N = *unN.listeAdjacents[i];
			listeAdjacents[i] = N;
		}
	}

	return *this;
}


//-------------------------------------------- Constructeurs - destructeur
Noeud::Noeud(const char * ville) : nomEtape(ville), parcouru(false), nbNoeudsAdjacents(0), size(ALLOC_INITIALE_NOEUD)
{
// Algorithme :
// Allocation de la mémoire pour le tableau de pointeurs vers des noeuds 
	#if defined (MAP)
		cout << "Appel au constructeur d'un noeud du graphe" << endl;
	#endif

	listeAdjacents = new Noeud*[ALLOC_INITIALE_NOEUD];
}

Noeud::~Noeud() 
{
// Algorithme :
//  Libération de la mémoire pour le tableau de pointeurs vers des noeuds 
	
	#if defined (MAP)
		cout << "Appel au destructeur d'un noeud du graphe." << endl;
	#endif

	delete[] listeAdjacents;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
