/*
 * PKW.h
 *
 *  Created on: 08.11.2022
 *      Author: aliihsangungoren
 */

#ifndef PKW_H_
#define PKW_H_

#include "Fahrzeug.h"
using namespace std;

class PKW: public Fahrzeug{
public:
	PKW(int p_iID, string p_sName,
			double p_sdMaxGeschwindigkeit, double p_dVerbrauch,
			double p_dTankvolumen);
	virtual ~PKW();



private:

	    int p_iID;
	    string p_sName;
	    double p_dMaxGeschwindigkeit;


	    double p_dGesamtStrecke;
	    double p_dVerbrauch; //Liter 100Km
		double p_dTankvolumen;
		double p_dTankinhalt;
		double p_dGesamtverbrauch = (p_dGesamtStrecke*p_dVerbrauch)/100;

		double dTanken();
		double dTanken(double dMenge);
		void vSimulieren();
        double dGeschwindigkeit();
		void vAusgeben();
};

#endif /* PKW_H_ */
