#pragma once
#include<iostream>
//三个结构：数独每个位置的结构体、数独生成器、数独解题器
struct SudokuPos
{
	int x;
	int y;
};
class Generator {
private:
	int game[9][9];
public:
	Generator();
	void init();
	void GenEndgames(int n);
	void GenPuzzle(int n, int m = 1, int r = 20);
	void GenUniPuzzle(int n);
	int GetNum(int i, int j) { return game[i][j]; }
};
class Solver {

};