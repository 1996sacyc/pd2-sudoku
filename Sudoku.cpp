#include<string>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include"Sudoku.h"
using namespace std;

void Sudoku::GiveQuestion(void){
     int q[12][12]={0 ,0 ,0 ,-1,-1,-1 ,0 ,0 ,0 ,0 ,2 ,4,
                    0 ,0 ,0 ,-1,-1,-1 ,0 ,0 ,0 ,5 ,8 ,0,
                    0 ,0 ,0 ,-1,-1,-1 ,8 ,7 ,0 ,0 ,0 ,0,
                    0 ,0 ,0 ,0 ,0 ,0,-1,-1,-1 ,0 ,4 ,0,
                    0 ,6 ,5 ,0 ,0 ,0,-1,-1,-1 ,9 ,0 ,3,
                    0 ,0 ,0 ,0 ,7 ,0,-1,-1,-1 ,0 ,0 ,5,
                   -1 ,-1 ,-1 ,0 ,0 ,0 ,0 ,4 ,0 ,0 ,3 ,0,
                   -1 ,-1 ,-1 ,0 ,0 ,2 ,0 ,0 ,9 ,6 ,0 ,0,
                   -1 ,-1 ,-1 ,0 ,1 ,0 ,0 ,6 ,0 ,0 ,0 ,0,
                    0 ,9 ,6 ,0 ,0 ,0 ,0 ,2 ,5,-1,-1,-1,
                    0 ,5 ,4 ,3 ,8 ,0 ,0 ,0 ,6,-1,-1,-1,
                    0 ,3 ,0 ,0 ,0 ,0 ,0 ,8 ,0,-1,-1,-1};
     srand(time(NULL));
     int change=rand()%9;
     int gg[12][12];
     int i;
     int j;
     for(i=0; i<12; i++){
        for(j=0; j<12; j++){
            if(q[i][j]>=1&&q[i][j]<=9){
               if(q[i][j]+change>9){
                  gg[i][j]=(q[i][j]+change)%9+1;
               }
               else{
                   gg[i][j]=q[i][j]+change;
               }
            }
            else{
               gg[i][j]=q[i][j];
            }
        }
     }
     for(i=0; i<12; i++){
        for(j=0; j<12; j++){
        cout<<gg[i][j]<<'\t';
        }
        cout<<endl;
     }
     cout<<endl;
} /*give question*/

void Sudoku::ReadIn(void)
{
	for(int i=0; i<144; i++) {
         cin>>sdku.sudokuAr1[i];
	}
} /*read in*/

void Sudoku::push(int sp){
	   tempNum[tempSp++]= sp; /*把處理過的位置存進去*/
}
	
int Sudoku::pop(){	   
	   if(tempSp<=0) return(-1);
	   else return(tempNum[--tempSp]);  /*回頭找*/
}

unsigned char Sudoku::NumberCheckConflict(int sp){
       int a, m, n, row, col;
	   unsigned char samechk= 0 ;       
       m=sp/12;
	   n=sp%12;
	      
	   for (a=0; a<12; a++){                       
           if (a!=m && sdku.sudokuAr2[m][n]==sdku.sudokuAr2[a][n] ) samechk++;  /*col check*/                      
           if (a!=n && sdku.sudokuAr2[m][n]==sdku.sudokuAr2[m][a] ) samechk++;  /*row check*/          
       }  
       if (!samechk){  
         for (row=((m/3)*3); row<(((m/3)*3)+3); row++){
            for (col=((n/3)*3); col<(((n/3)*3)+3); col++){                                  
                if (row!=m &&  col !=n){
                   if (sdku.sudokuAr2[m][n]==sdku.sudokuAr2[row][col] ) samechk++;
                }
            }
         }
       }
	   return(samechk) ;                /*0 成功, 1 失敗*/
}	

int Sudoku::GetNextBlankForward(int sp){
	   do{
	      sp++ ;
	   } while(sp<144 && sdku.sudokuAr1[sp]!=0);
	   return(sp);  /*從第一個空格開始*/
}

int Sudoku::GetNextBlankBackward(int sp){
	   do{
	      sp-- ;
	   } while(sp>=0 && sdku.sudokuAr1[sp]!=0);
	   return(sp);
}

void Sudoku::TrySolve(int dir){   
	   int sp;
       tempSp=0 ;     
                                              
       if (dir == -1) sp=GetNextBlankForward(-1) ;      /*找零*/
       else           sp=GetNextBlankBackward(144) ; 
       
	   do{
          sdku.sudokuAr1[sp]++ ;                    
	      if(sdku.sudokuAr1[sp]>9){                       
	         sdku.sudokuAr1[sp]= 0 ;
	         sp= pop() ;
	      } 
          else{
	         if(NumberCheckConflict(sp)==0){                      /*表示數字沒有衝突 找下一個空格*/                
	            push(sp) ;                    
                if (dir == -1) sp=GetNextBlankForward(-1) ;        
                else           sp=GetNextBlankBackward(144) ; 
	            
	         }
	      }
	   } while(sp>=0 && sp<144) ;	  
}

unsigned char Sudoku::QuestionPreCheckNG(int s[][12], int m, int n){
     int ocp[10]={0,0,0,0,0,0,0,0,0,0};   /*數字在那一行出現的次數*/
                                     /*ocp[0]是負一的個數*/
     int a, row, col, ocpno;        /*m row n column*/
    
     for (ocpno=0; ocpno<10; ocpno++) ocp[ocpno]=0;
     for (a=0; a<12; a++){        
         if ((s[a][n]>0) && (s[a][n]<10)) ocp[s[a][n]]++;        
         else{
              if (s[a][n]==-1) ocp[0]++;             /*負一的狀況*/     
              else if (s[a][n]!=0)return 1;       /*出問題的狀況*/
         }
     }  
     for (ocpno=1; ocpno<10; ocpno++) if (ocp[ocpno]>1) return 1;  /*某一個數字出現兩次以上*/
     if (ocp[0]!=3) return 1;
     
     for (ocpno=0; ocpno<10; ocpno++) ocp[ocpno]=0;
     for (a=0; a<12; a++){                         
         if ((s[m][a]>0) && (s[m][a]<10)) ocp[s[m][a]]++;        /*row direction check*/
         else{
              if (s[m][a]==-1) ocp[0]++;                 
              else if (s[m][a]!=0)return 1;
         }
     }  
     for (ocpno=1; ocpno<10; ocpno++) if (ocp[ocpno]>1) return 1;
     if (ocp[0]!=3) return 1; 
        
     
     for (ocpno=0; ocpno<10; ocpno++) ocp[ocpno]=0;
     if (s[m][n]!=-1){
        for (row=((m/3)*3); row<(((m/3)*3)+3); row++){
           for (col=((n/3)*3); col<(((n/3)*3)+3); col++){                                  
               if ((s[row][col]>0) && (s[row][col]<10)) ocp[s[row][col]]++;  /*Grid check*/  
           }
        }
     }
     for (ocpno=1; ocpno<10; ocpno++) if (ocp[ocpno]>1) return 1;  
     return 0;   
}

void Sudoku::Solve(void){
     int a,b, i;
     unsigned int SolutionCount;
     unsigned int BlankCount;
     int solutiontemp[144];
     int questiontemp[144];
      
     for (a=0; a<12; a++){
         for (b=0; b<12; b++){     
            if (QuestionPreCheckNG(sdku.sudokuAr2, a,b))  {                                  
               cout<<"0"<<endl;            /*無解 離開*/
               return;
            }
         }
     }
             
     BlankCount=0;
     for (i=0; i<144; i++) questiontemp[i]=sdku.sudokuAr1[i];   
     TrySolve(-1) ;              /*用從一到九的順序去解決題目*/
         
     for (i=0; i<144; i++){           
         solutiontemp[i]=sdku.sudokuAr1[i];
         if (sdku.sudokuAr1[i]==0) BlankCount++;
     }         /*相反的順序*/
    
     if (BlankCount!=0) SolutionCount=0;     /*無解*/
     else{
         for (i=0; i<144; i++) sdku.sudokuAr1[i]=questiontemp[i];
         TrySolve(144);               /*從後面開始解*/
                    
         SolutionCount=1;           /*先假設唯一解的狀況*/
         for (i=0; i<144; i++){
             if (sdku.sudokuAr1[i]!=solutiontemp[i]){                                                                            
                 SolutionCount=2;    /*有不相同的狀況就是多重解*/
                 i=144; /*終止條件*/
             }
         }
     }
              
     if (SolutionCount==1){             /*唯一解*/
         cout<<"1"<<endl;
         for (a=0; a<12; a++){
             for (b=0; b<12; b++){
                 cout<<sdku.sudokuAr2[a][b];
                 if (b==11) cout<<endl;
                 else cout<<" ";
             }
         }
     } 
     else cout<<SolutionCount<<endl;       
   
     /*return 0;*/
}
