/*
 * Verhalten.cpp
 *
 *  Created on: 30.12.2022
 *      Author: aliihsangungoren
 */

#include "Verhalten.h"
#include "Fahrzeug.h"
#include "Weg.h"


Verhalten::Verhalten(Weg& weg):speicherweg(weg)
{};

Verhalten::~Verhalten() {
	// TODO Auto-generated destructor stub
}


double Verhalten::getMaxGeschwindigkeit()
{return speicherweg.getTempolimit();}



double Verhalten::dStrecke(Fahrzeug& aFzg, double dZeitIntervall)
{

	//double d_gefahreneStrecke = aFzg.dGeschwindigkeit() * dZeitIntervall;
  // double letzteschritt = speicherweg.getLaenge()- aFzg.getdAbschnittStrecke();



return 0;

   // return min<double>(d_gefahreneStrecke,letzteschritt);




};

