/*************************************************************************
                           TRAJET  -  description
                             -------------------
    début                : 20/11/18
    copyright            : (C) Romain Perrone, Chanèle Jourdan - GROUPE 2_1
*************************************************************************/

//---------- Réalisation de la classe <CATALOGUE> (fichier Catalogue.cpp) -------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "CritereDeVilles.h"
#include "CritereAvecIntervalle.h"
#include "CritereDeType.h"

using namespace std;

//------------------------------------------------------------- Constantes

void Catalogue::Afficher() const
{
	listeItineraires->Afficher();
}

void Catalogue::AjouterTrajet(Trajet *t)
{
	listeItineraires->InsererTrajet(t);
	GrapheTrajets.AjouterTrajet(t->getVilleDep(), t->getVilleArr());
	nbItineraires++;
}

string Catalogue::ConstruireScript(int choixCritere, int &borneInf, int &borneSup, string &villeA, string &villeD) const{
    
    int nbTrajetsSaved = 0;
    

	//déclaration d'un Critere
	Critere *leCritere;

	//Initialisation du critère selon le choix de l'utilisateur
	if(choixCritere == 3) {
			leCritere = new CritereDeVilles(villeD, villeA);
	} else if(choixCritere == 4) {
			leCritere = new CritereAvecIntervalle(borneInf, borneSup);
	} else if(choixCritere == 21 || choixCritere == 22) {
			leCritere = new CritereDeType(choixCritere);
	} else {
		leCritere = new Critere();
	} 
    
    for (int i = 0; i < nbItineraires; i++) {
        if(leCritere->ValidationCritere(listeItineraires->Element(i))) {
            nbTrajetsSaved++;
        }
    }
    string chaine= "Nombre de trajets - "+std::to_string(nbTrajetsSaved)+"\n";

    //Ajout du script du trajet dans le fichier s'il respecte le critère
	for (int i = 0; i < nbItineraires; i++) {
        if(leCritere->ValidationCritere(listeItineraires->Element(i))) {
            chaine += listeItineraires->Element(i)->Script();
        }
    }	
        return chaine;
}

void Catalogue::ChargerScript(int nbSkip, int choixCritere, int &borneInf, int &borneSup, string &villeA, string &villeD) {

    //Creer un Critère général (à faire une fois que j'aurai créer les classes)
	//Selon la valeur de choixCritere l'initialiser comme le critère correspondant (idem)
	//Pour chaque ligne du script envoyé, crée un trajet temporaire t
	// regarder s'il valide le critère, et si oui on l'ajoute au catalogue (comme tu as fait dans le main mais faut le mettre ici)

	//NB : ATTENTION : le trajet temporaire t doit être crée avec un pointeur et supprimé ensuite sinon on aura des pb ac valgrind
	int nbTrajAded = 0;
	string name;
	cout << "Entrez un nom de fichier : (entrez q pour retourner au menu)" <<  endl;
	getline(cin, name);
	name += ".txt";

    ifstream infile (name, ios::in);
    int nbrTrajets;
    char vDep[50];
    char vArr[50];
    char tr[50];
    std::string vDepart;
    std::string vArrivee;
    std::string transport;
    std::string throwAway;
    std::string ligne;

    //Création du critère en fonction du choix de l'utilisateur
    Critere *leCritere;

    if(choixCritere == 3) {
        leCritere = new CritereDeVilles(villeD, villeA);
    } else if(choixCritere == 4) {
        leCritere = new CritereAvecIntervalle(borneInf, borneSup);
    } else if(choixCritere == 21) {
	leCritere = new CritereDeType(choixCritere);
    } else {
        leCritere= new Critere();
    }

    if(infile)
    {
        for(int j = 0; j<nbSkip; j++)
        {
            getline(infile, throwAway);
        }

        int i = 0;
        string type;
        getline(infile, throwAway, '-');
        infile >> nbrTrajets;
        cout << nbrTrajets << endl;
        while(i < nbrTrajets)
        {
            i++;
            do
            {
                infile >> type;
                cout << type << endl;
            } while(type != "TS" && type != "TC");

            if(type == "TS" && choixCritere != 22)
            {
                getline(infile, throwAway, ':');
                getline(infile, vDepart, ',');
                getline(infile, vArrivee, ',');
                getline(infile, transport);

                std::strcpy(vDep, vDepart.c_str());
                std::strcpy(vArr, vArrivee.c_str());
                std::strcpy(tr, transport.c_str());
                TrajetSimple *t = new TrajetSimple(vDep, vArr, tr);

                //Si le trajet répond au critère, on l'ajoute
                if(leCritere->ValidationCritere(t)) {
                    AjouterTrajet(t);
                }
            }

            if(type == "TC")
            {
                TrajetCompose* tc = new TrajetCompose();
                nbSkip = ChargerScript(tc, name, i, choixCritere, borneInf, borneSup, villeA, villeD);

                //Si le trajet répond au critère, on l'ajoute
                if(leCritere->ValidationCritere(tc)) {
                    AjouterTrajet(tc);
                }

                for(int j = 0; j<nbSkip+1; j++)
                {
                    getline(infile, throwAway);
                }
            }
        }
   } else if(name == "q.txt") {
		cout << "Retour au menu" << endl;
   } else { 
        cerr << "Impossible d'ouvrir le fichier ! Veuillez réessayer" << endl;
	return ChargerScript(nbSkip, choixCritere, borneInf, borneSup, villeA, villeD);
   }
   if(nbrTrajets == 0){
	cout << endl;
	cout << "Attention :  avez importé un catalogue vide" << endl; 
   }
}

int Catalogue::ChargerScript(TrajetCompose *traj, std::string name, int nbSkip, int choixCritere, int &borneInf, int &borneSup, string &villeA, string &villeD) {     //Version pour TC

	//NB : ATTENTION : le trajet temporaire t doit être crée avec un pointeur et supprimé ensuite sinon on aura des pb ac valgrind

    ifstream infile (name, ios::in);
    int nbrTrajets;
    char vDep[50];
    char vArr[50];
    char tr[50];
    string vDepart;
    string vArrivee;
    string transport;
    string throwAway;
    string ligne;

    if(infile)
    {
        for(int j = 0; j<nbSkip; j++)
        {
            getline(infile, throwAway);
        }

        int i = 0;
        string type;
        getline(infile, throwAway, '-');
        infile >> nbrTrajets;
        cout << nbrTrajets << endl;
        while(i < nbrTrajets)
        {
            i++;
            do
            {
                infile >> type;
                cout << type << endl;
            } while(type != "TS" && type != "TC");

            if(type == "TS")
            {
                getline(infile, throwAway, ':');
                getline(infile, vDepart, ',');
                getline(infile, vArrivee, ',');
                getline(infile, transport);

                std::strcpy(vDep, vDepart.c_str());
                std::strcpy(vArr, vArrivee.c_str());
                std::strcpy(tr, transport.c_str());
                TrajetSimple *t = new TrajetSimple(vDep, vArr, tr);
                traj->Ajouter(t);
            }
            if(type == "TC")
            {
            TrajetCompose* tc = new TrajetCompose();
            ChargerScript(tc, name, i, choixCritere, borneInf, borneSup, villeA, villeD);
            traj->Ajouter(tc);
            }
        }
   } else {
        cerr << "Erreur lors de la relecture du fichier ! Veuillez réessayer" << endl;
        ChargerScript(nbSkip, choixCritere, borneInf, borneSup, villeA, villeD);
   }
   return nbrTrajets;
}

void Catalogue::Rechercher(char* villeDep, char* villeArr) const
{
	GrapheTrajets.RechercheAvancee(villeDep, villeArr);
}


//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue()
{
	#if defined (MAP)
		cout << "Appel au constructeur de Catalogue" << endl;
	#endif

	nbItineraires = 0;

	listeItineraires = new Tableau();
	Graphe GrapheTrajets;
}

Catalogue::~Catalogue() {
	#if defined (MAP)
		cout << "Appel au destructeur de Catalogue" << endl;
	#endif

	delete[] listeItineraires;
}

 //------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées







