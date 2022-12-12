#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>

/***
* Classe Joueur
* Contient toutes les infos n�cessaires � un joueur et reste actuellement � compl�ter
***/
class Joueur
{
public:
	Joueur();

	std::string getPseudo() { return pseudo; };
	int getTempsPrison() { return tpsPrison; };
	int getPosition() { return position; };
	int getSolde() { return solde; };
	bool isStillPlaying() { return isPlaying; };

	/***
	* ATTENTION : Ajouter de quoi v�rifier que le joueur ne sort pas du plateau (dans plateau par exemple)
	* D�fini la nouvelle position du joueur
	***/
	void setPosition(int newPos);
	/***
	* D�place le joueur de nbPas par rapport � sa position actuelle.
	* nbPas peut �tre n�gatif
	***/
	void move(int nbPas);

	/***
	* Modifie le solde du joueur;
	***/
	void setSolde(int newSolde);
	/***
	* Change le solde du joueur d'un montant montant par rapport � son solde actuel.
	* Montant peut �tre n�gatif.
	***/
	void changeSolde(int montant);


private:
	std::string pseudo;
	int tpsPrison;
	int position;
	int solde;
	bool isPlaying;
};

#endif
