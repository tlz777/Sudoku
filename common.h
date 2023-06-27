#pragma once
#include<iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
//三个结构：数独每个位置的结构体、数独生成器、数独解题器
struct SudokuPos
{
	int x;
	int y;
};
class Generator {
private:
    vector<vector<int>>game;
public:
	Generator();
	bool GenEndgames(int n);                        //生成终局
	void GenPuzzle(int n, int m, int r_input);   //生成问题
	void GenUniPuzzle(int n);                       //生成具有唯一解的问题
    void print();                                   //打印结果
    void DigHoles(vector<int>& randomlist, int n);  //生成唯一解所用的挖洞递归函数
    void DigHoles(vector<int>& randomlist,int n,int x);              //随机挖洞生成数独
    int CheckSolve(vector<vector<int>>& pz, int n, int Nof_solution);//检查是否只有解
	int GetNum(int i, int j) { return game[i][j]; }
};
class Solver {

};
set<int> PossibleValueAtPosition(vector<vector<int>>& pz, int row, int col) {
    //计算某个位置的可填写的数字
    int r = row / 3 * 3;
    int c = col / 3 * 3;
    set<int> possible_values{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (int i = r; i < r + 3; i++) {
        for (int j = c; j < c + 3; j++) {
            possible_values.erase(pz[i][j]);
        }
    }
    for (int i = 0; i < 9; i++) {
        possible_values.erase(pz[row][i]);
        possible_values.erase(pz[i][col]);
    }
    return possible_values;
}

