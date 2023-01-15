#include <iostream>

#include <memory>
#include <vector>
#include <cstdio>
#include <ctime>


#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "Simulationsobjekt.h"
#include "Weg.h"
#include "Tempolimit.h"
#include "SimuClient.h"



//Unsere Globale Variablen
using namespace std;
double processingtime = 0.0;
double dGlobaleZeit = 0.0;
string seperator= "------------------------------------"
   			  "-----------------------------------------------------------------------\n";
double zeittakt = 0.3;
int space = 20;

bool isEqual(double a, double b)
{if(abs(a-b)<0.001){return true;}
else{return false;}}




//Testaufgabe fur die Konstruktoren und Destruktoren
void vAufgabe(){

    Fahrzeug* a = new Fahrzeug("a",4);
    Fahrzeug f("b",2);
    delete a;
    std::unique_ptr<Fahrzeug> uniquecar1 = std::make_unique<Fahrzeug>("car1",3);
    std::unique_ptr<Fahrzeug> uniquecar2 = std::make_unique<Fahrzeug>("car2",10);
    std::shared_ptr<Fahrzeug> sharedcar1 = std::make_shared<Fahrzeug>("car3",20);
    std::shared_ptr<Fahrzeug> sharedcar2 = std::make_shared<Fahrzeug>("car4",30);

    std::vector<std::unique_ptr<Fahrzeug>> uniquevector;

  uniquevector.push_back(std::move(uniquecar1));
  uniquevector.push_back(std::move(uniquecar2));

  uniquevector.clear();


  std::vector<std::shared_ptr<Fahrzeug>> sharedvector;
  sharedvector = {sharedcar1};
  sharedvector.push_back(std::move(sharedcar2));

  std::cout<<"Vector Size: "<<sharedvector.size()<<"\n";

}




//Basis Aufgabe
void vAufgabe_1a(){
	std::unique_ptr<Fahrzeug>  aufgabecar1 =
				std::make_unique<Fahrzeug>("Mercedes",19);

	std::unique_ptr<Fahrzeug>  aufgabecar2 =
			std::make_unique<Fahrzeug>("BMW",4);

	std::unique_ptr<Fahrzeug>  aufgabecar3 =
			std::make_unique<Fahrzeug>("Porsche",5);


	 std::vector<std::unique_ptr<Fahrzeug>> aufgabevector;


     aufgabevector.push_back(move(aufgabecar1));
     aufgabevector.push_back(move(aufgabecar2));
     aufgabevector.push_back(move(aufgabecar3));
    aufgabevector[0]->vKopf();
	while(true){

        //vAusgeben ist verandert deswegen ist diese Zeile auch rausgelassen
		aufgabevector[0]->vAusgeben(cout);
		cout<<"\n";
		aufgabevector[0]->vSimulieren();
	}



}

//Tanken Funktion und Geschwindigkeit Funktion, Unterklassen
void vAufgabe_2(){

     int pkwnummer = 0;
     int fahrradnummer = 0;
     double simulationdauer;
	cout<<"Fuer wie viele Stunden soll die Simulation laufen?: ;"<<endl;
	cin>>simulationdauer;

   cout<<"Nummer von PKWs: ";
   cin>>pkwnummer;
   cout<<endl;
   cout<<"Nummer von Fahrradern;   ";
   cin>>fahrradnummer;




	vector<unique_ptr<Fahrzeug>> aufgabe2vector;


	for(int i=0; i<pkwnummer; i++){
		 unique_ptr<PKW> pkws(new PKW("Auto" + to_string(i), 100, 30, 120 ));
		 aufgabe2vector.push_back(move(pkws));
	 }

	for(int i=0; i<fahrradnummer; i++){
			 unique_ptr<Fahrrad> fahrrad(new Fahrrad("Fahrrad" + to_string(i), 40 ));
			 aufgabe2vector.push_back(move(fahrrad));
		 }







     cout<<"Anzahl von Fahrzeugen:   "<<aufgabe2vector.size()<<"\n";

     aufgabe2vector[0]->vKopf();
   for(dGlobaleZeit=0; dGlobaleZeit<simulationdauer; dGlobaleZeit+=zeittakt){
    	for(int i=0; i<aufgabe2vector.size(); i++){
    		aufgabe2vector[i]->vSimulieren();
    		aufgabe2vector[i]->vAusgeben(cout);


    		if (fabs(dGlobaleZeit - 3.0) < zeittakt/2)
    		           {
    		               aufgabe2vector[i]->dTanken();
    		           }



    cout<<endl;
    	}

    }





}


void vAufgabe_AB1() {

   int l = 0; // Laufindex für gezielte AUsgabe
   vector<int> ausgabe{15};
   double dTakt = 0.3;

   std::vector<unique_ptr<Fahrzeug>> vecFahrzeuge;
   vecFahrzeuge.push_back(make_unique <PKW>("Audi", 217, 10.7));
   vecFahrzeuge.push_back(make_unique <Fahrrad>("BMX", 21.4));
   PKW bils("Audi",217,10.7);
   cout<<bils.p_dTankvolumen<<"\n";
   for(dGlobaleZeit = 0; dGlobaleZeit < 6; dGlobaleZeit += dTakt)
   {
       auto itL = find(ausgabe.begin(), ausgabe.end(), l);
       if (itL != ausgabe.end()) {
           std::cout << std::endl << l <<  " Globalezeit = " << dGlobaleZeit << std::endl;
           Fahrzeug::vKopf();
       }

       for (int i = 0; i < (int) vecFahrzeuge.size(); i++)
       {
           vecFahrzeuge[i]->vSimulieren();

           if (fabs(dGlobaleZeit - 3.0) < dTakt/2)
           {
               vecFahrzeuge[i]->dTanken();
           }
           if (itL != ausgabe.end()) {
               std::cout << *vecFahrzeuge[i] << endl;
           }
       }
       l++;
   }
   char c;
   std::cin >> c;
}






//Uberladene Funktionen
void vAufgabe_3(){
	PKW teslatruck("Tesla Truck",100,30,120);
	PKW mercedestruck("Mercedes Truck",120,30,120);

      teslatruck.vKopf();


		for(int i=0; i<2; i++){
			 teslatruck.vSimulieren();
			 mercedestruck.vSimulieren();

			 cout<<teslatruck;
			 	  cout<<endl;
			 	  cout<<mercedestruck;
			 	  cout<<endl;
		}
       bool x =  teslatruck<(mercedestruck);
       cout<< "Ergebnis:   " << x<<"\n";
       mercedestruck=(teslatruck);

       cout<<"Final Mercedes Truck:"<<mercedestruck;
       cout<<endl;


}


void vAufgabe4()
{Weg weg("weg",50);
weg.vKopf();
std::cout<<weg;}


void vAufgabe5()
{
	PKW teslatruck("Tesla Truck",100,30,120);
	cout<<"jo\n";
     cout<<dGlobaleZeit<<"\n";

	Weg weg("weg",500);

	unique_ptr<Fahrzeug> aufgabecar(new Fahrzeug("Mercedes", 90));
	//unique_ptr<Fahrzeug> aufgabecar2(new Fahrzeug("BMW", 95));

std::unique_ptr<Fahrzeug>  aufgabecar1 =
std::make_unique<Fahrzeug>("Mercedes",90);
std::unique_ptr<Fahrzeug>  aufgabecar2 =
std::make_unique<Fahrzeug>("BMW",95);
weg.vAnnahme(aufgabecar1);
weg.vAnnahme(aufgabecar2);
weg.vKopf();
double dTakt = 0.5;
for(dGlobaleZeit = 0 ;dGlobaleZeit<3; dGlobaleZeit += zeittakt)
{
	weg.vSimulieren();}

cout<<"jo\n";
cout<<weg;
}



void vAufgabe6()
{

	PKW teslatruck("Tesla Truck",100,30,120);


 Weg weghin("Landstrassehin", 500, Tempolimit::Landstrasse);
 Weg wegzur("Landstrassezur" ,500 ,Tempolimit::Landstrasse);

 std::unique_ptr<Fahrzeug> MercedesTruck(new PKW("MercedesTruck",50,5));
 std::unique_ptr<Fahrzeug> VolvoTruck(new PKW("VolvoTruck",150,3));
 std::unique_ptr<Fahrzeug> ParkingTesla(new PKW("ParkingTesla",100,3));
 int koordinaten[] = {700,250,100,250};

 bInitialisiereGrafik(800, 500);
 bZeichneStrasse("weghin", "wegzur", 500, 4, koordinaten);
 weghin.vKopf();
 //weg1.vAnnahme(MercedesTruck);  //@suppress("Invalid arguments")
 //weg1.vAnnahme(VolvoTruck);
 weghin.vAnnahme(ParkingTesla, 1);

 //@suppress("Invalid arguments")

 for(dGlobaleZeit = 0 ;dGlobaleZeit<3; dGlobaleZeit += zeittakt)
 {
	cout<<dGlobaleZeit<<endl;
 	weghin.vSimulieren(); }


 cout<<weghin;}



int main(){
//vAufgabe();
//vAufgabe_1a();
//vAufgabe_2();
//vAufgabe_3();
//vAufgabe_AB1();
//vAufgabe4();
//vAufgabe5();
//vAufgabe6();







 //c.vKopf();
 //c.vAusgeben(cout);





    return 0;
	}







