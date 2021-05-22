#pragma once
#include <iostream>
#include"../Constantes.h"
#include <array>
using namespace std;



class CubedAir {
public:
	array <double, 3> v;
	double z;
	bool nuage;
	double humidité;

	CubedAir(double a, double b, double c, double z0, bool n, double tau = 0.008);

	double enthalpie();
	double temp();
	double pression();
	double p_eau();
	double p_ros();

	void set_etat();
};