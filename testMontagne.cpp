#include <iostream>
#include <fstream>
#include "montagne.h"
using namespace std;

std::ostream& operator<<(std::ostream& stream, montagne const& mont)
{
	return stream;
}

void TestMontagne ()
{
	fstream fich;
	
	fich.open("Mont/mont1.dat", ios::out);
	montagne_Gaussienne mont(15, 15, 18, 5, 10);

	for (int i(0); i < 30; ++i) {
		
		for (int j(0); j < 30; ++j) {

			fich << i << " " << j << " " << mont.altitude(i, j) << endl;
		}
		
		fich << endl;
	}

}  

void TestMontagne2() {
	std::vector<montagne*> Ch = { new montagne_Gaussienne(2,22,12,12,3), new montagne_Gaussienne(20,2,15,8,4)};
	chaine_de_montagne Chaine(15.0, 15.0, 18.0, 5.0, 10.0, Ch);

	fstream fich;
	fich.open("Mont/TestMontagne2.dat", ios::out);
	montagne_Gaussienne mont(15, 15, 18, 5, 10);

	for (int i(0); i < 30; ++i) {

		for (int j(0); j < 30; ++j) {

			fich << i << " " << j << " " << Chaine.altitude(i, j) << endl;
		}

		fich << endl;
	}
}