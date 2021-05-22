#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "../CubedAir/CubedAir.h"
#include "../ChampPotentiels/ChampPotentiel.h"
using namespace std;

typedef vector<vector<vector<CubedAir>>> BoiteType2;


class Ciel {
protected:
	vector <double> Length;

public:
	double* L_x;
	double* L_y;
	double* L_z;
	double lambda;
	BoiteType2 boite;

	Ciel(ChampPotentiels champ);
	Ciel(double a, double b, double c, double d, double e);
	friend void CielTest();

	CubedAir* precedente(double dt, int i, int j, int k);
};
