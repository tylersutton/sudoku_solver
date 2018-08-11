#include "sudoku.h"
using namespace std;

int main() {
	Sudoku *sudoku = new Sudoku;
	*sudoku = sudoku->createSudoku();
	sudoku->displaySudoku(sudoku);
	sudoku->solveSudoku(sudoku);
	return 0;
}
