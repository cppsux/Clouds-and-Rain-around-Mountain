#include <iostream>
#include "ChampPotentiel.h"
#include <fstream>
#include <iomanip>
#include "../Potentiel/Potentiel.h"

using namespace std;

void PotentielTest()
{
	montagne_Gaussienne mont(15 * 20 / 29., 15 * 20 / 29. - 10, 15 * 20 / 29., 5 * 20 / 29., 5 * 20 / 29.);                  // y=y0-L_y/2
	ChampPotentiels champ(20, 20, 20, 20.0 / 29.0);

	fstream fich1;
	fstream fich2;
	fich1.open("ChampPotentiels/testPotentiel1.dat", ios::out);
	fich2.open("ChampPotentiels/testPotentiel2.dat", ios::out);

	champ.initialise(20.0, mont);    // initialise les valeurs des potentiels dans la boite	
	champ.CalculeLaplacien();

	champ.affiche_Potentiel(fich1);
	champ.affiche_Laplacien(fich2);

}