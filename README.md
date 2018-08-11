# Sudoku Solver

This is a simple sudoku solver written in C++. It takes a partially solved Sudoku puzzle
as input and uses a backtracking algorithm to recursively find the solution. Empty cells
are represented with 0's.

The proper input format is as shown:

0 0 6 0 5 4 9 0 0  
1 0 0 0 6 0 0 4 2  
7 0 0 0 8 9 0 0 0  
0 7 0 0 0 5 0 8 1  
0 5 0 3 4 0 6 0 0  
4 0 2 0 0 0 0 0 0  
0 3 4 0 0 0 1 0 0  
9 0 0 8 0 0 0 5 0  
0 0 0 4 0 0 3 0 7  

The solution of this puzzle outputs as shown:  

2 8 6 | 1 5 4 | 9 7 3   
1 9 5 | 7 6 3 | 8 4 2   
7 4 3 | 2 8 9 | 5 1 6  
\-------------------------    
3 7 9 | 6 2 5 | 4 8 1   
8 5 1 | 3 4 7 | 6 2 9   
4 6 2 | 9 1 8 | 7 3 5   
\-------------------------   
6 3 4 | 5 7 2 | 1 9 8  
9 1 7 | 8 3 6 | 2 5 4  
5 2 8 | 4 9 1 | 3 6 7  


Several sudoku puzzles written in proper input format can be found in "puzzles.txt".  
The puzzle to be solved should be placed in "sudoku.txt".  

