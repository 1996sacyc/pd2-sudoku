#include<iostream>
#include<string>  
#include<cstdlib>                                          
#include <iostream> 

class Sudoku{
	public:
		void GiveQuestion(void);
		void ReadIn(void);
		void Solve(void);
        union UnionSudoku{
        int sudokuAr1[144];
        int sudokuAr2[12][12];       
        } 
        sdku; 
        void push(int sp);
        int pop();
        unsigned char NumberCheckConflict(int sp);
        int GetNextBlankForward(int sp);
        int GetNextBlankBackward(int sp);
        void TrySolve(int dir);
        unsigned char QuestionPreCheckNG(int s[][12], int m, int n);
        int sdkqs[5][144];                 
        int tempNum[144] ;                               
        int tempSp; 
};
