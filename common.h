#ifndef COMMON_H
#define COMMON_H
#include<iostream>
#include <vector>
#include <set>
#include<fstream>
#include <algorithm>
#include <numeric>
using namespace std;
//三个结构：数独每个位置的结构体、数独生成器、数独解题器
struct SudokuPos
{
	int row;
	int col;
	int* res;//该位置可填写的数据
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
};
class Solver {
private:
	int game[9][9];
public:
	Solver(int**);									//构造函数，传入待解决的puzzle
	bool WriteAnswer();								//将结果写到同目录下的answer.txt
	SudokuPos* FindMinBlank();						//找到其中可以填充的数字个数最少的表格
	int* PossibleValueAtPosition(int r, int c);		//计算某个位置可填写的数字
	void SolvePuzzle();								//整体求解流程
	void print();                                   //打印结果
};
#endif