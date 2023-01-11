/*
 * Jeu.h
 *
 *  Created on: 3 janv. 2023
 *      Author: samid
 */

#ifndef JEU_H_
#define JEU_H_

#include <iostream>
#include "joueur.h"
#include "Plateau.h"

using namespace std;

class Jeu {

private:
	int nbJoueurs;
	Joueur* joueurs;
	Plateau board;

public:
	Jeu(std::string config = "0");
	//~Jeu();
	int getNbrJoueursEnJeu();
	void lancerPartie();
	void terminerPartie();
	//Ajouter de quoi g�rer l'exception caus�e par le fait qu'il n'y a pas assez de joueurs
	int joueurSuivant(int JoeurActuel);
	//void ench�re(Propriete);
	void jouerTour(int index);


};


#endif /* JEU_H_ */
