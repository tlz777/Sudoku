#ifndef COMMON_H
#define COMMON_H
#include<iostream>
#include <vector>
#include <set>
#include<fstream>
#include <algorithm>
#include <numeric>
using namespace std;
//�����ṹ������ÿ��λ�õĽṹ�塢����������������������
struct SudokuPos
{
	int row;
	int col;
	int* res;//��λ�ÿ���д������
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
};
class Solver {
private:
	int game[9][9];
public:
	Solver(int**);									//���캯��������������puzzle
	bool WriteAnswer();								//�����д��ͬĿ¼�µ�answer.txt
	SudokuPos* FindMinBlank();						//�ҵ����п����������ָ������ٵı��
	int* PossibleValueAtPosition(int r, int c);		//����ĳ��λ�ÿ���д������
	void SolvePuzzle();								//�����������
	void print();                                   //��ӡ���
};
#endif