// ===============================
// = Catherine Etter
// = Tiffany's Taffy Shop Seminar Project
// = Stats definition file
// = Stats.c
// ===============================

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Stats.h"

#define WAGE 8.29
#define TOTAL_HOURS 10
#define MATERIAL_COST_PER_POUND 3.49

//Initialize all the values of STATS
void generateStats(STATS *stats)
{
   stats->customersServed = 0;
   stats->totalWaitTime = 0;
   stats->totalServiceTime = 0;
   stats->totalSoldL = 0;
   stats->totalSoldM = 0;
   stats->totalSoldS = 0;
   stats->largestQueueSize = 0;
   stats->totalQueueSize = 0;
   stats->moneyMade = 0;
   stats->servicePastClosing = 0;
}
//Returns max of two ints
int max(int a, int b)
{
   return a > b ? a : b;
}
//Returns the total pounds of taffy in queue's stats
double getTaffyPounds(const STATS *stats)
{
   return (stats->totalSoldL * 2) + stats->totalSoldM + (stats->totalSoldS * .5);
}
//Calculates te profitability estimate.
double getProfitEstimate(const STATS *stats)
{
   return (WAGE * TOTAL_HOURS) + (MATERIAL_COST_PER_POUND * getTaffyPounds(stats));
}
//Returns the average queue size of a queue. Divides the total queue size by entire time the queue was running
double getTotalAvgQueueSize(const STATS *statsA, const STATS *statsB, int maxTime)
{
   int totalTime = maxTime + max(statsA->servicePastClosing,statsB->servicePastClosing);
   
   return (double)(statsA->totalQueueSize + statsB->totalQueueSize) / totalTime;
}
//Returns total service time of the two queues
int getTotalService(const STATS *statsA, const STATS *statsB)
{
   return (statsA->totalServiceTime + statsB->totalServiceTime);
}
//Returns the total waiting time of the two queues
int getTotalWait(const STATS *statsA, const STATS *statsB)
{
   return (statsA->totalWaitTime + statsB->totalWaitTime);
}
//Returns the total customers serviced by the two queues
int getTotalCust(const STATS *statsA, const STATS *statsB)
{
   return (statsA->customersServed + statsB->customersServed);
}
//Returns the total bags of taffy sold
int getTotalBags(const STATS *statsA, const STATS *statsB)
{
   int sum1 = statsA->totalSoldL + statsA->totalSoldM + statsA->totalSoldS;
   int sum2 = statsB->totalSoldL + statsB->totalSoldM + statsB->totalSoldS;
   
   return (sum1 + sum2);
}
//Displays individual stats of the two queues.
void displayStats(const STATS *statsA, const STATS *statsB)
{
   //Some stats calculated here to reserve horizontal space
   int custA = statsA->customersServed;
   int custB = statsB->customersServed;
   double avgServiceTimeA = (custA == 0 ? 0 : (double) statsA->totalServiceTime / custA);
   double avgServiceTimeB = (custB == 0 ? 0 : (double) statsB->totalServiceTime / custB);
   double avgWaitTimeA = (custA == 0 ? 0 : (double) statsA->totalWaitTime / custA);
   double avgWaitTimeB = (custB == 0 ? 0 : (double) statsB->totalWaitTime / custB);
   
   printf("Statistics             LineA      LineB\n");
   printf(" - Customers Served:   %-10d %-10d\n",statsA->customersServed,statsB->customersServed);
   printf(" - Service Time:       %-10d %-10d\n",statsA->totalServiceTime,statsB->totalServiceTime);
   printf(" - Avg Service Time:   %-10.2lf %-10.2lf\n",avgServiceTimeA,avgServiceTimeB);
   printf(" - Wait Time:          %-10d %-10d\n",statsA->totalWaitTime,statsB->totalWaitTime);
   printf(" - Avg Wait Time:      %-10.2lf %-10.2lf\n",avgWaitTimeA,avgWaitTimeB);
   printf(" - Largest Queue Size: %-10d %-10d\n",statsA->largestQueueSize,statsB->largestQueueSize);
   printf(" - Money Made:         %-10.2lf %-10.2lf\n",statsA->moneyMade,statsB->moneyMade);
   printf(" - Pounds Sold:        %-10.2lf %-10.2lf\n",getTaffyPounds(statsA),getTaffyPounds(statsB));
}
//Displays the totals of the two queues
void displayTotals(const STATS *statsA,const STATS *statsB, int maxTime)
{
   printf("Totals\n");
   printf(" - Total Customers:        %d\n",getTotalCust(statsA,statsB));
   printf(" - Total Service Time:     %d\n",getTotalService(statsA,statsB));
   printf(" - Total Avg Service Time: %.2lf\n",(double)getTotalService(statsA,statsB) / getTotalCust(statsA,statsB));
   printf(" - Total Wait Time:        %d\n",getTotalWait(statsA,statsB));
   printf(" - Total Avg Wait Time:    %.2lf\n",(double)getTotalWait(statsA,statsB) / getTotalCust(statsA,statsB));
   printf(" - Total Avg Queue Size:   %.2lf\n",getTotalAvgQueueSize(statsA,statsB,maxTime));
   printf(" - Total 2 lb Bags Sold:   %d\n",statsA->totalSoldL + statsB->totalSoldL);
   printf(" - Total 1 lb Bags Sold:   %d\n",statsA->totalSoldM + statsB->totalSoldM);
   printf(" - Total 1/2 lb Bags Sold: %d\n",statsA->totalSoldS + statsB->totalSoldS);
   printf(" - Total Bags Sold:        %d\n",getTotalBags(statsA,statsB));
   printf(" - Total Money Made:       %.2lf\n",statsA->moneyMade + statsB->moneyMade);
   printf(" - Time Past Closing:      %d\n",max(statsA->servicePastClosing,statsB->servicePastClosing));
   printf(" - Total Pounds Sold:      %.2lf\n",getTaffyPounds(statsA) + getTaffyPounds(statsB));
   printf(" - Profitability estimates: %.2lf\n",getProfitEstimate(statsA) + getProfitEstimate(statsB));
}
