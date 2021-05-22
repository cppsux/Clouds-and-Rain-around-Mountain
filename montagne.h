#pragma once
#include "../Vecteur2D/Vecteur2D.h" 
#include "../Dessinable/Dessinable.h"
#include <vector>


class montagne : protected dessinable {
protected:
	double x0;                // position x	centre
	double y0;                // position y centre
	double H;                 // hauteur 
	double sigma_x0;          // étalement x
	double sigma_y0;          // étalement y

public:
	montagne(double x , double y, double h, double sigma_x, double sigma_y);
	
	virtual void dessine_sur(Support_a_dessin& support) override
	{
		support.dessine(*this);
	}

	virtual double altitude(double x, double y) const =0;        // altitude à la position (x,y)
	friend std::ostream& operator<<(std::ostream& stream, montagne const& mont);
};

void TestMontagne();
void TestMontagne2();

class montagne_Gaussienne : public virtual montagne
{
public:
	montagne_Gaussienne(double x, double y, double h, double sigma_x, double sigma_y);
	
	virtual void dessine_sur(Support_a_dessin& support) override
	{
		support.dessine(*this);
	}

	virtual double altitude(double x, double y) const override;
	friend std::ostream& operator<<(std::ostream& stream, montagne_Gaussienne const& mont);
};

class chaine_de_montagne : public virtual montagne
{
protected:
	std::vector<montagne*> Chaine;
	virtual void dessine_sur(Support_a_dessin& support) override
	{
		support.dessine(*this);
	}
public:
	chaine_de_montagne(double x, double y, double h, double sigma_x, double sigma_y, std::vector<montagne*>);
	virtual double altitude(double x, double y) const override;
	
};