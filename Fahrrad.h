/*
 * Fahrrad.h
 *
 *  Created on: 08.11.2022
 *      Author: aliihsangungoren
 */

#ifndef FAHRRAD_H_
#define FAHRRAD_H_

#include "Fahrzeug.h"

class Fahrrad: public Fahrzeug {
public:
	Fahrrad();
	virtual ~Fahrrad();


private:
	        double dTanken();
			double dTanken(double dMenge);
			double dGeschwindigkeit();
			void vSimulieren();
			double p_dGesamtStrecke;
            double p_dMaxGeschwindigkeit;

};

#endif /* FAHRRAD_H_ */
