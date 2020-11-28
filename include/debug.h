#ifndef DEBUG_H
#define DEBUG_H

// use gcc -DEBUG to enable this
#ifdef EBUG
#include <stdio.h>

#define debug_print(args...) fprintf(stderr, args)

#else

#define debug_print(args...)

#endif

#endif
