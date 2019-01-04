#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <vector>
#include <iostream>
#include "ActionDisplay.h"
class Cell;

class TextDisplay{
		std::vector<std::vector<Cell*>> &theBoard;
		// ActionDisplay &action;

	public:
		TextDisplay(std::vector<std::vector<Cell *>> &theBoard);
		
		~TextDisplay();
		friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
