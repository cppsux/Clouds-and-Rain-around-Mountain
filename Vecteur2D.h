#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <string>

class Vecteur2D {
private: 
	double x;
	double y;


public:
	Vecteur2D(double a, double b) : x(a), y(b) {};
	Vecteur2D() :x(0), y(0) {};
	
	void set_coord(double x1, double y1);          //fonctions de bases
	double get_x()const;
	double get_y()const;
	std::string affiche() const;
	bool compare(Vecteur2D Vect1);
	                
	
	//opérations de bases sur des vecteurs
	Vecteur2D operator-();

	
	double operator*(Vecteur2D v);               // Produit scalaire
	double norme();
	/* double norme2(); */                       // Produit scalaire v*v 

	Vecteur2D unitaire();
	friend std::ostream& operator<<(std::ostream& stream, Vecteur2D const& v) {
		stream << v.get_x() << " " << v.get_y() ;
		return stream;
	}
};


const Vecteur2D operator*(double q, Vecteur2D const& vect1);
const Vecteur2D operator+(Vecteur2D u, Vecteur2D const& v);
const Vecteur2D operator-(Vecteur2D u, Vecteur2D const& v);

