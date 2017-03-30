#ifndef _JOSEPH_H_
#define _JOSEPHE_H


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct Joseph_ring
{
  int num;
  struct Joseph_ring* next;
}Joseph,*pJoseph;

pJoseph CreateJoseph(int n);
void joseph_r(pJoseph head, int k, int m);

#endif
