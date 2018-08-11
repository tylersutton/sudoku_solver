
class Cell {
	public:
		//stores 1-9 value of cell
		int val;
		//marks initially filled cells
		bool in;

};

class Sudoku {
	public:
		Cell cell[81];
		Sudoku createSudoku();
		void updateSudoku();
		void displaySudoku(Sudoku *sudoku);
		int findEmpty(Sudoku *sudoku);
		bool solveSudoku(Sudoku *sudoku);
		bool isValid(Sudoku *sudoku);
		bool isSolved(Sudoku *sudoku);
		Sudoku() {

		}
};

