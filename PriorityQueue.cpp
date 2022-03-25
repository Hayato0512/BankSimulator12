#include "PriorityQueue.h"
#include "BinaryHeap.h"
#include <iostream>
using namespace std;


template<class ElementType>
PriorityQueue<ElementType>::PriorityQueue()
{    elementCount = 0;
     heap = new BinaryHeap<ElementType>;

}

template<class ElementType>
PriorityQueue<ElementType>::~PriorityQueue()
{   
    delete heap;
}

   
    /******* Start of Priority Queue Public Interface *******/

   // Description: Returns "true" if this Priority Queue is empty, otherwise "false".
   // Postcondition: This Priority Queue is unchanged by this operation.
   // Time Efficiency: O(1)
   template<class ElementType>
   bool PriorityQueue<ElementType>::isEmpty() const{
       if(elementCount==0)
        return true;
       return false;
   }

   // Description: Inserts newElement in this Priority Queue and 
   //              returns "true" if successful, otherwise "false".
    template<class ElementType>
    bool PriorityQueue<ElementType>::enqueue(ElementType& newElement){
        bool ableToEnqueue = false;
        ableToEnqueue = heap->insert(newElement);
        elementCount++;
        return ableToEnqueue;

    }
// bool enqueue(ElementType& newElement);

   // Description: Removes (but does not return) the element with the next
   //              "highest" priority value from the Priority Queue.
   // Precondition: This Priority Queue is not empty.
   // Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
   template<class ElementType>
   void PriorityQueue<ElementType>::dequeue(){
       try {
            heap->remove();
        }
        catch ( EmptyDataCollectionException& anException ) {
            cout<<"detected exception because "<< anException.what()<<endl;
        }

       elementCount--;
   }
   
   // Description: Returns (but does not remove) the element with the next 
   //              "highest" priority from the Priority Queue.
   // Precondition: This Priority Queue is not empty.
   // Postcondition: This Priority Queue is unchanged by this operation.
   // Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
   template<class ElementType>
   ElementType PriorityQueue<ElementType>::peek() const{
        
       try {
            return heap->retrieve();
        }
        catch ( EmptyDataCollectionException& anException ) {
            cout<<"detected exception because "<< anException.what()<<endl;
        }
        return heap->retrieve();
   }
   
      template<class ElementType>
   void PriorityQueue<ElementType>::printPriorityQueue() const{
       heap->printHeap();
   }
   
   
   //OR  ElementType peek() const; 
  //this keyboard is doing really good, i mean I think I should explore more about 
  //available shortcuts in VSC as it will improve my workflow so much better.
///////RIGHT???ALSO THIS KEYBOARD IS LIKE LINUX SYSTEM. OR , I SHOULD SAY, I DONT KNOW MAYBE US STYLE?
