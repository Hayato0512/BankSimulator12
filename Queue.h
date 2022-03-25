/* 
 * Queue.h
 *
 * Description: Implementation of an int sequence with enqueue/dequeue ...
 * Class Invariant: ... in FIFO order
 *
 * Author:
 * Date:
 */
#include "Event.h"
template<class ElementType>
class Queue {
	
    private:
        static unsigned const INITIAL_CAPACITY = 6; // Constant INITIAL_CAPACITY
        ElementType *elements;             // To do: replace this by int * elements -> Question 4.a)

        unsigned int  elementCount;                      // Number of elements in the Queue
        unsigned int capacity;                          // Actual capacity of the data structure (number of cells in the array)
        unsigned int frontindex;                        // Index the topmost element
        unsigned int backindex;                         // Index where the next element will be placed                     

    public:
        // Description:  Constructor
        Queue();

       ~Queue();

bool QueueIsFull();
bool indexIsNotFlipped();
bool indexIsFlipped();
        // Description:  Inserts element x at the back (O(1))
        void enqueue(ElementType x);


        // Description:  Removes the frontmost element (O(1))
        // Precondition:  Queue not empty
        void dequeue();


        // Description:  Returns a copy of the frontmost element (O(1))
        // Precondition:  Queue not empty
        ElementType peek() const;


        // Description:  Returns true if and only if queue empty (O(1))
        bool isEmpty() const;

        int getElementCount();
};

#include "Queue.cpp"



// dESCRIPTION:  CONSTRUCTOr
/*
template<class ElementType>
Queue<ElementType>::Queue() : elementCount(0), capacity(INITIAL_CAPACITY), frontindex(0), backindex(0) {
    elements = new ElementType[INITIAL_CAPACITY];//これでいけてるんじゃない？？おけおけ
} 
//FIRST INSERT WITH MY VIM COMMAND OK, THIS IS hAYATO hELLO!!! i want to learn this shit.
template<class ElementType>
Queue<ElementType>::~Queue() {
    delete [] elements;
}
template<class ElementType>
bool Queue<ElementType>::QueueIsFull(){
    return capacity==elementCount;
}
template<class ElementType>
bool Queue<ElementType>::indexIsNotFlipped(){
    return frontindex<backindex;
}
template<class ElementType>
bool Queue<ElementType>::indexIsFlipped(){
    return frontindex<backindex;
}

//capacity==elementCount
// Description:  Inserts element x at the back (O(1))
template<class ElementType>
void Queue<ElementType>::enqueue(ElementType x) {
    elementCount++;
    if(QueueIsFull()){
        ElementType* toBeDeleted = elements;
        ElementType *newelements = new ElementType[capacity*2];
        if(indexIsNotFlipped()){
            for(int i = frontindex;i<backindex;i++){
                newelements[i] = elements[i];//void copySmallBig();
            }
            capacity = capacity*2;
            delete[] toBeDeleted;
            elements = newelements;
            


        }
        else if(indexIsFlipped()){
            for(int i =0;i<(elementCount-frontindex);i++){//frontIndexから最後のとこまで全部小py。
                newelements[frontindex+i]=elements[frontindex+i];//
            }
            for(int j = 0;j<frontindex;j++){//jが前に行っちゃってる分だけ、最初からコピー
                newelements[capacity+j] = elements[j];
            }
            backindex = backindex+capacity;
            capacity = capacity*2;
            delete[] toBeDeleted;
            elements = newelements;
            

        }
//(int i = 0; i<n;i++)
//hey I just used o command, it inserts a new line below and puts me into the insert mode

//hey I just used o command, it inserts a new line below and puts me into the insert mode
//hey I just used o command, it inserts a new line below and puts me into the insert mode
//hey I just used o command, it inserts a new line below and puts me into the insert mode
//hey I just used o command, it inserts a new line below and puts me into the insert mode
//hey I just used o command, it inserts a new line below and puts me into the insert mode
//hey I just used o command, it inserts a new line below and puts me into the insert mode
//hey I just used o command, it inserts a new line below and puts me into the insert mode
//hey I just used o command, it inserts a new line below and puts me into the insert mode
//hey I just used o command, it inserts a new line below and puts me into the insert mode






    }
    elements[backindex] = x;
    backindex = (backindex + 1) % capacity;
} 


// Description:  Removes the frontmost element (O(1))
// Precondition:  Queue not empty
template<class ElementType>
void Queue<ElementType>::dequeue() {
    elementCount--;
    if((elementCount < (capacity/4)) && (capacity > INITIAL_CAPACITY)){
        ElementType* toBeRemoved = elements;
        ElementType *newelements = new ElementType[capacity/2];
        if(frontindex < backindex){
            for(int i = 0;i<(backindex-frontindex);i++){
                newelements[i] = elements[frontindex+i];

            }
            delete[] toBeRemoved;
            elements = newelements;
            
            backindex = backindex - frontindex;
            frontindex = 0;
            capacity = capacity/2;
        }
        else if(frontindex > backindex){
            for(int i = 0;i<(capacity-frontindex);i++){
                newelements[i] = elements[frontindex+i];
            }
            for(int j = 0;j<((elementCount+1)-(capacity-frontindex));j++){
                newelements[(capacity-frontindex)+j] = elements[j];
            }
             delete[] toBeRemoved;
            elements = newelements;
           
            frontindex = 0;
            backindex = elementCount+1;
            capacity = capacity/2;

        }



    }
    frontindex = (frontindex + 1) % capacity;
} 


// Description:  Returns a copy of the frontmost element (O(1))
// Precondition:  Queue not empty
template<class ElementType>
ElementType Queue<ElementType>::peek() const {
    return elements[frontindex];
} 


// Description:  Returns true if and only if queue empty (O(1))
template<class ElementType>
bool Queue<ElementType>::isEmpty() const {
    return elementCount == 0;
}
*/