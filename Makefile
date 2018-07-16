lukasz.out: main.o Bot.o Map.o Status.o
	g++ -O2 $^ -o $@

main.o: main.cpp Bot.o Map.o Status.o
	g++ -c -g main.cpp

Status.o: biblioteka/src/Status.cpp biblioteka/includes/Status.hpp
	g++ -c biblioteka/src/Status.cpp

Bot.o: biblioteka/src/Bot.cpp biblioteka/includes/Bot.hpp
	g++ -c -g biblioteka/src/Bot.cpp

Map.o: biblioteka/src/Map.cpp biblioteka/includes/Map.hpp
	g++ -c -g biblioteka/src/Map.cpp

clean:
	rm -rf *.o *.out