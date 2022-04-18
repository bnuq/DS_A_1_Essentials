#include<iostream>
#include<vector>
using namespace std;


/* 
	Longest Common Substring problem
	두 문자열에서, 가장 긴 부분 문자열을 찾는 것
 */
// Top Down
int lcsTopDown(string s1,string s2,int i,int j,vector<vector<int> > &dp)
{
	
	// base case
	// 검색하는 한쪽 문자열의 끝에 도착함, 더이상 검색할 문자가 없다
	if(i==s1.length() or j==s2.length()){
		return  0;
	}

	// check if a state is already computed
	if(dp[i][j]! = -1){
		return dp[i][j];
	}

	// rec case
	if(s1[i]==s2[j]) // 문자가 같으면
	{
		// lcs 길이를 저장
		// 일단 지금 문자가 같으니 1개 추가되고
		// 뒤에서 어떤 sub string 이 같은 게 나올 수 있으니, 그 길이까지 더해서 저장해라
		// sub string 이 같은 지 조사를, 각 문자열의 끝에서 -> 앞 쪽 방향으로 조사한다
		return dp[i][j] = 1 + lcs(s1,s2,i+1,j+1,dp);
	}


	// 문자가 다르면, 각 문자열에서 조사
	int op1 = lcs(s1,s2,i+1,j,dp);	// s1 에서 이 문자 제외하고 
	int op2 = lcs(s1,s2,i,j+1,dp);	// s2 에서 이 문자 제외하고
	return dp[i][j] = max(op1,op2);	// 둘 중에 큰거 사용
}



// Bottom UP 방식 조사
int lcsBottomUp(string s1,string s2)
{
	//bottom up approach to lcs
	int n1 = s1.length();
	int n2 = s2.length();

	//2d dp array
	vector<vector<int > > dp(n1 + 1, vector<int>(n2+1,0));

	//1,1 ... n1,n2
	// 각 문자열의 첫번째 문자에서 부터 시작
	for(int i=1;i<=n1;i++){
		for(int j=1;j<=n2;j++){

			// 문자가 같으면
			if(s1[i-1]==s2[j-1]){
				// 그전까지 조사한 값에 1을 더해 추가
				// sub string 이 같은 지를 문자열 앞에서부터 -> 뒤로 조사
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				// 문자가 다르면 그 이전에 조사한 최대 값 중 하나를 가져온다
				int op1 = dp[i-1][j];
				int op2 = dp[i][j-1];
				dp[i][j] = max(op1,op2);
			}
		}
	}

	//print
	/*
	for(int i=0;i<=n1;i++){
		for(int j=0;j<=n2;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	*/

	vector<char> result;
	int i=n1,j=n2;

	/* 
		dp[i][j]
			s1 에서는 i 번째 까지 문자 범위와
			s2 에서는 j 번째 까지 문자 범위에서
			sub string 이 존재할 때
			가장 긴 문자열 길이를 저장
	 */

	// 각 문자열의 뒤에서부터 조사
	// 왜 뒤에서부터 조사? => 기준점이 문자열 앞이니까, 기준점을 유지하기 위해서
	while(i!=0 and j!=0){

		// j 는 영향이 없다
		if(dp[i][j]==dp[i][j-1]){
			j--;
		}
		// i 는 영향이 없다
		else if(dp[i][j]==dp[i-1][j]){
			i--;
		}
		// i,j 둘다 영향이 있다 => 둘이 가리키는 문자가 같다
		else{
			result.push_back(s1[i-1]); // 해당 문자를 저장
			i--;
			j--;
		}
	}

	// 뒤에서부터 조사한 문자를 뒤집어
	reverse(result.begin(),result.end());
	
	// sub string 출력
	for(char x:result){
		cout<<x <<",";
	}

	return dp[n1][n2];

}




int main(){

	string s1 = "ABCD";
	string s2 = "ABEDG";

	int n1 = s1.length();
	int n2 = s2.length();

	vector<vector<int> > dp(n1+1, vector<int>(n2+1,-1)); //n1 X n2 

	cout<< lcs(s1,s2,0,0,dp) <<endl;


	for(int i=0;i<=n1;i++){
		for(int j=0;j<=n2;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}