/*
// ===============================
// = Catherine Etter
// = Tiffany's Taffy Shop Seminar Project
// = Random definitions
// = Random.h
// ===============================

#include <time.h>
#include "Random.c"

void setRandSeed()
{
   srand(time(NULL));
}
int getRandInt(int LB, int UB)
{
   return ((rand() % (UB - (LB + 1))) + LB); 
}
*/
