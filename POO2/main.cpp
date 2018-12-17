/*************************************************************************
                           MAIN -  description
                             -------------------
    début                : 20/11/18
    copyright            : (C) Romain Perrone, Chanèle Jourdan - GROUPE 2_1
*************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

//---------------------------------------------------------------- INCLUDE

#include <iostream>
#include <fstream>
#include <cstring>

#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Constantes.h"
#include "Tableau.h"
#include "Catalogue.h"

using namespace std;
//-----------------------------------------------------Déclaration des méthodes

unsigned int afficherMenu();
// Mode d'emploi :
//	Affiche le menu et retourne un entier entre 1 et 3 en fonction du choix de l'utilisateur.

void afficherCatalogue(const Catalogue &c);
// Mode d'emploi :
//	Affiche le catalogue.

void ajoutTrajet(Catalogue &c);
// Mode d'emploi :
//	Construit un trajet simple ou un trajet composé et l'ajoute au catalogue.

void rechercherItineraire(const Catalogue &c);
// Mode d'emploi :
//	Demande à l'utilisateur d'entrer une ville de départ et une ville d'arrivée, puis recherche l'itinéraire adapté.

void exporterCatalogue(const Catalogue &c, std::string name);
// Mode d'emploi :
// Permet d'exporter le catalogue dans un nouveau fichier

//-------------------------------------------------------------------- Main


int main(){
	unsigned int choix;
	cout << "Bienvenue dans l'application de gestion de trajets." << endl;

	Catalogue c;
	bool quitter = false;
	
	TrajetSimple *t1 = new TrajetSimple("A", "B", "Voiture");
	TrajetSimple *t2 = new TrajetSimple("B", "C", "Voiture");
	TrajetCompose coucou;
	coucou.Ajouter(t1);
	coucou.Ajouter(t2);
	cout << coucou.Script() << endl;
	c.AjouterTrajet(t1);
	c.AjouterTrajet(t2);
	
	exporterCatalogue(c, "catalogue.txt");
	
	while(!quitter) {
		choix = afficherMenu();

		if (choix == 1) {
			afficherCatalogue(c);
		}
		else if (choix == 2) {
			ajoutTrajet(c);
		}
		else if (choix == 3) {
			rechercherItineraire(c);
		} else {
			quitter = true;
		}

		cout << "\r\n";
	}
	
	return 0;
}

//----------------------------------------------------------- Définition des méthodes

unsigned int afficherMenu()
{
	unsigned int choix;

	do {
		cout << "Choisissez parmi les options suivantes:" << endl;
		cout << "1. Afficher le catalogue" << endl;
		cout << "2. Ajouter un trajet" << endl;
		cout << "3. Rechercher un parcours" << endl;
		cout << "4. Enregistrer et quitter." << endl;

		char* reponse = new char[TAILLE_MAX_INDEX];
		cin.getline(reponse, TAILLE_MAX_INDEX);

		choix = 0;

		if (strcmp(reponse, "1") == 0 || strcmp(reponse, "2") == 0 || strcmp(reponse, "3") == 0 || strcmp(reponse, "4") == 0) {
			choix = atoi(reponse); // convertit la chaîne de caractère en entier
		}
		else {
			cout << endl << "Vous devez saisir un chiffre entre 1 et 4.\r\n" << endl;
		}

		delete reponse;
	} while (choix == 0);

	return choix;
}

void afficherCatalogue(const Catalogue &c)
{
	c.Afficher();
}


void ajoutTrajet(Catalogue &c)
{
	unsigned int choixTrajet;

	// CHOIX ENTRE TRAJET SIMPLE ET COMPOSE
	do {
		cout << endl << "Choisissez parmi les options suivantes: " << endl;
		cout << "1. Ajouter un trajet simple" << endl;
		cout << "2. Ajouter un trajet composé" << endl;

		char* reponse = new char[TAILLE_MAX_INDEX];;
		cin.getline(reponse, TAILLE_MAX_INDEX);

		choixTrajet = 0;

		if (strcmp(reponse, "1") == 0 || strcmp(reponse, "2") == 0) {
			choixTrajet = atoi(reponse);
		}
		else
		{
			cout << endl << "Vous devez saisir un chiffre entre 1 et 2.\r\n" << endl;
		}

		delete[] reponse;
	} while (choixTrajet == 0);

	char* villeDep = new char[TAILLE_MAX_VILLE];
	char* villeArr = new char[TAILLE_MAX_VILLE];
	char* transport = new char[TAILLE_MAX_TRANSPORT];

	// AJOUT D'UN TRAJET SIMPLE
	if (choixTrajet == 1) {
		cout << endl << "Ville de départ: " << endl;
		cin.getline(villeDep, TAILLE_MAX_VILLE);

		cout << endl << "Ville d'arrivée: " << endl;
		cin.getline(villeArr, TAILLE_MAX_VILLE);

		cout << endl << "Moyen de transport: " << endl;
		cin.getline(transport, TAILLE_MAX_TRANSPORT);

		Trajet *t; // pointeur vers Trajet utilisé pour la liaison dynamique
		TrajetSimple * t_simple = new TrajetSimple(villeDep, villeArr, transport);

		t = t_simple; 
		c.AjouterTrajet(t);
	}

	// AJOUT D'UN TRAJET COMPOSE
	else
	{
		unsigned int choixTrajetCompose;
		unsigned int nbAjout = 0;
		bool ajouter = true;

		TrajetCompose * t;
		TrajetCompose * tcompose = new TrajetCompose();

		char * villeEtapePrecedente = new char[TAILLE_MAX_VILLE]; // la ville d'arrivée d'une étape et de départ de la suivante doivent être identiques

		while (ajouter) {
			do {
				cout << endl << "Vous être en train d'ajouter un trajet composé." << endl;
				cout << "Choisissez parmi les options suivantes: " << endl;
				cout << "1. Ajouter une étape." << endl;

				// On peut mettre fin à l'itinéraire si au moins un trajet a été ajouté
				if (nbAjout > 1) {
					cout << "2. Terminer l'itinéraire." << endl;
				}

				char* reponse = new char[TAILLE_MAX_INDEX];
				cin.getline(reponse, TAILLE_MAX_INDEX); 

				choixTrajetCompose = 0;

				if (strcmp(reponse, "1") == 0 || (strcmp(reponse, "2") == 0 && nbAjout > 1)) {
					choixTrajetCompose = atoi(reponse);
				}
				else {
					cout << endl << "Vous devez saisir un chiffre entre 1 et 2.\r\n" << endl;
				}

				delete[] reponse;
			} while (choixTrajetCompose == 0);

			// premier ajout
			if (choixTrajetCompose == 1 && nbAjout < 1) {
				cout << endl << "Ville de départ: " << endl;
				cin.getline(villeDep, TAILLE_MAX_VILLE);

				cout << endl << "Ville d'arrivée: " << endl;
				cin.getline(villeArr, TAILLE_MAX_VILLE); 

				cout << endl << "Moyen de transport: " << endl;
				cin.getline(transport, TAILLE_MAX_TRANSPORT);

				Trajet * tTemp; // pointeur Trajet pour la liaison dynamique
				TrajetSimple * t_simple = new TrajetSimple(villeDep, villeArr, transport);

				tTemp = t_simple;
				tcompose->Ajouter(tTemp);

				strcpy(villeEtapePrecedente, villeArr); // on mémorise la ville d'arrivée
				nbAjout++;
			}
			else if (choixTrajetCompose == 1 && nbAjout >= 1)
			{
				cout << endl << "Ville de départ: " << endl;
				cout << villeEtapePrecedente << endl;

				cout << endl << "Ville d'arrivée: " << endl;
				cin.getline(villeArr, TAILLE_MAX_VILLE);

				cout << endl << "Moyen de transport: " << endl;
				cin.getline(transport, TAILLE_MAX_TRANSPORT);

				Trajet * tTemp; // pointeur Trajet pour la liaison dynamique
				TrajetSimple * t_simple = new TrajetSimple(villeEtapePrecedente, villeArr, transport);

				tTemp = t_simple;
				tcompose->Ajouter(tTemp);

				strcpy(villeEtapePrecedente, villeArr);  // on mémorise la ville d'arrivée
				nbAjout++;
			}
			else
			{
				t = tcompose; // pointeur de Trajet pour la liaison dynamique 
				c.AjouterTrajet(t); // on met fin à l'itinéraire

				delete[] villeEtapePrecedente;
				ajouter = false;
			}
		}
	}

	delete[] villeDep;
	delete[] villeArr;
	delete[] transport;
}

void rechercherItineraire(const Catalogue &c)
{
	char* villeDep = new char[TAILLE_MAX_VILLE];
	char* villeArr = new char[TAILLE_MAX_VILLE];

	cout << endl << "Ville de départ: " << endl;
	cin.getline(villeDep, TAILLE_MAX_VILLE);

	cout << endl << "Ville d'arrivée: " << endl;
	cin.getline(villeArr, TAILLE_MAX_VILLE);

	cout << endl;
	c.Rechercher(villeDep, villeArr);

	delete[] villeDep;
	delete[] villeArr;
}

void exporterCatalogue(const Catalogue &c, std::string name)
{
	std::ofstream outfile (name);
	outfile << c.ConstruireScript(0);
}
