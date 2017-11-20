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

void generateStats(STATS *stats)
{
   stats->customersServed = 0;
   stats->totalWaitTime = 0;
   stats->totalServiceTime = 0;
   stats->totalSoldL = 0;
   stats->totalSoldM = 0;
   stats->totalSoldS = 0;
   stats->largestQueueSize = 0;
   stats->moneyMade = 0;
   stats->servicePastClosing = 1;
}
int max(int a, int b)
{
   return a > b ? a : b;
}
double getTaffyPounds(const STATS *stats)
{
   return (stats->totalSoldL * 2) + stats->totalSoldM + (stats->totalSoldS * .5);
}
double getProfitEstimate(const STATS *stats)
{
   return (WAGE * TOTAL_HOURS) + (MATERIAL_COST_PER_POUND * getTaffyPounds(stats));
}
int getTotalService(const STATS *statsA, const STATS *statsB)
{
   return (statsA->totalServiceTime + statsB->totalServiceTime);
}
int getTotalWait(const STATS *statsA, const STATS *statsB)
{
   return (statsA->totalWaitTime + statsB->totalWaitTime);
}
int getTotalCust(const STATS *statsA, const STATS *statsB)
{
   return (statsA->customersServed + statsB->customersServed);
}
int getTotalBags(const STATS *statsA, const STATS *statsB)
{
   int sum1 = statsA->totalSoldL + statsA->totalSoldM + statsA->totalSoldS;
   int sum2 = statsB->totalSoldL + statsB->totalSoldM + statsB->totalSoldS;
   return (sum1 + sum2);
}
void displayStats(const STATS *stats)
{
   printf(" - Customers Served: %d\n",stats->customersServed);
   printf(" - Service Time:     %d\n",stats->totalServiceTime);
   printf(" - Avg Service Time: %.2lf\n",stats->totalServiceTime / stats->customersServed);
   printf(" - Wait Time:        %d\n",stats->totalWaitTime);
   printf(" - Avg Wait Time:    %.2lf\n",stats->totalWaitTime / stats->customersServed);
   printf(" - Money Made:       %.2lf\n",stats->moneyMade);
   printf(" - Pounds Sold:      %.2lf\n",getTaffyPounds(stats));
}
void displayTotals(const STATS *statsA,const STATS *statsB)
{
   printf(" - Total Customers:        %d\n",getTotalCust(statsA,statsB));
   printf(" - Total Service Time:     %d\n",getTotalService(statsA,statsB));
   printf(" - Total Avg Service Time: %lf\n",(double)getTotalService(statsA,statsB) / getTotalCust(statsA,statsB));
   printf(" - Total Wait Time:        %lf\n",getTotalWait(statsA,statsB));
   printf(" - Total Avg Wait Time:    %d\n",(double)getTotalWait(statsA,statsB) / getTotalCust(statsA,statsB));
   printf(" - Total 2 lb Bags Sold:   %d\n",statsA->totalSoldL + statsB->totalSoldL);
   printf(" - Total 1 lb Bags Sold:   %d\n",statsA->totalSoldM + statsB->totalSoldM);
   printf(" - Total 1/2 lb Bags Sold: %d\n",statsA->totalSoldS + statsB->totalSoldS);
   printf(" - Total Bags Sold:        %d\n",getTotalBags(statsA,statsB));
   printf(" - Total Money Made:       %d\n",statsA->moneyMade + statsB->moneyMade);
   printf(" - Time Past Closing:      %d\n",max(statsA->servicePastClosing,statsB->servicePastClosing));
   printf(" - Total Pounds Sold:      %d\n",getTaffyPounds(statsA) + getTaffyPounds(statsB));
   printf(" - Profitability estimates: %lf\n",getProfitEstimate(statsA) + getProfitEstimate(statsB));
}
