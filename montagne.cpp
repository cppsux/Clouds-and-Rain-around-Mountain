	#include <iostream>
#include"montagne.h"
#include <cmath>

montagne::montagne (double x, double y, double h, double sigma_x, double sigma_y) : x0(x), y0(y), H(h), sigma_x0(sigma_x), sigma_y0(sigma_y) {}

montagne_Gaussienne::montagne_Gaussienne(double x, double y, double h, double sigma_x, double sigma_y) : montagne(x, y, h, sigma_x, sigma_y) {}

double montagne_Gaussienne::altitude(double x, double y) const {

	double res = H * exp(-((x - x0) * (x - x0) / (2 * sigma_x0 * sigma_x0)) - ((y - y0) * (y - y0) / (2 * sigma_y0 * sigma_y0)));
	if (res < 0.5) res = 0;

	return res;
}

std::ostream& operator<<(std::ostream& stream, montagne_Gaussienne const& mont)
{
	stream << "une montagne:" << std::endl;
	stream << "gaussienne de paramètres : " << std::endl;
	stream << "i0 = " << mont.x0 << std::endl;
	stream << "j0 = " << mont.y0 << std::endl;
	stream << "H = " << mont.H << std::endl;
	stream << "Si0 " << mont.sigma_x0 << std::endl;
	stream << "Sj0 " << mont.sigma_y0 << std::endl;
	return stream;
}

chaine_de_montagne::chaine_de_montagne(double x, double y, double h, double sigma_x, double sigma_y, std::vector<montagne*> Ch) 
	: montagne(x,y,h,sigma_x,sigma_y), Chaine(Ch) {}

double chaine_de_montagne::altitude(double x, double y) const {
	double max(0);

	for (auto& value : Chaine) {
		if (value->altitude(x, y) > max) max = value->altitude(x, y);
	}
	if (H * exp(-((x - x0) * (x - x0) / (2 * sigma_x0 * sigma_x0)) - ((y - y0) * (y - y0) / (2 * sigma_y0 * sigma_y0))) > max) 
		max = H * exp(-((x - x0) * (x - x0) / (2 * sigma_x0 * sigma_x0)) - ((y - y0) * (y - y0) / (2 * sigma_y0 * sigma_y0)));
	return max;
}

