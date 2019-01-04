CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -g -MMD -Werror=vla
EXEC = dungeon_crawler

OBJECTS = main.o Potion.o Treasure.o ActionDisplay.o Decorator.o PH.o RH.o BA.o WA.o BD.o WD.o Subject.o TextDisplay.o Cell.o Wall.o Passage.o Doorway.o FloorTile.o Floor.o Shade.o Human.o EmptyCell.o  Enemy.o Character.o PC.o Vampire.o Drow.o Dwarf.o Troll.o Goblin.o Elf.o Merchant.o Halfling.o generateEnemy.o Orc.o generateItem.o DHoard.o Dragon.o Item.cc

DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
