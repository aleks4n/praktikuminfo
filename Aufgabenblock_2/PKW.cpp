/*
 * PKW.cpp
 *
 *  Created on: 08.11.2022
 *      Author: aliihsangungoren
 */

#include "PKW.h"
#include "Verhalten.h"



PKW::PKW(const string new_p_sName,
		const double new_p_dMaxGeschwindigkeit, const double new_p_dVerbrauch,
		const double new_p_dTankvolumen):Fahrzeug(new_p_sName, new_p_dMaxGeschwindigkeit)

		{
    p_dGesamtverbrauch = 0;
	p_dVerbrauch =new_p_dVerbrauch;
	p_dTankvolumen= new_p_dTankvolumen;
    p_dTankinhalt = new_p_dTankvolumen/2;
    //p_dMaxGeschwindigkeit = new_p_dMaxGeschwindigkeit;

	cout
	        <<"PKW Created;"
			<<" Name;"<<p_sName
			<<" ID"<<p_iID
			<<" Verbrauch:"<<p_dVerbrauch
			<<" Tankvolume:"<<p_dTankvolumen
			<<"\n";
}
	// TODO Auto-generated constructor stub



PKW::~PKW() {
	// TODO Auto-generated destructor stub
	{cout<<"PKW Deleted:"
		<<" Name:"<<p_sName<<" ID:"<<p_iID<<"\n";}
}





double PKW::dTanken(double dMenge){
	int zwischenspeicher = p_dTankvolumen;
	if(p_dTankvolumen-p_dTankinhalt>=dMenge){
	p_dTankinhalt += dMenge;
    }
    else if(dMenge>p_dTankvolumen-p_dTankinhalt)
    {p_dTankinhalt=zwischenspeicher;}
    cout<<"\n"<<"PKW ist getankt mit L:   " <<dMenge<<"\n\n";
    return p_dTankinhalt;
}


//void PKW::vSimulieren(){
//
//double zwischenstrecke;
//
//
//
//  	       if(p_dTankinhalt > 0){
//  	    	 zwischenstrecke = p_dGesamtStrecke;
//  		      p_dGesamtStrecke +=  p_dMaxGeschwindigkeit/(1/zeittakt) ;
//  	       	  dGeschwindigkeit();
//  	       	  p_dTankinhalt -= ((p_dGesamtStrecke-zwischenstrecke)*p_dVerbrauch)/(100);
//  	       	  p_dGesamtverbrauch =(p_dGesamtStrecke*p_dVerbrauch)/100;
//
//  	       }
//
//  	        else if(p_dTankinhalt<=0){cout<<"\n"<<"Tank Inhalt ist null, kann nicht bewegen\n";
//  	          };
//
//}



void PKW::vAusgeben(ostream& o) const{

	Fahrzeug::vAusgeben(o);


		 o<<p_dGesamtverbrauch
		 <<setw(space)
		 <<p_dTankinhalt;
}


double PKW::dGeschwindigkeit() const{
	double realGeschwindigkeit = std::min(p_dMaxGeschwindigkeit, p_pVerhalten->getMaxGeschwindigkeit());
return realGeschwindigkeit;
}






