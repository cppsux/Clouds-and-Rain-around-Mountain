#include"systeme.h"

std::ostream& operator<<(std::ostream& stream, Systeme const& syst) {
	cout << "Le système est constitué de :" << endl;
	cout << syst.mont;
	cout << syst.champ;
	return stream;
}

Systeme::Systeme(double a, double b, double c, double d, montagne& mont1) : champ(a, b, c, d), ciel(champ), mont(mont1) {}

void Systeme::deplacer_nuages(double dt)
{
	for (size_t i(0); i < ciel.boite.size(); ++i) {
		for (size_t j(0); j < ciel.boite[i].size(); ++j) {
			for (size_t k(0); k < ciel.boite[i][j].size(); ++k) {
				
				if (ciel.boite[i][j][k].nuage and not ciel.precedente(dt, i, j, k)->nuage) 
					ciel.boite[i][j][k].humidité *= 98.3/100;       //diminue 1.3%
				if (not ciel.boite[i][j][k].nuage and ciel.precedente(dt, i, j, k)->nuage) 
					ciel.boite[i][j][k].humidité *= 105 / 100;      //augmente 5%

			}
		}
	}
}


