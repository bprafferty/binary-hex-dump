
xbd: xbd.o 
	g++ xbd.o -o xbd

xbd.o: xbd.cpp 
	g++ -c xbd.cpp

clean: 
	rm *.o xbd