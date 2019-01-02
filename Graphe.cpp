/*************************************************************************
                           GRAPHE -  description
                             -------------------
    début                : 20/11/18
    copyright            : (C) Romain Perrone, Chanèle Jourdan - GROUPE 2_1
*************************************************************************/

//---------- Réalisation de la classe <GRAPHE (fichier Graphe.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>

#include "Graphe.h"
#include "Noeud.h"
#include "Constantes.h"

using namespace std;

//------------------------------------------------------------- Méthodes publiques

void Graphe::AjouterTrajet(const char * dep, const char * arr)
{
// Algorithme :
// Parcourt la liste des noeuds, ajoute les deux villes si elles n'en font pas partis et les connecte entre elles
// en ajoutant la ville d'arrivée aux noeuds adjacents de la ville de départ.
	
	Noeud *noeudDep = rechercherNoeud(dep);
	Noeud *noeudArr = rechercherNoeud(arr);

	// si aucun noeud n'a été trouvé (pointeur nul), on crée le noeud et on l'ajoute au graphe, et ceci pour les deux villes
	if (!noeudDep)
	{ 
		Noeud * nouveauNoeud = new Noeud(dep);
		noeudDep = nouveauNoeud;

		listeNoeuds[nbNoeuds] = noeudDep;
		nbNoeuds++;
	}

	if (!noeudArr)
	{
		Noeud * nouveauNoeud = new Noeud(arr);
		noeudArr = nouveauNoeud;
	}

	// la ville d'arrivée est connectée à la ville de départ
	noeudDep->AjouterNoeudAdjacent(noeudArr);

	if (nbNoeuds >= size) {
		Realloc();
	}
}

void Graphe::RechercheAvancee(const char* villeDep, const char* villeArr) const
{
// Algorithme :
// Affiche l'ensemble des itinéraires possibles pour aller de villeDep à villArr en utilisant la méthode 
// rechercheRecursive du Noeud correspondant à villeDep. Si villeDep n'existe pas et qu'une ville à l'orthographe
// similaire fait parti de notre graphe, on fait une suggestion à l'utilisateur en supposant une faute de frappe
	
	Noeud *noeudDep = rechercherNoeud(villeDep); //Pointeur vers le noeud correspondant à la ville de départ 

	if (!noeudDep) //Si le pointeur est nul
	{
		cout << "Aucun itinéraire trouvé. " << endl;
		cout << "Aucun trajet ne part de " << villeDep << endl;

		// suggère une ville de départ dont le nom est proche dans le cas d'une faute de frappe
		if (nbNoeuds > 0)
		{
			Noeud * suggestion = listeNoeuds[0];
			int distanceMin = INT_MAX; 

			for (int i = 0; i < nbNoeuds; i++) {
				int distance = Graphe::distanceDeLevenshtein(villeDep, listeNoeuds[i]->nomEtape);

				if (distance < distanceMin) {
					distanceMin = distance;
					suggestion = listeNoeuds[i];
				}
			}

			if (distanceMin < 3) { // si les deux villes ont un nom presque similaire
				cout << "Essayez avec l'orthographe " << suggestion->nomEtape << endl;
			}
		}

		return;
	}
	
	// définition de paramètres nécéssaires à la méthode RechercheRecursive de Noeud
	Noeud **path = new Noeud*[NB_MAX_ETAPES];
	int index_etape = 0;
	int nbItinerairesPossibles = 0;

	noeudDep->RechercheRecursive(villeArr, path, index_etape, nbItinerairesPossibles);

	if (nbItinerairesPossibles == 0)
	{
		cout << "Aucun itinéraire trouvé pour aller de " << villeDep << " à " << villeArr << endl;
	}
}

void Graphe::Realloc()
{
	// Algorithme :
	// Réalloue le tableau de pointeurs en multipliant sa taille actuelle par un certain facteur et en copiant les pointeurs
	
	size = size * FACTEUR_REALLOC_GRAPHE;
	Noeud **reallocListeNoeuds = new Noeud*[size];

	for (int i = 0; i< nbNoeuds; i++) {
		Noeud * N = new Noeud();
		*N = *listeNoeuds[i];

		reallocListeNoeuds[i] = N;
	}

	delete[] listeNoeuds;
	listeNoeuds = reallocListeNoeuds;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Graphe::Graphe(int taille) : nbNoeuds(0), size(taille)
{
// Algorithme :
// Allocation de la mémoire pour le tableau de pointeurs vers des noeuds 
	#if defined (MAP)
		cout << "Appel au constructeur du graphe" << endl;
	#endif

	listeNoeuds = new Noeud*[size];
}

Graphe::~Graphe() 
{
// Algorithme :
// Libération de la mémoire pour le tableau de pointeurs vers des noeuds 
	#if defined (MAP)
		cout << "Appel au destructeur du graphe." << endl;
	#endif

	delete[] listeNoeuds;
}

//------------------------------------------------------------------ PRIVE

Noeud * Graphe::rechercherNoeud(const char * nom) const
{
	// parcourt récursivement l'ensemble des noeuds du graphe
	for (int i = 0; i < nbNoeuds; i++) 
	{
		if (strcmp(listeNoeuds[i]->nomEtape, nom) == 0) // si les noms sont identiques, on retourne le résultat.
			return listeNoeuds[i];

		Noeud * N = listeNoeuds[i]->RechercherNoeudAdjacent(nom);

		if (N)  // si le pointeur retourné n'est pas un pointeur nul
			return N;
	}
	
	Noeud *n = nullptr; // on retourne un pointeur null
	return n;
}

int Graphe::distanceDeLevenshtein(const char * s1, const char * s2)
{
	// Algorithme :
	// Calcule la distance de Levenshtein entre deux chaines de caractère par programmation dynamique 
	
	bool egal;
	int dist[TAILLE_MAX_VILLE][TAILLE_MAX_VILLE];

	int s1_length = strlen(s1);
	int s2_length = strlen(s2);
	

	for (int i = 0; i <= s1_length; i++) {
		dist[0][i] = i;
	}

	for (int j = 0; j <= s2_length; j++) {
		dist[j][0] = j;
	}
	
	for (int j = 1; j <= s1_length; j++)
	{
		for (int i = 1; i <= s2_length; i++)
		{
			egal = (s1[i - 1] == s2[j - 1]) ? true : false; 
			dist[i][j] = min( min(dist[i - 1][j] + 1, dist[i][j - 1] + 1), dist[i - 1][j - 1] + egal);
		}
	}

	return dist[s1_length][s2_length];
}

//----------------------------------------------------- Méthodes protégées
