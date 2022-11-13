#include <iostream>
#include "Fahrzeug.h"
#include <memory>
#include <vector>
#include <cstdio>
#include <ctime>



std::clock_t start;
using namespace std;

void vAufgabe(){

    Fahrzeug* a = new Fahrzeug("a",4);
	static Fahrzeug f("a",2);
    delete a;
    std::unique_ptr<Fahrzeug> uniquecar1 = std::make_unique<Fahrzeug>("name",3,3);
    std::unique_ptr<Fahrzeug> uniquecar2 = std::make_unique<Fahrzeug>();
    std::shared_ptr<Fahrzeug> sharedcar1 = std::make_shared<Fahrzeug>();
    std::shared_ptr<Fahrzeug> sharedcar2 = std::make_shared<Fahrzeug>();

    std::vector<std::unique_ptr<Fahrzeug>> uniquevector;

  uniquevector.push_back(std::move(uniquecar1));
  uniquevector.push_back(std::move(uniquecar2));

  uniquevector.clear();


  std::vector<std::shared_ptr<Fahrzeug>> sharedvector;
  sharedvector = {sharedcar1};
  sharedvector.push_back(std::move(sharedcar1));

  std::cout<<sharedvector.size();

}




//Basis Aufgabe
void vAufgabe_1a(){
	std::unique_ptr<Fahrzeug>  aufgabecar1 =
				std::make_unique<Fahrzeug>("Mercedes",19,10);

	std::unique_ptr<Fahrzeug>  aufgabecar2 =
			std::make_unique<Fahrzeug>("b",4,4);

	std::unique_ptr<Fahrzeug>  aufgabecar3 =
			std::make_unique<Fahrzeug>("c",5,5);


	 std::vector<std::unique_ptr<Fahrzeug>> aufgabevector;


     aufgabevector.push_back(move(aufgabecar1));
     aufgabevector.push_back(move(aufgabecar2));
     aufgabevector.push_back(move(aufgabecar3));
    aufgabevector[0]->vKopf();
	while(true){


		//aufgabevector[0]->vAusgeben();
		aufgabevector[0]->vSimulieren();
	}



}

//Tanken Funktion und Geschwindigkeit Funktion, Unterklassen
void vAufgabe_2(){
	unique_ptr<Fahrzeug> Fahrrad1 = make_unique<Fahrzeug>("BMX",31,45);
	unique_ptr<Fahrzeug> PKW = make_unique<Fahrzeug>("Tesla Truck",903,100);
	vector<unique_ptr<Fahrzeug>> aufgabe2vector;
	aufgabe2vector.push_back(move(Fahrrad1));
	aufgabe2vector.push_back(move(PKW));
}

//Uberladene Funktionen
void vAufgabe_3(){}

int main(){
    //vAufgabe();




    return 0;
	}







