// ===============================
// = Catherine Etter
// = Tiffany's Taffy Shop Seminar Project
// = Queue declarations file
// = Queue.h
// ===============================


#include <stdbool.h>

#include "Stats.h"
#define MAX_QUEUE 100

#ifndef QUEUE_DEF
#define QUEUE_DEF

typedef struct CUSTOMER
{
   int ID;
   double order;
   int arrivalTime; //Time created
   int serviceTime;
   struct CUSTOMER *next;
} CUSTOMER;

typedef struct QUEUE
{
   int customers; //# of customers currently in line
   int timeSBag;
   int timeMBag;
   int timeLBag;
   CUSTOMER *next;
} QUEUE;

void generateCustomer(CUSTOMER *customer, int arrivalTime);
void displayCustomer(const CUSTOMER *customer);

void generateQueue(QUEUE *queue,int timeSBag, int timeMBag, int timeLBag);
void addRandCustToQueue(QUEUE *queue, int arrivalTime);
void addCustToQueue(CUSTOMER *cust, QUEUE *queue);
void removeFirstFromQueue(QUEUE *queue);
void serviceFirstCust(QUEUE *queue,STATS *stats);
void moveLastFromTo(QUEUE *queueA, QUEUE *queueB);
bool customersInQueue(QUEUE *queueA,QUEUE *queueB);
void displayQueue(const QUEUE *queue);
void displayQueueLine(const QUEUE *queue); //Debugging purposes

#endif
