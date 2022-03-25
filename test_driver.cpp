#include "BinaryHeap.h" 
#include "PriorityQueue.h"
#include <iostream>
#include "Event.h"
#include "Queue.h"
#include "EmptyDataCollectionException.h"
using namespace std;

int waitingTimeTotal = 0;

void processArrival(Event& newEvent,PriorityQueue<Event>& eventPriorityQueue,Queue<Event>& bankLine, bool& tellerAvailable, int currentTime){
    eventPriorityQueue.dequeue();
    
    Event customer = newEvent;
    if(bankLine.isEmpty() && tellerAvailable){
        cout<<"Processing an arrival event at time:   "<<customer.getTime()<<endl;
        int departureTime = newEvent.getTime() + newEvent.getLength();
        Event newDepartureEvent(Event::DEPARTURE, departureTime);
        eventPriorityQueue.enqueue(newDepartureEvent);
        tellerAvailable = false;
    }
    else{
        cout<<"Processing an arrival event at time:   "<<currentTime<<endl;//customer.getTime()
        bankLine.enqueue(customer);

    }
}

void processDeparture(Event& newEvent,PriorityQueue<Event>& eventPriorityQueue,Queue<Event>& bankLine, bool& tellerAvailable, int currentTime){
    cout<<"Processing an departure event at time: "<<currentTime<<endl;
    eventPriorityQueue.dequeue();

    if(!(bankLine.isEmpty())){
        
        Event customer = bankLine.peek();
        //cout<<"Processing an arrival event at time: "<<customer.getTime()<<endl;
        bankLine.dequeue();
        //waiting time of customer = newEvent's time  - customoers arrival time
        waitingTimeTotal += newEvent.getTime() - customer.getTime();
        int departureTime = currentTime + customer.getLength();
        Event newDepartureEvent(Event::DEPARTURE, departureTime);
        eventPriorityQueue.enqueue(newDepartureEvent);

    }
    else{
        tellerAvailable = true;
    }
}


int main(){
    cout<<"\nSimulation Begins \n"<<endl;
    Queue<Event> bankLine;
    PriorityQueue<Event> eventPriorityQueue;

    bool tellerAvailable = true;
    int time;
    int length;
    float numberOfCustomers = 0;
    while (std::cin >> time >> length){
        Event e(Event::ARRIVAL, time, length);
        eventPriorityQueue.enqueue(e);
        numberOfCustomers++;
         }
    //eventPriorityQueue.printPriorityQueue();
    

    while(!(eventPriorityQueue.isEmpty())){
        Event newEvent = eventPriorityQueue.peek();
        //Event* newEventP = &newEvent;

        int currentTime = newEvent.getTime();//ok

        if(newEvent.getType()== Event::ARRIVAL){
            processArrival(newEvent,eventPriorityQueue,bankLine, tellerAvailable, currentTime);
        }
        else{
            processDeparture(newEvent,eventPriorityQueue,bankLine, tellerAvailable, currentTime);
        }
    }
    cout<<"\nSimulation Ends\n\n"<<endl;

    float averageWaitingTime = waitingTimeTotal/numberOfCustomers;

    cout<<"Final Statistics: "<<endl<<endl<<endl;
    cout<<"     Total number of people processed: "<<numberOfCustomers<<endl<<endl;
    cout<<"     Average amount of time spent waiting: "<< averageWaitingTime<<endl<<endl;
    // Event a(Event::ARRIVAL, 30,30);
    // Event b(Event::DEPARTURE, 30);
    // Event c(Event::ARRIVAL, 29,30);
    
    // bool result = a<=c;
    // cout<<"result is this"<<result<<endl;
  
   
    // // std::cin >> time;
    // // std::cin >> length;
    // PriorityQueue<Event> q1;

    
    // //std::cout << n;
    // q1.printPriorityQueue();
    //Event e1(Event::ARRIVAL, time,length);

    //Event e2(Event::ARRIVAL, time2, length2);
    // Event e3(Event::ARRIVAL, 2);
    // Event e4(Event::ARRIVAL, 6);
    // Event e5(Event::ARRIVAL, 0);

    
    //haha.enqueue(e2);
    // cout<<haha.peek();
    // haha.dequeue();
    // cout<<haha.peek();
    // haha.dequeue();
    // cout<<haha.peek();
    // haha.dequeue();
    // cout<<haha.peek();
    // haha.dequeue();
    //cout<<haha.getElementCount();
    // haha.enqueue(e2);
    // haha.enqueue(e3);
    // haha.enqueue(e4);
    // haha.enqueue(e5);
    // haha.dequeue();
    // haha.dequeue();
    // haha.dequeue();
    // cout<<haha.peek();
   
//    //q1.peek();
//    //q1.isEmpty();
//    q1.enqueue(e1);
//    q1.enqueue(e2);
//    q1.enqueue(e3);
//    q1.enqueue(e4);
//    q1.enqueue(e5);
//    q1.printPriorityQueue();
//     cout<< q1.peek();
      

//    q1.dequeue();
//     q1.printPriorityQueue();
//    cout<< q1.peek();
//    q1.dequeue();
//    q1.printPriorityQueue();
//    cout<< q1.peek();
//    q1.dequeue();
//    q1.printPriorityQueue();
//    cout<< q1.peek();

//    //q1.printPriorityQueue();
   
//    cout<<"+++++++++++++++++++++++++++"<<endl;
//    q1.printPriorityQueue();
   

    

    /*Event e1(Event::ARRIVAL, 5);
    Event e2(Event::ARRIVAL, 3);
    Event e3(Event::ARRIVAL, 2);
    Event e4(Event::ARRIVAL, 6);
    Event e5(Event::ARRIVAL, 0);
    BinaryHeap t1 ;
    //cout<<t1.getElementCount()<<endl;
    t1.insert(e1);
    t1.insert(e2);
    t1.insert(e3);
    t1.insert(e4);
    t1.insert(e5);
    //t1.printHeap();
    t1.remove();
    t1.remove();
    t1.remove();
    t1.remove();
    t1.printHeap();
    //Ok, insert is ok!!!!*/
    

}


// g++ -o x -g test_driver.cpp Event.cpp EmptyDataCollectionException.cpp BinaryHeap.cpp

/*30 3
23 2
22 4
20 6*/