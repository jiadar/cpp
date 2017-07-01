all: driver

sparse_helper.o: sparse_helper.cpp matrix.h sparse_helper.h
	g++ -c -std=c++11 sparse_helper.cpp

sparse_matrix.o: sparse_helper.cpp sparse_helper.h sparse_matrix.cpp matrix.h
	g++ -c -std=c++11 sparse_matrix.cpp

driver.o: driver.cpp matrix.h sparse_matrix.o
	g++ -c -std=c++11 driver.cpp

driver: driver.o sparse_matrix.o sparse_helper.o
	g++ -o driver driver.o sparse_matrix.o sparse_helper.o

clean:
	rm driver *.o






