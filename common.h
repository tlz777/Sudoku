#ifndef COMMON_H
#define COMMON_H
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
    void init();                                    //恢复game矩阵全为0
	void GenPuzzle(int m, int r_input);      //生成问题
	void GenUniPuzzle();                       //生成具有唯一解的问题
    void print();                                   //打印结果
    void DigHoles(vector<int>& randomlist, int n);  //生成唯一解所用的挖洞递归函数
    void DigHoles(vector<int>& randomlist,int n,int x);              //随机挖洞生成数独
    int CheckSolve(vector<vector<int>>& pz, int n, int Nof_solution);//检查是否只有解
	int GetNum(int i, int j) { return game[i][j]; }
};
class Solver {

};

#endif