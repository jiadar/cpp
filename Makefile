all: matrix-driver

matrix.o: matrix.cpp matrix.h
	g++ -c matrix.cpp

matrix-driver.o: matrix-driver.cpp matrix.h matrix.o
	g++ -c matrix-driver.cpp

matrix-driver: matrix-driver.o matrix.o 
	g++ -o matrix-driver matrix-driver.o matrix.o

clean:
	rm matrix-driver.o matrix.o





