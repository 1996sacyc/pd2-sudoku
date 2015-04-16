#include<string>
#include<vector>
#include<cstdlib>
#include<ctime>
#include"Sudoku"
using namespace std;         

void Sudoku::GiveQuestion(){
     int q[12][12]={4,2,6,8,7,3,9,5,1,-1,-1,-1,
               0,0,3,9,5,0,6,0,4,-1,-1,-1,
               9,0,1,6,2,4,8,0,0,-1,-1,-1,
               -1,-1,-1,1,3,2,0,8,7,9,5,6,
               -1,-1,-1,0,8,0,1,9,0,4,2,0,
               -1,-1,-1,4,9,6,2,3,0,8,7,1,
               1,0,0,0,4,0,-1,-1,-1,6,9,5,
               0,0,4,0,6,0,-1,-1,-1,1,3,7,
               6,9,5,0,1,7,-1,-1,-1,2,8,4,
               3,1,2,-1,-1,-1,7,4,0,5,0,9,
               7,4,8,-1,-1,-1,0,6,9,3,0,2,
               0,6,0,-1,-1,-1,3,1,0,7,0,8,};
    srand(time(NULL));
    int level=rand()%3
    switch(level){
           case 0 
           int x1=rand()%8;       
           for(i=0; i<12; i++){
               for(k=0; k<12; k++){
                   if(q[i][k]==0||q[i][k]==-1){
                   return a[i][k];
                   }
                   else if(1<=q[i][k]||q[i][k]<=(9-change)){
                   q[i][k]=q[i][k]+(change);
                   }
                   else if(q[i][k]>=(10-change)){
                   q[i][k]=q[i][k]-(9-change);
                   }
               }
           }
    break;
      
    }             

    for(i=0; i<12; i++){
        for(k=0; k<12; k++){
            cout<<q[i][k];
        }     
    }
    cout<<endl;                                                
}              

void Sudoku::ReadIn(){
     int a[144];
     for(i=0; i<144; i++){
         cin>>a[i];
     }
     return a;
} 

void Sudoku::Solve(a[]){
     int checkC[144]; /*column*/
     int checkR[144]; /*row*/
     int checkB[144]; /*block*/
     
     for(i=0; i<144; i++){
         checkC[i]=a[i]; /*設定column(橫列)*/
         checkR[i]=a[12i-11]; /*row直行*/
         checkB[i]=a[i%3+12*(i/3)]; /*block格子*/ 
     }
     
     int findzero(int location){
         if(a[location]==0){
            location=location+1;
         }
         return location;                    
     } /*找0的地方*/
     
     int check(int location){
         int x=location/12;
         for(k=12x; k<12x+12; k++){
             if(a[location]==checkC[k]){
             a[location]++;
             return a[location];
             }
             else{
             break;
             }      
         }
         
         int y=location%12;
         for(k=y; k<y+12; k++){
             if(a[location]==checkR[y]){
             a[location]++;
             return a[location];      
             }
             else{
             break;
             }
         }
         
         int z=(location%12)/3;
         for(k=z*12; k<12z+12; k++){
             if(a[location]==checkB[k]){
             a[location]++;
             return a[location];
             }
             else{
             break;
             }
         }
         return a[location];        
     }             
     
     int calculate{
         int location=findzero(0); /*找0的地方*/
         while(a[location]<10){         
               a[location]++; /*從零開始加*/ 
               int origin=a[location]; /*待會去檢查a[location]有沒有改變的變數*/
               int a[location]=check(location); 
               int(a[location]==9&&){
          
	       if(origin==a[location]){
                  location=findzero(location);
                  calculate();
               } /*代表找到正確答案繼續找下一個零個位置*/
         }         
     }
     
     for(i=0; i<144; i++){
         cout<<a[i]<<'\t';    
         if(i%11==0){
            cout<<endl;
         }/*印出最終解出的東西 12個一行*/
     }
     cout<<endl;
}                                           
