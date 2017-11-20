// ===============================
// = Catherine Etter
// = Tiffany's Taffy Shop Seminar Project
// = Main program file
// = TaffyShopSimulation.c
// ===============================

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "CustomerQueue.h"
#include "Stats.h"
//#include "Random.h"

//Show Debugging?
#define DEBUG
#define MAX_TIME 10 //How long to run the simulation

#ifndef MENU
#define MENU
#define LRG_BAG 13.99 //2 pound
#define MED_BAG 7.79  // 1 pound
#define SML_BAG 4.29  //.5 pound
#endif

void getInput(double *arrivalRate);
void runSimulation(double arrivalRate,QUEUE *queueA,QUEUE *queueB,STATS *statsA,STATS *statsB);
void printAllStats(const STATS *statsA,const STATS *statsB);

int main()
{
   double arrivalRate;
   QUEUE queueA,queueB;
   STATS statsA,statsB;
   //Initialize the queues and the stats structs
   srand(time(NULL));
   generateStats(&statsA);
   generateStats(&statsB);
   generateQueue(&queueA,1,2,4);
   generateQueue(&queueB,2,3,5);
   
   //Welcome message
   printf(" ================================\n");
   printf(" =          Welcome to          =\n");
   printf(" =     TIFFANY'S TAFFY SHOP     =\n");
   printf(" ================================\n");
   printf(" This program simulates the day-to-day operations of a taffy shop.\n");
   
   getInput(&arrivalRate);
   runSimulation(arrivalRate,&queueA,&queueB,&statsA,&statsB);
   printAllStats(&statsA,&statsB);
}
//----------[Get input from user]
void getInput(double *arrivalRate)
{
   char charInput[30];
   double intInput = -1;
   
   //Ask for the arrival rate until input satisfys conditions
   while(intInput >= 1 || intInput <= 0)
   {
      printf(" Please enter the customer arrival rate between 0 and 1 exclusive.\n >> ");
      fgets(charInput,30,stdin);
      intInput = atof(charInput);
   }
   *arrivalRate = intInput;
}
//----------[Run the Taffy Shop Simulation]
void runSimulation(double arrivalRate,QUEUE *queueA,QUEUE *queueB,STATS *statsA,STATS *statsB)
{
   int timeLeft = MAX_TIME;
   int i;

   for(i = 1; i <= 3; i++)
   {
      addCustToQueue(queueA,MED_BAG,i);
   }
   printf("Before:\n");
   displayQueue(queueA);
   while(customersInQueue(queueA,queueB))
   {
      serviceFirstCust(queueA,statsA);
   }
   printf("\nAfter:\n");
   displayQueue(queueA);
}
//----------[Print all the statistics]
void printAllStats(const STATS *statsA,const STATS *statsB)
{
   printf("\n ======================\n");
   printf(" = Simulation Results =\n");
   printf(" ======================\n");
   printf(" Line A Statistics:\n");
   displayStats(statsA);
   //printf(" Line B Statistics:\n");
   //displayStats(statsB);
   //printf(" Totals:\n");
   //displayTotals(statsA,statsB);
}
