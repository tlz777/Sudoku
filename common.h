#pragma once
#include<iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
//�����ṹ������ÿ��λ�õĽṹ�塢����������������������
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
	bool GenEndgames(int n);                        //�����վ�
	void GenPuzzle(int n, int m, int r_input);   //��������
	void GenUniPuzzle(int n);                       //���ɾ���Ψһ�������
    void print();                                   //��ӡ���
    void DigHoles(vector<int>& randomlist, int n);  //����Ψһ�����õ��ڶ��ݹ麯��
    void DigHoles(vector<int>& randomlist,int n,int x);              //����ڶ���������
    int CheckSolve(vector<vector<int>>& pz, int n, int Nof_solution);//����Ƿ�ֻ�н�
	int GetNum(int i, int j) { return game[i][j]; }
};
class Solver {

};
set<int> PossibleValueAtPosition(vector<vector<int>>& pz, int row, int col) {
    //����ĳ��λ�õĿ���д������
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

