#include "Vecteur2D.h"
using namespace std;

double const precision = pow(10, -10);


void Vecteur2D::set_coord(double x1, double y1) {
	x = x1; y = y1;
}

double Vecteur2D::get_x() const
{
	return x;
}

double Vecteur2D::get_y() const
{
	return y;
}


std::string Vecteur2D::affiche() const {
	// std::cout << "(" << x << " " << y << ")" << endl;
	return std::to_string(x) + " " + std::to_string(y);
}

bool Vecteur2D::compare(Vecteur2D Vect1) {
	if ((abs(x - Vect1.x) <= precision) and (abs(y - Vect1.y) <= precision)) return true;
	else return false;
}

const Vecteur2D operator+(Vecteur2D u, Vecteur2D const& v)
{
	Vecteur2D res(u.get_x() + v.get_x(), u.get_y() + v.get_y());
	return res;
}

Vecteur2D Vecteur2D::operator-() {
	Vecteur2D oppose;
	oppose.set_coord(-x, -y);
	return oppose;
}

const Vecteur2D operator-(Vecteur2D u, Vecteur2D const& v)
{
	Vecteur2D res(u.get_x() - v.get_x(), u.get_y() - v.get_y());
	return res;
}


const Vecteur2D operator*(double q, Vecteur2D const& vect1)
{
	Vecteur2D res(q * vect1.get_x(), q * vect1.get_y());
	return res;
}

double Vecteur2D::operator*(Vecteur2D v)
{
	return x * v.x + y * v.y;
}



double Vecteur2D::norme() {
	return sqrt(x * x + y * y);
}

/* double Vecteur2D::norme2() {
	return norme() * norme();           Produit scalaire v*v
} */

Vecteur2D Vecteur2D::unitaire() {
	Vecteur2D res;
	res.x = x / norme();
	res.y = y / norme();
	return res;
}

/*
std::ostream& operator<<(std::ostream& stream, Vecteur2D& const v) {
	//v.affiche(); 
	//stream << v.affiche() << endl;
	return stream;
}
*/

