/*
 * Weg.cpp
 *
 *  Created on: 20.12.2022
 *      Author: aliihsangungoren
 */
#include "Fahrzeug.h"
#include "Weg.h"
#include "Fahrausnahme.h"
#include "Simulationsobjekt.h"
#include <iomanip>

Weg::Weg(std::string new_p_sName, double new_p_dLaenge, const Tempolimit new_tempolimit)
:Simulationsobjekt(new_p_sName)
{p_dLaenge = new_p_dLaenge;
 p_eTemplimit = new_tempolimit;
p_dZeit = 0.0;}

Weg::Weg() {
	// TODO Auto-generated constructor stub

}

Weg::~Weg() {
	// TODO Auto-generated destructor stub
}

double Weg::getTempolimit() const
{return double(p_eTemplimit);}


void Weg::vSimulieren()
{for(auto const& i : p_pFahrzeuge){
	       try
			{
				i->vSimulieren();
			}
			catch (Fahrausnahme& ausnahme)
			{
				ausnahme.vBearbeiten();
			}

	//i->vSimulieren();
}
p_dZeit = dGlobaleZeit;

}

double Weg::getLaenge()
{return p_dLaenge;};

void Weg::vAusgeben(ostream& o) const{
	Simulationsobjekt::vAusgeben(o);

	o<<p_dLaenge<<setw(space)<<"(";

	for(auto const& i : p_pFahrzeuge){
		o<<i->p_sName<<" ";
	}

	o<<")";
}

void Weg::vAnnahme(unique_ptr<Fahrzeug>& Fahrzeug)
{   Fahrzeug->vNeueStrecke(*this);
	p_pFahrzeuge.push_back(move(Fahrzeug));
};


void Weg::vKopf()
{std::cout<<"ID"<<setw(space)<<"Name"<<setw(space)<<"Laenge"<<setw(space)<<"Fahrzeuge"<<"\n"
	<<seperator;}


void Weg::vAnnahme(unique_ptr<Fahrzeug>& Fahrzeug, double dStartzeit)
{
	Fahrzeug->vNeueStrecke(*this, dStartzeit);
	p_pFahrzeuge.push_front(move(Fahrzeug));
}




