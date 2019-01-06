/*************************************************************************
                           MAIN -  description
                             -------------------
    début                : 20/11/18
    copyright            : (C) Romain Perrone, Chanèle Jourdan - GROUPE 2_1
				+ Quentin Ferro - Groupe 2_28
*************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

//---------------------------------------------------------------- INCLUDE

#include <iostream>
#include <fstream>
#include <cstring>
#include <ctype.h>

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

void exporterCatalogue(const Catalogue &c);
// Mode d'emploi :
// Permet d'exporter le catalogue dans un nouveau fichier ou un fichier déjà existant

void ouvrirCatalogue(Catalogue &c);
// Mode d'emploi :
// Permet d'ouvrir un catalogue présent dans un fichier name et de l'importer dans le catalogue courant

int choixDuCritere(int &borneInf, int &borneSup, string &villeA, string &villeD);
// Mode d'emploi :
// Permet de matérialiser l'interface avec l'utilisateur qui lui permet de choisir le critère de sauvegarde/chargement.
// Chaque cas particulier où la saisie n'est pas exploitable est traité, et un entier correspondant à un des critère est retourné.

//-------------------------------------------------------------------- Main


int main(){
	unsigned int choix;
	cout << "Bienvenue dans l'application de gestion de trajets." << endl;

	Catalogue c;
	bool quitter = false;

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
		}
		else if (choix==4) {
			exporterCatalogue(c);
		}
		else if (choix ==5) {
			ouvrirCatalogue(c);
        }
        else {
			quitter = true;

		cout << "\r\n";
        }
	}

	return 0;
}

//----------------------------------------------------------- Définition des méthodes

unsigned int afficherMenu()
{
	unsigned int choix;

	do {
		cout << endl <<"Choisissez parmi les options suivantes:" << endl;
		cout << "1. Afficher le catalogue" << endl;
		cout << "2. Ajouter un trajet" << endl;
		cout << "3. Rechercher un parcours" << endl;
		cout << "4. Sauvegarder le catalogue courant" << endl;
		cout << "5. Charger un catalogue depuis un fichier"<< endl;
		cout << "6. Quitter l'application" << endl;

		char* reponse = new char[TAILLE_MAX_INDEX];
		cin.getline(reponse, TAILLE_MAX_INDEX);

		choix = 0;

		if (strcmp(reponse, "1") == 0 || strcmp(reponse, "2") == 0 || strcmp(reponse, "3") == 0 || strcmp(reponse, "4") == 0 || strcmp(reponse, "5") == 0 || strcmp(reponse, "6") == 0) {
			choix = atoi(reponse); // convertit la chaîne de caractère en entier
		}
		else {
			cout << endl << "Vous devez saisir un chiffre entre 1 et 6.\r\n" << endl;
		}

		delete[] reponse;
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

void exporterCatalogue(const Catalogue &c)
{
    //Choix du critère par l'utilisateur via un appel à une autre méthode
    int borneInf=0;
    int borneSup=0;
    string villeD="";
    string villeA="";

	int choixCrit = choixDuCritere(borneInf,borneSup,villeA,villeD);

	//Gestion du fichier
	char* choix = new char[TAILLE_MAX_INDEX];
    	string name;
	cout << "Entrez un nom de fichier : (entrez q pour retourner au menu)" <<  endl;
	getline(cin, name);
	name += ".txt";

	ifstream infile (name, ios::in);

	//Gestion des cas particuliers liés au fichier
	if(infile) {

		cout << "Le fichier existe déjà, souhaitez vous :" << endl;
		cout << "1. L’écraser" << endl;
		cout << "2. Écrire à la suite de ce fichier (attention : le critère de sélection s’appliquera à l’ensemble, donc aux trajets déjà présents aussi)" << endl;
		cout << "3. Entrez de nouveau un nom" << endl;
		cin.getline(choix, TAILLE_MAX_INDEX);

		if(strcmp(choix, "2")==0) {
			Catalogue c2;
			c2.ChargerScript(name, 0, 1, borneInf, borneSup, villeA, villeD);
			c.Concat(c2);
			std::ofstream outfile (name);
			outfile << c2.ConstruireScript(choixCrit,borneInf,borneSup,villeA,villeD);
		} else if(strcmp(choix, "3")==0) {
			return exporterCatalogue(c);
		} else {
			std::ofstream outfile (name);
			outfile << c.ConstruireScript(choixCrit,borneInf,borneSup,villeA,villeD);
		}

	} else if(name == "q.txt") {
		cout << endl;
		cout << "Retour au menu" << endl;
	} else {
		std::ofstream outfile (name);
		outfile << c.ConstruireScript(choixCrit,borneInf,borneSup,villeA,villeD);
	}
	delete[] choix;
}

void ouvrirCatalogue(Catalogue &c)
{
	//Choix du critère par l'utilisateur via un appel à une autre méthode
	int borneInf = 0;
	int borneSup = 0;
	string villeD = "";
	string villeA = "";

	int choixCritere = choixDuCritere(borneInf, borneSup, villeA, villeD);

    //Gestion des fichiers
	string name;
	cout << "Entrez un nom de fichier : (entrez q pour retourner au menu)" <<  endl;
	getline(cin, name);
	name += ".txt";
	c.ChargerScript(name, 0, choixCritere, borneInf, borneSup, villeA, villeD);
}

int choixDuCritere(int &borneInf, int &borneSup, string &villeA, string &villeD){

    int choix = 0;

    do{
        //PROPOSITION DES CRITERES

        cout << endl<<"Choisissez parmi les critères suivants pour sélectionner les trajets : " << endl;
        cout << "1. Sans critère de sélection." << endl;
        cout << "2. Selon le type de trajets (simple/composé)." << endl;
        cout << "3. Selon la ville de départ et/ou la ville d'arrivée." << endl;
        cout << "4. Selon une sélection d'après un intervalle." << endl;

        char* reponse = new char[TAILLE_MAX_VILLE];
        cin.getline(reponse, TAILLE_MAX_VILLE);

        //GESTION DES DIFFERENTS CAS

        if (strcmp(reponse, "1") == 0) {
            choix = atoi(reponse);
        }
         else if (strcmp(reponse, "2") == 0) {
            choix =0;
            do{
                //Choix du type de trajet et gestion du cas où le chiffre ne correspond pas à l'une des propositions
                cout << endl << "Choisissez le type trajet que vous souhaiter sélectionner :" << endl;
                cout << "1. Trajets simples." << endl;
                cout << "2. Trajets composés." << endl;

                cin.getline(reponse, TAILLE_MAX_INDEX);

                if (strcmp(reponse, "1") == 0 || strcmp(reponse, "2") == 0){
                    choix = 20 + atoi(reponse);
                }
                else {
                    cout << endl << "Vous devez saisir un chiffre entre 1 et 2" << endl;
                }
            } while (choix!=21 && choix!=22);
        }

         else if (strcmp(reponse, "3") == 0) {
            choix = atoi(reponse);

            do{
                //Saisie du nom de(s) ville(s) et gestion du cas ou aucune ville n'est renseignée
                cout << endl << "Saisissez les villes (entrez 0 si une des villes ne vous importe pas)" << endl;
                cout << endl << "Ville de départ :" << endl;
                cin.getline(reponse, TAILLE_MAX_VILLE);
                villeD=reponse;
                cout << "Ville d'arrivée : " << endl;
                cin.getline(reponse, TAILLE_MAX_VILLE);
                villeA=reponse;

            if (villeA=="0" && villeD=="0"){
                    cout<<endl<<"Vous devez obligatoirement renseigner le nom d'une des deux villes"<<endl<<endl;
                }
            } while (villeA=="0" && villeD=="0");
        }

         else if (strcmp(reponse, "4") == 0) {

            choix = atoi(reponse);
            bool bornesValides;


            do{
                bornesValides=true;
                bool borneChiffre=true;

                //Saisie des bornes de l'intervalle
                cout << endl << "Saisissez les bornes de l'intervalle souhaité" << endl;
                cout << endl << "Borne inférieure :" << endl;
                cin.getline(reponse, TAILLE_MAX_INDEX);
                if(!(isdigit(reponse[0]))){
                    bornesValides=false;
                    borneChiffre=false;
                }
                borneInf=atoi(reponse);

                cout << "Borne supérieure : " << endl;
                cin.getline(reponse, TAILLE_MAX_INDEX);
                if(!(isdigit(reponse[0]))){
                    borneChiffre=false;
                    bornesValides=false;
                }
                borneSup=atoi(reponse);

                //Gestion du cas où une des bornes n'est pas un nombre:
                if (!borneChiffre){
                    cout<<endl<<"Les bornes doivent être des nombres, veuillez réessayer"<<endl<<endl;
                }

                //Gestion du cas où il y a une borne nulle (ou plusieurs)
                if((borneSup==0 || borneInf==0)&&borneChiffre){
                    bornesValides=false;
                    if(borneInf==0){
                        borneInf++;
                    }
                    if(borneSup==0){
                        borneSup++;
                    }
                    cout<<endl<<"Les bornes ne peuvent pas être nulles, vouliez vous dire : ["<<borneInf<<" ; "<<borneSup<<"] ?"<<endl;
                    cout <<"Tapez oui ou non :  ";
                    cin.getline(reponse, TAILLE_MAX_INDEX);
                    if (strcmp(reponse, "oui") == 0){
                        bornesValides=true;
                    }
                }

                 //Gestion du cas où il y a une borne négative (ou plusieurs)
                if((borneSup<0 || borneInf<0)&&borneChiffre){
                    bornesValides=false;
                    if(borneInf<0){
                        borneInf=-borneInf;
                    }
                    if(borneSup<0){
                        borneSup=-borneSup;
                    }
                    cout<<endl<<"Les bornes ne peuvent pas être nulles, vouliez vous dire : ["<<borneInf<<" ; "<<borneSup<<"] ?"<<endl;
                    cout <<"Tapez oui ou non :  ";
                    cin.getline(reponse, TAILLE_MAX_INDEX);
                    if (strcmp(reponse, "oui") == 0){
                        bornesValides=true;
                    }
                }

                  //Gestion du cas où borneInf est plus grande que borneSup
                if((borneSup<borneInf)&&borneChiffre){
                    bornesValides=false;

                    int tmp;
                    tmp=borneInf;
                    borneInf=borneSup;
                    borneSup=tmp;
                    cout<<endl<<"Les bornes doivent être rentrées dans l'ordre croissant, vouliez vous dire : ["<<borneInf<<" ; "<<borneSup<<"] ?"<<endl;
                    cout <<"Tapez oui ou non :  ";
                    cin.getline(reponse, TAILLE_MAX_INDEX);
                    if (strcmp(reponse, "oui") == 0){
                        bornesValides=true;
                    }
                }
            }while (!bornesValides);
        }

        else {
            cout << endl << "Vous devez saisir un chiffre entre 1 et 4.\r\n" << endl;
        }

        delete[] reponse;

    } while (choix == 0);

    return choix ;
}



