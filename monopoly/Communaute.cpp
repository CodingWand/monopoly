#include "Communaute.h"

Communaute::Communaute(std::string nom) : Case(nom)
{
}

void Communaute::getSuivant(Joueur& joueur)
{
	std::cout << joueur.getPseudo() << " pioche une carte communaut�." << std::endl;
	//Le joueur pioche une carte;
}
