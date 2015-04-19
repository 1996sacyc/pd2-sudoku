#include<iostream>
#include<string>  
#include<cstdlib>                                          
#include <iostream> 
class Sudoku
{
	public:
		Sudoku();
	void GiveQuestion(void);
	void ReadIn(void);
	void Solve(void);
        union UnionSudoku
        void push(int sp);
        int pop();
        unsigned char NumberCheckConflict(int sp);
        int GetNextBlankForward(int sp);
        int GetNextBlankBackward(int sp);
        void TrySolve(int dir);
        unsigned char QuestionPreCheckNG(int s[][12], int m, int n);
};

