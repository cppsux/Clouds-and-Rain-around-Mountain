#include"../CubedAir/CubedAir.h"

CubedAir::CubedAir(double a, double b, double c, double z0, bool n, double tau) : v({ a,b,c }), z(z0), nuage(n), humidité(tau) {}

double CubedAir::enthalpie() {
	return physique::cte - physique::g * z - 1 / 2 * (v[0] * v[0]+ v[1] * v[1] + v[2] * v[2]);
}

double CubedAir::temp() {
	return 2 / 7 * enthalpie() * physique::M_airsec / physique::R;
}

double CubedAir::pression() {
	return physique::P_infty * pow(temp() / physique::T_infty, 7 / 2);
}

double CubedAir::p_eau() {
	return humidité / ((physique::M_airsec / physique::M_eau) + humidité) * pression();
}

double CubedAir::p_ros() {
	return physique::p_ref * exp(13.96 - 5208 / temp());
}

void CubedAir::set_etat() {
	if (p_eau() > p_ros()) nuage = true;
	else nuage = false;
}