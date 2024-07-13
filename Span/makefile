span: main.o span.o
	g++ main.o span.o -o span

main.o: main.cpp span.h
	g++ -c main.cpp

span.o: span.cpp span.h
	g++ -c span.cpp

clean:
	rm *.o
	rm span

run: span
	./span
