//Program to determine costs of running ELISA testing.
//Author: Janice Love
//Date: October 15, 2014
//Update: April 29, 2015

#include <fstream>
#include <iostream>
#include <iomanip> 
#include <string>
#include "functions.h"

using namespace std; 

//variables
double plates = 173; //from Charles River online catalogue 


//Reagents

double sodiumChloride;
double sodiumHydroxide;
double haBuffer;
double tween;
double dryMilk;
double antifoamA;
double hydrogenPeroxide30;
double citricAcid;
double ABTS;

//Equipment 
double plateReader;
double plateWasher;
double incubator;
double electronicPipette;
double phMeter;

//Other supplies
double virusPlates;
double finnTips;

//MISC
int samples_per_plate = 48; 
int shortPanel = 6;
int Qpanel = 17; 




int main ()
{
	ofstream myFile;
	myFile.open("serologyPrices.txt");

//plates 
	double short6_panel = plates * 6; //plate cost per run
	double short7_panel = plates * 7; //plate cost per run 
	double quarantine_plate = plates * 17; //plate cost per run 


//*********************************************************************
	double a = posCONTROL();
	double b = fetalBovineSerum();
	double nacl = sodiumChloride();
	double naoh = sodiumHydroxide();
	double ha = haBuffer();
	double t = tween ();
	double milk = dryMilk();
	double foam = antiFoam();
	double peroxide = hPeroxide();
	double acid = citricAcid();
	double ABTS = abts();
	double reader = plateReader ();
	double washer = plateWasher ();
	double incubate = incubator ();
	double pipette = ePipette();
	double ph_meter = phMeter();
	double tips_fisher = tips();
	double labor_short = tech_time_short();
	double laborQ = tech_time_Q ();	  
//*********************************************************************
	
	 
	 double cost_basic =  nacl  + naoh
		  + ha  + t + milk  + foam 
		  + peroxide  + acid  + ABTS; //cost per run

	 double cost_equipment = reader  + washer + incubate 
		  + pipette + ph_meter; //cost per run

	double cost_short = cost_basic + short6_plate + tips_fisher
		 + a + b  + labor_short + cost_equipment; //cost per run

	 double cost_short7 = cost_basic + short7_plate + tips_fisher
		 + a + b + labor_short + cost_equipment; //cost per run
		  
	 double cost_long = cost_basic + quarantine_plate + tips_fisher
		 + a + b + laborQ + cost_equipment; //cost per run 

	 double half_short6 = cost_short / 24;
	 double half_short7 = cost_short7 / 24;
	 double half_quarantine = cost_long / 24;
	 
	 double full_short6 = cost_short / 48; 
	 double full_short7 = cost_short7 /48;
	 double full_quarantine = cost_long / 48;

	  myFile << setprecision(4);
	  myFile << "The cost of a short panel (6 plates) is: $ " << cost_short << endl;
	  
	  myFile << "The cost of a short panel (7 plates) is: $ " << cost_short7 << endl;
	  myFile << "The cost of a quarantine panel is: $ " << cost_long << endl; 
	  myFile << endl;
	  myFile << "Short Panel (6 plates) cost (half plate) is: $ " << half_short6 
		  << endl;
	  myFile << "Short panel (7 plates) cost (half plate) is: $ " << half_short7
		  << endl;
	  myFile << "Quarantine Panel cost (half plate) is: $ " << half_quarantine
		  << endl; 
	  myFile << endl;

	  myFile << "Short panel (6 plates) cost (full plate) is: $ " << full_short6 << endl;
	
	  myFile << "Short panel (7 plates) cost (full plate) is: $ " << full_short7
		  << endl;
	  myFile << "Quarantine Panel cost (full plate) is: $ " << full_quarantine
		  << endl; 
	  myFile << endl;



	 	  	  
	return 0;
}