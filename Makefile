output: ./src/main.o ./src/app/card.o ./src/app/set.o
	g++ main.o card.o set.o -o output

main.o: ./src/main.cpp
	g++ -c main.cpp

card.o: ./src/app/card.cpp
	g++ -c card.cpp 

set.o: ./src/app/set.cpp
	g++ -c set.cpp

clean:
	rm -f *.o output
