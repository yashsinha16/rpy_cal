all:sensortest-class

sensortest-class:main.o fun.o header.o
	g++ $^ -o $@
fun.o: fun.cpp fun.h
	g++ fun.cpp -c
header.o: header.cpp header.h
	g++ header.cpp -c
main.o: main.cpp header.h fun.h
	g++ main.cpp -c
clean:
	rm -rf *.o sensortest-class
run:
	./sensortest-class