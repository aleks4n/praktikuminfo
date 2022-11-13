/*
 * Fahrrad.cpp
 *
 *  Created on: 08.11.2022
 *      Author: aliihsangungoren
 */

#include "Fahrrad.h"

Fahrrad::Fahrrad() {
	// TODO Auto-generated constructor stub

}

Fahrrad::~Fahrrad() {
	// TODO Auto-generated destructor stub
}


double Fahrrad::dTanken(double dMenge){


    return 0;
}

double Fahrrad::dTanken(){

	return 0;


}

double Fahrrad::dGeschwindigkeit(){

		double zwischenstrecke = p_dGesamtStrecke;
		if(zwischenstrecke>=20 && p_dMaxGeschwindigkeit<=12){
			for(int i=0; i<zwischenstrecke/20; i++){
			p_dMaxGeschwindigkeit=9*p_dMaxGeschwindigkeit/10;
			}
			zwischenstrecke=0;
			}
	return p_dMaxGeschwindigkeit;
}

void Fahrrad::vSimulieren(){
 /*   while(true){
  	   dGlobaleZeit +=1.0;


  	   if(std::fmod(dGlobaleZeit,90000000.0)==0){
  	       	  p_dGesamtStrecke +=
  	       			  p_dMaxGeschwindigkeit/2 ;
  	       	  Uhr += 0.50;
              dGeschwindigkeit();

  	       	  break;
  	         }

} */
}







