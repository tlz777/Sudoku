#pragma once
#include<iostream>
//�����ṹ������ÿ��λ�õĽṹ�塢����������������������
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