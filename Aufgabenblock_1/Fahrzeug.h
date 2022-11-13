/*
 * Fahrzeug.h
 *
 *  Created on: 30.10.2022
 *      Author: aliihsangungoren
 */


#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
extern double dGlobaleZeit;
extern double Uhr;
extern int space;
class Fahrzeug {

private:
	string p_sName = "";
	int p_iID ;
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;
	double p_dZeit;

	  string seperator = "------------------------------------"
			  "------------------------\n";



public:
	Fahrzeug();
	Fahrzeug(std::string p_sName, int p_iID);
	Fahrzeug(std::string p_sName, double p_dMaxGeschwindigkeit);
	Fahrzeug(std::string p_sName, int p_iID, double p_dMaxGeschwindigkeit);


    virtual ~Fahrzeug();

    Fahrzeug(Fahrzeug const&) = delete;
    void vAusgeben(ostream& o);
    void vKopf();
    void vSimulieren();
    int idgetter();
    double dTanken();
    double dTanken(double dMenge);
    virtual double dGeschwindigkeit();
    bool operator <(Fahrzeug& vergleichfahrzeug)
    {return p_dGesamtStrecke< vergleichfahrzeug.p_dGesamtStrecke ;};
    void operator =(Fahrzeug& copyfahrzeug)
        {this->p_sName = copyfahrzeug.p_sName;
        this->p_iID = copyfahrzeug.p_iID;
        this->p_dMaxGeschwindigkeit = copyfahrzeug.p_dMaxGeschwindigkeit;};





};
//Const problem here
static void operator<<(ostream& o,  Fahrzeug& Fahrzeug)
{   Fahrzeug.vAusgeben(o);

			;}







