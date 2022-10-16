#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  if(pq->size == 0){return NULL;}
  else{return pq->heapArray[0].data;}
  return NULL;
}



void heap_push(Heap* pq, void* data, int priority){
  if(pq->size+1 > pq->capac){
    
    pq->capac = pq->capac * 2 + 1;
    //pq->heapArray = (heapElem*)realloc(pq->capac,sizeof(heapElem));
  }
  int auxP = pq->size; // empiezo al final 
  
  while (auxP > 0 && pq->heapArray[(auxP-1)/2].priority < priority){

    pq->heapArray[auxP] = pq->heapArray[(auxP-1)/2];
    auxP = (auxP-1)/2;
  }
  pq->heapArray[auxP].priority = priority;
  pq->heapArray[auxP].data = data;
  
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap *newHeap = (Heap*)malloc(sizeof(Heap));
  newHeap->heapArray = (heapElem*)malloc(3*sizeof(heapElem));
  newHeap->size = 0;
  newHeap->capac = 3;
  return newHeap;
}
