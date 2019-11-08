final: go_fish.o player.o deck.o card.o
	g++ -otest  go_fish.o player.o deck.o card.o
driver: go_fish.cpp card.h deck.h player.h
	g++ go_fish.cpp
player.o: player.cpp player.h card.h
	g++ player.cpp
deck.o: deck.cpp deck.h card.h
	g++ deck.cpp
card.o: card.cpp card.o
    g++ card.cpp