Dungeon: main.o Entity.o Player.o Fighter.o Sorcerer.o Monster.o Dragon.o Goblin.o Room.o Game.o
	g++ -g main.o Entity.o Player.o Fighter.o Sorcerer.o Monster.o Dragon.o Goblin.o Room.o Game.o -o Dungeon

Entity.o : Entity.h Entity.cpp
	g++ -g -c Entity.cpp

Player.o : Entity.h Player.h Player.cpp
	g++ -g -c Player.cpp

Fighter.o : Player.h Fighter.h Fighter.cpp
	g++ -g -c Fighter.cpp

Sorcerer.o : Player.h Sorcerer.h Sorcerer.cpp
	g++ -g -c Sorcerer.cpp

Monster.o : Entity.h Monster.h Monster.cpp
	g++ -g -c Monster.cpp

Dragon.o: Monster.h Player.h Dragon.h Dragon.cpp
	g++ -g -c Dragon.cpp

Goblin.o: Monster.h Player.h Goblin.h Goblin.cpp
	g++ -g -c Goblin.cpp

Room.o: Entity.h Room.h Room.cpp Dragon.h Goblin.h
	g++ -g -c Room.cpp

Game.o: Entity.h Room.h Game.h Game.cpp
	g++ -g -c Game.cpp

main.o:  Fighter.h Sorcerer.h Room.h Game.h main.cpp
	g++ -g -c main.cpp

clean:
	rm -f *.o Dungeon

