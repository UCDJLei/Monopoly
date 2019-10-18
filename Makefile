hoarding.out: main.o GameState.o CSVReader.o Space.o Board.o SpaceType.o Go.o Property.o Rules.o Utility.o DiceRoller.o Player.o Move.o
	g++ -g -std=c++14 -Wall -Werror -o hoarding.out main.o GameState.o CSVReader.o Space.o Board.o SpaceType.o Go.o Property.o Rules.o Utility.o DiceRoller.o Player.o Move.o
main.o: main.cpp GameState.h Utility.h
	g++ -g -std=c++14 -Wall -Werror -c main.cpp

Board.o: Board.cpp CSVReader.h Board.h
	g++ -g -std=c++14 -Wall -Werror -c Board.cpp

CSVReader.o: CSVReader.cpp 
	g++ -g -std=c++14 -Wall -Werror -c CSVReader.cpp

DiceRoller.o: DiceRoller.cpp DiceRoller.h CSVReader.h
	g++ -g -std=c++14 -Wall -Werror -c DiceRoller.cpp

GameState.o: GameState.cpp GameState.h 
	g++ -g -std=c++14 -Wall -Werror -c GameState.cpp

Go.o: Go.cpp Go.h 
	g++ -g -std=c++14 -Wall -Werror -c Go.cpp


Move.o: Move.cpp Move.h
	g++ -g -std=c++14 -Wall -Werror -c Move.cpp

Player.o: Player.cpp Player.h
	g++ -g -std=c++14 -Wall -Werror -c Player.cpp

Property.o: Property.cpp Property.h
	g++ -g -std=c++14 -Wall -Werror -c Property.cpp

Rules.o: Rules.cpp Rules.h CSVReader.h Utility.h
	g++ -g -std=c++14 -Wall -Werror -c Rules.cpp 

Space.o: Space.cpp Space.h 
	g++ -g -std=c++14 -Wall -Werror -c Space.cpp 

SpaceType.o: SpaceType.cpp SpaceType.h Space.h 
	g++ -g -std=c++14 -Wall -Werror -c SpaceType.cpp

Utility.o: Utility.cpp Utility.h
	g++ -g -std=c++14 -Wall -Werror -c Utility.cpp





clean:
	rm -f *.o* .out
