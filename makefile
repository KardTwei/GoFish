# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary.

final: card_demo.o player.o deck.o card.o
	g++ -o goFish card_demo.o player.o deck.o card.o

driver: card_demo.cpp player.h deck.h card.h
	g++ -c card_demo.cpp

player.o: player.cpp player.h deck.h card.h
	g++ -c player.cpp

deck.o: deck.cpp deck.h card.h
	g++ -c deck.cpp

card.o: card.cpp card.h
	g++ -c card.cpp
