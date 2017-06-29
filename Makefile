all: matrix-driver

matrix.o: matrix.cpp matrix.h
	g++ -c -std=c++11 matrix.cpp

matrix-driver.o: matrix-driver.cpp matrix.h matrix.o
	g++ -c -std=c++11 matrix-driver.cpp

matrix-driver: matrix-driver.o matrix.o 
	g++ -o matrix-driver matrix-driver.o matrix.o

clean:
	rm matrix-driver matrix-driver.o matrix.o





