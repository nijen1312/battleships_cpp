
all :
	g++ -w main.cpp Menu.cpp Game.cpp Fleet.cpp Board.cpp AuxBox.cpp Ship.cpp Destroyer.cpp Patrol.cpp Submarine.cpp Cruiser.cpp -o battleships -lncurses -lmenu
