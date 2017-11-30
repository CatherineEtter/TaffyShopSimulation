
// ===============================
// = Catherine Etter
// = Tiffany's Taffy Shop Seminar Project
// = Random definitions
// = Random.h
// ===============================

#include <time.h>
#include "Random.h"

void randSeed()
{
   srand(time(NULL));
}
int randInt(int LB, int UB)
{
   return ((rand() % (UB - LB + 1)) + LB); 
}

