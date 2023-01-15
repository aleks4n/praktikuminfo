/*
 * Weg.h
 *
 *  Created on: 20.12.2022
 *      Author: aliihsangungoren
 */

#ifndef WEG_H_
#define WEG_H_

#include "Simulationsobjekt.h"
#include <list>
class Fahrzeug;
class Simulationsobjekt;
#include "Tempolimit.h"

class Weg: public Simulationsobjekt {
public:
	Weg();
	Weg(std::string p_sName, double p_dLaenge, const Tempolimit tempolimit = Tempolimit::Autobahn);
	virtual ~Weg();
	void vKopf();
	void vAnnahme(unique_ptr<Fahrzeug>& Fahrzeug);
	void vAnnahme(unique_ptr<Fahrzeug>& Fahrzeug, double Startzeit);
	double getLaenge();
	void vSimulieren();
	double getTempolimit() const;
	std::list<unique_ptr<Fahrzeug>> p_pFahrzeuge;
private:

	    double p_dLaenge;
		Tempolimit p_eTemplimit;
	   // std::list<unique_ptr<Fahrzeug>> p_pFahrzeuge;
	    void vAusgeben(ostream& o) const;



};

#endif /* WEG_H_ */
