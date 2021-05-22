#include <iostream>
#include "../ChampPotentiels/ChampPotentiel.h"
#include <fstream>
#include "../Potentiel/Potentiel.h"
#include <iomanip>
#include"../Mont/montagne.h"
using namespace std;


void LaplacienTest()
{	
	montagne_Gaussienne mont(15, 5, 15, 5, 5);                 // y=y0-L_y/2
	ChampPotentiels champ(20, 20, 20, 20.0 / 29.0);

	champ.initialise(15.0, mont);    // initialise les valeurs des potentiels dans la boite	
	champ.CalculeLaplacien();

	champ.resolution(2.2621843e-5, 5000);
		
	fstream fich1;
	fich1.open("ChampPotentiels/testLaplacien.dat", ios::out);
	champ.affiche_All(fich1);

}
