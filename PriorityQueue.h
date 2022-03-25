//#ifndef PRIORITYQUEUE_H
//#define PRIORITYQUEUE_H
#include "BinaryHeap.h"
#include "Event.h"
#pragma once
template<class ElementType>
class PriorityQueue
{
public:
 /******* Start of Priority Queue Public Interface *******/
    PriorityQueue();
    ~PriorityQueue();
   


// Description: Inserts newElement in this Priority Queue and 
   //              returns "true" if successful, otherwise "false".
   bool enqueue(ElementType& newElement);


   // Description: Returns "true" if this Priority Queue is empty, otherwise "false".
   // Postcondition: This Priority Queue is unchanged by this operation.
   // Time Efficiency: O(1)
   bool isEmpty() const;

   

   // Description: Removes (but does not return) the element with the next
   //              "highest" priority value from the Priority Queue.
   // Precondition: This Priority Queue is not empty.
   // Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
   void dequeue();
   
   // Description: Returns (but does not remove) the element with the next 
   //              "highest" priority from the Priority Queue.
   // Precondition: This Priority Queue is not empty.
   // Postcondition: This Priority Queue is unchanged by this operation.
   // Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
   ElementType peek() const;  
   

   //For testing purpose, delete or move to private when submit
   void printPriorityQueue() const;
/*******  End of Priority Queue Public Interface *******/

private:
    int elementCount;
    BinaryHeap<ElementType>* heap;

    
};
#include "PriorityQueue.cpp"

//#endif