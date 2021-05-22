#include <iostream>
#include"../Dessinable/Dessinable.h"
#include"../ChampPotentiels/ChampPotentiel.h"
#include"../Ciel/Ciel.h"
using namespace std;

class Systeme : dessinable {
protected:
	ChampPotentiels champ;
	Ciel ciel;
	montagne& mont;

public:
	Systeme(double a, double b, double c, double d, montagne& mont1);
	
	void deplacer_nuages(double dt);
	
	virtual void dessine_sur(Support_a_dessin& support) override
	{
		support.dessine(*this);
	}
	friend std::ostream& operator<<(std::ostream& stream, Systeme const& syst);
};