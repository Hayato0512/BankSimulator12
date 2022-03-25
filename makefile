all: PQ

PQ: Event.o EmptyDataCollectionException.o BinaryHeap.h PriorityQueue.h Queue.h test_driver.o 
	g++ -Wall -g -o PQ test_driver.o Event.o  EmptyDataCollectionException.o -std=c++0x

test_driver.o: test_driver.cpp
	g++ -Wall -g -c test_driver.cpp -std=c++0x
		
Event.o: Event.h Event.cpp
	g++ -Wall -g -c Event.cpp -std=c++0x
		
EmptyDataCollectionException.o: EmptyDataCollectionException.h EmptyDataCollectionException.cpp
	g++ -Wall -g -c EmptyDataCollectionException.cpp -std=c++0x

clean:
	rm -f PQ *.o