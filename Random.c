// ===============================
// = Catherine Etter
// = Tiffany's Taffy Shop Seminar Project
// = Random definitions
// = Random.h
// ===============================

#include <time.h>
#include "Random.h"
//Sets a random seed
void randSeed()
{
   srand(time(NULL));
}
//Generates a random integer between a lowerbase and upperbase
int randInt(int LB, int UB)
{
   return ((rand() % (UB - LB + 1)) + LB); 
}
