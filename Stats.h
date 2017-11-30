// ===============================
// = Catherine Etter
// = Tiffany's Taffy Shop Seminar Project
// = Stats declarations file
// = Stats.h
// ===============================
/*
#define WAGE 8.29
#define TOTAL_HOURS 10
#define MATERIAL_COST_PER_POUND 3.49
*/
#ifndef STATS_DEF
#define STATS_DEF

typedef struct STATS
{
   int customersServed; //Number of customers serviced by the line
   int totalWaitTime; //Total time customers had to wait in line
   int totalServiceTime; //Total time each line spent servicing
   int totalSoldL; //Number of Large, medium, and small bags sold
   int totalSoldM;
   int totalSoldS;
   int largestQueueSize;
   int totalQueueSize; //Used to calculated Average Queue Size
   double moneyMade;
   int servicePastClosing; //How long the store had to remain open to service customers
}STATS;

void generateStats(STATS *stats);
int max(int a, int b);

double getTaffyPounds(const STATS *stats);
double getProfitEstimate(const STATS *stats);
double getTotalAvgQueueSize(const STATS *statsA, const STATS *statsB, int maxTime);
int getTotalService(const STATS *statsA, const STATS *statsB);
int getTotalWait(const STATS *statsA, const STATS *statsB);
int getTotalCust(const STATS *statsA, const STATS *statsB);
int getTotalBags(const STATS *statsA, const STATS *statsB);

void displayStats(const STATS *stats);
void displayTotals(const STATS *statsA, const STATS *statsB, int maxTime);

#endif
