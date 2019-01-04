#include "TextDisplay.h"
#include "Cell.h"
#include <vector>
class Info;
using namespace std;

TextDisplay::TextDisplay(vector<vector<Cell *>> &theBoard ):theBoard{theBoard}{}

TextDisplay::~TextDisplay(){
}

ostream &operator<<(ostream &out, const TextDisplay &td){
	int len = td.theBoard.size();
	int width = td.theBoard[0].size();
	for (int i = 0; i < len; ++i){
		for (int j = 0; j < width ; ++j){
			out << td.theBoard[i][j]->getInfo().display;
		}
		out << endl;
	}
	out << ActionDisplay::setAction();
	ActionDisplay::clearAction();
	return out;
}
