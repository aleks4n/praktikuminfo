/*
 * PKW.cpp
 *
 *  Created on: 08.11.2022
 *      Author: aliihsangungoren
 */

#include "PKW.h"



PKW::PKW(int new_p_iID, string new_p_sName,
		double new_p_dMaxGeschwindigkeit, double new_p_dVerbrauch,
		double new_p_dTankvolumen): p_iID(new_p_iID), p_sName(new_p_sName),
		p_dMaxGeschwindigkeit(new_p_dMaxGeschwindigkeit),
		p_dVerbrauch(new_p_dVerbrauch), p_dTankvolumen(new_p_dTankvolumen),
		p_dTankinhalt(new_p_dTankvolumen/2){
	// TODO Auto-generated constructor stub

}

PKW::~PKW() {
	// TODO Auto-generated destructor stub
}


double PKW::dTanken(double dMenge){
    if(p_dTankvolumen-p_dTankinhalt>=dMenge){
	p_dTankinhalt += dMenge;
    }
    else if(dMenge>p_dTankvolumen-p_dTankinhalt)
    {p_dTankinhalt=p_dTankvolumen;}

    return p_dTankinhalt;
}

double PKW::dTanken(){
	p_dTankinhalt=p_dTankvolumen;
	return p_dTankvolumen;
}


void PKW::vSimulieren(){
/*
	while(true){
	    	   dGlobaleZeit +=1.0;


	    	   if(std::fmod(dGlobaleZeit,90000000.0)==0){
	    	       	  p_dGesamtStrecke +=
	    	       			  p_dMaxGeschwindigkeit/2 ;
	    	       	  p_dTankinhalt-= ((p_dMaxGeschwindigkeit*p_dVerbrauch)/100)/2;
	    	       	  if(Uhr==3){
	    	       		  dTanken();
	    	       	  }

	    	       	  Uhr += 0.50;
	    	       	  break;
	    	         }
	}}
*/}

void PKW::vAusgeben(){
	 cout<<p_iID<<setw(space)<<p_sName<<setw(space)
					  <<p_dMaxGeschwindigkeit<<setw(space);
					 //<<p_dGesamtStrecke<<cout<<setw(space)<<p_dTankinhalt<<setw(space)<<p_dGesamtverbrauch;
}


double PKW::dGeschwindigkeit(){
	return p_dMaxGeschwindigkeit;
}






