#pragma once
#include "../Vecteur2D/Vecteur2D.h"

class Potentiel {
public:
	Vecteur2D Pot;
	Vecteur2D Lap;

	Potentiel(): Pot(), Lap() {};
};