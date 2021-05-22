#include "ChampPotentiel.h"

ChampPotentiels::ChampPotentiels(double a, double b, double c, double d)
	: Length({ a,b,c }), L_x(&Length[0]), L_y(&Length[1]), L_z(&Length[2]), 
	boite(vector<vector<vector<Potentiel>>>(int(a/d)+2 , vector<vector<Potentiel>>(int(b/d)+2, vector<Potentiel>(int(c/d)+2)))), pas(d){}

void ChampPotentiels::initialise(double v, montagne const& mont) {

	for (size_t i(0); i < boite.size(); ++i) {
		for (size_t j(0); j < boite[i].size(); ++j) {
			for (size_t k(0); k < boite[i][j].size(); ++k) {
				
				if (i == 0 or i == 29 or j == 0 or j == 29) {
					boite[i][j][k].Pot.set_coord(-(v / 2.) * k * pas, (v / 2.0) * (j * pas - (*L_y / 2.)));
				}
				
				else if (k * pas > mont.altitude(i * pas, j * pas - (*L_y / 2.0)))
				{
					boite[i][j][k].Pot.set_coord(-(v / 2.) * k * pas, (v / 2.) * (j * pas - (*L_y / 2.)));
				}
				
				else if (k * pas <= mont.altitude(i * pas, (j * pas) - (*L_y / 2.0)))
				{
					boite[i][j][k].Pot.set_coord(0, 0);
				}

				}
			}

		}
	
	}


void ChampPotentiels::CalculeLaplacien()
{
	for (size_t i(0); i < boite.size() - 1; ++i) {
		for (size_t j(0); j < boite[i].size() - 1; ++j) {
			for (size_t k(0); k < boite[i][j].size() - 1; ++k) {
				
				if (not (i == 0 or j == 0 or k == 0 )) {          
					boite[i][j][k].Lap = boite[i - 1][j][k].Pot + boite[i][j - 1][k].Pot + boite[i][j][k - 1].Pot
						 - 6 * boite[i][j][k].Pot + boite[i + 1][j][k].Pot + boite[i][j + 1][k].Pot + boite[i][j][k + 1].Pot;      
				}
			}
		}
	}
}

Vecteur2D ChampPotentiels::getPotentiel(size_t i, size_t j, size_t k) const {
	
	if (i < boite.size() and j < boite[i].size() and boite[i][j].size())
	{
		return boite[i][j][k].Pot;
	}
	Vecteur2D temp;
	return temp;
}

Vecteur2D ChampPotentiels::getLaplacien(size_t i, size_t j, size_t k) const {
	if (i < boite.size() and j < boite[i].size() and boite[i][j].size())
	{
		return boite[i][j][k].Lap;
	}
	Vecteur2D temp;
	return temp;
}

double ChampPotentiels::erreur()
{
	double res(0);
	for (size_t i(0); i < boite.size(); ++i) {
		for (size_t j(0); j < boite[i].size(); ++j) {
			for (size_t k(0); k < boite[i][j].size(); ++k) {

				res += boite[i][j][k].Lap * boite[i][j][k].Lap;     // Produit scalaire = norme²
			}
		}
	}
	return res;
}

void ChampPotentiels::iteration()
{
	for (size_t i(0); i < boite.size(); ++i) {
		for (size_t j(0); j < boite[i].size(); ++j) {
			for (size_t k(0); k < boite[i][j].size(); ++k) {
				
				boite[i][j][k].Pot = boite[i][j][k].Pot + physique::epsilon * boite[i][j][k].Lap;
			}
		}
	}
}

void ChampPotentiels::resolution(double error, int max, bool verbal) 
{
	int i(0);
	while (i <= max and erreur() >= error) {
		iteration();
		cout << i << " " << erreur() << endl;
		
		if (verbal == true) {
			for (size_t i(0); i < boite.size(); ++i) {
				for (size_t j(0); j < boite[i].size(); ++j) {
					for (size_t k(0); k < boite[i][j].size(); ++k) {
						cout << i << " " << j << " " << k << " " << boite[i][j][k].Pot << " " << boite[i][j][k].Lap << endl;
					}
				}
			}
		}

		++i;
		CalculeLaplacien();
	}
}

array <double, 3> ChampPotentiels::vitesse(int i, int j, int k) const   //Vecteur3D
{
	double v1 = 1 / (2 * pas) * (boite[i][j + 1][k].Pot.get_y() - boite[i][j - 1][k].Pot.get_y() - boite[i][j][k + 1].Pot.get_x() + boite[i][j][k - 1].Pot.get_x());
	double v2 = 1 / (2 * pas) * (boite[i - 1][j][k].Pot.get_y() - boite[i + 1][j][k].Pot.get_y());
	double v3 = 1 / (2 * pas) * (boite[i + 1][j][k].Pot.get_x() - boite[i - 1][j][k].Pot.get_x());
	return { v1, v2, v3 };
} 

ostream& ChampPotentiels::affiche_vitesse(int i, int j, int k, ostream& stream) const
{
	stream << vitesse(i, j, k)[0] << " " << vitesse(i, j, k)[1] << " " << vitesse(i, j, k)[2];
	return stream;
}

void ChampPotentiels::affiche_Potentiel(ostream& stream) const
{
	for (size_t i(0); i < boite.size(); ++i) {
		for (size_t j(0); j < boite[i].size(); ++j) {
			for (size_t k(0); k < boite[i][j].size(); ++k) {

				if (i == 29 and j == 29 and k == 29)
					stream << i << " " << j << " " << k << " " << getPotentiel(i, j, k);
				else stream << i << " " << j << " " << k << " " << getPotentiel(i, j, k) << endl;
				stream << i << " " << j << " " << k << " "  << getLaplacien(i, j, k) << endl;

			}
		}
	}
}

void ChampPotentiels::affiche_Laplacien(ostream& stream) const
{
	for (size_t i(0); i < boite.size(); ++i) {
		for (size_t j(0); j < boite[i].size(); ++j) {
			for (size_t k(0); k < boite[i][j].size(); ++k) {
				stream << i << " " << j << " " << k << " " << getLaplacien(i, j, k) << endl;
			}
		}
	}
}

std::ostream& operator<<(std::ostream& stream, ChampPotentiels const& champ) 
{
	stream << "un champ de potentiels : " << endl;
	stream << "L_x = " << *champ.L_x << " L_y = " << *champ.L_y << " L_z = " << *champ.L_z << endl;
	stream << "lambda = " << champ.pas << endl;
	stream << "valeurs: " << endl;
	champ.affiche_Potentiel(stream);
	return stream;
}

void ChampPotentiels::affiche_All(ostream& stream) const
{
	for (size_t i(0); i < boite.size(); ++i) {
		for (size_t j(0); j < boite[i].size(); ++j) {
			for (size_t k(0); k < boite[i][j].size(); ++k) {
				stream << i << " " << j << " " << k << " " << getPotentiel(i, j, k) << " "; 
				affiche_vitesse(i, j, k, stream);
				stream << " " << vitesse(i, j, k)[0] * vitesse(i, j, k)[0] + vitesse(i, j, k)[1] * vitesse(i, j, k)[1] + vitesse(i, j, k)[2] * vitesse(i, j, k)[2] << endl;
			}
		}
	}
}