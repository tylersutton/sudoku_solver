#include "sudoku.h"
using namespace std;

int main() {
	Sudoku *sudoku = new Sudoku;
	*sudoku = sudoku->createSudoku();
	//cout << sudoku->cell[2].val << endl;
	sudoku->displaySudoku(sudoku);
	sudoku->solveSudoku(sudoku);
	
	//sudoku->isValid(sudoku);
	return 0;
}
