#include<iostream>
#include<cmath>
using namespace std;


// [i][j] 에 no 를 넣는 것이 가능한지 조사
bool isSafe(int mat[][9],int i,int j,int no){
	//Check for row and col
	for(int k=0;k<9;k++){
		if(mat[k][j]==no||mat[i][k]==no){
			return false;
		}
	}
	//check for subgrid, 해당 칸이 속하는 작은 사각형을 조사
	int sx = (i/3)*3;
	int sy = (j/3)*3;
	for(int x=sx; x<sx + 3;x++){
		for(int y =sy;y<sy + 3;y++){
			if(mat[x][y]==no){
				return false;
			}
		}
	}
	return true;
}


bool solveSudoku(int mat[][9],int i,int j,int n){
	//base case, 주어진 스도쿠 판 row 를 넘어갔다 => 그 이전을 다 풀었다
	if(i==n){
		//print the solution later
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}
		return true;
	}


	//rec case
	if(j==n){ // 세로 경계를 벗어났다면 => 다음 줄로 넘기고
		return solveSudoku(mat,i+1,0,n);
	}
	//skip  the prefilled cell, 이미 채워진 칸이라면 다음 칸으로 넘기고
	if(mat[i][j]!=0){
		return solveSudoku(mat,i,j+1,n);
	}

	//cell to be filled
	//try out all possibilites
	for(int no=1;no<=n;no++){ // 해당 칸에 모든 숫자를 넣어본다
		//whether it is safe to place the number or not
		if(isSafe(mat,i,j,no)){ // 넣을 수 있는 지 확인하고
			mat[i][j] = no; // 넣는다 => 이번 단계 작업
			bool solveSubproblem = solveSudoku(mat,i,j+1,n); // 이후 다음 칸부터 스도쿠를 채우는 작업 = sub problem
			if(solveSubproblem==true){
				return true;
			}
		}
	}
	// if no option works, backtracking
	// 이번 칸에서 모든 숫자를 넣는 것이 실패한 경우
	// 다시 0 을 넣어준다 => 사용하기 이전 상태로 복귀
	mat[i][j] = 0;
	return false; // 실패함을 알림
}


int main(){
	int n = 9;
	int mat[9][9] =
        {{5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}};

        if(!solveSudoku(mat,0,0,n)){
        	cout<<"No solution exists!";
        }
}