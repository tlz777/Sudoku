#ifndef COMMON_H
#define COMMON_H
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
    void init();                                    //�ָ�game����ȫΪ0
	void GenPuzzle(int m, int r_input);      //��������
	void GenUniPuzzle();                       //���ɾ���Ψһ�������
    void print();                                   //��ӡ���
    void DigHoles(vector<int>& randomlist, int n);  //����Ψһ�����õ��ڶ��ݹ麯��
    void DigHoles(vector<int>& randomlist,int n,int x);              //����ڶ���������
    int CheckSolve(vector<vector<int>>& pz, int n, int Nof_solution);//����Ƿ�ֻ�н�
	int GetNum(int i, int j) { return game[i][j]; }
};
class Solver {

};

#endif