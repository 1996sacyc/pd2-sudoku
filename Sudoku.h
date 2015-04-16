#include<iostream>
#include<string>  
#include<cstdlib>                                          
using namespace std;

class Sudoku{
    public:
    int a[144];
    void GiveQuestion();
    void ReadIn();	
    void Solve(int a);    
};

