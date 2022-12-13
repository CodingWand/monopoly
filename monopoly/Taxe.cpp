#include "Taxe.h"

Taxe::Taxe(std::string nom, int taxe) : Case(nom)
{
	prix = taxe;
}

void Taxe::getSuivant(Joueur& j)
{
	std::cout << j.getPseudo() << " paie une taxe de " << prix << " billets � la banque." << std::endl;
	j.changeSolde(-prix);
}
