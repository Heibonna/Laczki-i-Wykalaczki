all : Game ;
Game : main.o Character.o City.o Armor.o Weapon.o
	c++ -o "Laczki i Wykalaczki" main.o Character.o City.o Armor.o Weapon.o
Game.o : Game.cpp
	c++ -c Game.cpp
clean :
	rm -f *.o

