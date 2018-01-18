// ===============================
// = Catherine Etter
// = Tiffany's Taffy Shop Seminar Project
// = CustomerQueue definitions file
// = CustomerQueue.c
// ===============================

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "CustomerQueue.h"
#include "Random.h"
#include "Stats.h"

//#define SHOW_PROCESS

#ifndef MENU
#define MENU
#define LRG_BAG 13.99 //2 pound
#define MED_BAG 7.79  // 1 pound
#define SML_BAG 4.29  //.5 pound
#endif

//Initialize all the values of CUSTOMER
void generateCustomer(CUSTOMER *customer, int arrivalTime)
{
   customer->ID = randInt(1000,9999);
   customer->order = 0; //Assigned when adding a customer.
   customer->arrivalTime = arrivalTime;
   customer->serviceTime = 0; //Will change when customer is first to allow line jumping
   customer->next = NULL;
}
//Initialize all the values of QUEUE
void generateQueue(QUEUE *queue, char type, int timeSBag, int timeMBag, int timeLBag)
{
   //Initialize all the values of QUEUE
   queue->type = type;
   queue->customers = 0;
   queue->timeLBag = timeLBag;
   queue->timeMBag = timeMBag;
   queue->timeSBag = timeSBag;
   queue->next = NULL;
}
//Creates a random customer object and assigns customer to queue
void addRandCustToQueue(QUEUE *queue, int arrivalTime)
{
   int r = randInt(1,100);
   CUSTOMER *newCustomer = (CUSTOMER *)malloc(sizeof(CUSTOMER));
   
   generateCustomer(newCustomer,arrivalTime);
   //Add the service time
   if(r <= 20) //20% chance for small
   {
      newCustomer->order = SML_BAG;
      newCustomer->serviceTime = queue->timeSBag;  
   }
   else if(r <= 70) //50% chance for medium
   {
      newCustomer->order = MED_BAG;
      newCustomer->serviceTime = queue->timeMBag;
   }
   else //30% chance for large
   {
      newCustomer->order = LRG_BAG;
      newCustomer->serviceTime = queue->timeLBag;
   }
   addCustToQueue(newCustomer,queue);
}
//Adds customer to queue
void addCustToQueue(CUSTOMER *cust, QUEUE *queue)
{
   CUSTOMER *current;
   
   //If 1st customer in queue
   if(queue->next == NULL)
   {
      queue->next = cust;
   }
   //Add customer to the last place in queue
   else
   {
      current = queue->next;
      while(current->next != NULL)
      {
         current = current->next;
      }
      current->next = cust;
   }
   queue->customers++;
#ifdef SHOW_PROCESS
   printf("------Added in Queue%c------\n",queue->type);
   displayCustomer(cust);
#endif
}
//Removes the first customer from the queue
void removeFirstFromQueue(QUEUE *queue)
{
   CUSTOMER *current = queue->next;
   
#ifdef SHOW_PROCESS
   printf("-----Removed from Queue%c-----\n",queue->type);
   displayCustomer(current);
#endif
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
   //Only Service first customer if there is a first customer
   if(queue->next != NULL)
   {
      CUSTOMER *first = queue->next;
      
      stats->totalWaitTime += queue->customers-1; //Add wait time for each customer not in front.
      if(first->serviceTime == 1) //Minutes are loops, so 1 minute is one loop.
      {
         //printf("Served customer with order: %.2lf\n",first->order);
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
      }
      //Updating Stats
      stats->totalServiceTime++;
      if(queue->customers > stats->largestQueueSize)
      {
         stats->largestQueueSize = queue->customers;
      }
      stats->totalQueueSize += queue->customers;
   }
}
//Moves the last customer in line form QueueA to QueueB
void moveLastFromTo(QUEUE *queueA, QUEUE *queueB)
{
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
