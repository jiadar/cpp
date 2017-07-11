all: driver

sparse_matrix.o: sparse_matrix.cpp matrix.h
	g++ -c -std=c++11 sparse_matrix.cpp

driver.o: driver.cpp matrix.h sparse_matrix.o
	g++ -c -std=c++11 driver.cpp

driver: driver.o sparse_matrix.o 
	g++ -o driver driver.o sparse_matrix.o 

clean:
	rm driver *.o






