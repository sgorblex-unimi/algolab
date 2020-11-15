#ifndef BOUNDED_QUEUE_H
#define BOUNDED_QUEUE_H

#include "queue.h"


// creates a bounded queue of capacity n
Queue newBoundedQueue(int);

// returns !=0 if q is full
int isFullQueue(Queue);

#endif
