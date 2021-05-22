#pragma once
#include "../Potentiel/Potentiel.h"
#include "../Mont/montagne.h"
#include "../Constantes.h"

#include <vector>
#include<array>

using namespace std;

typedef vector<vector<vector<Potentiel>>> BoiteType;

class ChampPotentiels {
protected:
	vector <double> Length;
	BoiteType boite;

public:
	double pas;
	double* L_x;
	double* L_y;
	double* L_z;

	ChampPotentiels(double a, double b, double c, double d);   // constructeur qui initialise aussi la boite (size)
	void initialise(double v, montagne const& mont);                           // initialise les valeurs des potentiels dans la boite	
	void CalculeLaplacien();

	Vecteur2D getPotentiel(size_t i, size_t j, size_t k) const;
	Vecteur2D getLaplacien(size_t i, size_t j, size_t k) const;
	
	double erreur();
	void iteration();
	void resolution(double error, int max, bool verbal = false);
	
	array <double, 3> vitesse(int i, int j, int k) const;
	ostream& affiche_vitesse(int i, int j, int k, ostream& stream) const;


	friend void PotentielTest();

	void affiche_Potentiel(ostream& stream) const;
	void affiche_Laplacien(ostream& stream) const;
	void affiche_All(ostream& stream) const;
	friend std::ostream& operator<<(std::ostream& stream, ChampPotentiels const& champ);
};
void LaplacienTest();
void PotentielTest();
