#include "Jeu.h"
#include "malloc.h"

Jeu::Jeu(std::string config) : board()
{
	joueurs = NULL;
	nbJoueurs = 0;

	std::cout << "Combien de joueurs �tes-vous ?";
	std::cin >> nbJoueurs;

	if (nbJoueurs <= 1) {
		cout << "D�sol�, le Monopoly se joue au moins � deux..." << endl;
		return;
	}

	joueurs = new Joueur[nbJoueurs];
	
	int startingMoney = 2 * 500 + 4 * 100 + 50 + 20 + 10 + 5 + 1;

	for (int i = 0; i < nbJoueurs; i++)
	{
		std::cin >> joueurs[i];
		std::cout << std::endl;

		joueurs[i].changeSolde(startingMoney);
		joueurs[i].setPosition(0);

		std::cout << joueurs[i] << std::endl;
	}
}

int Jeu::getNbrJoueursEnJeu()
{
	if (nbJoueurs < 2) return 0;

	int enJeu = 0;

	for (int i = 0; i < nbJoueurs; i++)
	{
		enJeu += (joueurs[i].isStillPlaying()) ? 1 : 0;
	}
	
	return enJeu;
}

void Jeu::lancerPartie()
{
	if (nbJoueurs < 2)
	{
		std::cout << "Il n'y a pas assez de joueurs pour commencer une partie..." << std::endl;
		return;
	}

	std::cout << "La partie commence, bon courage � tous !" << std::endl;
	std::cout << "Chacun va jeter les d�s, celui qui aura le score le plus �lev� commencera la partie." << std::endl;

	//Lancer les d�s
	//Le joueur qui a le max commence son index est first
	int first = 0;
	
	int player = first;
	while (getNbrJoueursEnJeu() > 1)
	{
		jouerTour(player);
		player = joueurSuivant(player);
	}
}

void Jeu::terminerPartie()
{
	if (getNbrJoueursEnJeu() > 1) return;
	//Faire l'annonce du gagnant
}

int Jeu::joueurSuivant(int actual)
{
	if (nbJoueurs < 2) return 0;
	int next = actual + 1;
	while (!joueurs[next].isStillPlaying()) {
		next += 1;
		next = next % nbJoueurs;
	}
	return next;
}

void Jeu::jouerTour(int index)
{
	Joueur* player = &joueurs[index];
	
	std::cout << "C'est au tour de " << player->getPseudo() << " !" << std::endl;

	//G�rer le cas prison

	//Lancer les d�s
	int nbPas = 6;
	/*
	Bougez votre pion d�autant de cases que le nombre de points indiqu� sur les d�s et
	dans le sens des aiguilles d�une montre.
	La case o� vous vous arr�terez d�terminera ce que vous avez � faire.
	*/

	board.deplacer(player, nbPas);

	/*
	Si vous passez par ou vous arr�tez sur la case D�PART, vous recevez M200 de la Banque.
	*/

	/*
	Si vous faites un double aux d�s, effectuez les op�rations habituelles sur la case o� vous vous arr�tez
	puis relancez les d�s(�tapes 1 � 4).
	Attention !Si vous faites trois doubles de suite, rendez - vous imm�diatement en prison.
	*/
	board[player->getPosition()]->arriverSur(*player);
	/*
	Lorsque vous avez termin� votre tour, donnez les d�s au joueur situ� sur votre gauche.
	*/
}
