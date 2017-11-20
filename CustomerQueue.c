// ===============================
// = Catherine Etter
// = Tiffany's Taffy Shop Seminar Project
// = Queue definitions file
// = Queue.c
// ===============================

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "CustomerQueue.h"
#include "Random.h"
#include "Stats.h"

#ifndef MENU
#define MENU
#define LRG_BAG 13.99 //2 pound
#define MED_BAG 7.79  // 1 pound
#define SML_BAG 4.29  //.5 pound
#endif

//Initialize all the values of CUSTOMER
void generateCustomer(CUSTOMER *customer, double order, int arrivalTime)
{
   customer->ID = randInt(1000,9999);
   customer->order = order;
   customer->arrivalTime = arrivalTime;
   customer->serviceTime = 0; //Will change when customer is first to allow line jumping
   customer->next = NULL;
}
//Initialize all the values of QUEUE
void generateQueue(QUEUE *queue, int timeSBag, int timeMBag, int timeLBag)
{
   //Initialize all the values of QUEUE
   queue->customers = 0;
   queue->timeLBag = timeLBag;
   queue->timeMBag = timeMBag;
   queue->timeSBag = timeSBag;
   queue->next = NULL;
}
//Add the customer object to the end of the queue
void addCustToQueue(QUEUE *queue, double order, int arrivalTime)
{
   int i;
   CUSTOMER *newCustomer = (CUSTOMER *)malloc(sizeof(CUSTOMER));
   CUSTOMER *current;
   
   generateCustomer(newCustomer,order,arrivalTime);
   //Add the service time
   if(newCustomer->order == LRG_BAG)
   {
      newCustomer->serviceTime = queue->timeLBag;
   }
   else if(newCustomer->order == MED_BAG)
   {
      newCustomer->serviceTime = queue->timeMBag;
   }
   else if(newCustomer->serviceTime = SML_BAG)
   {
      newCustomer->serviceTime = queue->timeSBag;
   }
         
   //If 1st customer in queue
   if(queue->next == NULL)
   {
      queue->next = newCustomer;
   }
   //Add customer to the last place in queue
   else
   {
      current = queue->next;
      while(current->next != NULL)
      {
         current = current->next;
      }
      current->next = newCustomer;
   }
   queue->customers++;
}
//Removes the first customer from the queue
void removeFirstFromQueue(QUEUE *queue)
{
   CUSTOMER *current = queue->next;
   if(current->next == NULL)//If only 1 in the list
   {
      queue->next = NULL;
   }
   else
   {
      current = queue->next->next;
      queue->next = current;
   
   }
   queue->customers--;
   
}
//Service the first customer and updates the stats
void serviceFirstCust(QUEUE *queue,STATS *stats)
{
   CUSTOMER *first = queue->next;
   if(first->serviceTime == 0)
   {
      //Updating Stats
      stats->customersServed++;
      if(first->order == LRG_BAG)
      {
         stats->totalSoldL++;
      }
      else if(first->order == MED_BAG)
      {
         stats->totalSoldM++;
      }
      else if(first->order == SML_BAG)
      {
         stats->totalSoldS++;
      }
      stats->moneyMade += first->order;
      //Removing first customer
      removeFirstFromQueue(queue);
   }
   else //Decrements the service time
   {
      first->serviceTime--;
      //Updating Stats
      stats->totalServiceTime++;
   }
}
//Displays information about the Queue
void displayQueue(const QUEUE *queue)
{
   printf("Customers: %d \n",queue->customers);
   printf("Service times for S/M/L: %d/%d/%d\n",queue->timeSBag,queue->timeMBag,queue->timeLBag);
}
bool customersInQueue(QUEUE *queueA,QUEUE *queueB)
{
   return queueA->customers != 0 || queueB->customers != 0;
}
//Displays information about customer
void displayCustomer(const CUSTOMER *customer)
{
   printf("ID: %d\n",customer->ID);
   printf("Order Amount: %.2lf\n",customer->order);
   printf("Arrival Time: %d\n",customer->arrivalTime);
   printf("Current Service Time: %d\n",customer->serviceTime);
}
//Display the customers inside the queue
void displayQueueLine(const QUEUE *queue)
{

   CUSTOMER *current = queue->next;
   
   while(current != NULL)
   {
      displayCustomer(current);
      printf("\n");
      current = current->next;
   }
}
