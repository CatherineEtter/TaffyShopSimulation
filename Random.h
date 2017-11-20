// ===============================
// = Catherine Etter
// = Tiffany's Taffy Shop Seminar Project
// = Random definitions
// = Random.h
// ===============================

#include <time.h>

#ifndef RANDOM_DEF
#define RANDOM_DEF

void setRandSeed()
{
   srand(time(NULL));
}
int randInt(int LB, int UB)
{
   return ((rand() % (UB - (LB + 1))) + LB); 
}
#endif
