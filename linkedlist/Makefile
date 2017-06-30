all: driver

linkedlist.o: linkedlist.cpp linkedlist.h
	g++ -c -std=c++11 linkedlist.cpp

driver.o: driver.cpp linkedlist.h linkedlist.o
	g++ -c -std=c++11 driver.cpp

driver: driver.o linkedlist.o 
	g++ -o driver driver.o linkedlist.o

clean:
	rm driver *.o





