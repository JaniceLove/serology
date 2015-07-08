//Program to determine costs of running ELISA testing.
//Author: Janice Love
//Date: October 15, 2014
//Update: July 8, 2015

#include <fstream>
#include <iostream>
#include <iomanip> 
#include <string>
#include "functions.h"

using namespace std; 

//variables
double plate = 173; //from Charles River online catalogue 


//MISC
double samples_per_plate = 48; 
double shortPanel = 6;
double Qpanel = 17; 




int main ()
{
	ofstream myFile;
	ofstream myFile2;
	myFile.open("serologyPrices.txt");
	myFile2.open("list.txt");

//plates 
	double short6_panel = plate * 6; //plate cost per run
	double short7_panel = plate * 7; //plate cost per run 
	double quarantine_plate = plate * 17; //plate cost per run 


//*********************************************************************
	double a = posCONTROL();
	double b = fetalBovineSerum();
	double nacl = sodiumChloride();
	double naoh = sodiumHydroxide();
	double ha = haBuffer();
	double t = tween ();
	double milk = dryMilk();
	double foam = antifoam();
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
	
	 myFile2 << setprecision(4);
	 double cost_basic =  nacl  + naoh
		  + ha  + t + milk  + foam 
		  + peroxide  + acid  + ABTS; //cost per run

				myFile2 << "Cost_basic = " << nacl << " + " << naoh << " + "
					<< ha << " + " << t << " + " << milk << " + " << foam << " + "
					<< peroxide << " + " << acid << " + " << ABTS << endl;
				myFile2 << "total: " << cost_basic << endl; 
				myFile2 << endl;
				myFile2 << endl;

	 double cost_equipment = reader  + washer + incubate 
		  + pipette + ph_meter; //cost per run

				myFile2 << "cost_equipment = " << reader << " + " << washer
					<< " + " << incubate << " + " << pipette << " + " << 
					ph_meter << endl;
				myFile2 << "total: " << cost_equipment << endl; 
				myFile2 << endl;
				myFile2 << endl;
				
	double cost_short = cost_basic + short6_panel + tips_fisher
		 + a + b  + labor_short + cost_equipment; //cost per run
				
				myFile2 << "cost_short = " << " + " << cost_basic << " + " <<
					short6_panel << " + " << tips_fisher << " + " << a << " + " <<
					b << " + " << labor_short << " + " << cost_equipment << endl;
				myFile2 << "total: " << cost_short << endl; 
				myFile2 << endl;
				myFile2 << endl;

	 double cost_short7 = cost_basic + short7_panel + tips_fisher
		 + a + b + labor_short + cost_equipment; //cost per run

				myFile2 << "cost_short7 = " << " + " << cost_basic << " + " <<
					short7_panel << " + " << tips_fisher << " + " << a << " + " <<
					b << " + " << labor_short << " + " << cost_equipment << endl;
				myFile2 << "total: " << cost_short7 << endl; 
				myFile2 << endl;
				myFile2 << endl;
		  
	 double cost_long = cost_basic + quarantine_plate + tips_fisher
		 + a + b + laborQ + cost_equipment; //cost per run 

				myFile2 << "cost_long = " << cost_basic << " + " << quarantine_plate
					<< " + " <<  tips_fisher << " + " <<  a << " + " << b 
					<< " + " <<  laborQ << " + " << cost_equipment << endl;
				myFile2 << "total: " << cost_long << endl; 
				myFile2 << endl;

	 double half_short6 = (cost_short / 2 ) / 22;
	 double half_short7 = (cost_short7 / 2 ) / 22;
	 double half_quarantine = (cost_long / 2) / 22;
		//divide by 2 to have the cost of only half the plate
	 
			myFile2 << "Short 6 panel (half): " << half_short6 << endl;
			myFile2 << "Short 7 panel (half): " << half_short7 << endl;
			myFile2 << "Quarantine (half): " << half_quarantine << endl;
			myFile2 << endl;

	 double full_short6 = cost_short / 45; 
	 double full_short7 = cost_short7 /45;
	 double full_quarantine = cost_long / 45;
			
			myFile2 << "Short 6 panel (full): " << full_short6 << endl;
			myFile2 << "Short 7 panel (full): " << full_short7 << endl;
			myFile2 << "Quarantine (full) " << full_quarantine << endl;
			myFile2 << endl;

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