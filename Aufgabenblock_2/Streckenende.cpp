/*
 * Streckenende.cpp
 *
 *  Created on: 06.01.2023
 *      Author: aliihsangungoren
 */

#include "Streckenende.h"
#include "Simulationsobjekt.h"
#include "Fahrzeug.h"
#include "Weg.h"

Streckenende::Streckenende(Fahrzeug& fahrzeug, Weg& weg):Fahrausnahme(fahrzeug, weg){
	// TODO Auto-generated constructor stub

}

Streckenende::~Streckenende() {
	// TODO Auto-generated destructor stub
}
void Streckenende::vBearbeiten()
{std::cout<<"Ausnahme Streckenende"<<speicherfahrzeug<<"\n"<<speicherweg<<"\n";}

