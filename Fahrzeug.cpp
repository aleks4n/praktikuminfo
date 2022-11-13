/*
 * Fahrzeug.cpp
 *
 *  Created on: 30.10.2022
 *      Author: aliihsangungoren
 */
#include <iomanip>
#include "Fahrzeug.h"
using namespace std;
double dGlobaleZeit = 0.0;
double Uhr = 0.0;
int space = 20;

Fahrzeug::Fahrzeug(std::string new_p_sName, int new_p_iID)
:p_sName(new_p_sName), p_iID(new_p_iID){std::cout<<"Object created:"
	<<" Name:"<<p_sName<<" ID:"<<p_iID<<"\n";}
Fahrzeug::Fahrzeug(){

	std::cout<<"New Pointer Created\n";
}

Fahrzeug::~Fahrzeug()
{std::cout<<"Deleted:"
	<<" Name:"<<p_sName<<" ID:"<<p_iID<<"\n";}



Fahrzeug::Fahrzeug(std::string newname, double newspeed){



	newname = p_sName;
	newspeed = (newspeed>0) ? p_dMaxGeschwindigkeit : 0;

}



Fahrzeug::Fahrzeug(std::string new_p_sName,
		int new_p_iID, double new_p_dMaxGeschwindigkeit)
:p_sName(new_p_sName), p_iID(new_p_iID), p_dMaxGeschwindigkeit(new_p_dMaxGeschwindigkeit){std::cout<<"Object created:"
	<<" Name:"<<p_sName<<" ID:"<<p_iID<<"\n";}

void Fahrzeug::vKopf(){
  cout<<"ID"<<setw(space)<<"Name"<<setw(space)
		  <<"MaxGeschwindigkeit"<<setw(space)
		  <<"Gesamtstrecke\n";
  cout<<seperator;
}
int Fahrzeug::idgetter(){
	return p_iID;
}
void Fahrzeug::vAusgeben(ostream& o){


	  o<<p_iID<<setw(space)<<p_sName<<setw(space)
				  <<p_dMaxGeschwindigkeit<<setw(space)
				 <<p_dGesamtStrecke;
	   }

void Fahrzeug::vSimulieren(){
      while(true){
    	   dGlobaleZeit +=1.0;


    	   if(std::fmod(dGlobaleZeit,90000000.0)==0){
    	       	  p_dGesamtStrecke +=
    	       			  p_dMaxGeschwindigkeit/2 ;
    	       	  Uhr += 0.50;


    	       	  break;
    	         }


      }








}

double Fahrzeug::dGeschwindigkeit(){return 0;};


