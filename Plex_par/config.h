#pragma once
#define CAP_LIMIT1 (1<<14)
#define CAP_LIMIT2 (1<<14)
#define PSIZE_LIMIT  4096 //Maximum possible size of K-plex
#define K_LIMIT 4
//#define TIMEOUT_THRESH 0.1 // in millisecond

// openmp
#if defined(OPENMP)
#include <omp.h>
#define parallel_main main
#define cilk_spawn
#define cilk_sync 
#define parallel_for _Pragma("omp parallel for") for
#define parallel_for_1 _Pragma("omp parallel for schedule (static,1)") for
#define parallel_for_256 _Pragma("omp parallel for schedule (static,256)") for
static int getWorkers() { return omp_get_max_threads(); }
static void setWorkers(int n) { omp_set_num_threads(n); }
static int getNumber(){ return omp_get_thread_num(); }

// serial c++
#else
#define parallel_main main
#define parallel_for for
#define parallel_for_1 for
#define parallel_for_256 for
#define cilk_sync  
#define cilk_spawn  

static int getWorkers() { return 1; }
static void setWorkers(int n) { }
static int getNumber(){ return 0; }

#endif


#include <limits.h>
#if defined(LONG)
typedef long intT;
typedef unsigned long uintT;
#define INT_T_MAX LONG_MAX
#define UINT_T_MAX ULONG_MAX
#else
typedef int intT;
typedef unsigned int uintT;
#define INT_T_MAX INT_MAX
#define UINT_T_MAX UINT_MAX
#endif
