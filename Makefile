libsrc.a: Bot.o Map.o
	ar cr $@ $^

Bot.o: biblioteka/src/Bot.cpp biblioteka/includes/Bot.hpp
	g++ -c biblioteka/src/Bot.cpp

Map.o: biblioteka/src/Map.cpp biblioteka/includes/Map.hpp
	g++ -c biblioteka/src/Map.cpp

clean:
	rm -rf libsrc.a *.o