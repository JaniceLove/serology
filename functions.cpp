//Functions for ELISA costs 
//Author: Janice Love
//Date: April 29, 2015
//Update: July 6, 2015


#include "functions.h"

double plates = 10;
double life = 8;

double posCONTROL() //cost per plate
{
	double price = 60.25; //0.5mL, 10 plates
	double perPlate = price / plates; 
	return perPlate;
}

double negCONTROL () //per plate
{
	 double price = 15.00; //0.1mL, 10 plates
	 double perPlate = price / plates;
	 return perPlate;
}

double fetalBovineSerum ()
{
	double price = 185.16; //500 mLs, BCM martketplace  
	  double volume = 500;
	  double quantity = 70;
	double perRun = (price / volume) * quantity; 
	return perRun;
}

double sodiumChloride()
{
	double price = 36.2; // per 500g
	double grams = 500;  
	double gramsPerRun = 36; 
	double pricePerGram = price / grams;
	double perRun = pricePerGram * pricePerGram;
	return perRun;
}

double sodiumHydroxide ()
{
	double price = 20.95; //per 2 pounds (907.184g)
	double grams = 907.184;
	double gramsPerRun = 25;
	double perGram = price / grams;
	double perRun = gramsPerRun * perGram;
	return perRun;
}

double haBuffer()
{
	double price = 60.66; //per pound (453.592g)
	double grams = 453.592;
	double gramsPerRun = 4.615; 
	double perGram = price / grams; 
	double perRun = gramsPerRun * perGram;
	return perRun;
}

double tween ()
{
	double price = 12.54; 
	double volume = 100; 
	double perML= price / volume;
	double perRunMLS = 4.615;
	double perRun = perRunMLS * perML;
	return perRun;
}

double dryMilk ()
{
	double price = 36;
	double grams = 250; 
	double gramsPerRun = 8.33; 
	double pricePerGram = price / grams;
	double perRun = pricePerGram * gramsPerRun;
	return perRun;
}

double antifoam ()
{
	double price = 30.5; 
	double volume = 100;
	double perML = price / volume;
	double perRunAmount = 0.53; 
	double perRun = perRunAmount * perML;
	return perRun;
}

double hPeroxide ()
{
	double price = 84.60; 
	double volume = 250; 
	double hpPerRun = 0.5; 
	double perML = price / volume;
	double perRun = hpPerRun * perML;
	return perRun; 
}

double citricAcid ()
{
	double price = 39.7;
	double grams = 500;
	double gramsPerRun = 2.4;
	double perGram = price / grams;
	double perRun = perGram * gramsPerRun;
	return perRun;
}

double abts ()
{
	double price = 194;
	double grams = 5;
	double gramsPerRun = 0.055; 
	double pricePerGram = price / grams;
	double perRun = gramsPerRun * pricePerGram;
	return perRun;
}

double plateReader ()
{
	double cost = 17793; //from asset listing
	 //double samples_per_month = 1632; 
		//48 samples per plate, 2 of each plate per month (17*2 = 34)
		// 48 * 34 = 1632 

	  double depreciation = cost / life; 
	  double per_month = depreciation / 12;
	  double per_run = per_month / 3; // runs per month 
	  return per_run; 
}

double plateWasher() //same as plate reader??
{
	double cost = 19470; //BCM marketplace
	double depreciation = cost / life;
	double perMonth = depreciation / 12; 
	double per_run = perMonth / 3; // runs per month 
	return per_run;
}

double incubator ()
{
	double cost = 1748.56;
	double depreciation = cost / life; 
	double perMonth = depreciation / 12;
	double perRun = perMonth / 3; //runs per month 
	  //double incubator_costPerSample = incubator_perMonth / 
		  //samples_per_month; 
	return perRun;
}

double ePipette ()
{
	double cost = 544.23; //BCM marketplace
	double depreciation = cost / life;
	double perMonth = depreciation / 12;
	double costPerRun = perMonth / 3; 
	return costPerRun;
}

double phMeter ()
{
	double cost = 157.50; //from BCM marketplace
	double depreciation = cost / life; 
	double costPerMonth = depreciation / 12; 
	double costPerRun = costPerMonth / 3; 
	return costPerRun;
}

double tips ()
{
	double cost = 127.74; //tips used only for serology, from BCM marketplace 
	double no_of_tips = 1920; //tips per case
	double tips_per_rack = 96; 
	double tipsRun = 3 * tips_per_rack; //2 boxes used per run
	  
	double costPerUnit = cost / no_of_tips; 
	double costPerRun = costPerUnit * tipsRun; 
	return costPerRun;
}

double tech_time_short ()
{
	 double hour = 23.38; //from CCM
	 double setUp = 30; //minutes, includes making reagents 
	 double incubation = 40 * 3; //2 sets of 40 minutes in incubation, plus 1 final set
	 double time = setUp + incubation; //minutes
	 double totalCost = (time / 60) * hour; //cost per run
	 return totalCost;
}

double tech_time_Q ()
{
	 double hour = 23.38; //from CCM
	 double setUpQ = 60; //minutes 
	 double incubation = 40 * 3; //2 sets of 40 minutes in incubation, plus 1 final set
	 double timeQ = setUpQ + incubation; //minutes
	 double total_long = (timeQ / 60) * hour; //cost per run 
	 return total_long;
}


	 
 



