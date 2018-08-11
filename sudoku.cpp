#include <iostream>
#include <fstream>
#include "sudoku.h"
using namespace std;

Sudoku Sudoku::createSudoku() {
	Sudoku *board = new Sudoku;
	//initialize cells to 0 (empty)
	ifstream file;
	file.open("sudoku.txt");
	if (!file) {
		cerr << "Unable to open file sudoku.txt";
		exit(1);
	}
	for (int i = 0; i < 81; i++) {
		file >> board->cell[i].val;
	}
	return *board;
}

bool Sudoku::solveSudoku(Sudoku *sudoku) {
	if (sudoku->isSolved(sudoku) == true) {
		//cout << "whoops" << endl;
		return true;
	}
	int n = findEmpty(sudoku);
	for (int x = 1; x <= 9; x++) {
		if (sudoku->cell[n].in == false) {
			sudoku->cell[n].val = x;
		}
		//cout << "cell [" << n << "] = " << x << endl;
		if (sudoku->isValid(sudoku)) {
			//system("clear");
			//sudoku->displaySudoku(sudoku);			
			if (sudoku->solveSudoku(sudoku) == true) {
				return true;
			}
		}
	}
	if (sudoku->cell[n].in == false) {
		sudoku->cell[n].val = 0;
	}
	return false;
}

bool Sudoku::isValid(Sudoku *sudoku) {
	//checks rows & columns
	for (int i = 0; i < 9; i++) {
		int A[10] = {0,0,0,0,0,0,0,0,0,0};
		int B[10] = {0,0,0,0,0,0,0,0,0,0};
		for (int j = 0; j < 9; j++) {
			int x = sudoku->cell[(9*i)+j].val;
			int y = sudoku->cell[(9*j)+i].val;
			A[x] += 1;
			B[y] += 1;
			if (x < 0 || x > 9) {
				cout << "invalid number: out of bounds" << endl;
				return 0;
			}
		}
		for (int k = 0; k < 9; k++) {
			if (A[k+1] > 1) {
				//cout << "invalid row" << endl;
				return 0;
			}
			if (B[k+1] > 1) {
				//cout << "invalid column" << endl;
				return 0;
			}
		}
	}
	//checks boxes
	for (int l = 0; l < 3; l++) {
		for (int k = 0; k < 3; k++) {
			int A[10] = {0,0,0,0,0,0,0,0,0,0};
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					int x = sudoku->cell[(9*i)+j+(3*k)+(27*l)].val;
					A[x] += 1;
				}
			}
			for (int b = 0; b < 9; b++) {
				if (A[b+1] > 1) {
					//cout << "invalid box" << endl;
					return 0;
				}
			}
		}
	}
	//cout << "valid" << endl;
	return 1;
}

bool Sudoku::isSolved(Sudoku *sudoku) {
	for (int i = 0; i < 81; i++) {
		if (sudoku->cell[i].val == 0) {
			return false;
		}
	}
	if (sudoku->isValid(sudoku) == false) {
		return false;
	}
	else {
		sudoku->displaySudoku(sudoku);
		return true;
	}
}

void Sudoku::displaySudoku(Sudoku *sudoku) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sudoku->cell[(9*i)+j].val == 0) {
				cout << "  ";
			}
			else {
				cout << sudoku->cell[(9*i)+j].val << " ";
			}
			if (((j+1) % 3 == 0) && (j != 0) && (j != 8)) {
				cout << "| ";
			}
			else if (j == 8) {
				cout << endl;
			}
		}
		if (((i + 1) % 3 == 0) && (i != 0) && (i != 8)) {
			cout << "---------------------" << endl;
		}
		if (i == 8) {
			cout << endl << endl << endl;
		}
	}
}

int Sudoku::findEmpty(Sudoku *sudoku) {
	for (int n = 0; n < 81; n++) {
		if (sudoku->cell[n].val == 0) {
			return n;
		}
	}
}