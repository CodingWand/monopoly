#include "Prison.h"

using namespace std;

Prison::Prison(std::string name) : Case(name)
{
}

void Prison::getSuivant(Joueur& joueur)
{
	cout << joueur.getPseudo() << " est en prison depuis " << joueur.getTempsPrison() + 1 << "tour(s)." << endl;
	//Payer une amande de 50 balles et sortir
	cout << "Veux-tu payer une amende de 50 billets et sortir ?" << endl;
	//Ou utiliser une carte "lib�r� de prison" puis relancer les d�s
	cout << "Veux-tu utiliser une carte lib�r� de prison ? Si tu n'en as pas tu peux en acheter � quelqu'un" << endl;
	//Ou faire un double et sortir de prison en faisant un lanc� de d�s pour avancer
	if (joueur.howManyDoubles() > 0 && joueur.howManyDoubles() < 3) {
		joueur.changeSolde(-50);
		joueur.setTempsPrison(-1); //Doing this tells that the time in prison is over
		//The player stays in prison but can get out during his next turn.
		cout << joueur.getPseudo() << " peut sortir de prison !" << endl;
	}
	//Ou apr�s 3 tours de prison, payer 50 euros � la banque et sortir
	if (joueur.getTempsPrison() <= 3)
	{
		cout << joueur.getPseudo() << " paie 50 billets � la banque et sort de prison." << endl;
		joueur.changeSolde(-50)
	}
}
