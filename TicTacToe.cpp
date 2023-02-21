#include<bits/stdc++.h>
using namespace std;

// win loos draw checker
int win(vector<vector<char>>&mat, int x, int y , int cnt)
{
    
    
    
    char var = mat[x][y];
    
    // check horizontal
    if(mat[x][0] == var && mat[x][1] == var && mat[x][2]==var)
    {
        if(var == 'X')
          return 1;
          
        return 2;  
    }
    // check vertical
    if(mat[0][y] == var && mat[1][y] == var && mat[2][y]==var)
    {
        if(var == 'X')
          return 1;
          
        return 2;  
    }
    
    // check main diogonal
    
    if(x==y)
    {
        if(mat[0][0] == var && mat[1][1] == var && mat[2][1]==var)
        {
        if(var == 'X')
          return 1;
          
        return 2;  
       }
    }
    
    // check secondary dioganal
    if(x==y || (x= 0 && y == 2) || (x==2 && y==0))
    {
       if(mat[0][2] == var && mat[1][1] == var && mat[2][0]==var)
        {
        if(var == 'X')
          return 1;
          
        return 2;  
       } 
    }
    // if mat is full and no one wins
    if(cnt == 9 )
    return 3;
    
    return 0;
}


//Function to print the current status of matrix
void print( vector<vector<char>>&matrix){
    cout<<endl;
    
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<3;col++)
        {
            cout<<matrix[row][col]<<"\t";
        }cout<<endl;
    }
    
}

int main()
{
    cout<<" TIC TAC TOE : \n";
    string player1, player2,step;
    bool start = 1;
    cout<<"Enter player1 name ( X ) : "; cin>>player1;
    cout<<"\nEnter Payer2 name ( O ): ";cin>>player2;
    cout<<"Hello "<<player1<<" & "<<player2<<", Welcome to Our game\n";
    
    cout<<"Who is going to step 1 : ";cin>>step;
    if(step == player2)
    start = 0;
    
    vector<vector<char>>matrix(3,vector<char>(3,'.'));
    print(matrix);
    
    
       
    int move_count =0;      
    while(1)
    {
        if(start ==1)
          cout<<"\n"<<player1<<" is your move : ";
        else 
         cout<<"\n"<<player2<<" is your move : ";
         
         
        int x , y;
        cout<<"\n Entner the index of row and column : (x,y)  : "; cin >> x >> y ;
        
        if(start == 1)
        {
           matrix[x][y] = 'X'; 
           start = 0;
        }else{
            matrix[x][y] = 'O';
            start = 1;
        }
        move_count++;
        
        print(matrix);
        
        int who = win(matrix,x,y,move_count);
        if(who == 1) {cout<<"\n"<<player1<<" Won the match🎉"; break;}
        else if(who == 2) {cout<<"\n"<<player2<<" Won the match🎉"; break;}
        else if(who == 3) {cout<<"\n"<<"Match Draws😒"; break;}
  
    }
    
    return 0;
    
}
