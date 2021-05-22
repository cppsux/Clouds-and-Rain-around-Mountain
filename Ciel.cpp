#include "Ciel.h"

Ciel::Ciel(ChampPotentiels champ) : Length({ *champ.L_x,*champ.L_y,*champ.L_z }), L_x(&Length[0]), L_y(&Length[1]), L_z(&Length[2]), lambda(champ.pas)
	{
		for (size_t i(0); i < boite.size(); ++i) {
			for (size_t j(0); j < boite[i].size(); ++j) {
				for (size_t k(0); k < boite[i][j].size(); ++k) {
					boite[i][j][k].v = champ.vitesse(i, j, k);
				}
			}
		}
	};

Ciel::Ciel(double a, double b, double c, double d, double e) : Length({ a, b, c }), L_x(&Length[0]), L_y(&Length[1]), L_z(&Length[2]), lambda(d) 
{
	for (size_t i(0); i < boite.size(); ++i) {
		for (size_t j(0); j < boite[i].size(); ++j) {
			for (size_t k(0); k < boite[i][j].size(); ++k) {
				boite[i][j][k].v = { e, 0, 0 };
				boite[i][j][k].z = k * lambda;
				boite[i][k][k].set_etat();
			}
		}
	}
}

CubedAir* Ciel::precedente(double dt, int i, int j, int k)  //returns pointer to a CubedAir inside box, and not a new CubedAir (so we can modify it)
{
	int i0 = trunc(i - dt * boite[i][j][k].v[0] / lambda);
	int j0 = trunc(j - dt * boite[i][j][k].v[1] / lambda);
	int k0 = trunc(k - dt * boite[i][j][k].v[2] / lambda);
	
	if (i0 < boite.size() and j0 < boite[i0].size() and k0 < boite[i0][j0].size()) {
		CubedAir* res = & boite[i0][j0][k0];                    
		return res;
	}
	return new CubedAir(0,0,0, k0 * lambda, false);
}



	